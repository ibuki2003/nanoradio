#include "freqs.h"

#include <stddef.h>
#include "lcd_kana.h"
#include "lcd.h"

const FreqMemory FREQS_AM_HOKKAIDO[] = {
  {0, NULL},
  {567, "NHK第1"},
  {585, "NHK第1"},
  {603, "NHK第1"},
  {621, "NHK第1"},
  {639, "STVﾗジｵ"},
  {675, "NHK第1"},
  {702, "NHK第2"},
  {747, "NHK第2"},
  {864, "HBCﾗジｵ"},
  {882, "STVﾗジｵ"},
  {900, "HBCﾗジｵ"},
  {909, "STVﾗジｵ"},
  {945, "NHK第1"},
  {1071, "STVﾗジｵ"},
  {1125, "NHK第2"},
  {1152, "NHK第2"},
  {1188, "NHK第1"},
  {1197, "STVﾗジｵ"},
  {1269, "HBCﾗジｵ"},
  {1287, "HBCﾗジｵ"},
  {1404, "HBCﾗジｵ"},
  {1440, "STVﾗジｵ"},
  {1449, "HBCﾗジｵ"},
  {1467, "NHK第2"},
  {1602, "NHK第2"},
  {65535, NULL},
};

const FreqMemory FREQS_AM_TOHOKU[] = {
  {0, NULL},
  {531, "NHK第1"},
  {540, "NHK第1"},
  {684, "IBCﾗジｵ"},
  {774, "NHK第2"},
  {891, "NHK第1"},
  {918, "YBCﾗジｵ"},
  {936, "ABSﾗジｵ"},
  {963, "NHK第1"},
  {1089, "NHK第2"},
  {1233, "RABﾗジｵ"},
  {1260, "TBCﾗジｵ"},
  {1323, "NHK第1"},
  {1386, "NHK第2"},
  {1458, "ﾗジｵﾌｸｼﾏ"},
  {1503, "NHK第1"},
  {1521, "NHK第2"},
  {1575, "AFN"},
  {1602, "NHK第2"},
  {65535, NULL},
};

const FreqMemory FREQS_AM_KANTO[] = {
  {0, NULL},
  {594, "NHK第1"},
  {693, "NHK第2"},
  {765, "YBSﾗジｵ"},
  {810, "AFN"},
  {927, "NHK第1"},
  {954, "TBSﾗジｵ"},
  {1098, "SBCﾗジｵ"},
  {1134, "ﾌﾞﾝｶ放送"},
  {1197, "ｲﾊﾞﾗｷ放送"},
  {1242, "ﾆｯﾎﾟﾝ放送"},
  {1404, "SBSﾗジｵ"},
  {1422, "ﾗジｵﾆｯﾎﾟﾝ"},
  {1530, "ﾄﾁｷﾞ放送"},
  {1602, "NHK第2"},
  {65535, NULL},
};

const FreqMemory FREQS_AM_CHUBU[] = {
  {0, NULL},
  {639, "NHK第2"},
  {648, "NHK第1"},
  {729, "NHK第1"},
  {738, "KNBﾗジｵ"},
  {765, "YBSﾗジｵ"},
  {819, "NHK第1"},
  {837, "NHK第1"},
  {864, "FBCﾗジｵ"},
  {882, "NHK第1"},
  {909, "NHK第2"},
  {927, "NHK第1"},
  {1035, "NHK第2"},
  {1053, "CBCﾗジｵ"},
  {1098, "SBCﾗジｵ"},
  {1107, "MROﾗジｵ"},
  {1116, "BSNﾗジｵ"},
  {1224, "NHK第1"},
  {1332, "ﾄｳｶｲﾗジｵ"},
  {1386, "NHK第2"},
  {1404, "SBSﾗジｵ"},
  {1431, "ｷﾞﾌﾁｬﾝ"},
  {1467, "NHK第2"},
  {1521, "NHK第2"},
  {1593, "NHK第2"},
  {65535, NULL},
};

