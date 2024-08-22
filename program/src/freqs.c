#include "freqs.h"

#include <stddef.h>
#include "lcd_kana.h"

const FreqMemory FREQS_AM_HOKKAIDO[] = {
  {567, "NHKﾀﾞｲ1"},
  {585, "NHKﾀﾞｲ1"},
  {603, "NHKﾀﾞｲ1"},
  {621, "NHKﾀﾞｲ1"},
  {639, "STVﾗｼﾞｵ"},
  {675, "NHKﾀﾞｲ1"},
  {702, "NHKﾀﾞｲ2"},
  {747, "NHKﾀﾞｲ2"},
  {864, "HBCﾗｼﾞｵ"},
  {882, "STVﾗｼﾞｵ"},
  {900, "HBCﾗｼﾞｵ"},
  {909, "STVﾗｼﾞｵ"},
  {945, "NHKﾀﾞｲ1"},
  {1071, "STVﾗｼﾞｵ"},
  {1125, "NHKﾀﾞｲ2"},
  {1152, "NHKﾀﾞｲ2"},
  {1188, "NHKﾀﾞｲ1"},
  {1197, "STVﾗｼﾞｵ"},
  {1269, "HBCﾗｼﾞｵ"},
  {1287, "HBCﾗｼﾞｵ"},
  {1404, "HBCﾗｼﾞｵ"},
  {1440, "STVﾗｼﾞｵ"},
  {1449, "HBCﾗｼﾞｵ"},
  {1467, "NHKﾀﾞｲ2"},
  {1602, "NHKﾀﾞｲ2"},
  {0, NULL},
};

const FreqMemory FREQS_AM_TOHOKU[] = {
  {531, "NHKﾀﾞｲ1"},
  {540, "NHKﾀﾞｲ1"},
  {684, "IBCﾗｼﾞｵ"},
  {774, "NHKﾀﾞｲ2"},
  {891, "NHKﾀﾞｲ1"},
  {918, "YBCﾗｼﾞｵ"},
  {936, "ABSﾗｼﾞｵ"},
  {963, "NHKﾀﾞｲ1"},
  {1089, "NHKﾀﾞｲ2"},
  {1233, "RABﾗｼﾞｵ"},
  {1260, "TBCﾗｼﾞｵ"},
  {1323, "NHKﾀﾞｲ1"},
  {1386, "NHKﾀﾞｲ2"},
  {1458, "ﾗｼﾞｵﾌｸｼﾏ"},
  {1503, "NHKﾀﾞｲ1"},
  {1521, "NHKﾀﾞｲ2"},
  {1575, "AFN"},
  {1602, "NHKﾀﾞｲ2"},
  {0, NULL},
};

const FreqMemory FREQS_AM_KANTO[] = {
  {594, "NHKﾀﾞｲ1"},
  {693, "NHKﾀﾞｲ2"},
  {765, "YBSﾗｼﾞｵ"},
  {810, "AFN"},
  {927, "NHKﾀﾞｲ1"},
  {954, "TBSﾗｼﾞｵ"},
  {1098, "SBCﾗｼﾞｵ"},
  {1134, "ﾌﾞﾝｶﾎｳｿｳ"},
  {1197, "IBSｲﾊﾞﾗｷﾎｳｿｳ"},
  {1242, "ﾆｯﾎﾟﾝﾎｳｿｳ"},
  {1404, "SBSﾗｼﾞｵ"},
  {1422, "ﾗｼﾞｵﾆｯﾎﾟﾝ"},
  {1530, "CRTﾄﾁｷﾞﾎｳｿｳ"},
  {1602, "NHKﾀﾞｲ2"},
  {0, NULL},
};

const FreqMemory FREQS_AM_CHUBU[] = {
  {639, "NHKﾀﾞｲ2"},
  {648, "NHKﾀﾞｲ1"},
  {729, "NHKﾀﾞｲ1"},
  {738, "KNBﾗｼﾞｵ"},
  {765, "YBSﾗｼﾞｵ"},
  {819, "NHKﾀﾞｲ1"},
  {837, "NHKﾀﾞｲ1"},
  {864, "FBCﾗｼﾞｵ"},
  {882, "NHKﾀﾞｲ1"},
  {909, "NHKﾀﾞｲ2"},
  {927, "NHKﾀﾞｲ1"},
  {1035, "NHKﾀﾞｲ2"},
  {1053, "CBCﾗｼﾞｵ"},
  {1098, "SBCﾗｼﾞｵ"},
  {1107, "MROﾗｼﾞｵ"},
  {1116, "BSNﾗｼﾞｵ"},
  {1224, "NHKﾀﾞｲ1"},
  {1332, "ﾄｳｶｲﾗｼﾞｵ"},
  {1386, "NHKﾀﾞｲ2"},
  {1404, "SBSﾗｼﾞｵ"},
  {1431, "AMｷﾞﾌﾗｼﾞｵ"},
  {1467, "NHKﾀﾞｲ2"},
  {1521, "NHKﾀﾞｲ2"},
  {1593, "NHKﾀﾞｲ2"},
  {0, NULL},
};

