#include "pebble_os.h"
#include "pebble_app.h"
#include "pebble_fonts.h"

#define MY_UUID { 0x4E, 0xCA, 0x31, 0x8B, 0x32, 0x9A, 0x4F, 0xCA, 0x82, 0x58, 0x5E, 0xFB, 0x1F, 0xD0, 0x72, 0x38 }
PBL_APP_INFO(MY_UUID,
             "Binary", "joneisen.me",
             1, 0, /* App version */
             RESOURCE_ID_IMAGE_MENU_ICON,
             APP_INFO_WATCH_FACE);

#define FONT_CHOICE FONT_KEY_GOTHIC_28_BOLD

Window window;

TextLayer monthLayer;
TextLayer dayLayer;
TextLayer hourLayer;
TextLayer minuteLayer;
TextLayer secondLayer;

void binaryize(int num, int len, char *str)
{
  int mask = 0x1;
  str += len-1;
  while(mask <= num) {
    *str-- = !!(mask & num) + '0';
    mask <<= 1;
  }
}

// Called once per second
void handle_second_tick(AppContextRef ctx, PebbleTickEvent *t) {

  (void)t;
  (void)ctx;

  static char months[] =  "    0000 month";
  static char days[] =    "  00000 day";
  static char hours[] =   "    0000 hour";
  static char minutes[] = "000000 min";
  static char seconds[] = "000000 sec";

  PblTm currentTime;

  get_time(&currentTime);

  binaryize(currentTime.tm_mon, 4, months+4);
  binaryize(currentTime.tm_mday, 5, days+2);
  binaryize(currentTime.tm_hour, 4, hours+4);
  binaryize(currentTime.tm_min, 6, minutes);
  binaryize(currentTime.tm_sec, 6, seconds);

  text_layer_set_text(&monthLayer, months);
  text_layer_set_text(&dayLayer, days);
  text_layer_set_text(&hourLayer, hours);
  text_layer_set_text(&minuteLayer, minutes);
  text_layer_set_text(&secondLayer, seconds);

}

void initLayer(TextLayer * layer, GRect grect) {
  // Init the text layer used to show the time
  text_layer_init(layer, window.layer.frame);
  text_layer_set_text_color(layer, GColorWhite);
  text_layer_set_background_color(layer, GColorClear);
  layer_set_frame(&(*layer).layer, grect);
  text_layer_set_font(layer, fonts_get_system_font(FONT_CHOICE));
  layer_add_child(&window.layer, &(*layer).layer);
}

void handle_init(AppContextRef app_ctx) {
  window_init(&window, "Jon1Test");
  window_stack_push(&window, true /* Animated */);
  window_set_background_color(&window, GColorBlack);

  initLayer(&monthLayer, GRect(10, 10, 144-10, 30));
  initLayer(&dayLayer, GRect(10, 40, 144-10, 30));
  initLayer(&hourLayer, GRect(10, 70, 144-10, 30));
  initLayer(&minuteLayer, GRect(10, 100, 144-10, 30));
  initLayer(&secondLayer, GRect(10, 130, 144-10, 28));

  // Ensures time is displayed immediately (will break if NULL tick event accessed).
  // (This is why it's a good idea to have a separate routine to do the update itself.)
  handle_second_tick(app_ctx, NULL);
}


void pbl_main(void *params) {
  PebbleAppHandlers handlers = {

    // Handle app start
    .init_handler = &handle_init,

    // Handle time updates
    .tick_info = {
      .tick_handler = &handle_second_tick,
      .tick_units = SECOND_UNIT
    }

  };
  app_event_loop(params, &handlers);
}