const FreqMemory FREQS_AM_KINKI[] = {
  {0, NULL},
  {558, "ﾗジｵｶﾝｻｲ"},
  {666, "NHK第1"},
  {828, "NHK第2"},
  {1008, "ABCﾗジｵ"},
  {1143, "KBSｷｮｳﾄ"},
  {1179, "MBSﾗジｵ"},
  {1314, "ﾗジｵｵｵｻｶ"},
  {1431, "ﾜｶﾔﾏ放送"},
  {65535, NULL},
};

const FreqMemory FREQS_AM_CHUGOKU[] = {
  {0, NULL},
  {603, "NHK第1"},
  {675, "NHK第1"},
  {702, "NHK第2"},
  {765, "KRYﾗジｵ"},
  {900, "BSSﾗジｵ"},
  {1071, "NHK第1"},
  {1125, "NHK第2"},
  {1296, "NHK第1"},
  {1350, "RCCﾗジｵ"},
  {1368, "NHK第1"},
  {1377, "NHK第2"},
  {1386, "NHK第2"},
  {1494, "RSKﾗジｵ"},
  {1575, "AFN"},
  {1593, "NHK第2"},
  {65535, NULL},
};

const FreqMemory FREQS_AM_SHIKOKU[] = {
  {0, NULL},
  {828, "NHK第2"},
  {900, "RKCﾗジｵ"},
  {945, "NHK第1"},
  {963, "NHK第1"},
  {990, "NHK第1"},
  {1035, "NHK第2"},
  {1116, "RNBﾗジｵ"},
  {1152, "NHK第2"},
  {1269, "ｼｺｸ放送"},
  {1368, "NHK第1"},
  {1449, "ﾆｼﾆｯﾎﾟﾝ放送"},
  {1512, "NHK第2"},
  {65535, NULL},
};

const FreqMemory FREQS_AM_KYUSHU[] = {
  {0, NULL},
  {540, "NHK第1"},
  {549, "NHK第1"},
  {576, "NHK第1"},
  {612, "NHK第1"},
  {639, "NHK第1"},
  {648, "AFN"},
  {684, "NHK第1"},
  {720, "KBCﾗジｵ"},
  {738, "RBCiﾗジｵ"},
  {756, "NHK第1"},
  {864, "ﾗジｵｵｷﾅﾜ"},
  {873, "NHK第2"},
  {936, "MRTﾗジｵ"},
  {963, "NHK第1"},
  {1017, "NHK第2"},
  {1098, "OBSﾗジｵ"},
  {1107, "MBCﾗジｵ"},
  {1125, "NHK第2"},
  {1197, "RKBﾗジｵ"}, // どっちもある
  {1233, "NBCﾗジｵ"},
  {1278, "RKBﾗジｵ"},
  {1377, "NHK第2"},
  {1386, "NHK第2"},
  {1413, "KBCﾗジｵ"},
  {1467, "NHK第2"},
  {1575, "AFN"},
  {1602, "NHK第2"},
  {65535, NULL},
};


const FreqMemory FREQS_FM_HOKKAIDO[] = {
  {0, NULL},
  {764, "AIR-G'"},
  {785, "AIR-G'"},
  {794, "ﾉｰｽｳｪｰﾌﾞ"},
  {798, "ﾉｰｽｳｪｰﾌﾞ"},
  {804, "AIR-G'"},
  {807, "ﾉｰｽｳｪｰﾌﾞ"},
  {821, "ﾉｰｽｳｪｰﾌﾞ"},
  {825, "ﾉｰｽｳｪｰﾌﾞ"},
  {831, "AIR-G'"},
  {852, "NHK-FM"},
  {858, "NHK-FM"},
  {860, "NHK-FM"},
  {864, "AIR-G'"},
  {870, "NHK-FM"},
  {875, "NHK-FM"},
  {880, "NHK-FM"},
  {885, "NHK-FM"},
  {888, "AIR-G'"},
  {894, "AIR-G'"},
  {904, "STVﾗジｵ"},
  {915, "HBCﾗジｵ"},
  {65535, NULL},
};