const FreqMemory FREQS_AM_KINKI[] = {
  {558, "ﾗｼﾞｵｶﾝｻｲ"},
  {666, "NHKﾀﾞｲ1"},
  {828, "NHKﾀﾞｲ2"},
  {1008, "ABCﾗｼﾞｵ"},
  {1143, "KBSｷｮｳﾄ"},
  {1179, "MBSﾗｼﾞｵ"},
  {1314, "ﾗｼﾞｵｵｵｻｶ"},
  {1431, "WBSﾜｶﾔﾏﾎｳｿｳ"},
  {0, NULL},
};

const FreqMemory FREQS_AM_CHUGOKU[] = {
  {603, "NHKﾀﾞｲ1"},
  {675, "NHKﾀﾞｲ1"},
  {702, "NHKﾀﾞｲ2"},
  {765, "KRYﾗｼﾞｵ"},
  {900, "BSSﾗｼﾞｵ"},
  {1071, "NHKﾀﾞｲ1"},
  {1125, "NHKﾀﾞｲ2"},
  {1296, "NHKﾀﾞｲ1"},
  {1350, "RCCﾗｼﾞｵ"},
  {1368, "NHKﾀﾞｲ1"},
  {1377, "NHKﾀﾞｲ2"},
  {1386, "NHKﾀﾞｲ2"},
  {1494, "RSKﾗｼﾞｵ"},
  {1575, "AFN"},
  {1593, "NHKﾀﾞｲ2"},
  {0, NULL},
};

const FreqMemory FREQS_AM_SHIKOKU[] = {
  {828, "NHKﾀﾞｲ2"},
  {900, "RKCﾗｼﾞｵ"},
  {945, "NHKﾀﾞｲ1"},
  {963, "NHKﾀﾞｲ1"},
  {990, "NHKﾀﾞｲ1"},
  {1035, "NHKﾀﾞｲ2"},
  {1116, "RNBﾗｼﾞｵ"},
  {1152, "NHKﾀﾞｲ2"},
  {1269, "JRTｼｺｸﾎｳｿｳ"},
  {1368, "NHKﾀﾞｲ1"},
  {1449, "RNCﾆｼﾆｯﾎﾟﾝﾎｳｿｳ"},
  {1512, "NHKﾀﾞｲ2"},
  {0, NULL},
};

const FreqMemory FREQS_AM_KYUSHU[] = {
  {540, "NHKﾀﾞｲ1"},
  {549, "NHKﾀﾞｲ1"},
  {576, "NHKﾀﾞｲ1"},
  {612, "NHKﾀﾞｲ1"},
  {639, "NHKﾀﾞｲ1"},
  {648, "AFN"},
  {684, "NHKﾀﾞｲ1"},
  {720, "KBCﾗｼﾞｵ"},
  {738, "RBCiﾗｼﾞｵ"},
  {756, "NHKﾀﾞｲ1"},
  {864, "ROK ﾗｼﾞｵｵｷﾅﾜ"},
  {873, "NHKﾀﾞｲ2"},
  {936, "MRTﾗｼﾞｵ"},
  {963, "NHKﾀﾞｲ1"},
  {1017, "NHKﾀﾞｲ2"},
  {1098, "OBSﾗｼﾞｵ"},
  {1107, "MBCﾗｼﾞｵ"},
  {1125, "NHKﾀﾞｲ2"},
  {1197, "RKBﾗｼﾞｵ"},
  {1233, "NBCﾗｼﾞｵ"},
  {1278, "RKBﾗｼﾞｵ"},
  {1377, "NHKﾀﾞｲ2"},
  {1386, "NHKﾀﾞｲ2"},
  {1413, "KBCﾗｼﾞｵ"},
  {1467, "NHKﾀﾞｲ2"},
  {1575, "AFN"},
  {1602, "NHKﾀﾞｲ2"},
  {0, NULL},
};


const FreqMemory FREQS_FM_HOKKAIDO[] = {
  {764, "AIR-G'"},
  {785, "AIR-G'"},
  {794, "NORTH WAVE"},
  {798, "NORTH WAVE"},
  {804, "AIR-G'"},
  {807, "NORTH WAVE"},
  {825, "NORTH WAVE"},
  {821, "NORTH WAVE"},
  {831, "AIR-G'"},
  {852, "NHK-FM"},
  {858, "NHK-FM"},
  {864, "AIR-G'"},
  {860, "NHK-FM"},
  {870, "NHK-FM"},
  {875, "NHK-FM"},
  {880, "NHK-FM"},
  {885, "NHK-FM"},
  {888, "AIR-G'"},
  {894, "AIR-G'"},
  {0, NULL},
};

const FreqMemory FREQS_FM_TOHOKU[] = {
  {761, "ｴﾌｴﾑｲﾜﾃ"},
  {771, "Date fm"},
  {800, "ｴﾌｴﾑｱｵﾓﾘ"},
  {804, "ｴﾌｴﾑﾔﾏｶﾞﾀ"},
  {818, "ﾌｸｼﾏFM"},
  {821, "NHK-FM"},
  {825, "NHK-FM"},
  {828, "ｴﾌｴﾑｱｷﾀ"},
  {831, "NHK-FM"},
  {853, "NHK-FM"},
  {860, "NHK-FM"},
  {867, "NHK-FM"},
  {0, NULL},
};

