#ifndef SIN512_FLOAT_H_
#define SIN512_FLOAT_H_
#include <arm_math.h>

#define SIN512_NUM_CELLS 512
#define SIN512_SAMPLERATE 512

const static float32_t SIN512_DATA [] =
{
      0.5,0.50613576914286,0.5122706142614561,0.5184036114706794,0.524533837163709,
      0.5306603681511043,0.5367822817998337,0.54289865617222,0.5490085701647803,0.5551111036469415,
      0.5612053375996081,0.5672903542535631,0.5733652372276808,0.5794290716669307,0.5854809443801506,
      0.5915199439775705,0.5975451610080641,0.6035556880961093,0.6095506200784349,0.6155290541403355,
      0.6214900899516319,0.6274328298022573,0.6333563787374492,0.6392598446925265,0.6451423386272311,
      0.651002974659614,0.6568408701994457,0.6626551460811314,0.66844492669611,0.6742093401247173,
      0.6799475182674941,0.6856585969759188,0.6913417161825449,0.6969960200305241,0.7026206570024949,
      0.7082147800488185,0.713777546715141,0.7193081192692639,0.7248056648273032,0.73026935547912,
      0.7356983684129988,0.7410918860395613,0.746449096114892,0.7517691918628588,0.7570513720966108,
      0.7622948413392345,0.7674988099435486,0.7726624942110232,0.7777851165098011,0.7828659053918066,
      0.7879040957089227,0.7928989287282194,0.7978496522462166,0.8027555207021628,0.8076157952903134,
      0.8124297440711932,0.8171966420818227,0.8219157714448957,0.8265864214768883,0.8312078887950859,
      0.8357794774235092,0.8403004988977265,0.8447702723685334,0.8491881247044865,0.8535533905932737,
      0.8578654126419093,0.8621235414757334,0.8663271358362064,0.8704755626774796,0.8745681972617296,
      0.8786044232532422,0.8825836328112295,0.8865052266813684,0.8903686142860472,0.8941732138133032,
      0.8979184523044417,0.9016037657403224,0.9052285991262974,0.9087924065757919,0.9122946513925126,
      0.9157348061512727,0.919112352777419,0.9224267826248536,0.9256775965526326,0.9288643050001361,
      0.9319864280607933,0.9350434955543556,0.9380350470977032,0.9409606321741775,0.943819810201427,
      0.9466121505977576,0.9493372328469769,0.9519946465617217,0.9545839915452612,0.9571048778517653,
      0.9595569258450289,0.9619397662556434,0.9642530402366077,0.9664963994173694,0.9686695059562875,
      0.9707720325915103,0.9728036626902606,0.9747640902965183,0.9766530201770969,0.9784701678661045,
      0.9802152597077829,0.98188803289772,0.983488235522426,0.985015626597272,0.98646997610278,
      0.9878510650192642,0.9891586853598138,0.9903926402016152,0.9915527437156082,0.9926388211944706,
      0.9936507090789293,0.9945882549823906,0.99545131771389,0.996239767299355,0.9969534850011781,
      0.9975923633360984,0.998156306091389,0.9986452283393451,0.9990590564500745,0.9993977281025862,
      0.9996611922941747,0.9998494093481021,0.9999623509195723,1.0,0.9999623509195723,
      0.9998494093481021,0.9996611922941747,0.9993977281025862,0.9990590564500745,0.9986452283393451,
      0.998156306091389,0.9975923633360985,0.9969534850011781,0.996239767299355,0.99545131771389,
      0.9945882549823906,0.9936507090789293,0.9926388211944706,0.9915527437156082,0.9903926402016152,
      0.9891586853598138,0.9878510650192642,0.9864699761027801,0.985015626597272,0.983488235522426,
      0.98188803289772,0.9802152597077829,0.9784701678661045,0.9766530201770969,0.9747640902965183,
      0.9728036626902608,0.9707720325915103,0.9686695059562875,0.9664963994173694,0.9642530402366079,
      0.9619397662556434,0.9595569258450289,0.9571048778517653,0.9545839915452612,0.9519946465617217,
      0.9493372328469769,0.9466121505977576,0.943819810201427,0.9409606321741775,0.9380350470977032,
      0.9350434955543557,0.9319864280607935,0.9288643050001361,0.9256775965526326,0.9224267826248536,
      0.9191123527774191,0.9157348061512727,0.9122946513925125,0.9087924065757919,0.9052285991262974,
      0.9016037657403224,0.8979184523044418,0.8941732138133032,0.8903686142860473,0.8865052266813686,
      0.8825836328112295,0.8786044232532424,0.8745681972617296,0.8704755626774795,0.8663271358362064,
      0.8621235414757334,0.8578654126419094,0.8535533905932737,0.8491881247044865,0.8447702723685335,
      0.8403004988977266,0.8357794774235092,0.831207888795086,0.8265864214768883,0.8219157714448957,
      0.8171966420818227,0.8124297440711932,0.8076157952903135,0.8027555207021628,0.7978496522462167,
      0.7928989287282195,0.7879040957089227,0.7828659053918068,0.7777851165098011,0.7726624942110232,
      0.7674988099435486,0.7622948413392345,0.7570513720966109,0.7517691918628588,0.7464490961148921,
      0.7410918860395614,0.735698368412999,0.7302693554791201,0.7248056648273035,0.7193081192692637,
      0.713777546715141,0.7082147800488185,0.702620657002495,0.6969960200305241,0.6913417161825449,
      0.6856585969759188,0.6799475182674941,0.6742093401247173,0.6684449266961101,0.6626551460811316,
      0.6568408701994457,0.651002974659614,0.6451423386272312,0.6392598446925266,0.6333563787374492,
      0.6274328298022573,0.621490089951632,0.6155290541403357,0.6095506200784351,0.6035556880961094,
      0.5975451610080643,0.5915199439775705,0.5854809443801506,0.5794290716669307,0.573365237227681,
      0.5672903542535631,0.5612053375996082,0.5551111036469416,0.5490085701647804,0.5428986561722201,
      0.5367822817998339,0.5306603681511043,0.5245338371637089,0.5184036114706794,0.5122706142614561,
      0.50613576914286,0.5000000000000001,0.4938642308571401,0.48772938573854396,0.4815963885293207,
      0.4754661628362911,0.4693396318488959,0.4632177182001663,0.45710134382778006,0.4509914298352197,
      0.4448888963530585,0.43879466240039194,0.432709645746437,0.4266347627723192,0.4205709283330694,
      0.41451905561984953,0.40848005602242965,0.4024548389919358,0.39644431190389073,0.3904493799215651,
      0.38447094585966446,0.3785099100483681,0.37256717019774277,0.3666436212625509,0.36074015530747355,
      0.354857661372769,0.3489970253403861,0.3431591298005544,0.3373448539188685,0.33155507330388995,
      0.3257906598752827,0.32005248173250594,0.3143414030240813,0.3086582838174552,0.30300397996947603,
      0.2973793429975051,0.29178521995118156,0.28622245328485907,0.28069188073073637,0.27519433517269665,
      0.26973064452087997,0.26430163158700115,0.25890811396043867,0.25355090388510804,0.24823080813714127,
      0.24294862790338922,0.23770515866076564,0.23250119005645153,0.22733750578897693,0.22221488349019902,
      0.21713409460819338,0.21209590429107733,0.20710107127178057,0.20215034775378338,0.19724447929783728,
      0.19238420470968665,0.18757025592880688,0.18280335791817737,0.17808422855510436,0.17341357852311173,
      0.1687921112049141,0.16422052257649078,0.1596995011022735,0.15522972763146659,0.1508118752955136,
      0.14644660940672627,0.14213458735809076,0.1378764585242666,0.1336728641637937,0.12952443732252056,
      0.12543180273827048,0.12139557674675788,0.11741636718877052,0.11349477331863167,0.10963138571395281,
      0.10582678618669705,0.10208154769555827,0.09839623425967747,0.09477140087370267,0.09120759342420809,
      0.08770534860748747,0.08426519384872738,0.08088764722258107,0.0775732173751465,0.07432240344736757,
      0.071135694999864,0.06801357193920676,0.06495650444564433,0.061964952902296644,0.05903936782582253,
      0.05618018979857298,0.05338784940224239,0.05066276715302309,0.04800535343827844,0.04541600845473881,
      0.042895122148234766,0.04044307415497117,0.03806023374435674,0.03574695976339226,0.03350360058263052,
      0.031330494043712576,0.029227967408489597,0.027196337309739416,0.025235909703481663,0.023346979822903124,
      0.021529832133895588,0.019784740292217162,0.01811196710228008,0.01651176447757391,0.014984373402728013,
      0.013530023897219912,0.01214893498073577,0.010841314640186173,0.00960735979838484,0.008447256284391857,
      0.007361178805529445,0.006349290921070838,0.005411745017609548,0.004548682286109995,0.003760232700644961,
      0.0030465149988219697,0.0024076366639015356,0.0018436939086109994,0.0013547716606548965,0.0009409435499254104,
      0.0006022718974137975,0.00033880770582528363,0.00015059065189787502,3.7649080427748505e-05,0.0,
      3.7649080427748505e-05,0.00015059065189787502,0.0003388077058252281,0.0006022718974137975,0.0009409435499254104,
      0.0013547716606548965,0.0018436939086109994,0.0024076366639015356,0.0030465149988219697,0.003760232700644961,
      0.004548682286109995,0.005411745017609548,0.006349290921070783,0.007361178805529389,0.008447256284391802,
      0.009607359798384785,0.010841314640186117,0.012148934980735715,0.013530023897219856,0.014984373402728013,
      0.016511764477573854,0.018111967102280024,0.019784740292217107,0.021529832133895532,0.02334697982290307,
      0.025235909703481607,0.02719633730973936,0.02922796740848954,0.03133049404371252,0.033503600582630466,
      0.035746959763392205,0.038060233744356686,0.04044307415497106,0.04289512214823471,0.045416008454738754,
      0.04800535343827833,0.05066276715302298,0.05338784940224234,0.05618018979857292,0.059039367825822475,
      0.06196495290229653,0.06495650444564427,0.06801357193920671,0.07113569499986389,0.07432240344736746,
      0.07757321737514639,0.08088764722258102,0.08426519384872727,0.08770534860748735,0.09120759342420798,
      0.09477140087370256,0.09839623425967736,0.10208154769555816,0.10582678618669694,0.1096313857139527,
      0.11349477331863156,0.11741636718877041,0.12139557674675772,0.1254318027382702,0.12952443732252045,
      0.13367286416379343,0.1378764585242665,0.14213458735809048,0.14644660940672616,0.15081187529551365,
      0.15522972763146642,0.1596995011022735,0.16422052257649067,0.1687921112049141,0.17341357852311146,
      0.17808422855510425,0.18280335791817703,0.18757025592880677,0.1923842047096863,0.19724447929783717,
      0.20215034775378338,0.20710107127178046,0.2120959042910774,0.21713409460819322,0.2222148834901989,
      0.2273375057889766,0.23250119005645137,0.2377051586607653,0.24294862790338906,0.24823080813714093,
      0.25355090388510787,0.25890811396043867,0.26430163158700104,0.26973064452088,0.27519433517269654,
      0.28069188073073614,0.28622245328485874,0.29178521995118134,0.2973793429975048,0.30300397996947587,
      0.3086582838174548,0.3143414030240811,0.320052481732506,0.32579065987528255,0.33155507330389,
      0.3373448539188683,0.34315912980055424,0.3489970253403857,0.35485766137276875,0.36074015530747316,
      0.3666436212625507,0.37256717019774277,0.3785099100483679,0.3844709458596645,0.3904493799215649,
      0.39644431190389073,0.4024548389919356,0.4084800560224295,0.41451905561984914,0.4205709283330692,
      0.4266347627723188,0.4327096457464368,0.438794662400392,0.44488889635305834,0.4509914298352197,
      0.45710134382777984,0.4632177182001663,0.4693396318488955,0.47546616283629095,0.4815963885293203,
      0.4877293857385438,0.4938642308571397,0.5
};
#endif