const FreqMemory FREQS_FM_TOHOKU[] = {
  {0, NULL},
  {761, "ｴﾌｴﾑｲﾜﾃ"},
  {771, "Date fm"},
  {800, "ｴﾌｴﾑｱｵﾓﾘ"},
  {804, "FMﾔﾏｶﾞﾀ"},
  {818, "ﾌｸｼﾏFM"},
  {821, "NHK-FM"},
  {825, "NHK-FM"},
  {828, "ｴﾌｴﾑｱｷﾀ"},
  {831, "NHK-FM"},
  {853, "NHK-FM"},
  {860, "NHK-FM"},
  {867, "NHK-FM"},
  {901, "ABSﾗジｵ"},
  {902, "ﾗジｵﾌｸｼﾏ"},
  {906, "IBCﾗジｵ"},
  {908, "ﾗジｵﾌｸｼﾏ"},
  {917, "RABﾗジｵ"},
  {924, "YBCﾗジｵ"},
  {927, "RABﾗジｵ"},
  {935, "TBCﾗジｵ"},
  {65535, NULL},
};

const FreqMemory FREQS_FM_KANTO[] = {
  {0, NULL},
  {764, "RADIO BERRY"},
  {765, "InterFM"},
  {780, "bayfm"},
  {788, "放送ﾀﾞｲｶﾞｸ"},
  {792, "K-MIX"},
  {795, "FM NACK5"},
  {797, "FMﾅｶﾞﾉ"},
  {800, "TOKYO FM"},
  {803, "NHK-FM"},
  {807, "NHK-FM"},
  {813, "J-WAVE"},
  {816, "NHK-FM"},
  {819, "NHK-FM"},
  {825, "NHK-FM"},
  {830, "FM-FUJI"},
  {832, "NHK-FM"},
  {847, "FMﾖｺﾊﾏ"},
  {851, "NHK-FM"},
  {856, "NHK-FM"},
  {863, "FMｸﾞﾝﾏ"},
  {881, "ｲﾊﾞﾗｷ放送"},
  {897, "InterFM"},
  {905, "TBSﾗジｵ"},
  {909, "YBSﾗジｵ"},
  {911, "ﾄﾁｷﾞ放送"},
  {916, "ﾌﾞﾝｶ放送"},
  {924, "ﾗジｵﾆｯﾎﾟﾝ"},
  {930, "ﾆｯﾎﾟﾝ放送"},
  {934, "ﾄﾁｷﾞ放送"},
  {941, "ﾄﾁｷﾞ放送"},
  {946, "ｲﾊﾞﾗｷ放送"},
  {65535, NULL},
};

const FreqMemory FREQS_FM_CHUBU[] = {
  {0, NULL},
  {761, "FMﾌｸｲ"},
  {775, "FMﾆｲｶﾞﾀ"},
  {778, "ZIP-FM"},
  {789, "ﾚﾃﾞｨｵｷｭｰﾌﾞFMﾐｴ"},
  {792, "K-MIX"},
  {797, "FMﾅｶﾞﾉ"},
  {800, "Radio 80"},
  {805, "ｴﾌｴﾑｲｼｶﾜ"},
  {807, "FM AICHI"},
  {815, "NHK-FM"},
  {818, "NHK-FM"},
  {822, "NHK-FM"},
  {823, "NHK-FM"},
  {825, "NHK-FM"},
  {827, "FMﾄﾔﾏ"},
  {830, "FM-FUJI"},
  {834, "NHK-FM"},
  {836, "NHK-FM"},
  {840, "NHK-FM"},
  {888, "NHK-FM"},
  {902, "KNBﾗジｵ"},
  {904, "ｷﾞﾌﾁｬﾝ"},
  {912, "SBCﾗジｵ"},
  {922, "SBCﾗジｵ"},
  {927, "BSNﾗジｵ"},
  {929, "ﾄｳｶｲﾗジｵ"},
  {936, "FBCﾗジｵ"},
  {937, "CBCﾗジｵ"},
  {939, "SBSﾗジｵ"},
  {940, "MROﾗジｵ"},
  {942, "SBCﾗジｵ"},
  {946, "FBCﾗジｵ"},
  {65535, NULL},
};

