#include <math.h>
#include <FastLED.h>

#define LED_PIN     7
#define COLOR_ORDER GRB
#define CHIPSET     WS2812B
#define NUM_LEDS    120
#define BRIGHTNESS  128


CRGB leds[NUM_LEDS];
int current_hue;
uint8_t previous_state1;
uint8_t previous_state2;
float X_COORDS[120] = {0.0, 0.0534, 0.1069, 0.1603, 0.2137, 0.2672, 0.3206, 0.374, 0.4275, 0.4809, 0.5344, 0.5878, 0.5878, 0.5674, 0.547, 0.5266, 0.5061, 0.4857, 0.4653, 0.4449, 0.4245, 0.4041, 0.3837, 0.3633, 0.3633, 0.4167, 0.4701, 0.5236, 0.577, 0.6304, 0.6839, 0.7373, 0.7908, 0.8442, 0.8976, 0.9511, 0.9511, 0.885, 0.819, 0.7529, 0.6869, 0.6208, 0.5548, 0.4887, 0.4227, 0.3566, 0.2906, 0.2245, 0.2245, 0.2041, 0.1837, 0.1633, 0.1429, 0.1225, 0.1021, 0.0816, 0.0612, 0.0408, 0.0204, 0.0, 0.0, -0.0204, -0.0408, -0.0612, -0.0816, -0.1021, -0.1225, -0.1429, -0.1633, -0.1837, -0.2041, -0.2245, -0.2245, -0.2906, -0.3566, -0.4227, -0.4887, -0.5548, -0.6208, -0.6869, -0.7529, -0.819, -0.885, -0.9511, -0.9511, -0.8976, -0.8442, -0.7908, -0.7373, -0.6839, -0.6304, -0.577, -0.5236, -0.4701, -0.4167, -0.3633, -0.3633, -0.3837, -0.4041, -0.4245, -0.4449, -0.4653, -0.4857, -0.5061, -0.5266, -0.547, -0.5674, -0.5878, -0.5878, -0.5344, -0.4809, -0.4275, -0.374, -0.3206, -0.2672, -0.2137, -0.1603, -0.1069, -0.0534, -0.0};
float Y_COORDS[120] = {-0.382, -0.4208, -0.4596, -0.4984, -0.5373, -0.5761, -0.6149, -0.6537, -0.6925, -0.7314, -0.7702, -0.809, -0.809, -0.7462, -0.6834, -0.6206, -0.5578, -0.4949, -0.4321, -0.3693, -0.3065, -0.2437, -0.1809, -0.118, -0.118, -0.0792, -0.0404, -0.0016, 0.0373, 0.0761, 0.1149, 0.1537, 0.1925, 0.2314, 0.2702, 0.309, 0.309, 0.309, 0.309, 0.309, 0.309, 0.309, 0.309, 0.309, 0.309, 0.309, 0.309, 0.309, 0.309, 0.3718, 0.4347, 0.4975, 0.5603, 0.6231, 0.6859, 0.7487, 0.8116, 0.8744, 0.9372, 1.0, 1.0, 0.9372, 0.8744, 0.8116, 0.7487, 0.6859, 0.6231, 0.5603, 0.4975, 0.4347, 0.3718, 0.309, 0.309, 0.309, 0.309, 0.309, 0.309, 0.309, 0.309, 0.309, 0.309, 0.309, 0.309, 0.309, 0.309, 0.2702, 0.2314, 0.1925, 0.1537, 0.1149, 0.0761, 0.0373, -0.0016, -0.0404, -0.0792, -0.118, -0.118, -0.1809, -0.2437, -0.3065, -0.3693, -0.4321, -0.4949, -0.5578, -0.6206, -0.6834, -0.7462, -0.809, -0.809, -0.7702, -0.7314, -0.6925, -0.6537, -0.6149, -0.5761, -0.5373, -0.4984, -0.4596, -0.4208, -0.382};


void setup() {
  unsigned long hour = 3600000;
//  delay(16 * hour); // sanity delay
  delay(3000); // sanity delay
  current_hue = 0;
  previous_state1 = 255;
  previous_state2 = 255;
  FastLED.addLeds<CHIPSET, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip).setTemperature(HighNoonSun);
  FastLED.setBrightness(BRIGHTNESS);
}

