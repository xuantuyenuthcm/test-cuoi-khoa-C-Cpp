#include <stdio.h>
#include <string.h>

typedef struct {
    char light;
    char fan;
    char motor;
} smartHome_t;

const char* data = "HTTP1.1 200 OK{"\
"\"light\": \"on\","\
"\"fan\" : \"off\","\
"\"motor\" : \"off\"}";

smartHome_t pair_data(const char* data);

 int main()
 {   smartHome_t x = pair_data(data);

   printf("Ket qua phan tich du lieu:\n");
   printf("Light: %d\n", x.light);
  printf("Fan: %d\n", x.fan);
  printf("Motor: %d\n", x.motor);

   printf("\n Du lieu goc:\n%s\n", data);

  return 0;
 }

smartHome_t pair_data(const char* data) {
    smartHome_t result = { 0, 0, 0 };

    // Tìm kiếm trạng thái của light
    char* light_pos = strstr(data, "\"light\":");
    if (light_pos != NULL) {
        char* light_value = strstr(light_pos, "\"on\"");
        if (light_value != NULL && light_value < strstr(light_pos, ",")) {
            result.light = 1;
        }
        else {
            result.light = 0;
        }
    }

    // Tìm kiếm trạng thái của fan
    char* fan_pos = strstr(data, "\"fan\":");
    if (fan_pos != NULL) {
        char* fan_value = strstr(fan_pos, "\"on\"");
        if (fan_value != NULL && fan_value < strstr(fan_pos, ",")) {
            result.fan = 1;
        }
        else {
            result.fan = 0;
        }
    }

    // Tìm kiếm trạng thái của motor
    char* motor_pos = strstr(data, "\"motor\":");
    if (motor_pos != NULL) {
        char* motor_value = strstr(motor_pos, "\"on\"");
        if (motor_value != NULL) {
            result.motor = 1;
        }
        else {
            result.motor = 0;
        }
    }

    return result;
}