const FreqMemory FREQS_FM_KANTO[] = {
  {761, "InterFM"},
  {764, "RADIO BERRY"},
  {780, "bayfm"},
  {788, "ﾎｳｿｳﾀﾞｲｶﾞｸ"},
  {792, "K-MIX"},
  {795, "FM NACK5"},
  {797, "FMﾅｶﾞﾉ"},
  {800, "TOKYO FM"},
  {807, "NHK-FM"},
  {803, "NHK-FM"},
  {813, "J-WAVE"},
  {816, "NHK-FM"},
  {819, "NHK-FM"},
  {825, "NHK-FM"},
  {832, "NHK-FM"},
  {830, "FM-FUJI"},
  {847, "FMﾖｺﾊﾏ"},
  {851, "NHK-FM"},
  {856, "NHK-FM"},
  {863, "FMｸﾞﾝﾏ"},
  {0, NULL},
};

const FreqMemory FREQS_FM_CHUBU[] = {
  {761, "FMﾌｸｲ"},
  {778, "ZIP-FM"},
  {775, "FM-NIIGATA"},
  {789, "ﾚﾃﾞｨｵｷｭｰﾌﾞFMﾐｴ"},
  {790, "FM PORT"},
  {792, "K-MIX"},
  {797, "FMﾅｶﾞﾉ"},
  {800, "Radio 80"},
  {805, "ｴﾌｴﾑｲｼｶﾜ"},
  {807, "FM AICHI"},
  {818, "NHK-FM"},
  {815, "NHK-FM"},
  {822, "NHK-FM"},
  {823, "NHK-FM"},
  {825, "NHK-FM"},
  {827, "FMﾄﾔﾏ"},
  {830, "FM-FUJI"},
  {836, "NHK-FM"},
  {834, "NHK-FM"},
  {840, "NHK-FM"},
  {888, "NHK-FM"},
  {0, NULL},
};

const FreqMemory FREQS_FM_KINKI[] = {
  {765, "FM COCOLO"},
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
  {899, "Kiss-FM KOBE"},
  {0, NULL},
};

const FreqMemory FREQS_FM_CHUGOKU[] = {
  {768, "FMｵｶﾔﾏ"},
  {774, "V-air ｴﾌｴﾑｻﾝｲﾝ"},
  {788, "V-air ｴﾌｴﾑｻﾝｲﾝ"},
  {782, "HFM"},
  {792, "ｴﾌｴﾑﾔﾏｸﾞﾁ"},
  {845, "NHK-FM"},
  {858, "NHK-FM"},
  {853, "NHK-FM"},
  {887, "NHK-FM"},
  {883, "NHK-FM"},
  {0, NULL},
};

const FreqMemory FREQS_FM_SHIKOKU[] = {
  {786, "FMｶｶﾞﾜ"},
  {797, "FMｴﾋﾒ"},
  {807, "ｴﾌｴﾑﾄｸｼﾏ"},
  {816, "FMｺｳﾁ"},
  {834, "NHK-FM"},
  {860, "NHK-FM"},
  {877, "NHK-FM"},
  {875, "NHK-FM"},
  {0, NULL},
};

const FreqMemory FREQS_FM_KYUSHU[] = {
  {761, "LOVE FM"},
  {770, "CROSS FM"},
  {774, "FMK ｴﾌｴﾑ･ｸﾏﾓﾄ"},
  {779, "ｴﾌｴﾑｻｶﾞ"},
  {787, "CROSS FM"},
  {795, "ｴﾌｴﾑﾅｶﾞｻｷ"},
  {798, "μ-FM ｴﾌｴﾑｶｺﾞｼﾏ"},
  {800, "fm fukuoka"},
  {801, "ROK ﾗｼﾞｵｵｷﾅﾜ"},
  {803, "NHKﾀﾞｲ2"},
  {807, "fm fukuoka"},
  {813, "NHKﾀﾞｲ1"},
  {816, "NHK-FM"},
  {826, "RBCiﾗｼﾞｵ"},
  {827, "LOVE FM"},
  {832, "JOY FM FMﾐﾔｻﾞｷ"},
  {835, "NHKﾀﾞｲ1"},
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
  {0, NULL},
};

const FreqMemory* const FREQS_AM[8] = {
  FREQS_AM_HOKKAIDO,
  FREQS_AM_TOHOKU,
  FREQS_AM_KANTO,
  FREQS_AM_CHUBU,
  FREQS_AM_KINKI,
  FREQS_AM_CHUGOKU,
  FREQS_AM_SHIKOKU,
  FREQS_AM_KYUSHU,
};

const FreqMemory* const FREQS_FM[8] = {
  FREQS_FM_HOKKAIDO,
  FREQS_FM_TOHOKU,
  FREQS_FM_KANTO,
  FREQS_FM_CHUBU,
  FREQS_FM_KINKI,
  FREQS_FM_CHUGOKU,
  FREQS_FM_SHIKOKU,
  FREQS_FM_KYUSHU,
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