void loop() {
  random16_add_entropy(random());
  uint8_t r = random8(9);
  do {
    r = random8(9);
  } while(r == previous_state1 || r == previous_state2);
  previous_state2 = previous_state1;
  previous_state1 = r;
  switch(r) {
    case 0: blast(15); break;
    case 1: caterpillar(60); break;
    case 2: spiral(30); break;
    case 3: burst(20); break;
    case 4: tide(40); break;
    case 5: ripple(30); break;
    case 6: tunnel(60); break;
    case 7: fire(40); break;
    case 8: snowfall(15); break;
  }
}

CRGB get_next_color(int hue_delta, uint8_t sat, uint8_t val) {
  current_hue = (current_hue + hue_delta) % 255;
  CHSV hsv = CHSV{(uint8_t)current_hue, sat, val};
  CRGB rgb;
  hsv2rgb_rainbow(hsv, rgb);
  return rgb;
}

CRGB interpolate_colors(CRGB color1, CRGB color2, float weight_of_color2) {
  int r = color1.r * (1 - weight_of_color2) + color2.r * weight_of_color2;
  int g = color1.g * (1 - weight_of_color2) + color2.g * weight_of_color2;
  int b = color1.b * (1 - weight_of_color2) + color2.b * weight_of_color2;
  return CRGB{(uint8_t)r, (uint8_t)g, (uint8_t)b};
}

CRGB dim_light(CRGB color, uint8_t scale) {
  return CRGB{scale8(color.r, scale), scale8(color.g, scale), scale8(color.b, scale)};
}

void set_color(CRGB* arr, int sz, CRGB color) {
  for(int k = 0; k < sz; k++) {
    arr[k] = color;
  }
}

void burst(int frames_per_second) {
  CRGB current_color;
  CRGB future_color = get_next_color(random8(), 255, 255);
  CRGB radial_colors[12] = {CRGB::Black};
  int n_frames = frames_per_second * 30;
  for(int i = 0; i < n_frames; i++) {
    int progress = i % 120;
    if(progress == 0) {
      current_color = future_color;
      future_color = get_next_color(random8(32, 224), 255, 255);
    }
    for(int r = 11; r > 0; r--) {
      radial_colors[r] = radial_colors[r-1];
    }
    float weight = (float)progress / 120;
    uint8_t scale = quadwave8(16 * (i % 16));
    radial_colors[0] = dim_light(interpolate_colors(current_color, future_color, weight), scale);
    for(int r = 0; r < 12; r++) {
      auto color = radial_colors[r];
      for(int arm = 0; arm < 5; arm++) {
        leds[arm * 24 + r] = color;
        leds[arm * 24 + 23 - r] = color;
      }
    }
    FastLED.show();
    FastLED.delay(1000 / frames_per_second);
  }
}

void snowfall(int frames_per_second) {
  float snow_x[5];
  float snow_y[5];
  float snow_r[5];
  float snow_v[5];
  float level = -0.8;
  CRGB background = CRGB{0, 64, 192};
  CRGB snow_color = CRGB(144, 250, 250);
  for (int i = 0; i < 120; i++) {
    leds[i] = background;
  }
  FastLED.show();
  FastLED.delay(1000 / frames_per_second);
  for (int i_snow = 0; i_snow < 5; i_snow++) {
    snow_x[i_snow] = 0.8 * ((float)random8() / 128 - 1);
    snow_y[i_snow] = (float)random8() / 512 + 0.6;
    snow_r[i_snow] = 0.08 + (float)random8(16) / 320;
    snow_v[i_snow] = 0.005 + (float)random8(16) / 1024;
  }
  int n_frames = frames_per_second * 30;
  for (int i_frame = 0; i_frame < n_frames; i_frame++) {
    for (int i_snow = 0; i_snow < 5; i_snow++) {
      snow_y[i_snow] -= snow_v[i_snow];
      if (snow_y[i_snow] < level) {
        snow_x[i_snow] = 0.8 * ((float)random8() / 128 - 1);
        snow_y[i_snow] = (float)random8() / 512 + 0.6;
        snow_r[i_snow] = 0.1 + (float)random8(16) / 320;
        snow_v[i_snow] = 0.02 + (float)random8(16) / 1024;
      }
    }
    level += 0.002;
    if (level > 0.1) {
      level = -0.8;
    }
    for (int i = 0; i < 120; i++) {
      float snow_weight = 1;
      if (Y_COORDS[i] > level) {
        snow_weight = 1 - 10 * (Y_COORDS[i] - level);
        if (snow_weight < 0) {
          snow_weight = 0;
        }
        for (int i_snow = 0; i_snow < 5; i_snow++) {
          float d = (X_COORDS[i] - snow_x[i_snow]) * (X_COORDS[i] - snow_x[i_snow]) + (Y_COORDS[i] - snow_y[i_snow]) * (Y_COORDS[i] - snow_y[i_snow]);
          float delta = 1 - (d / (snow_r[i_snow] * snow_r[i_snow]));
          if (delta > 0) {
            snow_weight += delta;
          }
        }
        if (snow_weight > 1) {
          snow_weight = 1;
        } else if (snow_weight < 0.1) {
          snow_weight = 0;
        }
      }
      if (snow_weight == 1) {
        leds[i] = snow_color;
      } else {
        leds[i] = interpolate_colors(background, snow_color, snow_weight);
      }
    }
    FastLED.show();
    FastLED.delay(1000 / frames_per_second);
  }
}

