#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define LOWER_UPPER_CNT   666
#define UPPER_LOWER_CNT   666
#define UNACCENT_CNT     1339

typedef struct {
    unsigned int   from_code;
    unsigned short cnt;
    int            to_offset;
   } CONV_T;

typedef struct {
    unsigned int from_code;
    unsigned int to_code;
   } CONV2_T;

// Conversion tables were automatically generated from
// the unicode names
static CONV_T G_lower_to_upper[UPPER_LOWER_CNT] =
   {{97,26,-32},{223,1,7615},{224,23,-32},
    {248,7,-32},{255,1,121},{257,1,-1},
    {259,1,-1},{261,1,-1},{263,1,-1},
    {265,1,-1},{267,1,-1},{269,1,-1},
    {271,1,-1},{273,1,-1},{275,1,-1},
    {277,1,-1},{279,1,-1},{281,1,-1},
    {283,1,-1},{285,1,-1},{287,1,-1},
    {289,1,-1},{291,1,-1},{293,1,-1},
    {295,1,-1},{297,1,-1},{299,1,-1},
    {301,1,-1},{303,1,-1},{307,1,-1},
    {309,1,-1},{311,1,-1},{314,1,-1},
    {316,1,-1},{318,1,-1},{320,1,-1},
    {322,1,-1},{324,1,-1},{326,1,-1},
    {328,1,-1},{331,1,-1},{333,1,-1},
    {335,1,-1},{337,1,-1},{339,1,-1},
    {341,1,-1},{343,1,-1},{345,1,-1},
    {347,1,-1},{349,1,-1},{351,1,-1},
    {353,1,-1},{355,1,-1},{357,1,-1},
    {359,1,-1},{361,1,-1},{363,1,-1},
    {365,1,-1},{367,1,-1},{369,1,-1},
    {371,1,-1},{373,1,-1},{375,1,-1},
    {378,1,-1},{380,1,-1},{382,1,-1},
    {384,1,195},{387,1,-1},{389,1,-1},
    {392,1,-1},{396,1,-1},{402,1,-1},
    {409,1,-1},{410,1,163},{414,1,130},
    {417,1,-1},{419,1,-1},{421,1,-1},
    {424,1,-1},{429,1,-1},{432,1,-1},
    {436,1,-1},{438,1,-1},{441,1,-1},
    {445,1,-1},{454,1,-2},{457,1,-2},
    {460,1,-2},{462,1,-1},{464,1,-1},
    {466,1,-1},{468,1,-1},{470,1,-1},
    {472,1,-1},{474,1,-1},{476,1,-1},
    {479,1,-1},{481,1,-1},{483,1,-1},
    {485,1,-1},{487,1,-1},{489,1,-1},
    {491,1,-1},{493,1,-1},{495,1,-1},
    {499,1,-2},{501,1,-1},{505,1,-1},
    {507,1,-1},{509,1,-1},{511,1,-1},
    {513,1,-1},{515,1,-1},{517,1,-1},
    {519,1,-1},{521,1,-1},{523,1,-1},
    {525,1,-1},{527,1,-1},{529,1,-1},
    {531,1,-1},{533,1,-1},{535,1,-1},
    {537,1,-1},{539,1,-1},{541,1,-1},
    {543,1,-1},{547,1,-1},{549,1,-1},
    {551,1,-1},{553,1,-1},{555,1,-1},
    {557,1,-1},{559,1,-1},{561,1,-1},
    {563,1,-1},{572,1,-1},{575,2,10815},
    {578,1,-1},{583,1,-1},{585,1,-1},
    {589,1,-1},{591,1,-1},{592,1,10783},
    {593,1,10780},{594,1,10782},{595,1,-210},
    {596,1,-206},{599,1,-205},{600,2,-202},
    {603,1,-203},{604,1,42319},{608,1,-205},
    {609,1,42315},{611,1,-207},{613,1,42280},
    {614,1,42308},{616,1,-209},{617,1,-211},
    {619,1,10743},{620,1,42305},{623,1,-211},
    {625,1,10749},{626,1,-213},{637,1,10727},
    {643,1,-218},{647,1,42282},{648,1,-218},
    {649,1,-69},{650,2,-217},{652,1,-71},
    {658,1,-219},{670,1,42258},{688,1,6788},
    {690,1,6788},{691,1,6796},{695,1,6795},
    {737,1,6743},{881,1,-1},{883,1,-1},
    {887,1,-1},{891,3,130},{940,1,-38},
    {941,3,-37},{945,17,-32},{963,9,-32},
    {972,1,-64},{973,2,-63},{995,1,-1},
    {997,1,-1},{999,1,-1},{1001,1,-1},
    {1003,1,-1},{1005,1,-1},{1007,1,-1},
    {1016,1,-1},{1019,1,-1},{1072,32,-32},
    {1104,16,-80},{1121,1,-1},{1123,1,-1},
    {1125,1,-1},{1127,1,-1},{1129,1,-1},
    {1131,1,-1},{1133,1,-1},{1135,1,-1},
    {1137,1,-1},{1139,1,-1},{1141,1,-1},
    {1143,1,-1},{1145,1,-1},{1147,1,-1},
    {1149,1,-1},{1151,1,-1},{1153,1,-1},
    {1163,1,-1},{1165,1,-1},{1167,1,-1},
    {1169,1,-1},{1171,1,-1},{1173,1,-1},
    {1175,1,-1},{1177,1,-1},{1179,1,-1},
    {1181,1,-1},{1183,1,-1},{1185,1,-1},
    {1187,1,-1},{1189,1,-1},{1191,1,-1},
    {1193,1,-1},{1195,1,-1},{1197,1,-1},
    {1199,1,-1},{1201,1,-1},{1203,1,-1},
    {1205,1,-1},{1207,1,-1},{1209,1,-1},
    {1211,1,-1},{1213,1,-1},{1215,1,-1},
    {1218,1,-1},{1220,1,-1},{1222,1,-1},
    {1224,1,-1},{1226,1,-1},{1228,1,-1},
    {1230,1,-1},{1233,1,-1},{1235,1,-1},
    {1237,1,-1},{1239,1,-1},{1241,1,-1},
    {1243,1,-1},{1245,1,-1},{1247,1,-1},
    {1249,1,-1},{1251,1,-1},{1253,1,-1},
    {1255,1,-1},{1257,1,-1},{1259,1,-1},
    {1261,1,-1},{1263,1,-1},{1265,1,-1},
    {1267,1,-1},{1269,1,-1},{1271,1,-1},
    {1273,1,-1},{1275,1,-1},{1277,1,-1},
    {1279,1,-1},{1281,1,-1},{1283,1,-1},
    {1285,1,-1},{1287,1,-1},{1289,1,-1},
    {1291,1,-1},{1293,1,-1},{1295,1,-1},
    {1297,1,-1},{1299,1,-1},{1301,1,-1},
    {1303,1,-1},{1305,1,-1},{1307,1,-1},
    {1309,1,-1},{1311,1,-1},{1313,1,-1},
    {1315,1,-1},{1317,1,-1},{1319,1,-1},
    {1321,1,-1},{1323,1,-1},{1325,1,-1},
    {1327,1,-1},{1377,38,-48},{7491,1,-23},
    {7495,1,-25},{7496,2,-24},{7501,1,-26},
    {7503,1,-24},{7504,1,-23},{7506,1,-22},
    {7510,1,-24},{7511,2,-23},{7515,1,3874},
    {7545,1,35332},{7549,1,3814},{7681,1,-1},
    {7683,1,-1},{7685,1,-1},{7687,1,-1},
    {7689,1,-1},{7691,1,-1},{7693,1,-1},
    {7695,1,-1},{7697,1,-1},{7699,1,-1},
    {7701,1,-1},{7703,1,-1},{7705,1,-1},
    {7707,1,-1},{7709,1,-1},{7711,1,-1},
    {7713,1,-1},{7715,1,-1},{7717,1,-1},
    {7719,1,-1},{7721,1,-1},{7723,1,-1},
    {7725,1,-1},{7727,1,-1},{7729,1,-1},
    {7731,1,-1},{7733,1,-1},{7735,1,-1},
    {7737,1,-1},{7739,1,-1},{7741,1,-1},
    {7743,1,-1},{7745,1,-1},{7747,1,-1},
    {7749,1,-1},{7751,1,-1},{7753,1,-1},
    {7755,1,-1},{7757,1,-1},{7759,1,-1},
    {7761,1,-1},{7763,1,-1},{7765,1,-1},
    {7767,1,-1},{7769,1,-1},{7771,1,-1},
    {7773,1,-1},{7775,1,-1},{7777,1,-1},
    {7779,1,-1},{7781,1,-1},{7783,1,-1},
    {7785,1,-1},{7787,1,-1},{7789,1,-1},
    {7791,1,-1},{7793,1,-1},{7795,1,-1},
    {7797,1,-1},{7799,1,-1},{7801,1,-1},
    {7803,1,-1},{7805,1,-1},{7807,1,-1},
    {7809,1,-1},{7811,1,-1},{7813,1,-1},
    {7815,1,-1},{7817,1,-1},{7819,1,-1},
    {7821,1,-1},{7823,1,-1},{7825,1,-1},
    {7827,1,-1},{7829,1,-1},{7841,1,-1},
    {7843,1,-1},{7845,1,-1},{7847,1,-1},
    {7849,1,-1},{7851,1,-1},{7853,1,-1},
    {7855,1,-1},{7857,1,-1},{7859,1,-1},
    {7861,1,-1},{7863,1,-1},{7865,1,-1},
    {7867,1,-1},{7869,1,-1},{7871,1,-1},
    {7873,1,-1},{7875,1,-1},{7877,1,-1},
    {7879,1,-1},{7881,1,-1},{7883,1,-1},
    {7885,1,-1},{7887,1,-1},{7889,1,-1},
    {7891,1,-1},{7893,1,-1},{7895,1,-1},
    {7897,1,-1},{7899,1,-1},{7901,1,-1},
    {7903,1,-1},{7905,1,-1},{7907,1,-1},
    {7909,1,-1},{7911,1,-1},{7913,1,-1},
    {7915,1,-1},{7917,1,-1},{7919,1,-1},
    {7921,1,-1},{7923,1,-1},{7925,1,-1},
    {7927,1,-1},{7929,1,-1},{7931,1,-1},
    {7933,1,-1},{7935,1,-1},{7936,8,8},
    {7952,6,8},{7968,8,8},{7984,8,8},
    {8000,6,8},{8017,1,8},{8019,1,8},
    {8021,1,8},{8023,1,8},{8032,8,8},
    {8048,2,74},{8050,4,86},{8054,2,100},
    {8056,2,128},{8058,2,112},{8060,2,126},
    {8112,2,8},{8144,2,8},{8160,2,8},
    {8165,1,7},{8467,1,-1},{8495,1,1},
    {8508,1,3},{8509,1,1},{8518,1,-1},
    {8526,1,-28},{9372,26,117876},{9424,26,-26},
    {11312,36,-48},{11350,1,-48},{11352,7,-48},
    {11361,1,-1},{11365,1,-10795},{11366,1,-10792},
    {11368,1,-1},{11370,1,-1},{11372,1,-1},
    {11379,1,-1},{11382,1,-1},{11393,1,-1},
    {11395,1,-1},{11397,1,-1},{11399,1,-1},
    {11401,1,-1},{11403,1,-1},{11405,1,-1},
    {11407,1,-1},{11409,1,-1},{11411,1,-1},
    {11413,1,-1},{11415,1,-1},{11417,1,-1},
    {11419,1,-1},{11421,1,-1},{11423,1,-1},
    {11425,1,-1},{11427,1,-1},{11429,1,-1},
    {11431,1,-1},{11433,1,-1},{11435,1,-1},
    {11437,1,-1},{11439,1,-1},{11441,1,-1},
    {11443,1,-1},{11445,1,-1},{11447,1,-1},
    {11449,1,-1},{11451,1,-1},{11453,1,-1},
    {11455,1,-1},{11457,1,-1},{11459,1,-1},
    {11461,1,-1},{11463,1,-1},{11465,1,-1},
    {11467,1,-1},{11469,1,-1},{11471,1,-1},
    {11473,1,-1},{11475,1,-1},{11477,1,-1},
    {11479,1,-1},{11481,1,-1},{11483,1,-1},
    {11485,1,-1},{11487,1,-1},{11489,1,-1},
    {11491,1,-1},{11500,1,-1},{11502,1,-1},
    {11507,1,-1},{11520,38,-7264},{11559,1,-7264},
    {11565,1,-7264},{42561,1,-1},{42563,1,-1},
    {42565,1,-1},{42567,1,-1},{42569,1,-1},
    {42571,1,-1},{42573,1,-1},{42575,1,-1},
    {42577,1,-1},{42579,1,-1},{42581,1,-1},
    {42583,1,-1},{42585,1,-1},{42587,1,-1},
    {42589,1,-1},{42591,1,-1},{42593,1,-1},
    {42595,1,-1},{42597,1,-1},{42599,1,-1},
    {42601,1,-1},{42603,1,-1},{42605,1,-1},
    {42625,1,-1},{42627,1,-1},{42629,1,-1},
    {42631,1,-1},{42633,1,-1},{42635,1,-1},
    {42637,1,-1},{42639,1,-1},{42641,1,-1},
    {42643,1,-1},{42645,1,-1},{42647,1,-1},
    {42649,1,-1},{42651,1,-1},{42787,1,-1},
    {42789,1,-1},{42791,1,-1},{42793,1,-1},
    {42795,1,-1},{42797,1,-1},{42799,1,-1},
    {42803,1,-1},{42805,1,-1},{42807,1,-1},
    {42809,1,-1},{42811,1,-1},{42813,1,-1},
    {42815,1,-1},{42817,1,-1},{42819,1,-1},
    {42821,1,-1},{42823,1,-1},{42825,1,-1},
    {42827,1,-1},{42829,1,-1},{42831,1,-1},
    {42833,1,-1},{42835,1,-1},{42837,1,-1},
    {42839,1,-1},{42841,1,-1},{42843,1,-1},
    {42845,1,-1},{42847,1,-1},{42849,1,-1},
    {42851,1,-1},{42853,1,-1},{42855,1,-1},
    {42857,1,-1},{42859,1,-1},{42861,1,-1},
    {42863,1,-1},{42874,1,-1},{42876,1,-1},
    {42879,1,-1},{42881,1,-1},{42883,1,-1},
    {42885,1,-1},{42887,1,-1},{42892,1,-1},
    {42897,1,-1},{42899,1,-1},{42903,1,-1},
    {42905,1,-1},{42907,1,-1},{42909,1,-1},
    {42911,1,-1},{42913,1,-1},{42915,1,-1},
    {42917,1,-1},{42919,1,-1},{42921,1,-1},
    {65345,26,-32},{66600,40,-40},{71872,32,-32},
    {119834,26,-26},{119886,7,-26},{119894,18,-26},
    {119938,26,-26},{119990,1,-26},{119992,2,-26},
    {119999,2,-26},{120003,1,-26},{120005,2,-26},
    {120008,8,-26},{120042,26,-26},{120094,2,-26},
    {120097,4,-26},{120103,8,-26},{120112,7,-26},
    {120146,2,-26},{120149,4,-26},{120154,5,-26},
    {120160,1,-26},{120164,7,-26},{120198,26,-26},
    {120250,26,-26},{120302,26,-26},{120354,26,-26},
    {120406,26,-26},{120458,26,-26},{120514,17,-26},
    {120532,7,-26},{120572,17,-26},{120590,7,-26},
    {120630,17,-26},{120648,7,-26},{120688,17,-26},
    {120706,7,-26},{120746,17,-26},{120764,7,-26},
    {120779,1,-1},{128289,1,-1},{917601,26,-32}};

