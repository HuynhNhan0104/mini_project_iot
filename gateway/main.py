from mqtt import MQTT_Module
from uart import Serial_module
import time
    
AIO_FEED_IDs  = [
    "NhanHuynh/feeds/led", 	
    "NhanHuynh/feeds/temp",
    "NhanHuynh/feeds/humi",
    # "NhanHuynh/feeds/lux",
    "NhanHuynh/feeds/fan"
]

AIO_USERNAME = "NhanHuynh"
AIO_KEY= ""
BROKER_ADDRESS = "io.adafruit.com"
PORT = 1883    

def send_command_to_node(serial,topic,data):
    print(f"topic: {topic}, data: {data}")
    if topic == "NhanHuynh/feeds/led":
        message = f"!LED:{data}#"
        serial.writeData(message)    
    elif topic == "NhanHuynh/feeds/fan":
        message = f"!FAN:{data}#"
        serial.writeData(message)
        
        
        
def processData_external(data,mqtt_handler):
    data = data.replace("!", "")
    data = data.replace("#", "")
    splitData = data.split(":")
    measure = splitData[0]
    value = splitData[1]
    print(splitData)    
    if measure == "TEMP":
        mqtt_handler.publish("NhanHuynh/feeds/temp",value)  
    if measure == "HUMI":
        mqtt_handler.publish("NhanHuynh/feeds/humi",value)  
    if measure == "LED":
        mqtt_handler.publish("NhanHuynh/feeds/led",value)  
    if measure == "FAN":
        mqtt_handler.publish("NhanHuynh/feeds/fan",value)  
    
def main():
    serial_handler = Serial_module("COM9",115200)
    mqtt_handler = MQTT_Module(username= AIO_USERNAME,access_token= AIO_KEY, feed_ids= AIO_FEED_IDs,broker_address=BROKER_ADDRESS,port=PORT)
    mqtt_handler.set_serial(serial_handler)
    mqtt_handler.set_on_message_callback(send_command_to_node)
    serial_handler.set_processData(processData_external)
    while True:
        try:
            serial_handler.readSerial(mqtt_handler)
            time.sleep(1)
        except KeyboardInterrupt:
            break 
if __name__ == "__main__":
    main()