void blast(int frames_per_second) {
  CRGB radial_colors[12] = {CRGB::Black};
  int n_frames = frames_per_second * 30;
  for(int i = 0; i < n_frames; i++) {
    for(int r = 11; r > 0; r--) {
      radial_colors[r] = radial_colors[r-1];
    }
    radial_colors[0] = get_next_color(random8(4, 8), 180, 180);
    for(int r = 0; r < 12; r++) {
      CRGB color = radial_colors[r];
      for(int arm = 0; arm < 5; arm++) {
        leds[arm * 24 + r] = color;
        leds[arm * 24 + 23 - r] = color;
      }
    }
    FastLED.show();
    FastLED.delay(1000 / frames_per_second);
  }
}

void ripple(int frames_per_second) {
  float pi = 3.14159265;
  int theta1 = random16(360);
  int theta2 = (theta1 + random16(45, 135)) % 360;
  uint8_t axial_light1[63] = {0};
  uint8_t axial_light2[63] = {0};
  float direction1_x = sin(theta1 * pi / 180);
  float direction1_y = cos(theta1 * pi / 180);
  float direction2_x = sin(theta2 * pi / 180);
  float direction2_y = cos(theta2 * pi / 180);
  int light_indexes1[120];
  int light_indexes2[120];
  for(int k = 0; k < 120; k++) {
      float kx = X_COORDS[k];
      float ky = Y_COORDS[k];
      float projection1 = kx * direction1_x + ky * direction1_y;
      light_indexes1[k] = (int)(projection1 * 31) + 31;
      float projection2 = kx * direction2_x + ky * direction2_y;
      light_indexes2[k] = (int)(projection2 * 31) + 31;
  }
  int n_frames = frames_per_second * 30;
  for(int i = 0; i < n_frames; i++) {
    int progress = i % 63;
    for(int a = 62; a > 0; a--) {
      axial_light1[a] = axial_light1[a-1];
      axial_light2[a] = axial_light2[a-1];
    }
    axial_light1[0] = 63 + scale8(quadwave8(progress * 15 + 32), 192);
    axial_light2[0] = 63 + scale8(quadwave8(progress * 8), 192);
    CRGB color = get_next_color(1, 240, 240);
    for(int k = 0; k < 120; k++) {
      uint8_t scale1 = axial_light1[light_indexes1[k]];
      uint8_t scale2 = axial_light2[light_indexes2[k]];
      leds[k] = dim_light(dim_light(color, scale1), scale2);
    }
    FastLED.show();
    FastLED.delay(1000 / frames_per_second);
  }
}

void tide(int frames_per_second) {
  CRGB current_color;
  CRGB future_color = get_next_color(random8(), 240, 240);
  CRGB axial_color[63];
  set_color(leds, 120, CRGB::Black);
  set_color(axial_color, 63, CRGB::Black);
  float pi = 3.14159265;
  int theta = random16(360);
  float direction_x = sin(theta * pi / 180);
  float direction_y = cos(theta * pi / 180);
  int indexes[120];
  for(int k = 0; k < 120; k++) {
      float kx = X_COORDS[k];
      float ky = Y_COORDS[k];
      float projection = kx * direction_x + ky * direction_y;
      indexes[k] = (int)(projection * 31) + 31;
  }
  int n_frames = frames_per_second * 30;
  for(int i = 0; i < n_frames; i++) {
    int progress = i % 63;
    if (progress == 0) {
      current_color = future_color;
      future_color = get_next_color(random8(8, 32), 255, 255);
    }
    for(int a = 62; a > 0; a--) {
      axial_color[a] = axial_color[a-1];
    }
    float weight = float(progress) / 63;
    uint8_t scale = quadwave8(8 * (i % 32));
    axial_color[0] = dim_light(interpolate_colors(current_color, future_color, weight), scale);
    for(int k = 0; k < 120; k++) {
      leds[k] = axial_color[indexes[k]];
    }
    FastLED.show();
    FastLED.delay(1000 / frames_per_second);
  }
}