static CONV_T G_upper_to_lower[UPPER_LOWER_CNT] =
   {{65,26,32},{192,23,32},{216,7,32},
    {256,1,1},{258,1,1},{260,1,1},
    {262,1,1},{264,1,1},{266,1,1},
    {268,1,1},{270,1,1},{272,1,1},
    {274,1,1},{276,1,1},{278,1,1},
    {280,1,1},{282,1,1},{284,1,1},
    {286,1,1},{288,1,1},{290,1,1},
    {292,1,1},{294,1,1},{296,1,1},
    {298,1,1},{300,1,1},{302,1,1},
    {306,1,1},{308,1,1},{310,1,1},
    {313,1,1},{315,1,1},{317,1,1},
    {319,1,1},{321,1,1},{323,1,1},
    {325,1,1},{327,1,1},{330,1,1},
    {332,1,1},{334,1,1},{336,1,1},
    {338,1,1},{340,1,1},{342,1,1},
    {344,1,1},{346,1,1},{348,1,1},
    {350,1,1},{352,1,1},{354,1,1},
    {356,1,1},{358,1,1},{360,1,1},
    {362,1,1},{364,1,1},{366,1,1},
    {368,1,1},{370,1,1},{372,1,1},
    {374,1,1},{376,1,-121},{377,1,1},
    {379,1,1},{381,1,1},{385,1,210},
    {386,1,1},{388,1,1},{390,1,206},
    {391,1,1},{394,1,205},{395,1,1},
    {398,2,202},{400,1,203},{401,1,1},
    {403,1,205},{404,1,207},{406,1,211},
    {407,1,209},{408,1,1},{412,1,211},
    {413,1,213},{416,1,1},{418,1,1},
    {420,1,1},{423,1,1},{425,1,218},
    {428,1,1},{430,1,218},{431,1,1},
    {433,2,217},{435,1,1},{437,1,1},
    {439,1,219},{440,1,1},{444,1,1},
    {452,1,2},{455,1,2},{458,1,2},
    {461,1,1},{463,1,1},{465,1,1},
    {467,1,1},{469,1,1},{471,1,1},
    {473,1,1},{475,1,1},{478,1,1},
    {480,1,1},{482,1,1},{484,1,1},
    {486,1,1},{488,1,1},{490,1,1},
    {492,1,1},{494,1,1},{497,1,2},
    {500,1,1},{504,1,1},{506,1,1},
    {508,1,1},{510,1,1},{512,1,1},
    {514,1,1},{516,1,1},{518,1,1},
    {520,1,1},{522,1,1},{524,1,1},
    {526,1,1},{528,1,1},{530,1,1},
    {532,1,1},{534,1,1},{536,1,1},
    {538,1,1},{540,1,1},{542,1,1},
    {544,1,-130},{546,1,1},{548,1,1},
    {550,1,1},{552,1,1},{554,1,1},
    {556,1,1},{558,1,1},{560,1,1},
    {562,1,1},{570,1,10795},{571,1,1},
    {573,1,-163},{574,1,10792},{577,1,1},
    {579,1,-195},{580,1,69},{581,1,71},
    {582,1,1},{584,1,1},{588,1,1},
    {590,1,1},{880,1,1},{882,1,1},
    {886,1,1},{902,1,38},{904,3,37},
    {908,1,64},{910,2,63},{913,17,32},
    {931,9,32},{994,1,1},{996,1,1},
    {998,1,1},{1000,1,1},{1002,1,1},
    {1004,1,1},{1006,1,1},{1015,1,1},
    {1018,1,1},{1021,3,-130},{1024,16,80},
    {1040,32,32},{1120,1,1},{1122,1,1},
    {1124,1,1},{1126,1,1},{1128,1,1},
    {1130,1,1},{1132,1,1},{1134,1,1},
    {1136,1,1},{1138,1,1},{1140,1,1},
    {1142,1,1},{1144,1,1},{1146,1,1},
    {1148,1,1},{1150,1,1},{1152,1,1},
    {1162,1,1},{1164,1,1},{1166,1,1},
    {1168,1,1},{1170,1,1},{1172,1,1},
    {1174,1,1},{1176,1,1},{1178,1,1},
    {1180,1,1},{1182,1,1},{1184,1,1},
    {1186,1,1},{1188,1,1},{1190,1,1},
    {1192,1,1},{1194,1,1},{1196,1,1},
    {1198,1,1},{1200,1,1},{1202,1,1},
    {1204,1,1},{1206,1,1},{1208,1,1},
    {1210,1,1},{1212,1,1},{1214,1,1},
    {1217,1,1},{1219,1,1},{1221,1,1},
    {1223,1,1},{1225,1,1},{1227,1,1},
    {1229,1,1},{1232,1,1},{1234,1,1},
    {1236,1,1},{1238,1,1},{1240,1,1},
    {1242,1,1},{1244,1,1},{1246,1,1},
    {1248,1,1},{1250,1,1},{1252,1,1},
    {1254,1,1},{1256,1,1},{1258,1,1},
    {1260,1,1},{1262,1,1},{1264,1,1},
    {1266,1,1},{1268,1,1},{1270,1,1},
    {1272,1,1},{1274,1,1},{1276,1,1},
    {1278,1,1},{1280,1,1},{1282,1,1},
    {1284,1,1},{1286,1,1},{1288,1,1},
    {1290,1,1},{1292,1,1},{1294,1,1},
    {1296,1,1},{1298,1,1},{1300,1,1},
    {1302,1,1},{1304,1,1},{1306,1,1},
    {1308,1,1},{1310,1,1},{1312,1,1},
    {1314,1,1},{1316,1,1},{1318,1,1},
    {1320,1,1},{1322,1,1},{1324,1,1},
    {1326,1,1},{1329,38,48},{4256,38,7264},
    {4295,1,7264},{4301,1,7264},{7468,1,23},
    {7470,1,25},{7472,2,24},{7475,1,26},
    {7476,1,-6788},{7478,1,-6788},{7479,1,24},
    {7480,1,-6743},{7481,1,23},{7484,1,22},
    {7486,1,24},{7487,1,-6796},{7488,2,23},
    {7490,1,-6795},{7680,1,1},{7682,1,1},
    {7684,1,1},{7686,1,1},{7688,1,1},
    {7690,1,1},{7692,1,1},{7694,1,1},
    {7696,1,1},{7698,1,1},{7700,1,1},
    {7702,1,1},{7704,1,1},{7706,1,1},
    {7708,1,1},{7710,1,1},{7712,1,1},
    {7714,1,1},{7716,1,1},{7718,1,1},
    {7720,1,1},{7722,1,1},{7724,1,1},
    {7726,1,1},{7728,1,1},{7730,1,1},
    {7732,1,1},{7734,1,1},{7736,1,1},
    {7738,1,1},{7740,1,1},{7742,1,1},
    {7744,1,1},{7746,1,1},{7748,1,1},
    {7750,1,1},{7752,1,1},{7754,1,1},
    {7756,1,1},{7758,1,1},{7760,1,1},
    {7762,1,1},{7764,1,1},{7766,1,1},
    {7768,1,1},{7770,1,1},{7772,1,1},
    {7774,1,1},{7776,1,1},{7778,1,1},
    {7780,1,1},{7782,1,1},{7784,1,1},
    {7786,1,1},{7788,1,1},{7790,1,1},
    {7792,1,1},{7794,1,1},{7796,1,1},
    {7798,1,1},{7800,1,1},{7802,1,1},
    {7804,1,1},{7806,1,1},{7808,1,1},
    {7810,1,1},{7812,1,1},{7814,1,1},
    {7816,1,1},{7818,1,1},{7820,1,1},
    {7822,1,1},{7824,1,1},{7826,1,1},
    {7828,1,1},{7838,1,-7615},{7840,1,1},
    {7842,1,1},{7844,1,1},{7846,1,1},
    {7848,1,1},{7850,1,1},{7852,1,1},
    {7854,1,1},{7856,1,1},{7858,1,1},
    {7860,1,1},{7862,1,1},{7864,1,1},
    {7866,1,1},{7868,1,1},{7870,1,1},
    {7872,1,1},{7874,1,1},{7876,1,1},
    {7878,1,1},{7880,1,1},{7882,1,1},
    {7884,1,1},{7886,1,1},{7888,1,1},
    {7890,1,1},{7892,1,1},{7894,1,1},
    {7896,1,1},{7898,1,1},{7900,1,1},
    {7902,1,1},{7904,1,1},{7906,1,1},
    {7908,1,1},{7910,1,1},{7912,1,1},
    {7914,1,1},{7916,1,1},{7918,1,1},
    {7920,1,1},{7922,1,1},{7924,1,1},
    {7926,1,1},{7928,1,1},{7930,1,1},
    {7932,1,1},{7934,1,1},{7944,8,-8},
    {7960,6,-8},{7976,8,-8},{7992,8,-8},
    {8008,6,-8},{8025,1,-8},{8027,1,-8},
    {8029,1,-8},{8031,1,-8},{8040,8,-8},
    {8120,2,-8},{8122,2,-74},{8136,4,-86},
    {8152,2,-8},{8154,2,-100},{8168,2,-8},
    {8170,2,-112},{8172,1,-7},{8184,2,-128},
    {8186,2,-126},{8466,1,1},{8496,1,-1},
    {8498,1,28},{8510,1,-1},{8511,1,-3},
    {8517,1,1},{9398,26,26},{11264,36,48},
    {11302,1,48},{11304,7,48},{11360,1,1},
    {11362,1,-10743},{11363,1,-3814},{11364,1,-10727},
    {11367,1,1},{11369,1,1},{11371,1,1},
    {11373,1,-10780},{11374,1,-10749},{11375,1,-10783},
    {11376,1,-10782},{11378,1,1},{11381,1,1},
    {11389,1,-3874},{11390,2,-10815},{11392,1,1},
    {11394,1,1},{11396,1,1},{11398,1,1},
    {11400,1,1},{11402,1,1},{11404,1,1},
    {11406,1,1},{11408,1,1},{11410,1,1},
    {11412,1,1},{11414,1,1},{11416,1,1},
    {11418,1,1},{11420,1,1},{11422,1,1},
    {11424,1,1},{11426,1,1},{11428,1,1},
    {11430,1,1},{11432,1,1},{11434,1,1},
    {11436,1,1},{11438,1,1},{11440,1,1},
    {11442,1,1},{11444,1,1},{11446,1,1},
    {11448,1,1},{11450,1,1},{11452,1,1},
    {11454,1,1},{11456,1,1},{11458,1,1},
    {11460,1,1},{11462,1,1},{11464,1,1},
    {11466,1,1},{11468,1,1},{11470,1,1},
    {11472,1,1},{11474,1,1},{11476,1,1},
    {11478,1,1},{11480,1,1},{11482,1,1},
    {11484,1,1},{11486,1,1},{11488,1,1},
    {11490,1,1},{11499,1,1},{11501,1,1},
    {11506,1,1},{42560,1,1},{42562,1,1},
    {42564,1,1},{42566,1,1},{42568,1,1},
    {42570,1,1},{42572,1,1},{42574,1,1},
    {42576,1,1},{42578,1,1},{42580,1,1},
    {42582,1,1},{42584,1,1},{42586,1,1},
    {42588,1,1},{42590,1,1},{42592,1,1},
    {42594,1,1},{42596,1,1},{42598,1,1},
    {42600,1,1},{42602,1,1},{42604,1,1},
    {42624,1,1},{42626,1,1},{42628,1,1},
    {42630,1,1},{42632,1,1},{42634,1,1},
    {42636,1,1},{42638,1,1},{42640,1,1},
    {42642,1,1},{42644,1,1},{42646,1,1},
    {42648,1,1},{42650,1,1},{42786,1,1},
    {42788,1,1},{42790,1,1},{42792,1,1},
    {42794,1,1},{42796,1,1},{42798,1,1},
    {42802,1,1},{42804,1,1},{42806,1,1},
    {42808,1,1},{42810,1,1},{42812,1,1},
    {42814,1,1},{42816,1,1},{42818,1,1},
    {42820,1,1},{42822,1,1},{42824,1,1},
    {42826,1,1},{42828,1,1},{42830,1,1},
    {42832,1,1},{42834,1,1},{42836,1,1},
    {42838,1,1},{42840,1,1},{42842,1,1},
    {42844,1,1},{42846,1,1},{42848,1,1},
    {42850,1,1},{42852,1,1},{42854,1,1},
    {42856,1,1},{42858,1,1},{42860,1,1},
    {42862,1,1},{42873,1,1},{42875,1,1},
    {42877,1,-35332},{42878,1,1},{42880,1,1},
    {42882,1,1},{42884,1,1},{42886,1,1},
    {42891,1,1},{42893,1,-42280},{42896,1,1},
    {42898,1,1},{42902,1,1},{42904,1,1},
    {42906,1,1},{42908,1,1},{42910,1,1},
    {42912,1,1},{42914,1,1},{42916,1,1},
    {42918,1,1},{42920,1,1},{42922,1,-42308},
    {42923,1,-42319},{42924,1,-42315},{42925,1,-42305},
    {42928,1,-42258},{42929,1,-42282},{65313,26,32},
    {66560,40,40},{71840,32,32},{119808,26,26},
    {119860,7,26},{119868,18,26},{119912,26,26},
    {119964,1,26},{119966,2,26},{119973,2,26},
    {119977,1,26},{119979,2,26},{119982,8,26},
    {120016,26,26},{120068,2,26},{120071,4,26},
    {120077,8,26},{120086,7,26},{120120,2,26},
    {120123,4,26},{120128,5,26},{120134,1,26},
    {120138,7,26},{120172,26,26},{120224,26,26},
    {120276,26,26},{120328,26,26},{120380,26,26},
    {120432,26,26},{120488,17,26},{120506,7,26},
    {120546,17,26},{120564,7,26},{120604,17,26},
    {120622,7,26},{120662,17,26},{120680,7,26},
    {120720,17,26},{120738,7,26},{120778,1,1},
    {127248,26,-117876},{128288,1,1},{917569,26,32}};

