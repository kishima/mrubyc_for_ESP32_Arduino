#include <mrubyc_for_ESP32_Arduino.h>
#include <WiFi.h>
#include "mrubyc.h"

const char* ssid     = "";
const char* password = "";
WiFiServer server(33333);

#define MEMORY_SIZE (1024*30)
static uint8_t memory_pool[MEMORY_SIZE];

static int first=0;
static struct VM *vm;

unsigned char buff[10*1024];
int buff_ptr=0;

void mrubyc(uint8_t *mrbbuf)
{

  if(!first){
    mrbc_init_alloc(memory_pool, MEMORY_SIZE);
    init_static();
    mrbc_define_methods();
    
    vm = mrbc_vm_open(NULL);
    if( vm == 0 ) {
      //fprintf(stderr, "Error: Can't open VM.\n");
      Serial.println("Can't open VM");
      return;
    }
  }
  
  if( mrbc_load_mrb(vm, mrbbuf) != 0 ) {
    Serial.println("mrbc_load_mrb error");//(stderr, "Error: Illegal bytecode.\n");
    return;
  }
  
  if(!first){
    mrbc_vm_begin(vm);
  }else{
    vm->pc_irep = vm->irep;
    vm->pc = 0;
    vm->current_regs = vm->regs;
    vm->flag_preemption = 0;
    vm->callinfo_top = 0;
    vm->error_code = 0;
    //printf("vm->regs[0].tt=%d\n",vm->regs[0].tt);
  }
  Serial.println("RUN!\n");
  mrbc_vm_run(vm);
  Serial.println("DONE!\n");
  if(first==0)first=1;
}

void setup()
{
    Serial.begin(115200);
    delay(10);

    Serial.println();
    Serial.println();
    Serial.print("Connecting to ");
    Serial.println(ssid);

    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    Serial.println("");
    Serial.println("WiFi connected.");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
    
    server.begin();
}

void loop(){
  WiFiClient client = server.available(); 
  if (client) {
    while (client.connected()) {           
       read_message(client);  
    }
    Serial.println("Client Disconnected.");
    client.stop();
    delay(10);
  }else{
    delay(10);
  }
}

int read_message(WiFiClient& client){
  Serial.println("new irep.");        
  String currentLine = "";               
  int remain=4;
  int size=0;
  unsigned char header[4];
  Serial.println("wating recv");   
  while (client.connected()) {
    size = client.read(&header[4-remain],remain);
    if(size<0){
      delay(10);
      continue;
    }
    if(size<remain){
      remain-=size;
      continue;
    }
    break;
  }
  uint16_t irep_len = bin_to_uint16(&header[2]);
  remain = irep_len;
  Serial.print("wating recv:irep_len=");
  Serial.println(irep_len);
  while (client.connected()) {           
    size = client.read(&buff[buff_ptr+(irep_len-remain)],remain);
    //Serial.println(size);
    if(size<0){
      delay(10);
      continue;
    }
    if(size<remain){
       remain-=size;
       continue;
    }
    int i=0;
    Serial.print("buff_ptr=");
    Serial.print(buff_ptr);
    Serial.print("\n");
    Serial.print(">>>>>>>>>>>>>>>>>>>>> Run VM\n");
    mrubyc(&buff[buff_ptr]);
    buff_ptr+=irep_len;
    return 0;
  }
  return -1;
}