void spiral(int frames_per_second) {
  CRGB color;
  set_color(leds, 120, CRGB::Black);
  int n_frames = frames_per_second * 30;
  for(int i = 0; i < n_frames; i++) {
    int progress = i % 24;
    if(progress == 0) {
      color = get_next_color(random8(64, 192), 200, 200);
    }
    for(int k = 0; k < progress+1; k++) {
      for(int arm = 0; arm < 5; arm++) {
        leds[k + arm * 24] = color;
      }
    }
    FastLED.show();
    FastLED.delay(1000 / frames_per_second);
  }
}

void caterpillar(int frames_per_second) {
  CRGB current_color;
  CRGB future_color = get_next_color(random8(), 255, 255);
  CRGB colors[120];
  set_color(leds, 120, CRGB::Black);
  set_color(colors, 120, CRGB::Black);
  int n_frames = frames_per_second * 30;
  for(int i = 0; i < n_frames; i++) {
    int progress = i % 120;
    if(progress == 0) {
      current_color = future_color;
      future_color = get_next_color(random8(32, 96), 255, 255);
    }
    float weight = (float)progress / 120;
    colors[progress] = interpolate_colors(current_color, future_color, weight);
    for(int k = 0; k < 120; k++) {
      int idx = (progress - k + 120) % 120;
      leds[idx] = dim_light(colors[idx], 255 - k * 2);
    }
    FastLED.show();
    FastLED.delay(1000 / frames_per_second);
  }
}

void tunnel(int frames_per_second) {
  CRGB current_color;
  CRGB future_color = get_next_color(random8(), 255, 255);
  CRGB colors[155];
  set_color(colors, 155, CRGB::Black);
  int n_frames = frames_per_second * 30;
  int indexes[155];
  for(int k = 0; k < 155; k++) {
    if(k < 12) indexes[k] = k + 12;
    else if(k < 19) indexes[k] = -1;
    else if(k < 43) indexes[k] = k - 19 + 48;
    else if(k < 50) indexes[k] = -1;
    else if(k < 74) indexes[k] = k - 50 + 96;
    else if(k < 81) indexes[k] = -1;
    else if(k < 105) indexes[k] = k - 81 + 24;
    else if(k < 112) indexes[k] = -1;
    else if(k < 136) indexes[k] = k - 112 + 72;
    else if(k < 143) indexes[k] = -1;
    else indexes[k] = k - 143;
  }
  for(int i = 0; i < n_frames; i++) {
    int progress = i % 155;
    if(progress == 0) {
      current_color = future_color;
      future_color = get_next_color(random8(32, 96), 255, 255);
    }
    float weight = (float)progress / 155;
    colors[progress] = interpolate_colors(current_color, future_color, weight);
    for(int k = 0; k < 155; k++) {
      int relative_idx = (progress - k + 155) % 155;
      int led_idx = indexes[relative_idx];
      if(led_idx != -1) {
        leds[led_idx] = dim_light(colors[relative_idx], 255 - k - k/2);
      }
    }
    FastLED.show();
    FastLED.delay(1000 / frames_per_second);
  }
}

void fire(int frames_per_second) {
  uint8_t heat[63] = {127};
  CRGBPalette16 palette = HeatColors_p;
  int cooling = 75;
  int sparking = 120;
  int n_frames = frames_per_second * 30;
  int y_level[120];
  for(int k = 0; k < 120; k++) {
    y_level[k] = (int)(Y_COORDS[k] * 30) + 32;
  }
  for(int i = 0; i < n_frames; i++) {
    for(int k = 0; k < 63; k++) {
      heat[k] = qsub8(heat[k], random8(0, ((cooling * 10) / 63) + 2));
    }
    for(int k = 62; k >= 2; k--) {
      heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2] ) / 3;
    }
    if(random8() < sparking) {
      int y = random8(7);
      heat[y] = qadd8(heat[y], random8(160,255));
    }
    for(int k = 0; k < 120; k++) {
      int y = y_level[k];
      uint8_t h = heat[y_level[k]];
      if (y == 41) {
        int d = random8(0, 32) - 16;
        if(d > 0) h = qadd8(h, d);
        else h = qsub8(h, -d);
      }
      uint8_t color_index = scale8(h, 240);
      leds[k] = ColorFromPalette(palette, color_index);
    }
    FastLED.show();
    FastLED.delay(1000 / frames_per_second);
  }
}