const FreqMemory FREQS_FM_KINKI[] = {
  {0, NULL},
  {765, "FMCOCOLO"},
  {770, "e-radio"},
  {802, "FM802"},
  {828, "NHK-FM"},
  {840, "NHK-FM"},
  {847, "NHK-FM"},
  {851, "FM OSAKA"},
  {865, "NHK-FM"},
  {874, "NHK-FM"},
  {881, "NHK-FM"},
  {894, "\x1fSTATION"}, // α-STATION
  {899, "Kiss-FM"},
  {906, "MBSﾗジｵ"},
  {911, "ﾗジｵｶﾝｻｲ"},
  {916, "ﾜｶﾔﾏ放送"},
  {919, "ﾗジｵｵｵｻｶ"},
  {924, "ﾜｶﾔﾏ放送"},
  {933, "ABCﾗジｵ"},
  {942, "ﾜｶﾔﾏﾎｳﾎｳ"},
  {949, "KBSｷｮｳﾄ"},
  {65535, NULL},
};

const FreqMemory FREQS_FM_CHUGOKU[] = {
  {0, NULL},
  {768, "FMｵｶﾔﾏ"},
  {774, "V-air FMｻﾝｲﾝ"},
  {782, "HFM"},
  {788, "V-air FMｻﾝｲﾝ"},
  {792, "FMﾔﾏｸﾞﾁ"},
  {845, "NHK-FM"},
  {853, "NHK-FM"},
  {858, "NHK-FM"},
  {864, "KRYﾗジｵ"},
  {871, "BSSﾗジｵ"},
  {883, "NHK-FM"},
  {887, "NHK-FM"},
  {914, "RSKﾗジｵ"},
  {922, "BSSﾗジｵ"},
  {923, "KRYﾗジｵ"},
  {946, "RCCﾗジｵ"},
  {65535, NULL},
};

const FreqMemory FREQS_FM_SHIKOKU[] = {
  {0, NULL},
  {786, "FMｶｶﾞﾜ"},
  {797, "FMｴﾋﾒ"},
  {807, "ｴﾌｴﾑﾄｸｼﾏ"},
  {816, "FMｺｳﾁ"},
  {834, "NHK-FM"},
  {860, "NHK-FM"},
  {875, "NHK-FM"},
  {877, "NHK-FM"},
  {903, "ﾆｼﾆｯﾎﾟﾝ放送"},
  {908, "RKCﾗジｵ"},
  {912, "RNBﾗジｵ"},
  {917, "RNBﾗジｵ"},
  {930, "ｼｺｸﾎｳﾎｳ"},
  {939, "ｼｺｸﾎｳﾎｳ"},
  {65535, NULL},
};