static CONV2_T G_unaccent[UNACCENT_CNT] =
   {{192,65},{193,65},{194,65},{195,65},{196,65},
    {197,65},{199,67},{200,69},{201,69},{202,69},
    {203,69},{204,73},{205,73},{206,73},{207,73},
    {209,78},{210,79},{211,79},{212,79},{213,79},
    {214,79},{216,79},{217,85},{218,85},{219,85},
    {220,85},{221,89},{224,97},{225,97},{226,97},
    {227,97},{228,97},{229,97},{231,99},{232,101},
    {233,101},{234,101},{235,101},{236,105},{237,105},
    {238,105},{239,105},{241,110},{242,111},{243,111},
    {244,111},{245,111},{246,111},{248,111},{249,117},
    {250,117},{251,117},{252,117},{253,121},{255,121},
    {256,65},{257,97},{258,65},{259,97},{260,65},
    {261,97},{262,67},{263,99},{264,67},{265,99},
    {266,67},{267,99},{268,67},{269,99},{270,68},
    {271,100},{272,68},{273,100},{274,69},{275,101},
    {276,69},{277,101},{278,69},{279,101},{280,69},
    {281,101},{282,69},{283,101},{284,71},{285,103},
    {286,71},{287,103},{288,71},{289,103},{290,71},
    {291,103},{292,72},{293,104},{294,72},{295,104},
    {296,73},{297,105},{298,73},{299,105},{300,73},
    {301,105},{302,73},{303,105},{304,73},{308,74},
    {309,106},{310,75},{311,107},{313,76},{314,108},
    {315,76},{316,108},{317,76},{318,108},{319,76},
    {320,108},{321,76},{322,108},{323,78},{324,110},
    {325,78},{326,110},{327,78},{328,110},{332,79},
    {333,111},{334,79},{335,111},{336,79},{337,111},
    {340,82},{341,114},{342,82},{343,114},{344,82},
    {345,114},{346,83},{347,115},{348,83},{349,115},
    {350,83},{351,115},{352,83},{353,115},{354,84},
    {355,116},{356,84},{357,116},{358,84},{359,116},
    {360,85},{361,117},{362,85},{363,117},{364,85},
    {365,117},{366,85},{367,117},{368,85},{369,117},
    {370,85},{371,117},{372,87},{373,119},{374,89},
    {375,121},{376,89},{377,90},{378,122},{379,90},
    {380,122},{381,90},{382,122},{384,98},{385,66},
    {386,66},{387,98},{391,67},{392,99},{394,68},
    {395,68},{396,100},{401,70},{402,102},{403,71},
    {407,73},{408,75},{409,107},{410,108},{413,78},
    {414,110},{415,79},{416,79},{417,111},{420,80},
    {421,112},{427,116},{428,84},{429,116},{430,84},
    {431,85},{432,117},{434,86},{435,89},{436,121},
    {437,90},{438,122},{442,658},{446,662},{452,497},
    {453,68},{454,499},{456,76},{459,78},{461,65},
    {462,97},{463,73},{464,105},{465,79},{466,111},
    {467,85},{468,117},{469,85},{470,117},{471,85},
    {472,117},{473,85},{474,117},{475,85},{476,117},
    {478,65},{479,97},{480,65},{481,97},{482,198},
    {483,230},{484,71},{485,103},{486,71},{487,103},
    {488,75},{489,107},{490,79},{491,111},{492,79},
    {493,111},{494,439},{495,658},{496,106},{498,68},
    {500,71},{501,103},{504,78},{505,110},{506,65},
    {507,97},{508,198},{509,230},{510,79},{511,111},
    {512,65},{513,97},{514,65},{515,97},{516,69},
    {517,101},{518,69},{519,101},{520,73},{521,105},
    {522,73},{523,105},{524,79},{525,111},{526,79},
    {527,111},{528,82},{529,114},{530,82},{531,114},
    {532,85},{533,117},{534,85},{535,117},{536,83},
    {537,115},{538,84},{539,116},{542,72},{543,104},
    {544,78},{545,100},{548,90},{549,122},{550,65},
    {551,97},{552,69},{553,101},{554,79},{555,111},
    {556,79},{557,111},{558,79},{559,111},{560,79},
    {561,111},{562,89},{563,121},{564,108},{565,110},
    {566,116},{570,65},{571,67},{572,99},{573,76},
    {574,84},{575,115},{576,122},{579,66},{582,69},
    {583,101},{584,74},{585,106},{587,113},{588,82},
    {589,114},{590,89},{591,121},{595,98},{597,99},
    {598,100},{599,100},{602,601},{605,604},{607,567},
    {608,103},{614,104},{615,42791},{616,105},{619,108},
    {620,108},{621,108},{624,623},{625,109},{626,110},
    {627,110},{634,633},{635,633},{636,114},{637,114},
    {638,114},{642,115},{644,567},{646,643},{648,116},
    {651,118},{656,122},{657,122},{659,658},{667,610},
    {669,106},{672,113},{673,660},{677,675},{686,613},
    {687,613},{689,688},{693,692},{902,913},{904,917},
    {905,919},{906,921},{908,927},{910,933},{911,937},
    {912,953},{938,921},{939,933},{940,945},{941,949},
    {942,951},{943,953},{944,965},{970,953},{971,965},
    {972,959},{973,965},{974,969},{1024,1045},{1037,1048},
    {1104,1077},{1117,1080},{1142,1140},{1143,1141},{1148,1120},
    {1149,1121},{1162,1049},{1163,1081},{1166,1056},{1167,1088},
    {1168,1043},{1169,1075},{1170,1043},{1171,1075},{1172,1043},
    {1173,1075},{1174,1046},{1175,1078},{1176,1047},{1177,1079},
    {1178,1050},{1179,1082},{1180,1050},{1181,1082},{1182,1050},
    {1183,1082},{1186,1053},{1187,1085},{1190,1055},{1191,1087},
    {1194,1057},{1195,1089},{1196,1058},{1197,1090},{1200,1198},
    {1201,1199},{1202,1061},{1203,1093},{1206,1063},{1207,1095},
    {1208,1063},{1209,1095},{1214,1212},{1215,1213},{1217,1046},
    {1218,1078},{1219,1050},{1220,1082},{1221,1051},{1222,1083},
    {1223,1053},{1224,1085},{1225,1053},{1226,1085},{1229,1052},
    {1230,1084},{1232,1040},{1233,1072},{1234,1040},{1235,1072},
    {1238,1045},{1239,1077},{1242,1240},{1243,1241},{1244,1046},
    {1245,1078},{1246,1047},{1247,1079},{1250,1048},{1251,1080},
    {1252,1048},{1253,1080},{1254,1054},{1255,1086},{1258,1256},
    {1259,1257},{1260,1069},{1261,1101},{1262,1059},{1263,1091},
    {1264,1059},{1265,1091},{1266,1059},{1267,1091},{1268,1063},
    {1269,1095},{1270,1043},{1271,1075},{1272,1067},{1273,1099},
    {1274,1043},{1275,1075},{1276,1061},{1277,1093},{1278,1061},
    {1279,1093},{1298,1051},{1299,1083},{1312,1051},{1313,1083},
    {1314,1053},{1315,1085},{1316,1055},{1317,1087},{1318,1210},
    {1319,1211},{1320,1053},{1321,1085},{1326,1051},{1327,1083},
    {1570,1575},{1571,1575},{1572,1608},{1573,1575},{1574,1610},
    {1595,1705},{1596,1705},{1597,1740},{1598,1740},{1599,1740},
    {1650,1575},{1651,1575},{1655,1735},{1660,1578},{1661,1578},
    {1665,1581},{1666,1581},{1669,1581},{1673,1583},{1674,1583},
    {1675,1583},{1679,1583},{1680,1583},{1682,1585},{1683,1585},
    {1684,1585},{1685,1585},{1686,1585},{1687,1585},{1689,1585},
    {1690,1587},{1691,1587},{1692,1587},{1693,1589},{1694,1589},
    {1695,1591},{1696,1593},{1698,1601},{1699,1601},{1701,1601},
    {1703,1602},{1704,1602},{1707,1603},{1708,1603},{1710,1603},
    {1712,1711},{1714,1711},{1716,1711},{1717,1604},{1718,1604},
    {1719,1604},{1720,1604},{1721,1606},{1724,1606},{1725,1606},
    {1727,1670},{1728,1607},{1730,1729},{1732,1608},{1738,1608},
    {1741,1610},{1742,1610},{1743,1608},{1745,1610},{1747,1746},
    {1774,1583},{1775,1585},{1786,1588},{1787,1590},{1788,1594},
    {1791,1607},{1872,1576},{1873,1576},{1874,1576},{1875,1576},
    {1876,1576},{1877,1576},{1878,1576},{1879,1581},{1880,1581},
    {1881,1583},{1882,1583},{1883,1585},{1884,1587},{1885,1593},
    {1886,1593},{1887,1593},{1888,1601},{1889,1601},{1890,1705},
    {1891,1705},{1892,1705},{1893,1605},{1894,1605},{1895,1606},
    {1896,1606},{1897,1606},{1898,1604},{1899,1585},{1900,1585},
    {1901,1587},{1902,1581},{1903,1581},{1904,1587},{1905,1585},
    {1906,1581},{1907,1575},{1908,1575},{1909,1740},{1910,1740},
    {1911,1740},{1912,1608},{1913,1608},{1914,1746},{1915,1746},
    {1916,1581},{1917,1587},{1918,1587},{1919,1603},{2208,1576},
    {2209,1576},{2210,1580},{2211,1591},{2212,1601},{2213,1602},
    {2214,1604},{2215,1605},{2216,1610},{2217,1610},{2218,1585},
    {2219,1608},{2222,1583},{2223,1589},{2224,1711},{2226,1586},
    {2544,2480},{2545,2480},{7436,671},{7443,7441},{7532,98},
    {7533,100},{7534,102},{7535,109},{7536,110},{7537,112},
    {7538,114},{7539,114},{7540,115},{7541,116},{7542,122},
    {7548,617},{7549,112},{7551,650},{7552,98},{7553,100},
    {7554,102},{7555,103},{7556,107},{7557,108},{7558,109},
    {7559,110},{7560,112},{7561,114},{7562,115},{7563,643},
    {7564,118},{7565,120},{7566,122},{7567,97},{7568,593},
    {7569,100},{7570,101},{7571,603},{7572,604},{7573,601},
    {7574,105},{7575,596},{7576,643},{7577,117},{7578,658},
    {7581,7580},{7591,7590},{7592,690},{7593,737},{7594,737},
    {7596,7504},{7597,7514},{7603,738},{7605,7511},{7609,7515},
    {7612,7611},{7613,7611},{7660,7645},{7661,870},{7664,871},
    {7666,867},{7667,870},{7668,871},{7680,65},{7681,97},
    {7682,66},{7683,98},{7684,66},{7685,98},{7686,66},
    {7687,98},{7688,67},{7689,99},{7690,68},{7691,100},
    {7692,68},{7693,100},{7694,68},{7695,100},{7696,68},
    {7697,100},{7698,68},{7699,100},{7700,69},{7701,101},
    {7702,69},{7703,101},{7704,69},{7705,101},{7706,69},
    {7707,101},{7708,69},{7709,101},{7710,70},{7711,102},
    {7712,71},{7713,103},{7714,72},{7715,104},{7716,72},
    {7717,104},{7718,72},{7719,104},{7720,72},{7721,104},
    {7722,72},{7723,104},{7724,73},{7725,105},{7726,73},
    {7727,105},{7728,75},{7729,107},{7730,75},{7731,107},
    {7732,75},{7733,107},{7734,76},{7735,108},{7736,76},
    {7737,108},{7738,76},{7739,108},{7740,76},{7741,108},
    {7742,77},{7743,109},{7744,77},{7745,109},{7746,77},
    {7747,109},{7748,78},{7749,110},{7750,78},{7751,110},
    {7752,78},{7753,110},{7754,78},{7755,110},{7756,79},
    {7757,111},{7758,79},{7759,111},{7760,79},{7761,111},
    {7762,79},{7763,111},{7764,80},{7765,112},{7766,80},
    {7767,112},{7768,82},{7769,114},{7770,82},{7771,114},
    {7772,82},{7773,114},{7774,82},{7775,114},{7776,83},
    {7777,115},{7778,83},{7779,115},{7780,83},{7781,115},
    {7782,83},{7783,115},{7784,83},{7785,115},{7786,84},
    {7787,116},{7788,84},{7789,116},{7790,84},{7791,116},
    {7792,84},{7793,116},{7794,85},{7795,117},{7796,85},
    {7797,117},{7798,85},{7799,117},{7800,85},{7801,117},
    {7802,85},{7803,117},{7804,86},{7805,118},{7806,86},
    {7807,118},{7808,87},{7809,119},{7810,87},{7811,119},
    {7812,87},{7813,119},{7814,87},{7815,119},{7816,87},
    {7817,119},{7818,88},{7819,120},{7820,88},{7821,120},
    {7822,89},{7823,121},{7824,90},{7825,122},{7826,90},
    {7827,122},{7828,90},{7829,122},{7830,104},{7831,116},
    {7832,119},{7833,121},{7834,97},{7835,383},{7836,383},
    {7837,383},{7840,65},{7841,97},{7842,65},{7843,97},
    {7844,65},{7845,97},{7846,65},{7847,97},{7848,65},
    {7849,97},{7850,65},{7851,97},{7852,65},{7853,97},
    {7854,65},{7855,97},{7856,65},{7857,97},{7858,65},
    {7859,97},{7860,65},{7861,97},{7862,65},{7863,97},
    {7864,69},{7865,101},{7866,69},{7867,101},{7868,69},
    {7869,101},{7870,69},{7871,101},{7872,69},{7873,101},
    {7874,69},{7875,101},{7876,69},{7877,101},{7878,69},
    {7879,101},{7880,73},{7881,105},{7882,73},{7883,105},
    {7884,79},{7885,111},{7886,79},{7887,111},{7888,79},
    {7889,111},{7890,79},{7891,111},{7892,79},{7893,111},
    {7894,79},{7895,111},{7896,79},{7897,111},{7898,79},
    {7899,111},{7900,79},{7901,111},{7902,79},{7903,111},
    {7904,79},{7905,111},{7906,79},{7907,111},{7908,85},
    {7909,117},{7910,85},{7911,117},{7912,85},{7913,117},
    {7914,85},{7915,117},{7916,85},{7917,117},{7918,85},
    {7919,117},{7920,85},{7921,117},{7922,89},{7923,121},
    {7924,89},{7925,121},{7926,89},{7927,121},{7928,89},
    {7929,121},{7934,89},{7935,121},{7936,945},{7937,945},
    {7938,945},{7939,945},{7940,945},{7941,945},{7942,945},
    {7943,945},{7944,913},{7945,913},{7946,913},{7947,913},
    {7948,913},{7949,913},{7950,913},{7951,913},{7952,949},
    {7953,949},{7954,949},{7955,949},{7956,949},{7957,949},
    {7960,917},{7961,917},{7962,917},{7963,917},{7964,917},
    {7965,917},{7968,951},{7969,951},{7970,951},{7971,951},
    {7972,951},{7973,951},{7974,951},{7975,951},{7976,919},
    {7977,919},{7978,919},{7979,919},{7980,919},{7981,919},
    {7982,919},{7983,919},{7984,953},{7985,953},{7986,953},
    {7987,953},{7988,953},{7989,953},{7990,953},{7991,953},
    {7992,921},{7993,921},{7994,921},{7995,921},{7996,921},
    {7997,921},{7998,921},{7999,921},{8000,959},{8001,959},
    {8002,959},{8003,959},{8004,959},{8005,959},{8008,927},
    {8009,927},{8010,927},{8011,927},{8012,927},{8013,927},
    {8016,965},{8017,965},{8018,965},{8019,965},{8020,965},
    {8021,965},{8022,965},{8023,965},{8025,933},{8027,933},
    {8029,933},{8031,933},{8032,969},{8033,969},{8034,969},
    {8035,969},{8036,969},{8037,969},{8038,969},{8039,969},
    {8040,937},{8041,937},{8042,937},{8043,937},{8044,937},
    {8045,937},{8046,937},{8047,937},{8048,945},{8049,945},
    {8050,949},{8051,949},{8052,951},{8053,951},{8054,953},
    {8055,953},{8056,959},{8057,959},{8058,965},{8059,965},
    {8060,969},{8061,969},{8064,945},{8065,945},{8066,945},
    {8067,945},{8068,945},{8069,945},{8070,945},{8071,945},
    {8072,913},{8073,913},{8074,913},{8075,913},{8076,913},
    {8077,913},{8078,913},{8079,913},{8080,951},{8081,951},
    {8082,951},{8083,951},{8084,951},{8085,951},{8086,951},
    {8087,951},{8088,919},{8089,919},{8090,919},{8091,919},
    {8092,919},{8093,919},{8094,919},{8095,919},{8096,969},
    {8097,969},{8098,969},{8099,969},{8100,969},{8101,969},
    {8102,969},{8103,969},{8104,937},{8105,937},{8106,937},
    {8107,937},{8108,937},{8109,937},{8110,937},{8111,937},
    {8112,945},{8113,945},{8114,945},{8115,945},{8116,945},
    {8118,945},{8119,945},{8120,913},{8121,913},{8122,913},
    {8123,913},{8124,913},{8130,951},{8131,951},{8132,951},
    {8134,951},{8135,951},{8136,917},{8137,917},{8138,919},
    {8139,919},{8140,919},{8144,953},{8145,953},{8146,953},
    {8147,953},{8150,953},{8151,953},{8152,921},{8153,921},
    {8154,921},{8155,921},{8160,965},{8161,965},{8162,965},
    {8163,965},{8164,961},{8165,961},{8166,965},{8167,965},
    {8168,933},{8169,933},{8170,933},{8171,933},{8172,929},
    {8178,969},{8179,969},{8180,969},{8182,969},{8183,969},
    {8184,927},{8185,927},{8186,937},{8187,937},{8188,937},
    {11301,11300},{11349,11348},{11360,76},{11361,108},{11362,76},
    {11363,80},{11364,82},{11365,97},{11366,116},{11367,72},
    {11368,104},{11369,75},{11370,107},{11371,90},{11372,122},
    {11374,77},{11377,118},{11378,87},{11379,119},{11380,118},
    {11384,101},{11385,633},{11386,111},{11390,83},{11391,90},
    {42576,1067},{42577,1099},{42634,1058},{42635,1090},{42798,42796},
    {42799,42797},{42810,42808},{42811,42809},{42815,8580},{42816,75},
    {42817,107},{42818,75},{42819,107},{42820,75},{42821,107},
    {42824,76},{42825,108},{42826,79},{42827,111},{42828,79},
    {42829,111},{42832,80},{42833,112},{42834,80},{42835,112},
    {42836,80},{42837,112},{42838,81},{42839,113},{42840,81},
    {42841,113},{42846,86},{42847,118},{42852,222},{42853,254},
    {42854,222},{42855,254},{42894,108},{42896,78},{42897,110},
    {42898,67},{42899,99},{42900,99},{42901,104},{42902,66},
    {42903,98},{42904,70},{42905,102},{42912,71},{42913,103},
    {42914,75},{42915,107},{42916,78},{42917,110},{42918,82},
    {42919,114},{42920,83},{42921,115},{42922,72},{42925,76},
    {43000,7476},{43828,101},{43830,609},{43831,108},{43832,108},
    {43833,108},{43834,109},{43835,110},{43836,331},{43838,43837},
    {43839,596},{43841,7444},{43842,7444},{43844,43843},{43846,640},
    {43847,114},{43849,114},{43850,43848},{43852,43851},{43854,117},
    {43855,649},{43858,117},{43860,43859},{43861,43859},{43862,120},
    {43863,120},{43864,120},{43865,120},{43866,121},{43869,737},
    {43870,737},{43871,7512},{64285,1497},{64298,1513},{64299,1513},
    {64300,1513},{64301,1513},{64302,1488},{64303,1488},{64304,1488},
    {64305,1489},{64306,1490},{64307,1491},{64308,1492},{64309,1493},
    {64310,1494},{64312,1496},{64313,1497},{64314,1498},{64315,1499},
    {64316,1500},{64318,1502},{64320,1504},{64321,1505},{64323,1507},
    {64324,1508},{64326,1510},{64327,1511},{64328,1512},{64329,1513},
    {64330,1514},{64331,1493},{64332,1489},{64333,1499},{64334,1508},
    {64420,1607},{64421,1607},{64432,1746},{64433,1746},{64477,1735},
    {65153,1575},{65154,1575},{65155,1575},{65156,1575},{65157,1608},
    {65158,1608},{65159,1575},{65160,1575},{65161,1610},{65162,1610},
    {65163,1610},{65164,1610},{113697,113689},{113698,113690},{113699,113691},
    {113700,113691},{113701,113692},{113702,113692},{113711,113705}};

static unsigned int ksu_conv_search(const CONV_T *tab,
                                    const int cnt,
                                    const unsigned int code) {
   int start = 0;
   int end = cnt - 1;
   int mid;

   unsigned int result = code;
   while(start<=end){
      mid = (start + end) / 2;
      if ((code >= tab[mid].from_code)
          && (code < tab[mid].from_code + tab[mid].cnt)) {
         result += tab[mid].to_offset;
         start = end + 1;
      } else {
         if (tab[mid].from_code < code) {
            start = mid + 1;
         } else {
            end = mid - 1;
         }
      }
   }
   return result;
}

static unsigned int ksu_conv2_search(const CONV2_T *tab,
                                     const int cnt,
                                     const unsigned int code) {
   int start = 0;
   int end = cnt - 1;
   int mid;

   unsigned int result = code;
   while(start<=end){
      mid = (start + end) / 2;
      if (tab[mid].from_code == code) {
         result = tab[mid].to_code;
         start = end + 1;
      } else {
         if (tab[mid].from_code < code) {
            start = mid + 1;
         } else {
            end = mid - 1;
         }
      }
   }
   return result;
}

// Returns the codepoint corresponding to the lower case,
// or the same codepoint if no lower case equivalent known
extern unsigned int ksu_unicode_lower(const unsigned int cp) {
    return ksu_conv_search((const CONV_T *)G_upper_to_lower,
                           UPPER_LOWER_CNT,
                           cp);
}

// Returns the codepoint corresponding to the upper case,
// or the same codepoint if no upper case equivalent known
extern unsigned int ksu_unicode_upper(const unsigned int cp) {
    return ksu_conv_search((const CONV_T *)G_lower_to_upper,
                           LOWER_UPPER_CNT,
                           cp);
}

// Returns the codepoint corresponding to the letter stripped of accents,
// or the same codepoint if no unaccented equivalent known
extern unsigned int ksu_unicode_strip_accent(const unsigned int cp) {
    return ksu_conv2_search((const CONV2_T *)G_unaccent,
                           UNACCENT_CNT,
                           cp);
}

extern unsigned int ksu_hex_to_codepoint(const char *hex) {
            int len = strlen((char *)hex);
            int val;
   unsigned int ret = 0;
            int coef = 1;
            int i;

   i = len;
   while (i) {
      i--;
      if (isalpha(hex[i])) {
         val = 10 + toupper(hex[i]) - 'A';
         if ((val < 10) || (val > 15)) {
            return 0;  // Invalid hex
         }
      } else {
         val = hex[i] - '0';
      }
      ret += val * coef;
      coef *= 16; 
   } 
   return ret;
}