const FreqMemory FREQS_FM_KYUSHU[] = {
  {0, NULL},
  {761, "LOVE FM"},
  {770, "CROSS FM"},
  {774, "ｴﾌｴﾑｸﾏﾓﾄ"},
  {779, "ｴﾌｴﾑｻｶﾞ"},
  {787, "CROSS FM"},
  {795, "FMﾅｶﾞｻｷ"},
  {798, "FMｶｺﾞｼﾏ"},
  {800, "FMﾌｸｵｶ"},
  {801, "ﾗジｵｵｷﾅﾜ"},
  {803, "NHK第2"},
  {807, "FMﾌｸｵｶ"},
  {813, "NHK第1"},
  {816, "NHK-FM"},
  {826, "RBCiﾗジｵ"},
  {827, "LOVE FM"},
  {832, "JOY FM FMﾐﾔｻﾞｷ"},
  {835, "NHK第1"},
  {845, "NHK-FM"},
  {848, "NHK-FM"},
  {854, "NHK-FM"},
  {856, "NHK-FM"},
  {857, "NHK-FM"},
  {862, "NHK-FM"},
  {873, "ｴﾌｴﾑｵｷﾅﾜ"},
  {880, "ｴﾌｴﾑｵｵｲﾀ"},
  {881, "NHK-FM"},
  {889, "NHK-FM"},
  {891, "AFN"},
  {902, "KBCﾗｼﾞｵ"},
  {904, "MRTﾗｼﾞｵ"},
  {906, "NBCﾗｼﾞｵ"},
  {910, "RKBﾗｼﾞｵ"},
  {914, "RKKﾗｼﾞｵ"},
  {915, "RKBﾗｼﾞｵ"},
  {921, "RBCiﾗｼﾞｵ"},
  {926, "NBCﾗｼﾞｵ"},
  {928, "MBCﾗｼﾞｵ"},
  {931, "ROK ﾗｼﾞｵｵｷﾅﾜ"},
  {933, "OBSﾗｼﾞｵ"},
  {935, "NBCﾗｼﾞｵ"},
  {940, "KBCﾗｼﾞｵ"},
  {947, "MRTﾗｼﾞｵ"},
  {65535, NULL},
};

const FreqMemory* const FREQS_AM[AREA_COUNT] = {
  FREQS_AM_HOKKAIDO,
  FREQS_AM_TOHOKU,
  FREQS_AM_KANTO,
  FREQS_AM_CHUBU,
  FREQS_AM_KINKI,
  FREQS_AM_CHUGOKU,
  FREQS_AM_SHIKOKU,
  FREQS_AM_KYUSHU,
};

const FreqMemory* const FREQS_FM[AREA_COUNT] = {
  FREQS_FM_HOKKAIDO,
  FREQS_FM_TOHOKU,
  FREQS_FM_KANTO,
  FREQS_FM_CHUBU,
  FREQS_FM_KINKI,
  FREQS_FM_CHUGOKU,
  FREQS_FM_SHIKOKU,
  FREQS_FM_KYUSHU,
};

const char* const AREAS[AREA_COUNT] = {
  "ﾎｯｶｲﾄﾞｳ",
  "ﾄｳﾎｸ",
  "ｶﾝﾄｳ",
  "ﾁｭｳﾌﾞ",
  "ｷﾝｷ",
  "ﾁｭｳｺﾞｸ",
  "ｼｺｸ",
  "ｷｭｳｼｭｳ",
};


// pointer to *nearest* station entry
FreqMemory const* fptr = 0;

// Run a naive search on the table
// need to call this after changing am/fm or area
void find_station_refresh(uint16_t freq, bool am, uint8_t area) {
  fptr = am ? FREQS_AM[area] : FREQS_FM[area];
  ++fptr;
  if (freq <= fptr->freq) return;

  while (fptr->freq < freq) ++fptr;
}

char const* find_station(uint16_t freq, bool am, uint8_t area) {
  static bool last_am = 0;
  static uint8_t last_area = 255; // invalid area

  if (last_am != am || last_area != area || !fptr) {
    last_am = am;
    last_area = area;
    find_station_refresh(freq, am, area);
    return fptr && (fptr->freq == freq) ? fptr->name : 0;
  }

  if (fptr->freq == freq) return fptr->name;
  else if (freq < fptr->freq) {
    while (1) {
      FreqMemory const* prev = fptr - 1;
      if (prev->freq == freq) {
        fptr = prev;
        break;
      }
      if (freq > prev->freq) {
        break;
      }
      fptr = prev;
    }
  } else {
    while (1) {
      FreqMemory const* next = fptr + 1;
      if (next->freq == freq) {
        fptr = next;
        break;
      }
      if (freq < next->freq) {
        break;
      }
      fptr = next;
    }
  }
  return (fptr->freq == freq) ? fptr->name : 0;
}
