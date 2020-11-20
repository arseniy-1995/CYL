// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
//-V2008_CYCLOMATIC_COMPLEXITY=100
// Добро пожаовать в программу CYL.EXE ©. Автор программы Юрченко Арсений Владиславович ©
// Программа написана для лаборатории 2.0 ИЯФ СО РАН
// Для моделирования движения частиц в эксперементальной установке по получению поляризованных молекул изотопа водорода/дейтерия



  //;--------------------------------------------------------------------------------------------------------------;
  //;         5555                                                                                                 ;
  //;     s555S5555S5S  s5S5        S55    S5S                    5555SS5555S5    5SS        ,S5     5S55S555555S  ;
  //;   ,55S        55   55S,      S55     S55                    555              555      5S5,     555           ;
  //;   555               55S     r55;     S55                    555               555    .5S5      555           ;
  //;  555                 555    55S      S55                    555                5S5  ,SS5       555           ;
  //;  5SS                  S55  55,       S55                    555                 5S5,55         555           ;
  //;  S5,                   5S S5S        S55                    55555S5555S          5S55          55555S55SS5   ;
  //;  55,                   s5555         S55                    555                  5555S         555           ;
  //;  55i                    5SS          S55                    555                 SSi 55S        555           ;
  //;  SS5                    S5S          S55                    555               :S5S   5S5       555           ;
  //;   S5S                   55S          S55                    555              :555     5S5      555           ;
  //;   S555        sS        55S          S55           S55,     555              S55      iSS5     555           ;
  //;     5S5S5S555555        55S          S55S5555555,  5555     555S5S55555S    SSS         55S    55555S555SSS  ;
  //;         555S                                                                                                 ;
  //;                                                                                                              ;
  //;                                Computer Simulation Program for Physical Installation                         ;
  //;                                                (lab. 2.0 INP SB RAS)                                         ;
  //;                                                                                                              ;
  //;		                    Author  -  (C) Yurchenko Arseniy Vladislavovich (C)                          ;
  //;                                           e-mail: arseniy-1995@mail.ru                                       ;
  //;                                   Supervisor  -  Toporkov Dmitriy Konstantinovich                            ;
  //;                                           e-mail: D.K.Toporkov@inp.nsk.su                                    ;
  //;                                                                                                              ;
  //;                                              (<<<...Best Regard...>>>)                                       ;
  //;                                                                                                              ;
  //;                                                                                                              ;
  //;                                                                                                              ;
  //;                                                                                                Copyright (C) ;
  //;                                                     2016-2019                                                ;
  //;--------------------------------------------------------------------------------------------------------------;

/*
  : ,,,.,.,.,.,...,.,.,.......................................... . .           . . . ......,.,...,.,.,.,.,,,,,,:.
  ,                                                                                                              ,
  , ,......................................                                       . . ................,.,...,.,.:.
  . .............................. . . ...                                           . . ......................,..
  , ,.................. ... . . ... .   .            .:rJv;,                          . . ......................,.
  . ............ ... . . . . .   . .           .:L5NEOMBMBMBOq7.                       . .........................
  . ............. . . . . . . .             ;u8B@B@BMGO8EN88MM@8J:YYrrr7v7ri:,        . . ... ..................,.
  . .......... . . . . . .   .          .JO@@@MM8MOMOOZOZ008OMB@B@@@B@B@BBN2LLvv:    . . . . . ...................
  . ......... ... . . .               :8@BB8OGO8GEGEOOM8MZZ0MMMB@B@B@B@@BMMGkjL;Y;        . ... . ................
  . ........ . . . .                 SB@8ZqGZOZ8EqPZ00NEG8ZGEGOBBMM@B@BBOMZ8OMN2vL:      .   . . ..... ...........
  . ... . .   . .                  :@BMOMOBMOZ8EG0Eq0FXZOO8Z8MMMBM@B@B@MBMMZ0XqS05L         . . . . . ............
  . .... .                        J@BMM@B@M8GGEO8MZZqNk0ZBMM8MOMMMMBM@B@BB8OEN5PqO5          .   . . . . .........
  . . . . . .                    u@BBB@MOEZNGZGE8qGMMOMMO8BB@MMOMOBMMM@B@MMOOZZ0OM8.              . . . . ........
  . .. . .                      7@B@BBOZXNNZZN0MMMO@B@@@@BMMB@M@MMO@OOOBMM8OZ0q0PGB:                 . . . . .....
  . . .   .                    :@BBMM8ZPEXGOMOM8O8OEqSS1F11u2uSSXSGkLvL1GMBOO0qXX8E.                    ... . ....
  . .. .                       @BMMMMMOMOMMMOq2uvvii:::::::::iiir7i:,i:i7OM@OMPGkZP                        . . ...
  . .                         :BBOBMBM@B@BMNu;i::..,,.,,,.,.,,,,,..,::::ijZ00OMZOMP                       . . ....
  .  .                        P@B@M@B@B@MMk7::::,,,,.,.,.,.,,,...,,:::::iv50SOBMM@:                        . . ...
  . .                         BB@B@BBMO8Gur::::::,,.,.,.,,,.,...,.:::::::jkUE0@BBP                          . ....
  .                           M@@@B@O8ZM2i:i::,,.........,...,.. ....:::.vBPZMM@8.                             ...
  . .                         NB@M@MMM@S::i::..   . ....,.,...,.....,,,:,i@OGB@B7                               ..
  .                           r@B@BBM@Bi:ri77U1SSNENLi:::::::77vGBMqjLrr:iBBq@Y.                               ...
  . .                          5@BBM@BE:irvLUUqPq8M0jvrii:::;7vY0PXkSJri::@BEM:                                 ..
  .                             u@BBB@u:irrv58LGB@Lj2Lri:,.::rLuB@Mi5Pvr::E@O@:                                  .
  .                             rBBBMOj:i::ir7:rOF.,;:ri:..:rir,vGL,ii:::.5MM@i                                  .
  .                              @B@ZM7:::,:::ii::ii::ii:..:ii:::::i::,,,.JBOF                                   .
  .                              i@MM87:i::,,,,,,,:,:::i:..,:::...,.,...:.v@8                                    .
  .                               .8OGJii:::,,...,..,::i:,.:::,,.......,,,J@:                                    .
  .                                .uLPrri:::,,.....:i;::..,:::,,...,.,,::Ou                                     .
  .                                ::.J7ii::,:,,...,:i::....,::,.,.,.,:::YP                                      .
  .                              ,MBZL0v:i;::::,,.,:ii7:,...:i:,,.:,:,::i:                                       .
  .                               :GB@@P:iii::,:,,,::YFuJJ77Yki,.,,,,,:i:                                        .
  . .                             .vMB@8riiii::::,,.,,:iiii::,..,.:,:::ir                                        .
  .                               ::;YuX7riiii::::::,,,,.,.,,:,,,::::::r:                                        .
  .                                     irri;ii:ii7LLiri::::iirvvri:::r.                                         .
  .                                    r1ir7;riiii:rvuLrr7r;7Yvrii:i:r:                                          .
  . .                                 iB::;7vr;i:::,::rr7rr7r:,.,:::7:                                           .
  . ..                               YB@ .:;7Lri:::::::;v2Lr:::::::i.                                            .
  , ...                             GB@Bi .,irLv;,:,,....,..,.,,::ir                                             .
  . ....                         7F@BBM@M  ,,:iLuJi:,... ......:;v:5:0ZL:.                                       .
  , ..... .                   .k@B@MMOMM@8. :,,,iLSFuriii:iiiru2v,iP O@B@@@Gkv:                                  .
  , ......                   1B@BMZ8Z88MM@M. :::,,:vXMMMOMOGPq2r.:P. BBMMBB@B@B@O8PkULi,                         .
  , ,......                iBBMOMOGZ8ZMOMO@@i :::::,,:vuF5SJ7::,:Pr :BMOMOMOMOMMBB@B@B@@@Eu7.                    .
  , ........             YB@MO88GM88EGZ88OM@BL ,:::::,...:irii:rU:  :@8MOO8OMOGOG8OO8O8OOBB@Bu                   .
  : ,........       .:uEBBM88ZGZ8OM8OZGZ8Z88BBP .,:,:,,..   ::rY7vr :BOGMOMOO88Z8G8Z8EZEGZGEMBk                  .
  ,.,,.....     :u8@B@B@MOZGEZ0GZOOOOOZGE8Z8ZMB8. .,.,...  i7i:.r@B..@O8GO8OZ88OZ8ZGG8ZZZGEZ0MBL                 .
  : ,,...    i0B@B@MMOOZ8E808EGZGEMGOOMZZZZ0GEOBB. ....  .7vi::.i8@i BMG8GO888O8OEOZ8ZGEZ0Z0EZMB                 .
  :.,..   :XB@BBGOZ8E8EG08EG0OEGZGZMOMOOZGZGEZEO@B.  . .:rMi.::,,7SO.@OOG8GOE8EZGGZ8ZGZGEGEZNGOBP                .
  :.,  .JG@BM88EZZGEZ0ZZGZGEZEGEGZGNO8MOOE808ZGE8B@   ,:iv0.,...,..u7qMGOZGE8GGZ8Z88GEGEG0EEZqMG@B.              .
  :. :k@B@MOGGGGZEZEEZ0EZZZZEEZ8EGEE0ZE8OGNGEGZGZ8B@ .,:.17 ...,:.  JMOGGGZGZ88OGG88EZ0GZZEZEZOOZ@B              .
  : iB@BMO8EG08EO000ZE0EZEEEZ080808ZEEZNZEG0ZEZZGZOB@....ir ...,:.. JMGZ8EGZGZGEG0G8G0GZGEEEG08GZM@:             .
  . B@OM88ZGZG0Z0OEGNG0GNG0GEZ0GEZZMZ0GGZGEEEZEZZ8ZOB0 ...i....:,,. :BG8ZGEGE8EGEGZMEZZ8EE0ZEZEM08B@:            .
  .r@MO8OGM8OGGZZNG880ZNZEGZZZEGZZZZMOZZGEZEG0GZGEZZMBu ..i...,,:,. .OMGGZGZGEG0ZZZZZEG0Z0EZO0GOZZMB@:           .
  .0BMOOOM88ZGZGEZqZ8GEZ0EZEZGEGEGNGNMO8G80GEE0ZEZ0G8BBi .i:.,.:,:.. kB8Z8EGEGEGZGE8EZEG0ZZO880BE8OMB@           .
  .M@MMOM8OGOG8EGZZEZZOq8E80OEG08EGEG0ZOOEGEGEZ0GEZN8O@M. ;:..,,.,:. v@OOEGZGE8GZZ8ZGEGEZZOOOZZM88OZ8@E          .
  .BBM8MOOG88OZGZGEG0ZGO08E8ZGZEZZZZGGEGOO08EZZG0ZEGZOM@1 :r .,,..:, iBMZ8ZGZGZ8ZG08ZG0GE8GM88ZOZMZGZOBJ         .
  .J@MO8O8OOOEG08ZZEG0ZZOZGZGG8EGZ808E8E8OMEOZ8Z8EGZ8ZOM@:.7..::,.::..OB8ZGEG0ZZ8EZGGZ8E8GMOO88OM8G08M@B7        .
  . O@8O8MOOG8EZZGZGZZE08M08E8ZG0OZGGGGZGGMO08GGGOGOGOGMB@.7.,.....::.u@G8Z8EGEGGG08ZGGOGMMMG8GMOGZOBM8@         .
  ..@BMOO8OZ8E8N8ZGE8EGNZGMEGG88Z88Z8E8Z8Z8OMEGG8GOG8OOGMBF:..,....:i.;BMZGZGZ8EGZ8ZGEO8OOMOOGOM8ZBMM8OMu       ..
  .rBBOOOO8GZGZZZGZGZGGEEEOOZZGOZ8ZOEOZ8Z8ZZMMEOG8GO8O8OGMBF .,,...i7:,OMOGGEGGGZZ0OGOZO8MOOO88MOBMMO8OBB@:   ....
  .:@BMOOOMZOZ8080O08EOEOZ88ONOE8G8GGGGG8Z8ZGOMGO8O8O8O8O8@B. ,,,..:Ji.0BG8GGZGZGE8ZO888MBBOOGMBB8OOEGOOMB@:  ....
  ..B@OM8OOO88GZZZEZZZZZ88GOMGZ8GGG8G8ZOE8EOZ8OBGOGOOO8O888@P .:,,..jL qBOZ8ZGZZZZ0MGO8MB@OMOMMBMMO88O8OOMB@: ....
  : BBMOM8O8O8O08E80808EGG8EOM8E8ZOGOZ888G88Z88OMEO8OOO8MO8O@7 ,:,. vX.2@GOZGZ8ZOE8MOOMMBOMMMOMB@OMMBB@MBOMBu ...,
  : Z@OMOO8OGOGGZGGEEGEGE8GOGBOOZGGOG8G8Z8Z8ZOG8OBZO8OOO8OGOB@..,:. :MiuBOZ8Z8GGGGO@OMOO8BOMOMM@OOOOZGE8EOO@7  ...
  i 5BMOMOOGOG8ZGEG08GGEGG8GOOBG8Z8GOZOGOGOZ8G888MBZMGMOO8O8OB0 ,,,.,MLYB88Z8ZGZG0OMO8MOMMMOMOBBOEE0GGOGOO8B@X  .,
  : r@MMOMOOGOEGZ8EG08EOEOGMGMMBZOZO8O8O8888G8GOEOMBZO8OOO8OOMB; ,:, O5jMO8GG8Z808OMOOOMMBOMOMB@B8OMOM8MOOM@B@r ..
  i..B@OMOOOOGGZGZGZ0EZZG8OG8OMBOO8O88OOOEOZOGO8O8OBMGM8O8O8O8@B..i: 1OuMZOZOGO88GMOMOMMMOMMMM@MMMM8MOMZOMM88BE  .
  i, U@M8M8MOOZOEOE8NMMBMBMMOMM@MOGMGOGMO8GOG88O8OOMBMGOOMGOOOO@5 .r LBkO88OGOGOZMMMOMOMOMOOOMMM8OZOGOEGZ8EGGMB@L.
  i..M@OMOO8MMM8G88GGOMM@B@B@BBB@OOOOOOOOGOGOZOGOGMOM@OGMOOOOOOM@. i,i@0MEOZOGOZ8MMOMOMMMMBOMM@B@MMMM8MOOZGZ88MM@F
  : J@@OOMOMOO8O08ZGZ888Z88MB@B@BB8MGMGMOOGOG8OOOOOMO@@8OMOM8O8OB8 i::BM88ZO88GOOMMMOMMBMBMMOBBMMMOMMMMMMMMMMMOMMB
  :.@B@MOZM8OZO8MOOZ8EOZOZOZ8O@B@BMOM8OOM888O8O8OGMOMM@B8OM8OGOOM@r,7.OBOGO8OZ8EOMMMMMBMBOMGOB@BBO8EGZOZOGOGOGOZZN
  ,:B@MM088BMBB@B@B@BMOO8OGOGOMBB@MMOOZMOM8MOOOOOOOMMBM@M8OMOM8OM@M:7.F@8O8O8O8OMMMMMBOMO8ZOM@B@B@@BMO8OZGE8EZ0GGO
  : @BMO80NZGZZ88GG8MM@BBMMOO8MO@BBOMOOOOOOOO8OOM8MMMMMM@M8MMOM8MM@XL:v@MZOGO88GMOMOMOMGOZ8OBB@BBBBBBBBMMOOEOOMB@M
  i.;@B@MB8OZGEZ0808E8EOOMOOOBMBB@@MOMGMOM8M8OGOOOOBMBMMM@OOOM8M8MM@FriMBO8OGOZOMMOMOMOOZOOMB@B@MBOMOMMMMMGOB@MM8G
  i,.r@B@B@BBMBOMO88GEGEGEG8MM@MM@@BMOOOOOOOMOMOM8MMMMMOOM@OO8MOM8MMMLrS@8OGO88MMOMOM8OOO8MM@B@B@MMMMOMOOO888ZGE8E
  i:: j@MBMBBBMBBBMM8EZ8GOZOZOE88BB@OMOM8MOMOMOMOMOMMMMMOMB@8MOO8MGM@GYvMOGOZOZMOMOMOOGO8MM@B@B@B@BBMBMBBBMM8OGOGG
  ;:i.uBM8OOMOOOOGG8MMBBBMMMMOOZ8G8M@MMOMOOOOOOOMOMMBMMOMOOB@888MOM8MBN78O8G8GOMMOMOOGO8MMBM@B@B@@@@MOOOMMBBBBBMMO
  ;:i,v@MMOOEGZMMBB@B@MMMMOMMMOGZMOOB@MMOMOMOMOMMBMMMMMMMM8MB@8OOMOMO@M5ZO8O888MOMOM8OOMMMM@B@B@B@B@B@MOZ88O88OO8O
  r:i,rB@MMG8OMMMMM8GZZZOGOEOZOqGOMOMB@MMOOOMOMMMOMOMMBOMOOOMB@GO8OOOO@ZO8O8OZBMMOMOMMMMBMBB@B@B@B@B@B@BBOMOO8O8OZ
  i:i:i@BMO8EON8EGEGZZGZ8ZGG8GEZOBOO8@B@OMOMOMOM8O8MMMMMMMOMOOB@8OOMOOMBG8G8ZOMMOMOMMMMMMBM@@@vuB@MMMBB@B@MBMMOMMB
  r:i::B@MM8ZGZZ8GOZOZMEOGOZGZOOBMM8MO@BBMMMMOOMMOMOMMBMMMMOM8OB@O8ZOM@BOZ8Z88BMMOMMBMBMBBBB@B2 k@@BM8MM@B@B@OMOMO
  ;:i::@BMOOOO88GGOG888888Z8GBBBMMOOOOB@BBOMOMOBMMMMMMMBMMOMOO8OB@MOOBB@O8GOZMMMOMMMMMMBMBM@@@N  5B@MM8O8MOMM@OO8O
  r:;::B@MMOOOM8M8OGOZGZGGG8MMMOMOMOMOMB@BBMMOMMMOMMBMBMBOMOO8MMMM@MOGMBMZGZOMMMMMBMMMMMBMBB@BM . uB@BBOMOOOMMMMMM
  riii,MBMOOGM8MGMGOGOZO0MZOZOGOGOOOMOM@@@MMOMOMMMOBMMMBMM8MOMMMMOM@MOM@MGG8MMOMMMMMOBMBBBM@@@B ., LB@@@MMMOOOOMMO
  r:ri,0@MMG8GO8OOOOOO888OO888GZ88OGO8OB@B@MMMMMBOMMMMBMMOMMMMMOM8OO@BMBBZ8GBMOOMOMMBMMMBM@B@B@ ::, LB@B@BBMMOMOM8
  rirr.FBBMOOOOM8MOMGMZOGMOMOMMM8OGO888@B@B@MBOMMMMMMBMBMMOMOMMMMMOMM@B@MGZMBMOOOMMMMBMBM@M@B@B.,::: YB@@@B@MBMMMM
  7:i:.r@MMOMGOOOGO88Z8OM8MOMOMOM8MZOZMB@B@BBMMMMOMMMOMMMMMOMOOOMOMMMM@BBZ8BMOO8MMBMMMBMBMMM@@@ .,,,. rB@B@B@BBMMO

 /_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/

  ----------::*+==%%%%%==+*::::------------------::--:------------------------------------------------------------
  -----------------------:**+=======+**:::*+++===%%%%%%=+++++*::--------------------------------------------------
  ----------------------------------::*+=====%%%%%%%%%%%%%%%%%=++*::----------------------------------------------
  ---------------------------------:*====%%%%%%%%%%%@@@@%%%%%%%%%%=*::--------------------------------------------
  -------------------------------:+===%%%%%%%%%%%%%%%%%%%%%%%%%%%%=%%====++*::::----------------------------------
  ------------------------------*===%%%%%%%%%%%%%%%%%%%%%%%%%%%%@@@%%%=+*::--::**+=%%%=+**::::--------------------
  ----------------------------:==%%%%==%%%%%%%%%%%@@%%@@@@@@%%%%%@@@%%%=**=*:::----------::**+=%%%%=+**:::--------
  ---------------------------*%%%%%%%%%%%%%%%%%%%%%@@@@@@%%%%%%%%%%@@%%%%%%=**:------------------------::*+-------
  -------------------------:=%%%%%%%%%%%%%%%%%%%%%@@@@@%%%%%%%%%%%%%@@%%%%%%%+:-----------------------------------
  ------------------------:%%%%%%%%%%%%%%%%%@@@@@@@@@%@@%%%%========%%@%%%%%%%=:----------------------------------
  -----------------------*%%%%%%%%@%%%%%%%%%%%%%%%%%%%%%====++++++++==%%%@%%%%%=*---------------------------------
  ----------------------:=%%%%%%%%%%%%%%%%%%%%%%%%%==++++++++******+++=%%@@@%%%%=*--------------------------------
  ---------------------:=%%%@@@%%%%%%========++++++*********:::******+==%%@@@%%%%+:-------------------------------
  --------------------:+@@@@@%%++*+++++=+=+***********:::::::::::*****+=%%@@@@%%%+:-------------------------------
  --------------------:%@@@%%=+*::::*::::::::::**:::::::::::::::::::***==%%@@@%%%=:-------------------------------
  --------------------*%@@%%%=+*:::----:--::::::::::::::::::::::::::***+=%%@@@@%%+:-------------------------------
  ---------------------+@@@%%=+*::----------::::::::::::::::::::::*****+=%%%%@@%%+:-------------------------------
  --:------------------:@@@%%%=*::::------------::::::::::::::::*********+%%@@@%%*--------------------------------
  ---------------------:%@@@@%=*:::::-------------:------:::::::::********+%@@@@=---------------------------------
  ----------------------+@@@@%*:::::------------:-----:::::::*::::::*******=@@@%:---------------------------------
  ----------------------:@@@@=::::::---::::::*:::::::::*++=====+===+++*****+@@%+*---------------------------------
  -----------::----------:%@@=::::*+==%%%%%%%++*::::::**+++%%%=+**+*********%@=*+:---------------:----------------
  :------------:----------+@%+:::***++===%%==++**:::::***+==%@%%%+%%++******=%%**:--------------------------------
  -:::::::::--------------+%%*::::*+==+=%%%==%++*:::::**++%%==%==++++*******+%%*::--------------------------------
  :::::::::::::-::::------*@%*:::::*****+++++++**::-::*+++++++**************+%@+*:--------------------------------
  ::::::::::::::::::------:%@*:::::::::*********::--::*************::::::***+%%+*---------------------------------
  ::::*::::::::::::::::::--*%+:::------:::::::::::--::******:::**:::::::::**+%*::---------------------------------
  ::::::::::::::::::::::::---**:---------::-::::::--:*******::::::::::::::**++:::---------------------------------
  ++===%%@@@@@@%%==++**:::---:*:::--------:::::::--::::****::::::::::::::***+*:::----::::::::-::--:--:------------
  ===+++++=====++++*++++++:---**::-------:::::::----::******::::::::::::****+::::::::::::::::::::::::::::::-------
  ====%%%==+========%+++==+++*--::::------:::::::----::**:**::::::::::::*****::::::::::::::::::::::::::::::-------
  =====+==+=======+==++==+=++*--::::::-:-::::::***:::*******::::::::::::****%@@@@@@@@@%%==++***::::::::::::-------
  +++==+==*=+==+====%==+=%====--*::::::--:::::::**::*******::::::::::::****+==++====++++++++==%%%@@@@@@##@@-------
  =======+++========+=+=+===%%=--::::::-::::::::::::::::::::::::::::::*:***====+==%==+++===+++=+==++=+=====-------
  ++===%=*+==+=%==+===%%%=====%--+:::::::::::::::::**:::::::*:::::::::::**+==++=======%%%+=======+========%-------
  *+===+%%=%%%%======%%==%==%=%--=*::::::::*+=====++*+++===%=***:::::::***++==%===%====+=============++====-------
  @@@@@@@@@@@@@@%%%%===+=++=%===--=**::::::::::*********+**:::::::::::*****+======++===%=======+==+++======-------
  @@@@@@%%%@%%%%%======%=%%%%%%=--=:***::::::::::::****:::::::::::::******-=%====+++==+=======+===+====++==-------
  @%%@@%%@@%%@@@%@@%%%@%%@%@%%%%--*.:****::::::::::*++**:::::::::********--*%%=====+==+++++++=++++=+%+=====-------
  %%%@%%%%%%%%%%%%%%%%%%%%%%%%@%----.-*****::::::::::::***::::****++**+*----%%%%@@%%%@@@@@@@@@@@@@%%%%%%===-------
  @%%%%@%%=@=%%@%%%%%=%%%=%%====----...-+****::::::::::::::::***++**=+------=@%%%%%%%%%%%%%%%%%@@@@@@%@@@@@@@@@@@@
  %@%%%%%%%=%%%%%%%==+===%%%%%%%:----....-+=++***::::::::::**++++=%+-------:@@@@%%%%%%%%@%%%@@@%@%@@%%@@@%%@@@@@@@
  =%%@%%%%%%%==%=%%=%%%%@@@%=%%%=-----......:=+++++******+++++=%=:--------:%@@@@@@@@@%%%@%@%%@%@%%@@%%%@%%%@@@@@@@
  ++==%%=%%%==%%=%%%%%%@@%%==%%%%+-----......-:+%=+******+==%%*:--------:*%@@@@@@@@@@@@@%=%%%@%@@%@%%@@@@%@@@@@@@@
  %%=%%%%=%=%%%%%%%%@@@%%%%=%%%%%%*------....-%@@@@%%===%%@=:--------:::*%@@@@@@@@@@@@@@@@@%%%%@%@@%%@%%%%%@@@@@@@
  %%%%%%%%%%%%%%%%@@@@%%%%%%%%%%%%%*---=%--.*@@@@%=++=%==@@@@:-----::::*=@@@@@@@@@@@@@@@@@@@@@@@%%%%%@@@%%%@@@@@@@
  %%%%%%%%%%%%%@@@@@%%%%%%%%%%%%%%@=*:=-----@%%@@%=*+@%%*+%@@@----%@=:*+@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%%%%%@@@@@@@
  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%@=:----.-*@%@%@**++++===%@@%---:*%***@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
  %%%%%%%%%%%@@@@%%%%%%%%%%%%%%%%%%%*----.-%%%###=++@%#@==%@@@+---:::*%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
  %%%%%%%%%%@@@@%%%%%%%%%%%%%%%%%%%@+--:--%%%@####@%%@@@@@@#@@@%--::*=@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
  %%%%%%%%%@@@@@###@@%%%%%%%%%%%%%%@=--:-%@%@##@@@@@@@##@###@#@@@::*+@@@@@@@@@@@@@@@@@@@@@##@@@@@@@@@@@@@@@@@@@@@@
  %%%%%%@%@@@@@@@@@@%%%%%%%%%%%%%%%@@--*@@@@##@@@%@@@@@#@######@@#=*%@@@@@@@@@@@@@@@@@@##@@@@@@@@@@@@@@@@@@@@@@@@@
  %%%%%%@@@@@@@@@%%%%%%%%%%%%%%%%%%@@@@##@@%%=@@@@@@@@=@##@@#######@@@@@@@@@@@@@@@@@@@#@@@@@@@@@@@@@@@@@@@@@@@@@@@
  %%%%@@@@@@@@%%%%%%%%%%%%%%%%%%%%@@@@@##@+*+++@@@@@%@@@@@##@##@@##@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
  %%%@@@@@@@@%%%%%%%%%%%%%%%%%%%%%%%@@@@%+**::*=@@=@@@@@@#####@%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
  %%%@%@@@@@@@%%%%%%%%%%%%%%%%%%%%%@@@@@=+**:*+*:=@@@@@@#####@%==%@@@@@@@@@@@@@@@@@@@@@@@@@@#@@@@@@@@@@@@@@@@@@@@@
  %%%%%@%@@@@@%%%%%%%%%%%%%%%%%%%%%@@@@@@++****:-:=@@@@@@###@%==%@@@@@@@@@@@@@@@@@@@@@@@@@@##@@@@@@@@@@@@@@@@@@@@@
  %%%%%%@%@@@@@%%@%@%%%%%%%@@@@%%%@@@@@@@=+***::-:+@@@######%===@%@@@@@@@@@@@@@@@@@@@@@@@@##@@@@@@@@@@@@@@@@@@@@@@
  %%%%%%%%%%@@@@@%%%%%%%%%%@%@%%%%@@@@@@@%+***:::*@@@@######@==%@@@@@@@@@@@@@@@@@@@@@@@@###@@@@@@@@@@@@@@@@@@@@@@@
  %@%%%%%%%@%%@@@@%%%@%%%%@%%%%%%@@@@@@@@@++*:::*@@@#########%%@@@@@@@@@@@@@@%++@@@@@@@###@@@@@@@@@@@@@@@@@@@@@@@@
  @%%%%%%%%@@%@@@@@%@%@%%%@@%%%%@@@@@@@@@@%+****@@@###########@@@@@@@@@@@@@@@=:=@@@@@@###@@@@@@@@@@@@@@@@@@@@@@@@@
  @@%%@%%%%@%%@@@@@@%@@%@@@@@@%@@@@@@@@@@@@+**%#@@@##########@%@@@@@@@@@@@@@@%%@@@@@@###@@@@@@@@@@@@@@@@@@@@@@@@@@
  @%@%%@%%@%%@@@@@@@@%@@%@%@@@@%@@@@@@@@@@#++@#@@@@@########@%@@@@@@@@@@@@@@@@@@@@@@###@@@@@@@@@@@@@@@@@@@@@@@@@@@
  %%%%%@@@@%@%@@@@@@@%%%%%@@%%%@@@%@@@@@@@#@@#@@@@@@########@@@@@@@@@@@@@@@@@@@@@@###@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
  @@@@%@@%@@%@@@@@@@@@@@%@@@@@@@@@@@@@@@@@@####@###########@@@@@@@@@@@@@@@@@@@@@@##@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
  @@@%@@%@@%@@%@@@@@@@@@@@@@@@@@@@@@@@@@@@@###############@@@@@@@@@@@@@@@@@@@@@@#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
  @@%@%@@@%%@@@@%@@@@@@@@%@@@@@@@@@@@@@@@@@##############@@@@@@@@@@@@@@@@@@@@@##@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
  @@@%@@@@@%%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#############@@@@@@@@@@@@@@@@@@@@@##@@@@@@@@@@@@@@@@@@@@@@@@@@@#@@@@@@@
  %@%%@@@@@@@@@@%@@@@@@@@@@@@@@@@@@@@@@@@@@#############@@@@@@@@@@@@@@@@@@@###@@@@@@@@@@@@@@@@@@@@@@@@@@@@#@@@@@@@

*/



// Программа CYL.EXE сентябрь 2016 - август 2018



// cyl.cpp: определяет точку входа для консольного приложения.
//
//#define _CRT_SECURE_NO_WARNINGS
#include "stdafx.h"
#include <fstream>
#include <string.h> 
#include <iomanip>
#include <stdlib.h>
#include <fftw3.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <cmath> 
#include <iostream>
#include "float.h"
#include <time.h>
#include <random>
#include <ctime>
#include <windows.h>
#include <tchar.h>
#include <conio.h>
#include <omp.h> // многопоточность процессора
#include <io.h>
#include <process.h>
#include <string.h>
#include <vector>
#include <iterator>
#include <malloc.h> 

#pragma comment (lib, "User32.lib")
//#pragma comment (lib, "User64.lib")


/*


#ifdef _DEBUG
#include <crtdbg.h>
#define _CRTDBG_MAP_ALLOC
#endif

*/


#define _CRTDBG_MAP_ALLOC #include <stdlib.h> #include <crtdbg.h> 

// This source code was highlighted with Source Code Highlighter



using namespace std;

#include <amp.h>
#include <amp_math.h>
using namespace concurrency;

const long double epsilon = DBL_EPSILON * pow(10.0, 8.0);		 // предел точности для сравнения двух чисел, если сделать слишком маленьким, программа может не считать

const long double B_MAX = pow(3.7, 4.0); // большое поле для вычисления магнитного момента при больших полях
																 
																 
																 // библеотека alglib 

#include "stdafx.h"
#include <math.h>
#include "src/alglibmisc.h"
#include "src/alglibinternal.h"
#include "src/linalg.h"
#include "src/statistics.h"
#include "src/dataanalysis.h"
#include "src/specialfunctions.h"
#include "src/solvers.h"
#include "src/optimization.h"
#include "src/diffequations.h"
#include "src/fasttransforms.h"
#include "src/integration.h"
#include "src/interpolation.h"

using namespace alglib;


// функция подсчета длины массива
template<typename T> inline size_t arrlen(T *arr) {



	return static_cast<size_t>(_msize(arr) / sizeof(T));
}


/*




// Функция, генерирующая случайное действительное число от min до max  на языке C
long double random(long double min, long double max)
{
//задаем параметр случайности
srand((unsigned int)time(NULL) + rand()); // привязка генератора случайных чисел к системному времени
return (long double)rand() / RAND_MAX * (max - min) + min;

}


*/


//*************************************************************************************************************
// аппроксимация гамма-функции в интервале от 1 до 2
// отношением полиномов 8 степени
inline long double gammaapprox(double x) {
	double p[] = { -1.71618513886549492533811e+0,
		2.47656508055759199108314e+1,
		-3.79804256470945635097577e+2,
		6.29331155312818442661052e+2,
		8.66966202790413211295064e+2,
		-3.14512729688483675254357e+4,
		-3.61444134186911729807069e+4,
		6.64561438202405440627855e+4 };

	double q[] = { -3.08402300119738975254353e+1,
		3.15350626979604161529144e+2,
		-1.01515636749021914166146e+3,
		-3.10777167157231109440444e+3,
		2.25381184209801510330112e+4,
		4.75584627752788110767815e+3,
		-1.34659959864969306392456e+5,
		-1.15132259675553483497211e+5 };
	double z = x - 1.0;
	double a = 0.0;
	double b = 1.0;
	for (int i = 0; i < 8; i++) {
		a = (a + p[i])*z;
		b = b * z + q[i];
	}
	return (a / b + 1.0);
}


//*************************************************************************************************************
// Гамма-функция вещественного агрумента
// возвращает значение гамма-функции аргумента z
inline long double gamma(double z) {
	if ((z > 0.0) && (z < 1.0)) {

		if (z == 0.5) { //-V550

			return pow(M_PI, 1.0 / 2.0);	   	//точное соотношение

		}
		else {

			return gamma(z + 1.0) / z;	   	// рекурентное соотношение для 0
		}


	}
	if (z > 2) {
		return (z - 1)*gamma(z - 1);	 	// рекурентное соотношение для z>2 
	}
	if (z <= 0) {
		return M_PI / (sin(M_PI*z)*gamma(1 - z));	// рекурентное соотношение для z<=0 
	}
	else {

		return gammaapprox(z);	// 1<=z<=2 использовать аппроксимацию
	}
}





// Функция, генерирующая случайное действительное число от min до max на языке C++ V.11
inline long double random(long double min, long double max)
{


	std::random_device rd;
	//std::mt19937 gen(rd()+ time(NULL));
	std::mt19937_64 gen(rd() + (size_t)time(NULL));
	//std::mt19937_64 gen (rd());
	//std::mt19937_64 gen(rd());
	//std::mt19937_64 gen(rd());


	std::uniform_real_distribution<> dis((double)min, (double)max);

	//cout << dis(gen) << endl;

	return	dis(gen);




}

inline size_t random_integer(size_t min, size_t max)
{


	std::random_device rd;
	//	std::mt19937 gen(rd()+ time(NULL));
	std::mt19937_64 gen(rd() + (size_t)time(NULL));
	//std::mt19937_64 gen(rd());


	std::uniform_int_distribution<> dis(min, max);

	return	dis(gen);




}


inline long double temp_z(long double z0, long double theta, long double t) {

	long double temp_z = 0.0;

	temp_z = z0 + t * cos(theta);

	return temp_z;

}


// функция распределения Максвелла по модулю скорости
long double Maxwell_abs_speed(long double v, long double m, long double T, bool flaq_Maxwell_mode, long double drift_velocity) {

	const long double k = 1.3806485279; // постоянная Больцмана/10^-23 , Дж/К
	const long double N_A = 6.02214085774; // постоянная Авогадро/10^23 , 1/моль
	const long double R_gas_constant = 8.314459845; // // Универсальная газовая постоянная , Дж/(моль*K)

	long double A = 0.0; // нормировка для распределения при наличии дрейфовой скорости

	v = v / pow(10.0, 3.0);

	drift_velocity = drift_velocity / pow(10.0, 3.0);

	m = m * N_A*1.6605402*pow(10.0, -4.0); // в кг, скорость в мм/сек
										 // масса выражена в а.е.м
										 // 1 а.е.м=1.6605402*10^-27 кг

	long double f = 0.0;



	if (flaq_Maxwell_mode == false) {

		f = 4.0*M_PI*pow(v, 2.0)*pow((m / (2.0*M_PI*R_gas_constant*T)), 3.0 / 2.0)*exp(-m * pow(v, 2.0) / (2.0*R_gas_constant*T));



	}

	else if (flaq_Maxwell_mode == true) {

		if (fabs(drift_velocity)<epsilon) {
			f = pow(v, 3.0)*pow((m / (R_gas_constant*T)), 2.0)*exp(-m * pow(v, 2.0) / (2.0*R_gas_constant*T)) / 2.0;

		}
		else {

			//A = (2.0*pow(m, 2.0)) / (pow(2.0*R_gas_constant*T, 2.0)*(1.0 + m * pow(drift_velocity, 2.0) / (2.0*R_gas_constant*T))*exp(-m * pow(drift_velocity, 2.0) / (2.0*R_gas_constant*T)) + pow(2.0*M_PI / 3.0, 1.0 / 2.0)*pow(3.0*R_gas_constant*T, 2.0)*pow(m*pow(drift_velocity, 2.0) / (3.0*R_gas_constant*T), 1.0 / 2.0)*(1.0 + m * pow(drift_velocity, 2.0) / (3.0*R_gas_constant*T))*(1.0 + erf(pow(m*pow(drift_velocity,2.0) / (2.0*R_gas_constant*T), 1.0 / 2.0))));

			A = 0.5*pow(m / (R_gas_constant*T), 2.0) / ((1.0 + m * pow(drift_velocity, 2.0) / (2.0*R_gas_constant*T))*exp(-m * pow(drift_velocity, 2.0) / (2.0*R_gas_constant*T)) + (9.0 / 4.0)*pow(2.0*M_PI / 3.0, 1.0 / 2.0)*pow(m*pow(drift_velocity, 2.0) / (3.0*R_gas_constant*T), 1.0 / 2.0)*(1.0 + m * pow(drift_velocity, 2.0) / (3.0*R_gas_constant*T))*(1.0 + erf(pow(m*pow(drift_velocity, 2.0) / (2.0*R_gas_constant*T), 1.0 / 2.0))));

			f = A * pow(v, 3.0)*exp(-m * pow(v - drift_velocity, 2.0) / (2.0*R_gas_constant*T));

		}



	}




	return f;

}


inline long double f_v_median(long double x, long double m, long double T, bool flaq_Maxwell_mode, long double drift_velocity) {

	const long double k = 1.3806485279; // постоянная Больцмана/10^-23 , Дж/К
	const long double N_A = 6.02214085774; // постоянная Авогадро/10^23 , 1/моль
	const long double R_gas_constant = 8.314459845; // // Универсальная газовая постоянная , Дж/(моль*K)

//	cout << "масса " <<m<<" температура "<<T<<" скорость"<<x<<" дрифт скорость "<<drift_velocity<< endl;

	x = x / pow(10.0, 3.0);		  // в м/c

	drift_velocity = drift_velocity / pow(10.0, 3.0);			   // в м/c

	m = m * N_A*1.6605402*pow(10.0, -4.0); // в кг, скорость в мм/сек
										   // масса выражена в а.е.м
										   // 1 а.е.м=1.6605402*10^-27 кг


	long double f = 0.0;

	long double numerator = 0.0;

	long double denominator = 0.0;

	numerator = 2.0*(exp(-m * pow(drift_velocity, 2.0) / (2.0*R_gas_constant*T))*(1.0 + m * pow(drift_velocity, 2.0) / (2.0*R_gas_constant*T)) - exp(-m * pow(x - drift_velocity, 2.0) / (2.0*R_gas_constant*T))*(1.0 + m * (pow(x, 2.0) + x * drift_velocity + pow(drift_velocity, 2.0)) / (2.0 * R_gas_constant*T))) + 3.0*pow(M_PI / 2.0, 1.0 / 2.0)*drift_velocity*pow(m / (R_gas_constant*T),1.0/2.0)*(1.0 + m * pow(drift_velocity, 2.0) / (3.0*R_gas_constant*T))*(erf((x - drift_velocity)*pow(m / (2.0*R_gas_constant*T), 1.0 / 2.0)) + erf(drift_velocity*pow(m / (2.0*R_gas_constant*T), 1.0 / 2.0)));
	
	denominator = 2.0*exp(-m * pow(drift_velocity, 2.0) / (2.0*R_gas_constant*T))*(1.0 + m * pow(drift_velocity, 2.0) / (2.0*R_gas_constant*T)) + 3.0*pow(M_PI / 2.0, 1.0 / 2.0)*drift_velocity*pow(m / (R_gas_constant*T), 1.0 / 2.0)*(1.0 + m * pow(drift_velocity, 2.0) / (3.0*R_gas_constant*T))*(1.0 + erf(drift_velocity*pow(m / (2.0*R_gas_constant*T), 1.0 / 2.0)));
		
	f = numerator / denominator - 0.5;

//	cout << f << endl;

	return f;


}


void v_median_maxwell_beam(long double m, long double T, long double a, long double b, bool flaq_Maxwell_mode, long double &v_median, long double drift_velocity)
{
	//cout << "дрифт " << drift_velocity << endl;

	//out << "масса " << m << endl;
	
	long double v_median_numeric = 0.0;

	//cout << m << endl;

	long double tmp = 0.0, x0 = 0.0, x1 = 0.0, eps = pow(10.0, -4.0);
	int N = 0;

	long double v = 0.0;


	const long double e = exp(1.0); // число Эйлера

	const long double k = 1.3806485279; // постоянная Больцмана/10^-23 , Дж/К
	const long double N_A = 6.02214085774; // постоянная Авогадро/10^23 , 1/моль
	const long double R_gas_constant = 8.314459845; // // Универсальная газовая постоянная , Дж/(моль*K)

	//m = m * 0.0010735441498156322; // МэВ в а.е.м.

	m = m * N_A*1.6605402*pow(10.0, -4.0);

	drift_velocity = drift_velocity / pow(10.0, 3.0);		// в м/c





	if (flaq_Maxwell_mode == false) {



		x0 = pow(2.0*R_gas_constant*T / m, 1.0 / 2.0)*pow(10.0, 3.0);


	}

	else if (flaq_Maxwell_mode == true) {



		//x0 = pow(3.0*R_gas_constant*T / m, 1.0 / 2.0)*pow(10.0, 3.0);

		

		x0 = (drift_velocity / 2.0 + pow(3.0*R_gas_constant*T / m, 1.0 / 2.0)*pow(1.0 + m * pow(drift_velocity, 2.0) / (12.0*R_gas_constant*T), 1.0 / 2.0))*pow(10.0, 3.0);				    // наиболее вероятная скорость


	}

	x1 = b;

	//cout << "x0" << x0 << "x1 " << endl;

	//cout <<" " << x0 << " !!! " << x1 << endl;

	m = m / (N_A*1.6605402*pow(10.0, -4.0));

	drift_velocity = drift_velocity * pow(10.0, 3.0);

	long double f1 = 0.0;
	long double f2 = 0.0;
	long double f3 = 0.0;
	

	long double t = 0.0;
	long double x = 0.0;
//	cout << eps << endl;

	//x0 = a;

	do
	{
		t = (x0 + x1) / 2.0;
		f1 = f_v_median(x0, m, T, flaq_Maxwell_mode, drift_velocity);
		
		f2 = f_v_median(t, m, T, flaq_Maxwell_mode, drift_velocity);

		f3 = f_v_median(x1, m, T, flaq_Maxwell_mode, drift_velocity);

		if (f1*f2 < 0) {
			x1 = t;
		}
		else if (f3*f2 < 0) {
			x0 = t;
		}
	//	cout << " " << x0 <<" "<<t<<" "<<x1 << endl;

	//	cout << " " << f1 << " " << f2 << " " << f3 << endl;
	} while (fabs(x1 - x0) > eps);


	x = (x0 + x1) / 2.0;


	//v = x * pow(10.0, 3.0);


	v = x;











	v_median = v;

	m = m * (N_A*1.6605402*pow(10.0, -4.0));

	drift_velocity = drift_velocity / pow(10.0, 3.0);

	if (flaq_Maxwell_mode == false) {

		v_median_numeric = 1.29551032030496*pow(2.0*R_gas_constant*T / m, 1.0 / 2.0)*pow(10.0, 3.0);

		v_median = v_median_numeric;
	}
	else if (flaq_Maxwell_mode == true) {

		if (fabs(drift_velocity) < epsilon) {

			v_median_numeric = 1.29551032030496*pow(2.0*R_gas_constant*T / m, 1.0 / 2.0)*pow(10.0, 3.0);
			v_median = v_median_numeric;
		}
		else {

			v_median = v_median;
		}
	}




}






// максимум распределения
long double Max_Maxwell_abs_speed(long double m, long double T, bool flaq_Maxwell_mode, long double &v1, long double &v2, long double &v3, long double &v4, long double drift_velocity, long double a, long double b) {

	long double e = exp(1.0); // число Эйлера

	const long double k = 1.3806485279; // постоянная Больцмана/10^-23 , Дж/К
	const long double N_A = 6.02214085774; // постоянная Авогадро/10^23 , 1/моль
	const long double R_gas_constant = 8.314459845; // // Универсальная газовая постоянная , Дж/(моль*K)



	m = m * N_A*1.6605402*pow(10.0, -4.0);
	// масса выражена в а.е.м
	// 1 а.е.м=1.6605402*10^-27 кг


	//m*N_A*1.6605402*pow(10.0, -10.0)
	long double M = 0.0;

	if (flaq_Maxwell_mode == false) {

		M = (4.0 / e)*pow((m / (2.0*M_PI*R_gas_constant*T)), 1.0 / 2.0);			 // максимум распределения

		v1 = pow(2.0*R_gas_constant*T / m, 1.0 / 2.0)*pow(10.0, 3.0);				// наиболее вероятная скорость
		v2 = pow(8.0*R_gas_constant*T / (M_PI*m), 1.0 / 2.0)*pow(10.0, 3.0);	   // средняя скорость
		v3 = pow(3.0*R_gas_constant*T / m, 1.0 / 2.0)*pow(10.0, 3.0);			   // ср.кв. скорость
		v4 = 1.0876520317581673*pow(2.0*R_gas_constant*T / m, 1.0 / 2.0)*pow(10.0, 3.0);	  // медианная скорость

	}

	else if (flaq_Maxwell_mode == true) {

		if (fabs(drift_velocity)<epsilon) {

			M = pow(3.0 / e, 3.0 / 2.0)*pow((m / (R_gas_constant*T)), 1.0 / 2.0) / 2.0;			 // максимум распределения

			v1 = pow(3.0*R_gas_constant*T / m, 1.0 / 2.0)*pow(10.0, 3.0);				    // наиболее вероятная скорость
			v2 = 3.0*pow(M_PI*R_gas_constant*T / (8.0*m), 1.0 / 2.0)*pow(10.0, 3.0);	   // средняя скорость
			v3 = pow(4.0*R_gas_constant*T / m, 1.0 / 2.0)*pow(10.0, 3.0);					    // ср.кв. скорость
			v4 = 1.29551032030496*pow(2.0*R_gas_constant*T / m, 1.0 / 2.0)*pow(10.0, 3.0);		  // медианная скорость

		}
		else {

			//			M = (1.0/2.0)*pow(3.0, 3.0 / 2.0)*pow((m / (R_gas_constant*T)), 1.0 / 2.0)*(exp(-()/()))/();		   	   // максимум распределения

			drift_velocity = drift_velocity / pow(10.0, 3.0);

			v1 = (drift_velocity / 2.0 + pow(3.0*R_gas_constant*T / m, 1.0 / 2.0)*pow(1.0 + m * pow(drift_velocity, 2.0) / (12.0*R_gas_constant*T), 1.0 / 2.0))*pow(10.0, 3.0);				    // наиболее вероятная скорость

			M = Maxwell_abs_speed(v1, m / (N_A*1.6605402*pow(10.0, -4.0)), T, flaq_Maxwell_mode, drift_velocity*pow(10.0, 3.0));

			v2 = drift_velocity * ((10.0*(1.0 + m * pow(drift_velocity, 2.0) / (5.0*R_gas_constant*T))*exp(-m * pow(drift_velocity, 2.0) / (2.0*R_gas_constant*T)) + pow(6.0*M_PI, 1.0 / 2.0)*pow((3.0*R_gas_constant*T) / (m * pow(drift_velocity, 2.0)), 1.0 / 2.0)*(1.0 + 2.0*m * pow(drift_velocity, 2.0) / (R_gas_constant*T) + pow(m * pow(drift_velocity, 2.0) / (R_gas_constant*T), 2.0) / 3.0)*(1.0 + erf(pow(m / (2.0*R_gas_constant*T), 1.0 / 2.0)*drift_velocity))) / (4.0*(1.0 + m * pow(drift_velocity, 2.0) / (2.0*R_gas_constant*T))*exp(-m * pow(drift_velocity, 2.0) / (2.0*R_gas_constant*T)) + 9.0*pow(2.0*M_PI / 3.0, 1.0 / 2.0)*pow(m * pow(drift_velocity, 2.0) / (3.0*R_gas_constant*T), 1.0 / 2.0)*(1.0 + m * pow(drift_velocity, 2.0) / (3.0*R_gas_constant*T))*(1.0 + erf(pow(m / (2.0*R_gas_constant*T), 1.0 / 2.0)*drift_velocity))))*pow(10.0, 3.0);	   // средняя скорость
			v3 = pow(R_gas_constant*T / m, 1.0 / 2.0)*pow((16.0*(1.0 + m * pow(drift_velocity, 2.0) / (R_gas_constant*T))*(1.0 + m * pow(drift_velocity, 2.0) / (8.0*R_gas_constant*T))*exp(-m * pow(drift_velocity, 2.0) / (2.0*R_gas_constant*T)) + 45.0*pow(2.0*M_PI / 3.0, 1.0 / 2.0)*pow(m * pow(drift_velocity, 2.0) / (3.0*R_gas_constant*T), 1.0 / 2.0)*(1.0 + (2.0 / 3.0)*m * pow(drift_velocity, 2.0) / (R_gas_constant*T) + pow(m * pow(drift_velocity, 2.0) / (R_gas_constant*T), 2.0) / 15.0)*(1.0 + erf(pow(m / (2.0*R_gas_constant*T), 1.0 / 2.0)*drift_velocity))) / (4.0*(1.0 + m * pow(drift_velocity, 2.0) / (2.0*R_gas_constant*T))*exp(-m * pow(drift_velocity, 2.0) / (2.0*R_gas_constant*T)) + 9.0*pow(2.0*M_PI / 3.0, 1.0 / 2.0)*pow(m * pow(drift_velocity, 2.0) / (3.0*R_gas_constant*T), 1.0 / 2.0)*(1.0 + m * pow(drift_velocity, 2.0) / (3.0*R_gas_constant*T))*(1.0 + erf(pow(m / (2.0*R_gas_constant*T), 1.0 / 2.0)*drift_velocity))), 1.0 / 2.0)*pow(10.0, 3.0);					    // ср.кв. скорость
		
			m = m /(N_A*1.6605402*pow(10.0, -4.0));
			drift_velocity = drift_velocity* pow(10.0, 3.0);
			v_median_maxwell_beam( m, T,  a, b, flaq_Maxwell_mode, v4, drift_velocity);
			
			m = m * N_A*1.6605402*pow(10.0, -4.0);
			drift_velocity = drift_velocity / pow(10.0, 3.0);
			//v4 = 0.0*pow(10.0, 3.0);  // медианная скорость
		}

	}

	//cout<<"наиболее вероятная скорость" << v1 << endl;
	//cout << "средняя скорость" << v2 << endl;
	//cout << "ср. кв. скорость" << v3 << endl;
	//cout << "максимум" << M << endl;

	return M;
}


inline long double random_Neumann_Maxwell_abs_speed(long double a, long double b, long double m, long double T, bool flaq_Maxwell_mode, long double &v1, long double &v2, long double &v3, long double &v4, long double &M, long double drift_velocity) {

	//cout << m << endl;

	long double r1 = 0.0;
	long double r2 = 0.0;


	M = Max_Maxwell_abs_speed(m, T, flaq_Maxwell_mode, v1, v2, v3, v4, drift_velocity, a,b );

	//cout << "дрифт скорость" << drift_velocity << endl;
	
	//cout << erf(9999999.0) << endl;
	//cout<<"максимум" << M << endl;

	bool flaq = false;

	while (flaq == false) {


		r1 = random(0.0, 1.0);
		r2 = random(0.0, 1.0);


		r1 = a + r1 * (b - a);
		r2 = M * r2;

		if(fabs(Maxwell_abs_speed(r1, m, T, flaq_Maxwell_mode, drift_velocity)) < DBL_EPSILON*pow(10.0,3.0)) {

			continue;
		}
		else {


			if (r2 <= Maxwell_abs_speed(r1, m, T, flaq_Maxwell_mode, drift_velocity)) {

				//cout << "переносная скорость" << drift_velocity << endl;
				//cout << "скорость" << r1 << endl;
				flaq = true;
			}

			else {

				//cout << "переносная скорость" << drift_velocity << endl;
				//cout << "скорость" << r1 << endl;
				flaq = false;
			}
		}

	}
	//	cout << "переносная скорость" << drift_velocity << endl;
	//	cout <<"скорость"<< r1 << endl;
	return r1;

}


void v_mean_maxwell(long double m, long double T, long double a, long double b, bool flaq_Maxwell, bool flaq_Maxwell_mode, long double drift_velocity, long double &v1, long double &v2, long double &v3, long double &v4) {

  	long double e = exp(1.0); // число Эйлера

	const long double k = 1.3806485279; // постоянная Больцмана/10^-23 , Дж/К
	const long double N_A = 6.02214085774; // постоянная Авогадро/10^23 , 1/моль
	const long double R_gas_constant = 8.314459845; // // Универсальная газовая постоянная , Дж/(моль*K)

	m = m * 0.0010735441498156322;

	m = m * N_A*1.6605402*pow(10.0, -4.0);

	if (flaq_Maxwell == false) {
		v1 = pow(2.0*R_gas_constant*T / m, 1.0 / 2.0)*pow(10.0, 3.0);
		v2 = pow(2.0*R_gas_constant*T / m, 1.0 / 2.0)*pow(10.0, 3.0);
		v3 = pow(2.0*R_gas_constant*T / m, 1.0 / 2.0)*pow(10.0, 3.0);
		v4 = NAN;


	}
	else if (flaq_Maxwell == true) {


		if (flaq_Maxwell_mode == false) {

			//	M = (4.0 / e)*pow((m / (2.0*M_PI*R_gas_constant*T)), 1.0 / 2.0);			 // максимум распределения

			v1 = pow(2.0*R_gas_constant*T / m, 1.0 / 2.0)*pow(10.0, 3.0);				// наиболее вероятная скорость
			v2 = pow(8.0*R_gas_constant*T / (M_PI*m), 1.0 / 2.0)*pow(10.0, 3.0);	   // средняя скорость
			v3 = pow(3.0*R_gas_constant*T / m, 1.0 / 2.0)*pow(10.0, 3.0);			   // ср.кв. скорость
			v4 = 1.0876520317581673*pow(2.0*R_gas_constant*T / m, 1.0 / 2.0)*pow(10.0, 3.0);	  // медианная скорость

		}

		else if (flaq_Maxwell_mode == true) {

			if (fabs(drift_velocity) < epsilon) {

				//	M = pow(3.0 / e, 3.0 / 2.0)*pow((m / (R_gas_constant*T)), 1.0 / 2.0) / 2.0;			 // максимум распределения

				v1 = pow(3.0*R_gas_constant*T / m, 1.0 / 2.0)*pow(10.0, 3.0);				    // наиболее вероятная скорость
				v2 = 3.0*pow(M_PI*R_gas_constant*T / (8.0*m), 1.0 / 2.0)*pow(10.0, 3.0);	   // средняя скорость
				v3 = pow(4.0*R_gas_constant*T / m, 1.0 / 2.0)*pow(10.0, 3.0);					    // ср.кв. скорость
				v4 = 1.29551032030496*pow(2.0*R_gas_constant*T / m, 1.0 / 2.0)*pow(10.0, 3.0);		  // медианная скорость

			}
			else {

				//			M = (1.0/2.0)*pow(3.0, 3.0 / 2.0)*pow((m / (R_gas_constant*T)), 1.0 / 2.0)*(exp(-()/()))/();		   	   // максимум распределения

				drift_velocity = drift_velocity / pow(10.0, 3.0);

				v1 = (drift_velocity / 2.0 + pow(3.0*R_gas_constant*T / m, 1.0 / 2.0)*pow(1.0 + m * pow(drift_velocity, 2.0) / (12.0*R_gas_constant*T), 1.0 / 2.0))*pow(10.0, 3.0);				    // наиболее вероятная скорость

			//	M = Maxwell_abs_speed(v1, m / (N_A*1.6605402*pow(10.0, -4.0)), T, flaq_Maxwell_mode, drift_velocity*pow(10.0, 3.0));

				v2 = drift_velocity * ((10.0*(1.0 + m * pow(drift_velocity, 2.0) / (5.0*R_gas_constant*T))*exp(-m * pow(drift_velocity, 2.0) / (2.0*R_gas_constant*T)) + pow(6.0*M_PI, 1.0 / 2.0)*pow((3.0*R_gas_constant*T) / (m * pow(drift_velocity, 2.0)), 1.0 / 2.0)*(1.0 + 2.0*m * pow(drift_velocity, 2.0) / (R_gas_constant*T) + pow(m * pow(drift_velocity, 2.0) / (R_gas_constant*T), 2.0) / 3.0)*(1.0 + erf(pow(m / (2.0*R_gas_constant*T), 1.0 / 2.0)*drift_velocity))) / (4.0*(1.0 + m * pow(drift_velocity, 2.0) / (2.0*R_gas_constant*T))*exp(-m * pow(drift_velocity, 2.0) / (2.0*R_gas_constant*T)) + 9.0*pow(2.0*M_PI / 3.0, 1.0 / 2.0)*pow(m * pow(drift_velocity, 2.0) / (3.0*R_gas_constant*T), 1.0 / 2.0)*(1.0 + m * pow(drift_velocity, 2.0) / (3.0*R_gas_constant*T))*(1.0 + erf(pow(m / (2.0*R_gas_constant*T), 1.0 / 2.0)*drift_velocity))))*pow(10.0, 3.0);	   // средняя скорость
				v3 = pow(R_gas_constant*T / m, 1.0 / 2.0)*pow((16.0*(1.0 + m * pow(drift_velocity, 2.0) / (R_gas_constant*T))*(1.0 + m * pow(drift_velocity, 2.0) / (8.0*R_gas_constant*T))*exp(-m * pow(drift_velocity, 2.0) / (2.0*R_gas_constant*T)) + 45.0*pow(2.0*M_PI / 3.0, 1.0 / 2.0)*pow(m * pow(drift_velocity, 2.0) / (3.0*R_gas_constant*T), 1.0 / 2.0)*(1.0 + (2.0 / 3.0)*m * pow(drift_velocity, 2.0) / (R_gas_constant*T) + pow(m * pow(drift_velocity, 2.0) / (R_gas_constant*T), 2.0) / 15.0)*(1.0 + erf(pow(m / (2.0*R_gas_constant*T), 1.0 / 2.0)*drift_velocity))) / (4.0*(1.0 + m * pow(drift_velocity, 2.0) / (2.0*R_gas_constant*T))*exp(-m * pow(drift_velocity, 2.0) / (2.0*R_gas_constant*T)) + 9.0*pow(2.0*M_PI / 3.0, 1.0 / 2.0)*pow(m * pow(drift_velocity, 2.0) / (3.0*R_gas_constant*T), 1.0 / 2.0)*(1.0 + m * pow(drift_velocity, 2.0) / (3.0*R_gas_constant*T))*(1.0 + erf(pow(m / (2.0*R_gas_constant*T), 1.0 / 2.0)*drift_velocity))), 1.0 / 2.0)*pow(10.0, 3.0);					    // ср.кв. скорость

				m = m / (N_A*1.6605402*pow(10.0, -4.0));
				drift_velocity = drift_velocity * pow(10.0, 3.0);
				v_median_maxwell_beam(m, T, a, b, flaq_Maxwell_mode, v4, drift_velocity);

				m = m * N_A*1.6605402*pow(10.0, -4.0);
				drift_velocity = drift_velocity / pow(10.0, 3.0);
				//v4 = 0.0*pow(10.0, 3.0);  // медианная скорость
			}

		}


	}




}




inline long double f_theta_intensity(long double theta, long double n_cos_intensity) {

	long double A_theta_intensity = 2.0*gamma(n_cos_intensity / 2.0 + 1.0) / (pow(M_PI, 1.0 / 2.0)*gamma((n_cos_intensity + 1.0) / 2.0));

	long double f = 0.0;

	f = A_theta_intensity * pow(cos(theta), n_cos_intensity);

	return 	f;
}

inline long double random_Neumann_theta_intensity(long double n_cos_intensity) {

	long double a = 0.0;
	long double b = M_PI_2;

	long double A_theta_intensity = 2.0*gamma(n_cos_intensity / 2.0 + 1.0) / (pow(M_PI, 1.0 / 2.0)*gamma((n_cos_intensity + 1.0) / 2.0));


	long double M = A_theta_intensity;


	long double r1 = 0.0;
	long double r2 = 0.0;





	bool flaq = false;

	while (flaq == false) {


		r1 = random(0.0, 1.0);
		r2 = random(0.0, 1.0);


		r1 = a + r1 * (b - a);
		r2 = M * r2;

		if (r2 <= f_theta_intensity(r1, n_cos_intensity)) {


			flaq = true;
		}

		else {

			flaq = false;
		}

	}

	return r1;

}




inline long double min_new(long double a, long double b) {

	long double temp = 0.0;

	if (a < b) {
		temp = a;
	}
	else {
		temp = b;
	}

	return temp;
}


inline long double max_new(long double a, long double b) {

	long double temp = 0.0;

	if (a < b) {
		temp = b;
	}
	else {
		temp = a;
	}

	return temp;
}


// функция знака числа

inline long double signum(long double x) {



	if (x > 0.0) {


		return 1.0;
	}

	else if (fabs(x - 0.0) <= epsilon) {


		return 0.0;
	}

	else if (x < 0.0) {



		return -1.0;
	}



	return 0.0;



}


// поворот вокруг оси z + обратная матрица поворота

inline void rotate(const char *s, long double x0, long double y0, long double z0, long double &x, long double &y, long double &z) {


	long double	temp_x = x;
	long double	temp_y = y;
	long double	temp_z = z;


	long double alpha = 0.0;

	if (fabs(x0 - 0.0) <= epsilon && y0 > 0) {

		alpha = M_PI_2;
	}


	if (fabs(x0 - 0.0) <= epsilon && y0 < 0) {

		alpha = 3.0*M_PI_2;
	}


	if (fabs(y0 - 0.0) <= epsilon && x0 > 0) {

		alpha = 0.0;
	}

	if (fabs(y0 - 0.0) <= epsilon && x0 < 0) {

		alpha = M_PI;
	}

	if (fabs(y0 - 0.0) <= epsilon && fabs(x0 - 0.0) <= epsilon) {

		alpha = 0.0;
	}

	if (x0 > 0 && y0 > 0) {

		alpha = atan(fabs(y0 / x0));
	}



	if (x0 < 0 && y0 < 0) {

		alpha = M_PI + atan(fabs(y0 / x0));
	}

	if (x0 > 0 && y0 < 0) {

		alpha = 2.0*M_PI - atan(fabs(y0 / x0));
	}


	if (x0 < 0 && y0 > 0) {

		alpha = M_PI - atan(fabs(y0 / x0));
	}

	if (strcmp(s, "matrix") == 0) {

		x = temp_x * cos(alpha) + temp_y * sin(alpha);
		y = -temp_x * sin(alpha) + temp_y * cos(alpha);
		z = temp_z;

	}

	if (strcmp(s, "inverse_matrix") == 0) {

		x = temp_x * cos(alpha) - temp_y * sin(alpha);
		y = temp_x * sin(alpha) + temp_y * cos(alpha);
		z = temp_z;
	}

}


// Функция, строящая функцию распределения(гистограмму) числа частиц, попавших в бины гистограммы, распределение по радиусу

// гистограмма распределения по радиусу с учетом знака координаты y (проинтегрировано по половине полного угла)
long double **histo_x(const char *s, long double **mass_histo, std::size_t N_histo, long double x, long double y, long double R, long double R_source, long double x_0_source) {


	long double h = 2.0*R / (long double)N_histo; // ширина бина


	if (strcmp(s, "histo") == 0) {

		long double r = pow(pow(x, 2.0) + pow(y, 2.0), 1.0 / 2.0); // текущий радиус

		size_t lenrow = arrlen(mass_histo);

		for (size_t i = 0; i < (lenrow / 2); i = i + 1) { // перебираем бины

			if ((r > (R - h * (i + 1.0))) && (r <= (R - h * i)) && (y <= 0))
			{
				mass_histo[i][0] = mass_histo[i][0] + 1.0; // если частица попала в бин, то содержимое бина увеличилось на одну частицу

			}

			if ((r > (R - h * (i + 1.0))) && (r <= (R - h * i)) && (y > 0))
			{
				mass_histo[lenrow - 1 - i][0] = mass_histo[lenrow - 1 - i][0] + 1.0; // если частица попала в бин, то содержимое бина увеличилось на одну частицу

			}

		}
	}

	if (strcmp(s, "source") == 0) {

		long double r = 0.0;  // текущий радиус
		long double y_0_source = 0.0; // смещение детектора

		size_t lenrow = arrlen(mass_histo);

		for (size_t i = 0; i < lenrow; i = i + 1) { // перебираем бины

			y_0_source = -R + h * i;

			r = pow(pow(x - x_0_source, 2.0) + pow(y - y_0_source, 2.0), 1.0 / 2.0);

			if (r <= R_source)
			{
				mass_histo[i][0] = mass_histo[i][0] + 1.0; // если частица попала в кольцо детектора, то содержимое бина увеличилось на одну частицу

			}


		}




	}




	return mass_histo;



}


// гистограмма распределения по модулю радиусу (проинтегрировано по полному углу)
long double **histo_r(const char *s, long double **mass_histo, std::size_t N_histo, long double x, long double y, long double R, long double R_source, long double x_0_source) {


	long double h = R / N_histo; // ширина бина


	if (strcmp(s, "histo") == 0) {

		long double r = pow(pow(x, 2.0) + pow(y, 2.0), 1.0 / 2.0); // текущий радиус

		size_t lenrow = arrlen(mass_histo);

		for (size_t i = 0; i < lenrow; i = i + 1) { // перебираем бины

			if ((r > (R - h * (i + 1.0))) && (r <= (R - h * i)))
			{
				mass_histo[lenrow - 1 - i][0] = mass_histo[lenrow - 1 - i][0] + 1.0; // если частица попала в бин, то содержимое бина увеличилось на одну частицу

			}


		}


	}





	if (strcmp(s, "source") == 0) {

		long double r = 0.0;  // текущий радиус
		long double y_0_source = 0.0; // смещение детектора

		size_t lenrow = arrlen(mass_histo);

		for (size_t i = 0; i < lenrow; i = i + 1) { // перебираем бины

			y_0_source = h * i;

			r = pow(pow(x - x_0_source, 2.0) + pow(fabs(y - y_0_source), 2.0), 1.0 / 2.0);


			if ((r <= R_source))
			{
				mass_histo[i][0] = mass_histo[i][0] + 1.0; // если частица попала в кольцо детектора, то содержимое бина увеличилось на одну частицу

			}


		}

	}


	return mass_histo;
}


// гистограмма распределения по модулю скорости
long double **histo_V_0(long double **mass_histo_V_0, std::size_t N_histo_V_0, long double a_V_0, long double b_V_0, long double V_0) {


	long double h = (b_V_0 - a_V_0) / N_histo_V_0; // ширина бина

	size_t lenrow = arrlen(mass_histo_V_0);

	for (size_t i = 0; i < lenrow; i = i + 1) { // перебираем бины

		if ((V_0 > (h*i)) && (V_0 <= (h*(i + 1)))) {

			mass_histo_V_0[i][0] = mass_histo_V_0[i][0] + 1.0;

		}

	}

	return mass_histo_V_0;

}




// гистограмма распределения по модулю скорости
long double **histo_time(long double **mass_histo_time, std::size_t N_histo_time, long double a_time, long double b_time, long double time) {


	long double h = (b_time - a_time) / N_histo_time; // ширина бина

	size_t lenrow = arrlen(mass_histo_time);

	for (size_t i = 0; i < lenrow; i = i + 1) { // перебираем бины

		if ((time > (h*i)) && (time <= (h*(i + 1)))) {

			mass_histo_time[i][0] = mass_histo_time[i][0] + 1.0;

		}

	}

	return mass_histo_time;

}




// гистограмма распределения по углу theta
long double **histo_theta_in(long double **mass_histo_theta_in, std::size_t N_histo_theta_in, long double theta_in) {


	long double h = M_PI / N_histo_theta_in; // ширина бина

	size_t lenrow = arrlen(mass_histo_theta_in) - 1;

	for (size_t i = 0; i < lenrow; i = i + 1) { // перебираем бины

		if ((theta_in > (-M_PI_2 + h * i)) && (theta_in <= (-M_PI_2 + h * (i + 1)))) {

			mass_histo_theta_in[i][0] = mass_histo_theta_in[i][0] + 1.0;


		}
		//else {
		//continue;
		//}




	}

	return mass_histo_theta_in;

}


void mass_histo_out(long double **arr) { // печать содержимого двумерного массива в терминале
	size_t lenrow = arrlen(arr);
	size_t lencol = arrlen(arr[0]);
	for (size_t i = 0; i < lenrow; ++i) {
		std::cout << "[ ";
		for (size_t j = 0; j < lencol; ++j) {

			std::cout << std::fixed << std::setprecision(3) << arr[i][j] << " ";
		}

		std::cout << "]" << std::endl;
	}

}


long double angular_coefficient_calculation(long double L_initial, long double L_final, long double R1_initial, long double R2_initial, long double R3_initial, long double R1_final, long double R2_final, long double R3_final, long int N_r, long int N_phi, long double n_cos_intensity) {

	long double h_r_initial = fabs(R2_initial - R3_initial) / N_r;
	long double h_r_final = fabs(R2_final - R3_final) / N_r;
	long double h_phi_initial = 2.0*M_PI / N_phi;
	long double h_phi_final = 2.0*M_PI / N_phi;

	long double r1 = R3_initial;
	long double r2 = R3_final;




	long double phi1 = 0.0;
	long double phi2 = 0.0;

	long double theta1 = 0.0;

	long double theta2 = 0.0;

	long double z1 = L_initial;
	long double z2 = L_final;

	//	cout << r1 << endl;
	//	cout << r2 << endl;
	//	cout << z1 << endl;
	//	cout << z2 << endl;

	long double r12 = 0.0;

	long double x1 = 0.0;
	long double y1 = 0.0;

	long double x2 = 0.0;
	long double y2 = 0.0;


	long double dS1 = 0.0;
	long double dS2 = 0.0;

	long double K = 0.0;

	long double  angular_coefficient = 0.0;


	dS1 = r1 * h_r_initial*h_phi_initial;
	dS2 = r2 * h_r_final*h_phi_final;

	//#pragma omp  parallel for 





#pragma omp  parallel for ordered schedule(dynamic)







	for (int i = 0; i < N_r; i = i + 1) {
		// while(r1<R2_initial)	{

#pragma omp ordered
		{



			//h_phi_initial = 2.0*M_PI / N_phi;
			h_phi_final = 2.0*M_PI / N_phi;
			r2 = R3_final;
			phi1 = 0.0;
			phi2 = 0.0;

			//	while (phi1 <= 2.0*M_PI-h_phi_initial*r1 /(r1 - h_r_initial)) {
					//	#pragma omp  parallel for

#pragma omp  parallel for ordered schedule(dynamic)
			for (int j = 0; j < N_phi; j = j + 1) {
#pragma omp ordered
				{

					h_phi_final = 2.0*M_PI / N_phi;
					r2 = R3_final;
					phi2 = 0.0;

					//	#pragma omp  parallel for 
#pragma omp  parallel for ordered schedule(dynamic)

					for (int k = 0; k < N_r; k = k + 1) {
#pragma omp ordered
						{

							phi2 = 0.0;
							//	while (r2<R2_final) {

						//	while (phi2 <= 2.0*M_PI-h_phi_final*r2 / (r2 - h_r_final)) {
#pragma omp  parallel for ordered schedule(dynamic)

							for (int m = 0; m < N_phi; m = m + 1) {
#pragma omp ordered
								{
									//	for(;;){

									x1 = r1 * cos(phi1);
									y1 = r1 * sin(phi1);

									x2 = r2 * cos(phi2);
									y2 = r2 * sin(phi2);

									r12 = pow(pow(x2 - x1, 2.0) + pow(y2 - y1, 2.0) + pow(z2 - z1, 2.0), 1.0 / 2.0);

									theta1 = acos(fabs(z2 - z1) / r12);
									theta2 = acos(fabs(z2 - z1) / r12); //-V656

									//cout << theta1 << endl;

									//cout << z1 << endl;
									//cout << z2 << endl;

									//cout << r12 << endl;


								//	K = ((n_cos_intensity + 1.0) / (2.0*M_PI))*pow(cos(theta1), n_cos_intensity)*pow(cos(theta2), n_cos_intensity) / pow(r12, 2.0);

								//	K = ((n_cos_intensity + 1.0) / (2.0*M_PI))*cos(theta1)*cos(theta2) / pow(r12, 2.0);

									K = ((n_cos_intensity + 1.0) / (2.0*M_PI))*pow(cos(theta1), n_cos_intensity)*cos(theta2) / pow(r12, 2.0);

									dS1 = r1 * h_r_initial*h_phi_initial;
									dS2 = r2 * h_r_final*h_phi_final;

									angular_coefficient = angular_coefficient + K * dS1*dS2;



									/*



									if (m == 0) {
										angular_coefficient = angular_coefficient + K*dS1*dS2 / 3.0;
										goto step_out;
									}
									if (m == (N_phi-1)) {

										//cout << "!" << endl;
										angular_coefficient = angular_coefficient + K*dS1*dS2 / 3.0;
										goto step_out;
									}
									if (m != 0 && m != (N_phi - 1) && m % 2 == 0) {

										angular_coefficient = angular_coefficient + 2.0*K*dS1*dS2 / 3.0;
										goto step_out;
									}

									if (m != 0 && m != (N_phi - 1) && m % 2 == 1) {

										angular_coefficient = angular_coefficient + 4.0*K*dS1*dS2 / 3.0;
										goto step_out;
									}


									step_out:

								   */

								   //printf("%.5e\n", K*dS1*dS2);

									phi2 = phi2 + h_phi_final;

									//	cout << r1 << " " << phi1 << " " << r2 << " " << phi2 << endl;

										//	if (phi2 > 2.0*M_PI) {
										//		break;
										//	}
								}
							}



							r2 = r2 + h_r_final;
							//h_r_final = dS2 / (r2*h_phi);
						//	h_phi_final = dS2 / (r2*h_r_final);
						//	h_phi_final = h_phi_final*(r2 - h_r_final) / r2;


						//cout << h_phi_final << endl;

						//	h_phi_final = h_phi_final*(r2 - h_r_final) / r2;

							//cout << h_phi_final << endl;
							//cout  << endl;

							//	dS2 = r2*h_r_final*h_phi_final;
						}
					}



					phi1 = phi1 + h_phi_initial;

				}
			}



			r1 = r1 + h_r_initial;
			//h_r_initial=dS1/(r1*h_phi);
			//h_phi_initial = dS1 / (r1*h_r_initial);
			//cout << h_phi_initial << endl;


		//	h_phi_initial = h_phi_initial*(r1 - h_r_initial) / r1;


			//cout << h_phi_initial << endl;
			//cout  << endl;

			//	dS1 = r1*h_r_initial*h_phi_initial;

		}
	}





	long double S1 = M_PI * (pow(R2_initial, 2.0) - pow(R3_initial, 2.0));

	long double S2 = M_PI * (pow(R2_final, 2.0) - pow(R3_final, 2.0));

	angular_coefficient = angular_coefficient / S1;







	return angular_coefficient;

}



long double angular_coefficient_calculation_monte_carlo(long double L_initial, long double L_final, long double R1_initial, long double R2_initial, long double R3_initial, long double R1_final, long double R2_final, long double R3_final, long int N_monte_carlo, long double n_cos_intensity) {



	long double r1_min = R3_initial;
	long double r2_min = R3_final;


	long double r1_max = R2_initial; //-V537
	long double r2_max = R2_final;

	long double r1 = 0.0;
	long double r2 = 0.0;


	long double phi1_min = 0.0;
	long double phi2_min = 0.0;

	long double phi1_max = 2.0*M_PI;
	long double phi2_max = 2.0*M_PI;

	long double phi1 = 0.0;
	long double phi2 = 0.0;

	long double theta1 = 0.0;

	long double theta2 = 0.0;

	long double z1 = L_initial;
	long double z2 = L_final;

	//	cout << r1 << endl;
	//	cout << r2 << endl;
	//	cout << z1 << endl;
	//	cout << z2 << endl;

	long double r12 = 0.0;

	long double x1 = 0.0;
	long double y1 = 0.0;

	long double x2 = 0.0;
	long double y2 = 0.0;


	long double dS1 = 0.0;
	long double dS2 = 0.0;

	long double K = 0.0;

	long double angular_coefficient = 0.0;

	long int N_yes = 0;


	long double f = 0.0;

	long double f_min = 0.0;

	long double f_max = 0.0;





	long double r12_min = z2 - z1;


	long double r12_max = pow(pow(-r1_max - r2_max, 2.0) + pow(z2 - z1, 2.0), 1.0 / 2.0);

	long double theta_12_max = atan(fabs((-r1_max - r2_max) / (z2 - z1)));


	//	f_max = ((n_cos_intensity + 1.0) / (2.0*M_PI))*r1_max*r2_max / pow(r12_min, 2.0);

	//	f_max = ((n_cos_intensity + 1.0) / (2.0*M_PI))*r1_max*r2_max / pow(r12_min, 2.0);

	f_max = ((n_cos_intensity + 1.0) / (2.0*M_PI))*r1_max*r2_max / pow(r12_min, 2.0);


	//	((n_cos_intensity + 1.0) / (2.0*M_PI))*pow(cos(theta_12_max),n_cos_intensity)*pow(cos(theta_12_max),,n_cos_intensity)*r1_min*r2_min / pow(r12_max, 2.0);

	//	((n_cos_intensity + 1.0) / (2.0*M_PI))*cos(theta_12_max)*cos(theta_12_max)*r1_min*r2_min / pow(r12_max, 2.0);

	f_min = ((n_cos_intensity + 1.0) / (2.0*M_PI))*pow(cos(theta_12_max), n_cos_intensity)*cos(theta_12_max)*r1_min*r2_min / pow(r12_max, 2.0);

	//cout << f_min << endl;

	//cout << f_max<<endl;

	f_min = 0.0;

	long double ksi1 = 0.0;
	long double ksi2 = 0.0;
	long double ksi3 = 0.0;
	long double ksi4 = 0.0;
	long double ksi5 = 0.0;


#pragma omp  parallel for 

	//#pragma omp  parallel for shared(N_yes)

	//#pragma omp  parallel for  schedule(static) ordered

	//#pragma omp  parallel for  schedule(dynamic) ordered



	for (long int i = 0; i < N_monte_carlo; i = i + 1) {

		//#pragma omp ordered	


		ksi1 = random(0.0, 1.0);
		ksi2 = random(0.0, 1.0);
		ksi3 = random(0.0, 1.0);
		ksi4 = random(0.0, 1.0);
		ksi5 = random(0.0, 1.0);

		phi1 = phi1_min + (phi1_max - phi1_min)*ksi1;
		phi2 = phi2_min + (phi2_max - phi2_min)*ksi2;
		r1 = r1_min + (r1_max - r1_min)*ksi3;
		r2 = r2_min + (r2_max - r2_min)*ksi4;
		f = f_min + (f_max - f_min)*ksi5;


		x1 = r1 * cos(phi1);
		y1 = r1 * sin(phi1);

		x2 = r2 * cos(phi2);
		y2 = r2 * sin(phi2);

		r12 = pow(pow(x2 - x1, 2.0) + pow(y2 - y1, 2.0) + pow(z2 - z1, 2.0), 1.0 / 2.0);

		theta1 = acos(fabs(z2 - z1) / r12);
		theta2 = acos(fabs(z2 - z1) / r12); //-V656




		//	K = ((n_cos_intensity + 1.0) / (2.0*M_PI))*pow(cos(theta1), n_cos_intensity)*pow(cos(theta2), n_cos_intensity) / pow(r12, 2.0);

		//	K = ((n_cos_intensity + 1.0) / (2.0*M_PI))*cos(theta1)*cos(theta2) / pow(r12, 2.0);

		K = ((n_cos_intensity + 1.0) / (2.0*M_PI))*pow(cos(theta1), n_cos_intensity)*cos(theta2)*r1*r2 / pow(r12, 2.0);

		if (f < K) {
#pragma omp atomic
			//	N_yes = N_yes + 1;
			N_yes++;

		}


	}



	long double S = 0.0;

	S = (r1_max - r1_min)*(phi1_max - phi1_min)*(r2_max - r2_min)*(phi2_max - phi2_min)*(f_max - f_min);


	angular_coefficient = S * N_yes / N_monte_carlo;

	long double S1 = M_PI * (pow(R2_initial, 2.0) - pow(R3_initial, 2.0));

	long double S2 = M_PI * (pow(R2_final, 2.0) - pow(R3_final, 2.0));

	angular_coefficient = angular_coefficient / S1;

	return angular_coefficient;

}






void out_txt(const char *filename, long double **mass_histo_x, long double **mass_histo_r, unsigned int start_time, unsigned int end_time, long double  R1_1, long double R2_1, long double R3_1, long double L_1, long double V_0, long double  R1_2, long double R2_2,
	long double R3_2, long double L_2, long double R1_3, long double R2_3, long double R3_3, long double L_3, long double R1_4, long double R2_4, long double R3_4, long double L_4, long double R1_5, long double R2_5, long double R3_5, long double L_5, long double R1_6, long double R2_6, long double R3_6, long double L_6, long double R1_7, long double R2_7, long double R3_7, long double L_7, long double R1_8, long double R2_8, long double R3_8, int  N, std::size_t N_histo, long double R, long double b1_left, long double b1_surface,
	long double b1_right, long double b2_left, long double b2_surface, long double b2_right, long double b3_left, long double b3_surface, long double b3_right, long double b4_left, long double b4_surface, long double b4_right, long double b5_left, long double b5_surface, long double b5_right, long double b6_left, long double b6_surface, long double b6_right, long double b7_left, long double b7_surface, long double b7_right, std::size_t N_on, std::size_t N_off, std::size_t N1_1, std::size_t N2_1, std::size_t N3_1, std::size_t N4_1, std::size_t N5_1, std::size_t N6_1,
	std::size_t N7_1, std::size_t N1_2, std::size_t N2_2, std::size_t N3_2, std::size_t N4_2, std::size_t N5_2, std::size_t N6_2, std::size_t N7_2, std::size_t N1_3, std::size_t N2_3, std::size_t N3_3, std::size_t N4_3, std::size_t N5_3, std::size_t N6_3, std::size_t N7_3, std::size_t N1_4, std::size_t N2_4, std::size_t N3_4, std::size_t N4_4, std::size_t N5_4, std::size_t N6_4, std::size_t N7_4, std::size_t N1_5, std::size_t N2_5, std::size_t N3_5, std::size_t N4_5, std::size_t N5_5, std::size_t N6_5, std::size_t N7_5, std::size_t N1_6, std::size_t N2_6, std::size_t N3_6, std::size_t N4_6, std::size_t N5_6, std::size_t N6_6, std::size_t N7_6, std::size_t N1_7, std::size_t N2_7, std::size_t N3_7, std::size_t N4_7, std::size_t N5_7, std::size_t N6_7, std::size_t N7_7, std::size_t n1, std::size_t n2, std::size_t n3, std::size_t n4, std::size_t n5, std::size_t n6, std::size_t n7, std::size_t n_travel, long double t, long double theta1_diffusion_left,
	long double theta1_diffusion_surface, long double theta1_diffusion_right, long double theta2_diffusion_left, long double theta2_diffusion_surface, long double theta2_diffusion_right, long double theta3_diffusion_left, long double theta3_diffusion_surface,
	long double theta3_diffusion_right, long double theta4_diffusion_left, long double theta4_diffusion_surface, long double theta4_diffusion_right, long double theta5_diffusion_left, long double theta5_diffusion_surface, long double theta5_diffusion_right, long double theta6_diffusion_left, long double theta6_diffusion_surface, long double theta6_diffusion_right, long double theta7_diffusion_left, long double theta7_diffusion_surface, long double theta7_diffusion_right, long double R_source, std::size_t N_histo_source, std::size_t normalization_x, std::size_t normalization_r, long double x_0_source, long double z0_mag1, long double L_mag1, long double z0_mag2, long double L_mag2, long double z0_mag3, long double L_mag3, long double z0_mag4, long double L_mag4, long double z0_mag5, long double L_mag5, long double z0_mag6, long double L_mag6, long double z0_mag7, long double L_mag7,
	long double B1_max, long double B2_max, long double B3_max, long double B4_max, long double B5_max, long double B6_max, long double B7_max, long double r1_mag_max_initial, long double r2_mag_max_initial, long double r3_mag_max_initial, long double r4_mag_max_initial, long double r5_mag_max_initial, long double r6_mag_max_initial, long double r7_mag_max_initial, long double mu_particle, long double m_particle, bool on_off_mag_1, bool on_off_mag_2, bool on_off_mag_3, bool on_off_mag_4, bool on_off_mag_5, bool on_off_mag_6, bool on_off_mag_7, long double B_critical,
	long double mu_electron_particle, long double J_particle, long double I_particle, long double mu_core_particle, long double m_J, long double m_F, long double r1_mag_max_final, long double r2_mag_max_final, long double r3_mag_max_final, long double r4_mag_max_final, long double r5_mag_max_final, long double r6_mag_max_final, long double r7_mag_max_final, size_t N_mag_partitions,
	int particle_mode, long double temp_beam, bool flaq_Maxwell, long double a_V_0, long double b_V_0, std::size_t N_histo_V_0, std::size_t N_histo_theta_in, bool flaq_Maxwell_mode, bool average_peak, std::size_t n_mag_1_in, std::size_t n_mag_1_absorption, std::size_t n_mag_1_out, std::size_t n_mag_2_in, std::size_t n_mag_2_absorption, std::size_t n_mag_2_out, std::size_t n_mag_3_in, std::size_t n_mag_3_absorption, std::size_t n_mag_3_out, std::size_t n_mag_4_in, std::size_t n_mag_4_absorption, std::size_t n_mag_4_out, std::size_t n_mag_5_in, std::size_t n_mag_5_absorption, std::size_t n_mag_5_out, std::size_t n_mag_6_in, std::size_t n_mag_6_absorption, std::size_t n_mag_6_out, std::size_t n_mag_7_in, std::size_t n_mag_7_absorption, std::size_t n_mag_7_out,
	std::size_t n_tube_y0_x0, long double phi_1_2, bool flaq_angular_coefficient, size_t N_CYL_partitions, size_t N_r_angular, size_t N_phi_angular, long double n_cos_intensity) {


	printf("Вывод пространственного распределения\n");
	printf("\n");

	long double temp = 0.0;

	if (average_peak == true) {

		size_t len = arrlen(mass_histo_x);

		for (size_t i = 0; i < (len / 2); i++) {

			temp = (mass_histo_x[i][0] + mass_histo_x[len - 1 - i][0]) / 2.0;
			// огругление до целого в большую сторону
			mass_histo_x[i][0] = ceil(temp);
			mass_histo_x[len - 1 - i][0] = ceil(temp);

		}

	}



	// вывод полученных результатов в файл
	FILE *fd;

	fopen_s(&fd, filename, "wb");

	if (fd == NULL) {
		fprintf(stderr, "Ошибка открытия выводного файла.\n");
		cout << endl;
		SleepEx(40, true); // пауза для того, чтобы успеть прочитать информацию
		exit(1);
	}
	else {
		setlocale(LC_ALL, "rus"); // корректное отображение Кириллицы

		fprintf(fd, "\n");
		fprintf(fd, "### \n");
		fprintf(fd, "### Число Частиц в Бине штук || Нормированное Значение || Координата X Левого Конца Бина мм || Число Частиц в Бине штук || Нормированное Значение || Координата R Левого Конца Бина мм \n");
		fprintf(fd, "### \n");
		fprintf(fd, "\n");

		int summ = 0; // переменная для подсчита сколько всего чатиц попало в круг определенного радиуса


		setlocale(LC_ALL, "C"); // установить используемую системой локаль для корректной отображении точки в выходном файле

		for (size_t i = 0; i < arrlen(mass_histo_x); i++) {

			if (i < arrlen(mass_histo_r)) {

				summ = summ + (int)mass_histo_r[i][0];

				if ((normalization_x == 0) || (normalization_r == 0)) {// исключение надписи nan(ind)
					fprintf(fd, "%.0Lf %.5Le %Lf %.0Lf %.5Le %Lf %.0Lf\n", mass_histo_x[i][0], 0.0, mass_histo_x[i][1], mass_histo_r[i][0], 0.0, mass_histo_r[i][1], (long double)summ);
				}
				else {
					fprintf(fd, "%.0Lf %.5Le %Lf %.0Lf %.5Le %Lf %.0Lf\n", mass_histo_x[i][0], (mass_histo_x[i][0] / normalization_x), mass_histo_x[i][1], mass_histo_r[i][0], (mass_histo_r[i][0] / normalization_r), mass_histo_r[i][1], (long double)summ);

				}


			}

			else {

				if ((normalization_x == 0) || (normalization_r == 0)) {// исключение надписи nan(ind)
					fprintf(fd, "%.0Lf %.5Le %Lf %.0Lf %.5Le %Lf %.0Lf\n", mass_histo_x[i][0], 0.0, mass_histo_x[i][1], 0.0, 0.0, 0.0, 0.0);
				}
				else {
					fprintf(fd, "%.0Lf %.5Le %Lf %.0Lf %.5Le %Lf %.0Lf\n", mass_histo_x[i][0], (long double)(mass_histo_x[i][0] / normalization_x), mass_histo_x[i][1], 0.0, 0.0, 0.0, 0.0);

				}
			}

		}


		//long double phi_1_2_new = (1.0 / (2.0*pow(R2_1, 2.0)))*(pow(L_1, 2.0) + pow(R2_1, 2.0) + pow(R2_2, 2.0) - pow(pow(pow(L_1, 2.0) + pow(R2_1, 2.0) + pow(R2_2, 2.0), 2.0) - 4.0*pow(R2_1*R2_2, 2.0), 1.0 / 2.0)) - (1.0 / (2.0*pow(R3_1, 2.0)))*(pow(L_1, 2.0) + pow(R3_1, 2.0) + pow(R3_2, 2.0) - pow(pow(pow(L_1, 2.0) + pow(R3_1, 2.0) + pow(R3_2, 2.0), 2.0) - 4.0*pow(R3_1*R3_2, 2.0), 1.0 / 2.0));
		/*



		long double	r1 = max(R2_1, R2_2);
		long double r2 = max(R3_1, R3_2);
		long double r3 = max(R2_1, R3_2);
		long double r4 = max(R2_2, R3_1);



		long double phi_1_2_new_1 = (1.0 / (2.0*pow(r1, 2.0)))*(pow(L_1, 2.0) + pow(R2_1, 2.0) + pow(R2_2, 2.0) - pow(pow(pow(L_1, 2.0) + pow(R2_1, 2.0) + pow(R2_2, 2.0), 2.0) - 4.0*pow(R2_1*R2_2, 2.0), 1.0 / 2.0));
		long double phi_1_2_new_2 = (1.0 / (2.0*pow(r2, 2.0)))*(pow(L_1, 2.0) + pow(R3_1, 2.0) + pow(R3_2, 2.0) - pow(pow(pow(L_1, 2.0) + pow(R3_1, 2.0) + pow(R3_2, 2.0), 2.0) - 4.0*pow(R3_1*R3_2, 2.0), 1.0 / 2.0));
		long double phi_1_2_new_3 = (1.0 / (2.0*pow(r3, 2.0)))*(pow(L_1, 2.0) + pow(R2_1, 2.0) + pow(R3_2, 2.0) - pow(pow(pow(L_1, 2.0) + pow(R2_1, 2.0) + pow(R3_2, 2.0), 2.0) - 4.0*pow(R2_1*R3_2, 2.0), 1.0 / 2.0));
		long double phi_1_2_new_4 = (1.0 / (2.0*pow(r4, 2.0)))*(pow(L_1, 2.0) + pow(R2_2, 2.0) + pow(R3_1, 2.0) - pow(pow(pow(L_1, 2.0) + pow(R2_2, 2.0) + pow(R3_1, 2.0), 2.0) - 4.0*pow(R2_2*R3_1, 2.0), 1.0 / 2.0));

		long double phi_1_2_new = phi_1_2_new_1 + phi_1_2_new_2 - phi_1_2_new_3 - phi_1_2_new_4;
		*/

		long double	r1 = max(R2_1, R2_2);
		long double r2 = max(R3_1, R3_2);
		long double r3 = max(R2_1, R3_2);
		long double r4 = max(R2_2, R3_1);


		//long double phi_1_2_new = (1.0 / (2.0*pow(r1, 2.0)))*(pow(L_1, 2.0) + pow(R2_1, 2.0) + pow(R2_2, 2.0) - pow(pow(pow(L_1, 2.0) + pow(R2_1, 2.0) + pow(R2_2, 2.0), 2.0) - 4.0*pow(R2_1*R2_2, 2.0), 1.0 / 2.0)) - (1.0 / (2.0*pow(r2, 2.0)))*(pow(L_1, 2.0) + pow(R3_1, 2.0) + pow(R3_2, 2.0) - pow(pow(pow(L_1, 2.0) + pow(R3_1, 2.0) + pow(R3_2, 2.0), 2.0) - 4.0*pow(R3_1*R3_2, 2.0), 1.0 / 2.0));

		//long double phi_1_2_new_1 = (1.0 / (2.0*pow(r1, 2.0)))*(pow(L_1, 2.0) + pow(R2_1, 2.0) + pow(R2_2, 2.0) - pow(pow(pow(L_1, 2.0) + pow(R2_1, 2.0) + pow(R2_2, 2.0), 2.0) - 4.0*pow(R2_1*R2_2, 2.0), 1.0 / 2.0));
		//long double phi_1_2_new_2 = (1.0 / (2.0*pow(r2, 2.0)))*(pow(L_1, 2.0) + pow(R3_1, 2.0) + pow(R3_2, 2.0) - pow(pow(pow(L_1, 2.0) + pow(R3_1, 2.0) + pow(R3_2, 2.0), 2.0) - 4.0*pow(R3_1*R3_2, 2.0), 1.0 / 2.0));
		//long double phi_1_2_new_3 = (1.0 / (2.0*pow(r3, 2.0)))*(pow(L_1, 2.0) + pow(R2_1, 2.0) + pow(R3_2, 2.0) - pow(pow(pow(L_1, 2.0) + pow(R2_1, 2.0) + pow(R3_2, 2.0), 2.0) - 4.0*pow(R2_1*R3_2, 2.0), 1.0 / 2.0));
		//long double phi_1_2_new_4 = (1.0 / (2.0*pow(r4, 2.0)))*(pow(L_1, 2.0) + pow(R2_2, 2.0) + pow(R3_1, 2.0) - pow(pow(pow(L_1, 2.0) + pow(R2_2, 2.0) + pow(R3_1, 2.0), 2.0) - 4.0*pow(R2_2*R3_1, 2.0), 1.0 / 2.0));


		long double phi_12_34 = (1.0 / (2.0*pow(R2_1, 2.0)))*(pow(L_1, 2.0) + pow(R2_1, 2.0) + pow(R2_2, 2.0) - pow(pow(pow(L_1, 2.0) + pow(R2_1, 2.0) + pow(R2_2, 2.0), 2.0) - 4.0*pow(R2_1*R2_2, 2.0), 1.0 / 2.0));
		long double phi_12_4 = (1.0 / (2.0*pow(R2_1, 2.0)))*(pow(L_1, 2.0) + pow(R2_1, 2.0) + pow(R3_2, 2.0) - pow(pow(pow(L_1, 2.0) + pow(R2_1, 2.0) + pow(R3_2, 2.0), 2.0) - 4.0*pow(R2_1*R3_2, 2.0), 1.0 / 2.0));
		long double phi_1_34 = (1.0 / (2.0*pow(R3_1, 2.0)))*(pow(L_1, 2.0) + pow(R3_1, 2.0) + pow(R2_2, 2.0) - pow(pow(pow(L_1, 2.0) + pow(R3_1, 2.0) + pow(R2_2, 2.0), 2.0) - 4.0*pow(R3_1*R2_2, 2.0), 1.0 / 2.0));
		long double phi_1_4 = (1.0 / (2.0*pow(R3_1, 2.0)))*(pow(L_1, 2.0) + pow(R3_1, 2.0) + pow(R3_2, 2.0) - pow(pow(pow(L_1, 2.0) + pow(R3_1, 2.0) + pow(R3_2, 2.0), 2.0) - 4.0*pow(R3_1*R3_2, 2.0), 1.0 / 2.0));



		//long double k1 = 0.0, k2=0.0,k3=0.0,k4=0.0 ;

		//long double phi_1_2_new = k1*phi_1_2_new_1 + *k2*phi_1_2_new_2 - k3*phi_1_2_new_3 - k4*phi_1_2_new_4;

		//long double phi_1_2_new = phi_1_2_new_1 + phi_1_2_new_2 - phi_1_2_new_3 - phi_1_2_new_4;


		long double phi_1_2_new = 0.0;

		//long double phi_1_2_new = (pow(R2_1, 2.0) / (pow(R2_1, 2.0) - pow(R3_1, 2.0)))*(phi_12_34 - phi_12_4) - (pow(R3_1, 2.0) / (pow(R2_1, 2.0) - pow(R3_1, 2.0)))*(phi_1_34 - phi_1_4);

		//long double phi_1_2_new_1 = (1.0 / (2.0*pow(r1, 2.0)))*(pow(L_1, 2.0) + pow(R2_1, 2.0) + pow(R2_2, 2.0) - pow(pow(pow(L_1, 2.0) + pow(R2_1, 2.0) + pow(R2_2, 2.0), 2.0) - 4.0*pow(R2_1*R2_2, 2.0), 1.0 / 2.0)) - (1.0 / (2.0*pow(r1, 2.0)))*(pow(L_1, 2.0) + pow(R2_1, 2.0) + pow(R3_2, 2.0) - pow(pow(pow(L_1, 2.0) + pow(R2_1, 2.0) + pow(R3_2, 2.0), 2.0) - 4.0*pow(R2_1*R3_2, 2.0), 1.0 / 2.0))-(1.0 / (2.0*pow(r2, 2.0)))*(pow(L_1, 2.0) + pow(R2_2, 2.0) + pow(R3_1, 2.0) - pow(pow(pow(L_1, 2.0) + pow(R2_2, 2.0) + pow(R3_1, 2.0), 2.0) - 4.0*pow(R2_2*R3_1, 2.0), 1.0 / 2.0)) - (1.0 / (2.0*pow(R2_1, 2.0)))*(pow(L_1, 2.0) + pow(R2_1, 2.0) + pow(R2_2, 2.0) - pow(pow(pow(L_1, 2.0) + pow(R2_1, 2.0) + pow(R2_2, 2.0), 2.0) - 4.0*pow(R2_1*R2_2, 2.0), 1.0 / 2.0));

		/*


		if (n_cos_intensity = 1.0) {

			phi_1_2_new = (pow(R2_1, 2.0) / (pow(R2_1, 2.0) - pow(R3_1, 2.0)))*(phi_12_34 - phi_12_4) - (pow(R3_1, 2.0) / (pow(R2_1, 2.0) - pow(R3_1, 2.0)))*(phi_1_34 - phi_1_4);

		}
		else {

			phi_1_2_new = angular_coefficient_calculation(0.0, L_1, R1_1, R2_1, R3_1, R1_2, R2_2, R3_2, N_r_angular, N_phi_angular, n_cos_intensity);
		}
		 */

		 //phi_1_2 = phi_1_2_new;

		setlocale(LC_ALL, "rus"); // корректное отображение Кириллицы

		fprintf(fd, "\n");
		fprintf(fd, "### \n");
		fprintf(fd, "### Скорость = %.2Lf мм/сек. Число Частиц = %.4Le штук Число Бинов = %.0Lf штук Максимальное время счета = %.2Lf (мин.)\n", V_0, (long double)N, (long double)N_histo, t);
		fprintf(fd, "### R1_1=%.1Lf мм R2_1=%.1Lf мм R3_1=%.1Lf мм L_1=%.1Lf мм\n", R1_1, R2_1, R3_1, L_1);
		fprintf(fd, "### Метод угловых коэффициентов для цилиндров №№ 1-2 = %s\n", (flaq_angular_coefficient ? "Включено" : "Отключено"));

		fprintf(fd, "### Интегральный угловой коэффициент для цилиндров №№ 1-2 = %.4Le 1/(число частиц вышло из цилиндра № 1)\n", phi_1_2);


		fprintf(fd, "### R1_2=%.1Lf мм R2_2=%.1Lf мм R3_2=%.1Lf мм L_2=%.1Lf мм\n", R1_2, R2_2, R3_2, L_2);
		fprintf(fd, "### R1_3=%.1Lf мм R2_3=%.1Lf мм R3_3=%.1Lf мм L_3=%.1Lf мм\n", R1_3, R2_3, R3_3, L_3);
		fprintf(fd, "### R1_4=%.1Lf мм R2_4=%.1Lf мм R3_4=%.1Lf мм L_4=%.1Lf мм\n", R1_4, R2_4, R3_4, L_4);
		fprintf(fd, "### R1_5=%.1Lf мм R2_5=%.1Lf мм R3_5=%.1Lf мм L_5=%.1Lf мм\n", R1_5, R2_5, R3_5, L_5);
		fprintf(fd, "### R1_6=%.1Lf мм R2_6=%.1Lf мм R3_6=%.1Lf мм L_6=%.1Lf мм\n", R1_6, R2_6, R3_6, L_6);
		fprintf(fd, "### R1_7=%.1Lf мм R2_7=%.1Lf мм R3_7=%.1Lf мм L_7=%.1Lf мм\n", R1_7, R2_7, R3_7, L_7);
		fprintf(fd, "### R1_8=%.1Lf мм R2_8=%.1Lf мм R3_8=%.1Lf мм L_8=%.1Lf мм\n", R1_8, R2_8, R3_8, L_7);
		
		fprintf(fd, "### \n");

		fprintf(fd, "### Максимальный радиус экрана = %.2Lf мм\n", R);
		fprintf(fd, "### Усреднение по двум полуплоскостям на экране = %s\n", (average_peak ? "Включено" : "Отключено"));
		fprintf(fd, "### Радиус кольца детектора = %.2Lf мм\n", R_source);
		fprintf(fd, "### Координата x_0 детектора = %.2Lf мм\n", x_0_source);
		fprintf(fd, "### Число точек, измеренных детектором = %.0Lf штук\n", (long double)N_histo_source);
		fprintf(fd, "### \n");

		fprintf(fd, "### Расстояние магнита от левого_торца цилиндра (первый цилиндр) = %.2Lf мм\n", z0_mag1);
		fprintf(fd, "### Длина магнита (первый цилиндр) = %.2Lf мм\n", L_mag1);
		fprintf(fd, "### Максимальное магнитное поле (первый цилиндр) = %.2Lf Гс\n", B1_max);
		fprintf(fd, "### Максимальный начальный радиус магнита (первый цилиндр) = %.2Lf мм\n", r1_mag_max_initial);
		fprintf(fd, "### Максимальный конечный радиус магнита (первый цилиндр) = %.2Lf мм\n", r1_mag_max_final);
		fprintf(fd, "### Наличие магнита (первый цилиндр) = %s\n", (on_off_mag_1 ? "Да" : "Нет"));
		fprintf(fd, "### \n");

		fprintf(fd, "### Расстояние магнита от левого_торца цилиндра (второй цилиндр) = %.2Lf мм\n", z0_mag2);
		fprintf(fd, "### Длина магнита (второй цилиндр) = %.2Lf мм\n", L_mag2);
		fprintf(fd, "### Максимальное магнитное поле (второй цилиндр) = %.2Lf Гс\n", B2_max);
		fprintf(fd, "### Максимальный начальный радиус магнита (второй цилиндр) = %.2Lf мм\n", r2_mag_max_initial);
		fprintf(fd, "### Максимальный конечный радиус магнита (второй цилиндр) = %.2Lf мм\n", r2_mag_max_final);
		fprintf(fd, "### Наличие магнита (второй цилиндр) = %s\n", (on_off_mag_2 ? "Да" : "Нет"));
		fprintf(fd, "### \n");

		fprintf(fd, "### Расстояние магнита от левого_торца цилиндра (третий цилиндр) = %.2Lf мм\n", z0_mag3);
		fprintf(fd, "### Длина магнита (третий цилиндр) = %.2Lf мм\n", L_mag3);
		fprintf(fd, "### Максимальное магнитное поле (третий цилиндр) = %.2Lf Гс\n", B3_max);
		fprintf(fd, "### Максимальный начальный радиус магнита (третий цилиндр) = %.2Lf мм\n", r3_mag_max_initial);
		fprintf(fd, "### Максимальный конечный радиус магнита (третий цилиндр) = %.2Lf мм\n", r3_mag_max_final);
		fprintf(fd, "### Наличие магнита (третий цилиндр) = %s\n", (on_off_mag_3 ? "Да" : "Нет"));



		fprintf(fd, "### Расстояние магнита от левого_торца цилиндра (четвертый цилиндр) = %.2Lf мм\n", z0_mag4);
		fprintf(fd, "### Длина магнита (четвертый цилиндр) = %.2Lf мм\n", L_mag4);
		fprintf(fd, "### Максимальное магнитное поле (четвертый цилиндр) = %.2Lf Гс\n", B4_max);
		fprintf(fd, "### Максимальный начальный радиус магнита (четвертый цилиндр) = %.2Lf мм\n", r4_mag_max_initial);
		fprintf(fd, "### Максимальный конечный радиус магнита (четвертый цилиндр) = %.2Lf мм\n", r4_mag_max_final);
		fprintf(fd, "### Наличие магнита (четвертый цилиндр) = %s\n", (on_off_mag_4 ? "Да" : "Нет"));


		fprintf(fd, "### Расстояние магнита от левого_торца цилиндра (пятый цилиндр) = %.2Lf мм\n", z0_mag5);
		fprintf(fd, "### Длина магнита (пятый цилиндр) = %.2Lf мм\n", L_mag5);
		fprintf(fd, "### Максимальное магнитное поле (пятый цилиндр) = %.2Lf Гс\n", B5_max);
		fprintf(fd, "### Максимальный начальный радиус магнита (пятый цилиндр) = %.2Lf мм\n", r5_mag_max_initial);
		fprintf(fd, "### Максимальный конечный радиус магнита (пятый цилиндр) = %.2Lf мм\n", r5_mag_max_final);
		fprintf(fd, "### Наличие магнита (пятый цилиндр) = %s\n", (on_off_mag_5 ? "Да" : "Нет"));

	  
		fprintf(fd, "### Расстояние магнита от левого_торца цилиндра (шестой цилиндр) = %.2Lf мм\n", z0_mag6);
		fprintf(fd, "### Длина магнита (шестой цилиндр) = %.2Lf мм\n", L_mag6);
		fprintf(fd, "### Максимальное магнитное поле (шестой цилиндр) = %.2Lf Гс\n", B6_max);
		fprintf(fd, "### Максимальный начальный радиус магнита (шестой цилиндр) = %.2Lf мм\n", r6_mag_max_initial);
		fprintf(fd, "### Максимальный конечный радиус магнита (шестой цилиндр) = %.2Lf мм\n", r6_mag_max_final);
		fprintf(fd, "### Наличие магнита (шестой цилиндр) = %s\n", (on_off_mag_6 ? "Да" : "Нет"));


		fprintf(fd, "### Расстояние магнита от левого_торца цилиндра (седьмой цилиндр) = %.2Lf мм\n", z0_mag7);
		fprintf(fd, "### Длина магнита (седьмой цилиндр) = %.2Lf мм\n", L_mag7);
		fprintf(fd, "### Максимальное магнитное поле (седьмой цилиндр) = %.2Lf Гс\n", B7_max);
		fprintf(fd, "### Максимальный начальный радиус магнита (седьмой цилиндр) = %.2Lf мм\n", r7_mag_max_initial);
		fprintf(fd, "### Максимальный конечный радиус магнита (седьмой цилиндр) = %.2Lf мм\n", r7_mag_max_final);
		fprintf(fd, "### Наличие магнита (седьмой цилиндр) = %s\n", (on_off_mag_7 ? "Да" : "Нет"));




		fprintf(fd, "### \n");
		fprintf(fd, "### Магнитный момент ядра частицы g_I = %.9Le\n", mu_core_particle);
		fprintf(fd, "### Магнитный момент электронной оболочки частицы g_J = %.9Le\n", mu_electron_particle);
		fprintf(fd, "### Масса частицы m = %.9Le МэВ\n", m_particle);
		fprintf(fd, "### Спин ядра частицы I= %.9Le\n", I_particle);
		fprintf(fd, "### Момент электронной оболочки частицы J=L+S = %.9Le\n", J_particle);
		fprintf(fd, "### Проекция момента электронной оболочки частицы m_J = %.9Le\n", m_J);
		fprintf(fd, "### Критическое поле частицы B_critical = %.9Le Гс\n", B_critical);
		fprintf(fd, "### Проекция полного момента F=I+J частицы m_F = %.9Le\n", m_F);
		fprintf(fd, "### Число разбиений магнита = %.0Lf штук\n", (long double)N_mag_partitions);
		fprintf(fd, "### Температура пучка частиц = %.3Lf  Кельвинов\n", temp_beam);
		fprintf(fd, "### Распределение по модулю скорости = %s\n", (flaq_Maxwell ? "Дельта функция" : "Распределение Максвелла по модулю скорости"));
		fprintf(fd, "### Режим распределения Максвелла = %s\n", (flaq_Maxwell_mode ? "Распределение Максвелла для пучка" : "Обычнное по модулю скорости"));
		fprintf(fd, "### Левая граница для распределения по модулю скорости  = %.9Le мм/сек\n", a_V_0);
		fprintf(fd, "### Певая граница для распределения по модулю скорости  = %.9Le мм/сек\n", b_V_0);
		fprintf(fd, "### Число точек гистограммы распределения по модулю скорости  = %.9Le точек\n", (long double)N_histo_V_0);
		fprintf(fd, "### Число точек гистограммы распределения по углу theta частиц, вылетающих из кольца источника  = %.9Le точек\n", (long double)N_histo_theta_in);



		if (particle_mode == 0) {
			fprintf(fd, "### Режим частиц = ручной ввод состояния (particle mode = %.0Lf)\n", (long double)particle_mode);
		}
		else if (particle_mode == 1) {

			fprintf(fd, "### Режим частиц = режим водорода (случайное выбирание подсостояния из возможных для водорода) (particle mode = %.0Lf)\n", (long double)particle_mode);

		}
		else if (particle_mode == 2) {

			fprintf(fd, "### Режим частиц = режим дейтерия (случайное выбирание подсостояния из возможных для дейтерия) (particle mode = %.0Lf)\n", (long double)particle_mode);
		}
		else {

			fprintf(fd, "### Введено неправильное значение particle mode, введите значение 0,1 или 2 (Вы ввели particle mode = %.0Lf)\n", (long double)particle_mode);

		}








		fprintf(fd, "### \n");
		
		
		fprintf(fd, "### (Цилиндр №1) Коэфф.Захвата Левого торца = %.2Lf Коэфф.Захвата Поверхности Образующей = %.2Lf Коэфф.Захвата Правого торца = %.2Lf\n", b1_left, b1_surface, b1_right);
		fprintf(fd, "### (Цилиндр №2) Коэфф.Захвата Левого торца = %.2Lf Коэфф.Захвата Поверхности Образующей = %.2Lf Коэфф.Захвата Правого торца = %.2Lf\n", b2_left, b2_surface, b2_right);
		fprintf(fd, "### (Цилиндр №3) Коэфф.Захвата Левого торца = %.2Lf Коэфф.Захвата Поверхности Образующей = %.2Lf Коэфф.Захвата Правого торца = %.2Lf\n", b3_left, b3_surface, b3_right);
		fprintf(fd, "### (Цилиндр №4) Коэфф.Захвата Левого торца = %.2Lf Коэфф.Захвата Поверхности Образующей = %.2Lf Коэфф.Захвата Правого торца = %.2Lf\n", b4_left, b4_surface, b4_right);
		fprintf(fd, "### (Цилиндр №5) Коэфф.Захвата Левого торца = %.2Lf Коэфф.Захвата Поверхности Образующей = %.2Lf Коэфф.Захвата Правого торца = %.2Lf\n", b5_left, b5_surface, b5_right);
		fprintf(fd, "### (Цилиндр №6) Коэфф.Захвата Левого торца = %.2Lf Коэфф.Захвата Поверхности Образующей = %.2Lf Коэфф.Захвата Правого торца = %.2Lf\n", b6_left, b6_surface, b6_right);
		fprintf(fd, "### (Цилиндр №7) Коэфф.Захвата Левого торца = %.2Lf Коэфф.Захвата Поверхности Образующей = %.2Lf Коэфф.Захвата Правого торца = %.2Lf\n", b7_left, b7_surface, b7_right);

		
		fprintf(fd, "### \n");
		
		
		fprintf(fd, "### (Цилиндр №1) Дифф. Угол Левого торца = %.2Lf Дифф. Угол Поверхности Образующей = %.2Lf Дифф. Угол Правого торца = %.2Lf\n", theta1_diffusion_left, theta1_diffusion_surface, theta1_diffusion_right);
		fprintf(fd, "### (Цилиндр №2) Дифф. Угол Левого торца = %.2Lf Дифф. Угол Поверхности Образующей = %.2Lf Дифф. Угол Правого торца = %.2Lf\n", theta2_diffusion_left, theta2_diffusion_surface, theta2_diffusion_right);
		fprintf(fd, "### (Цилиндр №3) Дифф. Угол Левого торца = %.2Lf Дифф. Угол Поверхности Образующей = %.2Lf Дифф. Угол Правого торца = %.2Lf\n", theta3_diffusion_left, theta3_diffusion_surface, theta3_diffusion_right);
		fprintf(fd, "### (Цилиндр №4) Дифф. Угол Левого торца = %.2Lf Дифф. Угол Поверхности Образующей = %.2Lf Дифф. Угол Правого торца = %.2Lf\n", theta4_diffusion_left, theta4_diffusion_surface, theta4_diffusion_right);
		fprintf(fd, "### (Цилиндр №5) Дифф. Угол Левого торца = %.2Lf Дифф. Угол Поверхности Образующей = %.2Lf Дифф. Угол Правого торца = %.2Lf\n", theta5_diffusion_left, theta5_diffusion_surface, theta5_diffusion_right);
		fprintf(fd, "### (Цилиндр №6) Дифф. Угол Левого торца = %.2Lf Дифф. Угол Поверхности Образующей = %.2Lf Дифф. Угол Правого торца = %.2Lf\n", theta6_diffusion_left, theta6_diffusion_surface, theta6_diffusion_right);
		fprintf(fd, "### (Цилиндр №7) Дифф. Угол Левого торца = %.2Lf Дифф. Угол Поверхности Образующей = %.2Lf Дифф. Угол Правого торца = %.2Lf\n", theta7_diffusion_left, theta7_diffusion_surface, theta7_diffusion_right);

		
		fprintf(fd, "### \n");



		fprintf(fd, "### (Цилиндр №1) Максимальное число столкновений о стенки = %.0Lf ударов\n", (long double)n1);
		fprintf(fd, "### (Цилиндр №2) Максимальное число столкновений о стенки = %.0Lf ударов\n", (long double)n2);
		fprintf(fd, "### (Цилиндр №3) Максимальное число столкновений о стенки = %.0Lf ударов\n", (long double)n3);
		fprintf(fd, "### (Цилиндр №4) Максимальное число столкновений о стенки = %.0Lf ударов\n", (long double)n4);
		fprintf(fd, "### (Цилиндр №5) Максимальное число столкновений о стенки = %.0Lf ударов\n", (long double)n5);
		fprintf(fd, "### (Цилиндр №6) Максимальное число столкновений о стенки = %.0Lf ударов\n", (long double)n6);
		fprintf(fd, "### (Цилиндр №7) Максимальное число столкновений о стенки = %.0Lf ударов\n", (long double)n7);

		fprintf(fd, "### Максимальное число переходов частицы между цилиндрами №1,2,3 = %.0Lf переходов\n", (long double)n_travel);


		fprintf(fd, "### \n");
		fprintf(fd, "### Полное число частиц брошенных в круг, описанный вокруг торца цилиндра = %.4Le штук\n", (long double)N / phi_1_2);
		fprintf(fd, "### Число частиц, которые не вышли из круга в источник = %.4Le штук\n", (long double)N_off / phi_1_2);
		fprintf(fd, "### Число частиц выпущенных из кольца источника = %.4Le штук\n", (long double)N_on / phi_1_2);
		if (flaq_angular_coefficient == false) {
			fprintf(fd, "### Полное число частиц, которые вышли из цилиндра №1 = %.4Le штук\n", (long double)N2_1);
		}
		else if (flaq_angular_coefficient == true) {
			fprintf(fd, "### Полное число частиц, которые вышли из цилиндра №1 = %.4Le штук\n", (long double)N);
		}
		fprintf(fd, "### Полное число частиц, которые вышли из цилиндра №2 = %.0Lf штук\n", (long double)N2_2);
		fprintf(fd, "### Полное число частиц, которые вышли из цилиндра №3 = %.0Lf штук\n", (long double)N2_3);
		fprintf(fd, "### Полное число частиц, которые вышли из цилиндра №4 = %.0Lf штук\n", (long double)N2_4);
		fprintf(fd, "### Полное число частиц, которые вышли из цилиндра №5 = %.0Lf штук\n", (long double)N2_5);
		fprintf(fd, "### Полное число частиц, которые вышли из цилиндра №6 = %.0Lf штук\n", (long double)N2_6);
		fprintf(fd, "### Полное число частиц, которые вышли из цилиндра №7 = %.0Lf штук\n", (long double)N2_7);
		
		
		fprintf(fd, "### \n");



		fprintf(fd, "### Число частиц, которые вернулись обратно в источник из цилиндра №1 = %.0Lf штук\n", (long double)N1_1);
		fprintf(fd, "### Число частиц, которые вернулись обратно в цилиндр №1 из цилиндра №2 = %.0Lf штук\n", (long double)N1_2);
		fprintf(fd, "### Число частиц, которые вернулись обратно в цилиндр №2 из цилиндра №3 = %.0Lf штук\n", (long double)N1_3);
		fprintf(fd, "### Число частиц, которые вернулись обратно в цилиндр №3 из цилиндра №4 = %.0Lf штук\n", (long double)N1_4);
		fprintf(fd, "### Число частиц, которые вернулись обратно в цилиндр №4 из цилиндра №5 = %.0Lf штук\n", (long double)N1_5);
		fprintf(fd, "### Число частиц, которые вернулись обратно в цилиндр №5 из цилиндра №6 = %.0Lf штук\n", (long double)N1_6);
		fprintf(fd, "### Число частиц, которые вернулись обратно в цилиндр №6 из цилиндра №7 = %.0Lf штук\n", (long double)N1_7);


		fprintf(fd, "### \n");


		if (flaq_angular_coefficient == false) {
			fprintf(fd, "### Число частиц, которые были захвачены поверхностью цилиндра №1 = %.0Lf штук\n", (long double)(N3_1 + N4_1 + N5_1));

		}
		else  if (flaq_angular_coefficient == true) {

			fprintf(fd, "### Число частиц, которые были захвачены поверхностью цилиндра №1 = %.4Le штук\n", (long double)(N_on / phi_1_2 - N_on));


		}

		fprintf(fd, "### Число частиц, которые были захвачены левым торцом поверхности цилиндра №1 = %.0Lf штук\n", (long double)N3_1);
		fprintf(fd, "### Число частиц, которые были захвачены поверхностью образующей цилиндра №1 = %.0Lf штук\n", (long double)N4_1);
		fprintf(fd, "### Число частиц, которые были захвачены правым торцом поверхности цилиндра №1 = %.0Lf штук\n", (long double)N5_1);
		fprintf(fd, "### \n");


		fprintf(fd, "### Число частиц, которые были захвачены поверхностью цилиндра №2 = %.0Lf штук\n", (long double)(N3_2 + N4_2 + N5_2));
		fprintf(fd, "### Число частиц, которые были захвачены левым торцом поверхности цилиндра №2 = %.0Lf штук\n", (long double)N3_2);
		fprintf(fd, "### Число частиц, которые были захвачены поверхностью образующей цилиндра №2 = %.0Lf штук\n", (long double)N4_2);
		fprintf(fd, "### Число частиц, которые были захвачены правым торцом поверхности цилиндра №2 = %.0Lf штук\n", (long double)N5_2);
		fprintf(fd, "### \n");


		fprintf(fd, "### Число частиц, которые были захвачены поверхностью цилиндра №3 = %.0Lf штук\n", (long double)(N3_3 + N4_3 + N5_3));
		fprintf(fd, "### Число частиц, которые были захвачены левым торцом поверхности цилиндра №3 = %.0Lf штук\n", (long double)N3_3);
		fprintf(fd, "### Число частиц, которые были захвачены поверхностью образующей цилиндра №3 = %.0Lf штук\n", (long double)N4_3);
		fprintf(fd, "### Число частиц, которые были захвачены правым торцом поверхности цилиндра №3 = %.0Lf штук\n", (long double)N5_3);
		fprintf(fd, "### \n");

		fprintf(fd, "### Число частиц, которые были захвачены поверхностью цилиндра №4 = %.0Lf штук\n", (long double)(N3_4 + N4_4 + N5_4));
		fprintf(fd, "### Число частиц, которые были захвачены левым торцом поверхности цилиндра №4 = %.0Lf штук\n", (long double)N3_4);
		fprintf(fd, "### Число частиц, которые были захвачены поверхностью образующей цилиндра №4 = %.0Lf штук\n", (long double)N4_4);
		fprintf(fd, "### Число частиц, которые были захвачены правым торцом поверхности цилиндра №4 = %.0Lf штук\n", (long double)N5_4);
		fprintf(fd, "### \n");


		fprintf(fd, "### Число частиц, которые были захвачены поверхностью цилиндра №5 = %.0Lf штук\n", (long double)(N3_5 + N4_5 + N5_5));
		fprintf(fd, "### Число частиц, которые были захвачены левым торцом поверхности цилиндра №5 = %.0Lf штук\n", (long double)N3_5);
		fprintf(fd, "### Число частиц, которые были захвачены поверхностью образующей цилиндра №5 = %.0Lf штук\n", (long double)N4_5);
		fprintf(fd, "### Число частиц, которые были захвачены правым торцом поверхности цилиндра №5 = %.0Lf штук\n", (long double)N5_5);
		fprintf(fd, "### \n");


		fprintf(fd, "### Число частиц, которые были захвачены поверхностью цилиндра №6 = %.0Lf штук\n", (long double)(N3_6 + N4_6 + N5_6));
		fprintf(fd, "### Число частиц, которые были захвачены левым торцом поверхности цилиндра №6 = %.0Lf штук\n", (long double)N3_6);
		fprintf(fd, "### Число частиц, которые были захвачены поверхностью образующей цилиндра №6 = %.0Lf штук\n", (long double)N4_6);
		fprintf(fd, "### Число частиц, которые были захвачены правым торцом поверхности цилиндра №6 = %.0Lf штук\n", (long double)N5_6);
		fprintf(fd, "### \n");



		fprintf(fd, "### Число частиц, которые были захвачены поверхностью цилиндра №7 = %.0Lf штук\n", (long double)(N3_7 + N4_7 + N5_7));
		fprintf(fd, "### Число частиц, которые были захвачены левым торцом поверхности цилиндра №7 = %.0Lf штук\n", (long double)N3_7);
		fprintf(fd, "### Число частиц, которые были захвачены поверхностью образующей цилиндра №7 = %.0Lf штук\n", (long double)N4_7);
		fprintf(fd, "### Число частиц, которые были захвачены правым торцом поверхности цилиндра №7 = %.0Lf штук\n", (long double)N5_7);
		fprintf(fd, "### \n");




		fprintf(fd, "### Полное число частиц, которые были захвачены поверхностими цилиндров №1,2,3,4,5,6,7 = %.0Lf штук\n", (long double)(N3_1 + N4_1 + N5_1 + N3_2 + N4_2 + N5_2 + N3_3 + N4_3 + N5_3 + N3_4 + N4_4 + N5_4 + N3_5 + N4_5 + N5_5 + N3_6 + N4_6 + N5_6 + N3_7 + N4_7 + N5_7));
		fprintf(fd, "### Полное число частиц, которые были захвачены левым торцом поверхности цилиндров №1,2,3,4,5,6,7 = %.0Lf штук\n", (long double)(N3_1 + N3_2 + N3_3 + N3_4 + N3_5 + N3_6 + N3_7));
		fprintf(fd, "### Полное число частиц, которые были захвачены поверхностью образующей цилиндров №1,2,3,4,5,6,7 = %.0Lf штук\n", (long double)(N4_1 + N4_2 + N4_3 + N4_4 + N4_5 + N4_6 + N4_7));
		fprintf(fd, "### Полное число частиц, которые были захвачены правым торцом поверхности цилиндров №1,2,3,4,5,6,7 = %.0Lf штук\n", (long double)(N5_1 + N5_2 + N5_3 + N5_4 + N5_5 + N5_6 + N5_7));


		fprintf(fd, "### \n");


		fprintf(fd, "### Число частиц, которые вошли в магнит №1 = %.0Lf штук\n", (long double)n_mag_1_in);
		fprintf(fd, "### Число частиц, которые поглотились магнитом №1 = %.0Lf штук\n", (long double)n_mag_1_absorption);
		fprintf(fd, "### Число частиц, которые вышли из магнита №1 = %.0Lf штук\n", (long double)n_mag_1_out);
		fprintf(fd, "### \n");

		fprintf(fd, "### Число частиц, которые вошли в магнит №2 = %.0Lf штук\n", (long double)n_mag_2_in);
		fprintf(fd, "### Число частиц, которые поглотились магнитом №2 = %.0Lf штук\n", (long double)n_mag_2_absorption);
		fprintf(fd, "### Число частиц, которые вышли из магнита №2 = %.0Lf штук\n", (long double)n_mag_2_out);
		fprintf(fd, "### \n");


		fprintf(fd, "### Число частиц, которые вошли в магнит №3 = %.0Lf штук\n", (long double)n_mag_3_in);
		fprintf(fd, "### Число частиц, которые поглотились магнитом №3 = %.0Lf штук\n", (long double)n_mag_3_absorption);
		fprintf(fd, "### Число частиц, которые вышли из магнита №3 = %.0Lf штук\n", (long double)n_mag_3_out);
		fprintf(fd, "### \n");

		fprintf(fd, "### Число частиц, которые вошли в магнит №4 = %.0Lf штук\n", (long double)n_mag_4_in);
		fprintf(fd, "### Число частиц, которые поглотились магнитом №4 = %.0Lf штук\n", (long double)n_mag_4_absorption);
		fprintf(fd, "### Число частиц, которые вышли из магнита №4 = %.0Lf штук\n", (long double)n_mag_4_out);
		fprintf(fd, "### \n");

		fprintf(fd, "### Число частиц, которые вошли в магнит №5 = %.0Lf штук\n", (long double)n_mag_5_in);
		fprintf(fd, "### Число частиц, которые поглотились магнитом №5 = %.0Lf штук\n", (long double)n_mag_5_absorption);
		fprintf(fd, "### Число частиц, которые вышли из магнита №5 = %.0Lf штук\n", (long double)n_mag_5_out);
		fprintf(fd, "### \n");

		fprintf(fd, "### Число частиц, которые вошли в магнит №6 = %.0Lf штук\n", (long double)n_mag_6_in);
		fprintf(fd, "### Число частиц, которые поглотились магнитом №6 = %.0Lf штук\n", (long double)n_mag_6_absorption);
		fprintf(fd, "### Число частиц, которые вышли из магнита №6 = %.0Lf штук\n", (long double)n_mag_6_out);
		fprintf(fd, "### \n");

		fprintf(fd, "### Число частиц, которые вошли в магнит №7 = %.0Lf штук\n", (long double)n_mag_7_in);
		fprintf(fd, "### Число частиц, которые поглотились магнитом №7 = %.0Lf штук\n", (long double)n_mag_7_absorption);
		fprintf(fd, "### Число частиц, которые вышли из магнита №7 = %.0Lf штук\n", (long double)n_mag_7_out);
		fprintf(fd, "### \n");


		fprintf(fd, "### Число частиц, которые попали в приемную трубу, расположенную в начале координат = %.0Lf штук\n", (long double)n_tube_y0_x0);
		if (flaq_angular_coefficient == true) {
			fprintf(fd, "### N_tube/N_0 = %.9Le штук\n", (long double)n_tube_y0_x0 / (N / phi_1_2));

		}
		else if (flaq_angular_coefficient == false) {

			fprintf(fd, "### N_tube/N_0 = %.9Le штук\n", (long double)n_tube_y0_x0 / N);
		}


		fprintf(fd, "### \n");


		//	fprintf(fd, "### \n");
		//	fprintf(fd, "### Число частиц, которые остались вечно саударяться со стенками цилиндра №1 = \n", n1);
		//	fprintf(fd, "### Число частиц, которые остались вечно саударяться со стенками цилиндра №2 = \n", n2);
		//	fprintf(fd, "### Число частиц, которые остались вечно саударяться со стенками цилиндра №3 = \n", n3);
		//	fprintf(fd, "### Число частиц, которые остались вечно гулять между цилиндрами №1,2,3 = \n", n_travel);

		//	fprintf(fd, "### Число частиц, которые сразу вышли из усточника и не коснулись стенок %.0Lf\n", (long double)N5);
		////	fprintf(fd, "### Число частиц, которые хотя бы раз коснулись стенок и вышли из источника %.0Lf\n", (long double)N6);
		fprintf(fd, "### \n");
		fprintf(fd, "### N_out/N_in=%.5Lf\n", ((long double)N2_3 / (long double)N_on));
		fprintf(fd, "### L_3/R_3=%.5Lf\n", ((long double)L_3 / (long double)R1_3));
		fprintf(fd, "### k=(N_out/N_in)/(L_3/R_3)=%.5Lf\n", ((long double)N2_3 / (long double)N_on) / ((long double)L_3 / (long double)R1_3));
		fprintf(fd, "### \n");


		unsigned int search_time = end_time - start_time; // искомое время в миллисекундах
		unsigned int search_time_ = search_time / (1000 * 60); // минут
		unsigned int search_time__ = (search_time / 1000) % 60; // секунд


		fprintf(fd, "### Время выполнения расчета: %.0Lf мин. и %.0Lf сек.\n", (long double)search_time_, (long double)search_time__);
		fprintf(fd, "\n");



		fclose(fd);

	}



	// удаление двумерного динамического массива гистограммы
	for (size_t count = 0; count < arrlen(mass_histo_x); count++) {
		delete[] mass_histo_x[count];
	}

	delete[] mass_histo_x;


	mass_histo_x = nullptr;

	// удаление двумерного динамического массива гистограммы
	for (size_t count = 0; count < arrlen(mass_histo_r); count++) {
		delete[] mass_histo_r[count];
	}

	delete[] mass_histo_r;


	mass_histo_r = nullptr;



}








void out_txt_P_z_P_zz(const char *filename, long double **mass_histo_x, long double **mass_histo_r, unsigned int start_time, unsigned int end_time, long double  R1_1, long double R2_1, long double R3_1, long double L_1, long double V_0, long double  R1_2, long double R2_2,
	long double R3_2, long double L_2, long double R1_3, long double R2_3, long double R3_3, long double L_3, long double R1_4, long double R2_4, long double R3_4, long double L_4, long double R1_5, long double R2_5, long double R3_5, long double L_5, long double R1_6, long double R2_6, long double R3_6, long double L_6, long double R1_7, long double R2_7, long double R3_7, long double L_7, long double R1_8, long double R2_8, long double R3_8, int  N, std::size_t N_histo, long double R, long double b1_left, long double b1_surface,
	long double b1_right, long double b2_left, long double b2_surface, long double b2_right, long double b3_left, long double b3_surface, long double b3_right, long double b4_left, long double b4_surface, long double b4_right, long double b5_left, long double b5_surface, long double b5_right, long double b6_left, long double b6_surface, long double b6_right, long double b7_left, long double b7_surface, long double b7_right, std::size_t N_on, std::size_t N_off, std::size_t N1_1, std::size_t N2_1, std::size_t N3_1, std::size_t N4_1, std::size_t N5_1, std::size_t N6_1,
	std::size_t N7_1, std::size_t N1_2, std::size_t N2_2, std::size_t N3_2, std::size_t N4_2, std::size_t N5_2, std::size_t N6_2, std::size_t N7_2, std::size_t N1_3, std::size_t N2_3, std::size_t N3_3, std::size_t N4_3, std::size_t N5_3, std::size_t N6_3, std::size_t N7_3, std::size_t N1_4, std::size_t N2_4, std::size_t N3_4, std::size_t N4_4, std::size_t N5_4, std::size_t N6_4, std::size_t N7_4, std::size_t N1_5, std::size_t N2_5, std::size_t N3_5, std::size_t N4_5, std::size_t N5_5, std::size_t N6_5, std::size_t N7_5, std::size_t N1_6, std::size_t N2_6, std::size_t N3_6, std::size_t N4_6, std::size_t N5_6, std::size_t N6_6, std::size_t N7_6, std::size_t N1_7, std::size_t N2_7, std::size_t N3_7, std::size_t N4_7, std::size_t N5_7, std::size_t N6_7, std::size_t N7_7, std::size_t n1, std::size_t n2, std::size_t n3, std::size_t n4, std::size_t n5, std::size_t n6, std::size_t n7, std::size_t n_travel, long double t, long double theta1_diffusion_left,
	long double theta1_diffusion_surface, long double theta1_diffusion_right, long double theta2_diffusion_left, long double theta2_diffusion_surface, long double theta2_diffusion_right, long double theta3_diffusion_left, long double theta3_diffusion_surface,
	long double theta3_diffusion_right, long double theta4_diffusion_left, long double theta4_diffusion_surface, long double theta4_diffusion_right, long double theta5_diffusion_left, long double theta5_diffusion_surface, long double theta5_diffusion_right, long double theta6_diffusion_left, long double theta6_diffusion_surface, long double theta6_diffusion_right, long double theta7_diffusion_left, long double theta7_diffusion_surface, long double theta7_diffusion_right, long double R_source, std::size_t N_histo_source, std::size_t normalization_x, std::size_t normalization_r, long double x_0_source, long double z0_mag1, long double L_mag1, long double z0_mag2, long double L_mag2, long double z0_mag3, long double L_mag3, long double z0_mag4, long double L_mag4, long double z0_mag5, long double L_mag5, long double z0_mag6, long double L_mag6, long double z0_mag7, long double L_mag7,
	long double B1_max, long double B2_max, long double B3_max, long double B4_max, long double B5_max, long double B6_max, long double B7_max, long double r1_mag_max_initial, long double r2_mag_max_initial, long double r3_mag_max_initial, long double r4_mag_max_initial, long double r5_mag_max_initial, long double r6_mag_max_initial, long double r7_mag_max_initial, long double mu_particle, long double m_particle, bool on_off_mag_1, bool on_off_mag_2, bool on_off_mag_3, bool on_off_mag_4, bool on_off_mag_5, bool on_off_mag_6, bool on_off_mag_7, long double B_critical,
	long double mu_electron_particle, long double J_particle, long double I_particle, long double mu_core_particle, long double m_J, long double m_F, long double r1_mag_max_final, long double r2_mag_max_final, long double r3_mag_max_final, long double r4_mag_max_final, long double r5_mag_max_final, long double r6_mag_max_final, long double r7_mag_max_final, size_t N_mag_partitions,
	int particle_mode, long double temp_beam, bool flaq_Maxwell, long double a_V_0, long double b_V_0, std::size_t N_histo_V_0, std::size_t N_histo_theta_in, bool flaq_Maxwell_mode, bool average_peak, std::size_t n_mag_1_in, std::size_t n_mag_1_absorption, std::size_t n_mag_1_out, std::size_t n_mag_2_in, std::size_t n_mag_2_absorption, std::size_t n_mag_2_out, std::size_t n_mag_3_in, std::size_t n_mag_3_absorption, std::size_t n_mag_3_out, std::size_t n_mag_4_in, std::size_t n_mag_4_absorption, std::size_t n_mag_4_out, std::size_t n_mag_5_in, std::size_t n_mag_5_absorption, std::size_t n_mag_5_out, std::size_t n_mag_6_in, std::size_t n_mag_6_absorption, std::size_t n_mag_6_out, std::size_t n_mag_7_in, std::size_t n_mag_7_absorption, std::size_t n_mag_7_out,
	std::size_t n_tube_y0_x0, long double phi_1_2, bool flaq_angular_coefficient, size_t N_CYL_partitions, size_t N_r_angular, size_t N_phi_angular, long double n_cos_intensity) {


	printf("Вывод пространственного распределения\n");
	printf("\n");

	
	
	
	
	long double temp = 0.0;

	if (average_peak == true) {

		size_t len = arrlen(mass_histo_x);

		for (size_t i = 0; i < (len / 2); i++) {

			temp = (mass_histo_x[i][0] + mass_histo_x[len - 1 - i][0]) / 2.0;
			// (огругление до целого в большую сторону)
			mass_histo_x[i][0] = temp;
			mass_histo_x[len - 1 - i][0] = temp;

		}

	}

   

	// вывод полученных результатов в файл
	FILE *fd;

	fopen_s(&fd, filename, "wb");

	if (fd == NULL) {
		fprintf(stderr, "Ошибка открытия выводного файла.\n");
		cout << endl;
		SleepEx(40, true); // пауза для того, чтобы успеть прочитать информацию
		exit(1);
	}
	else {
		setlocale(LC_ALL, "rus"); // корректное отображение Кириллицы

		fprintf(fd, "\n");
		fprintf(fd, "### \n");
		fprintf(fd, "### Число Частиц в Бине штук || Нормированное Значение || Координата X Левого Конца Бина мм || Число Частиц в Бине штук || Нормированное Значение || Координата R Левого Конца Бина мм \n");
		fprintf(fd, "### \n");
		fprintf(fd, "\n");

		int summ = 0; // переменная для подсчита сколько всего чатиц попало в круг определенного радиуса


		setlocale(LC_ALL, "C"); // установить используемую системой локаль для корректной отображении точки в выходном файле

		for (size_t i = 0; i < arrlen(mass_histo_x); i++) {

			if (i < arrlen(mass_histo_r)) {

				summ = summ + (int)mass_histo_r[i][0];

				if ((normalization_x == 0) || (normalization_r == 0)) {// исключение надписи nan(ind)
					fprintf(fd, "%.5Le %.5Le %Lf %.5Le %.5Le %Lf %.5Le\n", mass_histo_x[i][0], 0.0, mass_histo_x[i][1], mass_histo_r[i][0], 0.0, mass_histo_r[i][1], (long double)summ);
				}
				else {
					fprintf(fd, "%.5Le %.5Le %Lf %.5Le %.5Le %Lf %.5Le\n", mass_histo_x[i][0], (mass_histo_x[i][0] / normalization_x), mass_histo_x[i][1], mass_histo_r[i][0], (mass_histo_r[i][0] / normalization_r), mass_histo_r[i][1], (long double)summ);

				}


			}

			else {

				if ((normalization_x == 0) || (normalization_r == 0)) {// исключение надписи nan(ind)
					fprintf(fd, "%.5Le %.5Le %Lf %.5Le %.5Le %Lf %.5Le\n", mass_histo_x[i][0], 0.0, mass_histo_x[i][1], 0.0, 0.0, 0.0, 0.0);
				}
				else {
					fprintf(fd, "%.5Le %.5Le %Lf %.5Le %.5Le %Lf %.5Le\n", mass_histo_x[i][0], (long double)(mass_histo_x[i][0] / normalization_x), mass_histo_x[i][1], 0.0, 0.0, 0.0, 0.0);

				}
			}

		}


		//long double phi_1_2_new = (1.0 / (2.0*pow(R2_1, 2.0)))*(pow(L_1, 2.0) + pow(R2_1, 2.0) + pow(R2_2, 2.0) - pow(pow(pow(L_1, 2.0) + pow(R2_1, 2.0) + pow(R2_2, 2.0), 2.0) - 4.0*pow(R2_1*R2_2, 2.0), 1.0 / 2.0)) - (1.0 / (2.0*pow(R3_1, 2.0)))*(pow(L_1, 2.0) + pow(R3_1, 2.0) + pow(R3_2, 2.0) - pow(pow(pow(L_1, 2.0) + pow(R3_1, 2.0) + pow(R3_2, 2.0), 2.0) - 4.0*pow(R3_1*R3_2, 2.0), 1.0 / 2.0));
		/*



		long double	r1 = max(R2_1, R2_2);
		long double r2 = max(R3_1, R3_2);
		long double r3 = max(R2_1, R3_2);
		long double r4 = max(R2_2, R3_1);



		long double phi_1_2_new_1 = (1.0 / (2.0*pow(r1, 2.0)))*(pow(L_1, 2.0) + pow(R2_1, 2.0) + pow(R2_2, 2.0) - pow(pow(pow(L_1, 2.0) + pow(R2_1, 2.0) + pow(R2_2, 2.0), 2.0) - 4.0*pow(R2_1*R2_2, 2.0), 1.0 / 2.0));
		long double phi_1_2_new_2 = (1.0 / (2.0*pow(r2, 2.0)))*(pow(L_1, 2.0) + pow(R3_1, 2.0) + pow(R3_2, 2.0) - pow(pow(pow(L_1, 2.0) + pow(R3_1, 2.0) + pow(R3_2, 2.0), 2.0) - 4.0*pow(R3_1*R3_2, 2.0), 1.0 / 2.0));
		long double phi_1_2_new_3 = (1.0 / (2.0*pow(r3, 2.0)))*(pow(L_1, 2.0) + pow(R2_1, 2.0) + pow(R3_2, 2.0) - pow(pow(pow(L_1, 2.0) + pow(R2_1, 2.0) + pow(R3_2, 2.0), 2.0) - 4.0*pow(R2_1*R3_2, 2.0), 1.0 / 2.0));
		long double phi_1_2_new_4 = (1.0 / (2.0*pow(r4, 2.0)))*(pow(L_1, 2.0) + pow(R2_2, 2.0) + pow(R3_1, 2.0) - pow(pow(pow(L_1, 2.0) + pow(R2_2, 2.0) + pow(R3_1, 2.0), 2.0) - 4.0*pow(R2_2*R3_1, 2.0), 1.0 / 2.0));

		long double phi_1_2_new = phi_1_2_new_1 + phi_1_2_new_2 - phi_1_2_new_3 - phi_1_2_new_4;
		*/

		long double	r1 = max(R2_1, R2_2);
		long double r2 = max(R3_1, R3_2);
		long double r3 = max(R2_1, R3_2);
		long double r4 = max(R2_2, R3_1);


		//long double phi_1_2_new = (1.0 / (2.0*pow(r1, 2.0)))*(pow(L_1, 2.0) + pow(R2_1, 2.0) + pow(R2_2, 2.0) - pow(pow(pow(L_1, 2.0) + pow(R2_1, 2.0) + pow(R2_2, 2.0), 2.0) - 4.0*pow(R2_1*R2_2, 2.0), 1.0 / 2.0)) - (1.0 / (2.0*pow(r2, 2.0)))*(pow(L_1, 2.0) + pow(R3_1, 2.0) + pow(R3_2, 2.0) - pow(pow(pow(L_1, 2.0) + pow(R3_1, 2.0) + pow(R3_2, 2.0), 2.0) - 4.0*pow(R3_1*R3_2, 2.0), 1.0 / 2.0));

		//long double phi_1_2_new_1 = (1.0 / (2.0*pow(r1, 2.0)))*(pow(L_1, 2.0) + pow(R2_1, 2.0) + pow(R2_2, 2.0) - pow(pow(pow(L_1, 2.0) + pow(R2_1, 2.0) + pow(R2_2, 2.0), 2.0) - 4.0*pow(R2_1*R2_2, 2.0), 1.0 / 2.0));
		//long double phi_1_2_new_2 = (1.0 / (2.0*pow(r2, 2.0)))*(pow(L_1, 2.0) + pow(R3_1, 2.0) + pow(R3_2, 2.0) - pow(pow(pow(L_1, 2.0) + pow(R3_1, 2.0) + pow(R3_2, 2.0), 2.0) - 4.0*pow(R3_1*R3_2, 2.0), 1.0 / 2.0));
		//long double phi_1_2_new_3 = (1.0 / (2.0*pow(r3, 2.0)))*(pow(L_1, 2.0) + pow(R2_1, 2.0) + pow(R3_2, 2.0) - pow(pow(pow(L_1, 2.0) + pow(R2_1, 2.0) + pow(R3_2, 2.0), 2.0) - 4.0*pow(R2_1*R3_2, 2.0), 1.0 / 2.0));
		//long double phi_1_2_new_4 = (1.0 / (2.0*pow(r4, 2.0)))*(pow(L_1, 2.0) + pow(R2_2, 2.0) + pow(R3_1, 2.0) - pow(pow(pow(L_1, 2.0) + pow(R2_2, 2.0) + pow(R3_1, 2.0), 2.0) - 4.0*pow(R2_2*R3_1, 2.0), 1.0 / 2.0));


		long double phi_12_34 = (1.0 / (2.0*pow(R2_1, 2.0)))*(pow(L_1, 2.0) + pow(R2_1, 2.0) + pow(R2_2, 2.0) - pow(pow(pow(L_1, 2.0) + pow(R2_1, 2.0) + pow(R2_2, 2.0), 2.0) - 4.0*pow(R2_1*R2_2, 2.0), 1.0 / 2.0));
		long double phi_12_4 = (1.0 / (2.0*pow(R2_1, 2.0)))*(pow(L_1, 2.0) + pow(R2_1, 2.0) + pow(R3_2, 2.0) - pow(pow(pow(L_1, 2.0) + pow(R2_1, 2.0) + pow(R3_2, 2.0), 2.0) - 4.0*pow(R2_1*R3_2, 2.0), 1.0 / 2.0));
		long double phi_1_34 = (1.0 / (2.0*pow(R3_1, 2.0)))*(pow(L_1, 2.0) + pow(R3_1, 2.0) + pow(R2_2, 2.0) - pow(pow(pow(L_1, 2.0) + pow(R3_1, 2.0) + pow(R2_2, 2.0), 2.0) - 4.0*pow(R3_1*R2_2, 2.0), 1.0 / 2.0));
		long double phi_1_4 = (1.0 / (2.0*pow(R3_1, 2.0)))*(pow(L_1, 2.0) + pow(R3_1, 2.0) + pow(R3_2, 2.0) - pow(pow(pow(L_1, 2.0) + pow(R3_1, 2.0) + pow(R3_2, 2.0), 2.0) - 4.0*pow(R3_1*R3_2, 2.0), 1.0 / 2.0));



		//long double k1 = 0.0, k2=0.0,k3=0.0,k4=0.0 ;

		//long double phi_1_2_new = k1*phi_1_2_new_1 + *k2*phi_1_2_new_2 - k3*phi_1_2_new_3 - k4*phi_1_2_new_4;

		//long double phi_1_2_new = phi_1_2_new_1 + phi_1_2_new_2 - phi_1_2_new_3 - phi_1_2_new_4;


		long double phi_1_2_new = 0.0;

		//long double phi_1_2_new = (pow(R2_1, 2.0) / (pow(R2_1, 2.0) - pow(R3_1, 2.0)))*(phi_12_34 - phi_12_4) - (pow(R3_1, 2.0) / (pow(R2_1, 2.0) - pow(R3_1, 2.0)))*(phi_1_34 - phi_1_4);

		//long double phi_1_2_new_1 = (1.0 / (2.0*pow(r1, 2.0)))*(pow(L_1, 2.0) + pow(R2_1, 2.0) + pow(R2_2, 2.0) - pow(pow(pow(L_1, 2.0) + pow(R2_1, 2.0) + pow(R2_2, 2.0), 2.0) - 4.0*pow(R2_1*R2_2, 2.0), 1.0 / 2.0)) - (1.0 / (2.0*pow(r1, 2.0)))*(pow(L_1, 2.0) + pow(R2_1, 2.0) + pow(R3_2, 2.0) - pow(pow(pow(L_1, 2.0) + pow(R2_1, 2.0) + pow(R3_2, 2.0), 2.0) - 4.0*pow(R2_1*R3_2, 2.0), 1.0 / 2.0))-(1.0 / (2.0*pow(r2, 2.0)))*(pow(L_1, 2.0) + pow(R2_2, 2.0) + pow(R3_1, 2.0) - pow(pow(pow(L_1, 2.0) + pow(R2_2, 2.0) + pow(R3_1, 2.0), 2.0) - 4.0*pow(R2_2*R3_1, 2.0), 1.0 / 2.0)) - (1.0 / (2.0*pow(R2_1, 2.0)))*(pow(L_1, 2.0) + pow(R2_1, 2.0) + pow(R2_2, 2.0) - pow(pow(pow(L_1, 2.0) + pow(R2_1, 2.0) + pow(R2_2, 2.0), 2.0) - 4.0*pow(R2_1*R2_2, 2.0), 1.0 / 2.0));

		/*


		if (n_cos_intensity = 1.0) {

			phi_1_2_new = (pow(R2_1, 2.0) / (pow(R2_1, 2.0) - pow(R3_1, 2.0)))*(phi_12_34 - phi_12_4) - (pow(R3_1, 2.0) / (pow(R2_1, 2.0) - pow(R3_1, 2.0)))*(phi_1_34 - phi_1_4);

		}
		else {

			phi_1_2_new = angular_coefficient_calculation(0.0, L_1, R1_1, R2_1, R3_1, R1_2, R2_2, R3_2, N_r_angular, N_phi_angular, n_cos_intensity);
		}
		 */

		 //phi_1_2 = phi_1_2_new;

		setlocale(LC_ALL, "rus"); // корректное отображение Кириллицы

		fprintf(fd, "\n");
		fprintf(fd, "### \n");
		fprintf(fd, "### Скорость = %.2Lf мм/сек. Число Частиц = %.4Le штук Число Бинов = %.0Lf штук Максимальное время счета = %.2Lf (мин.)\n", V_0, (long double)N, (long double)N_histo, t);
		fprintf(fd, "### R1_1=%.1Lf мм R2_1=%.1Lf мм R3_1=%.1Lf мм L_1=%.1Lf мм\n", R1_1, R2_1, R3_1, L_1);
		fprintf(fd, "### Метод угловых коэффициентов для цилиндров №№ 1-2 = %s\n", (flaq_angular_coefficient ? "Включено" : "Отключено"));

		fprintf(fd, "### Интегральный угловой коэффициент для цилиндров №№ 1-2 = %.4Le 1/(число частиц вышло из цилиндра № 1)\n", phi_1_2);


		fprintf(fd, "### R1_2=%.1Lf мм R2_2=%.1Lf мм R3_2=%.1Lf мм L_2=%.1Lf мм\n", R1_2, R2_2, R3_2, L_2);
		fprintf(fd, "### R1_3=%.1Lf мм R2_3=%.1Lf мм R3_3=%.1Lf мм L_3=%.1Lf мм\n", R1_3, R2_3, R3_3, L_3);
		fprintf(fd, "### R1_4=%.1Lf мм R2_4=%.1Lf мм R3_4=%.1Lf мм L_4=%.1Lf мм\n", R1_4, R2_4, R3_4, L_4);
		fprintf(fd, "### R1_5=%.1Lf мм R2_5=%.1Lf мм R3_5=%.1Lf мм L_5=%.1Lf мм\n", R1_5, R2_5, R3_5, L_5);
		fprintf(fd, "### R1_6=%.1Lf мм R2_6=%.1Lf мм R3_6=%.1Lf мм L_6=%.1Lf мм\n", R1_6, R2_6, R3_6, L_6);
		fprintf(fd, "### R1_7=%.1Lf мм R2_7=%.1Lf мм R3_7=%.1Lf мм L_7=%.1Lf мм\n", R1_7, R2_7, R3_7, L_7);
		fprintf(fd, "### R1_8=%.1Lf мм R2_8=%.1Lf мм R3_8=%.1Lf мм L_8=%.1Lf мм\n", R1_8, R2_8, R3_8, L_7);

		fprintf(fd, "### \n");

		fprintf(fd, "### Максимальный радиус экрана = %.2Lf мм\n", R);
		fprintf(fd, "### Усреднение по двум полуплоскостям на экране = %s\n", (average_peak ? "Включено" : "Отключено"));
		fprintf(fd, "### Радиус кольца детектора = %.2Lf мм\n", R_source);
		fprintf(fd, "### Координата x_0 детектора = %.2Lf мм\n", x_0_source);
		fprintf(fd, "### Число точек, измеренных детектором = %.0Lf штук\n", (long double)N_histo_source);
		fprintf(fd, "### \n");

		fprintf(fd, "### Расстояние магнита от левого_торца цилиндра (первый цилиндр) = %.2Lf мм\n", z0_mag1);
		fprintf(fd, "### Длина магнита (первый цилиндр) = %.2Lf мм\n", L_mag1);
		fprintf(fd, "### Максимальное магнитное поле (первый цилиндр) = %.2Lf Гс\n", B1_max);
		fprintf(fd, "### Максимальный начальный радиус магнита (первый цилиндр) = %.2Lf мм\n", r1_mag_max_initial);
		fprintf(fd, "### Максимальный конечный радиус магнита (первый цилиндр) = %.2Lf мм\n", r1_mag_max_final);
		fprintf(fd, "### Наличие магнита (первый цилиндр) = %s\n", (on_off_mag_1 ? "Да" : "Нет"));
		fprintf(fd, "### \n");

		fprintf(fd, "### Расстояние магнита от левого_торца цилиндра (второй цилиндр) = %.2Lf мм\n", z0_mag2);
		fprintf(fd, "### Длина магнита (второй цилиндр) = %.2Lf мм\n", L_mag2);
		fprintf(fd, "### Максимальное магнитное поле (второй цилиндр) = %.2Lf Гс\n", B2_max);
		fprintf(fd, "### Максимальный начальный радиус магнита (второй цилиндр) = %.2Lf мм\n", r2_mag_max_initial);
		fprintf(fd, "### Максимальный конечный радиус магнита (второй цилиндр) = %.2Lf мм\n", r2_mag_max_final);
		fprintf(fd, "### Наличие магнита (второй цилиндр) = %s\n", (on_off_mag_2 ? "Да" : "Нет"));
		fprintf(fd, "### \n");

		fprintf(fd, "### Расстояние магнита от левого_торца цилиндра (третий цилиндр) = %.2Lf мм\n", z0_mag3);
		fprintf(fd, "### Длина магнита (третий цилиндр) = %.2Lf мм\n", L_mag3);
		fprintf(fd, "### Максимальное магнитное поле (третий цилиндр) = %.2Lf Гс\n", B3_max);
		fprintf(fd, "### Максимальный начальный радиус магнита (третий цилиндр) = %.2Lf мм\n", r3_mag_max_initial);
		fprintf(fd, "### Максимальный конечный радиус магнита (третий цилиндр) = %.2Lf мм\n", r3_mag_max_final);
		fprintf(fd, "### Наличие магнита (третий цилиндр) = %s\n", (on_off_mag_3 ? "Да" : "Нет"));



		fprintf(fd, "### Расстояние магнита от левого_торца цилиндра (четвертый цилиндр) = %.2Lf мм\n", z0_mag4);
		fprintf(fd, "### Длина магнита (четвертый цилиндр) = %.2Lf мм\n", L_mag4);
		fprintf(fd, "### Максимальное магнитное поле (четвертый цилиндр) = %.2Lf Гс\n", B4_max);
		fprintf(fd, "### Максимальный начальный радиус магнита (четвертый цилиндр) = %.2Lf мм\n", r4_mag_max_initial);
		fprintf(fd, "### Максимальный конечный радиус магнита (четвертый цилиндр) = %.2Lf мм\n", r4_mag_max_final);
		fprintf(fd, "### Наличие магнита (четвертый цилиндр) = %s\n", (on_off_mag_4 ? "Да" : "Нет"));


		fprintf(fd, "### Расстояние магнита от левого_торца цилиндра (пятый цилиндр) = %.2Lf мм\n", z0_mag5);
		fprintf(fd, "### Длина магнита (пятый цилиндр) = %.2Lf мм\n", L_mag5);
		fprintf(fd, "### Максимальное магнитное поле (пятый цилиндр) = %.2Lf Гс\n", B5_max);
		fprintf(fd, "### Максимальный начальный радиус магнита (пятый цилиндр) = %.2Lf мм\n", r5_mag_max_initial);
		fprintf(fd, "### Максимальный конечный радиус магнита (пятый цилиндр) = %.2Lf мм\n", r5_mag_max_final);
		fprintf(fd, "### Наличие магнита (пятый цилиндр) = %s\n", (on_off_mag_5 ? "Да" : "Нет"));


		fprintf(fd, "### Расстояние магнита от левого_торца цилиндра (шестой цилиндр) = %.2Lf мм\n", z0_mag6);
		fprintf(fd, "### Длина магнита (шестой цилиндр) = %.2Lf мм\n", L_mag6);
		fprintf(fd, "### Максимальное магнитное поле (шестой цилиндр) = %.2Lf Гс\n", B6_max);
		fprintf(fd, "### Максимальный начальный радиус магнита (шестой цилиндр) = %.2Lf мм\n", r6_mag_max_initial);
		fprintf(fd, "### Максимальный конечный радиус магнита (шестой цилиндр) = %.2Lf мм\n", r6_mag_max_final);
		fprintf(fd, "### Наличие магнита (шестой цилиндр) = %s\n", (on_off_mag_6 ? "Да" : "Нет"));


		fprintf(fd, "### Расстояние магнита от левого_торца цилиндра (седьмой цилиндр) = %.2Lf мм\n", z0_mag7);
		fprintf(fd, "### Длина магнита (седьмой цилиндр) = %.2Lf мм\n", L_mag7);
		fprintf(fd, "### Максимальное магнитное поле (седьмой цилиндр) = %.2Lf Гс\n", B7_max);
		fprintf(fd, "### Максимальный начальный радиус магнита (седьмой цилиндр) = %.2Lf мм\n", r7_mag_max_initial);
		fprintf(fd, "### Максимальный конечный радиус магнита (седьмой цилиндр) = %.2Lf мм\n", r7_mag_max_final);
		fprintf(fd, "### Наличие магнита (седьмой цилиндр) = %s\n", (on_off_mag_7 ? "Да" : "Нет"));




		fprintf(fd, "### \n");
		fprintf(fd, "### Магнитный момент ядра частицы g_I = %.9Le\n", mu_core_particle);
		fprintf(fd, "### Магнитный момент электронной оболочки частицы g_J = %.9Le\n", mu_electron_particle);
		fprintf(fd, "### Масса частицы m = %.9Le МэВ\n", m_particle);
		fprintf(fd, "### Спин ядра частицы I= %.9Le\n", I_particle);
		fprintf(fd, "### Момент электронной оболочки частицы J=L+S = %.9Le\n", J_particle);
		fprintf(fd, "### Проекция момента электронной оболочки частицы m_J = %.9Le\n", m_J);
		fprintf(fd, "### Критическое поле частицы B_critical = %.9Le Гс\n", B_critical);
		fprintf(fd, "### Проекция полного момента F=I+J частицы m_F = %.9Le\n", m_F);
		fprintf(fd, "### Число разбиений магнита = %.0Lf штук\n", (long double)N_mag_partitions);
		fprintf(fd, "### Температура пучка частиц = %.3Lf  Кельвинов\n", temp_beam);
		fprintf(fd, "### Распределение по модулю скорости = %s\n", (flaq_Maxwell ? "Дельта функция" : "Распределение Максвелла по модулю скорости"));
		fprintf(fd, "### Режим распределения Максвелла = %s\n", (flaq_Maxwell_mode ? "Распределение Максвелла для пучка" : "Обычнное по модулю скорости"));
		fprintf(fd, "### Левая граница для распределения по модулю скорости  = %.9Le мм/сек\n", a_V_0);
		fprintf(fd, "### Певая граница для распределения по модулю скорости  = %.9Le мм/сек\n", b_V_0);
		fprintf(fd, "### Число точек гистограммы распределения по модулю скорости  = %.9Le точек\n", (long double)N_histo_V_0);
		fprintf(fd, "### Число точек гистограммы распределения по углу theta частиц, вылетающих из кольца источника  = %.9Le точек\n", (long double)N_histo_theta_in);



		if (particle_mode == 0) {
			fprintf(fd, "### Режим частиц = ручной ввод состояния (particle mode = %.0Lf)\n", (long double)particle_mode);
		}
		else if (particle_mode == 1) {

			fprintf(fd, "### Режим частиц = режим водорода (случайное выбирание подсостояния из возможных для водорода) (particle mode = %.0Lf)\n", (long double)particle_mode);

		}
		else if (particle_mode == 2) {

			fprintf(fd, "### Режим частиц = режим дейтерия (случайное выбирание подсостояния из возможных для дейтерия) (particle mode = %.0Lf)\n", (long double)particle_mode);
		}
		else {

			fprintf(fd, "### Введено неправильное значение particle mode, введите значение 0,1 или 2 (Вы ввели particle mode = %.0Lf)\n", (long double)particle_mode);

		}








		fprintf(fd, "### \n");


		fprintf(fd, "### (Цилиндр №1) Коэфф.Захвата Левого торца = %.2Lf Коэфф.Захвата Поверхности Образующей = %.2Lf Коэфф.Захвата Правого торца = %.2Lf\n", b1_left, b1_surface, b1_right);
		fprintf(fd, "### (Цилиндр №2) Коэфф.Захвата Левого торца = %.2Lf Коэфф.Захвата Поверхности Образующей = %.2Lf Коэфф.Захвата Правого торца = %.2Lf\n", b2_left, b2_surface, b2_right);
		fprintf(fd, "### (Цилиндр №3) Коэфф.Захвата Левого торца = %.2Lf Коэфф.Захвата Поверхности Образующей = %.2Lf Коэфф.Захвата Правого торца = %.2Lf\n", b3_left, b3_surface, b3_right);
		fprintf(fd, "### (Цилиндр №4) Коэфф.Захвата Левого торца = %.2Lf Коэфф.Захвата Поверхности Образующей = %.2Lf Коэфф.Захвата Правого торца = %.2Lf\n", b4_left, b4_surface, b4_right);
		fprintf(fd, "### (Цилиндр №5) Коэфф.Захвата Левого торца = %.2Lf Коэфф.Захвата Поверхности Образующей = %.2Lf Коэфф.Захвата Правого торца = %.2Lf\n", b5_left, b5_surface, b5_right);
		fprintf(fd, "### (Цилиндр №6) Коэфф.Захвата Левого торца = %.2Lf Коэфф.Захвата Поверхности Образующей = %.2Lf Коэфф.Захвата Правого торца = %.2Lf\n", b6_left, b6_surface, b6_right);
		fprintf(fd, "### (Цилиндр №7) Коэфф.Захвата Левого торца = %.2Lf Коэфф.Захвата Поверхности Образующей = %.2Lf Коэфф.Захвата Правого торца = %.2Lf\n", b7_left, b7_surface, b7_right);


		fprintf(fd, "### \n");


		fprintf(fd, "### (Цилиндр №1) Дифф. Угол Левого торца = %.2Lf Дифф. Угол Поверхности Образующей = %.2Lf Дифф. Угол Правого торца = %.2Lf\n", theta1_diffusion_left, theta1_diffusion_surface, theta1_diffusion_right);
		fprintf(fd, "### (Цилиндр №2) Дифф. Угол Левого торца = %.2Lf Дифф. Угол Поверхности Образующей = %.2Lf Дифф. Угол Правого торца = %.2Lf\n", theta2_diffusion_left, theta2_diffusion_surface, theta2_diffusion_right);
		fprintf(fd, "### (Цилиндр №3) Дифф. Угол Левого торца = %.2Lf Дифф. Угол Поверхности Образующей = %.2Lf Дифф. Угол Правого торца = %.2Lf\n", theta3_diffusion_left, theta3_diffusion_surface, theta3_diffusion_right);
		fprintf(fd, "### (Цилиндр №4) Дифф. Угол Левого торца = %.2Lf Дифф. Угол Поверхности Образующей = %.2Lf Дифф. Угол Правого торца = %.2Lf\n", theta4_diffusion_left, theta4_diffusion_surface, theta4_diffusion_right);
		fprintf(fd, "### (Цилиндр №5) Дифф. Угол Левого торца = %.2Lf Дифф. Угол Поверхности Образующей = %.2Lf Дифф. Угол Правого торца = %.2Lf\n", theta5_diffusion_left, theta5_diffusion_surface, theta5_diffusion_right);
		fprintf(fd, "### (Цилиндр №6) Дифф. Угол Левого торца = %.2Lf Дифф. Угол Поверхности Образующей = %.2Lf Дифф. Угол Правого торца = %.2Lf\n", theta6_diffusion_left, theta6_diffusion_surface, theta6_diffusion_right);
		fprintf(fd, "### (Цилиндр №7) Дифф. Угол Левого торца = %.2Lf Дифф. Угол Поверхности Образующей = %.2Lf Дифф. Угол Правого торца = %.2Lf\n", theta7_diffusion_left, theta7_diffusion_surface, theta7_diffusion_right);


		fprintf(fd, "### \n");



		fprintf(fd, "### (Цилиндр №1) Максимальное число столкновений о стенки = %.0Lf ударов\n", (long double)n1);
		fprintf(fd, "### (Цилиндр №2) Максимальное число столкновений о стенки = %.0Lf ударов\n", (long double)n2);
		fprintf(fd, "### (Цилиндр №3) Максимальное число столкновений о стенки = %.0Lf ударов\n", (long double)n3);
		fprintf(fd, "### (Цилиндр №4) Максимальное число столкновений о стенки = %.0Lf ударов\n", (long double)n4);
		fprintf(fd, "### (Цилиндр №5) Максимальное число столкновений о стенки = %.0Lf ударов\n", (long double)n5);
		fprintf(fd, "### (Цилиндр №6) Максимальное число столкновений о стенки = %.0Lf ударов\n", (long double)n6);
		fprintf(fd, "### (Цилиндр №7) Максимальное число столкновений о стенки = %.0Lf ударов\n", (long double)n7);

		fprintf(fd, "### Максимальное число переходов частицы между цилиндрами №1,2,3 = %.0Lf переходов\n", (long double)n_travel);


		fprintf(fd, "### \n");
		fprintf(fd, "### Полное число частиц брошенных в круг, описанный вокруг торца цилиндра = %.4Le штук\n", (long double)N / phi_1_2);
		fprintf(fd, "### Число частиц, которые не вышли из круга в источник = %.4Le штук\n", (long double)N_off / phi_1_2);
		fprintf(fd, "### Число частиц выпущенных из кольца источника = %.4Le штук\n", (long double)N_on / phi_1_2);
		if (flaq_angular_coefficient == false) {
			fprintf(fd, "### Полное число частиц, которые вышли из цилиндра №1 = %.4Le штук\n", (long double)N2_1);
		}
		else if (flaq_angular_coefficient == true) {
			fprintf(fd, "### Полное число частиц, которые вышли из цилиндра №1 = %.4Le штук\n", (long double)N);
		}
		fprintf(fd, "### Полное число частиц, которые вышли из цилиндра №2 = %.0Lf штук\n", (long double)N2_2);
		fprintf(fd, "### Полное число частиц, которые вышли из цилиндра №3 = %.0Lf штук\n", (long double)N2_3);
		fprintf(fd, "### Полное число частиц, которые вышли из цилиндра №4 = %.0Lf штук\n", (long double)N2_4);
		fprintf(fd, "### Полное число частиц, которые вышли из цилиндра №5 = %.0Lf штук\n", (long double)N2_5);
		fprintf(fd, "### Полное число частиц, которые вышли из цилиндра №6 = %.0Lf штук\n", (long double)N2_6);
		fprintf(fd, "### Полное число частиц, которые вышли из цилиндра №7 = %.0Lf штук\n", (long double)N2_7);


		fprintf(fd, "### \n");



		fprintf(fd, "### Число частиц, которые вернулись обратно в источник из цилиндра №1 = %.0Lf штук\n", (long double)N1_1);
		fprintf(fd, "### Число частиц, которые вернулись обратно в цилиндр №1 из цилиндра №2 = %.0Lf штук\n", (long double)N1_2);
		fprintf(fd, "### Число частиц, которые вернулись обратно в цилиндр №2 из цилиндра №3 = %.0Lf штук\n", (long double)N1_3);
		fprintf(fd, "### Число частиц, которые вернулись обратно в цилиндр №3 из цилиндра №4 = %.0Lf штук\n", (long double)N1_4);
		fprintf(fd, "### Число частиц, которые вернулись обратно в цилиндр №4 из цилиндра №5 = %.0Lf штук\n", (long double)N1_5);
		fprintf(fd, "### Число частиц, которые вернулись обратно в цилиндр №5 из цилиндра №6 = %.0Lf штук\n", (long double)N1_6);
		fprintf(fd, "### Число частиц, которые вернулись обратно в цилиндр №6 из цилиндра №7 = %.0Lf штук\n", (long double)N1_7);


		fprintf(fd, "### \n");


		if (flaq_angular_coefficient == false) {
			fprintf(fd, "### Число частиц, которые были захвачены поверхностью цилиндра №1 = %.0Lf штук\n", (long double)(N3_1 + N4_1 + N5_1));

		}
		else  if (flaq_angular_coefficient == true) {

			fprintf(fd, "### Число частиц, которые были захвачены поверхностью цилиндра №1 = %.4Le штук\n", (long double)(N_on / phi_1_2 - N_on));


		}

		fprintf(fd, "### Число частиц, которые были захвачены левым торцом поверхности цилиндра №1 = %.0Lf штук\n", (long double)N3_1);
		fprintf(fd, "### Число частиц, которые были захвачены поверхностью образующей цилиндра №1 = %.0Lf штук\n", (long double)N4_1);
		fprintf(fd, "### Число частиц, которые были захвачены правым торцом поверхности цилиндра №1 = %.0Lf штук\n", (long double)N5_1);
		fprintf(fd, "### \n");


		fprintf(fd, "### Число частиц, которые были захвачены поверхностью цилиндра №2 = %.0Lf штук\n", (long double)(N3_2 + N4_2 + N5_2));
		fprintf(fd, "### Число частиц, которые были захвачены левым торцом поверхности цилиндра №2 = %.0Lf штук\n", (long double)N3_2);
		fprintf(fd, "### Число частиц, которые были захвачены поверхностью образующей цилиндра №2 = %.0Lf штук\n", (long double)N4_2);
		fprintf(fd, "### Число частиц, которые были захвачены правым торцом поверхности цилиндра №2 = %.0Lf штук\n", (long double)N5_2);
		fprintf(fd, "### \n");


		fprintf(fd, "### Число частиц, которые были захвачены поверхностью цилиндра №3 = %.0Lf штук\n", (long double)(N3_3 + N4_3 + N5_3));
		fprintf(fd, "### Число частиц, которые были захвачены левым торцом поверхности цилиндра №3 = %.0Lf штук\n", (long double)N3_3);
		fprintf(fd, "### Число частиц, которые были захвачены поверхностью образующей цилиндра №3 = %.0Lf штук\n", (long double)N4_3);
		fprintf(fd, "### Число частиц, которые были захвачены правым торцом поверхности цилиндра №3 = %.0Lf штук\n", (long double)N5_3);
		fprintf(fd, "### \n");

		fprintf(fd, "### Число частиц, которые были захвачены поверхностью цилиндра №4 = %.0Lf штук\n", (long double)(N3_4 + N4_4 + N5_4));
		fprintf(fd, "### Число частиц, которые были захвачены левым торцом поверхности цилиндра №4 = %.0Lf штук\n", (long double)N3_4);
		fprintf(fd, "### Число частиц, которые были захвачены поверхностью образующей цилиндра №4 = %.0Lf штук\n", (long double)N4_4);
		fprintf(fd, "### Число частиц, которые были захвачены правым торцом поверхности цилиндра №4 = %.0Lf штук\n", (long double)N5_4);
		fprintf(fd, "### \n");


		fprintf(fd, "### Число частиц, которые были захвачены поверхностью цилиндра №5 = %.0Lf штук\n", (long double)(N3_5 + N4_5 + N5_5));
		fprintf(fd, "### Число частиц, которые были захвачены левым торцом поверхности цилиндра №5 = %.0Lf штук\n", (long double)N3_5);
		fprintf(fd, "### Число частиц, которые были захвачены поверхностью образующей цилиндра №5 = %.0Lf штук\n", (long double)N4_5);
		fprintf(fd, "### Число частиц, которые были захвачены правым торцом поверхности цилиндра №5 = %.0Lf штук\n", (long double)N5_5);
		fprintf(fd, "### \n");


		fprintf(fd, "### Число частиц, которые были захвачены поверхностью цилиндра №6 = %.0Lf штук\n", (long double)(N3_6 + N4_6 + N5_6));
		fprintf(fd, "### Число частиц, которые были захвачены левым торцом поверхности цилиндра №6 = %.0Lf штук\n", (long double)N3_6);
		fprintf(fd, "### Число частиц, которые были захвачены поверхностью образующей цилиндра №6 = %.0Lf штук\n", (long double)N4_6);
		fprintf(fd, "### Число частиц, которые были захвачены правым торцом поверхности цилиндра №6 = %.0Lf штук\n", (long double)N5_6);
		fprintf(fd, "### \n");



		fprintf(fd, "### Число частиц, которые были захвачены поверхностью цилиндра №7 = %.0Lf штук\n", (long double)(N3_7 + N4_7 + N5_7));
		fprintf(fd, "### Число частиц, которые были захвачены левым торцом поверхности цилиндра №7 = %.0Lf штук\n", (long double)N3_7);
		fprintf(fd, "### Число частиц, которые были захвачены поверхностью образующей цилиндра №7 = %.0Lf штук\n", (long double)N4_7);
		fprintf(fd, "### Число частиц, которые были захвачены правым торцом поверхности цилиндра №7 = %.0Lf штук\n", (long double)N5_7);
		fprintf(fd, "### \n");




		fprintf(fd, "### Полное число частиц, которые были захвачены поверхностими цилиндров №1,2,3,4,5,6,7 = %.0Lf штук\n", (long double)(N3_1 + N4_1 + N5_1 + N3_2 + N4_2 + N5_2 + N3_3 + N4_3 + N5_3 + N3_4 + N4_4 + N5_4 + N3_5 + N4_5 + N5_5 + N3_6 + N4_6 + N5_6 + N3_7 + N4_7 + N5_7));
		fprintf(fd, "### Полное число частиц, которые были захвачены левым торцом поверхности цилиндров №1,2,3,4,5,6,7 = %.0Lf штук\n", (long double)(N3_1 + N3_2 + N3_3 + N3_4 + N3_5 + N3_6 + N3_7));
		fprintf(fd, "### Полное число частиц, которые были захвачены поверхностью образующей цилиндров №1,2,3,4,5,6,7 = %.0Lf штук\n", (long double)(N4_1 + N4_2 + N4_3 + N4_4 + N4_5 + N4_6 + N4_7));
		fprintf(fd, "### Полное число частиц, которые были захвачены правым торцом поверхности цилиндров №1,2,3,4,5,6,7 = %.0Lf штук\n", (long double)(N5_1 + N5_2 + N5_3 + N5_4 + N5_5 + N5_6 + N5_7));


		fprintf(fd, "### \n");


		fprintf(fd, "### Число частиц, которые вошли в магнит №1 = %.0Lf штук\n", (long double)n_mag_1_in);
		fprintf(fd, "### Число частиц, которые поглотились магнитом №1 = %.0Lf штук\n", (long double)n_mag_1_absorption);
		fprintf(fd, "### Число частиц, которые вышли из магнита №1 = %.0Lf штук\n", (long double)n_mag_1_out);
		fprintf(fd, "### \n");

		fprintf(fd, "### Число частиц, которые вошли в магнит №2 = %.0Lf штук\n", (long double)n_mag_2_in);
		fprintf(fd, "### Число частиц, которые поглотились магнитом №2 = %.0Lf штук\n", (long double)n_mag_2_absorption);
		fprintf(fd, "### Число частиц, которые вышли из магнита №2 = %.0Lf штук\n", (long double)n_mag_2_out);
		fprintf(fd, "### \n");


		fprintf(fd, "### Число частиц, которые вошли в магнит №3 = %.0Lf штук\n", (long double)n_mag_3_in);
		fprintf(fd, "### Число частиц, которые поглотились магнитом №3 = %.0Lf штук\n", (long double)n_mag_3_absorption);
		fprintf(fd, "### Число частиц, которые вышли из магнита №3 = %.0Lf штук\n", (long double)n_mag_3_out);
		fprintf(fd, "### \n");

		fprintf(fd, "### Число частиц, которые вошли в магнит №4 = %.0Lf штук\n", (long double)n_mag_4_in);
		fprintf(fd, "### Число частиц, которые поглотились магнитом №4 = %.0Lf штук\n", (long double)n_mag_4_absorption);
		fprintf(fd, "### Число частиц, которые вышли из магнита №4 = %.0Lf штук\n", (long double)n_mag_4_out);
		fprintf(fd, "### \n");

		fprintf(fd, "### Число частиц, которые вошли в магнит №5 = %.0Lf штук\n", (long double)n_mag_5_in);
		fprintf(fd, "### Число частиц, которые поглотились магнитом №5 = %.0Lf штук\n", (long double)n_mag_5_absorption);
		fprintf(fd, "### Число частиц, которые вышли из магнита №5 = %.0Lf штук\n", (long double)n_mag_5_out);
		fprintf(fd, "### \n");

		fprintf(fd, "### Число частиц, которые вошли в магнит №6 = %.0Lf штук\n", (long double)n_mag_6_in);
		fprintf(fd, "### Число частиц, которые поглотились магнитом №6 = %.0Lf штук\n", (long double)n_mag_6_absorption);
		fprintf(fd, "### Число частиц, которые вышли из магнита №6 = %.0Lf штук\n", (long double)n_mag_6_out);
		fprintf(fd, "### \n");

		fprintf(fd, "### Число частиц, которые вошли в магнит №7 = %.0Lf штук\n", (long double)n_mag_7_in);
		fprintf(fd, "### Число частиц, которые поглотились магнитом №7 = %.0Lf штук\n", (long double)n_mag_7_absorption);
		fprintf(fd, "### Число частиц, которые вышли из магнита №7 = %.0Lf штук\n", (long double)n_mag_7_out);
		fprintf(fd, "### \n");


		fprintf(fd, "### Число частиц, которые попали в приемную трубу, расположенную в начале координат = %.0Lf штук\n", (long double)n_tube_y0_x0);
		if (flaq_angular_coefficient == true) {
			fprintf(fd, "### N_tube/N_0 = %.9Le штук\n", (long double)n_tube_y0_x0 / (N / phi_1_2));

		}
		else if (flaq_angular_coefficient == false) {

			fprintf(fd, "### N_tube/N_0 = %.9Le штук\n", (long double)n_tube_y0_x0 / N);
		}


		fprintf(fd, "### \n");


		//	fprintf(fd, "### \n");
		//	fprintf(fd, "### Число частиц, которые остались вечно саударяться со стенками цилиндра №1 = \n", n1);
		//	fprintf(fd, "### Число частиц, которые остались вечно саударяться со стенками цилиндра №2 = \n", n2);
		//	fprintf(fd, "### Число частиц, которые остались вечно саударяться со стенками цилиндра №3 = \n", n3);
		//	fprintf(fd, "### Число частиц, которые остались вечно гулять между цилиндрами №1,2,3 = \n", n_travel);

		//	fprintf(fd, "### Число частиц, которые сразу вышли из усточника и не коснулись стенок %.0Lf\n", (long double)N5);
		////	fprintf(fd, "### Число частиц, которые хотя бы раз коснулись стенок и вышли из источника %.0Lf\n", (long double)N6);
		fprintf(fd, "### \n");
		fprintf(fd, "### N_out/N_in=%.5Lf\n", ((long double)N2_3 / (long double)N_on));
		fprintf(fd, "### L_3/R_3=%.5Lf\n", ((long double)L_3 / (long double)R1_3));
		fprintf(fd, "### k=(N_out/N_in)/(L_3/R_3)=%.5Lf\n", ((long double)N2_3 / (long double)N_on) / ((long double)L_3 / (long double)R1_3));
		fprintf(fd, "### \n");


		unsigned int search_time = end_time - start_time; // искомое время в миллисекундах
		unsigned int search_time_ = search_time / (1000 * 60); // минут
		unsigned int search_time__ = (search_time / 1000) % 60; // секунд


		fprintf(fd, "### Время выполнения расчета: %.0Lf мин. и %.0Lf сек.\n", (long double)search_time_, (long double)search_time__);
		fprintf(fd, "\n");



		fclose(fd);

	}



	// удаление двумерного динамического массива гистограммы
	for (size_t count = 0; count < arrlen(mass_histo_x); count++) {
		delete[] mass_histo_x[count];
	}

	delete[] mass_histo_x;


	mass_histo_x = nullptr;

	// удаление двумерного динамического массива гистограммы
	for (size_t count = 0; count < arrlen(mass_histo_r); count++) {
		delete[] mass_histo_r[count];
	}

	delete[] mass_histo_r;


	mass_histo_r = nullptr;



}








inline long double f(long double x, long double m, long double T, bool flaq_Maxwell_mode, long double drift_velocity, long double a, long double b) {






	long double f = 0.0;

	long double v1 = 0.0;
	long double v2 = 0.0;
	long double v3 = 0.0;
	long double v4 = 0.0;

	f = Maxwell_abs_speed(x, m, T, flaq_Maxwell_mode, drift_velocity) - 0.5* Max_Maxwell_abs_speed(m, T, flaq_Maxwell_mode, v1, v2, v3, v4, drift_velocity, a, b);

	return f;


}




void FWHM_maxwell(long double m, long double T, long double a, long double b, bool flaq_Maxwell_mode, long double &FWHM_delta, long double drift_velocity)
{

	long double FWHM_delta_numeric = 0.0;

	//cout << m << endl;

	long double tmp = 0.0, x0 = 0.0, x1 = 0.0, eps = pow(10.0, -4.0);
	int N = 0;

	long double v1 = 0.0;
	long double v2 = 0.0;

	const long double e = exp(1.0); // число Эйлера

	const long double k = 1.3806485279; // постоянная Больцмана/10^-23 , Дж/К
	const long double N_A = 6.02214085774; // постоянная Авогадро/10^23 , 1/моль
	const long double R_gas_constant = 8.314459845; // // Универсальная газовая постоянная , Дж/(моль*K)

	m = m * 0.0010735441498156322; // МэВ в а.е.м.

//	cout << "масса " <<m<< endl;

	m = m * N_A*1.6605402*pow(10.0, -4.0);

	drift_velocity = drift_velocity / 1000.0;
	



	if (flaq_Maxwell_mode == false) {



		x1 = pow(2.0*R_gas_constant*T / m, 1.0 / 2.0)*pow(10.0, 3.0);


	}

	else if (flaq_Maxwell_mode == true) {



		if (fabs(drift_velocity)<epsilon) {
			x1 = pow(3.0*R_gas_constant*T / m, 1.0 / 2.0)*pow(10.0, 3.0);

		}
		else {

			//x1 = pow(3.0*R_gas_constant*T / m, 1.0 / 2.0)*pow(10.0, 3.0);

		//	drift_velocity = drift_velocity / pow(10.0, 3.0);

			x1 = (drift_velocity / 2.0 + pow(3.0*R_gas_constant*T / m, 1.0 / 2.0)*pow(1.0 + m * pow(drift_velocity, 2.0) / (12.0*R_gas_constant*T), 1.0 / 2.0))*pow(10.0, 3.0);				    // наиболее вероятная скорость
		}


	}



	x0 = a;


	m = m / (N_A*1.6605402*pow(10.0, -4.0));
	drift_velocity = drift_velocity * 1000.0;

	//cout << x0 << "!!!" << x1 << endl;


	long double f1 = 0.0;
	long double f2 = 0.0;
	long double f3 = 0.0;
	long double t = 0.0;
	long double x = 0.0;
	do
	{
		f1 = f(x0, m, T, flaq_Maxwell_mode, drift_velocity, a, b);
		t = (x0 + x1) / 2.0;

		//cout << t << endl;
		f2 = f(t, m, T, flaq_Maxwell_mode, drift_velocity, a, b);

		f3 = f(x1, m, T, flaq_Maxwell_mode, drift_velocity, a, b);
		if (f1*f2 < 0) {
			x1 = t;
		}
		else if (f3*f2 < 0) {
			x0 = t;
		}
	
		
		
	//	else if (fabs(f1 - epsilon) < 0 || fabs(f2 - epsilon) < 0 || fabs(f3 - epsilon) < 0) {
	//
	//		break;
	 //
	//	}
	//	else {
	//		break;
	//	}



	} while (fabs(x1 - x0) > eps);


	x = (x0 + x1) / 2.0;


	//v1 = f(x, m, T, flaq_Maxwell_mode, drift_velocity, a, b);

	v1 = x;

	//cout<<" v1 " << v1 << endl;


	/*



	while (fabs(x1- x0) > eps)
	{
	x0 = x1 - (x1 -x0) * f(x1, m, T, flaq_Maxwell_mode) / (f(x1, m, T, flaq_Maxwell_mode) - f(x0, m, T, flaq_Maxwell_mode));
	x1= x0 + (x0 - x1) * f(x0, m, T, flaq_Maxwell_mode) / (f(x0, m, T, flaq_Maxwell_mode) - f(x1, m, T, flaq_Maxwell_mode));
	N = N + 1;
	//cout << x1 << endl;

	}


	*/

	// a - i-1, b - i-тый члены


//	v2 = x1;

//	N = 0;


	m = m * N_A*1.6605402*pow(10.0, -4.0);

	drift_velocity = drift_velocity / 1000.0;

	if (flaq_Maxwell_mode == false) {



		x0 = pow(2.0*R_gas_constant*T / m, 1.0 / 2.0)*pow(10.0, 3.0);


	}

	else if (flaq_Maxwell_mode == true) {



		//x0 = pow(3.0*R_gas_constant*T / m, 1.0 / 2.0)*pow(10.0, 3.0);

		//drift_velocity = drift_velocity / pow(10.0, 3.0);

		x0 = (drift_velocity / 2.0 + pow(3.0*R_gas_constant*T / m, 1.0 / 2.0)*pow(1.0 + m * pow(drift_velocity, 2.0) / (12.0*R_gas_constant*T), 1.0 / 2.0))*pow(10.0, 3.0);				    // наиболее вероятная скорость


	}

	x1 = b;

	//cout << x0 << "!!!" << x1 << endl;

	m = m / (N_A*1.6605402*pow(10.0, -4.0));

	drift_velocity = drift_velocity * 1000.0;


	f1 = 0.0;
	f2 = 0.0;
	t = 0.0;
	x = 0.0;
	do
	{
		f1 = f(x0, m, T, flaq_Maxwell_mode, drift_velocity,a,b);
		t = (x0 + x1) / 2.0;
		f2 = f(t, m, T, flaq_Maxwell_mode, drift_velocity,a,b);

		f3 = f(x1, m, T, flaq_Maxwell_mode, drift_velocity, a, b);
		if (f1*f2 <= 0) {
			x1 = t;
		}
		else if(f3*f2 <= 0) {
			x0 = t;
		}
		//else if (fabs(f1 - epsilon) < 0 || fabs(f2 - epsilon) < 0 || fabs(f3 - epsilon) < 0) {
	  //
		//break;
	 //
	//}
//	else {
	//	break;
	//}

	} while (fabs(x1 - x0) > eps);


	x = (x0 + x1) / 2.0;


	//v2 = f(x, m, T, flaq_Maxwell_mode, drift_velocity,a,b);


	v2 = x;

	//cout << " v2 " << v2 << endl;

	//	cout << x0 << "!!!" << x1 << endl;

	/*



	while (fabs(x1 - x0) > eps)
	{
	x0 = x1 - (x1 - x0) * f(x1, m, T, flaq_Maxwell_mode) / (f(x1, m, T, flaq_Maxwell_mode) - f(x0, m, T, flaq_Maxwell_mode));
	x1 = x0 + (x0 - x1) * f(x0, m, T, flaq_Maxwell_mode) / (f(x0, m, T, flaq_Maxwell_mode) - f(x1, m, T, flaq_Maxwell_mode));
	N = N + 1;

	//cout << x1 << endl;
	}

	*/

	// a - i-1, b - i-тый члены

	//v1 = x1;

	//cout << v1 << "!!!" << v2 << endl;

	
	
	


	FWHM_delta = fabs(v2 - v1);

//	FWHM_delta = fabs(v2 + v1);
	m = m * (N_A*1.6605402*pow(10.0, -4.0));

	drift_velocity = drift_velocity / 1000.0;

	if (flaq_Maxwell_mode == false) {

		FWHM_delta_numeric = 1.154942360251079*pow(2.0 * R_gas_constant*T / m, 1.0 / 2.0)*pow(10.0, 3.0);

		FWHM_delta = FWHM_delta_numeric;
	}
	else if (flaq_Maxwell_mode == true) {

		if (fabs(drift_velocity) < epsilon) {

			FWHM_delta_numeric = 1.1623761746298176*pow(2.0 * R_gas_constant*T / m, 1.0 / 2.0)*pow(10.0, 3.0);
			FWHM_delta = FWHM_delta_numeric;
		}
		else {

			FWHM_delta = FWHM_delta;
		}
	}


	//cout << FWHM_delta << endl;

}




void out_txt_V_0(const char *filename, long double **mass_histo_V_0, std::size_t normalization_V_0, long double a_V_0, long double b_V_0, std::size_t N_histo_V_0, long double x_title, long double y_title) {


	printf("Вывод надписей скоростей\n");
	printf("\n");

	long double h_V_0 = (b_V_0 - a_V_0) / N_histo_V_0; // ширина бина

	long double v_mean = 0.0; // средняя скорость
	long double v_square = 0.0; // средняя квадратичная скорость
	long double v_brobability = 0.0; // наиболее вероятная скорость
	long double v_median = 0.0; // медианная скорость скорость

	long double FWHM = 0.0;

	long double f = 0.0; // функция выпуклости
	long double g = 0.0; // функция выпуклости

	long double Integral = 0.0;

	long double *integral = new long double[N_histo_V_0]; // N_histo_V_0 строк в массиве




	for (size_t count = 1; count < arrlen(integral); count++) {


		integral[count] = integral[count - 1] + (long double)(mass_histo_V_0[count][0] / normalization_V_0);
		//	cout << integral[count][0] << endl;




	}






	// вывод полученных результатов в файл
	FILE *fd;

	fopen_s(&fd, filename, "wb");

	if (fd == NULL) {
		fprintf(stderr, "Ошибка открытия выводного файла.\n");
		cout << endl;
		SleepEx(40, true); // пауза для того, чтобы успеть прочитать информацию
		exit(1);
	}
	else {
		setlocale(LC_ALL, "rus"); // корректное отображение Кириллицы

		fprintf(fd, "\n");
		fprintf(fd, "### \n");
		//	fprintf(fd, "### Число Частиц в Бине штук || Нормированное Значение || Координата X Левого Конца Бина мм || Число Частиц в Бине штук || Нормированное Значение || Координата R Левого Конца Бина мм \n");
		fprintf(fd, "### \n");
		fprintf(fd, "\n");

		setlocale(LC_ALL, "C"); // установить используемую системой локаль для корректной отображении точки в выходном файле




		for (size_t i = 0; i < arrlen(mass_histo_V_0); i++) {


			fprintf(fd, "%.9Le %.9Le %.9Le %.9Le %.9Le\n", (long double)mass_histo_V_0[i][0], (long double)(pow(10.0, 3.0)*mass_histo_V_0[i][0] / (normalization_V_0*h_V_0)), (long double)(mass_histo_V_0[i][1] / h_V_0), normalization_V_0*mass_histo_V_0[i][1] / pow(10.0, 3.0), mass_histo_V_0[i][2]);

			v_mean = v_mean + (mass_histo_V_0[i][0] / normalization_V_0)*mass_histo_V_0[i][2];

			v_square = v_square + (mass_histo_V_0[i][0] / normalization_V_0)*pow(mass_histo_V_0[i][2], 2.0);

			Integral = Integral + (mass_histo_V_0[i][0] / normalization_V_0);



			if (integral[i] < 0.5 && integral[i + 1] >= 0.5) {

				v_median = mass_histo_V_0[i][2];

				//	cout << v_median << endl;
			}

			if ((i <= arrlen(mass_histo_V_0) - 10) && (i >= 10)) {


				/*


				if (Integral < 0.5 && Integral + (mass_histo_V_0[i + 1][0] / normalization_V_0) >= 0.5) {

				v_median = mass_histo_V_0[i][2];

				cout << v_median << endl;
				}

				*/


				f = (integral[i] * (mass_histo_V_0[i - 5][2] - mass_histo_V_0[i - 10][2]) + integral[i - 10] * (mass_histo_V_0[i][2] - mass_histo_V_0[i - 5][2])) / (mass_histo_V_0[i][2] - mass_histo_V_0[i - 10][2]);

				i = i + 1;

				g = (integral[i] * (mass_histo_V_0[i - 5][2] - mass_histo_V_0[i - 10][2]) + integral[i - 10] * (mass_histo_V_0[i][2] - mass_histo_V_0[i - 5][2])) / (mass_histo_V_0[i][2] - mass_histo_V_0[i - 10][2]);

				i = i - 1;


				if ((f - integral[i - 5] > 0) && (g - integral[i - 5 + 1] < 0)) {

					//cout << "!!!" << endl;

					v_brobability = mass_histo_V_0[i][2];

				}

			}


		}
		setlocale(LC_ALL, "rus"); // корректное отображение Кириллицы


		v_square = pow(v_square, 1.0 / 2.0);




		fclose(fd);

	}



	char string_name_1[256] = "/0";

	//char string_name_2[] =filename;



	strncpy_s(string_name_1, filename, strlen(filename) - 4);

	//strlen(string_name)


	strcat_s(string_name_1, "_title.txt");

	long double max1 = y_title - 0.0*(0.5*y_title / 4.0);
	long double max2 = y_title - 1.0*(0.5*y_title / 4.0);
	long double max3 = y_title - 2.0*(0.5*y_title / 4.0);
	long double max4 = y_title - 3.0*(0.5*y_title / 4.0);
	long double max5 = y_title - 4.0*(0.5*y_title / 4.0);

	// вывод полученных результатов в файл
	FILE *fd1;

	fopen_s(&fd1, string_name_1, "wb");

	if (fd1 == NULL) {
		fprintf(stderr, "Ошибка открытия выводного файла.\n");
		cout << endl;
		SleepEx(40, true); // пауза для того, чтобы успеть прочитать информацию
		exit(1);
	}
	else {
		setlocale(LC_ALL, "rus"); // корректное отображение Кириллицы

		fprintf(fd1, "\n");
		fprintf(fd1, "### \n");
		//	fprintf(fd, "### Число Частиц в Бине штук || Нормированное Значение || Координата X Левого Конца Бина мм || Число Частиц в Бине штук || Нормированное Значение || Координата R Левого Конца Бина мм \n");
		fprintf(fd1, "### \n");
		fprintf(fd1, "\n");

		setlocale(LC_ALL, "C"); // установить используемую системой локаль для корректной отображении точки в выходном файле


		fprintf(fd1, "%.9Le %.9Le \"Наиболее вероятная скорость=%.2Le мм/c\" \n", x_title, max1, v_brobability);

		fprintf(fd1, "%.9Le %.9Le \"Медианная скорость=%.2Le мм/c\" \n", x_title, max2, v_median);

		fprintf(fd1, "%.9Le %.9Le \"Средняя скорость=%.2Le мм/c\" \n", x_title, max3, v_mean);

		fprintf(fd1, "%.9Le %.9Le \"Среднеквадратичная скорость=%.2Le мм/c\" \n", x_title, max4, v_square);

		fprintf(fd1, "%.9Le %.9Le \"Ширина на полувысоте=%.2Le мм/c\" \n", x_title, max5, FWHM);

		setlocale(LC_ALL, "rus"); // корректное отображение Кириллицы

		fclose(fd1);

	}




	// удаление двумерного динамического массива гистограммы
	for (size_t count = 0; count < arrlen(mass_histo_V_0); count++) {
		delete[] mass_histo_V_0[count];
	}

	delete[] mass_histo_V_0;


	mass_histo_V_0 = nullptr;

	delete[] integral;

	integral = nullptr;

}


void out_txt_time(const char *filename, long double **mass_histo_time, std::size_t normalization_time, long double a_time, long double b_time, std::size_t N_histo_time, long double x_title, long double y_title) {

	printf("Вывод времени пролета\n");
	printf("\n");


	long double h_time = (b_time - a_time) / N_histo_time; // ширина бина

	long double time_mean = 0.0; // средняя скорость
	long double time_square = 0.0; // средняя квадратичная скорость
	long double time_brobability = 0.0; // наиболее вероятная скорость
	long double time_median = 0.0; // медианная скорость скорость





	long double FWHM = 0.0;

	long double f = 0.0; // функция выпуклости
	long double g = 0.0; // функция выпуклости

	long double Integral = 0.0;

	long double *integral = new long double[N_histo_time]; // N_histo_V_0 строк в массиве


	integral[0] = (mass_histo_time[0][0] / (normalization_time*h_time));

	for (size_t count = 1; count < arrlen(integral); count++) {


		integral[count] = integral[count - 1] + (long double)(mass_histo_time[count][0] / (normalization_time));
		//	cout << integral[count][0] << endl;




	}






	// вывод полученных результатов в файл
	FILE *fd;

	fopen_s(&fd, filename, "wb");

	if (fd == NULL) {
		fprintf(stderr, "Ошибка открытия выводного файла.\n");
		cout << endl;
		SleepEx(40, true); // пауза для того, чтобы успеть прочитать информацию
		exit(1);
	}
	else {
		setlocale(LC_ALL, "rus"); // корректное отображение Кириллицы

		fprintf(fd, "\n");
		fprintf(fd, "### \n");
		//	fprintf(fd, "### Число Частиц в Бине штук || Нормированное Значение || Координата X Левого Конца Бина мм || Число Частиц в Бине штук || Нормированное Значение || Координата R Левого Конца Бина мм \n");
		fprintf(fd, "### \n");
		fprintf(fd, "\n");

		setlocale(LC_ALL, "C"); // установить используемую системой локаль для корректной отображении точки в выходном файле




		for (size_t i = 0; i < arrlen(mass_histo_time); i++) {


			fprintf(fd, "%.9Le %.9Le %.9Le %.9Le %.9Le\n", (long double)mass_histo_time[i][0], (long double)(mass_histo_time[i][0] / (normalization_time*h_time)), (long double)(mass_histo_time[i][1] / h_time), normalization_time*mass_histo_time[i][1], pow(10.0, 3.0)*mass_histo_time[i][2]);

			time_mean = time_mean + (mass_histo_time[i][0] / normalization_time)*mass_histo_time[i][2];

			time_square = time_square + (mass_histo_time[i][0] / normalization_time)*pow(mass_histo_time[i][2], 2.0);

			Integral = Integral + (mass_histo_time[i][0] / (normalization_time));



			if (integral[i] < 0.5 && integral[i + 1] >= 0.5) {

				time_median = mass_histo_time[i][2];

				//	cout << v_median << endl;
			}

			if ((i <= arrlen(mass_histo_time) - 10) && (i >= 10)) {


				/*


				if (Integral < 0.5 && Integral + (mass_histo_V_0[i + 1][0] / normalization_V_0) >= 0.5) {

				v_median = mass_histo_V_0[i][2];

				cout << v_median << endl;
				}

				*/


				f = (integral[i] * (mass_histo_time[i - 5][2] - mass_histo_time[i - 10][2]) + integral[i - 10] * (mass_histo_time[i][2] - mass_histo_time[i - 5][2])) / (mass_histo_time[i][2] - mass_histo_time[i - 10][2]);

				i = i + 1;

				g = (integral[i] * (mass_histo_time[i - 5][2] - mass_histo_time[i - 10][2]) + integral[i - 10] * (mass_histo_time[i][2] - mass_histo_time[i - 5][2])) / (mass_histo_time[i][2] - mass_histo_time[i - 10][2]);

				i = i - 1;


				if (signum((f - integral[i - 5]) * (g - integral[i - 5 + 1])) < 0) {

					//cout << "!!!" << endl;

					time_brobability = mass_histo_time[i][2];

				}

			}


		}
		setlocale(LC_ALL, "rus"); // корректное отображение Кириллицы


		time_square = pow(time_square, 1.0 / 2.0);




		fclose(fd);

	}



	char string_name_1[256] = "/0";

	//char string_name_2[] =filename;

	strncpy_s(string_name_1, filename, strlen(filename) - 4);

	//strlen(string_name)


	strcat_s(string_name_1, "_title.txt");

	long double max1 = y_title - 0.0*(0.5*y_title / 4.0);
	long double max2 = y_title - 1.0*(0.5*y_title / 4.0);
	long double max3 = y_title - 2.0*(0.5*y_title / 4.0);
	long double max4 = y_title - 3.0*(0.5*y_title / 4.0);
	long double max5 = y_title - 4.0*(0.5*y_title / 4.0);

	// вывод полученных результатов в файл
	FILE *fd1;

	fopen_s(&fd1, string_name_1, "wb");

	if (fd1 == NULL) {
		fprintf(stderr, "Ошибка открытия выводного файла.\n");
		cout << endl;
		SleepEx(40, true); // пауза для того, чтобы успеть прочитать информацию
		exit(1);
	}
	else {
		setlocale(LC_ALL, "rus"); // корректное отображение Кириллицы

		fprintf(fd1, "\n");
		fprintf(fd1, "### \n");
		//	fprintf(fd, "### Число Частиц в Бине штук || Нормированное Значение || Координата X Левого Конца Бина мм || Число Частиц в Бине штук || Нормированное Значение || Координата R Левого Конца Бина мм \n");
		fprintf(fd1, "### \n");
		fprintf(fd1, "\n");

		setlocale(LC_ALL, "C"); // установить используемую системой локаль для корректной отображении точки в выходном файле


		fprintf(fd1, "%.9Le %.9Le \"Наиболее вероятное время=%.2Lf мс\" \n", x_title, max1, pow(10.0, 3.0)*time_brobability);

		fprintf(fd1, "%.9Le %.9Le \"Медианное время=%.2Lf мс\" \n", x_title, max2, pow(10.0, 3.0)*time_median);

		fprintf(fd1, "%.9Le %.9Le \"Среднее время=%.2Lf мс\" \n", x_title, max3, pow(10.0, 3.0)*time_mean);

		fprintf(fd1, "%.9Le %.9Le \"Среднеквадратичное время=%.2Lf мс\" \n", x_title, max4, pow(10.0, 3.0)*time_square);

		fprintf(fd1, "%.9Le %.9Le \"Ширина на полувысоте=%.2Lf мс\" \n", x_title, max5, pow(10.0, 3.0)*FWHM);

		setlocale(LC_ALL, "rus"); // корректное отображение Кириллицы

		fclose(fd1);

	}




	// удаление двумерного динамического массива гистограммы
	for (size_t count = 0; count < arrlen(mass_histo_time); count++) {
		delete[] mass_histo_time[count];
	}

	delete[] mass_histo_time;


	mass_histo_time = nullptr;

	delete[] integral;

	integral = nullptr;

}



void out_txt_theta_in(const char *filename, long double **mass_histo_theta_in, std::size_t normalization_theta_in, long double h_theta_in, long double A_theta_intensity) {

	printf("Вывод углов на входе\n");
	printf("\n");

	// вывод полученных результатов в файл
	FILE *fd;

	fopen_s(&fd, filename, "wb");

	if (fd == NULL) {
		fprintf(stderr, "Ошибка открытия выводного файла.\n");
		cout << endl;
		SleepEx(40, true); // пауза для того, чтобы успеть прочитать информацию
		exit(1);
	}
	else {
		setlocale(LC_ALL, "rus"); // корректное отображение Кириллицы

		fprintf(fd, "\n");
		fprintf(fd, "### \n");
		//	fprintf(fd, "### Число Частиц в Бине штук || Нормированное Значение || Координата X Левого Конца Бина мм || Число Частиц в Бине штук || Нормированное Значение || Координата R Левого Конца Бина мм \n");
		fprintf(fd, "### \n");
		fprintf(fd, "\n");

		setlocale(LC_ALL, "C"); // установить используемую системой локаль для корректной отображении точки в выходном файле

	//	long double A_theta_intensity = 2.0*gamma(n_cos_intensity / 2.0 + 1.0) / (pow(M_PI, 1.0 / 2.0)*gamma((n_cos_intensity + 1.0) / 2.0));


		for (size_t i = 0; i < arrlen(mass_histo_theta_in); i++) {


			fprintf(fd, "%.9Le %.9Le %.9Le %.9Le %.9Le %.9Le\n", mass_histo_theta_in[i][0], 2.0*mass_histo_theta_in[i][0] / (normalization_theta_in*h_theta_in*A_theta_intensity), mass_histo_theta_in[i][1] / (h_theta_in*A_theta_intensity), normalization_theta_in*mass_histo_theta_in[i][1] / 2.0, mass_histo_theta_in[i][2], mass_histo_theta_in[i][3]);
			//fprintf(fd, "%.9Le %.9Le %.9Le %.9Le %.9Le %.9Le\n", (long double)mass_histo_theta_in[i][0] / sin((long double)mass_histo_theta_in[i][2]), (long double)mass_histo_theta_in[i][0] / normalization_theta_in / sin((long double)mass_histo_theta_in[i][2]), mass_histo_theta_in[i][1] , normalization_theta_in*mass_histo_theta_in[i][1], mass_histo_theta_in[i][2] , mass_histo_theta_in[i][3]);


		}
		setlocale(LC_ALL, "rus"); // корректное отображение Кириллицы





		fclose(fd);

	}



	// удаление двумерного динамического массива гистограммы
	for (size_t count = 0; count < arrlen(mass_histo_theta_in); count++) {
		delete[] mass_histo_theta_in[count];
	}

	delete[] mass_histo_theta_in;


	mass_histo_theta_in = nullptr;



}



// вывод характерных скоростей в файл для отображения на графике
void out_txt_V_title(const char *filename, long double v1, long double v2, long double v3, long double v4, long double FWHM, long double x_title, long double y_title) {

	printf("Вывод надписей скоростей\n");
	printf("\n");

	long double max1 = y_title - 0.0*(0.5*y_title / 4.0);
	long double max2 = y_title - 1.0*(0.5*y_title / 4.0);
	long double max3 = y_title - 2.0*(0.5*y_title / 4.0);
	long double max4 = y_title - 3.0*(0.5*y_title / 4.0);
	long double max5 = y_title - 4.0*(0.5*y_title / 4.0);


	// вывод полученных результатов в файл
	FILE *fd;

	fopen_s(&fd, filename, "wb");

	if (fd == NULL) {
		fprintf(stderr, "Ошибка открытия выводного файла.\n");
		cout << endl;
		SleepEx(40, true); // пауза для того, чтобы успеть прочитать информацию
		exit(1);
	}
	else {
		setlocale(LC_ALL, "rus"); // корректное отображение Кириллицы

		fprintf(fd, "\n");
		fprintf(fd, "### \n");
		//	fprintf(fd, "### Число Частиц в Бине штук || Нормированное Значение || Координата X Левого Конца Бина мм || Число Частиц в Бине штук || Нормированное Значение || Координата R Левого Конца Бина мм \n");
		fprintf(fd, "### \n");
		fprintf(fd, "\n");

		setlocale(LC_ALL, "C"); // установить используемую системой локаль для корректной отображении точки в выходном файле


		fprintf(fd, "%.3Lf %.9Le \"Наиболее вероятная скорость=%.2Lf м/c\" \n", x_title / 1000.0, max1, v1/1000.0);

		fprintf(fd, "%.9Le %.9Le \"Медианная скорость=%.2Lf м/c\" \n", x_title / 1000.0, max2, v4 / 1000.0);

		fprintf(fd, "%.9Le %.9Le \"Средняя скорость=%.2Lf м/c\" \n", x_title / 1000.0, max3, v2 / 1000.0);

		fprintf(fd, "%.9Le %.9Le \"Среднеквадратичная скорость=%.2Lf м/c\" \n", x_title / 1000.0, max4, v3 / 1000.0);

		fprintf(fd, "%.9Le %.9Le \"Ширина на полувысоте=%.2Lf м/c\" \n", x_title / 1000.0, max5, FWHM / 1000.0);

		setlocale(LC_ALL, "rus"); // корректное отображение Кириллицы

		fclose(fd);

	}


}



// вывод траеторий частиц в магните в файл
void out_txt_traectory_mag(const char *filename, const vector<long double> &Vector_r_mag, const vector<long double> &Vector_z_mag, long double L_mag, const vector<long double> &Vector_x_mag, const vector<long double> &Vector_y_mag, const vector<long double>&Vector_color_mag, const vector<long double> &Vector_rr_mag, const vector<long double> &Vector_out_mag, const vector<long double> &Vector_phi_mag, const vector<long double> &Vector_psi_mag, const vector<long double> &Vector_theta_mag, const vector<long double> &Vector_v_x_mag,
	const vector<long double> &Vector_v_y_mag, const vector<long double>&Vector_v_z_mag, const vector<long double> &Vector_v_r_mag, const vector<long double> &Vector_v_phi_mag, const vector<long double> &Vector_v_perp_mag, const vector<long double> &Vector_v_0_mag, const vector<long double> &Vector_force_mag, const vector<long double> &Vector_condition_color_mag, const vector<long double> &Vector_mu_mag, const vector<long double> &Vector_B_mag) {

	printf("Вывод траеторий в магните\n");
	printf("\n");

	// Сохраняем количество элементов вектора 
	size_t vector_size = Vector_z_mag.size();








	// вывод полученных результатов в файл
	FILE *fd;

	fopen_s(&fd, filename, "wb");

	if (fd == NULL) {
		fprintf(stderr, "Ошибка открытия выводного файла.\n");
		cout << endl;
		SleepEx(40, true); // пауза для того, чтобы успеть прочитать информацию
		exit(1);
	}
	else {
		setlocale(LC_ALL, "rus"); // корректное отображение Кириллицы

		fprintf(fd, "\n");
		fprintf(fd, "### \n");
		//	fprintf(fd, "### Число Частиц в Бине штук || Нормированное Значение || Координата X Левого Конца Бина мм || Число Частиц в Бине штук || Нормированное Значение || Координата R Левого Конца Бина мм \n");
		fprintf(fd, "### \n");
		fprintf(fd, "\n");

		setlocale(LC_ALL, "C"); // установить используемую системой локаль для корректной отображении точки в выходном файле


		for (size_t i = 0; i < vector_size; i++) {

			fprintf(fd, "%.9Le %.9Le %.9Le %.9Le %.9Le %.9Le %.9Le %.9Le %.9Le %.9Le %.9Le %.9Le %.9Le %.9Le %.9Le %.9Le %.9Le %.9Le %.9Le %.9Le\n", Vector_r_mag[i], Vector_z_mag[i], Vector_x_mag[i], Vector_y_mag[i], Vector_color_mag[i], Vector_rr_mag[i], Vector_phi_mag[i], Vector_psi_mag[i], Vector_theta_mag[i], Vector_v_x_mag[i], Vector_v_y_mag[i], Vector_v_z_mag[i], Vector_v_r_mag[i], Vector_v_phi_mag[i], Vector_v_perp_mag[i], Vector_v_0_mag[i], Vector_force_mag[i], Vector_condition_color_mag[i], Vector_mu_mag[i], Vector_B_mag[i]);
			if (fabs(Vector_z_mag[i] - L_mag) <= epsilon && Vector_out_mag[i] == 1.0) { //-V550
				fprintf(fd, "\n");
				fprintf(fd, "\n");

			}

		}




		setlocale(LC_ALL, "rus"); // корректное отображение Кириллицы

		fclose(fd);

	}


}




// вывод траеторий частиц в магните в файл
void out_txt_traectory_cyl_one(const char *filename, const vector<long double> &Vector_r_cyl, const vector<long double> &Vector_z_cyl, long double L_cyl, const vector<long double> &Vector_x_cyl, const vector<long double> &Vector_y_cyl, const vector<long double>&Vector_color_cyl, const vector<long double> &Vector_rr_cyl,
	const vector<long double> &Vector_out_cyl, const vector<long double> &Vector_phi_cyl, const vector<long double> &Vector_psi_cyl, const vector<long double> &Vector_theta_cyl, const vector<long double> &Vector_v_x_cyl, const vector<long double> &Vector_v_y_cyl, const vector<long double> &Vector_v_z_cyl, const vector<long double> &Vector_v_r_cyl,
	const vector<long double> &Vector_v_phi_cyl, const vector<long double> &Vector_v_perp_cyl, const vector<long double> &Vector_v_0_cyl, const vector<long double> &Vector_force_cyl, const vector<long double> &Vector_condition_color_cyl, const vector<long double> &Vector_mu_cyl, const vector<long double> &Vector_B_cyl) {


	printf("Вывод траеторий в цилиндре\n");
	printf("\n");
	// Сохраняем количество элементов вектора 
	size_t vector_size = Vector_z_cyl.size();








	// вывод полученных результатов в файл
	FILE *fd;

	fopen_s(&fd, filename, "wb");

	if (fd == NULL) {
		fprintf(stderr, "Ошибка открытия выводного файла.\n");
		cout << endl;
		SleepEx(40, true); // пауза для того, чтобы успеть прочитать информацию
		exit(1);
	}
	else {
		setlocale(LC_ALL, "rus"); // корректное отображение Кириллицы

		fprintf(fd, "\n");
		fprintf(fd, "### \n");
		//	fprintf(fd, "### Число Частиц в Бине штук || Нормированное Значение || Координата X Левого Конца Бина мм || Число Частиц в Бине штук || Нормированное Значение || Координата R Левого Конца Бина мм \n");
		fprintf(fd, "### \n");
		fprintf(fd, "\n");

		setlocale(LC_ALL, "C"); // установить используемую системой локаль для корректной отображении точки в выходном файле


		for (size_t i = 0; i < vector_size; i++) {

			fprintf(fd, "%.9Le %.9Le %.9Le %.9Le %.9Le %.9Le %.9Le %.9Le %.9Le %.9Le %.9Le %.9Le %.9Le %.9Le %.9Le %.9Le %.9Le %.9Le %.9Le %.9Le\n", Vector_r_cyl[i], Vector_z_cyl[i], Vector_x_cyl[i], Vector_y_cyl[i], Vector_color_cyl[i], Vector_rr_cyl[i], Vector_phi_cyl[i], Vector_psi_cyl[i], Vector_theta_cyl[i], Vector_v_x_cyl[i], Vector_v_y_cyl[i], Vector_v_z_cyl[i], Vector_v_r_cyl[i], Vector_v_phi_cyl[i], Vector_v_perp_cyl[i], Vector_v_0_cyl[i], Vector_force_cyl[i], Vector_condition_color_cyl[i], Vector_mu_cyl[i], Vector_B_cyl[i]);
			if (fabs(Vector_z_cyl[i] - L_cyl) <= epsilon && Vector_out_cyl[i] == 1.0) { //-V550
				fprintf(fd, "\n");
				fprintf(fd, "\n");

			}

		}




		setlocale(LC_ALL, "rus"); // корректное отображение Кириллицы

		fclose(fd);

	}


}






// вывод траеторий частиц в магните в файл
void out_txt_traectory_CYL(const char *filename, const vector<long double> &Vector_x, const vector<long double> &Vector_y, const vector<long double> &Vector_z, const vector<long double> &Vector_r, long double L_CYL, const vector<long double>&Vector_color_trajectory_cyl, const vector<long double> &Vector_rr, size_t N_mag_partitions, bool on_off_mag_1, bool on_off_mag_2, bool on_off_mag_3, bool on_off_mag_4, bool on_off_mag_5, bool on_off_mag_6, bool on_off_mag_7, long double R_source, size_t N_CYL_partitions, std::size_t i_Collision_all_1, std::size_t i_Collision_all_2, std::size_t i_Collision_all_3, std::size_t i_Collision_all_4, std::size_t i_Collision_all_5, std::size_t i_Collision_all_6, std::size_t i_Collision_all_7, const vector<long double> &Vector_out_trajectory_cyl,
	const vector<long double> &Vector_phi, const vector<long double> &Vector_psi, const vector<long double> &Vector_theta, const vector<long double> &Vector_v_x, const vector<long double> &Vector_v_y, const vector<long double> &Vector_v_z, const vector<long double> &Vector_v_r, const vector<long double> &Vector_v_phi, const vector<long double> &Vector_v_perp, const vector<long double> &Vector_v_0, const vector<long double> &Vector_force, const vector<long double> &Vector_condition_color, const vector<long double> &Vector_mu, const vector<long double> &Vector_B) {

	printf("Вывод траеторий во всех цилиндрах\n");
	printf("\n");

	// Сохраняем количество элементов вектора 
	size_t vector_size = Vector_z.size();
 /*
 
 
	int index = 0;

	if (on_off_mag_1 == true && on_off_mag_2 == true && on_off_mag_3 == true) {

		index = 3;

	}

	if (on_off_mag_1 == true && on_off_mag_2 == true && on_off_mag_3 == false) {

		index = 2;

	}

	if (on_off_mag_1 == true && on_off_mag_2 == false && on_off_mag_3 == true) {

		index = 2;

	}

	if (on_off_mag_1 == true && on_off_mag_2 == false && on_off_mag_3 == false) {

		index = 1;

	}


	if (on_off_mag_1 == false && on_off_mag_2 == true && on_off_mag_3 == true) {

		index = 2;

	}

	if (on_off_mag_1 == false && on_off_mag_2 == true && on_off_mag_3 == false) {

		index = 1;

	}


	if (on_off_mag_1 == false && on_off_mag_2 == false && on_off_mag_3 == true) {

		index = 1;

	}


	if (on_off_mag_1 == false && on_off_mag_2 == false && on_off_mag_3 == false) {

		index = 0;

	}

	*/


	// вывод полученных результатов в файл
	FILE *fd;

	fopen_s(&fd, filename, "wb");

	if (fd == NULL) {
		fprintf(stderr, "Ошибка открытия выводного файла.\n");
		cout << endl;
		SleepEx(40, true); // пауза для того, чтобы успеть прочитать информацию
		exit(1);
	}
	else {
		setlocale(LC_ALL, "rus"); // корректное отображение Кириллицы

		fprintf(fd, "\n");
		fprintf(fd, "### \n");
		//	fprintf(fd, "### Число Частиц в Бине штук || Нормированное Значение || Координата X Левого Конца Бина мм || Число Частиц в Бине штук || Нормированное Значение || Координата R Левого Конца Бина мм \n");
		fprintf(fd, "### \n");
		fprintf(fd, "\n");

		setlocale(LC_ALL, "C"); // установить используемую системой локаль для корректной отображении точки в выходном файле

								//i + 3 + index*(N_mag_partitions + 1 + N_CYL_partitions) + 3 * N_CYL_partitions + N_CYL_partitions*(i_Collision_all_1 + i_Collision_all_2 + i_Collision_all_3 - 3)

								//#pragma omp parallel
								//	{

		size_t jj = 0;

		for (size_t i = 0; i < vector_size; i = i + 1) {

			//	fprintf(fd, "%.3Lf %.3Lf %.3Lf %.3Lf %.3Lf %.3Lf\n", Vector_x[i], Vector_y[i], Vector_z[i], Vector_r[i], Vector_color_trajectory_cyl[i], Vector_rr[i]);

			if (Vector_r[i] <= R_source && fabs(Vector_z[i] - L_CYL) <= epsilon && Vector_out_trajectory_cyl[i] == 1.0) { //-V550

				for (size_t j = jj; j <= i; j = j + 1) {

					if (Vector_color_trajectory_cyl[j] != 0.0) { //-V550

						if (j % 2 == 0) {

							fprintf(fd, "%.9Le %.9Le %.9Le %.9Le %.9Le %.9Le %.9Le %.9Le %.9Le %.9Le %.9Le %.9Le %.9Le %.9Le %.9Le %.9Le %.9Le %.9Le %.9Le %.9Le\n", Vector_x[j], Vector_y[j], Vector_z[j], Vector_r[j], Vector_color_trajectory_cyl[j], Vector_rr[j], Vector_phi[j], Vector_psi[j], Vector_theta[j], Vector_v_x[j], Vector_v_y[j], Vector_v_z[j], Vector_v_r[j], Vector_v_phi[j], Vector_v_perp[j], Vector_v_0[j], Vector_force[j], Vector_condition_color[j], Vector_mu[j], Vector_B[j]);
						}

						else {

							fprintf(fd, "%.9Le %.9Le %.9Le %.9Le %.6e %.9Le %.9Le %.9Le %.9Le %.9Le %.9Le %.9Le %.9Le %.9Le %.9Le %.9Le %.9Le %.9Le %.9Le %.9Le\n", Vector_x[j], Vector_y[j], Vector_z[j], Vector_r[j], 44.0, Vector_rr[j], Vector_phi[j], Vector_psi[j], Vector_theta[j], Vector_v_x[j], Vector_v_y[j], Vector_v_z[j], Vector_v_r[j], Vector_v_phi[j], Vector_v_perp[j], Vector_v_0[j], Vector_force[j], Vector_condition_color[j], Vector_mu[j], Vector_B[j]);
						}


					}

					if ((Vector_color_trajectory_cyl[j] == 0.0)) { //-V550


						//	fprintf(fd, "%.9Le %.9Le %.9Le %.9Le %.6f %.9Le %.9Le %.9Le %.9Le %.9Le %.9Le %.9Le %.9Le %.9Le %.9Le %.9Le %.9Le %.9Le\n", Vector_x[j], Vector_y[j], Vector_z[j], Vector_r[j], 4.0, Vector_rr[j], Vector_phi[j], Vector_psi[j], Vector_theta[j], Vector_v_x[j], Vector_v_y[j], Vector_v_z[j], Vector_v_r[j], Vector_v_phi[j], Vector_v_perp[j], Vector_v_0[j], Vector_force[j], Vector_condition_color[j]);

						if (j % 2 == 0) {

							fprintf(fd, "%.9Le %.9Le %.9Le %.9Le %.9Le %.9Le %.9Le %.9Le %.9Le %.9Le %.9Le %.9Le %.9Le %.9Le %.9Le %.9Le %.9Le %.9Le %.9Le %.9Le\n", Vector_x[j], Vector_y[j], Vector_z[j], Vector_r[j], (long double) 44.0, Vector_rr[j], Vector_phi[j], Vector_psi[j], Vector_theta[j], Vector_v_x[j], Vector_v_y[j], Vector_v_z[j], Vector_v_r[j], Vector_v_phi[j], Vector_v_perp[j], Vector_v_0[j], Vector_force[j], (long double) 44.0, Vector_mu[j], Vector_B[j]);
						}

						else {

							fprintf(fd, "%.9Le %.9Le %.9Le %.9Le %.6Le %.9Le %.9Le %.9Le %.9Le %.9Le %.9Le %.9Le %.9Le %.9Le %.9Le %.9Le %.9Le %.9Le %.9Le %.9Le\n", Vector_x[j], Vector_y[j], Vector_z[j], Vector_r[j], (long double) 44.0, Vector_rr[j], Vector_phi[j], Vector_psi[j], Vector_theta[j], Vector_v_x[j], Vector_v_y[j], Vector_v_z[j], Vector_v_r[j], Vector_v_phi[j], Vector_v_perp[j], Vector_v_0[j], Vector_force[j], Vector_condition_color[j], Vector_mu[j], Vector_B[j]);
						}


					}


					if (fabs(Vector_z[j] - L_CYL) <= epsilon && Vector_out_trajectory_cyl[j] == 1.0) { //-V550
						fprintf(fd, "\n");
						fprintf(fd, "\n");


					}

					i = j;

				}


				jj = i + 1;

			}

			if (Vector_r[i] > R_source && fabs(Vector_z[i] - L_CYL) <= epsilon && Vector_out_trajectory_cyl[i] == 1.0) { //-V550

				for (size_t j = jj; j <= i; j = j + 1) {


					fprintf(fd, "%.9Le %.9Le %.9Le %.9Le %.9Le %.9Le %.9Le %.9Le %.9Le %.9Le %.9Le %.9Le %.9Le %.9Le %.9Le %.9Le %.9Le %.9Le %.9Le %.9Le\n", Vector_x[j], Vector_y[j], Vector_z[j], Vector_r[j], Vector_color_trajectory_cyl[j], Vector_rr[j], Vector_phi[j], Vector_psi[j], Vector_theta[j], Vector_v_x[j], Vector_v_y[j], Vector_v_z[j], Vector_v_r[j], Vector_v_phi[j], Vector_v_perp[j], Vector_v_0[j], Vector_force[j], Vector_condition_color[j], Vector_mu[j], Vector_B[j]);


					if (fabs(Vector_z[j] - L_CYL) <= epsilon && Vector_out_trajectory_cyl[j] == 1.0) { //-V550

						fprintf(fd, "\n");
						fprintf(fd, "\n");

					}

					//fprintf(fd, "%.3Lf %.3Lf %.3Lf %.3Lf %.3Lf %.3Lf\n", Vector_x[j], Vector_y[j], Vector_z[j], Vector_r[j], 4.0, Vector_rr[j]);


					i = j;
				}



				jj = i + 1;

			}



		}


		//	fprintf(fd, "\n");
		//	fprintf(fd, "\n");

		/*


		fprintf(fd, "### \n");
		fprintf(fd, "### \n");

		unsigned int jj = 0;
		for (unsigned int i = 0; i < vector_size; i = i + 1) {


		if (Vector_r[i] <= R_source && Vector_z[i] == L_CYL) {

		for (unsigned int j = jj; j <= i; j = j + 1) {

		if (Vector_color_trajectory_cyl[j] != 0.0) {

		if ((int)j % 3 == 0) {

		//	fprintf(fd, "%.3Lf %.3Lf %.3Lf %.3Lf %.3Lf %.3Lf\n", Vector_x[j], Vector_y[j], Vector_z[j], Vector_r[j], Vector_color_trajectory_cyl[j], Vector_rr[j]);
		}

		else {

		//	fprintf(fd, "%.3Lf %.3Lf %.3Lf %.3Lf %.3f %.3Lf\n", Vector_x[j], Vector_y[j], Vector_z[j], Vector_r[j], 4.0, Vector_rr[j]);
		}


		}

		if ((Vector_color_trajectory_cyl[j] == 0.0)) {


		//fprintf(fd, "%.3Lf %.3Lf %.3Lf %.3Lf %.3f %.3Lf\n", Vector_x[j], Vector_y[j], Vector_z[j], Vector_r[j], 4.0, Vector_rr[j]);


		}

		if (Vector_z[j] == L_CYL) {
		//fprintf(fd, "\n");
		//fprintf(fd, "\n");


		}




		//fprintf(fd, "%.3Lf %.3Lf %.3Lf %.3Lf %.3Lf %.3Lf\n", Vector_x[j], Vector_y[j], Vector_z[j], Vector_r[j], 4.0, Vector_rr[j]);

		//		if (Vector_z[j] == 0.0) {

		//		break;
		//	}





		*/


		//	}





		//		}


		/*

		if (Vector_r[i] > R_source && Vector_z[i] == L_CYL) {

		for (unsigned int j = jj; j <= i; j = j + 1) {


		//	fprintf(fd, "%.3Lf %.3Lf %.3Lf %.3Lf %.3Lf %.3Lf\n", Vector_x[j], Vector_y[j], Vector_z[j], Vector_r[j], Vector_color_trajectory_cyl[j], Vector_rr[j]);


		if (Vector_z[j] == L_CYL) {
		//	fprintf(fd, "\n");
		//	fprintf(fd, "\n");

		}

		//fprintf(fd, "%.3Lf %.3Lf %.3Lf %.3Lf %.3Lf %.3Lf\n", Vector_x[j], Vector_y[j], Vector_z[j], Vector_r[j], 4.0, Vector_rr[j]);

		}


		}



		jj = i;

		}
		//	}

		}

		*/


		setlocale(LC_ALL, "rus"); // корректное отображение Кириллицы

		fclose(fd);

	}

}





// вывод траеторий частиц в магните в файл
void out_txt_traectory_CYL_angular(const char *filename, const vector<long double> &Vector_z, const vector<long double> &Vector_r, long double L_CYL, const vector<long double>&Vector_color_trajectory_cyl, size_t N_cyl_partitions, size_t N_mag_partitions, bool on_off_mag_1, bool on_off_mag_2, bool on_off_mag_3, bool on_off_mag_4, bool on_off_mag_5, bool on_off_mag_6, bool on_off_mag_7, long double R_source, size_t N_CYL_partitions, std::size_t i_Collision_all_1, std::size_t i_Collision_all_2, std::size_t i_Collision_all_3, std::size_t i_Collision_all_4, std::size_t i_Collision_all_5, std::size_t i_Collision_all_6, std::size_t i_Collision_all_7, const vector<long double> &Vector_out_trajectory_cyl, const vector<long double> &Vector_angular) {

	printf("Вывод углов\n");
	printf("\n");

	// Сохраняем количество элементов вектора 
	size_t vector_size = Vector_z.size();


	long double epsilon_angular = 2.0*M_PI / min(N_mag_partitions, N_cyl_partitions);

	/*
	
	

	int index = 0;

	if (on_off_mag_1 == true && on_off_mag_2 == true && on_off_mag_3 == true) {

		index = 3;

	}

	if (on_off_mag_1 == true && on_off_mag_2 == true && on_off_mag_3 == false) {

		index = 2;

	}

	if (on_off_mag_1 == true && on_off_mag_2 == false && on_off_mag_3 == true) {

		index = 2;

	}

	if (on_off_mag_1 == true && on_off_mag_2 == false && on_off_mag_3 == false) {

		index = 1;

	}


	if (on_off_mag_1 == false && on_off_mag_2 == true && on_off_mag_3 == true) {

		index = 2;

	}

	if (on_off_mag_1 == false && on_off_mag_2 == true && on_off_mag_3 == false) {

		index = 1;

	}


	if (on_off_mag_1 == false && on_off_mag_2 == false && on_off_mag_3 == true) {

		index = 1;

	}


	if (on_off_mag_1 == false && on_off_mag_2 == false && on_off_mag_3 == false) {

		index = 0;

	}


	*/

	// вывод полученных результатов в файл
	FILE *fd;

	fopen_s(&fd, filename, "wb");

	if (fd == NULL) {
		fprintf(stderr, "Ошибка открытия выводного файла.\n");
		cout << endl;
		SleepEx(40, true); // пауза для того, чтобы успеть прочитать информацию
		exit(1);
	}
	else {
		setlocale(LC_ALL, "rus"); // корректное отображение Кириллицы

		fprintf(fd, "\n");
		fprintf(fd, "### \n");
		//	fprintf(fd, "### Число Частиц в Бине штук || Нормированное Значение || Координата X Левого Конца Бина мм || Число Частиц в Бине штук || Нормированное Значение || Координата R Левого Конца Бина мм \n");
		fprintf(fd, "### \n");
		fprintf(fd, "\n");

		setlocale(LC_ALL, "C"); // установить используемую системой локаль для корректной отображении точки в выходном файле

								//i + 3 + index*(N_mag_partitions + 1 + N_CYL_partitions) + 3 * N_CYL_partitions + N_CYL_partitions*(i_Collision_all_1 + i_Collision_all_2 + i_Collision_all_3 - 3)

								//#pragma omp parallel
								//	{

		size_t jj = 0;

		for (size_t i = 0; i < vector_size; i = i + 1) {

			//	fprintf(fd, "%.3Lf %.3Lf %.3Lf %.3Lf %.3Lf %.3Lf\n", Vector_x[i], Vector_y[i], Vector_z[i], Vector_r[i], Vector_color_trajectory_cyl[i], Vector_rr[i]);

			if (Vector_r[i] <= R_source && fabs(Vector_z[i] - L_CYL) <= epsilon && Vector_out_trajectory_cyl[i] == 1.0) { //-V550

				for (size_t j = jj; j <= i; j = j + 1) {

					if (Vector_color_trajectory_cyl[j] != 0.0) { //-V550

						if (j % 2 == 0) {

							fprintf(fd, "%.9Le %.9Le %.9Le %.9Le\n", Vector_z[j], Vector_r[j], Vector_color_trajectory_cyl[j], Vector_angular[j]);
						}

						else {

							fprintf(fd, "%.9Le %.9Le %.3e %.9Le\n", Vector_z[j], Vector_r[j], 44.0, Vector_angular[j]);
						}


					}

					if ((Vector_color_trajectory_cyl[j] == 0.0)) { //-V550


						fprintf(fd, "%.9Le %.9Le %.3e %.9Le\n", Vector_z[j], Vector_r[j], 44.0, Vector_angular[j]);


					}


					if (fabs(Vector_z[j] - L_CYL) <= epsilon && Vector_out_trajectory_cyl[j] == 1.0) { //-V550
						fprintf(fd, "\n");
						fprintf(fd, "\n");


					}

					if (j <= i - 1) {

						epsilon_angular = fabs(Vector_angular[j + 1] - Vector_angular[j]);
					}



					if ((fabs(Vector_angular[j] - 0.0) <= epsilon_angular) && (fabs(Vector_angular[j + 1] - 2.0*M_PI) <= epsilon_angular) && (j <= i - 1)) {

						fprintf(fd, "\n");
						fprintf(fd, "\n");


					}


					if ((fabs(Vector_angular[j + 1] - 0.0) <= epsilon_angular) && (fabs(Vector_angular[j] - 2.0*M_PI) <= epsilon_angular) && (j <= i - 1)) {

						fprintf(fd, "\n");
						fprintf(fd, "\n");


					}

					i = j;

				}


				jj = i + 1;

			}

			if (Vector_r[i] > R_source && fabs(Vector_z[i] - L_CYL) <= epsilon && Vector_out_trajectory_cyl[i] == 1.0) { //-V550

				for (size_t j = jj; j <= i; j = j + 1) {


					fprintf(fd, "%.9Le %.9Le %.9Le %.9Le\n", Vector_z[j], Vector_r[j], Vector_color_trajectory_cyl[j], Vector_angular[j]);


					if (fabs(Vector_z[j] - L_CYL) <= epsilon && Vector_out_trajectory_cyl[j] == 1.0) { //-V550

						fprintf(fd, "\n");
						fprintf(fd, "\n");

					}


					if (j <= i - 1) {

						epsilon_angular = fabs(Vector_angular[j + 1] - Vector_angular[j]);
					}


					if ((fabs(Vector_angular[j] - 0.0) <= epsilon_angular) && (fabs(Vector_angular[j + 1] - 2.0*M_PI) <= epsilon_angular) && (j <= i - 1)) {

						fprintf(fd, "\n");
						fprintf(fd, "\n");


					}


					if ((fabs(Vector_angular[j + 1] - 0.0) <= epsilon_angular) && (fabs(Vector_angular[j] - 2.0*M_PI) <= epsilon_angular) && (j <= i - 1)) {

						fprintf(fd, "\n");
						fprintf(fd, "\n");


					}

					//fprintf(fd, "%.3Lf %.3Lf %.3Lf %.3Lf %.3Lf %.3Lf\n", Vector_x[j], Vector_y[j], Vector_z[j], Vector_r[j], 4.0, Vector_rr[j]);


					i = j;
				}



				jj = i + 1;

			}



		}


		//	fprintf(fd, "\n");
		//	fprintf(fd, "\n");

		/*


		fprintf(fd, "### \n");
		fprintf(fd, "### \n");

		unsigned int jj = 0;
		for (unsigned int i = 0; i < vector_size; i = i + 1) {


		if (Vector_r[i] <= R_source && Vector_z[i] == L_CYL) {

		for (unsigned int j = jj; j <= i; j = j + 1) {

		if (Vector_color_trajectory_cyl[j] != 0.0) {

		if ((int)j % 3 == 0) {

		//	fprintf(fd, "%.3Lf %.3Lf %.3Lf %.3Lf %.3Lf %.3Lf\n", Vector_x[j], Vector_y[j], Vector_z[j], Vector_r[j], Vector_color_trajectory_cyl[j], Vector_rr[j]);
		}

		else {

		//	fprintf(fd, "%.3Lf %.3Lf %.3Lf %.3Lf %.3f %.3Lf\n", Vector_x[j], Vector_y[j], Vector_z[j], Vector_r[j], 4.0, Vector_rr[j]);
		}


		}

		if ((Vector_color_trajectory_cyl[j] == 0.0)) {


		//fprintf(fd, "%.3Lf %.3Lf %.3Lf %.3Lf %.3f %.3Lf\n", Vector_x[j], Vector_y[j], Vector_z[j], Vector_r[j], 4.0, Vector_rr[j]);


		}

		if (Vector_z[j] == L_CYL) {
		//fprintf(fd, "\n");
		//fprintf(fd, "\n");


		}




		//fprintf(fd, "%.3Lf %.3Lf %.3Lf %.3Lf %.3Lf %.3Lf\n", Vector_x[j], Vector_y[j], Vector_z[j], Vector_r[j], 4.0, Vector_rr[j]);

		//		if (Vector_z[j] == 0.0) {

		//		break;
		//	}





		*/


		//	}





		//		}


		/*

		if (Vector_r[i] > R_source && Vector_z[i] == L_CYL) {

		for (unsigned int j = jj; j <= i; j = j + 1) {


		//	fprintf(fd, "%.3Lf %.3Lf %.3Lf %.3Lf %.3Lf %.3Lf\n", Vector_x[j], Vector_y[j], Vector_z[j], Vector_r[j], Vector_color_trajectory_cyl[j], Vector_rr[j]);


		if (Vector_z[j] == L_CYL) {
		//	fprintf(fd, "\n");
		//	fprintf(fd, "\n");

		}

		//fprintf(fd, "%.3Lf %.3Lf %.3Lf %.3Lf %.3Lf %.3Lf\n", Vector_x[j], Vector_y[j], Vector_z[j], Vector_r[j], 4.0, Vector_rr[j]);

		}


		}



		jj = i;

		}
		//	}

		}

		*/


		setlocale(LC_ALL, "rus"); // корректное отображение Кириллицы

		fclose(fd);

	}

}



// вывод траеторий частиц в магните в файл
void out_txt_traectory_CYL_force(const char *filename, const vector<long double> &Vector_z, const vector<long double> &Vector_r, const vector<long double> &Vector_force, const vector<long double>&Vector_color_trajectory_cyl, long double L_CYL, size_t N_cyl_partitions, size_t N_mag_partitions, bool on_off_mag_1, bool on_off_mag_2, bool on_off_mag_3, bool on_off_mag_4, bool on_off_mag_5, bool on_off_mag_6, bool on_off_mag_7, long double R_source, size_t N_CYL_partitions, std::size_t i_Collision_all_1, std::size_t i_Collision_all_2, std::size_t i_Collision_all_3, std::size_t i_Collision_all_4, std::size_t i_Collision_all_5, std::size_t i_Collision_all_6, std::size_t i_Collision_all_7, const vector<long double> &Vector_out_trajectory_cyl) {

	printf("Вывод силы\n");
	printf("\n");

	// Сохраняем количество элементов вектора 
	size_t vector_size = Vector_z.size();


	/*
	
	

	int index = 0;

	if (on_off_mag_1 == true && on_off_mag_2 == true && on_off_mag_3 == true) {

		index = 3;

	}

	if (on_off_mag_1 == true && on_off_mag_2 == true && on_off_mag_3 == false) {

		index = 2;

	}

	if (on_off_mag_1 == true && on_off_mag_2 == false && on_off_mag_3 == true) {

		index = 2;

	}

	if (on_off_mag_1 == true && on_off_mag_2 == false && on_off_mag_3 == false) {

		index = 1;

	}


	if (on_off_mag_1 == false && on_off_mag_2 == true && on_off_mag_3 == true) {

		index = 2;

	}

	if (on_off_mag_1 == false && on_off_mag_2 == true && on_off_mag_3 == false) {

		index = 1;

	}


	if (on_off_mag_1 == false && on_off_mag_2 == false && on_off_mag_3 == true) {

		index = 1;

	}


	if (on_off_mag_1 == false && on_off_mag_2 == false && on_off_mag_3 == false) {

		index = 0;

	}

	*/


	// вывод полученных результатов в файл
	FILE *fd;

	fopen_s(&fd, filename, "wb");

	if (fd == NULL) {
		fprintf(stderr, "Ошибка открытия выводного файла.\n");
		cout << endl;
		SleepEx(40, true); // пауза для того, чтобы успеть прочитать информацию
		exit(1);
	}
	else {
		setlocale(LC_ALL, "rus"); // корректное отображение Кириллицы

		fprintf(fd, "\n");
		fprintf(fd, "### \n");
		//	fprintf(fd, "### Число Частиц в Бине штук || Нормированное Значение || Координата X Левого Конца Бина мм || Число Частиц в Бине штук || Нормированное Значение || Координата R Левого Конца Бина мм \n");
		fprintf(fd, "### \n");
		fprintf(fd, "\n");

		setlocale(LC_ALL, "C"); // установить используемую системой локаль для корректной отображении точки в выходном файле

								//i + 3 + index*(N_mag_partitions + 1 + N_CYL_partitions) + 3 * N_CYL_partitions + N_CYL_partitions*(i_Collision_all_1 + i_Collision_all_2 + i_Collision_all_3 - 3)

								//#pragma omp parallel
								//	{

		size_t jj = 0;

		for (size_t i = 0; i < vector_size; i = i + 1) {

			//	fprintf(fd, "%.3Lf %.3Lf %.3Lf %.3Lf %.3Lf %.3Lf\n", Vector_x[i], Vector_y[i], Vector_z[i], Vector_r[i], Vector_color_trajectory_cyl[i], Vector_rr[i]);

			if (Vector_r[i] <= R_source && fabs(Vector_z[i] - L_CYL) <= epsilon && Vector_out_trajectory_cyl[i] == 1.0) { //-V550

				for (size_t j = jj; j <= i; j = j + 1) {

					if (Vector_color_trajectory_cyl[j] != 0.0) { //-V550

						if (j % 2 == 0) {

							fprintf(fd, "%.9Le %.9Le %.9Le %.9Le\n", Vector_z[j], Vector_r[j], Vector_color_trajectory_cyl[j], Vector_force[j]);
						}

						else {

							fprintf(fd, "%.9Le %.9Le %.3e %.9Le\n", Vector_z[j], Vector_r[j], 44.0, Vector_force[j]);
						}


					}

					if ((Vector_color_trajectory_cyl[j] == 0.0)) { //-V550


						fprintf(fd, "%.9Le %.9Le %.3e %.9Le \n", Vector_z[j], Vector_r[j], 44.0, Vector_force[j]);


					}


					if (fabs(Vector_z[j] - L_CYL) <= epsilon && Vector_out_trajectory_cyl[j] == 1.0) { //-V550
						fprintf(fd, "\n");
						fprintf(fd, "\n");


					}





					if ((fabs(Vector_force[j] - 0.0) <= epsilon) && (fabs(Vector_force[j + 1] - 0.0) > epsilon) && (j <= i - 1)) {

						fprintf(fd, "\n");
						fprintf(fd, "\n");


					}


					if ((fabs(Vector_force[j + 1] - 0.0) <= epsilon) && (fabs(Vector_force[j] - 0.0) > epsilon) && (j <= i - 1)) {

						fprintf(fd, "\n");
						fprintf(fd, "\n");


					}

					i = j;

				}


				jj = i + 1;

			}

			if (Vector_r[i] > R_source && fabs(Vector_z[i] - L_CYL) <= epsilon && Vector_out_trajectory_cyl[i] == 1.0) { //-V550

				for (size_t j = jj; j <= i; j = j + 1) {


					fprintf(fd, "%.9Le %.9Le %.9Le %.9Le\n", Vector_z[j], Vector_r[j], Vector_color_trajectory_cyl[j], Vector_force[j]);


					if (fabs(Vector_z[j] - L_CYL) <= epsilon && Vector_out_trajectory_cyl[j] == 1.0) { //-V550

						fprintf(fd, "\n");
						fprintf(fd, "\n");

					}


					if ((fabs(Vector_force[j] - 0.0) <= epsilon) && (fabs(Vector_force[j + 1] - 0.0) > epsilon) && (j <= i - 1)) {

						fprintf(fd, "\n");
						fprintf(fd, "\n");


					}


					if ((fabs(Vector_force[j + 1] - 0.0) <= epsilon) && (fabs(Vector_force[j] - 0.0) > epsilon) && (j <= i - 1)) {

						fprintf(fd, "\n");
						fprintf(fd, "\n");


					}



					//fprintf(fd, "%.3Lf %.3Lf %.3Lf %.3Lf %.3Lf %.3Lf\n", Vector_x[j], Vector_y[j], Vector_z[j], Vector_r[j], 4.0, Vector_rr[j]);


					i = j;
				}



				jj = i + 1;

			}



		}


		//	fprintf(fd, "\n");
		//	fprintf(fd, "\n");

		/*


		fprintf(fd, "### \n");
		fprintf(fd, "### \n");

		unsigned int jj = 0;
		for (unsigned int i = 0; i < vector_size; i = i + 1) {


		if (Vector_r[i] <= R_source && Vector_z[i] == L_CYL) {

		for (unsigned int j = jj; j <= i; j = j + 1) {

		if (Vector_color_trajectory_cyl[j] != 0.0) {

		if ((int)j % 3 == 0) {

		//	fprintf(fd, "%.3Lf %.3Lf %.3Lf %.3Lf %.3Lf %.3Lf\n", Vector_x[j], Vector_y[j], Vector_z[j], Vector_r[j], Vector_color_trajectory_cyl[j], Vector_rr[j]);
		}

		else {

		//	fprintf(fd, "%.3Lf %.3Lf %.3Lf %.3Lf %.3f %.3Lf\n", Vector_x[j], Vector_y[j], Vector_z[j], Vector_r[j], 4.0, Vector_rr[j]);
		}


		}

		if ((Vector_color_trajectory_cyl[j] == 0.0)) {


		//fprintf(fd, "%.3Lf %.3Lf %.3Lf %.3Lf %.3f %.3Lf\n", Vector_x[j], Vector_y[j], Vector_z[j], Vector_r[j], 4.0, Vector_rr[j]);


		}

		if (Vector_z[j] == L_CYL) {
		//fprintf(fd, "\n");
		//fprintf(fd, "\n");


		}




		//fprintf(fd, "%.3Lf %.3Lf %.3Lf %.3Lf %.3Lf %.3Lf\n", Vector_x[j], Vector_y[j], Vector_z[j], Vector_r[j], 4.0, Vector_rr[j]);

		//		if (Vector_z[j] == 0.0) {

		//		break;
		//	}





		*/


		//	}





		//		}


		/*

		if (Vector_r[i] > R_source && Vector_z[i] == L_CYL) {

		for (unsigned int j = jj; j <= i; j = j + 1) {


		//	fprintf(fd, "%.3Lf %.3Lf %.3Lf %.3Lf %.3Lf %.3Lf\n", Vector_x[j], Vector_y[j], Vector_z[j], Vector_r[j], Vector_color_trajectory_cyl[j], Vector_rr[j]);


		if (Vector_z[j] == L_CYL) {
		//	fprintf(fd, "\n");
		//	fprintf(fd, "\n");

		}

		//fprintf(fd, "%.3Lf %.3Lf %.3Lf %.3Lf %.3Lf %.3Lf\n", Vector_x[j], Vector_y[j], Vector_z[j], Vector_r[j], 4.0, Vector_rr[j]);

		}


		}



		jj = i;

		}
		//	}

		}

		*/


		setlocale(LC_ALL, "rus"); // корректное отображение Кириллицы

		fclose(fd);

	}

}

// вывод траеторий частиц в магните в файл
void out_txt_traectory_CYL_B(const char *filename, const vector<long double> &Vector_z, const vector<long double> &Vector_r, const vector<long double> &Vector_B, const vector<long double>&Vector_color_trajectory_cyl, long double L_CYL, size_t N_cyl_partitions, size_t N_mag_partitions, bool on_off_mag_1, bool on_off_mag_2, bool on_off_mag_3, bool on_off_mag_4, bool on_off_mag_5, bool on_off_mag_6, bool on_off_mag_7, long double R_source, size_t N_CYL_partitions, std::size_t i_Collision_all_1, std::size_t i_Collision_all_2, std::size_t i_Collision_all_3, std::size_t i_Collision_all_4, std::size_t i_Collision_all_5, std::size_t i_Collision_all_6, std::size_t i_Collision_all_7, const vector<long double> &Vector_out_trajectory_cyl) {

	printf("Вывод магнитного поля вдоль траеторий\n");
	printf("\n");

	// Сохраняем количество элементов вектора 
	size_t vector_size = Vector_z.size();


	/*
	
	

	int index = 0;

	if (on_off_mag_1 == true && on_off_mag_2 == true && on_off_mag_3 == true) {

		index = 3;

	}

	if (on_off_mag_1 == true && on_off_mag_2 == true && on_off_mag_3 == false) {

		index = 2;

	}

	if (on_off_mag_1 == true && on_off_mag_2 == false && on_off_mag_3 == true) {

		index = 2;

	}

	if (on_off_mag_1 == true && on_off_mag_2 == false && on_off_mag_3 == false) {

		index = 1;

	}


	if (on_off_mag_1 == false && on_off_mag_2 == true && on_off_mag_3 == true) {

		index = 2;

	}

	if (on_off_mag_1 == false && on_off_mag_2 == true && on_off_mag_3 == false) {

		index = 1;

	}


	if (on_off_mag_1 == false && on_off_mag_2 == false && on_off_mag_3 == true) {

		index = 1;

	}


	if (on_off_mag_1 == false && on_off_mag_2 == false && on_off_mag_3 == false) {

		index = 0;

	}

	*/

	// вывод полученных результатов в файл
	FILE *fd;

	fopen_s(&fd, filename, "wb");

	if (fd == NULL) {
		fprintf(stderr, "Ошибка открытия выводного файла.\n");
		cout << endl;
		SleepEx(40, true); // пауза для того, чтобы успеть прочитать информацию
		exit(1);
	}
	else {
		setlocale(LC_ALL, "rus"); // корректное отображение Кириллицы

		fprintf(fd, "\n");
		fprintf(fd, "### \n");
		//	fprintf(fd, "### Число Частиц в Бине штук || Нормированное Значение || Координата X Левого Конца Бина мм || Число Частиц в Бине штук || Нормированное Значение || Координата R Левого Конца Бина мм \n");
		fprintf(fd, "### \n");
		fprintf(fd, "\n");

		setlocale(LC_ALL, "C"); // установить используемую системой локаль для корректной отображении точки в выходном файле

								//i + 3 + index*(N_mag_partitions + 1 + N_CYL_partitions) + 3 * N_CYL_partitions + N_CYL_partitions*(i_Collision_all_1 + i_Collision_all_2 + i_Collision_all_3 - 3)

								//#pragma omp parallel
								//	{

		size_t jj = 0;

		for (size_t i = 0; i < vector_size; i = i + 1) {

			//	fprintf(fd, "%.3Lf %.3Lf %.3Lf %.3Lf %.3Lf %.3Lf\n", Vector_x[i], Vector_y[i], Vector_z[i], Vector_r[i], Vector_color_trajectory_cyl[i], Vector_rr[i]);

			if (Vector_r[i] <= R_source && fabs(Vector_z[i] - L_CYL) <= epsilon && Vector_out_trajectory_cyl[i] == 1.0) { //-V550

				for (size_t j = jj; j <= i; j = j + 1) {

					if (Vector_color_trajectory_cyl[j] != 0.0) { //-V550

						if (j % 2 == 0) {

							fprintf(fd, "%.9Le %.9Le %.9Le %.9Le\n", Vector_z[j], Vector_r[j], Vector_color_trajectory_cyl[j], Vector_B[j]);
						}

						else {

							fprintf(fd, "%.9Le %.9Le %.3e %.9Le\n", Vector_z[j], Vector_r[j], 44.0, Vector_B[j]);
						}


					}

					if ((Vector_color_trajectory_cyl[j] == 0.0)) { //-V550


						fprintf(fd, "%.9Le %.9Le %.3e %.9Le \n", Vector_z[j], Vector_r[j], 44.0, Vector_B[j]);


					}


					if (fabs(Vector_z[j] - L_CYL) <= epsilon && Vector_out_trajectory_cyl[j] == 1.0) { //-V550
						fprintf(fd, "\n");
						fprintf(fd, "\n");


					}





					if ((fabs(Vector_B[j] - 0.0) <= epsilon) && (fabs(Vector_B[j + 1] - 0.0) > epsilon) && (j <= i - 1)) {

						fprintf(fd, "\n");
						fprintf(fd, "\n");


					}


					if ((fabs(Vector_B[j + 1] - 0.0) <= epsilon) && (fabs(Vector_B[j] - 0.0) > epsilon) && (j <= i - 1)) {

						fprintf(fd, "\n");
						fprintf(fd, "\n");


					}

					i = j;

				}


				jj = i + 1;

			}

			if (Vector_r[i] > R_source && fabs(Vector_z[i] - L_CYL) <= epsilon && Vector_out_trajectory_cyl[i] == 1.0) { //-V550

				for (size_t j = jj; j <= i; j = j + 1) {


					fprintf(fd, "%.9Le %.9Le %.9Le %.9Le\n", Vector_z[j], Vector_r[j], Vector_color_trajectory_cyl[j], Vector_B[j]);


					if (fabs(Vector_z[j] - L_CYL) <= epsilon && Vector_out_trajectory_cyl[j] == 1.0) { //-V550

						fprintf(fd, "\n");
						fprintf(fd, "\n");

					}


					if ((fabs(Vector_B[j] - 0.0) <= epsilon) && (fabs(Vector_B[j + 1] - 0.0) > epsilon) && (j <= i - 1)) {

						fprintf(fd, "\n");
						fprintf(fd, "\n");


					}


					if ((fabs(Vector_B[j + 1] - 0.0) <= epsilon) && (fabs(Vector_B[j] - 0.0) > epsilon) && (j <= i - 1)) {

						fprintf(fd, "\n");
						fprintf(fd, "\n");


					}



					//fprintf(fd, "%.3Lf %.3Lf %.3Lf %.3Lf %.3Lf %.3Lf\n", Vector_x[j], Vector_y[j], Vector_z[j], Vector_r[j], 4.0, Vector_rr[j]);


					i = j;
				}



				jj = i + 1;

			}



		}


		//	fprintf(fd, "\n");
		//	fprintf(fd, "\n");

		/*


		fprintf(fd, "### \n");
		fprintf(fd, "### \n");

		unsigned int jj = 0;
		for (unsigned int i = 0; i < vector_size; i = i + 1) {


		if (Vector_r[i] <= R_source && Vector_z[i] == L_CYL) {

		for (unsigned int j = jj; j <= i; j = j + 1) {

		if (Vector_color_trajectory_cyl[j] != 0.0) {

		if ((int)j % 3 == 0) {

		//	fprintf(fd, "%.3Lf %.3Lf %.3Lf %.3Lf %.3Lf %.3Lf\n", Vector_x[j], Vector_y[j], Vector_z[j], Vector_r[j], Vector_color_trajectory_cyl[j], Vector_rr[j]);
		}

		else {

		//	fprintf(fd, "%.3Lf %.3Lf %.3Lf %.3Lf %.3f %.3Lf\n", Vector_x[j], Vector_y[j], Vector_z[j], Vector_r[j], 4.0, Vector_rr[j]);
		}


		}

		if ((Vector_color_trajectory_cyl[j] == 0.0)) {


		//fprintf(fd, "%.3Lf %.3Lf %.3Lf %.3Lf %.3f %.3Lf\n", Vector_x[j], Vector_y[j], Vector_z[j], Vector_r[j], 4.0, Vector_rr[j]);


		}

		if (Vector_z[j] == L_CYL) {
		//fprintf(fd, "\n");
		//fprintf(fd, "\n");


		}




		//fprintf(fd, "%.3Lf %.3Lf %.3Lf %.3Lf %.3Lf %.3Lf\n", Vector_x[j], Vector_y[j], Vector_z[j], Vector_r[j], 4.0, Vector_rr[j]);

		//		if (Vector_z[j] == 0.0) {

		//		break;
		//	}





		*/


		//	}





		//		}


		/*

		if (Vector_r[i] > R_source && Vector_z[i] == L_CYL) {

		for (unsigned int j = jj; j <= i; j = j + 1) {


		//	fprintf(fd, "%.3Lf %.3Lf %.3Lf %.3Lf %.3Lf %.3Lf\n", Vector_x[j], Vector_y[j], Vector_z[j], Vector_r[j], Vector_color_trajectory_cyl[j], Vector_rr[j]);


		if (Vector_z[j] == L_CYL) {
		//	fprintf(fd, "\n");
		//	fprintf(fd, "\n");

		}

		//fprintf(fd, "%.3Lf %.3Lf %.3Lf %.3Lf %.3Lf %.3Lf\n", Vector_x[j], Vector_y[j], Vector_z[j], Vector_r[j], 4.0, Vector_rr[j]);

		}


		}



		jj = i;

		}
		//	}

		}

		*/


		setlocale(LC_ALL, "rus"); // корректное отображение Кириллицы

		fclose(fd);

	}

}

// вывод траеторий частиц в магните в файл
void out_txt_traectory_CYL_mu(const char *filename, const vector<long double> &Vector_z, const vector<long double> &Vector_r, const vector<long double> &Vector_mu, const vector<long double>&Vector_color_trajectory_cyl, long double L_CYL, size_t N_cyl_partitions, size_t N_mag_partitions, bool on_off_mag_1, bool on_off_mag_2, bool on_off_mag_3, bool on_off_mag_4, bool on_off_mag_5, bool on_off_mag_6, bool on_off_mag_7, long double R_source, size_t N_CYL_partitions, std::size_t i_Collision_all_1, std::size_t i_Collision_all_2, std::size_t i_Collision_all_3, std::size_t i_Collision_all_4, std::size_t i_Collision_all_5, std::size_t i_Collision_all_6, std::size_t i_Collision_all_7, const vector<long double> &Vector_out_trajectory_cyl) {

	printf("Вывод магнитного момента вдоль траеторий\n");
	printf("\n");

	// Сохраняем количество элементов вектора 
	size_t vector_size = Vector_z.size();

	long double epsilon_mu = pow(10.0, -4.0);


	/*
	
	
	

	int index = 0;

	if (on_off_mag_1 == true && on_off_mag_2 == true && on_off_mag_3 == true) {

		index = 3;

	}

	if (on_off_mag_1 == true && on_off_mag_2 == true && on_off_mag_3 == false) {

		index = 2;

	}

	if (on_off_mag_1 == true && on_off_mag_2 == false && on_off_mag_3 == true) {

		index = 2;

	}

	if (on_off_mag_1 == true && on_off_mag_2 == false && on_off_mag_3 == false) {

		index = 1;

	}


	if (on_off_mag_1 == false && on_off_mag_2 == true && on_off_mag_3 == true) {

		index = 2;

	}

	if (on_off_mag_1 == false && on_off_mag_2 == true && on_off_mag_3 == false) {

		index = 1;

	}


	if (on_off_mag_1 == false && on_off_mag_2 == false && on_off_mag_3 == true) {

		index = 1;

	}


	if (on_off_mag_1 == false && on_off_mag_2 == false && on_off_mag_3 == false) {

		index = 0;

	}

	*/


	// вывод полученных результатов в файл
	FILE *fd;

	fopen_s(&fd, filename, "wb");

	if (fd == NULL) {
		fprintf(stderr, "Ошибка открытия выводного файла.\n");
		cout << endl;
		SleepEx(40, true); // пауза для того, чтобы успеть прочитать информацию
		exit(1);
	}
	else {
		setlocale(LC_ALL, "rus"); // корректное отображение Кириллицы

		fprintf(fd, "\n");
		fprintf(fd, "### \n");
		//	fprintf(fd, "### Число Частиц в Бине штук || Нормированное Значение || Координата X Левого Конца Бина мм || Число Частиц в Бине штук || Нормированное Значение || Координата R Левого Конца Бина мм \n");
		fprintf(fd, "### \n");
		fprintf(fd, "\n");

		setlocale(LC_ALL, "C"); // установить используемую системой локаль для корректной отображении точки в выходном файле

								//i + 3 + index*(N_mag_partitions + 1 + N_CYL_partitions) + 3 * N_CYL_partitions + N_CYL_partitions*(i_Collision_all_1 + i_Collision_all_2 + i_Collision_all_3 - 3)

								//#pragma omp parallel
								//	{

		size_t jj = 0;

		for (size_t i = 0; i < vector_size; i = i + 1) {

			//	fprintf(fd, "%.3Lf %.3Lf %.3Lf %.3Lf %.3Lf %.3Lf\n", Vector_x[i], Vector_y[i], Vector_z[i], Vector_r[i], Vector_color_trajectory_cyl[i], Vector_rr[i]);

			if (Vector_r[i] <= R_source && fabs(Vector_z[i] - L_CYL) <= epsilon && Vector_out_trajectory_cyl[i] == 1.0) { //-V550

				for (size_t j = jj; j <= i; j = j + 1) {

					if (Vector_color_trajectory_cyl[j] != 0.0) { //-V550

						if (j % 2 == 0) {

							fprintf(fd, "%.9Le %.9Le %.9Le %.9Le\n", Vector_z[j], Vector_r[j], Vector_color_trajectory_cyl[j], Vector_mu[j]);
						}

						else {

							fprintf(fd, "%.9Le %.9Le %.3e %.9Le\n", Vector_z[j], Vector_r[j], 44.0, Vector_mu[j]);
						}


					}

					if ((Vector_color_trajectory_cyl[j] == 0.0)) { //-V550


						fprintf(fd, "%.9Le %.9Le %.3e %.9Le \n", Vector_z[j], Vector_r[j], 44.0, Vector_mu[j]);


					}


					if (fabs(Vector_z[j] - L_CYL) <= epsilon && Vector_out_trajectory_cyl[j] == 1.0) { //-V550
						fprintf(fd, "\n");
						fprintf(fd, "\n");


					}





					if ((fabs(Vector_mu[j + 1] - Vector_mu[j]) > epsilon_mu) && (j <= i - 1)) {

						fprintf(fd, "\n");
						fprintf(fd, "\n");


					}



					if ((fabs(Vector_mu[j] - Vector_mu[j + 1]) > epsilon_mu) && (j <= i - 1)) {

						fprintf(fd, "\n");
						fprintf(fd, "\n");


					}

					i = j;

				}


				jj = i + 1;

			}

			if (Vector_r[i] > R_source && fabs(Vector_z[i] - L_CYL) <= epsilon && Vector_out_trajectory_cyl[i] == 1.0) { //-V550

				for (size_t j = jj; j <= i; j = j + 1) {


					fprintf(fd, "%.9Le %.9Le %.9Le %.9Le\n", Vector_z[j], Vector_r[j], Vector_color_trajectory_cyl[j], Vector_mu[j]);


					if (fabs(Vector_z[j] - L_CYL) <= epsilon && Vector_out_trajectory_cyl[j] == 1.0) { //-V550

						fprintf(fd, "\n");
						fprintf(fd, "\n");

					}



					if ((fabs(Vector_mu[j + 1] - Vector_mu[j]) > epsilon_mu) && (j <= i - 1)) {

						fprintf(fd, "\n");
						fprintf(fd, "\n");


					}


					if ((fabs(Vector_mu[j] - Vector_mu[j + 1]) > epsilon_mu) && (j <= i - 1)) {

						fprintf(fd, "\n");
						fprintf(fd, "\n");


					}



					//fprintf(fd, "%.3Lf %.3Lf %.3Lf %.3Lf %.3Lf %.3Lf\n", Vector_x[j], Vector_y[j], Vector_z[j], Vector_r[j], 4.0, Vector_rr[j]);


					i = j;
				}



				jj = i + 1;

			}



		}


		//	fprintf(fd, "\n");
		//	fprintf(fd, "\n");

		/*


		fprintf(fd, "### \n");
		fprintf(fd, "### \n");

		unsigned int jj = 0;
		for (unsigned int i = 0; i < vector_size; i = i + 1) {


		if (Vector_r[i] <= R_source && Vector_z[i] == L_CYL) {

		for (unsigned int j = jj; j <= i; j = j + 1) {

		if (Vector_color_trajectory_cyl[j] != 0.0) {

		if ((int)j % 3 == 0) {

		//	fprintf(fd, "%.3Lf %.3Lf %.3Lf %.3Lf %.3Lf %.3Lf\n", Vector_x[j], Vector_y[j], Vector_z[j], Vector_r[j], Vector_color_trajectory_cyl[j], Vector_rr[j]);
		}

		else {

		//	fprintf(fd, "%.3Lf %.3Lf %.3Lf %.3Lf %.3f %.3Lf\n", Vector_x[j], Vector_y[j], Vector_z[j], Vector_r[j], 4.0, Vector_rr[j]);
		}


		}

		if ((Vector_color_trajectory_cyl[j] == 0.0)) {


		//fprintf(fd, "%.3Lf %.3Lf %.3Lf %.3Lf %.3f %.3Lf\n", Vector_x[j], Vector_y[j], Vector_z[j], Vector_r[j], 4.0, Vector_rr[j]);


		}

		if (Vector_z[j] == L_CYL) {
		//fprintf(fd, "\n");
		//fprintf(fd, "\n");


		}




		//fprintf(fd, "%.3Lf %.3Lf %.3Lf %.3Lf %.3Lf %.3Lf\n", Vector_x[j], Vector_y[j], Vector_z[j], Vector_r[j], 4.0, Vector_rr[j]);

		//		if (Vector_z[j] == 0.0) {

		//		break;
		//	}





		*/


		//	}





		//		}


		/*

		if (Vector_r[i] > R_source && Vector_z[i] == L_CYL) {

		for (unsigned int j = jj; j <= i; j = j + 1) {


		//	fprintf(fd, "%.3Lf %.3Lf %.3Lf %.3Lf %.3Lf %.3Lf\n", Vector_x[j], Vector_y[j], Vector_z[j], Vector_r[j], Vector_color_trajectory_cyl[j], Vector_rr[j]);


		if (Vector_z[j] == L_CYL) {
		//	fprintf(fd, "\n");
		//	fprintf(fd, "\n");

		}

		//fprintf(fd, "%.3Lf %.3Lf %.3Lf %.3Lf %.3Lf %.3Lf\n", Vector_x[j], Vector_y[j], Vector_z[j], Vector_r[j], 4.0, Vector_rr[j]);

		}


		}



		jj = i;

		}
		//	}

		}

		*/


		setlocale(LC_ALL, "rus"); // корректное отображение Кириллицы

		fclose(fd);

	}

}



// вывод траеторий частиц в магните в файл
void out_txt_traectory_CYL_one_1(const char *filename_1, const char *filename_2, const char *filename_3, const char *filename_4, const char *filename_5, const char *filename_6, const char *filename_7, const char *filename_8, const char *filename_9, const vector<long double> &Vector_x, const vector<long double> &Vector_y, const vector<long double> &Vector_z, const vector<long double> &Vector_r, long double L_CYL, const vector<long double>&Vector_color_trajectory_cyl, long double L1, long double L2, long double L3, long double L4, long double L5, long double L6, long double L7, long double M1, long double M2, long double M3, long double M4, long double M5, long double M6, long double M7, long double z0_M1, long double z0_M2, long double z0_M3, long double z0_M4, long double z0_M5, long double z0_M6, long double z0_M7, size_t N_mag_partitions, const vector<long double> &Vector_rr_mag) {

	printf("Вывод траеторий\n");
	printf("\n");

	// Сохраняем количество элементов вектора 
	size_t vector_size = Vector_z.size();


	// вывод полученных результатов в файл
	FILE *fd_1;

	fopen_s(&fd_1, filename_1, "wb");


	FILE *fd_2;

	fopen_s(&fd_2, filename_1, "wb");


	FILE *fd_3;

	fopen_s(&fd_3, filename_1, "wb");


	FILE *fd_4;

	fopen_s(&fd_4, filename_1, "wb");


	FILE *fd_5;

	fopen_s(&fd_5, filename_1, "wb");


	FILE *fd_6;

	fopen_s(&fd_6, filename_1, "wb");


	FILE *fd_7;

	fopen_s(&fd_7, filename_1, "wb");


	FILE *fd_8;

	fopen_s(&fd_8, filename_1, "wb");



	FILE *fd_9;

	fopen_s(&fd_9, filename_1, "wb");

	if (fd_1 == NULL) {
		fprintf(stderr, "Ошибка открытия выводного файла.\n");
		cout << endl;
		SleepEx(40, true); // пауза для того, чтобы успеть прочитать информацию
		exit(1);
	}

	if (fd_2 == NULL) {
		fprintf(stderr, "Ошибка открытия выводного файла.\n");
		cout << endl;
		SleepEx(40, true); // пауза для того, чтобы успеть прочитать информацию
		exit(1);
	}


	if (fd_3 == NULL) {
		fprintf(stderr, "Ошибка открытия выводного файла.\n");
		cout << endl;
		SleepEx(40, true); // пауза для того, чтобы успеть прочитать информацию
		exit(1);
	}


	if (fd_4 == NULL) {
		fprintf(stderr, "Ошибка открытия выводного файла.\n");
		cout << endl;
		SleepEx(40, true); // пауза для того, чтобы успеть прочитать информацию
		exit(1);
	}


	if (fd_5 == NULL) {
		fprintf(stderr, "Ошибка открытия выводного файла.\n");
		cout << endl;
		SleepEx(40, true); // пауза для того, чтобы успеть прочитать информацию
		exit(1);
	}


	if (fd_6 == NULL) {
		fprintf(stderr, "Ошибка открытия выводного файла.\n");
		cout << endl;
		SleepEx(40, true); // пауза для того, чтобы успеть прочитать информацию
		exit(1);
	}

	if (fd_7 == NULL) {
		fprintf(stderr, "Ошибка открытия выводного файла.\n");
		cout << endl;
		SleepEx(40, true); // пауза для того, чтобы успеть прочитать информацию
		exit(1);
	}

	if (fd_8 == NULL) {
		fprintf(stderr, "Ошибка открытия выводного файла.\n");
		cout << endl;
		SleepEx(40, true); // пауза для того, чтобы успеть прочитать информацию
		exit(1);
	}

	if (fd_9 == NULL) {
		fprintf(stderr, "Ошибка открытия выводного файла.\n");
		cout << endl;
		SleepEx(40, true); // пауза для того, чтобы успеть прочитать информацию
		exit(1);
	}
	if (fd_1 != NULL && fd_2 != NULL && fd_3 != NULL && fd_4 != NULL && fd_5 != NULL && fd_6 != NULL && fd_7 != NULL && fd_8 != NULL && fd_9 != NULL) {
		setlocale(LC_ALL, "rus"); // корректное отображение Кириллицы

		fprintf(fd_1, "\n");
		fprintf(fd_1, "### \n");
		//	fprintf(fd, "### Число Частиц в Бине штук || Нормированное Значение || Координата X Левого Конца Бина мм || Число Частиц в Бине штук || Нормированное Значение || Координата R Левого Конца Бина мм \n");
		fprintf(fd_1, "### \n");
		fprintf(fd_1, "\n");


		fprintf(fd_2, "\n");
		fprintf(fd_2, "### \n");
		//	fprintf(fd, "### Число Частиц в Бине штук || Нормированное Значение || Координата X Левого Конца Бина мм || Число Частиц в Бине штук || Нормированное Значение || Координата R Левого Конца Бина мм \n");
		fprintf(fd_2, "### \n");
		fprintf(fd_2, "\n");


		fprintf(fd_3, "\n");
		fprintf(fd_3, "### \n");
		//	fprintf(fd, "### Число Частиц в Бине штук || Нормированное Значение || Координата X Левого Конца Бина мм || Число Частиц в Бине штук || Нормированное Значение || Координата R Левого Конца Бина мм \n");
		fprintf(fd_3, "### \n");
		fprintf(fd_3, "\n");


		fprintf(fd_4, "\n");
		fprintf(fd_4, "### \n");
		//	fprintf(fd, "### Число Частиц в Бине штук || Нормированное Значение || Координата X Левого Конца Бина мм || Число Частиц в Бине штук || Нормированное Значение || Координата R Левого Конца Бина мм \n");
		fprintf(fd_4, "### \n");
		fprintf(fd_4, "\n");


		fprintf(fd_5, "\n");
		fprintf(fd_5, "### \n");
		//	fprintf(fd, "### Число Частиц в Бине штук || Нормированное Значение || Координата X Левого Конца Бина мм || Число Частиц в Бине штук || Нормированное Значение || Координата R Левого Конца Бина мм \n");
		fprintf(fd_5, "### \n");
		fprintf(fd_5, "\n");


		fprintf(fd_6, "\n");
		fprintf(fd_6, "### \n");
		//	fprintf(fd, "### Число Частиц в Бине штук || Нормированное Значение || Координата X Левого Конца Бина мм || Число Частиц в Бине штук || Нормированное Значение || Координата R Левого Конца Бина мм \n");
		fprintf(fd_6, "### \n");
		fprintf(fd_6, "\n");


		fprintf(fd_7, "\n");
		fprintf(fd_7, "### \n");
		//	fprintf(fd, "### Число Частиц в Бине штук || Нормированное Значение || Координата X Левого Конца Бина мм || Число Частиц в Бине штук || Нормированное Значение || Координата R Левого Конца Бина мм \n");
		fprintf(fd_7, "### \n");
		fprintf(fd_7, "\n");


		fprintf(fd_8, "\n");
		fprintf(fd_8, "### \n");
		//	fprintf(fd, "### Число Частиц в Бине штук || Нормированное Значение || Координата X Левого Конца Бина мм || Число Частиц в Бине штук || Нормированное Значение || Координата R Левого Конца Бина мм \n");
		fprintf(fd_8, "### \n");
		fprintf(fd_8, "\n");


		fprintf(fd_9, "\n");
		fprintf(fd_9, "### \n");
		//	fprintf(fd, "### Число Частиц в Бине штук || Нормированное Значение || Координата X Левого Конца Бина мм || Число Частиц в Бине штук || Нормированное Значение || Координата R Левого Конца Бина мм \n");
		fprintf(fd_9, "### \n");
		fprintf(fd_9, "\n");

		setlocale(LC_ALL, "C"); // установить используемую системой локаль для корректной отображении точки в выходном файле


		for (size_t j = 0; j < vector_size; j++) {


			if (fabs(Vector_z[j] - z0_M1) <= epsilon) {
				fprintf(fd_1, "%.3Lf %.3Lf %.3Lf %.3Lf %.3Lf\n", Vector_x[j - 1], Vector_y[j - 1], Vector_z[j - 1], Vector_r[j - 1], Vector_color_trajectory_cyl[j - 1]);
				fprintf(fd_1, "%.3Lf %.3Lf %.3Lf %.3Lf %.3Lf\n", Vector_x[j], Vector_y[j], Vector_z[j], Vector_r[j], Vector_color_trajectory_cyl[j]);
				fprintf(fd_1, "\n");
				fprintf(fd_1, "\n");

			}

			if (fabs(Vector_z[j] - (z0_M1 + M1)) <= epsilon) {

				fprintf(fd_2, "%.3Lf %.3Lf %.3Lf %.3Lf %.3Lf\n", Vector_x[j - 1 - N_mag_partitions], Vector_y[j - 1 - N_mag_partitions], Vector_z[j - 1 - N_mag_partitions], Vector_r[j - 1 - N_mag_partitions], Vector_color_trajectory_cyl[j - 1 - N_mag_partitions]);
				for (size_t i = vector_size - N_mag_partitions; i < vector_size; i = i + 1) {
					fprintf(fd_2, "%.3Lf %.3Lf %.3Lf %.3Lf %.3Lf\n", Vector_x[i], Vector_y[i], Vector_z[i], Vector_r[i], Vector_color_trajectory_cyl[i]);
				}

				fprintf(fd_2, "\n");
				fprintf(fd_2, "\n");

			}

			if (fabs(Vector_z[j] - L1) <= epsilon) {
				fprintf(fd_1, "%.3Lf %.3Lf %.3Lf %.3Lf %.3Lf\n", Vector_x[j - 1], Vector_y[j - 1], Vector_z[j - 1], Vector_r[j - 1], Vector_color_trajectory_cyl[j - 1]);
				fprintf(fd_1, "%.3Lf %.3Lf %.3Lf %.3Lf %.3Lf\n", Vector_x[j], Vector_y[j], Vector_z[j], Vector_r[j], Vector_color_trajectory_cyl[j]);
				fprintf(fd_1, "\n");
				fprintf(fd_1, "\n");

			}


		}




		setlocale(LC_ALL, "rus"); // корректное отображение Кириллицы

		fclose(fd_1);
		fclose(fd_2);
		fclose(fd_3);
		fclose(fd_4);
		fclose(fd_5);
		fclose(fd_6);
		fclose(fd_7);
		fclose(fd_8);
		fclose(fd_9);

	}


}




// вывод траеторий частиц в магните в файл
void out_txt_xy_in(const char *filename, const vector<long double> &Vector_x, const vector<long double> &Vector_y, const vector<long double> &Vector_z, const vector<long double> &Vector_r, const vector<long double> &Vector_rr, const vector<long double> &Vector_color) {

	setlocale(LC_ALL, "rus");

	printf("Вывод траеторий\n");
	printf("\n");

	setlocale(LC_ALL, "C");

	// Сохраняем количество элементов вектора 
	size_t vector_size = Vector_z.size();

	long double phi = 0.0;

	long double x = 0.0;
	long double y = 0.0;


	// вывод полученных результатов в файл
	FILE *fd;

	fopen_s(&fd, filename, "wb");

	if (fd == NULL) {
		fprintf(stderr, "Ошибка открытия выводного файла.\n");
		cout << endl;
		SleepEx(40, true); // пауза для того, чтобы успеть прочитать информацию
		exit(1);
	}
	else {
		setlocale(LC_ALL, "rus"); // корректное отображение Кириллицы

		fprintf(fd, "\n");
		fprintf(fd, "### \n");
		//	fprintf(fd, "### Число Частиц в Бине штук || Нормированное Значение || Координата X Левого Конца Бина мм || Число Частиц в Бине штук || Нормированное Значение || Координата R Левого Конца Бина мм \n");
		fprintf(fd, "### \n");
		fprintf(fd, "\n");

		setlocale(LC_ALL, "C"); // установить используемую системой локаль для корректной отображении точки в выходном файле


		for (size_t i = 0; i < vector_size; i = i + 1) {

			x = Vector_x[i];


			y = Vector_y[i];



			if (fabs(x - 0.0) <= epsilon && y > 0) {

				phi = M_PI_2;
			}


			if (fabs(x - 0.0) <= epsilon && y < 0) {

				phi = 3.0*M_PI_2;
			}


			if (fabs(y - 0.0) <= epsilon && x > 0) {

				phi = 0.0;
			}

			if (fabs(y - 0.0) <= epsilon && x < 0) {

				phi = M_PI;
			}

			if (fabs(y - 0.0) <= epsilon && fabs(x - 0.0) <= epsilon) {

				phi = 0.0;
			}

			if (x > 0 && y > 0) {

				phi = atan(fabs(y / x));
			}



			if (x < 0 && y < 0) {

				phi = M_PI + atan(fabs(y / x));
			}

			if (x > 0 && y < 0) {

				phi = 2.0*M_PI - atan(fabs(y / x));
			}


			if (x < 0 && y > 0) {

				phi = M_PI - atan(fabs(y / x));
			}


			fprintf(fd, "%.3Lf %.3Lf %.3Lf %.3Lf %.3Lf %.3Lf %.3Lf\n", Vector_x[i], Vector_y[i], Vector_z[i], Vector_r[i], Vector_rr[i], Vector_color[i], phi);

			//fprintf(fd, "\n");
			//fprintf(fd, "\n");


		}


	}




	setlocale(LC_ALL, "rus"); // корректное отображение Кириллицы

	fclose(fd);

}






// время контакта с цилиндром для частиц, испущенных с кольца
inline long double time1(const char *s, long double r, long double theta, long double phi, long double psi, long double R, long double V_0) // определение времени момента столкновение со стенкой цилиндра, частица испущена с торца
{
	long double t = 0.0;

	if (strcmp(s, "left") == 0) {

		t = fabs(-r * cos(phi - psi) + pow(pow(R, 2.0) - pow(r, 2.0)*pow(sin(phi - psi), 2.0), 1.0 / 2.0)) / (sin(theta));
	}

	if (strcmp(s, "right") == 0) {
		t = fabs(-(r*cos(phi - psi) + pow(pow(R, 2.0) - pow(r, 2.0)*pow(sin(phi - psi), 2.0), 1.0 / 2.0))) / (sin(theta));
		//cout << "yes" << endl;

	}


	return t;

}

// время контакта с плоскостью z=h для частиц, испущенных с кольца
inline long double time1_(long double z0, long double h, long double theta, long double V_0) // частица испущена с торца
{
	long double t = 0.0;
	t = fabs(h - z0) / cos(theta);
	return t;

}



// время контакта с цилиндром для частиц, испущенных с поверхности образующей цилиндра
inline long double time2(long double theta, long double psi, long double R, long double V_0) // определение времени момента столкновение со стенкой цилиндра, частица испущена с поверхности цилиндра
{
	long double t = 0.0;
	//t = (2.0*R) / (cos(theta)*(1.0 + pow(tan(theta)*sin(psi), 2.0)));

	t = fabs(2.0*R*cos(theta) / (1.0 - pow(sin(theta)*cos(psi), 2.0)));

	return t;

}

// время контакта с плоскостью z=h для частиц, испущенных с поверхности образующей цилиндра
inline long double time2_(long double z0, long double h, long double theta, long double psi, long double V_0) //  частица испущена с поверхности цилиндра
{
	long double t = 0.0;

	t = fabs((z0 - h) / (sin(theta)*cos(psi)));

	return t;

}




/* Cubic equation solution. Real coefficients case.

int Cubic(double *x,double a,double b,double c);
Parameters:
x - solution array (size 3). On output:
3 real roots -> then x is filled with them;
1 real + 2 complex -> x[0] is real, x[1] is real part of
complex roots, x[2] - non-negative
imaginary part.
a, b, c - coefficients, as described
Returns: 3 - 3 real roots;
1 - 1 real root + 2 complex;
2 - 1 real root + complex roots imaginary part is zero
(i.e. 2 real roots).
*/



#define M_2PI (2.0*M_PI)

inline int Cubic(long double *x, long double a, long double b, long double c) {
	long double q = 0.0, r = 0.0, r2 = 0.0, q3 = 0.0;
	q = (a*a - 3.0*b) / 9.; r = (a*(2.0*a*a - 9.*b) + 27.0*c) / 54.0;
	r2 = pow(r, 2.0); q3 = pow(q, 3.0);
	if (r2 < q3) {
		long double t = acos(r / sqrt(q3));
		a = a / 3.0; q = -2.0*sqrt(q);
		x[0] = q * cos(t / 3.0) - a;
		x[1] = q * cos((t + M_2PI) / 3.0) - a;
		x[2] = q * cos((t - M_2PI) / 3.0) - a;
		return(3);
	}
	else {
		long double aa = 0.0, bb = 0.0;
		if (r <= 0.0) r = -r;
		aa = -pow(r + sqrt(r2 - q3), 1.0 / 3.0);
		if (fabs(aa - 0.0) > epsilon) bb = q / aa;
		else bb = 0.0;
		a = a / 3.0; q = aa + bb; r = aa - bb;
		x[0] = q - a;
		x[1] = (-0.5)*q - a;
		x[2] = (sqrt(3.0)*0.5)*fabs(r);
		if (fabs(x[2] - 0.0) <= epsilon) return(2); //-V550
		return(1);
	}
}



inline long double sigma_mu(long double sigma_iso, long double sigma_anis, long double J, long double m_J) {


	long double sigma_perp = sigma_iso + 2.0*sigma_anis / 3.0;
	long double sigma_parall = sigma_iso - sigma_anis / 3.0;

	long double sigma_temp = 2.0*sigma_perp / 3.0 + sigma_parall / 3.0 + (sigma_perp - sigma_parall)*(2.0 / ((2.0*J - 1.0)*(2.0*J + 3.0)*3.0)*(3.0*pow(m_J, 2.0) - J * (J + 1.0)));

	return sigma_temp;

}




long double mu_H(size_t index, long double B, long double &mu_temp, long double &E_temp) {

	if (fabs(B - 0.0) <= epsilon) {
		B = 0.001;
	}


	long double h = 4.13566766225; //10^-15 эВ*сек

	long double c_speed = 2.99792458; // 10^10 см/сек

	long double mu_bor = 5.788381806638; // 10^-9 эВ/Гс

	long double mu = 0.0;
	long double E = 0.0;

	long double m = 1.00727646667991 + 5.4857990907016 / 1000.0;
	long double m_electron = 5.4857990907016 / 1000.0;

	// масса приходит в a.e.m

	m = m * 931493614.8385;		   // теперь масса в эВ
	m_electron = m_electron * 931493614.8385;		   // теперь масса в эВ

	long double B_critical = 507.6;

	long double x = B / B_critical;

	long double E_HFS = 1420405750.0;

	if (index == 0) {

		E = E_HFS * (0.25 + 0.5*x);
		E_temp = E;
		mu = E_HFS * 0.5*x / B;
		mu_temp = E_HFS * 0.5*x / B;


	}
	if (index == 1) {

		E = E_HFS * (-0.25 + 0.5*pow(pow(x, 2.0) + 1.0, 1.0 / 2.0));
		E_temp = E;
		mu = E_HFS * 0.5*pow(x, 2.0) / (pow(pow(x, 2.0) + 1.0, 1.0 / 2.0)*B);
		mu_temp = E_HFS * 0.5*pow(x, 2.0) / (pow(pow(x, 2.0) + 1.0, 1.0 / 2.0)*B); //-V656
	}
	if (index == 2) {
		E = E_HFS * (0.25 - 0.5*x);
		E_temp = E;
		mu = -E_HFS * 0.5*x / B;
		mu_temp = -E_HFS * 0.5*x / B;

	}
	if (index == 3) {

		E = E_HFS * (-0.25 - 0.5*pow(pow(x, 2.0) + 1.0, 1.0 / 2.0));
		E_temp = E;
		mu = -E_HFS * 0.5*pow(x, 2.0) / (pow(pow(x, 2.0) + 1.0, 1.0 / 2.0)*B);
		mu_temp = -E_HFS * 0.5*pow(x, 2.0) / (pow(pow(x, 2.0) + 1.0, 1.0 / 2.0)*B); //-V656
	}







	E_temp = E_temp / pow(10.0, 9.0);	// в ГГц

	mu_temp = (mu_temp*h / mu_bor)*pow(10.0, -6.0);

	mu = (mu*h / mu_bor)*pow(10.0, -6.0);

	return mu;
}

void out_mu_H(const char *filename, long double B_min, long double B_max, size_t N) {

	setlocale(LC_ALL, "rus");

	printf("\n");
	printf("Вывод магнитного момента и энергии в магнитном поле для атома водорода\n");
	printf("\n");

	setlocale(LC_ALL, "C");

	long double h = (B_max - B_min) / N;
	long double B = B_min;

	long double mu_0 = 0.0;
	long double mu_1 = 0.0;
	long double mu_2 = 0.0;
	long double mu_3 = 0.0;


	long double E_0 = 0.0;
	long double E_1 = 0.0;
	long double E_2 = 0.0;
	long double E_3 = 0.0;



	// вывод полученных результатов в файл









	FILE *fd;

	fopen_s(&fd, filename, "wb");



	char string_name_1[256] = "/0";

	//char string_name_2[] =filename;

	strncpy_s(string_name_1, filename, strlen(filename) - 4); //-V112

	//strlen(string_name)


	strcat_s(string_name_1, "_energy.txt");


	// вывод полученных результатов в файл
	FILE *fd1;

	fopen_s(&fd1, string_name_1, "wb");




	if (fd == NULL || fd1 == NULL) {
		fprintf(stderr, "Ошибка открытия выводного файла.\n");
		cout << endl;
		SleepEx(40, true); // пауза для того, чтобы успеть прочитать информацию
		exit(1);
	}
	else {
		setlocale(LC_ALL, "rus"); // корректное отображение Кириллицы



		setlocale(LC_ALL, "C"); // установить используемую системой локаль для корректной отображении точки в выходном файле

		for (size_t i = 0; i <= N; i = i + 1) {

			mu_H(0, B, mu_0, E_0);
			mu_H(1, B, mu_1, E_1);
			mu_H(2, B, mu_2, E_2);
			mu_H(3, B, mu_3, E_3);




			fprintf(fd, "%.9Le %.9Le %.9Le %.9Le %.9Le \n", B, mu_0, mu_1, mu_2, mu_3);
			fprintf(fd1, "%.9Le %.9Le %.9Le %.9Le %.9Le \n", B, E_0, E_1, E_2, E_3);

			B = B + h;
		}


	}





	setlocale(LC_ALL, "rus"); // корректное отображение Кириллицы

	fclose(fd);
	fclose(fd1);

}


long double mu_D(size_t index, long double B, long double &mu_temp, long double &E_temp) {

	if (fabs(B - 0.0) <= epsilon) {
		B = 0.001;
	}


	long double h = 4.13566766225; //10^-15 эВ*сек

	long double c_speed = 2.99792458; // 10^10 см/сек

	long double mu_bor = 5.788381806638; // 10^-9 эВ/Гс

	long double mu = 0.0;
	long double E = 0.0;

	long double m = 1.00727646667991 + 1.0086649158849 + 5.4857990907016 / 1000.0;
	long double m_electron = 5.4857990907016 / 1000.0;

	// масса приходит в a.e.m

	m = m * 931493614.8385;		   // теперь масса в эВ
	m_electron = m_electron * 931493614.8385;		   // теперь масса в эВ

	long double B_critical = 117.0;

	long double x = B / B_critical;

	long double E_HFS = 327384300.0;

	if (index == 2) {

		E = E_HFS * (1.0 / 3.0 + 0.5*x);
		E_temp = E;
		mu = E_HFS * 0.5*x / B;
		mu_temp = E_HFS * 0.5*x / B;


	}
	if (index == 0) {

		E = E_HFS * (-1.0 / 6.0 + 0.5*pow(pow(x, 2.0) + 2.0*x / 3.0 + 1.0, 1.0 / 2.0));
		E_temp = E;
		mu = 0.0*E_HFS * 0.5*(pow(x, 2.0) + x / 3.0) / (pow(pow(x, 2.0) + 2.0*x / 3.0 + 1.0, 1.0 / 2.0)*B);
		mu_temp = E_HFS * 0.5*(pow(x, 2.0) + x / 3.0) / (pow(pow(x, 2.0) + 2.0*x / 3.0 + 1.0, 1.0 / 2.0)*B); //-V656
	}
	if (index == 3) {
		E = E_HFS * (-1.0 / 6.0 + 0.5*pow(pow(x, 2.0) - 2.0*x / 3.0 + 1.0, 1.0 / 2.0));
		E_temp = E;
		mu = E_HFS * 0.5*(pow(x, 2.0) - x / 3.0) / (pow(pow(x, 2.0) - 2.0*x / 3.0 + 1.0, 1.0 / 2.0)*B);
		mu_temp = E_HFS * 0.5*(pow(x, 2.0) - x / 3.0) / (pow(pow(x, 2.0) - 2.0*x / 3.0 + 1.0, 1.0 / 2.0)*B); //-V656

	}
	if (index == 4) {

		E = E_HFS * (1.0 / 3.0 - 0.5*x);
		E_temp = E;
		mu = -E_HFS * 0.5*x / B;
		mu_temp = -E_HFS * 0.5*x / B;
	}
	if (index == 1) { //-V112

		E = E_HFS * (-1.0 / 6.0 - 0.5*pow(pow(x, 2.0) - 2.0*x / 3.0 + 1.0, 1.0 / 2.0));
		E_temp = E;
		mu = -0.0*E_HFS * 0.5*(pow(x, 2.0) - x / 3.0) / (pow(pow(x, 2.0) - 2.0*x / 3.0 + 1.0, 1.0 / 2.0)*B);
		mu_temp = -E_HFS * 0.5*(pow(x, 2.0) - x / 3.0) / (pow(pow(x, 2.0) - 2.0*x / 3.0 + 1.0, 1.0 / 2.0)*B); //-V656
	}

	if (index == 5) {

		E = E_HFS * (-1.0 / 6.0 - 0.5*pow(pow(x, 2.0) + 2.0*x / 3.0 + 1.0, 1.0 / 2.0));
		E_temp = E;
		mu = -E_HFS * 0.5*(pow(x, 2.0) + x / 3.0) / (pow(pow(x, 2.0) + 2.0*x / 3.0 + 1.0, 1.0 / 2.0)*B);
		mu_temp = -E_HFS * 0.5*(pow(x, 2.0) + x / 3.0) / (pow(pow(x, 2.0) + 2.0*x / 3.0 + 1.0, 1.0 / 2.0)*B); //-V656
	}




	E_temp = E_temp / pow(10.0, 9.0);

	mu_temp = (mu_temp*h / mu_bor)*pow(10.0, -6.0);

	mu = (mu*h / mu_bor)*pow(10.0, -6.0);

	return mu;
}

void out_mu_D(const char *filename, long double B_min, long double B_max, size_t N) {

	setlocale(LC_ALL, "rus");

	printf("\n");
	printf("Вывод магнитного момента и энергии в магнитном поле для атома дейтерия\n");
	printf("\n");

	setlocale(LC_ALL, "C");

	long double h = (B_max - B_min) / N;
	long double B = B_min;

	long double mu_0 = 0.0;
	long double mu_1 = 0.0;
	long double mu_2 = 0.0;
	long double mu_3 = 0.0;
	long double mu_4 = 0.0;
	long double mu_5 = 0.0;



	long double E_0 = 0.0;
	long double E_1 = 0.0;
	long double E_2 = 0.0;
	long double E_3 = 0.0;
	long double E_4 = 0.0;
	long double E_5 = 0.0;



	// вывод полученных результатов в файл









	FILE *fd;

	fopen_s(&fd, filename, "wb");



	char string_name_1[256] = "/0";

	//char string_name_2[] =filename;

	strncpy_s(string_name_1, filename, strlen(filename) - 4); //-V112

	//strlen(string_name)


	strcat_s(string_name_1, "_energy.txt");


	// вывод полученных результатов в файл
	FILE *fd1;

	fopen_s(&fd1, string_name_1, "wb");




	if (fd == NULL || fd1 == NULL) {
		fprintf(stderr, "Ошибка открытия выводного файла.\n");
		cout << endl;
		SleepEx(40, true); // пауза для того, чтобы успеть прочитать информацию
		exit(1);
	}
	else {
		setlocale(LC_ALL, "rus"); // корректное отображение Кириллицы



		setlocale(LC_ALL, "C"); // установить используемую системой локаль для корректной отображении точки в выходном файле

		for (size_t i = 0; i <= N; i = i + 1) {

			mu_D(0, B, mu_0, E_0);
			mu_D(1, B, mu_1, E_1);
			mu_D(2, B, mu_2, E_2);
			mu_D(3, B, mu_3, E_3);
			mu_D(4, B, mu_4, E_4); //-V112
			mu_D(5, B, mu_5, E_5);



			fprintf(fd, "%.9Le %.9Le %.9Le %.9Le %.9Le %.9Le %.9Le \n", B, mu_0, mu_1, mu_2, mu_3, mu_4, mu_5);
			fprintf(fd1, "%.9Le %.9Le %.9Le %.9Le %.9Le %.9Le %.9Le \n", B, E_0, E_1, E_2, E_3, E_4, E_5);

			B = B + h;
		}


	}





	setlocale(LC_ALL, "rus"); // корректное отображение Кириллицы

	fclose(fd);
	fclose(fd1);

}




long double mu_H_2(size_t index, long double B, long double &mu_temp, long double &E_temp) {

	//long double mu_temp = 0.0;
	//long double E_temp = 0.0;

	if (fabs(B - 0.0) <= epsilon) {
		B = 0.001;
	}


	long double h = 4.13566766225; //10^-15 эВ*сек

	long double c_speed = 2.99792458; // 10^10 см/сек

	long double mu_bor = 5.788381806638; // 10^-9 эВ/Гс

	long double m = 2.0*(1.00727646667991 + 5.4857990907016 / 1000.0);
	long double m_electron = 5.4857990907016 / 1000.0;

	// масса приходит в a.e.m

	m = m * 931493614.8385;		   // теперь масса в эВ
	m_electron = m_electron * 931493614.8385;		   // теперь масса в эВ

	long double sigma_iso = 28.26*pow(10.0, -6.0);
	long double sigma_anis = 25.35*pow(10.0, -6.0);
	long double sigma_perp = sigma_iso + 2.0*sigma_anis / 3.0;
	long double sigma_parall = sigma_iso - sigma_anis / 3.0;
	long double sigma = 2.0*sigma_perp / 3.0 + sigma_parall / 3.0;
	long double sigma_HF = -0.59*pow(10.0, -5.0);
	long double sigma_L = sigma - sigma_HF;

	long double dzeta_perp = 0.0;
	long double dzeta_parall = 0.0;
	long double dzeta_iso = 0.0;
	long double dzeta_anis = 0.0;
	long double dzeta = 0.0;
	long double dzeta_HF = 1.719*6.241506363094 / (10.0*h); //10^-6 Гц/ГС^2
	long double dzeta_L = 0.0;
	long double alpha = (1.0 / (8.0*M_PI))*pow(8.0*pow(M_PI, 5.0) / 15.0, -1.0 / 3.0);	  // постоянная тонкой структуры 1/137.138

	long double r_aver_pow_2 = 0.7258; //10^-16 см^2
	long double x_0_aver_pow_2 = 0.2144; //10^-16 см^2
	long double y_0_aver_pow_2 = 0.2144; //10^-16 см^2
	long double z_0_aver_pow_2 = 0.2969; //10^-16 см^2


	dzeta_perp = (m_electron / m)*m_electron*mu_bor*mu_bor*pow(2.0*M_PI, 2.0)*(r_aver_pow_2 + z_0_aver_pow_2) / (pow(h, 3.0)*pow(c_speed, 2.0))*pow(10.0, -9.0) + 1.5*dzeta_HF*pow(10.0, -6);

	dzeta_parall = (m_electron / m)*m_electron*mu_bor*mu_bor*pow(2.0*M_PI, 2.0)*(x_0_aver_pow_2 + y_0_aver_pow_2) / (pow(h, 3.0)*pow(c_speed, 2.0))*pow(10.0, -9.0);
	dzeta_iso = dzeta_perp / 3.0 + 2.0*dzeta_parall / 3.0;
	dzeta_anis = dzeta_perp - dzeta_parall;


	dzeta = 2.0*dzeta_perp / 3.0 + dzeta_parall / 3.0;
	dzeta_L = dzeta - dzeta_HF;

	//cout << dzeta_perp << " " << dzeta_parall << endl;

	long double a = 4258.0*B;
	long double b = 671.7*B;
	long double c = 113904.0;
	long double d = 57671.0;

	long double f = (dzeta_perp - dzeta_parall)*pow(B, 2.0) / 5.0;
	long double g = (dzeta_perp / 3.0 - dzeta_parall / 6.0)*pow(B, 2.0);

	//cout << f << " " << g << endl;

	//f = -27.6*pow(10.0, -6.0)*pow(B, 2.0);
	//g = (3.0*dzeta_parall*pow(B, 2.0) + 10.0*f)/6.0;

	//cout << f << " " << g << endl;


	long double K_2 = pow(a - b, 2.0) / (2.0*c - 3.0*d);
	long double K_2_ = 2.0*pow(a - b, 2.0) / (3.0*(c + 7.5*d));

	long double C_2 = (pow(c + 1.5*d, 2.0) + 4.5*pow(d, 2.0)) / (a - b);
	long double C_2_ = pow(c - 1.5*d, 2.0) / (a - b);
	long double C_3 = (pow(c + 1.5*d, 2.0)*(c - 4.5*d)) / pow(a - b, 2.0);


	long double aa1 = 1.0;
	long double bb1 = -(2.0*c + 3.0*d);
	long double cc1 = -(pow(a - b, 2.0) + pow(c, 2.0) + 45.0*pow(d, 2.0) / 4.0 + c * d);
	long double dd1 = 2.0*pow(a - b, 2.0)*d - 0.5*(d - 2.0*c)*(-2.5*d + c)*(5.0*d + 2.0*c);

	long double d_B = 0.001;

	B = B + d_B;

	a = 4258.0*B;
	b = 671.7*B;



	long double aa2 = 1.0;
	long double bb2 = -(2.0*c + 3.0*d);
	long double cc2 = -(pow(a - b, 2.0) + pow(c, 2.0) + 45.0*pow(d, 2.0) / 4.0 + c * d);
	long double dd2 = 2.0*pow(a - b, 2.0)*d - 0.5*(d - 2.0*c)*(-2.5*d + c)*(5.0*d + 2.0*c);
	long double *roots_1 = new long double[3];
	roots_1[0] = 0.0;
	roots_1[1] = 0.0;
	roots_1[2] = 0.0;

	long double *roots_2 = new long double[3];
	roots_2[0] = 0.0;
	roots_2[1] = 0.0;
	roots_2[2] = 0.0;

	B = B - d_B;

	a = 4258.0*B;
	b = 671.7*B;

	Cubic(roots_1, bb1, cc1, dd1);
	Cubic(roots_2, bb2, cc2, dd2);

	long double E_1 = roots_1[0];
	long double mu_1 = (roots_2[0] - roots_1[0]) / d_B;

	long double E_2 = roots_1[1];
	long double mu_2 = (roots_2[1] - roots_1[1]) / d_B;

	long double E_3 = roots_1[2];
	long double mu_3 = (roots_2[2] - roots_1[2]) / d_B;


	//cout << mu_1 <<" "<<mu_2<<" "<<mu_3<< endl;
	//	cout << roots_1[0] << " " << roots_1[1] << " " << roots_1[2] << endl;
	//	cout << roots_2[0] << " " << roots_2[1] << " " << roots_2[2] << endl;

	long double E = 0.0;
	long double mu = 0.0;



	long double B_min = 3.5;
	long double B_max = 1000.0;
	//	B > B_min&&B < B_max

	if (B > B_min && B < B_max) {
		if (index == 0) {

			E = 0.5*(a + b - 2.0*d) - 0.5*(pow(pow(a - b, 2.0) + 4.0*pow(-c + 1.5*d, 2.0), 1.0 / 2.0));
			E_temp = E;
			mu = 0.0*(0.5*(a + b) / B - pow(a - b, 2.0) / (2.0*B*(pow(pow(a - b, 2.0) + 4.0*pow(-c + 1.5*d, 2.0), 1.0 / 2.0))));
			mu_temp = 0.5*(a + b) / B - pow(a - b, 2.0) / (2.0*B*(pow(pow(a - b, 2.0) + 4.0*pow(-c + 1.5*d, 2.0), 1.0 / 2.0)));


		}
		if (index == 1) {

			E = E_3;
			E_temp = E;
			mu = 0.0*mu_3;
			mu_temp = mu_3;
		}
		if (index == 2) {
			E = 0.5*(-a - b - 2.0*d) + 0.5*(pow(pow(a - b, 2.0) + 4.0*pow(-c + 1.5*d, 2.0), 1.0 / 2.0));
			E_temp = E;
			mu = 0.0*(-0.5*(a + b) / B + pow(a - b, 2.0) / (2.0*B*(pow(pow(a - b, 2.0) + 4.0*pow(-c + 1.5*d, 2.0), 1.0 / 2.0))));
			mu_temp = -0.5*(a + b) / B + pow(a - b, 2.0) / (2.0*B*(pow(pow(a - b, 2.0) + 4.0*pow(-c + 1.5*d, 2.0), 1.0 / 2.0)));
		}
		if (index == 3) {

			E = 0.0;
			E_temp = E;
			mu = 0.0;
			mu_temp = mu;
		}
		if (index == 4) { //-V112

			E = 0.0;
			E_temp = E;
			mu = 0.0;
			mu_temp = mu;
		}
		if (index == 5) {

			E = 0.0;
			E_temp = E;
			mu = 0.0;
			mu_temp = mu;
		}
		if (index == 6) {

			E = (a + b) - c + 0.5*d;
			E_temp = E;
			mu = (a + b) / B;
			mu_temp = mu;

		}
		if (index == 7) {
			E = 0.5*(a + b - 2 * d) + 0.5*(pow(pow(a - b, 2.0) + 4.0*pow(-c + 1.5*d, 2.0), 1.0 / 2.0));
			E_temp = E;
			mu = 0.5*(a + b) / B + pow(a - b, 2.0) / (2.0*B*(pow(pow(a - b, 2.0) + 4.0*pow(-c + 1.5*d, 2.0), 1.0 / 2.0)));
			mu_temp = mu;

		}
		if (index == 8) {

			E = E_2;
			E_temp = E;
			mu = mu_2;
			mu_temp = mu_2;

		}
		if (index == 9) {

			E = E_1;
			E_temp = E;
			mu = mu_1;
			mu_temp = mu_1;
		}
		if (index == 10) {
			E = 0.5*(-a - b - 2 * d) - 0.5*(pow(pow(a - b, 2.0) + 4.0*pow(-c + 1.5*d, 2.0), 1.0 / 2.0));
			E_temp = E;
			mu = -0.5*(a + b) / B - pow(a - b, 2.0) / (2.0*B*(pow(pow(a - b, 2.0) + 4.0*pow(-c + 1.5*d, 2.0), 1.0 / 2.0)));
			mu_temp = mu;
		}
		if (index == 11) {

			E = -(a + b) - c + 0.5*d;
			E_temp = E;
			mu = -(a + b) / B;
			mu_temp = mu;
		}

	}
	if (B >= B_max) {
		if (index == 0) {

			E = (1.0 - sigma_mu(sigma_iso, sigma_anis, 1.0, -1.0))*b - d - f / 3.0 - g;
			E_temp = E;
			mu = 0.0*((1.0 - sigma_mu(sigma_iso, sigma_anis, 1.0, -1.0))*b / B - 2.0*f / (3.0*B) - 2.0*g / B);
			mu_temp = (1.0 - sigma_mu(sigma_iso, sigma_anis, 1.0, -1.0))*b / B - 2.0*f / (3.0*B) - 2.0*g / B;

		}
		if (index == 1) {

			E = 2.0*d + 2.0 / 3.0 * f - g + 2.0*C_3;
			E_temp = E;
			mu = 0.0*(4.0*f / (3.0*B) - 2.0*g / B + 2.0*(-2.0*C_3 / B));
			mu_temp = 4.0*f / (3.0*B) - 2.0*g / B + 2.0*(-2.0*C_3 / B);

		}
		if (index == 2) {
			E = -(1.0 - sigma_mu(sigma_iso, sigma_anis, 1.0, 1.0))*b - d - f / 3.0 - g + C_2_;
			E_temp = E;
			mu = 0.0*(-(1.0 - sigma_mu(sigma_iso, sigma_anis, 1.0, 1.0))*b / B - 2.0*f / (3.0*B) - 2.0*g / B - 2.0*C_2_ / B);
			mu_temp = -(1.0 - sigma_mu(sigma_iso, sigma_anis, 1.0, 1.0))*b / B - 2.0*f / (3.0*B) - 2.0*g / B - 2.0*C_2_ / B;

		}
		if (index == 3) {

			E = 0.0;
			E_temp = E;
			mu = 0.0;
			mu_temp = mu;
		}
		if (index == 4) { //-V112

			E = 0.0;
			E_temp = E;
			mu = 0.0;
			mu_temp = mu;
		}
		if (index == 5) {

			E = 0.0;
			E_temp = E;
			mu = 0.0;
			mu_temp = mu;
		}
		if (index == 6) {

			E = (1.0 - sigma_mu(sigma_iso, sigma_anis, 1.0, -1.0))*a + (1.0 - sigma_mu(sigma_iso, sigma_anis, 1.0, -1.0))*b - c + 0.5*d - f / 3.0 - g;
			E_temp = E;
			mu = (1.0 - sigma_mu(sigma_iso, sigma_anis, 1.0, -1.0))*a / B + (1.0 - sigma_mu(sigma_iso, sigma_anis, 1.0, -1.0))*b / B - 2.0*f / (3.0*B) - 2.0*g / B;
			mu_temp = mu;

		}
		if (index == 7) {
			E = (1.0 - sigma_mu(sigma_iso, sigma_anis, 0.0, -1.0))*a - d + 2.0*f / 3.0 - g + C_2_;
			E_temp = E;
			mu = (1.0 - sigma_mu(sigma_iso, sigma_anis, 0.0, -1.0))*a / B - 4.0*f / (3.0*B) - 2.0*g / B - 2.0*C_2_ / B;
			mu_temp = mu;

		}
		if (index == 8) {

			E = (1.0 - sigma_mu(sigma_iso, sigma_anis, 1.0, -1.0))*a - (1.0 - sigma_mu(sigma_iso, sigma_anis, 1.0, 1.0))*b + c + 0.5*d - f / 3.0 - g + C_2 - C_3;
			E_temp = E;
			mu = (1.0 - sigma_mu(sigma_iso, sigma_anis, 1.0, -1.0))*a / B - (1.0 - sigma_mu(sigma_iso, sigma_anis, 1.0, 1.0))*b / B - 2.0*f / (3.0*B) - 2.0*g / B - 2.0*C_2 / B + 2.0*C_3 / B;
			mu_temp = mu;

		}
		if (index == 9) {

			E = -(1.0 - sigma_mu(sigma_iso, sigma_anis, 1.0, 1.0))*a + (1.0 - sigma_mu(sigma_iso, sigma_anis, 1.0, -1.0))*b + c + 0.5*d - f / 3.0 - g - C_2 - C_3;
			E_temp = E;
			mu = -(1.0 - sigma_mu(sigma_iso, sigma_anis, 1.0, 1.0))*a / B + (1.0 - sigma_mu(sigma_iso, sigma_anis, 1.0, -1.0))*b / B - 2.0*f / (3.0*B) - 2.0*g / B + 2.0*C_2 / B + 2.0*C_3 / B;
			mu_temp = mu;

		}
		if (index == 10) {
			E = -(1.0 - sigma_mu(sigma_iso, sigma_anis, 0.0, 1.0))*a - d + 2.0*f / 3.0 - g - C_2_;
			E_temp = E;
			mu = -(1.0 - sigma_mu(sigma_iso, sigma_anis, 0.0, 1.0))*a / B - 4.0*f / (3.0*B) - 2.0*g / B + 2.0*C_2_ / B;
			mu_temp = mu;

		}
		if (index == 11) {

			E = -(1.0 - sigma_mu(sigma_iso, sigma_anis, 1.0, 1.0))*a - (1.0 - sigma_mu(sigma_iso, sigma_anis, 1.0, 1.0))*b - c + 0.5*d - f / 3.0 - g;
			E_temp = E;
			mu = -(1.0 - sigma_mu(sigma_iso, sigma_anis, 1.0, 1.0))*a / B - (1.0 - sigma_mu(sigma_iso, sigma_anis, 1.0, 1.0))*b / B - 2.0*f / (3.0*B) - 2.0*g / B;
			mu_temp = mu;
		}

	}
	if (B <= B_min) {

		if (index == 0) {
			E = -c + 0.5*d + 0.5*(a + b) - 0.25*K_2;
			E_temp = E;
			mu = 0.0*(0.5*(a + b) / B - 0.5*K_2 / B);
			mu_temp = 0.5*(a + b) / B - 0.5*K_2 / B;

		}
		if (index == 1) {

			E = c - 2.5*d + K_2 / 3.0 - K_2_;
			E_temp = E;
			mu = 0.0*(2.0*K_2 / (3.0*B) - 2.0*K_2_ / B);
			mu_temp = 2.0*K_2 / (3.0*B) - 2.0*K_2_ / B;

		}
		if (index == 2) {
			E = c - 2.5*d - 0.5*(a + b) + 0.25*K_2;
			E_temp = E;
			mu = 0.0*(-0.5*(a + b) / B + 0.5*K_2 / B);
			mu_temp = -0.5*(a + b) / B + 0.5*K_2 / B;

		}
		if (index == 3) {

			E = 0.0;
			E_temp = E;
			mu = 0.0;
			mu_temp = mu;
		}
		if (index == 4) { //-V112

			E = 0.0;
			E_temp = E;
			mu = 0.0;
			mu_temp = mu;
		}
		if (index == 5) {

			E = 0.0;
			E_temp = E;
			mu = 0.0;
			mu_temp = mu;
		}
		if (index == 6) {

			E = -c + 0.5*d + (a + b);
			E_temp = E;
			mu = (a + b) / B;
			mu_temp = mu;

		}
		if (index == 7) {
			E = c - 2.5*d + 0.5*(a + b) + 0.25*K_2;
			E_temp = E;
			mu = 0.5*(a + b) / B + 0.5*K_2 / B;
			mu_temp = mu;

		}
		if (index == 8) {

			E = 2.0*c + 5.0*d + K_2_;
			E_temp = E;
			mu = 2.0*K_2_ / B;
			mu_temp = mu;

		}
		if (index == 9) {

			E = -c + 0.5*d - K_2 / 3.0;
			E_temp = E;
			mu = -2.0*K_2 / (3.0*B);
			mu_temp = mu;

		}
		if (index == 10) {
			E = -c + 0.5*d - 0.5*(a + b) - 0.25*K_2;
			E_temp = E;
			mu = -0.5*(a + b) / B - 0.5*K_2 / B;
			mu_temp = mu;

		}
		if (index == 11) {

			E = -c + 0.5*d - (a + b);
			E_temp = E;
			mu = -(a + b) / B;
			mu_temp = mu;
		}

	}


	delete[] roots_1;
	delete[] roots_2;



	roots_1 = nullptr;

	roots_2 = nullptr;

	E_temp = E_temp / pow(10.0, 3.0);

	mu_temp = (mu_temp*h / mu_bor)*pow(10.0, -6.0);

	mu = (mu*h / mu_bor)*pow(10.0, -6.0);

	return mu;
}

void out_mu_H_2(const char *filename, long double B_min, long double B_max, size_t N) {

	setlocale(LC_ALL, "rus");

	printf("\n");
	printf("Вывод магнитного момента и энергии в магнитном поле для молекулы водорода\n");
	printf("\n");

	setlocale(LC_ALL, "C");

	long double h = (B_max - B_min) / N;
	long double B = B_min;

	long double mu_0 = 0.0;
	long double mu_1 = 0.0;
	long double mu_2 = 0.0;
	long double mu_3 = 0.0;
	long double mu_4 = 0.0;
	long double mu_5 = 0.0;
	long double mu_6 = 0.0;
	long double mu_7 = 0.0;
	long double mu_8 = 0.0;
	long double mu_9 = 0.0;
	long double mu_10 = 0.0;
	long double mu_11 = 0.0;

	long double E_0 = 0.0;
	long double E_1 = 0.0;
	long double E_2 = 0.0;
	long double E_3 = 0.0;
	long double E_4 = 0.0;
	long double E_5 = 0.0;
	long double E_6 = 0.0;
	long double E_7 = 0.0;
	long double E_8 = 0.0;
	long double E_9 = 0.0;
	long double E_10 = 0.0;
	long double E_11 = 0.0;


	// вывод полученных результатов в файл









	FILE *fd;

	fopen_s(&fd, filename, "wb");



	char string_name_1[256] = "/0";

	//char string_name_2[] =filename;

	strncpy_s(string_name_1, filename, strlen(filename) - 4); //-V112

	//strlen(string_name)


	strcat_s(string_name_1, "_energy.txt");


	// вывод полученных результатов в файл
	FILE *fd1;

	fopen_s(&fd1, string_name_1, "wb");




	if (fd == NULL || fd1 == NULL) {
		fprintf(stderr, "Ошибка открытия выводного файла.\n");
		cout << endl;
		SleepEx(40, true); // пауза для того, чтобы успеть прочитать информацию
		exit(1);
	}
	else {
		setlocale(LC_ALL, "rus"); // корректное отображение Кириллицы



		setlocale(LC_ALL, "C"); // установить используемую системой локаль для корректной отображении точки в выходном файле

		for (size_t i = 0; i <= N; i = i + 1) {

			mu_H_2(0, B, mu_0, E_0);
			mu_H_2(1, B, mu_1, E_1);
			mu_H_2(2, B, mu_2, E_2);
			mu_H_2(3, B, mu_3, E_3);
			mu_H_2(4, B, mu_4, E_4); //-V112
			mu_H_2(5, B, mu_5, E_5);
			mu_H_2(6, B, mu_6, E_6);
			mu_H_2(7, B, mu_7, E_7);
			mu_H_2(8, B, mu_8, E_8);
			mu_H_2(9, B, mu_9, E_9);
			mu_H_2(10, B, mu_10, E_10);
			mu_H_2(11, B, mu_11, E_11);



			fprintf(fd, "%.9Le %.9Le %.9Le %.9Le %.9Le %.9Le %.9Le %.9Le %.9Le %.9Le %.9Le %.9Le %.9Le\n", B, mu_0, mu_1, mu_2, mu_3, mu_4, mu_5, mu_6, mu_7, mu_8, mu_9, mu_10, mu_11);
			fprintf(fd1, "%.9Le %.9Le %.9Le %.9Le %.9Le %.9Le %.9Le %.9Le %.9Le %.9Le %.9Le %.9Le %.9Le\n", B, E_0, E_1, E_2, E_3, E_4, E_5, E_6, E_7, E_8, E_9, E_10, E_11);

			B = B + h;
		}


	}





	setlocale(LC_ALL, "rus"); // корректное отображение Кириллицы

	fclose(fd);
	fclose(fd1);

}


long double mu_D_2(size_t index, long double B, long double &mu_temp, long double &E_temp) {

	//long double mu_temp = 0.0;
	//long double E_temp = 0.0;

	if (fabs(B - 0.0) <= epsilon) {
		B = 0.001;
	}


	long double h = 4.13566766225; //10^-15 эВ*сек

	long double c_speed = 2.99792458; // 10^10 см/сек

	long double mu_bor = 5.788381806638; // 10^-9 эВ/Гс

	long double m = 2.0*(1.00727646667991 + 1.0086649158849 + 5.4857990907016 / 1000.0);
	long double m_electron = 5.4857990907016 / 1000.0;

	// масса приходит в a.e.m

	m = m * 931493614.8385;		   // теперь масса в эВ
	m_electron = m_electron * 931493614.8385;		   // теперь масса в эВ

	long double sigma_iso = 28.26*pow(10.0, -6.0);
	long double sigma_anis = 25.35*pow(10.0, -6.0);
	long double sigma_perp = sigma_iso + 2.0*sigma_anis / 3.0;
	long double sigma_parall = sigma_iso - sigma_anis / 3.0;
	long double sigma = 2.0*sigma_perp / 3.0 + sigma_parall / 3.0;
	long double sigma_HF = -0.59*pow(10.0, -5.0);
	long double sigma_L = sigma - sigma_HF;

	long double dzeta_perp = 0.0;
	long double dzeta_parall = 0.0;
	long double dzeta_iso = 0.0;
	long double dzeta_anis = 0.0;
	long double dzeta = 0.0;
	long double dzeta_HF = 1.622*6.241506363094 / (10.0*h); //10^-6 Гц/ГС^2
	long double dzeta_L = 0.0;
	long double alpha = (1.0 / (8.0*M_PI))*pow(8.0*pow(M_PI, 5.0) / 15.0, -1.0 / 3.0);	  // постоянная тонкой структуры 1/137.138

	long double r_aver_pow_2 = 0.7258; //10^-16 см^2
	long double x_0_aver_pow_2 = 0.2144; //10^-16 см^2
	long double y_0_aver_pow_2 = 0.2144; //10^-16 см^2
	long double z_0_aver_pow_2 = 0.2969; //10^-16 см^2


	dzeta_perp = (m_electron / m)*m_electron*mu_bor*mu_bor*pow(2.0*M_PI, 2.0)*(r_aver_pow_2 + z_0_aver_pow_2) / (pow(h, 3.0)*pow(c_speed, 2.0))*pow(10.0, -9.0) + 1.5*dzeta_HF*pow(10.0, -6);

	dzeta_parall = (m_electron / m)*m_electron*mu_bor*mu_bor*pow(2.0*M_PI, 2.0)*(x_0_aver_pow_2 + y_0_aver_pow_2) / (pow(h, 3.0)*pow(c_speed, 2.0))*pow(10.0, -9.0);
	dzeta_iso = dzeta_perp / 3.0 + 2.0*dzeta_parall / 3.0;
	dzeta_anis = dzeta_perp - dzeta_parall;


	dzeta = 2.0*dzeta_perp / 3.0 + dzeta_parall / 3.0;
	dzeta_L = dzeta - dzeta_HF;

	//cout << dzeta_perp << " " << dzeta_parall << endl;

	long double a = 653.6*B;
	long double b = 336.8*B;
	long double c = 8788.0;
	long double d = 25237.0;

	long double f = (dzeta_perp - dzeta_parall)*pow(B, 2.0) / 5.0;
	long double g = (dzeta_perp / 3.0 - dzeta_parall / 6.0)*pow(B, 2.0);

	//cout << f << " " << g << endl;

	//f = -26.2*pow(10.0, -6.0)*pow(B, 2.0);
	//g = (3.0*dzeta_parall*pow(B, 2.0) + 10.0*f)/6.0;

	//cout << f << " " << g << endl;


	long double K_2 = pow(a - b, 2.0) / (2.0*c - 3.0*d);
	long double K_2_ = 2.0*pow(a - b, 2.0) / (3.0*(c + 7.5*d));

	long double C_2 = (pow(c + 1.5*d, 2.0) + 4.5*pow(d, 2.0)) / (a - b);
	long double C_2_ = pow(c - 1.5*d, 2.0) / (a - b);
	long double C_3 = (pow(c + 1.5*d, 2.0)*(c - 4.5*d)) / pow(a - b, 2.0);


	long double aa1 = 1.0;
	long double bb1 = -(2.0*c + 3.0*d);
	long double cc1 = -(pow(a - b, 2.0) + pow(c, 2.0) + 45.0*pow(d, 2.0) / 4.0 + c * d);
	long double dd1 = 2.0*pow(a - b, 2.0)*d - 0.5*(d - 2.0*c)*(-2.5*d + c)*(5.0*d + 2.0*c);

	long double d_B = 0.001;

	B = B + d_B;

	a = 653.6*B;
	b = 336.8*B;



	long double aa2 = 1.0;
	long double bb2 = -(2.0*c + 3.0*d);
	long double cc2 = -(pow(a - b, 2.0) + pow(c, 2.0) + 45.0*pow(d, 2.0) / 4.0 + c * d);
	long double dd2 = 2.0*pow(a - b, 2.0)*d - 0.5*(d - 2.0*c)*(-2.5*d + c)*(5.0*d + 2.0*c);
	long double *roots_1 = new long double[3];
	roots_1[0] = 0.0;
	roots_1[1] = 0.0;
	roots_1[2] = 0.0;

	long double *roots_2 = new long double[3];
	roots_2[0] = 0.0;
	roots_2[1] = 0.0;
	roots_2[2] = 0.0;

	B = B - d_B;

	a = 653.6*B;
	b = 336.8*B;

	Cubic(roots_1, bb1, cc1, dd1);
	Cubic(roots_2, bb2, cc2, dd2);

	long double E_1 = roots_1[0];
	long double mu_1 = (roots_2[0] - roots_1[0]) / d_B;

	long double E_2 = roots_1[1];
	long double mu_2 = (roots_2[1] - roots_1[1]) / d_B;

	long double E_3 = roots_1[2];
	long double mu_3 = (roots_2[2] - roots_1[2]) / d_B;


	//cout << mu_1 <<" "<<mu_2<<" "<<mu_3<< endl;
	//	cout << roots_1[0] << " " << roots_1[1] << " " << roots_1[2] << endl;
	//	cout << roots_2[0] << " " << roots_2[1] << " " << roots_2[2] << endl;

	long double E = 0.0;
	long double mu = 0.0;



	long double B_min = 3.5;
	long double B_max = 1000.0;
	//	B > B_min&&B < B_max

	if (B > B_min && B < B_max) {
		if (index == 0) {

			E = 0.5*(a + b - 2.0*d) - 0.5*(pow(pow(a - b, 2.0) + 4.0*pow(-c + 1.5*d, 2.0), 1.0 / 2.0));
			E_temp = E;
			mu = 0.0*(0.5*(a + b) / B - pow(a - b, 2.0) / (2.0*B*(pow(pow(a - b, 2.0) + 4.0*pow(-c + 1.5*d, 2.0), 1.0 / 2.0))));
			mu_temp = 0.5*(a + b) / B - pow(a - b, 2.0) / (2.0*B*(pow(pow(a - b, 2.0) + 4.0*pow(-c + 1.5*d, 2.0), 1.0 / 2.0)));


		}
		if (index == 1) {

			E = E_3;
			E_temp = E;
			mu = 0.0*mu_3;
			mu_temp = mu_3;
		}
		if (index == 2) {
			E = 0.5*(-a - b - 2.0*d) + 0.5*(pow(pow(a - b, 2.0) + 4.0*pow(-c + 1.5*d, 2.0), 1.0 / 2.0));
			E_temp = E;
			mu = 0.0*(-0.5*(a + b) / B + pow(a - b, 2.0) / (2.0*B*(pow(pow(a - b, 2.0) + 4.0*pow(-c + 1.5*d, 2.0), 1.0 / 2.0))));
			mu_temp = -0.5*(a + b) / B + pow(a - b, 2.0) / (2.0*B*(pow(pow(a - b, 2.0) + 4.0*pow(-c + 1.5*d, 2.0), 1.0 / 2.0)));
		}
		if (index == 3) {

			E = (a + b) - c + 0.5*d;
			E_temp = E;
			mu = (a + b) / B;
			mu_temp = mu;

		}
		if (index == 4) { //-V112
			E = 0.5*(a + b - 2 * d) + 0.5*(pow(pow(a - b, 2.0) + 4.0*pow(-c + 1.5*d, 2.0), 1.0 / 2.0));
			E_temp = E;
			mu = 0.5*(a + b) / B + pow(a - b, 2.0) / (2.0*B*(pow(pow(a - b, 2.0) + 4.0*pow(-c + 1.5*d, 2.0), 1.0 / 2.0)));
			mu_temp = mu;

		}
		if (index == 5) {

			E = E_2;
			E_temp = E;
			mu = mu_2;
			mu_temp = mu_2;

		}
		if (index == 6) {

			E = E_1;
			E_temp = E;
			mu = mu_1;
			mu_temp = mu_1;
		}
		if (index == 7) {
			E = 0.5*(-a - b - 2 * d) - 0.5*(pow(pow(a - b, 2.0) + 4.0*pow(-c + 1.5*d, 2.0), 1.0 / 2.0));
			E_temp = E;
			mu = -0.5*(a + b) / B - pow(a - b, 2.0) / (2.0*B*(pow(pow(a - b, 2.0) + 4.0*pow(-c + 1.5*d, 2.0), 1.0 / 2.0)));
			mu_temp = mu;
		}
		if (index == 8) {

			E = -(a + b) - c + 0.5*d;
			E_temp = E;
			mu = -(a + b) / B;
			mu_temp = mu;
		}

	}
	if (B >= B_max) {
		if (index == 0) {

			E = (1.0 - sigma_mu(sigma_iso, sigma_anis, 1.0, -1.0))*b - d - f / 3.0 - g;
			E_temp = E;
			mu = 0.0*((1.0 - sigma_mu(sigma_iso, sigma_anis, 1.0, -1.0))*b / B - 2.0*f / (3.0*B) - 2.0*g / B);
			mu_temp = (1.0 - sigma_mu(sigma_iso, sigma_anis, 1.0, -1.0))*b / B - 2.0*f / (3.0*B) - 2.0*g / B;

		}
		if (index == 1) {

			E = 2.0*d + 2.0 / 3.0 * f - g + 2.0*C_3;
			E_temp = E;
			mu = 0.0*(4.0*f / (3.0*B) - 2.0*g / B + 2.0*(-2.0*C_3 / B));
			mu_temp = 4.0*f / (3.0*B) - 2.0*g / B + 2.0*(-2.0*C_3 / B);

		}
		if (index == 2) {
			E = -(1.0 - sigma_mu(sigma_iso, sigma_anis, 1.0, 1.0))*b - d - f / 3.0 - g + C_2_;
			E_temp = E;
			mu = 0.0*(-(1.0 - sigma_mu(sigma_iso, sigma_anis, 1.0, 1.0))*b / B - 2.0*f / (3.0*B) - 2.0*g / B - 2.0*C_2_ / B);
			mu_temp = -(1.0 - sigma_mu(sigma_iso, sigma_anis, 1.0, 1.0))*b / B - 2.0*f / (3.0*B) - 2.0*g / B - 2.0*C_2_ / B;

		}
		if (index == 3) {

			E = (1.0 - sigma_mu(sigma_iso, sigma_anis, 1.0, -1.0))*a + (1.0 - sigma_mu(sigma_iso, sigma_anis, 1.0, -1.0))*b - c + 0.5*d - f / 3.0 - g;
			E_temp = E;
			mu = (1.0 - sigma_mu(sigma_iso, sigma_anis, 1.0, -1.0))*a / B + (1.0 - sigma_mu(sigma_iso, sigma_anis, 1.0, -1.0))*b / B - 2.0*f / (3.0*B) - 2.0*g / B;
			mu_temp = mu;

		}
		if (index == 4) { //-V112
			E = (1.0 - sigma_mu(sigma_iso, sigma_anis, 0.0, -1.0))*a - d + 2.0*f / 3.0 - g + C_2_;
			E_temp = E;
			mu = (1.0 - sigma_mu(sigma_iso, sigma_anis, 0.0, -1.0))*a / B - 4.0*f / (3.0*B) - 2.0*g / B - 2.0*C_2_ / B;
			mu_temp = mu;

		}
		if (index == 5) {

			E = (1.0 - sigma_mu(sigma_iso, sigma_anis, 1.0, -1.0))*a - (1.0 - sigma_mu(sigma_iso, sigma_anis, 1.0, 1.0))*b + c + 0.5*d - f / 3.0 - g + C_2 - C_3;
			E_temp = E;
			mu = (1.0 - sigma_mu(sigma_iso, sigma_anis, 1.0, -1.0))*a / B - (1.0 - sigma_mu(sigma_iso, sigma_anis, 1.0, 1.0))*b / B - 2.0*f / (3.0*B) - 2.0*g / B - 2.0*C_2 / B + 2.0*C_3 / B;
			mu_temp = mu;

		}
		if (index == 6) {

			E = -(1.0 - sigma_mu(sigma_iso, sigma_anis, 1.0, 1.0))*a + (1.0 - sigma_mu(sigma_iso, sigma_anis, 1.0, -1.0))*b + c + 0.5*d - f / 3.0 - g - C_2 - C_3;
			E_temp = E;
			mu = -(1.0 - sigma_mu(sigma_iso, sigma_anis, 1.0, 1.0))*a / B + (1.0 - sigma_mu(sigma_iso, sigma_anis, 1.0, -1.0))*b / B - 2.0*f / (3.0*B) - 2.0*g / B + 2.0*C_2 / B + 2.0*C_3 / B;
			mu_temp = mu;

		}
		if (index == 7) {
			E = -(1.0 - sigma_mu(sigma_iso, sigma_anis, 0.0, 1.0))*a - d + 2.0*f / 3.0 - g - C_2_;
			E_temp = E;
			mu = -(1.0 - sigma_mu(sigma_iso, sigma_anis, 0.0, 1.0))*a / B - 4.0*f / (3.0*B) - 2.0*g / B + 2.0*C_2_ / B;
			mu_temp = mu;

		}
		if (index == 8) {

			E = -(1.0 - sigma_mu(sigma_iso, sigma_anis, 1.0, 1.0))*a - (1.0 - sigma_mu(sigma_iso, sigma_anis, 1.0, 1.0))*b - c + 0.5*d - f / 3.0 - g;
			E_temp = E;
			mu = -(1.0 - sigma_mu(sigma_iso, sigma_anis, 1.0, 1.0))*a / B - (1.0 - sigma_mu(sigma_iso, sigma_anis, 1.0, 1.0))*b / B - 2.0*f / (3.0*B) - 2.0*g / B;
			mu_temp = mu;
		}

	}
	if (B <= B_min) {


		if (index == 0) {
			E = c - 2.5*d + 0.5*(a + b) + 0.25*K_2;
			E_temp = E;
			mu = 0.0*(0.5*(a + b) / B + 0.5*K_2 / B);
			mu_temp = 0.5*(a + b) / B + 0.5*K_2 / B;

		}
		if (index == 1) {

			E = -c + 0.5*d - K_2 / 3.0;
			E_temp = E;
			mu = 0.0*(-2.0*K_2 / (3.0*B));
			mu_temp = -2.0*K_2 / (3.0*B);

		}
		if (index == 2) {
			E = -c + 0.5*d - 0.5*(a + b) - 0.25*K_2;
			E_temp = E;
			mu = 0.0*(-0.5*(a + b) / B - 0.5*K_2 / B);
			mu_temp = -0.5*(a + b) / B - 0.5*K_2 / B;

		}
		if (index == 3) {

			E = -c + 0.5*d + (a + b);
			E_temp = E;
			mu = (a + b) / B;
			mu_temp = mu;

		}
		if (index == 4) { //-V112
			E = -c + 0.5*d + 0.5*(a + b) - 0.25*K_2;
			E_temp = E;
			mu = 0.5*(a + b) / B - 0.5*K_2 / B;
			mu_temp = mu;

		}
		if (index == 5) {

			E = 2.0*c + 5.0*d + K_2_;
			E_temp = E;
			mu = 2.0*K_2_ / B;
			mu_temp = mu;

		}
		if (index == 6) {

			E = c - 2.5*d + K_2 / 3.0 - K_2_;
			E_temp = E;
			mu = 2.0*K_2 / (3.0*B) - 2.0*K_2_ / B;
			mu_temp = mu;

		}
		if (index == 7) {
			E = c - 2.5*d - 0.5*(a + b) + 0.25*K_2;
			E_temp = E;
			mu = -0.5*(a + b) / B + 0.5*K_2 / B;
			mu_temp = mu;

		}
		if (index == 8) {

			E = -c + 0.5*d - (a + b);
			E_temp = E;
			mu = -(a + b) / B;
			mu_temp = mu;
		}






	}


	delete[] roots_1;
	delete[] roots_2;

	roots_1 = nullptr;

	roots_2 = nullptr;


	E_temp = E_temp / pow(10.0, 3.0);

	mu_temp = (mu_temp*h / mu_bor)*pow(10.0, -6.0);

	mu = (mu*h / mu_bor)*pow(10.0, -6.0);

	return mu;
}


void out_mu_D_2(const char *filename, long double B_min, long double B_max, size_t N) {

	setlocale(LC_ALL, "rus");

	printf("\n");
	printf("Вывод магнитного момента и энергии в магнитном поле для молекулы дейтерия\n");
	printf("\n");

	setlocale(LC_ALL, "C");

	long double h = (B_max - B_min) / N;
	long double B = B_min;

	long double mu_0 = 0.0;
	long double mu_1 = 0.0;
	long double mu_2 = 0.0;
	long double mu_3 = 0.0;
	long double mu_4 = 0.0;
	long double mu_5 = 0.0;
	long double mu_6 = 0.0;
	long double mu_7 = 0.0;
	long double mu_8 = 0.0;


	long double E_0 = 0.0;
	long double E_1 = 0.0;
	long double E_2 = 0.0;
	long double E_3 = 0.0;
	long double E_4 = 0.0;
	long double E_5 = 0.0;
	long double E_6 = 0.0;
	long double E_7 = 0.0;
	long double E_8 = 0.0;



	// вывод полученных результатов в файл









	FILE *fd;

	fopen_s(&fd, filename, "wb");



	char string_name_1[256] = "/0";

	//char string_name_2[] =filename;

	strncpy_s(string_name_1, filename, strlen(filename) - 4); //-V112

	//strlen(string_name)


	strcat_s(string_name_1, "_energy.txt");


	// вывод полученных результатов в файл
	FILE *fd1;

	fopen_s(&fd1, string_name_1, "wb");




	if (fd == NULL || fd1 == NULL) {
		fprintf(stderr, "Ошибка открытия выводного файла.\n");
		cout << endl;
		SleepEx(40, true); // пауза для того, чтобы успеть прочитать информацию
		exit(1);
	}
	else {
		setlocale(LC_ALL, "rus"); // корректное отображение Кириллицы



		setlocale(LC_ALL, "C"); // установить используемую системой локаль для корректной отображении точки в выходном файле

		for (size_t i = 0; i <= N; i = i + 1) {

			mu_D_2(0, B, mu_0, E_0);
			mu_D_2(1, B, mu_1, E_1);
			mu_D_2(2, B, mu_2, E_2);
			mu_D_2(3, B, mu_3, E_3);
			mu_D_2(4, B, mu_4, E_4); //-V112
			mu_D_2(5, B, mu_5, E_5);
			mu_D_2(6, B, mu_6, E_6);
			mu_D_2(7, B, mu_7, E_7);
			mu_D_2(8, B, mu_8, E_8);




			fprintf(fd, "%.9Le %.9Le %.9Le %.9Le %.9Le %.9Le %.9Le %.9Le %.9Le %.9Le\n", B, mu_0, mu_1, mu_2, mu_3, mu_4, mu_5, mu_6, mu_7, mu_8);
			fprintf(fd1, "%.9Le %.9Le %.9Le %.9Le %.9Le %.9Le %.9Le %.9Le %.9Le %.9Le\n", B, E_0, E_1, E_2, E_3, E_4, E_5, E_6, E_7, E_8);

			B = B + h;
		}


	}





	setlocale(LC_ALL, "rus"); // корректное отображение Кириллицы

	fclose(fd);
	fclose(fd1);

}





/*Чтение таблицы магнитного поля из файла*/
void ReadFile_magnetic_field_table(const char *filename, vector<long double> &Vector_r_magnetic_field_table, vector<long double> &Vector_phi_magnetic_field_table, vector<long double> &Vector_B_magnetic_field_table, vector<long double> &Vector_delta_B_magnetic_field_table, vector <size_t> &Vector_index_r_magnetic_field_table, size_t &index_phi_magnetic_field_table, long double &m_mag, long double r_min_mag_table, long double r_max_mag_table) {

	/*

	const int N = 256; //Константный размер строки
	//char *FName = filename; //Путь к файлу
	//cout << endl << "ReadFile:  "; //Для красоты
	char S[N] = { "" }; //В S будут считываться строки
	ifstream in1(filename); //Открыли файл для чтения
	while (!in1.eof()) //Будем читать информацию пока не дойдем до конца файла
	{
	in1.getline(S, N); //Построчное считывание информации в S


	//cout << S << endl; //Вывод очередной строки на экран
	//SleepEx(8, true);
	}
	in1.close();  //Закрыли открытый файл

	*/


	//открываем файл с входными данными в режиме чтения
	cout << endl;
	cout << "Открытие файла с входными данными магнитного поля..." << endl;
	FILE *F;
	fopen_s(&F, filename, "r");


	//если открытие файла прошло некорректно, то вывод
	//сообщения об отсутствии такого файла
	if (F == NULL) {
		fprintf(stderr, "Ошибка открытия выводного файла.\n");
		cout << endl;
		SleepEx(40, true); // пауза для того, чтобы успеть прочитать информацию
		exit(1);
	}


	else {

		cout << "Чтение таблицы магнитного поля" << endl;
		cout << endl;

		setlocale(LC_ALL, "C"); // установить используемую системой локаль для корректной отображении точки в выходном файле

		size_t i = 1; // индекс массива
		size_t m = 1;
		size_t k = 1;

		long double r_temp = 0.0;
		long double phi_temp = 0.0;
		long double B_temp = 0.0;


		//	const std::size_t SIZE = n;
		//const int MAX_SIZE = 255;
		const std::size_t MAX_SIZE = 511;

		//	size_t n = 0;

		size_t summ = 0;

		//char **str = new char*[SIZE];
		//Будем читать информацию пока не дойдем до конца файла

		/*


		while (!feof(F)) {
		//str[n] = new char[MAX_SIZE];
		fgetc(F);
		n = n + 1;
		cout << n << endl;
		}

		*/

		//цикл для чтения значений из файла; выполнение цикла прервется,
		//когда достигнем конца файла, в этом случае F.eof() вернет истину.
		while (!feof(F)) {
			//while(	fscanf_s(F, "%Lf", &mass[i]) != EOF)

			SleepEx(1, true); // пауза для того, чтобы успеть прочитать информацию
							   //чтение очередного значения из потока F в переменную mass
			cout << " .";

			if ((i % 30) == 0) { //-V112
				cout << endl;
			}




			//чтение очередного значения из потока F в переменную temp
			fscanf_s(F, "%Lf %Lf %Lf", &r_temp, &phi_temp, &B_temp, (unsigned int)MAX_SIZE + 1); /* чтение из файла */
			Vector_r_magnetic_field_table.push_back(r_temp);
			Vector_phi_magnetic_field_table.push_back(phi_temp);
			Vector_B_magnetic_field_table.push_back(B_temp);
			//fscanf_s(F, "%Lf", &mass[i]); /* чтение из файла */

			//cout << r_temp << " " << phi_temp << " " << B_temp << endl;

			if (i > 1) {


				if (fabs(Vector_r_magnetic_field_table[i - 2] - 0.0) > epsilon && fabs(Vector_r_magnetic_field_table[i - 1] - 0.0) <= epsilon) {


					Vector_index_r_magnetic_field_table.push_back(m - 1);

					cout << m - 1 << endl;
					summ = summ + m - 1;
					m = 1;
				}

				if (fabs(Vector_phi_magnetic_field_table[i - 2] - Vector_phi_magnetic_field_table[i - 1]) > epsilon) {

					k = k + 1;


				}

			}
			i = i + 1;

			m = m + 1;


			//	cout << i << endl;
		}

		index_phi_magnetic_field_table = k;

		Vector_index_r_magnetic_field_table.push_back(i - 1 - summ);
		cout << Vector_index_r_magnetic_field_table[Vector_index_r_magnetic_field_table.size() - 1] << endl;
		cout << Vector_index_r_magnetic_field_table.size() << endl;

		//	cout << endl;
		//	cout << k << endl;

			//	for (i = 0; i < n; i++) {
			//	delete[] str[i];
			//	}

			//	delete[] str;

			//	str = nullptr;

		setlocale(LC_ALL, "rus"); // корректное отображение Кириллицы

		cout << endl;
		cout << endl;
		cout << "Чтение данных магнитного поля завершено." << endl;

	}


	//закрытие потока

	fclose(F);

	size_t vector_size = Vector_r_magnetic_field_table.size();

	//long double h_r = fabs(Vector_r_magnetic_field_table[vector_size - 1] - Vector_r_magnetic_field_table[0]) / vector_size;

	long double delta_B_temp = 0.0;

	size_t index_temp = 0;

	for (size_t ii = 0; ii < Vector_index_r_magnetic_field_table.size(); ii = ii + 1) {

		for (size_t i = index_temp; i < index_temp + Vector_index_r_magnetic_field_table[ii]; i = i + 1) {

			if (i == (index_temp + Vector_index_r_magnetic_field_table[ii] - 1)) {


				Vector_delta_B_magnetic_field_table.push_back(delta_B_temp);

				break;
			}

			if (Vector_r_magnetic_field_table[i] <= r_max_mag_table && Vector_r_magnetic_field_table[i + 1] > r_max_mag_table) {


				//		delta_B_temp = (Vector_B_magnetic_field_table[i + 0] - Vector_B_magnetic_field_table[i-1]) / (Vector_r_magnetic_field_table[i + 0] - Vector_r_magnetic_field_table[i-1]);

				Vector_delta_B_magnetic_field_table.push_back(delta_B_temp);

				continue;

			}

			//	cout << index_temp << endl;
				//	delta_B_temp = (Vector_B_magnetic_field_table[i + 1] - Vector_B_magnetic_field_table[i]) / h_r;

			delta_B_temp = (Vector_B_magnetic_field_table[i + 1] - Vector_B_magnetic_field_table[i]) / (Vector_r_magnetic_field_table[i + 1] - Vector_r_magnetic_field_table[i]);

			Vector_delta_B_magnetic_field_table.push_back(delta_B_temp);


		}

		index_temp = index_temp + Vector_index_r_magnetic_field_table[ii] + 0;

	}



	long double r_mag_max = 0.0;
	long double B_mag_max = 0.0;
	long double phi_mag_max = 0.0;



	for (size_t i = 0; i < vector_size; i = i + 1) {

		if (Vector_r_magnetic_field_table[i] >= r_min_mag_table && Vector_r_magnetic_field_table[i] <= r_max_mag_table) {

			if (Vector_r_magnetic_field_table[i] > r_mag_max) {
				r_mag_max = Vector_r_magnetic_field_table[i];
			}

			if (Vector_B_magnetic_field_table[i] > B_mag_max) {
				B_mag_max = Vector_B_magnetic_field_table[i];
			}

			if (Vector_phi_magnetic_field_table[i] > phi_mag_max) {
				phi_mag_max = Vector_phi_magnetic_field_table[i];
			}
		}
	}

	m_mag = (int)(2.0*M_PI / phi_mag_max) / 2.0;

	//Vector_delta_B_magnetic_field_table[vector_size - 1] = Vector_delta_B_magnetic_field_table[vector_size - 2]				  ;
}

long double search_B_magnetic_field_table(const vector<long double> &Vector_r_magnetic_field_table, const vector<long double> &Vector_phi_magnetic_field_table, const vector<long double> &Vector_B_magnetic_field_table, long double r, long double phi, vector <size_t> &Vector_index_r_magnetic_field_table, size_t &index_phi_magnetic_field_table) {

	size_t vector_size = Vector_r_magnetic_field_table.size();

	size_t vector_size_phi = Vector_index_r_magnetic_field_table.size();

	//cout <<"vector_size_phi" <<vector_size_phi << endl;

	long double temp_B = 0.0;

	//cout << r << endl;

	//	cout << vector_size << endl;


	long double h_phi = fabs(Vector_phi_magnetic_field_table[vector_size - 1] - Vector_r_magnetic_field_table[0]) / (vector_size_phi - 1);

	//cout << "h_phi" << h_phi << endl;
	//cout << h_r << endl;



	//phi = fabs(phi);

	if (phi < 0) {
		cout << "!" << endl;
	}

	//	cout << (phi / M_PI)*180.0 << endl;

	phi = phi - Vector_phi_magnetic_field_table[vector_size - 1] * (int)(phi / Vector_phi_magnetic_field_table[vector_size - 1]);

	size_t index_phi = (size_t)(phi / h_phi);
	size_t vector_size_r = Vector_index_r_magnetic_field_table[index_phi];

	//cout << "index_phi" << index_phi+1 << endl;
	//cout << "vector_size_r" << vector_size_r << endl;

	size_t index_r_left = 0;
	size_t index_r_right = 0;

	for (size_t i = 0; i < index_phi; i = i + 1) {

		if (index_phi == 0) {
			continue;
		}
		index_r_left = index_r_left + Vector_index_r_magnetic_field_table[i];
	}
	index_r_right = index_r_left + vector_size_r - 1;

	long double h_r = fabs(Vector_r_magnetic_field_table[index_r_right - 1] - Vector_r_magnetic_field_table[index_r_left]) / vector_size_r;

	size_t index_r = (size_t)(r / h_r) + index_r_left;
	//cout << index << endl;

	//cout << "index_r_left" << index_r_left+1 << endl;
	//cout << "index_r_right" << index_r_right+1 << endl;
//	cout << "index_r" << index_r+1 << endl;
	//cout << index_r << endl;

	//cout << index_r + vector_size_r - 0 + 1 << endl;

	if (index_phi == 0) {


		if (index_r == index_r_left) {

			temp_B = Vector_B_magnetic_field_table[index_r] + pow(pow((Vector_B_magnetic_field_table[index_r + 1] - Vector_B_magnetic_field_table[index_r]) / (Vector_r_magnetic_field_table[index_r + 1] - Vector_r_magnetic_field_table[index_r])*(r - Vector_r_magnetic_field_table[index_r]), 2.0) + pow((Vector_B_magnetic_field_table[index_r + vector_size_r - 0] - Vector_B_magnetic_field_table[index_r]) / (Vector_phi_magnetic_field_table[index_r + vector_size_r - 0] - Vector_phi_magnetic_field_table[index_r])*(phi - Vector_phi_magnetic_field_table[index_r]), 2.0), 1.0 / 2.0);
		}
		else

			if (index_r - 2 == index_r_right) {


				temp_B = Vector_B_magnetic_field_table[index_r - 2] + (Vector_B_magnetic_field_table[index_r - 2 + vector_size_r - 0] - Vector_B_magnetic_field_table[index_r - 2]) / (Vector_phi_magnetic_field_table[index_r - 2 + vector_size_r - 0] - Vector_phi_magnetic_field_table[index_r - 2])*(phi - Vector_phi_magnetic_field_table[index_r - 2]);

			}
			else {

				index_r = index_r - 1;

				temp_B = Vector_B_magnetic_field_table[index_r] + pow(pow((Vector_B_magnetic_field_table[index_r + 1] - Vector_B_magnetic_field_table[index_r]) / (Vector_r_magnetic_field_table[index_r + 1] - Vector_r_magnetic_field_table[index_r])*(r - Vector_r_magnetic_field_table[index_r]), 2.0) + pow((Vector_B_magnetic_field_table[index_r + vector_size_r - 0] - Vector_B_magnetic_field_table[index_r]) / (Vector_phi_magnetic_field_table[index_r + vector_size_r - 0] - Vector_phi_magnetic_field_table[index_r])*(phi - Vector_phi_magnetic_field_table[index_r]), 2.0), 1.0 / 2.0);

			}
			//cout << temp_B << endl;

	}

	if (index_phi == vector_size_phi - 1) {


		if (index_r == index_r_left) {

			temp_B = Vector_B_magnetic_field_table[index_r] + (Vector_B_magnetic_field_table[index_r + 1] - Vector_B_magnetic_field_table[index_r]) / (Vector_r_magnetic_field_table[index_r + 1] - Vector_r_magnetic_field_table[index_r])*(r - Vector_r_magnetic_field_table[index_r]);
		}
		else

			if (index_r - 2 == index_r_right) {


				temp_B = Vector_B_magnetic_field_table[index_r - 2];

			}
			else {

				index_r = index_r - 1;

				temp_B = Vector_B_magnetic_field_table[index_r] + (Vector_B_magnetic_field_table[index_r + 1] - Vector_B_magnetic_field_table[index_r]) / (Vector_r_magnetic_field_table[index_r + 1] - Vector_r_magnetic_field_table[index_r])*(r - Vector_r_magnetic_field_table[index_r]);

			}
			//cout << temp_B << endl;

	}


	else {


		if (index_r == index_r_left) {

			temp_B = Vector_B_magnetic_field_table[index_r] + pow(pow((Vector_B_magnetic_field_table[index_r + 1] - Vector_B_magnetic_field_table[index_r]) / (Vector_r_magnetic_field_table[index_r + 1] - Vector_r_magnetic_field_table[index_r])*(r - Vector_r_magnetic_field_table[index_r]), 2.0) + pow((Vector_B_magnetic_field_table[index_r + vector_size_r - 0] - Vector_B_magnetic_field_table[index_r]) / (Vector_phi_magnetic_field_table[index_r + vector_size_r - 0] - Vector_phi_magnetic_field_table[index_r])*(phi - Vector_phi_magnetic_field_table[index_r]), 2.0), 1.0 / 2.0);
		}
		else

			if (index_r - 2 == index_r_right) {


				temp_B = Vector_B_magnetic_field_table[index_r - 2] + (Vector_B_magnetic_field_table[index_r - 2 + vector_size_r - 0] - Vector_B_magnetic_field_table[index_r - 2]) / (Vector_phi_magnetic_field_table[index_r - 2 + vector_size_r - 0] - Vector_phi_magnetic_field_table[index_r - 2])*(phi - Vector_phi_magnetic_field_table[index_r - 2]);

			}
			else {

				index_r = index_r - 1;

				temp_B = Vector_B_magnetic_field_table[index_r] + pow(pow((Vector_B_magnetic_field_table[index_r + 1] - Vector_B_magnetic_field_table[index_r]) / (Vector_r_magnetic_field_table[index_r + 1] - Vector_r_magnetic_field_table[index_r])*(r - Vector_r_magnetic_field_table[index_r]), 2.0) + pow((Vector_B_magnetic_field_table[index_r + vector_size_r - 0] - Vector_B_magnetic_field_table[index_r]) / (Vector_phi_magnetic_field_table[index_r + vector_size_r - 0] - Vector_phi_magnetic_field_table[index_r])*(phi - Vector_phi_magnetic_field_table[index_r]), 2.0), 1.0 / 2.0);

				//cout << Vector_B_magnetic_field_table[index_r] << endl;
				//cout << Vector_B_magnetic_field_table[index_r + vector_size_r - 0] << endl;
			}
			//cout << temp_B << endl;

	}

	return temp_B;
}


long double search_delta_B_magnetic_field_table(const vector<long double> &Vector_r_magnetic_field_table, const vector<long double> &Vector_phi_magnetic_field_table, const vector<long double> &Vector_delta_B_magnetic_field_table, long double r, long double phi, vector <size_t> &Vector_index_r_magnetic_field_table, size_t &index_phi_magnetic_field_table) {

	size_t vector_size = Vector_r_magnetic_field_table.size();

	size_t vector_size_phi = Vector_index_r_magnetic_field_table.size();

	//cout <<"vector_size_phi" <<vector_size_phi << endl;

	long double temp_delta_B = 0.0;

	//cout << r << endl;

	//	cout << vector_size << endl;


	long double h_phi = fabs(Vector_phi_magnetic_field_table[vector_size - 1] - Vector_r_magnetic_field_table[0]) / (vector_size_phi - 1);

	//cout << "h_phi" << h_phi << endl;
	//cout << h_r << endl;

//	phi = fabs(phi);

	if (phi < 0) {
		cout << "!" << endl;
	}

	phi = phi - Vector_phi_magnetic_field_table[vector_size - 1] * ((int)(phi / Vector_phi_magnetic_field_table[vector_size - 1]));

	size_t index_phi = (size_t)(phi / h_phi);
	size_t vector_size_r = Vector_index_r_magnetic_field_table[index_phi];

	//cout << "index_phi" << index_phi + 1 << endl;
	//cout << "vector_size_r" << vector_size_r << endl;

	size_t index_r_left = 0;
	size_t index_r_right = 0;

	for (size_t i = 0; i < index_phi; i = i + 1) {

		if (index_phi == 0) {
			continue;
		}
		index_r_left = index_r_left + Vector_index_r_magnetic_field_table[i];
	}
	index_r_right = index_r_left + vector_size_r - 1;

	long double h_r = fabs(Vector_r_magnetic_field_table[index_r_right - 1] - Vector_r_magnetic_field_table[index_r_left]) / vector_size_r;

	size_t index_r = (size_t)(r / h_r) + index_r_left;
	//cout << index << endl;

	//cout << "index_r_left" << index_r_left+1 << endl;
	//cout << "index_r_right" << index_r_right+1 << endl;
	//	cout << "index_r" << index_r+1 << endl;
	//cout << index_r << endl;

	//cout << index_r + vector_size_r - 0 + 1 << endl;

	if (index_phi == 0) {


		if (index_r == index_r_left) {

			temp_delta_B = Vector_delta_B_magnetic_field_table[index_r] + pow(pow((Vector_delta_B_magnetic_field_table[index_r + 1] - Vector_delta_B_magnetic_field_table[index_r]) / (Vector_r_magnetic_field_table[index_r + 1] - Vector_r_magnetic_field_table[index_r])*(r - Vector_r_magnetic_field_table[index_r]), 2.0) + pow((Vector_delta_B_magnetic_field_table[index_r + vector_size_r - 0] - Vector_delta_B_magnetic_field_table[index_r]) / (Vector_phi_magnetic_field_table[index_r + vector_size_r - 0] - Vector_phi_magnetic_field_table[index_r])*(phi - Vector_phi_magnetic_field_table[index_r]), 2.0), 1.0 / 2.0);
		}
		else

			if (index_r - 2 == index_r_right) {


				temp_delta_B = Vector_delta_B_magnetic_field_table[index_r - 2] + (Vector_delta_B_magnetic_field_table[index_r - 2 + vector_size_r - 0] - Vector_delta_B_magnetic_field_table[index_r - 2]) / (Vector_phi_magnetic_field_table[index_r - 2 + vector_size_r - 0] - Vector_phi_magnetic_field_table[index_r - 2])*(phi - Vector_phi_magnetic_field_table[index_r - 2]);

			}
			else {

				index_r = index_r - 1;

				temp_delta_B = Vector_delta_B_magnetic_field_table[index_r] + pow(pow((Vector_delta_B_magnetic_field_table[index_r + 1] - Vector_delta_B_magnetic_field_table[index_r]) / (Vector_r_magnetic_field_table[index_r + 1] - Vector_r_magnetic_field_table[index_r])*(r - Vector_r_magnetic_field_table[index_r]), 2.0) + pow((Vector_delta_B_magnetic_field_table[index_r + vector_size_r - 0] - Vector_delta_B_magnetic_field_table[index_r]) / (Vector_phi_magnetic_field_table[index_r + vector_size_r - 0] - Vector_phi_magnetic_field_table[index_r])*(phi - Vector_phi_magnetic_field_table[index_r]), 2.0), 1.0 / 2.0);

			}
			//cout << temp_B << endl;

	}

	if (index_phi == vector_size_phi - 1) {


		if (index_r == index_r_left) {

			temp_delta_B = Vector_delta_B_magnetic_field_table[index_r] + (Vector_delta_B_magnetic_field_table[index_r + 1] - Vector_delta_B_magnetic_field_table[index_r]) / (Vector_r_magnetic_field_table[index_r + 1] - Vector_r_magnetic_field_table[index_r])*(r - Vector_r_magnetic_field_table[index_r]);
		}
		else

			if (index_r - 2 == index_r_right) {


				temp_delta_B = Vector_delta_B_magnetic_field_table[index_r - 2];

			}
			else {

				index_r = index_r - 1;

				temp_delta_B = Vector_delta_B_magnetic_field_table[index_r] + (Vector_delta_B_magnetic_field_table[index_r + 1] - Vector_delta_B_magnetic_field_table[index_r]) / (Vector_r_magnetic_field_table[index_r + 1] - Vector_r_magnetic_field_table[index_r])*(r - Vector_r_magnetic_field_table[index_r]);

			}
			//cout << temp_B << endl;

	}


	else {


		if (index_r == index_r_left) {

			temp_delta_B = Vector_delta_B_magnetic_field_table[index_r] + pow(pow((Vector_delta_B_magnetic_field_table[index_r + 1] - Vector_delta_B_magnetic_field_table[index_r]) / (Vector_r_magnetic_field_table[index_r + 1] - Vector_r_magnetic_field_table[index_r])*(r - Vector_r_magnetic_field_table[index_r]), 2.0) + pow((Vector_delta_B_magnetic_field_table[index_r + vector_size_r - 0] - Vector_delta_B_magnetic_field_table[index_r]) / (Vector_phi_magnetic_field_table[index_r + vector_size_r - 0] - Vector_phi_magnetic_field_table[index_r])*(phi - Vector_phi_magnetic_field_table[index_r]), 2.0), 1.0 / 2.0);
		}
		else

			if (index_r - 2 == index_r_right) {


				temp_delta_B = Vector_delta_B_magnetic_field_table[index_r - 2] + (Vector_delta_B_magnetic_field_table[index_r - 2 + vector_size_r - 0] - Vector_delta_B_magnetic_field_table[index_r - 2]) / (Vector_phi_magnetic_field_table[index_r - 2 + vector_size_r - 0] - Vector_phi_magnetic_field_table[index_r - 2])*(phi - Vector_phi_magnetic_field_table[index_r - 2]);

			}
			else {

				index_r = index_r - 1;

				temp_delta_B = Vector_delta_B_magnetic_field_table[index_r] + pow(pow((Vector_delta_B_magnetic_field_table[index_r + 1] - Vector_delta_B_magnetic_field_table[index_r]) / (Vector_r_magnetic_field_table[index_r + 1] - Vector_r_magnetic_field_table[index_r])*(r - Vector_r_magnetic_field_table[index_r]), 2.0) + pow((Vector_delta_B_magnetic_field_table[index_r + vector_size_r - 0] - Vector_delta_B_magnetic_field_table[index_r]) / (Vector_phi_magnetic_field_table[index_r + vector_size_r - 0] - Vector_phi_magnetic_field_table[index_r])*(phi - Vector_phi_magnetic_field_table[index_r]), 2.0), 1.0 / 2.0);

				//cout << Vector_B_magnetic_field_table[index_r] << endl;
				//cout << Vector_B_magnetic_field_table[index_r + vector_size_r - 0] << endl;
			}
			//cout << temp_B << endl;

	}

	return temp_delta_B;
}





// вычисление координат после вылета из торца цилиндра
inline void func1(const char *s, long double x_in, long double y_in, long double z_in, long double r_in, long double theta_in, long double phi_in, long double psi_in, long double &x_out, long double &y_out, long double &z_out, long double &r_out, long double &theta_out, long double &phi_out, long double &psi_out, long double t, long double V_0, long double v_phi_in, long double &v_phi_out, size_t N_CYL_partitions, vector<long double> &trajectory_cyl_x,
	vector<long double> &trajectory_cyl_y, vector<long double> &trajectory_cyl_z, vector<long double> &trajectory_cyl_r, vector<long double>&Vector_color_trajectory_cyl, vector<long double> &trajectory_cyl_rr, vector<long double> &out_trajectory_cyl, vector<long double> &trajectory_cyl_phi, vector<long double> &trajectory_cyl_psi, vector<long double> &trajectory_cyl_theta, vector<long double> &trajectory_cyl_v_x, vector<long double> &trajectory_cyl_v_y,
	vector<long double> &trajectory_cyl_v_z, vector<long double> &trajectory_cyl_v_r, vector<long double> &trajectory_cyl_v_phi, vector<long double> &trajectory_cyl_v_perp, vector<long double> &trajectory_cyl_v_0, vector<long double> &trajectory_cyl_force, vector<long double> &trajectory_cyl_condition_color,
	long double mu_particle, long double mu_particle_force, bool flaq_on_off_mu_B, size_t index_condition, size_t particle_mode, vector<long double> &trajectory_cyl_mu, vector<long double> &trajectory_cyl_B) { // передача аргументов по ссылке


	long double phi = phi_in;
	long double psi = psi_in;
	long double theta = theta_in;

	//	cout << theta << endl;

	//cout << x_in << " " << y_in << " " << z_in << " " << r_in << " " << endl;

	//	trajectory_cyl_x.push_back(x_in);
	//	trajectory_cyl_y.push_back(y_in);
	//	trajectory_cyl_z.push_back(z_in);
	//	trajectory_cyl_r.push_back(r_in);

	//	if (y_in < 0) {
	//		trajectory_cyl_rr.push_back(-r_in);
	//	}
	//	else if (y_in >= 0) {
	//		trajectory_cyl_rr.push_back(r_in);
	//	}

	//	Vector_color_trajectory_cyl.push_back(0.0);

	//	out_trajectory_cyl.push_back(0.0);

	//if (strcmp(s, "left") == 0) {

	//}

	//if (strcmp(s, "right") == 0) {

	//}


	//x_out = r_in*cos(phi_in) + t*sin(theta_in)*cos(psi_in);
	//y_out = r_in*sin(phi_in) + t*sin(theta_in)*sin(psi_in);

	long double x = x_in;
	long double y = y_in;
	long double z = z_in;
	long double r = r_in;

	/*

	if (strcmp(s, "left") == 0) {
	z_out = z_in + t*cos(theta_in);

	}

	if (strcmp(s, "right") == 0) {
	z_out = z_in - t*cos(theta_in);
	//cout << "yes" << endl;

	}

	*/



	if (strcmp(s, "left") == 0) {

		x_out = r_in * cos(phi_in) + t * sin(theta_in)*cos(psi_in);
		y_out = r_in * sin(phi_in) + t * sin(theta_in)*sin(psi_in);
		z_out = z_in + t * cos(theta_in);

	}



	if (strcmp(s, "left_right") == 0) {

		x_out = r_in * cos(phi_in) + t * sin(theta_in)*cos(psi_in);
		y_out = r_in * sin(phi_in) + t * sin(theta_in)*sin(psi_in);
		z_out = z_in - t * cos(theta_in);

	}

	if (strcmp(s, "right") == 0) {

		x_out = r_in * cos(phi_in) - t * sin(theta_in)*cos(psi_in);
		y_out = r_in * sin(phi_in) - t * sin(theta_in)*sin(psi_in);
		z_out = z_in - t * cos(theta_in);
		//cout << "yes" << endl;

	}

	if (fabs(x_out - 0.0) <= epsilon && y_out > 0) {

		phi_out = M_PI_2;
	}


	if (fabs(x_out - 0.0) <= epsilon && y_out < 0) {

		phi_out = 3.0*M_PI_2;
	}


	if (fabs(y_out - 0.0) <= epsilon && x_out > 0) {

		phi_out = 0.0;
	}

	if (fabs(y_out - 0.0) <= epsilon && x_out < 0) {

		phi_out = M_PI;
	}

	if (fabs(y_out - 0.0) <= epsilon && fabs(x_out - 0.0) <= epsilon) {

		phi_out = 0.0;
	}

	if (x_out > 0 && y_out > 0) {

		phi_out = atan(fabs(y_out / x_out));
	}



	if (x_out < 0 && y_out < 0) {

		phi_out = M_PI + atan(fabs(y_out / x_out));
	}

	if (x_out > 0 && y_out < 0) {

		phi_out = 2.0*M_PI - atan(fabs(y_out / x_out));
	}


	if (x_out < 0 && y_out > 0) {

		phi_out = M_PI - atan(fabs(y_out / x_out));
	}


	r_out = pow(pow(x_out, 2.0) + pow(y_out, 2.0), 1.0 / 2.0);

	theta_out = theta_in;

	psi_out = psi_in;

	v_phi_out = v_phi_in * r_in / r_out;


	long double h_z = fabs(z_out - z_in) / (N_CYL_partitions + 1);

	long double delta_t = h_z / fabs(cos(theta_in));

	const long double mu_bor = 5.788381806638*pow(10.0, 13.0)*pow(2.99792458, 2.0); // магнетон Бора электронный в единицах эВ/Гс*(скорость света [мм/c])^2

																					//	const long double mu_bor = 3.152451260522*pow(10.0, 10.0)*pow(2.99792458, 2.0); // магнетон Бора ядерный в единицах эВ/Гс*(скорость света [мм/c])^2


	const long double mu_bor_force = 9.2740096820*pow(10.0, 0.0);

	//cout << "N_cyl_part " << N_CYL_partitions << endl;

	/*



	long double mu_particle = 0.0;
	long double mu_particle_force = 0.0;

	long double B_temp = 0.001;
	long double mu_temp_temp = 0.0;
	long double E_temp_temp = 0.0;


	if (flaq_on_off_mu_B == false) {
		mu_particle = mu_temp;
		mu_particle_force = mu_force_temp;
	}
	if (flaq_on_off_mu_B == true) {


		//	cout << index_condition << endl;

		if (particle_mode == 1) {
			mu_particle = mu_H(index_condition, B_temp, mu_temp_temp, E_temp_temp)*mu_bor;
			mu_particle_force = mu_H(index_condition, B_temp, mu_temp_temp, E_temp_temp)*mu_bor_force;
		}

		if (particle_mode == 2) {

			mu_particle = mu_D(index_condition, B_temp, mu_temp_temp, E_temp_temp)*mu_bor;
			mu_particle_force = mu_D(index_condition, B_temp, mu_temp_temp, E_temp_temp)*mu_bor_force;
		}

		if (particle_mode == 3) {
			mu_particle = mu_H_2(index_condition, B_temp, mu_temp_temp, E_temp_temp)*mu_bor;
			mu_particle_force = mu_H_2(index_condition, B_temp, mu_temp_temp, E_temp_temp)*mu_bor_force;

		}

		if (particle_mode == 4) { //-V112

			mu_particle = mu_D_2(index_condition, B_temp, mu_temp_temp, E_temp_temp)*mu_bor;
			mu_particle_force = mu_D_2(index_condition, B_temp, mu_temp_temp, E_temp_temp)*mu_bor_force;

		}

	}

	*/

	for (size_t i = 0; i <= N_CYL_partitions - 1; i = i + 1) {








		if (N_CYL_partitions == 0) {
			i = 1;
			break;
		}

		if (strcmp(s, "left") == 0) {
			//	x = x + tan(theta_in)*cos(psi_in)*h_z;
			//	y = y + tan(theta_in)*sin(psi_in)*h_z;

			x = x + sin(theta_in)*cos(psi_in)*delta_t;
			y = y + sin(theta_in)*sin(psi_in)*delta_t;

			z = z + h_z;
			r = pow(pow(x, 2.0) + pow(y, 2.0), 1.0 / 2.0);

			trajectory_cyl_v_x.push_back(V_0*sin(theta_in)*cos(psi_in));
			trajectory_cyl_v_y.push_back(V_0*sin(theta_in)*sin(psi_in));
			trajectory_cyl_v_z.push_back(V_0*cos(theta_in));
			trajectory_cyl_v_r.push_back(V_0*sin(theta_in)*cos(phi - psi_in));
			trajectory_cyl_v_phi.push_back(V_0*sin(theta_in)*sin(phi - psi_in));
			trajectory_cyl_v_perp.push_back(V_0*sin(theta_in));
			trajectory_cyl_v_0.push_back(V_0);
			trajectory_cyl_force.push_back(0.0);




		}



		if (strcmp(s, "left_right") == 0) {
			//	x = x + tan(theta_in)*cos(psi_in)*h_z;
			//	y = y + tan(theta_in)*sin(psi_in)*h_z;

			x = x + sin(theta_in)*cos(psi_in)*delta_t;
			y = y + sin(theta_in)*sin(psi_in)*delta_t;

			z = z - h_z;
			r = pow(pow(x, 2.0) + pow(y, 2.0), 1.0 / 2.0);

			trajectory_cyl_v_x.push_back(V_0*sin(theta_in)*cos(psi_in));
			trajectory_cyl_v_y.push_back(V_0*sin(theta_in)*sin(psi_in));
			trajectory_cyl_v_z.push_back(-V_0 * cos(theta_in));
			trajectory_cyl_v_r.push_back(V_0*sin(theta_in)*cos(phi - psi_in));
			trajectory_cyl_v_phi.push_back(V_0*sin(theta_in)*sin(phi - psi_in));
			trajectory_cyl_v_perp.push_back(V_0*sin(theta_in));
			trajectory_cyl_v_0.push_back(V_0);
			trajectory_cyl_force.push_back(0.0);


		}


		if (strcmp(s, "right") == 0) {
			//	x = x - tan(theta_in)*cos(psi_in)*h_z;
			//	y = y - tan(theta_in)*sin(psi_in)*h_z;

			x = x - sin(theta_in)*cos(psi_in)*delta_t;
			y = y - sin(theta_in)*sin(psi_in)*delta_t;

			z = z - h_z;
			r = pow(pow(x, 2.0) + pow(y, 2.0), 1.0 / 2.0);

			trajectory_cyl_v_x.push_back(-V_0 * sin(theta_in)*cos(psi_in));
			trajectory_cyl_v_y.push_back(-V_0 * sin(theta_in)*sin(psi_in));
			trajectory_cyl_v_z.push_back(-V_0 * cos(theta_in));
			trajectory_cyl_v_r.push_back(-V_0 * sin(theta_in)*cos(phi - psi_in));
			trajectory_cyl_v_phi.push_back(V_0*sin(theta_in)*sin(phi - psi_in));
			trajectory_cyl_v_perp.push_back(V_0*sin(theta_in));
			trajectory_cyl_v_0.push_back(V_0);
			trajectory_cyl_force.push_back(0.0);
		}

		trajectory_cyl_x.push_back(x);
		trajectory_cyl_y.push_back(y);
		trajectory_cyl_z.push_back(z);
		trajectory_cyl_r.push_back(r);

		trajectory_cyl_mu.push_back(mu_particle / mu_bor);
		trajectory_cyl_B.push_back(0.0);

		if (mu_particle > 0.0) {
			trajectory_cyl_condition_color.push_back(11.0);
		}
		if (fabs(mu_particle - 0.0) <= epsilon) {
			trajectory_cyl_condition_color.push_back(10.0);
		}
		if (mu_particle < 0.0) {
			trajectory_cyl_condition_color.push_back(-11.0);
		}









		if (fabs(x - 0.0) <= epsilon && y > 0) {

			phi = M_PI_2;
		}


		if (fabs(x - 0.0) <= epsilon && y < 0) {

			phi = 3.0*M_PI_2;
		}


		if (fabs(y - 0.0) <= epsilon && x > 0) {

			phi = 0.0;
		}

		if (fabs(y - 0.0) <= epsilon && x < 0) {

			phi = M_PI;
		}

		if (fabs(y - 0.0) <= epsilon && fabs(x - 0.0) <= epsilon) {

			phi = 0.0;
		}

		if (x > 0 && y > 0) {

			phi = atan(fabs(y / x));
		}



		if (x < 0 && y < 0) {

			phi = M_PI + atan(fabs(y / x));
		}

		if (x > 0 && y < 0) {

			phi = 2.0*M_PI - atan(fabs(y / x));
		}


		if (x < 0 && y > 0) {

			phi = M_PI - atan(fabs(y / x));
		}






		trajectory_cyl_phi.push_back(phi);
		trajectory_cyl_psi.push_back(psi);
		trajectory_cyl_theta.push_back(theta_in);

		//	cout << theta << endl;

		if (y < 0) {
			trajectory_cyl_rr.push_back(-r);
		}
		else if (y >= 0) {
			trajectory_cyl_rr.push_back(r);
		}

		Vector_color_trajectory_cyl.push_back(0.0);

		out_trajectory_cyl.push_back(0.0);

	}




	trajectory_cyl_x.push_back(x_out);
	trajectory_cyl_y.push_back(y_out);
	trajectory_cyl_z.push_back(z_out);
	trajectory_cyl_r.push_back(r_out);

	trajectory_cyl_mu.push_back(mu_particle / mu_bor);
	trajectory_cyl_B.push_back(0.0);

	if (mu_particle > 0.0) {
		trajectory_cyl_condition_color.push_back(11.0);
	}
	if (fabs(mu_particle - 0.0) <= epsilon) {
		trajectory_cyl_condition_color.push_back(10.0);
	}
	if (mu_particle < 0.0) {
		trajectory_cyl_condition_color.push_back(-11.0);
	}


	trajectory_cyl_phi.push_back(phi_out);
	trajectory_cyl_psi.push_back(psi_out);
	trajectory_cyl_theta.push_back(theta_out);


	if (strcmp(s, "left") == 0) {


		trajectory_cyl_v_x.push_back(V_0*sin(theta_out)*cos(psi_out));
		trajectory_cyl_v_y.push_back(V_0*sin(theta_out)*sin(psi_out));
		trajectory_cyl_v_z.push_back(V_0*cos(theta_out));
		trajectory_cyl_v_r.push_back(V_0*sin(theta_out)*cos(phi_out - psi_out));
		trajectory_cyl_v_phi.push_back(V_0*sin(theta_out)*sin(phi_out - psi_out));
		trajectory_cyl_v_perp.push_back(V_0*sin(theta_out));
		trajectory_cyl_v_0.push_back(V_0);
		trajectory_cyl_force.push_back(0.0);


	}



	if (strcmp(s, "left_right") == 0) {

		trajectory_cyl_v_x.push_back(V_0*sin(theta_out)*cos(psi_out));
		trajectory_cyl_v_y.push_back(V_0*sin(theta_out)*sin(psi_out));
		trajectory_cyl_v_z.push_back(-V_0 * cos(theta_out));
		trajectory_cyl_v_r.push_back(V_0*sin(theta_out)*cos(phi_out - psi_out));
		trajectory_cyl_v_phi.push_back(V_0*sin(theta_out)*sin(phi_out - psi_out));
		trajectory_cyl_v_perp.push_back(V_0*sin(theta_out));
		trajectory_cyl_v_0.push_back(V_0);
		trajectory_cyl_force.push_back(0.0);


	}


	if (strcmp(s, "right") == 0) {


		trajectory_cyl_v_x.push_back(-V_0 * sin(theta_out)*cos(psi_out));
		trajectory_cyl_v_y.push_back(-V_0 * sin(theta_out)*sin(psi_out));
		trajectory_cyl_v_z.push_back(-V_0 * cos(theta_out));
		trajectory_cyl_v_r.push_back(-V_0 * sin(theta_out)*cos(phi_out - psi_out));
		trajectory_cyl_v_phi.push_back(V_0*sin(theta_out)*sin(phi_out - psi_out));
		trajectory_cyl_v_perp.push_back(V_0*sin(theta_out));
		trajectory_cyl_v_0.push_back(V_0);
		trajectory_cyl_force.push_back(0.0);
	}




	//	cout << theta_out << endl;

	//	cout << endl;
	if (y_out < 0) {
		trajectory_cyl_rr.push_back(-r_out);
	}
	else if (y_out >= 0) {
		trajectory_cyl_rr.push_back(r_out);
	}

	Vector_color_trajectory_cyl.push_back(0.0);

	out_trajectory_cyl.push_back(0.0);

	//cout << v_phi_out << endl;


	//cout << x_out << " " << y_out << " " << z_out << " " << r_out << " " << endl;

	//cout << endl;

	//	cout << theta_in << " " << theta_out << endl;

}





// вычисление координат после вылета с поверхности цилиндра с учетом того, что частица снова окажется на цилиндре
inline void func2(const char *s, long double x_in, long double y_in, long double z_in, long double r_in, long double theta_in, long double phi_in, long double psi_in, long double &x_out, long double &y_out, long double &z_out, long double &r_out, long double &theta_out, long double &phi_out, long double &psi_out, long double t, long double V_0, long double v_phi_in, long double &v_phi_out, size_t N_CYL_partitions, vector<long double> &trajectory_cyl_x,
	vector<long double> &trajectory_cyl_y, vector<long double> &trajectory_cyl_z, vector<long double> &trajectory_cyl_r, vector<long double>&Vector_color_trajectory_cyl, vector<long double> &trajectory_cyl_rr, vector<long double> &out_trajectory_cyl, vector<long double> &trajectory_cyl_phi, vector<long double> &trajectory_cyl_psi, vector<long double> &trajectory_cyl_theta, vector<long double> &trajectory_cyl_v_x, vector<long double> &trajectory_cyl_v_y,
	vector<long double> &trajectory_cyl_v_z, vector<long double> &trajectory_cyl_v_r, vector<long double> &trajectory_cyl_v_phi, vector<long double> &trajectory_cyl_v_perp, vector<long double> &trajectory_cyl_v_0, vector<long double> &trajectory_cyl_force, vector<long double> &trajectory_cyl_condition_color,
	long double mu_particle, long double mu_particle_force, bool flaq_on_off_mu_B, size_t index_condition, size_t particle_mode, vector<long double> &trajectory_cyl_mu, vector<long double> &trajectory_cyl_B) { // передача аргументов по ссылке


	long double phi = phi_in;
	long double psi = psi_in;
	long double theta = theta_in;


	//cout << t << " " << fabs(time2(theta_in, psi_in, 1.0, V_0)) << endl;


	//t = fabs(time2(theta_in, psi_in, 1.0, V_0));

	//cout << x_in << " " << y_in << " " << z_in << " " << r_in << " " << endl;

	//trajectory_cyl_x.push_back(x_in);
	//trajectory_cyl_y.push_back(y_in);
	//trajectory_cyl_z.push_back(z_in);
	//trajectory_cyl_r.push_back(r_in);

	//if (y_in < 0) {
	//	trajectory_cyl_rr.push_back(-r_in);
	//}
	//else if (y_in >= 0) {
	//	trajectory_cyl_rr.push_back(r_in);
	//}

	//Vector_color_trajectory_cyl.push_back(0.0);


	//out_trajectory_cyl.push_back(0.0);



	long double temp_x = x_in;	   //	t = t*V_0;
	long double temp_y = y_in;
	long double temp_z = z_in;
	long double temp_r = r_in;


	long double x = r_in;
	long double y = 0.0;
	long double z = z_in;
	long double r = r_in;


	//	y_out = t*sin(theta_in)*sin(psi_in);
	//	x_out = r_in - t*cos(theta_in);

	//	rotate("matrix", x_in, y_in, z_in, temp_x, temp_y, temp_z);

	//	temp_r = pow(pow(temp_x, 2.0) + pow(temp_y, 2.0), 1.0 / 2.0);

	//	cout << temp_x << " " << temp_y << " " << temp_z << " " << temp_r<< " " << endl;


	temp_y = t * sin(theta_in)*sin(psi_in);
	temp_x = temp_r - t * cos(theta_in);

	temp_r = pow(pow(temp_x, 2.0) + pow(temp_y, 2.0), 1.0 / 2.0);




	//	temp_y = temp_y + t*sin(theta_in)*sin(psi_in);
	//	temp_x = temp_x - t*cos(theta_in);

	//	temp_r = pow(pow(temp_x, 2.0) + pow(temp_y, 2.0), 1.0 / 2.0);

	//	cout << temp_x << " " << temp_y << " " << temp_z << " " << temp_r << " " << endl;


	/*





	if (strcmp(s, "left") == 0) {
	z_out = z_in + fabs(t*sin(theta_in)*cos(psi_in));
	}

	if (strcmp(s, "right") == 0) {
	z_out = z_in - fabs(t*sin(theta_in)*cos(psi_in));
	}

	*/


	if (strcmp(s, "left") == 0) {
		temp_z = temp_z + fabs(t*sin(theta_in)*cos(psi_in));
	}

	if (strcmp(s, "right") == 0) {

		//cout << t*sin(theta_in)*cos(psi_in) << endl;

		temp_z = temp_z - fabs(t*sin(theta_in)*cos(psi_in));
	}



	//cout << temp_z << endl;

	rotate("inverse_matrix", x_in, y_in, z_in, temp_x, temp_y, temp_z);

	//rotate("matrix", x_in, y_in, z_in, x_out, y_out, z_out);


	//cout << temp_z << endl;

	temp_r = pow(pow(temp_x, 2.0) + pow(temp_y, 2.0), 1.0 / 2.0);


	x_out = temp_x;
	y_out = temp_y;
	z_out = temp_z;
	r_out = temp_r;


	//cout << temp_z <<" "<<z_out<< endl;

	if (fabs(x_out - 0.0) <= epsilon && y_out > 0) {

		phi_out = M_PI_2;
	}


	if (fabs(x_out - 0.0) <= epsilon && y_out < 0) {

		phi_out = 3.0*M_PI_2;
	}


	if (fabs(y_out - 0.0) <= epsilon && x_out > 0) {

		phi_out = 0.0;
	}

	if (fabs(y_out - 0.0) <= epsilon && x_out < 0) {

		phi_out = M_PI;
	}

	if (fabs(y_out - 0.0) <= epsilon && fabs(x_out - 0.0) <= epsilon) {

		phi_out = 0.0;
	}

	if (x_out > 0 && y_out > 0) {

		phi_out = atan(fabs(y_out / x_out));
	}



	if (x_out < 0 && y_out < 0) {

		phi_out = M_PI + atan(fabs(y_out / x_out));
	}

	if (x_out > 0 && y_out < 0) {

		phi_out = 2.0*M_PI - atan(fabs(y_out / x_out));
	}


	if (x_out < 0 && y_out > 0) {

		phi_out = M_PI - atan(fabs(y_out / x_out));
	}


	theta_out = theta_in;

	psi_out = psi_in;

	v_phi_out = v_phi_in * r_in / r_out;


	//	r_out = pow(pow(x_out, 2.0) + pow(y_out, 2.0), 1.0 / 2.0);

	//cout << x_out << " " << y_out << " " << z_out << " " << r_out << " " << endl;

	//cout << endl;



	long double h_z = fabs(z_out - z_in) / (N_CYL_partitions + 1);


	long double delta_t = h_z / fabs(sin(theta_in)*cos(psi_in));


	const long double mu_bor = 5.788381806638*pow(10.0, 13.0)*pow(2.99792458, 2.0); // магнетон Бора электронный в единицах эВ/Гс*(скорость света [мм/c])^2

																					//	const long double mu_bor = 3.152451260522*pow(10.0, 10.0)*pow(2.99792458, 2.0); // магнетон Бора ядерный в единицах эВ/Гс*(скорость света [мм/c])^2


	const long double mu_bor_force = 9.2740096820*pow(10.0, 0.0);

//	cout << "N_cyl_part " << N_CYL_partitions << endl;

	/*




	long double mu_particle = 0.0;
	long double mu_particle_force = 0.0;

	long double B_temp = 0.001;
	long double mu_temp_temp = 0.0;
	long double E_temp_temp = 0.0;



	if (flaq_on_off_mu_B == false) {
		mu_particle = mu_temp;
		mu_particle_force = mu_force_temp;
	}
	if (flaq_on_off_mu_B == true) {


		//	cout << index_condition << endl;

		if (particle_mode == 1) {
			mu_particle = mu_H(index_condition, B_temp, mu_temp_temp, E_temp_temp)*mu_bor;
			mu_particle_force = mu_H(index_condition, B_temp, mu_temp_temp, E_temp_temp)*mu_bor_force;
		}

		if (particle_mode == 2) {

			mu_particle = mu_D(index_condition, B_temp, mu_temp_temp, E_temp_temp)*mu_bor;
			mu_particle_force = mu_D(index_condition, B_temp, mu_temp_temp, E_temp_temp)*mu_bor_force;
		}

		if (particle_mode == 3) {
			mu_particle = mu_H_2(index_condition, B_temp, mu_temp_temp, E_temp_temp)*mu_bor;
			mu_particle_force = mu_H_2(index_condition, B_temp, mu_temp_temp, E_temp_temp)*mu_bor_force;

		}

		if (particle_mode == 4) { //-V112

			mu_particle = mu_D_2(index_condition, B_temp, mu_temp_temp, E_temp_temp)*mu_bor;
			mu_particle_force = mu_D_2(index_condition, B_temp, mu_temp_temp, E_temp_temp)*mu_bor_force;

		}

	}



	*/

	for (size_t i = 0; i <= N_CYL_partitions - 1; i = i + 1) {

		if (N_CYL_partitions == 0) {
			i = 1;
			break;
		}


		y = y + delta_t * sin(theta_in)*sin(psi_in);
		x = x - fabs(delta_t*cos(theta_in));





		//x = x + tan(theta_in)*cos(psi_in)*h_z;
		//y = y + tan(theta_in)*sin(psi_in)*h_z;
		if (strcmp(s, "left") == 0) {
			z = z + h_z;
		}

		if (strcmp(s, "right") == 0) {
			z = z - h_z;
		}



		rotate("inverse_matrix", x_in, y_in, z_in, x, y, z);
		r = pow(pow(x, 2.0) + pow(y, 2.0), 1.0 / 2.0);

		trajectory_cyl_x.push_back(x);
		trajectory_cyl_y.push_back(y);
		trajectory_cyl_z.push_back(z);
		trajectory_cyl_r.push_back(r);

		trajectory_cyl_mu.push_back(mu_particle / mu_bor);
		trajectory_cyl_B.push_back(0.0);

		if (mu_particle > 0.0) {
			trajectory_cyl_condition_color.push_back(11.0);
		}
		if (fabs(mu_particle - 0.0) <= epsilon) {
			trajectory_cyl_condition_color.push_back(10.0);
		}
		if (mu_particle < 0.0) {
			trajectory_cyl_condition_color.push_back(-11.0);
		}


		trajectory_cyl_v_x.push_back(V_0*sin(theta_in)*cos(psi_in));
		trajectory_cyl_v_y.push_back(V_0*sin(theta_in)*sin(psi_in));
		trajectory_cyl_v_z.push_back(V_0*cos(theta_in));
		trajectory_cyl_v_r.push_back(V_0*sin(theta_in)*cos(phi - psi_in));
		trajectory_cyl_v_phi.push_back(V_0*sin(theta_in)*sin(phi - psi_in));
		trajectory_cyl_v_perp.push_back(V_0*sin(theta_in));
		trajectory_cyl_v_0.push_back(V_0);
		trajectory_cyl_force.push_back(0.0);



		if (fabs(x - 0.0) <= epsilon && y > 0) {

			phi = M_PI_2;
		}


		if (fabs(x - 0.0) <= epsilon && y < 0) {

			phi = 3.0*M_PI_2;
		}


		if (fabs(y - 0.0) <= epsilon && x > 0) {

			phi = 0.0;
		}

		if (fabs(y - 0.0) <= epsilon && x < 0) {

			phi = M_PI;
		}

		if (fabs(y - 0.0) <= epsilon && fabs(x - 0.0) <= epsilon) {

			phi = 0.0;
		}

		if (x > 0 && y > 0) {

			phi = atan(fabs(y / x));
		}



		if (x < 0 && y < 0) {

			phi = M_PI + atan(fabs(y / x));
		}

		if (x > 0 && y < 0) {

			phi = 2.0*M_PI - atan(fabs(y / x));
		}


		if (x < 0 && y > 0) {

			phi = M_PI - atan(fabs(y / x));
		}




		trajectory_cyl_phi.push_back(phi);
		trajectory_cyl_psi.push_back(psi);
		trajectory_cyl_theta.push_back(theta);


		//cout << x << " " << y << " " << z << " " << r << " " << endl;

		if (y < 0) {
			trajectory_cyl_rr.push_back(-r);
		}
		else if (y >= 0) {
			trajectory_cyl_rr.push_back(r);
		}

		Vector_color_trajectory_cyl.push_back(0.0);

		out_trajectory_cyl.push_back(0.0);

		rotate("matrix", x_in, y_in, z_in, x, y, z);







	}


	//cout << x_out << " " << y_out << " " << z_out << " " << r_out << " " << endl;


	//cout<< endl;



	trajectory_cyl_x.push_back(x_out);
	trajectory_cyl_y.push_back(y_out);
	trajectory_cyl_z.push_back(z_out);
	trajectory_cyl_r.push_back(r_out);
	trajectory_cyl_force.push_back(0.0);

	trajectory_cyl_mu.push_back(mu_particle / mu_bor);
	trajectory_cyl_B.push_back(0.0);

	if (mu_particle > 0.0) {
		trajectory_cyl_condition_color.push_back(11.0);
	}
	if (fabs(mu_particle - 0.0) <= epsilon) {
		trajectory_cyl_condition_color.push_back(10.0);
	}
	if (mu_particle < 0.0) {
		trajectory_cyl_condition_color.push_back(-11.0);
	}


	trajectory_cyl_v_x.push_back(V_0*sin(theta_out)*cos(psi_out));
	trajectory_cyl_v_y.push_back(V_0*sin(theta_out)*sin(psi_out));
	trajectory_cyl_v_z.push_back(V_0*cos(theta_out));
	trajectory_cyl_v_r.push_back(V_0*sin(theta_out)*cos(phi_out - psi_out));
	trajectory_cyl_v_phi.push_back(V_0*sin(theta_in)*sin(phi_out - psi_out));
	trajectory_cyl_v_perp.push_back(V_0*sin(theta_out));
	trajectory_cyl_v_0.push_back(V_0);




	trajectory_cyl_phi.push_back(phi_out);
	trajectory_cyl_psi.push_back(psi_out);
	trajectory_cyl_theta.push_back(theta_out);


	if (y_out < 0) {
		trajectory_cyl_rr.push_back(-r_out);
	}
	else if (y_out >= 0) {
		trajectory_cyl_rr.push_back(r_out);
	}

	Vector_color_trajectory_cyl.push_back(0.0);

	out_trajectory_cyl.push_back(0.0);


}

long double func_r_2m(long double a, long double b, long double v_z, long double m, long double c, long double z, long double r, long double v_r) {

	long double f = 0.0;

	//if ((c - a / pow(r, 2.0) - 2.0*b / (m - 1.0)*pow(r, m - 1.0)) >= 0) {
	//	f = -signum(v_r)*pow((c-a/pow(r,2.0)-2.0*b/(m-1.0)*pow(r,m-1.0)),1.0/2.0)/v_z;
	f = -pow((c - a / pow(r, 2.0) - 2.0*b / (m - 1.0)*pow(r, m - 1.0)), 1.0 / 2.0) / v_z;


	//f = -pow((c + a*pow(r, 2.0) - 2.0*b / (m - 1.0)*pow(r, m - 1.0)), 1.0 / 2.0) / v_z;

	//f = -signum(v_r)*pow((c + a*pow(r, 2.0) - 2.0*b / (m - 1.0)*pow(r, m - 1.0)), 1.0 / 2.0) / v_z;

	//	}

	//else {

	//	f = 0.0;
	//	}

	return f;

}





inline long double func_r_2m_1(long double a, long double b, long double V_0, long double m, long double z, long double r) {

	long double f = 0.0;


	f = r / V_0;

	//if (f < 0) {
	//f = -f;
	//}

	return f;

}

inline long double func_r_2m_2(long double a, long double b, long double V_0, long double m, long double z, long double r) {

	long double f = 0.0;


	//	f = (pow(a, 2.0)*r - b *pow(r, m - 2.0)) / V_0;

	f = (a / pow(r, 3.0) - b * pow(r, m - 2.0)) / V_0;




	return f;

}

inline long double func_r_2m_2_magnetic_field_table(long double a, long double V_0, long double mu_particle, long double m_particle, long double z, long double r, const vector<long double> &Vector_r_magnetic_field_table, const vector<long double> &Vector_phi_magnetic_field_table, const vector<long double> &Vector_delta_B_magnetic_field_table, long double r_max, long double h_r_max, long double B_max, long double B_h_max, long double m_mag, long double z_in, long double L_cyl_temp_left, long double z0_mag, long double L_cyl, long double B_max_initial, long double r_max_initial, long double phi, vector <size_t> &Vector_index_r_magnetic_field_table, size_t &index_phi_magnetic_field_table, long double m_mag_table) {

	long double f = 0.0;

	const long double mu_bor = 5.788381806638*pow(10.0, 13.0)*pow(2.99792458, 2.0); // магнетон Бора электронный в единицах эВ/Гс*(скорость света [мм/c])^2

	long double k = 0.0;

	/*



	if (fabs(z_in - (L_cyl_temp_left + z0_mag)) <= epsilon) {
		k = ((B_max + B_h_max) / B_max)*pow(r_max / (r_max + h_r_max), m_mag - 1.0);
		//cout << h_r_max << endl;
	}

	if (fabs(z_in - (L_cyl_temp_left + L_cyl)) <= epsilon) {
		k = ((B_max - B_h_max) / B_max)*pow(r_max / (r_max - h_r_max), m_mag - 1.0);

	}

	*/


	//long double k = ((B_max + B_h_max) / B_max)*pow(r_max/(r_max+h_r_max), m_mag - 1.0);


	// коэффициент пересчета

	k = (B_max / B_max_initial)*pow(r_max_initial / r_max, m_mag_table - 1.0);




	long double delta_B = search_delta_B_magnetic_field_table(Vector_r_magnetic_field_table, Vector_phi_magnetic_field_table, Vector_delta_B_magnetic_field_table, r, phi, Vector_index_r_magnetic_field_table, index_phi_magnetic_field_table)*k;

	//cout << k <<" "<<delta_B<< endl;

	//	f = (pow(a, 2.0)*r - b *pow(r, m - 2.0)) / V_0;

	f = (a / pow(r, 3.0) - mu_particle * delta_B / m_particle) / V_0;


	//cout << f << endl;


	/*

	if (f != f) {

		cout << a << endl;
		cout << mu_particle << endl;
		cout << m_particle << endl;
		cout << V_0 << endl;
		cout << r << endl;
		cout << phi << endl;
		cout << r_max << endl;
		cout << B_max_initial << endl;
		cout << delta_B << endl;
		cout << f << endl;
		cout << endl;
	}
   */

	return f;

}


void out_magnetic_field_table(const char *filename, const vector<long double> &Vector_r_magnetic_field_table, const vector<long double> &Vector_phi_magnetic_field_table, const vector<long double> &Vector_B_magnetic_field_table, const vector<long double> &Vector_delta_B_magnetic_field_table, const vector <size_t> &Vector_index_r_magnetic_field_table, size_t index_phi_magnetic_field_table, long double r_min_mag_table, long double r_max_mag_table) {

	setlocale(LC_ALL, "rus");

	printf("\n");
	printf("Вывод таблицы магнитного поля\n");
	printf("\n");

	setlocale(LC_ALL, "C");





	// вывод полученных результатов в файл




	char string_name_1[256] = "/0";

	//char string_name_2[] =filename;

	strncpy_s(string_name_1, filename, strlen(filename) - 4); //-V112

	//strlen(string_name)


	strcat_s(string_name_1, "_ideal.txt");



	// вывод полученных результатов в файл
	FILE *fd1;

	fopen_s(&fd1, string_name_1, "wb");





	FILE *fd;

	fopen_s(&fd, filename, "wb");







	if (fd == NULL && fd1 == NULL) {
		fprintf(stderr, "Ошибка открытия выводного файла.\n");
		cout << endl;
		SleepEx(40, true); // пауза для того, чтобы успеть прочитать информацию
		exit(1);
	}
	else {
		setlocale(LC_ALL, "rus"); // корректное отображение Кириллицы



		setlocale(LC_ALL, "C"); // установить используемую системой локаль для корректной отображении точки в выходном файле

		size_t vector_size = Vector_r_magnetic_field_table.size();





		size_t vector_size_r = Vector_index_r_magnetic_field_table[0];

		size_t vector_size_phi = Vector_index_r_magnetic_field_table.size();

		size_t k = 0;

		long double r_mag_max = 0.0;
		long double B_mag_max = 0.0;
		long double phi_mag_max = 0.0;

		//cout << r_min_mag_table << endl;
		//cout << r_max_mag_table << endl;


		for (size_t i = 0; i < vector_size; i = i + 1) {


			if (Vector_r_magnetic_field_table[i] >= r_min_mag_table && Vector_r_magnetic_field_table[i] <= r_max_mag_table) {



				if (Vector_r_magnetic_field_table[i] > r_mag_max) {
					r_mag_max = Vector_r_magnetic_field_table[i];
				}

				if (Vector_B_magnetic_field_table[i] > B_mag_max) {
					B_mag_max = Vector_B_magnetic_field_table[i];
				}

				if (Vector_phi_magnetic_field_table[i] > phi_mag_max) {
					phi_mag_max = Vector_phi_magnetic_field_table[i];
				}
			}
		}

		long double m_mag = (int)(2.0*M_PI / phi_mag_max) / 2.0;

		long double B_temp = 0.0;
		long double delta_B_temp = 0.0;

		for (size_t i = 0; i < vector_size; i = i + 1) {

			if (Vector_r_magnetic_field_table[i] >= r_min_mag_table && Vector_r_magnetic_field_table[i] <= r_max_mag_table) {

				B_temp = B_mag_max * pow(Vector_r_magnetic_field_table[i] / r_mag_max, m_mag - 1.0);
				delta_B_temp = B_mag_max * (m_mag - 1.0)*pow(Vector_r_magnetic_field_table[i] / r_mag_max, m_mag - 2.0) / r_mag_max;


				fprintf(fd, "%.9Le %.9Le %.9Le %.9Le\n", Vector_r_magnetic_field_table[i], Vector_phi_magnetic_field_table[i], Vector_B_magnetic_field_table[i], Vector_delta_B_magnetic_field_table[i]);
				fprintf(fd1, "%.9Le %.9Le %.9Le %.9Le\n", Vector_r_magnetic_field_table[i], Vector_phi_magnetic_field_table[i], B_temp, delta_B_temp);

				if (i < vector_size - 1) {


					if (fabs(Vector_r_magnetic_field_table[i - 0] - 0.0) > epsilon && fabs(Vector_r_magnetic_field_table[i + 1] - 0.0) <= epsilon) {

						fprintf(fd, "\n");
						fprintf(fd1, "\n");

					}

					if (Vector_r_magnetic_field_table[i - 0] <= r_max_mag_table && Vector_r_magnetic_field_table[i + 1] > r_max_mag_table) {

						fprintf(fd, "\n");
						fprintf(fd1, "\n");

					}
				}
			}
			//else {


		//			fprintf(fd, "\n");
		//			fprintf(fd1, "\n");


		//	}

		}
	}





	setlocale(LC_ALL, "rus"); // корректное отображение Кириллицы

	fclose(fd);
	fclose(fd1);


}


void out_2_magnetic_field_table(const char *filename, const vector<long double> &Vector_r_magnetic_field_table, const vector<long double> &Vector_phi_magnetic_field_table, const vector<long double> &Vector_B_magnetic_field_table, const vector<long double> &Vector_delta_B_magnetic_field_table, const vector <size_t> &Vector_index_r_magnetic_field_table, size_t index_phi_magnetic_field_table, long double r_min_mag_table, long double r_max_mag_table) {

	setlocale(LC_ALL, "rus");

	printf("\n");
	printf("Вывод таблицы магнитного поля\n");
	printf("\n");

	setlocale(LC_ALL, "C");





	// вывод полученных результатов в файл





	char string_name_1[256] = "/0";

	//char string_name_2[] =filename;

	strncpy_s(string_name_1, filename, strlen(filename) - 4); //-V112

	//strlen(string_name)


	strcat_s(string_name_1, "_ideal.txt");



	// вывод полученных результатов в файл
	FILE *fd1;

	fopen_s(&fd1, string_name_1, "wb");











	FILE *fd;

	fopen_s(&fd, filename, "wb");







	if (fd == NULL && fd1 == NULL) {
		fprintf(stderr, "Ошибка открытия выводного файла.\n");
		cout << endl;
		SleepEx(40, true); // пауза для того, чтобы успеть прочитать информацию
		exit(1);
	}
	else {
		setlocale(LC_ALL, "rus"); // корректное отображение Кириллицы



		setlocale(LC_ALL, "C"); // установить используемую системой локаль для корректной отображении точки в выходном файле

		size_t vector_size = Vector_r_magnetic_field_table.size();

		size_t vector_size_r = Vector_index_r_magnetic_field_table[0];

		size_t vector_size_phi = Vector_index_r_magnetic_field_table.size();

		size_t k = 0;

		long double r_mag_max = 0.0;
		long double B_mag_max = 0.0;
		long double phi_mag_max = 0.0;



		for (size_t i = 0; i < vector_size; i = i + 1) {
			if (Vector_r_magnetic_field_table[i] >= r_min_mag_table && Vector_r_magnetic_field_table[i] <= r_max_mag_table) {
				if (Vector_r_magnetic_field_table[i] > r_mag_max) {
					r_mag_max = Vector_r_magnetic_field_table[i];
				}

				if (Vector_B_magnetic_field_table[i] > B_mag_max) {
					B_mag_max = Vector_B_magnetic_field_table[i];
				}

				if (Vector_phi_magnetic_field_table[i] > phi_mag_max) {
					phi_mag_max = Vector_phi_magnetic_field_table[i];
				}
			}
		}

		long double m_mag = (int)(2.0*M_PI / phi_mag_max) / 2.0;

		//	cout << m_mag << endl;
		//	cout << r_mag_max << endl;
		//	cout << B_mag_max << endl;


		long double B_temp = 0.0;
		long double delta_B_temp = 0.0;

		for (size_t ii = 0; ii < vector_size_r; ii = ii + 1) {

			for (size_t i = 0; i < vector_size_phi; i = i + 1) {
				k = ii + vector_size_r * i;
				if (Vector_r_magnetic_field_table[k] >= r_min_mag_table && Vector_r_magnetic_field_table[k] <= r_max_mag_table) {



					B_temp = B_mag_max * pow(Vector_r_magnetic_field_table[k] / r_mag_max, m_mag - 1.0);
					delta_B_temp = B_mag_max * (m_mag - 1.0)*pow(Vector_r_magnetic_field_table[k] / r_mag_max, m_mag - 2.0) / r_mag_max;
					fprintf(fd, "%.9Le %.9Le %.9Le %.9Le\n", Vector_r_magnetic_field_table[k], Vector_phi_magnetic_field_table[k], Vector_B_magnetic_field_table[k], Vector_delta_B_magnetic_field_table[k]);
					fprintf(fd1, "%.9Le %.9Le %.9Le %.9Le\n", Vector_r_magnetic_field_table[k], Vector_phi_magnetic_field_table[k], B_temp, delta_B_temp);
				}
			}

			fprintf(fd, "\n");
			fprintf(fd, "\n");

			fprintf(fd1, "\n");
			fprintf(fd1, "\n");
		}


	}





	setlocale(LC_ALL, "rus"); // корректное отображение Кириллицы

	fclose(fd);
	fclose(fd1);


}




// метод Рунге-Кутты 4 порядка для магнита, первый порядкок уравнения
void RK_4_mag_curve_1(long double L_mag, long double r_mag_initial, long double r_mag_final, long double B_mag_max_initial, long double B_mag_max_final, long double V_0, long double m_particle, long double m_mag, int n, long double x_in, long double y_in, long double z_in, long double r_in, long double theta_in, long double phi_in, long double psi_in, long double &x_out, long double &y_out, long double &z_out, long double &r_out, long double &theta_out, long double &phi_out, long double &psi_out, bool &out, vector<long double> &Vector_r, vector<long double> &Vector_z) {

	out = true;

	long double h_z = L_mag / n; // шаг по z
	long double h_r = (r_mag_final - r_mag_initial) / n; // шаг по r_max
	long double h_B = (B_mag_max_final - B_mag_max_initial) / n; // шаг по B_mag_max

																 //	cout << h_r << endl;

	long double r = r_in;
	long double z = 0.0;
	long double r_mag_max = r_mag_initial;
	long double c = 0.0; // константа с начальными условиями
	long double B = B_mag_max_initial;
	long double theta = theta_in;

	//Vector_r.push_back(0.0);
	//Vector_z.push_back(0.0);

	//Vector_r.push_back(r);
	//Vector_z.push_back(z);


	long double v_z = 0.0;
	long double v_r = 0.0;
	long double v_phi = 0.0;

	long double v_psi = 0.0;

	long double mu_particle = 0.0;

	const long double mu_bor = 5.788381806638*pow(10.0, 13.0)*pow(2.99792458, 2.0); // магнетон Бора электронный в единицах эВ/Гс*(скорость света [мм/c])^2

																					//const long double mu_bor = 3.152451260522*pow(10.0, 10.0)*pow(2.99792458, 2.0); // магнетон Бора ядерный в единицах эВ/Гс*(скорость света [мм/c])^2



																					// масса приходит в МэВ

	m_particle = m_particle * pow(10.0, 6.0); // теперь масса в эВ

	mu_particle = 0.0025*mu_bor;

	//mu_particle = 0.0;

	//mu_particle = 5.0*mu_bor;


	v_z = V_0 * cos(theta_in);

	v_r = V_0 * sin(theta_in); // скорость по радиусу на входе в магнит

	v_psi = V_0 * sin(theta_in)*sin(phi_in - psi_in); // скорость вдоль угла на входе в магнит

													//	}


	v_phi = V_0 * sin(theta_in)*cos(phi_in - psi_in);

	//v_r = V_0*sin(theta_in); // скорость по радиусу на входе в магнит




	long double a = pow(r_in*v_phi, 2.0);
	//long double a = pow(v_phi / r_in, 2.0);

	long double b = (m_mag - 1.0)*mu_particle*B_mag_max_initial / (m_particle*pow(r_mag_max, m_mag - 1.0));

	c = pow(v_r, 2.0) + pow(v_phi, 2.0) + 2.0*b*pow(r_in, m_mag - 1.0) / (m_mag - 1.0);

	//c = pow(v_r, 2.0) - pow(v_phi, 2.0) + 2.0*b*pow(r_in, m_mag - 1.0) / (m_mag - 1.0);


	long double k1 = 0.0, k2 = 0.0, k3 = 0.0, k4 = 0.0;

	// Применим теперь сам метод Рунге-Кутты 4 порядка
	long double r1 = r;// на предыдущей итерации
	long double r2 = r;// на текущей итерации










	for (int i = 0; i < n; i++) {


		k1 = func_r_2m(a, b, v_z, m_mag, c, z, r, v_r);
		k2 = func_r_2m(a, b, v_z, m_mag, c, z + (h_z / 2.0), r + (h_z / 2.0)*k1, v_r);
		k3 = func_r_2m(a, b, v_z, m_mag, c, z + (h_z / 2.0), r + (h_z / 2.0)*k2, v_r);
		k4 = func_r_2m(a, b, v_z, m_mag, c, z + h_z, r + h_z * k3, v_r);


		//cout << k1 << endl;
		//cout << k2 << endl;
		//cout << k3 << endl;
		//cout << k4 << endl;
		r = r + (h_z / 6.0)*(k1 + 2.0*k2 + 2.0*k3 + k4);

		z = z + h_z;

		Vector_r.push_back(r);

		Vector_z.push_back(z);


		//	Vector_r[i] = r

		//	Vector_r.push_back(r);

		//cout << r << endl;
		if ((r >= r_mag_max) || (r <= 0.0)) {



			//	Vector_r.erase(Vector_r.end() - i - 1, Vector_r.end());
			//	Vector_z.erase(Vector_z.end() - i - 1, Vector_z.end());
			//	Vector_x.erase(Vector_x.end() - i - 1, Vector_x.end());
			//	Vector_y.erase(Vector_y.end() - i - 1, Vector_y.end());

			//	cout << "ава" << endl;
			out = false;
			break;
		}

		r_mag_max = r_mag_max + h_r;
		B = B + h_B;



		//	Vector_z[i] = z;

		//Vector_z.push_back(z);

		//if (out == true) {
		//	Vector_r.push_back(r);

		//	Vector_z.push_back(z);
		//	}

		r2 = r;
		v_r = v_z * (r2 - r1) / h_z;
		r1 = r;

		//theta = atan((r2-r1)/h_z);

		theta = asin(v_r / V_0);
		b = (m_mag - 1.0)*mu_particle*B / (m_particle*pow(r_mag_max, m_mag - 1.0));
		c = pow(v_r, 2.0) + pow(v_phi, 2.0) + 2.0*b*pow(r, m_mag - 1.0) / (m_mag - 1.0);
		//	c = pow(v_r, 2.0) - pow(v_phi, 2.0) + 2.0*b*pow(r, m_mag - 1.0) / (m_mag - 1.0);
	}

	//if (out == false) {

	//Vector_r.erase(Vector_r.end() - n, Vector_r.end());
	//Vector_z.erase(Vector_z.end() - n, Vector_z.end());
	//Vector_r.pop_back();

	//Vector_z.pop_back();

	//	}

	//	Vector_r.push_back(r_mag_final);
	//	Vector_z.push_back(L_mag);

	//	Vector_r.push_back(0.0);
	//	Vector_z.push_back(L_mag);

	//theta_out = theta_in + atan(fabs(v_r / v_z));

	//theta_out = atan(fabs(v_r / v_z));

	//theta_out = atan(v_r / v_z);

	theta_out = fabs(theta);

	//theta_out = theta_in + asin(v_r / V_0);


	//theta_out = theta_in + (v_r / r_in)*(L_mag / v_z);

	//	theta_out = theta_in;

	phi_out = phi_in + (v_phi / r_in)*(L_mag / v_z);
	//phi_out = phi_in;


	psi_out = psi_in + (v_psi / r_in)*(L_mag / v_z);
	//psi_out = psi_in;

	if (v_r < 0) {
		//	psi_out = psi_out + M_PI;
		//	phi_out = phi_out + M_PI;
	}





	x_out = r * cos(phi_out);

	y_out = r * sin(phi_out);

	z_out = z_in + z;
	r_out = r;


}



// метод Рунге-Кутты 4 порядка для магнита, второй порядок уравнения
void RK_4_mag_curve_2(long double L_mag, long double r_mag_initial, long double r_mag_final, long double B_mag_max_initial, long double B_mag_max_final, long double &V_0, long double m_particle, long double m_mag, size_t n, long double x_in, long double y_in, long double z_in, long double r_in, long double theta_in, long double phi_in, long double psi_in, long double &x_out, long double &y_out, long double &z_out, long double &r_out, long double &theta_out, long double &phi_out, long double &psi_out, bool &out, vector<long double> &Vector_r, vector<long double> &Vector_z, vector<long double> &Vector_x, vector<long double> &Vector_y, long double min_r_out_mag, long double min_r_in_mag, size_t &n_mag_in,
	size_t &n_mag_absorption, size_t &n_mag_out, long double &z_zero, long double I_particle, long double J_particle, long double m_F, long double m_J, int particle_mode, long double iron_mag, long double v_r_in, long double &v_r_out, long double v_x_in, long double &v_x_out, long double v_y_in, long double &v_y_out, long double v_phi_in, long double &v_phi_out, vector<long double>&Vector_color_mag, long double cyl_number, vector<long double> &Vector_rr, vector<long double> &Vector_out, long double b_mag_surface, long double b_mag_left, long double b_mag_right, long double z0_mag, long double L_cyl, long double L_cyl_1, long double L_cyl_2, long double L_cyl_3, long double L_cyl_4, long double L_cyl_5, long double L_cyl_6, long double L_cyl_7, vector<long double> &Vector_phi,
	vector<long double> &Vector_psi, vector<long double> &Vector_theta, vector<long double> &Vector_v_x, vector<long double> &Vector_v_y, vector<long double> &Vector_v_z, vector<long double> &Vector_v_r, vector<long double> &Vector_v_phi, vector<long double> &Vector_v_perp, vector<long double> &Vector_v_0, long double n_cos_intensity, vector<long double> &Vector_force,
	size_t &N_negative_mag, size_t &N_zero_mag, size_t &N_positive_mag, long double mu_temp, long double mu_force_temp, vector<long double> &Vector_condition_color, bool flaq_on_off_mu_B, size_t index_condition, vector<long double> &Vector_mu, vector<long double> &Vector_B, vector<long double> &Vector_r_magnetic_field_table, vector<long double> &Vector_phi_magnetic_field_table, vector<long double> &Vector_B_magnetic_field_table, vector<long double> &Vector_delta_B_magnetic_field_table, bool on_off_table_magnetic_field, vector <size_t> &Vector_index_r_magnetic_field_table, size_t &index_phi_magnetic_field_table, long double m_mag_table, long double r_min_mag_table, long double r_max_mag_table,
	long double L_mag_B_off_after) {


	// cout<<"масса" << m_particle << endl;

	//	Vector_mu.clear();

		//cout << theta_in << " " << phi_in << " " << psi_in << endl;
		//cout << V_0 << endl;
		//cout << signum(cos(psi_in)*sin(phi_in)) << endl;

		//	cout <<x_in<<" "<<y_in<<" "<< z_in << endl;

	long double L_cyl_temp_left = 0.0;


	if (cyl_number == 7.0) { //-V550

		L_cyl_temp_left = L_cyl_1 + L_cyl_2 + L_cyl_3 + L_cyl_4 + L_cyl_5 + L_cyl_6;
	}


	if (cyl_number == 6.0) { //-V550

		L_cyl_temp_left = L_cyl_1 + L_cyl_2 + L_cyl_3 + L_cyl_4 + L_cyl_5;
	}


	if (cyl_number == 5.0) { //-V550

		L_cyl_temp_left = L_cyl_1 + L_cyl_2 + L_cyl_3 + L_cyl_4;
	}

	if (cyl_number == 4.0) { //-V550

		L_cyl_temp_left = L_cyl_1 + L_cyl_2 + L_cyl_3;
	}


	if (cyl_number == 3.0) { //-V550

		L_cyl_temp_left = L_cyl_1 + L_cyl_2;
	}

	if (cyl_number == 2.0) { //-V550

		L_cyl_temp_left = L_cyl_1;
	}


	if (cyl_number == 1.0) { //-V550

		L_cyl_temp_left = 0.0;
	}

	//cout << B_mag_max_initial << endl;
	//n_mag_in = n_mag_in + 1;
	out = true;


	if ((r_in < min_r_in_mag)||(r_in > r_mag_initial&&fabs(z_in - (L_cyl_temp_left + z0_mag)) <= epsilon)||(r_in > r_mag_final&&fabs(z_in - (L_cyl_temp_left + L_cyl)) <= epsilon)) {
		out = false;
		//cout << "!!!" << endl;
		z_out = z_in;
		r_out = r_in;
		x_out = x_in;
		y_out = y_in;
		
		//n_mag_in = n_mag_in - 1;

		goto step11;
	}
	else
	{

		n_mag_in = n_mag_in + 1;
		Vector_r.push_back(r_in);

		if (y_in < 0) {
			Vector_rr.push_back(-r_in);
		}
		else if (y_in >= 0) {
			Vector_rr.push_back(r_in);
		}

		Vector_z.push_back(0.0);

		Vector_x.push_back(x_in);
		Vector_y.push_back(y_in);




		Vector_phi.push_back(phi_in);
		Vector_psi.push_back(psi_in);
		Vector_theta.push_back(theta_in);

		Vector_v_x.push_back(V_0*sin(theta_in)*cos(psi_in));
		Vector_v_y.push_back(V_0*sin(theta_in)*sin(psi_in));
		Vector_v_z.push_back(V_0*cos(theta_in));
		Vector_v_r.push_back(V_0*sin(theta_in)*cos(phi_in - psi_in));
		Vector_v_phi.push_back(V_0*sin(theta_in)*sin(phi_in - psi_in));
		Vector_v_perp.push_back(V_0*sin(theta_in));
		Vector_v_0.push_back(V_0);


		//if (cyl_number == 1.0) {
		//	Vector_color_mag.push_back("black");
		//}

		//if (cyl_number == 2.0) {
		//	Vector_color_mag.push_back("red");
		//}
		//if (cyl_number == 3.0) {
		//	Vector_color_mag.push_back("blue");
		//}

		Vector_color_mag.push_back(cyl_number);
		Vector_out.push_back(0.0);
	}
	//	cout << min_r_in_mag << endl;

	//cout << theta_in << " " << r_in << endl;

	long double h_z = L_mag / n; // шаг по z
	long double h_r = (r_mag_final - r_mag_initial) / n; // шаг по r_max
	long double h_B = (B_mag_max_final - B_mag_max_initial) / n; // шаг по B_mag_max


																 //cout << theta_in << endl;

																 //	cout << h_r << endl;
	long double phi = phi_in;
	long double psi = psi_in;
	//long double v_r_0 = v_r_in;

	//phi = atan(x_in / y_in);
	long double r_1 = r_in;
	long double r_2 = 0.0;

	long double x = x_in;
	long double y = y_in;

	long double x0 = x_in;
	long double y0 = y_in;

	long double dx = 0.0;
	long double dy = 0.0;

	//cout << r_1 << " " << pow(x*x + y*y, 1.0 / 2.0) << endl;

	//	cout << x << " " << r_in*cos(psi_in) << endl;

	//cout << y_in / x_in << " " << tan(phi_in)<<endl;

	long double z = 0.0;
	long double r_mag_max = 0.0;
	long double B = 0.0;

	if (fabs(z_in - (L_cyl_temp_left + z0_mag)) <= epsilon) {
		r_mag_max = r_mag_initial;
		B = B_mag_max_initial;

	}

	if (fabs(z_in - (L_cyl_temp_left + L_cyl)) <= epsilon) {

		r_mag_max = r_mag_final;
		B = B_mag_max_final;
	}


	long double B_temp = 0.0;

	//B_temp = B*pow(r_in / r_mag_max, m_mag - 1.0);

	if (on_off_table_magnetic_field == false) {
		B_temp = B * pow(r_in / r_mag_max, m_mag - 1.0);
	}

	if (on_off_table_magnetic_field == true) {

		long double k = (B / B_mag_max_initial)*pow(r_mag_initial / r_mag_max, m_mag_table - 1.0);

		B_temp = search_B_magnetic_field_table(Vector_r_magnetic_field_table, Vector_phi_magnetic_field_table, Vector_B_magnetic_field_table, r_in, phi_in, Vector_index_r_magnetic_field_table, index_phi_magnetic_field_table)*k;

	}


	//	long double c = 0.0; // константа с начальными условиями

	long double theta = theta_in;

	//Vector_r.push_back(0.0);
	//Vector_z.push_back(0.0);



	long double v_z = 0.0;
	long double v_r = 0.0;

	long double v_x = 0.0;

	long double v_y = 0.0;

	long double v_perp = 0.0;
	long double v_phi = 0.0;
	//long double v_psi = 0.0;

	long double mu_particle = 0.0;
	long double mu_particle_force = 0.0;

	long double mu_temp_temp = 0.0;
	long double E_temp_temp = 0.0;

	const long double mu_bor = 5.788381806638*pow(10.0, 13.0)*pow(2.99792458, 2.0); // магнетон Бора электронный в единицах эВ/Гс*(скорость света [мм/c])^2

																					//	const long double mu_bor = 3.152451260522*pow(10.0, 10.0)*pow(2.99792458, 2.0); // магнетон Бора ядерный в единицах эВ/Гс*(скорость света [мм/c])^2


	const long double mu_bor_force = 9.2740096820*pow(10.0, 0.0);	 // опущена степень ^-21
																					// масса приходит в МэВ

	m_particle = m_particle * pow(10.0, 6.0); // теперь масса в эВ

											  //mu_particle = mu_bor;

											  //mu_particle = 10.0 * mu_bor;

											  //mu_particle = mu_bor/100.0;

											  //	mu_particle = 0.0000000000000001;
//	if (particle_mode == 0) {
	//	mu_particle = 0.0025*mu_bor;

	//	mu_particle_force = 0.0025*mu_bor_force;
	//	mu_particle = mu_temp;
	//}

//	mu_particle = mu_temp;
//	mu_particle_force = mu_force_temp;

	//cout << mu_particle << endl;

	//mu_particle = 0.0;

	//mu_particle_force = 0.0*mu_bor_force;

	//mu_particle = mu_particle*pow(10.0, 1.0);

	//mu_particle = 0.00065*mu_bor;

	//if (particle_mode == 3) {

	if (flaq_on_off_mu_B == false) {
		mu_particle = mu_temp;
		mu_particle_force = mu_force_temp;

		//cout << fabs(mu_particle / mu_bor) << endl;
	}
	if (flaq_on_off_mu_B == true) {


		//	cout << index_condition << endl;

		if (particle_mode == 1) {
			mu_particle = mu_H(index_condition, B_temp, mu_temp_temp, E_temp_temp)*mu_bor;
			mu_particle_force = mu_H(index_condition, B_temp, mu_temp_temp, E_temp_temp)*mu_bor_force;
		}

		if (particle_mode == 2) {

			mu_particle = mu_D(index_condition, B_temp, mu_temp_temp, E_temp_temp)*mu_bor;
			mu_particle_force = mu_D(index_condition, B_temp, mu_temp_temp, E_temp_temp)*mu_bor_force;
		}

		if (particle_mode == 3) {
			mu_particle = mu_H_2(index_condition, B_temp, mu_temp_temp, E_temp_temp)*mu_bor;
			mu_particle_force = mu_H_2(index_condition, B_temp, mu_temp_temp, E_temp_temp)*mu_bor_force;

		}

		if (particle_mode == 4) { //-V112

			mu_particle = mu_D_2(index_condition, B_temp, mu_temp_temp, E_temp_temp)*mu_bor;
			mu_particle_force = mu_D_2(index_condition, B_temp, mu_temp_temp, E_temp_temp)*mu_bor_force;

		}

	}

	//cout << fabs(mu_particle / mu_bor) << endl;

	//cout << mu_particle / mu_bor << endl;

	/*



	  long double rnd = random(0.0, 1.0);


	  if ((rnd <= 0.25) && (rnd >= 0.0)) {

		  mu_particle = 0.0025*mu_bor;
	  }


	  if ((rnd > 0.25) && (rnd <= 1.0)) {

		  mu_particle = -0.0025*mu_bor;
		  //	out = false;


		  //	Vector_r.erase(Vector_r.end()  - 1 - 0, Vector_r.end());
		  //	Vector_z.erase(Vector_z.end()  - 1 - 0, Vector_z.end());

		  //	Vector_x.erase(Vector_x.end()  - 1 - 0, Vector_x.end());
		  //	Vector_y.erase(Vector_y.end()  - 1 - 0, Vector_y.end());

		  //	Vector_r.shrink_to_fit();
		  //	Vector_z.shrink_to_fit();
		  //	Vector_x.shrink_to_fit();
		  //	Vector_y.shrink_to_fit();

		  //	goto step11;
	  }
	 */
	 //}
//	cout << mu_particle << endl;

	if (mu_particle > 0.0) {
		Vector_condition_color.push_back(11.0);
	}
	if (fabs(mu_particle - 0.0) <= epsilon) {
		Vector_condition_color.push_back(10.0);
	}
	if (mu_particle < 0.0) {
		Vector_condition_color.push_back(-11.0);
	}

	Vector_mu.push_back(mu_particle / mu_bor);
	Vector_B.push_back(B_temp);

	Vector_force.push_back(-mu_particle_force * B_mag_max_initial*(m_mag - 1.0)*pow(r_in / r_mag_max, m_mag - 1.0) / r_in);









	//mu_particle = 0.0025*mu_bor/100000000000000000000000000000000000.0;
	//	mu_particle = -0.0025*mu_bor *1.5;
	v_z = fabs(V_0*cos(theta_in));
	v_perp = fabs(V_0*sin(theta_in))*signum(v_r_in);




	long double v_perp_in = v_perp;

	//v_perp = pow(pow(V_0,2.0)-pow(v_z,2.0),1.0/2.0);

	//mu_particle = mu_bor;

	//particle_mode = 3;









	//	mu_particle = mu_particle / 10000000000.0;


	//mu_particle = 0.0;
	//signum(cos(psi_in))

	//v_r = signum(cos(psi_in))*V_0*sin(theta_in); // скорость по радиусу на входе в магнит
	//v_r = V_0*sin(theta_in); // скорость по радиусу на входе в магнит

	//v_r = V_0*sin(theta_in)*cos(phi_in-psi_in);

	//v_r = fabs(V_0*sin(theta_in)*cos(phi_in - psi_in))*signum(v_r_in);

	v_r = v_r_in;


	//	cout << z_in << endl;

	if (fabs(z_in - (L_cyl_temp_left + L_cyl)) <= epsilon) {

		//	cout << z_in << endl;

		//	cout << z0_mag + L_mag << endl;

		z = L_mag;
		v_z = -v_z;

		//	v_r = -v_r;
	}

	//cout << V_0*sin(theta_in)*cos(phi_in - psi_in) << endl;

	//cout << signum(v_r) << endl;
	//cout << theta_in << endl;


	//	long double v_r_0 = v_r;

	//v_phi = fabs(V_0*sin(theta_in)*sin(phi_in - psi_in)); // скорость вдоль угла на входе в магнит

	if (v_x_in > 0 && v_y_in > 0) {

		v_phi = fabs(V_0*sin(theta_in)*sin(phi_in - psi_in)); // скорость вдоль угла на входе в магнит

	}


	if (v_x_in < 0 && v_y_in < 0) {

		v_phi = -fabs(V_0*sin(theta_in)*sin(phi_in - psi_in));

	}


	if (v_x_in > 0 && v_y_in < 0) {

		v_phi = fabs(V_0*sin(theta_in)*sin(phi_in - psi_in));

	}


	if (v_x_in < 0 && v_y_in > 0) {


		v_phi = -fabs(V_0*sin(theta_in)*sin(phi_in - psi_in));
	}



	//	v_phi = V_0*sin(theta_in)*sin(phi_in - psi_in); // скорость вдоль угла на входе в магнит


	v_phi = v_phi_in;

	//long double v_phi_0 = V_0*sin(theta_in)*sin(phi_in - psi_in); // скорость вдоль угла на входе в магнит

	long double v_phi_0 = v_phi_in; // скорость вдоль угла на входе в магнит


									//v_r = 0.000000000001;											//	}


									//v_psi = V_0*sin(theta_in)*cos(phi_in - psi_in);

									//v_psi = V_0*sin(theta_in);

									//v_r = V_0*sin(theta_in); // скорость по радиусу на входе в магнит


	r_2 = v_r;

	//long double a = pow(v_phi/ r_in, 2.0);

	long double a = pow(r_in*v_phi_in, 2.0);

	long double aa = r_in * v_phi_in;


	//cout << v_phi_in << endl;

	long double b = (m_mag - 1.0)*mu_particle*B / (m_particle*pow(r_mag_max, m_mag - 1.0));




	long double k1_1 = 0.0, k2_1 = 0.0, k3_1 = 0.0, k4_1 = 0.0;
	long double k1_2 = 0.0, k2_2 = 0.0, k3_2 = 0.0, k4_2 = 0.0;

	// Применим теперь сам метод Рунге-Кутты 4 порядка
	long double r1 = r_1;// на предыдущей итерации
	long double r2 = r_1;// на текущей итерации


	long double d_phi = 0.0;




mag_in:

	//cout << endl;

	for (size_t i = 1; i <= n; i++) {


		//cout << mu_particle/mu_bor << endl;

	//	printf("%.6e \n", mu_particle / mu_bor);
		//cout << endl;

		//	if (fabs(z - epsilon) <= 0.0) {

		//		cout << z << endl;
		//		out = false;

		//		break;

		//	}



		x0 = x; // на предыдущем шаге
		y0 = y;

		r1 = r_1;
		v_phi_0 = v_phi;
		//cout << v_r << endl;




		//cout << k1_1 <<k1_2<< endl;
		//cout << k2_1 << k2_2 << endl;
		//cout << k3_1 << k3_2 << endl;
		//cout << k4_1 << k4_2 << endl;


		//	if (v_z >= 0) {

		if (on_off_table_magnetic_field == false) {


			k1_1 = func_r_2m_1(a, b, v_z, m_mag, z, r_2);
			k1_2 = func_r_2m_2(a, b, v_z, m_mag, z, r_1); //-V537

			k2_1 = func_r_2m_1(a, b, v_z, m_mag, z + (h_z / 2.0), r_2 + (h_z / 2.0)*k1_2);
			k2_2 = func_r_2m_2(a, b, v_z, m_mag, z + (h_z / 2.0), r_1 + (h_z / 2.0)*k1_1);

			k3_1 = func_r_2m_1(a, b, v_z, m_mag, z + (h_z / 2.0), r_2 + (h_z / 2.0)*k2_2);
			k3_2 = func_r_2m_2(a, b, v_z, m_mag, z + (h_z / 2.0), r_1 + (h_z / 2.0)*k2_1);

			k4_1 = func_r_2m_1(a, b, v_z, m_mag, z + h_z, r_2 + h_z * k3_2);
			k4_2 = func_r_2m_2(a, b, v_z, m_mag, z + h_z, r_1 + h_z * k3_1);

			//cout << endl;
		}

		if (on_off_table_magnetic_field == true) {


			k1_1 = func_r_2m_1(a, b, v_z, m_mag, z, r_2);
			k1_2 = func_r_2m_2_magnetic_field_table(a, v_z, mu_particle, m_particle, z, r_1, Vector_r_magnetic_field_table, Vector_phi_magnetic_field_table, Vector_delta_B_magnetic_field_table, r_mag_max, h_r, B, h_B, m_mag, z_in, L_cyl_temp_left, z0_mag, L_cyl, B_mag_max_initial, r_mag_initial, phi, Vector_index_r_magnetic_field_table, index_phi_magnetic_field_table, m_mag_table); //-V537

			k2_1 = func_r_2m_1(a, b, v_z, m_mag, z + (h_z / 2.0), r_2 + (h_z / 2.0)*k1_2);
			k2_2 = func_r_2m_2_magnetic_field_table(a, v_z, mu_particle, m_particle, z + (h_z / 2.0), r_1 + (h_z / 2.0)*k1_1, Vector_r_magnetic_field_table, Vector_phi_magnetic_field_table, Vector_delta_B_magnetic_field_table, r_mag_max, h_r, B, h_B, m_mag, z_in, L_cyl_temp_left, z0_mag, L_cyl, B_mag_max_initial, r_mag_initial, phi, Vector_index_r_magnetic_field_table, index_phi_magnetic_field_table, m_mag_table);



			k3_1 = func_r_2m_1(a, b, v_z, m_mag, z + (h_z / 2.0), r_2 + (h_z / 2.0)*k2_2);
			k3_2 = func_r_2m_2_magnetic_field_table(a, v_z, mu_particle, m_particle, z + (h_z / 2.0), r_1 + (h_z / 2.0)*k2_1, Vector_r_magnetic_field_table, Vector_phi_magnetic_field_table, Vector_delta_B_magnetic_field_table, r_mag_max, h_r, B, h_B, m_mag, z_in, L_cyl_temp_left, z0_mag, L_cyl, B_mag_max_initial, r_mag_initial, phi, Vector_index_r_magnetic_field_table, index_phi_magnetic_field_table, m_mag_table);


			k4_1 = func_r_2m_1(a, b, v_z, m_mag, z + h_z, r_2 + h_z * k3_2);
			k4_2 = func_r_2m_2_magnetic_field_table(a, v_z, mu_particle, m_particle, z + h_z, r_1 + h_z * k3_1, Vector_r_magnetic_field_table, Vector_phi_magnetic_field_table, Vector_delta_B_magnetic_field_table, r_mag_max, h_r, B, h_B, m_mag, z_in, L_cyl_temp_left, z0_mag, L_cyl, B_mag_max_initial, r_mag_initial, phi, Vector_index_r_magnetic_field_table, index_phi_magnetic_field_table, m_mag_table);


			/*



			cout << k1_2 << " " << k2_2 << " " << k3_2 << " " << k4_2 << endl;

			long double k1_1_0 = 0.0, k2_1_0 = 0.0, k3_1_0 = 0.0, k4_1_0 = 0.0;
			long double k1_2_0 = 0.0, k2_2_0 = 0.0, k3_2_0 = 0.0, k4_2_0 = 0.0;

			k1_1_0 = func_r_2m_1(a, b, v_z, m_mag, z, r_2);
			k1_2_0 = func_r_2m_2(a, b, v_z, m_mag, z, r_1); //-V537

			k2_1_0 = func_r_2m_1(a, b, v_z, m_mag, z + (h_z / 2.0), r_2 + (h_z / 2.0)*k1_2_0);
			k2_2_0 = func_r_2m_2(a, b, v_z, m_mag, z + (h_z / 2.0), r_1 + (h_z / 2.0)*k1_1_0);

			k3_1_0 = func_r_2m_1(a, b, v_z, m_mag, z + (h_z / 2.0), r_2 + (h_z / 2.0)*k2_2_0);
			k3_2_0 = func_r_2m_2(a, b, v_z, m_mag, z + (h_z / 2.0), r_1 + (h_z / 2.0)*k2_1_0);

			k4_1_0 = func_r_2m_1(a, b, v_z, m_mag, z + h_z, r_2 + h_z*k3_2_0);
			k4_2_0 = func_r_2m_2(a, b, v_z, m_mag, z + h_z, r_1 + h_z*k3_1_0);


			cout << k1_2_0 << " " << k2_2_0 << " " << k3_2_0 << " " << k4_2_0 << endl;

			cout << endl;

			*/
		}





		r_1 = r_1 + (h_z / 6.0)*(k1_1 + 2.0*k2_1 + 2.0*k3_1 + k4_1);
		r_2 = r_2 + (h_z / 6.0)*(k1_2 + 2.0*k2_2 + 2.0*k3_2 + k4_2);

		/*


		if (r_1 != r_1) {

			cout << k1_1 << endl;
			cout << k1_2 << endl;
			cout << k2_1 << endl;
			cout << k2_2 << endl;
			cout << k3_1 << endl;
			cout << k3_2 << endl;
			cout << k4_1 << endl;
			cout << k4_2 << endl;
		}
		*/
		//	}
		/*


		if (v_z<0) {

		k1_1 = func_r_2m_1(a, b, v_z, m_mag, z, r_2);
		k1_2 = func_r_2m_2(a, b, v_z, m_mag, z, r_1); //-V537

		k2_1 = func_r_2m_1(a, b, v_z, m_mag, z - (h_z / 2.0), r_2 - (h_z / 2.0)*k1_2);
		k2_2 = func_r_2m_2(a, b, v_z, m_mag, z - (h_z / 2.0), r_1 - (h_z / 2.0)*k1_1);

		k3_1 = func_r_2m_1(a, b, v_z, m_mag, z - (h_z / 2.0), r_2 - (h_z / 2.0)*k2_2);
		k3_2 = func_r_2m_2(a, b, v_z, m_mag, z - (h_z / 2.0), r_1 - (h_z / 2.0)*k2_1);

		k4_1 = func_r_2m_1(a, b, v_z, m_mag, z - h_z, r_2 - h_z*k3_2);
		k4_2 = func_r_2m_2(a, b, v_z, m_mag, z - h_z, r_1 - h_z*k3_1);

		r_1 = r_1 - (h_z / 6.0)*(k1_1 + 2.0*k2_1 + 2.0*k3_1 + k4_1);
		r_2 = r_2 - (h_z / 6.0)*(k1_2 + 2.0*k2_2 + 2.0*k3_2 + k4_2);
		}

		*/
		z = z + signum(v_z)*h_z;

		Vector_r.push_back(r_1);



		Vector_z.push_back(z);

		//if (cyl_number == 1.0) {
		//	Vector_color_mag.push_back("black");
		//}

		//if (cyl_number == 2.0) {
		//	Vector_color_mag.push_back("red");
		//}
		//if (cyl_number == 3.0) {
		//	Vector_color_mag.push_back("blue");
		//}

		Vector_color_mag.push_back(cyl_number);

		Vector_out.push_back(0.0);

		r2 = r_1;
		//v_r = v_z*(r2 - r1) / h_z;

		//v_z = V_0*cos(theta);

		//v_r = V_0*cos(theta)*(r2 - r1) / h_z;

		//v_r = v_z*(r2 - r1) / h_z;

		v_r = r_2;

		//cout << v_r << endl;

		//cout << atan((r2 - r1) / h_z) << " " << asin(v_r / V_0) << endl;

		//if (v_r < 0) {

		//r_1 = -r_1;
		//}

		//cout<<v_r<< " " << r_2 << endl;


		//cout << v_r <<" "<< pow((b)*pow(r_1, m_mag - 1.0), 1.0 / 2.0) << endl;

		//cout << v_r <<" "<<V_0*sin(theta)<< endl;

		//v_r = signum(r2 - r1)*pow((b)*pow(r_1, m_mag - 1.0), 1.0 / 2.0);

		v_phi = v_phi_in * r_in / r_1;

		v_perp = pow(pow(v_r, 2.0) + pow(v_phi, 2.0), 1.0 / 2.0)*signum(v_r);

		V_0 = pow((pow(v_z, 2.0) + pow(v_perp, 2.0)), 1.0 / 2.0);

		theta = fabs(asin(v_perp / V_0));

		//	cout << theta << endl;


			//theta = fabs(asin(v_r / V_0));

			//theta = fabs(asin(v_r / (V_0*cos(phi - psi))));

			//theta =(v_r / V_0);




			//theta = atan((r2 - r1) / h_z);

			//cout << atan((r2 - r1) / h_z) << " " << asin(v_r / V_0) << endl;

			//v_phi = V_0*sin(theta)*sin(phi - psi);
			//v_psi = V_0*sin(theta)*cos(phi - psi);

			//cout << v_r << endl;

			//	phi = phi + (v_phi / r_1)*(h_z / v_z);
			//	psi = psi + (v_psi / r_1)*(h_z / v_z);

			//v_phi = 100000.0;

			//phi = phi + (v_phi / r_in)*(h_z / v_z);

			//phi = phi + aa*(h_z / v_z)/pow(r_1,2.0)-(aa*r_2/pow(r_1,3.0))*pow(h_z / v_z,2.0);


		d_phi = -aa * (h_z / v_z) / pow(r_1, 2.0) + (aa*r_2 / pow(r_1, 3.0))*pow(h_z / v_z, 2.0);

		phi = phi + d_phi;

		while (phi < 0) {
			phi = phi + 2.0*M_PI;
		}

		/*



		if (phi != phi) {
			cout << "!" << endl;
			cout << d_phi << endl;
			cout << phi << endl;
			cout << aa << endl;
			cout << h_z << endl;
			cout << v_z << endl;
			cout << r_1 << endl;
			cout << r_2 << endl;
		}
	   */
	   //phi = 0.0;

	   //phi = phi + a*(h_z / v_z) / pow(r_1, 2.0);

	   //v_phi = v_phi_0*r_in / r_1;
	   //phi = phi + (v_phi / r_1)*(h_z / v_z);

	   //	psi = psi + (v_psi / r_in)*(h_z / v_z);

	   //cout << phi << endl;

	   //cout << v_phi / v_z << endl;

		x = r_1 * cos(phi);

		y = r_1 * sin(phi);



		dx = x - x0;
		dy = y - y0;

		//psi = psi + atan(dy / dx);

		Vector_x.push_back(x);

		Vector_y.push_back(y);





		if (dx >= 0 && dy >= 0) {

			//	psi_out = fabs(asin((dx)*v_z / (V_0*h_z*sin(theta))));

			psi = fabs(atan(dy / dx));
		}



		if (dx < 0 && dy < 0) {

			//	psi_out = M_PI + fabs(asin((dx)*v_z / (V_0*h_z*sin(theta))));

			psi = 1.0*M_PI + fabs(atan(dy / dx));

		}

		if (dx > 0 && dy < 0) {

			//	psi_out = 2.0*M_PI - fabs(asin((dx)*v_z / (V_0*h_z*sin(theta))));

			psi = 2.0*M_PI - fabs(atan(dy / dx));

		}


		if (dx < 0 && dy > 0) {

			//	psi_out = M_PI - fabs(asin((dx)*v_z / (V_0*h_z*sin(theta))));

			psi = 1.0*M_PI - fabs(atan(dy / dx));

		}





		Vector_phi.push_back(phi);
		Vector_psi.push_back(psi);
		Vector_theta.push_back(theta);


		Vector_v_x.push_back(V_0*sin(theta)*cos(psi));
		Vector_v_y.push_back(V_0*sin(theta)*sin(psi));
		Vector_v_z.push_back(V_0*cos(theta));
		Vector_v_r.push_back(V_0*sin(theta)*cos(phi - psi));
		Vector_v_phi.push_back(V_0*sin(theta)*sin(phi - psi));
		Vector_v_perp.push_back(V_0*sin(theta));
		Vector_v_0.push_back(V_0);
		Vector_force.push_back(-mu_particle_force * B*(m_mag - 1.0)*pow(r_1 / r_mag_max, m_mag - 1.0) / r_1);





		if (y < 0) {
			Vector_rr.push_back(-r_1);
		}
		else if (y >= 0) {
			Vector_rr.push_back(r_1);
		}

		//psi = phi - atan(v_phi / v_r);

		//	Vector_r[i] = r

		//	Vector_r.push_back(r);

		//cout << r << endl;


		//	if (r_1 <= 0) {

		//	cout << "!!!" << endl;
		//	}

		if ((r_1 >= (r_mag_max - iron_mag))) {

			//	cout << r2 << " " << r1 << endl;


			long double mu = random(0.0, 1.0); // случайное число для учета захвата частицы поверхностью цилиндра
											   //cout << mu;




			if (mu <= b_mag_surface) {

				//cout <<x0<<" "<<y<<" "<< z << " " <<r_1 << endl;


				if (r2 > (r_mag_max - iron_mag)) {

					Vector_r.erase(Vector_r.end() - 1, Vector_r.end());
					Vector_rr.erase(Vector_rr.end() - 1, Vector_rr.end());
					Vector_z.erase(Vector_z.end() - 1, Vector_z.end());
					Vector_mu.erase(Vector_mu.end() - 1, Vector_mu.end());
					Vector_B.erase(Vector_B.end() - 1, Vector_B.end());

					Vector_x.erase(Vector_x.end() - 1, Vector_x.end());
					Vector_y.erase(Vector_y.end() - 1, Vector_y.end());

					Vector_condition_color.erase(Vector_condition_color.end() - 1, Vector_condition_color.end());


					Vector_phi.erase(Vector_phi.end() - 1, Vector_phi.end());
					Vector_psi.erase(Vector_psi.end() - 1, Vector_psi.end());
					Vector_theta.erase(Vector_theta.end() - 1, Vector_theta.end());



					Vector_v_x.erase(Vector_v_x.end() - 1, Vector_v_x.end());
					Vector_v_y.erase(Vector_v_y.end() - 1, Vector_v_y.end());
					Vector_v_z.erase(Vector_v_z.end() - 1, Vector_v_z.end());
					Vector_v_r.erase(Vector_v_r.end() - 1, Vector_v_r.end());
					Vector_v_phi.erase(Vector_v_phi.end() - 1, Vector_v_phi.end());
					Vector_v_perp.erase(Vector_v_perp.end() - 1, Vector_v_perp.end());
					Vector_v_0.erase(Vector_v_0.end() - 1, Vector_v_0.end());
					Vector_force.erase(Vector_force.end() - 1, Vector_force.end());






					Vector_color_mag.erase(Vector_color_mag.end() - 1, Vector_color_mag.end());

					Vector_out.erase(Vector_out.end() - 1, Vector_out.end());


					Vector_r.shrink_to_fit();
					Vector_rr.shrink_to_fit();
					Vector_z.shrink_to_fit();
					Vector_x.shrink_to_fit();
					Vector_y.shrink_to_fit();

					Vector_mu.shrink_to_fit();
					Vector_B.shrink_to_fit();

					Vector_condition_color.shrink_to_fit();

					Vector_phi.shrink_to_fit();
					Vector_psi.shrink_to_fit();
					Vector_theta.shrink_to_fit();


					Vector_v_x.shrink_to_fit();
					Vector_v_y.shrink_to_fit();
					Vector_v_z.shrink_to_fit();
					Vector_v_r.shrink_to_fit();
					Vector_v_phi.shrink_to_fit();
					Vector_v_perp.shrink_to_fit();
					Vector_v_0.shrink_to_fit();
					Vector_force.shrink_to_fit();


					Vector_color_mag.shrink_to_fit();
					Vector_out.shrink_to_fit();

				}

				//	cout << "!!!" << endl;
				out = false;
				break;
			}


			else {

				//cout << "!!!" << endl;

				if (r2 > (r_mag_max - iron_mag)) {

					Vector_r.erase(Vector_r.end() - 1, Vector_r.end());
					Vector_rr.erase(Vector_rr.end() - 1, Vector_rr.end());
					Vector_z.erase(Vector_z.end() - 1, Vector_z.end());

					Vector_mu.erase(Vector_mu.end() - 1, Vector_mu.end());
					Vector_B.erase(Vector_B.end() - 1, Vector_B.end());


					Vector_condition_color.erase(Vector_condition_color.end() - 1, Vector_condition_color.end());



					Vector_x.erase(Vector_x.end() - 1, Vector_x.end());
					Vector_y.erase(Vector_y.end() - 1, Vector_y.end());


					Vector_phi.erase(Vector_phi.end() - 1, Vector_phi.end());
					Vector_psi.erase(Vector_psi.end() - 1, Vector_psi.end());
					Vector_theta.erase(Vector_theta.end() - 1, Vector_theta.end());


					Vector_v_x.erase(Vector_v_x.end() - 1, Vector_v_x.end());
					Vector_v_y.erase(Vector_v_y.end() - 1, Vector_v_y.end());
					Vector_v_z.erase(Vector_v_z.end() - 1, Vector_v_z.end());
					Vector_v_r.erase(Vector_v_r.end() - 1, Vector_v_r.end());
					Vector_v_phi.erase(Vector_v_phi.end() - 1, Vector_v_phi.end());
					Vector_v_perp.erase(Vector_v_perp.end() - 1, Vector_v_perp.end());
					Vector_v_0.erase(Vector_v_0.end() - 1, Vector_v_0.end());
					Vector_force.erase(Vector_force.end() - 1, Vector_force.end());



					Vector_color_mag.erase(Vector_color_mag.end() - 1, Vector_color_mag.end());

					Vector_out.erase(Vector_out.end() - 1, Vector_out.end());


					Vector_r.shrink_to_fit();
					Vector_rr.shrink_to_fit();
					Vector_z.shrink_to_fit();
					Vector_x.shrink_to_fit();
					Vector_y.shrink_to_fit();

					Vector_mu.shrink_to_fit();
					Vector_B.shrink_to_fit();

					Vector_condition_color.shrink_to_fit();


					Vector_phi.shrink_to_fit();
					Vector_psi.shrink_to_fit();
					Vector_theta.shrink_to_fit();


					Vector_v_x.shrink_to_fit();
					Vector_v_y.shrink_to_fit();
					Vector_v_z.shrink_to_fit();
					Vector_v_r.shrink_to_fit();
					Vector_v_phi.shrink_to_fit();
					Vector_v_perp.shrink_to_fit();
					Vector_v_0.shrink_to_fit();
					Vector_force.shrink_to_fit();


					Vector_color_mag.shrink_to_fit();
					Vector_out.shrink_to_fit();


				}



				long double ksi_mag = random(0.0, 1.0);

				//theta = asin(pow(ksi_mag, 1.0 / 2.0));


				theta = asin(pow(1.0 - pow(1.0 - ksi_mag, 2.0 / (n_cos_intensity + 1.0)), 1.0 / 2.0));




				theta = M_PI_2 - theta;

				psi = 2.0*M_PI*random(0.0, 1.0);

				k1_1 = 0.0, k2_1 = 0.0, k3_1 = 0.0, k4_1 = 0.0;
				k1_2 = 0.0, k2_2 = 0.0, k3_2 = 0.0, k4_2 = 0.0;

				r_1 = r_mag_max - iron_mag;

				//r1 = r_1;

				r2 = r_1;

				//phi = phi;
				//psi = psi;

				//x = x;
				//y = y;

				//x0 = x0;
				//y0 = y0;

				//dx = x-x0;
				//dy = y-y0;





				//z = z;
				//r_mag_max = r_mag_max;
				//B = B;


				v_r = -fabs(V_0*sin(theta)*cos(phi - psi));
				v_perp = V_0 * sin(theta);
				v_phi = V_0 * sin(theta)*sin(phi - psi);
				v_x = V_0 * sin(theta)*cos(psi);
				v_y = V_0 * sin(theta)*sin(psi);

				v_z = signum(cos(psi))*fabs(V_0*cos(theta));

				if (r2 > (r_mag_max - iron_mag)) {
					z = z + signum(v_z)*fabs(r2 - r_1)*h_z / fabs(r2 - r1);

					phi = phi - d_phi;

					d_phi = -aa * (h_z / v_z) / pow(r_1, 2.0) + (aa*r_2 / pow(r_1, 3.0))*pow(h_z / v_z, 2.0);

					phi = phi + d_phi * signum(v_z)*fabs(r2 - r_1) / fabs(r2 - r1);

					x = r_1 * cos(phi);
					y = r_1 * sin(phi);


				}


				// signum(v_z)
				//	else {

				//	z = z - signum(v_z)*h_z;
				//}





				//	cout << r2 - r1 << endl;

				//v_z = fabs(V_0*cos(theta));

				v_perp = fabs(V_0*sin(theta))*signum(v_r);

				v_perp_in = v_perp;


				if (v_z > 0) {
					h_z = fabs(L_mag - z) / n; // шаг по z

				}
				else {

					h_z = fabs(0.0 - z) / n; // шаг по z
				}


				v_r = v_r;

				if (v_x > 0 && v_y > 0) {

					v_phi = fabs(V_0*sin(theta)*sin(phi - psi)); // скорость вдоль угла на входе в магнит

				}


				if (v_x < 0 && v_y < 0) {

					v_phi = -fabs(V_0*sin(theta)*sin(phi - psi));

				}


				if (v_x > 0 && v_y < 0) {

					v_phi = fabs(V_0*sin(theta)*sin(phi - psi));

				}


				if (v_x < 0 && v_y > 0) {


					v_phi = -fabs(V_0*sin(theta)*sin(phi - psi));
				}


				//v_phi = v_phi;

				v_phi_in = v_phi;

				r_in = r_1;

				//v_phi_0 = v_phi; // скорость вдоль угла на входе в магнит

				r_2 = v_r;

				//	cout << r_2 << endl;

				a = pow(r_in*v_phi_in, 2.0);

				aa = r_in * v_phi_in;


				Vector_r.push_back(r_1);



				Vector_z.push_back(z);


				Vector_color_mag.push_back(cyl_number);

				Vector_out.push_back(0.0);



				Vector_phi.push_back(phi);

				Vector_psi.push_back(psi);

				Vector_theta.push_back(theta);


				Vector_v_x.push_back(V_0*sin(theta)*cos(psi));
				Vector_v_y.push_back(V_0*sin(theta)*sin(psi));
				Vector_v_z.push_back(V_0*cos(theta));
				Vector_v_r.push_back(V_0*sin(theta)*cos(phi - psi));
				Vector_v_phi.push_back(V_0*sin(theta)*sin(phi - psi));
				Vector_v_perp.push_back(V_0*sin(theta));
				Vector_v_0.push_back(V_0);
				Vector_force.push_back(-mu_particle_force * B_mag_max_initial*(m_mag - 1.0)*pow(r_1 / r_mag_max, m_mag - 1.0) / r_1);

				Vector_x.push_back(x);

				Vector_y.push_back(y);

				if (on_off_table_magnetic_field == false) {
					B_temp = B * pow(r_1 / r_mag_max, m_mag - 1.0);
				}

				if (on_off_table_magnetic_field == true) {

					long double k = (B / B_mag_max_initial)*pow(r_mag_initial / r_mag_max, m_mag_table - 1.0);

					B_temp = search_B_magnetic_field_table(Vector_r_magnetic_field_table, Vector_phi_magnetic_field_table, Vector_B_magnetic_field_table, r_1, phi, Vector_index_r_magnetic_field_table, index_phi_magnetic_field_table)*k;

				}

				if (flaq_on_off_mu_B == false) {
					mu_particle = mu_temp;
					mu_particle_force = mu_force_temp;
				}
				if (flaq_on_off_mu_B == true) {


					//	cout << index_condition << endl;

					if (particle_mode == 1) {
						mu_particle = mu_H(index_condition, B_temp, mu_temp_temp, E_temp_temp)*mu_bor;
						mu_particle_force = mu_H(index_condition, B_temp, mu_temp_temp, E_temp_temp)*mu_bor_force;
					}

					if (particle_mode == 2) {

						mu_particle = mu_D(index_condition, B_temp, mu_temp_temp, E_temp_temp)*mu_bor;
						mu_particle_force = mu_D(index_condition, B_temp, mu_temp_temp, E_temp_temp)*mu_bor_force;
					}

					if (particle_mode == 3) {
						mu_particle = mu_H_2(index_condition, B_temp, mu_temp_temp, E_temp_temp)*mu_bor;
						mu_particle_force = mu_H_2(index_condition, B_temp, mu_temp_temp, E_temp_temp)*mu_bor_force;

					}

					if (particle_mode == 4) { //-V112

						mu_particle = mu_D_2(index_condition, B_temp, mu_temp_temp, E_temp_temp)*mu_bor;
						mu_particle_force = mu_D_2(index_condition, B_temp, mu_temp_temp, E_temp_temp)*mu_bor_force;

					}

				}







				Vector_mu.push_back(mu_particle / mu_bor);
				Vector_B.push_back(B_temp);






				if (mu_particle > 0.0) {
					Vector_condition_color.push_back(11.0);
				}
				if (fabs(mu_particle - 0.0) <= epsilon) {
					Vector_condition_color.push_back(10.0);
				}
				if (mu_particle < 0.0) {
					Vector_condition_color.push_back(-11.0);
				}


				if (y < 0) {
					Vector_rr.push_back(-r_1);
				}
				else if (y >= 0) {
					Vector_rr.push_back(r_1);
				}



				goto mag_in;
			}




		}


		if (fabs(z_in - (L_cyl_temp_left + z0_mag)) <= epsilon) {
			r_mag_max = r_mag_max + h_r;
			B = B + h_B;

		}

		if (fabs(z_in - (L_cyl_temp_left + L_cyl)) <= epsilon) {
			r_mag_max = r_mag_max - h_r;
			B = B - h_B;

		}





		//	Vector_z[i] = z;

		//Vector_z.push_back(z);

		//if (out == true) {
		//	Vector_r.push_back(r_1);

		//	Vector_z.push_back(z);
		//}

		//r2 = r_1;
		//v_r = v_z*(r2 - r1) / h_z;

		//r1 = r_1;


		//theta = atan((r2 - r1) / h_z);
		//theta = asin(v_r / V_0);

		if (on_off_table_magnetic_field == false) {

			B_temp = B * pow(r_1 / r_mag_max, m_mag - 1.0);
		}

		if (on_off_table_magnetic_field == true) {


			long double k = (B / B_mag_max_initial)*pow(r_mag_initial / r_mag_max, m_mag_table - 1.0);

			B_temp = search_B_magnetic_field_table(Vector_r_magnetic_field_table, Vector_phi_magnetic_field_table, Vector_B_magnetic_field_table, r_1, phi, Vector_index_r_magnetic_field_table, index_phi_magnetic_field_table)*k;

		}

		if (flaq_on_off_mu_B == false) {
			mu_particle = mu_temp;
			mu_particle_force = mu_force_temp;
		}
		if (flaq_on_off_mu_B == true) {
			if (particle_mode == 1) {
				mu_particle = mu_H(index_condition, B_temp, mu_temp_temp, E_temp_temp)*mu_bor;
				mu_particle_force = mu_H(index_condition, B_temp, mu_temp_temp, E_temp_temp)*mu_bor_force;
			}

			if (particle_mode == 2) {

				mu_particle = mu_D(index_condition, B_temp, mu_temp_temp, E_temp_temp)*mu_bor;
				mu_particle_force = mu_D(index_condition, B_temp, mu_temp_temp, E_temp_temp)*mu_bor_force;
			}

			if (particle_mode == 3) {
				mu_particle = mu_H_2(index_condition, B_temp, mu_temp_temp, E_temp_temp)*mu_bor;
				mu_particle_force = mu_H_2(index_condition, B_temp, mu_temp_temp, E_temp_temp)*mu_bor_force;

			}

			if (particle_mode == 4) { //-V112

				mu_particle = mu_D_2(index_condition, B_temp, mu_temp_temp, E_temp_temp)*mu_bor;
				mu_particle_force = mu_D_2(index_condition, B_temp, mu_temp_temp, E_temp_temp)*mu_bor_force;

			}

		}



		if (i % 2 != 0) {

			Vector_condition_color.push_back(cyl_number);

		}
		else {

			if (mu_particle > 0.0) {
				Vector_condition_color.push_back(11.0);
			}
			if (fabs(mu_particle - 0.0) <= epsilon) {
				Vector_condition_color.push_back(10.0);
			}
			if (mu_particle < 0.0) {
				Vector_condition_color.push_back(-11.0);
			}

		}



		Vector_mu.push_back(mu_particle / mu_bor);
		Vector_B.push_back(B_temp);

		b = (m_mag - 1.0)*mu_particle*B / (m_particle*pow(r_mag_max, m_mag - 1.0));







		//	cout << x << " " << y << " " << r_1 << " " << z << endl;

		//psi = psi + (v_psi / r_1)*(h_z / v_z);

		//v_phi = V_0*sin(theta)*sin(phi - psi); 
		//v_psi = V_0*sin(theta)*cos(phi - psi);

		// a = pow(v_phi / r_1, 2.0);

		//a = pow(r_1*v_phi, 2.0);
	}


	//V_0 = pow((pow(v_z, 2.0) + pow(v_r, 2.0)), 1.0 / 2.0);

	//theta = asin(v_r / V_0);


	//theta = atan((r2 - r1) / h_z);
	//theta = asin(v_r / V_0);

	//if (out == false) {

	//Vector_r.erase(Vector_r.end() - n, Vector_r.end());
	//Vector_z.erase(Vector_z.end() - n, Vector_z.end());
	//Vector_r.pop_back();

	//Vector_z.pop_back();

	//	}

	//	Vector_r.push_back(r_mag_final);
	//	Vector_z.push_back(L_mag);

	//	Vector_r.push_back(0.0);
	//	Vector_z.push_back(L_mag);

	//theta_out = theta_in + atan(fabs(v_r / v_z));

	//theta_out = atan(fabs(v_r / v_z));

	//theta_out = atan(v_r / v_z);

	theta_out = fabs(theta);

	//theta_out = theta_in + asin(v_r / V_0);


	//theta_out = theta_in + (v_r / r_in)*(L_mag / v_z);

	//	theta_out = theta_in;

	//phi_out = phi_in + (v_phi / r_in)*(L_mag / v_z);

	//phi_out = phi_in;
	phi_out = phi;

	//psi_out = phi_out - acos(v_r/v_perp);

	//psi_out = phi_out - atan(v_phi/v_r);

	//psi_out = asin((x - x0)*v_z / (V_0*h_z*sin(theta)));


	if (dx >= 0 && dy >= 0) {

		//	psi_out = fabs(asin((dx)*v_z / (V_0*h_z*sin(theta))));

		psi_out = fabs(atan(dy / dx));
	}



	if (dx < 0 && dy < 0) {

		//	psi_out = M_PI + fabs(asin((dx)*v_z / (V_0*h_z*sin(theta))));

		psi_out = 1.0*M_PI + fabs(atan(dy / dx));

	}

	if (dx > 0 && dy < 0) {

		//	psi_out = 2.0*M_PI - fabs(asin((dx)*v_z / (V_0*h_z*sin(theta))));

		psi_out = 2.0*M_PI - fabs(atan(dy / dx));

	}


	if (dx < 0 && dy > 0) {

		//	psi_out = M_PI - fabs(asin((dx)*v_z / (V_0*h_z*sin(theta))));

		psi_out = 1.0*M_PI - fabs(atan(dy / dx));

	}

	//cout << dx << " " << dy << endl;

	//psi_out = -psi_out+M_PI;

	//psi_out = fabs(fabs(phi_out) - fabs(atan(v_phi/v_r)));

	//psi_out = psi;
	//psi_out = phi_out - atan(v_phi / v_r);

	//x_out = r_1;
	//y_out = 0.0;
	//phi_out = 0.0;

	//psi_out = psi_in - (v_psi / r_in)*(L_mag / v_z);

	//psi_out = psi_in*signum(v_r);

	//psi_out = psi_in;

	//	psi_out = psi;
	//psi_out = M_PI_2+phi_out;

	//psi_out = M_PI;

	//psi_out = psi;
	//	cout <<v_r_0<<" "<< v_r << endl;

	//cout << signum(v_r) << endl;

	//if (signum(v_r*v_r_0*sin(phi))<0) {
	//psi_out = psi_out+ M_PI;
	//phi_out = phi_out + M_PI;
	//}



	//if (signum(v_r*r_2) < 0) {
	//psi_out = psi_out + M_PI;
	//psi_out = -psi_out ;
	//	phi_out = phi_out + M_PI;
	//}


	//psi_out = psi_out*signum(cos(psi_in)*cos(phi_in)*signum(-v_r));

	//psi_out = psi_out*signum(sin(psi_in)*signum(v_r));


	x_out = x;
	y_out = y;



	//x_out = r_1*cos(phi_out);

	//y_out = r_1*sin(phi_out);


	if (fabs(z_in - (L_cyl_temp_left + z0_mag)) <= epsilon) {
		z_out = z_in + z;
	}

	if (fabs(z_in - (L_cyl_temp_left + L_cyl)) <= epsilon) {

		z_out = L_cyl_temp_left + z0_mag + z;
	}


	//cout << z << endl;

	r_out = r_1;


	v_r_out = r_2;



	//if (signum(v_r_in*v_r_out) < 0) {
	//	psi_out = -psi_out + 2.0*M_PI;
	//psi_out = -psi_out;
	//psi_out = -psi_out ;
	//	phi_out = phi_out + M_PI;
	//}




	v_phi_out = v_phi_in * r_in / r_out;

	long double v_perp_out = v_perp;

	//if (signum(v_perp_in*v_perp_out) < 0) {
	//psi_out = psi_out + M_PI;
	//psi_out = -psi_out ;
	//phi_out = phi_out + M_PI;
	//}


	//cout << v_r << " " << v_r_0 << endl;
	//cout << min_r_out_mag << endl;

	if (r_out <= min_r_out_mag) {



		out = false;
		//	Vector_r.erase(Vector_r.end() - n - 1 - 1, Vector_r.end());
		//	Vector_rr.erase(Vector_rr.end() - n - 1 - 1, Vector_rr.end());
		//	Vector_z.erase(Vector_z.end() - n - 1 - 1, Vector_z.end());

		//	Vector_x.erase(Vector_x.end() - n - 1 - 1, Vector_x.end());
		//	Vector_y.erase(Vector_y.end() - n - 1 - 1, Vector_y.end());

		//	Vector_color_mag.erase(Vector_color_mag.end() - n - 1 - 1, Vector_color_mag.end());



		//	Vector_r.shrink_to_fit();
		//	Vector_rr.shrink_to_fit();
		//	Vector_z.shrink_to_fit();
		//	Vector_x.shrink_to_fit();
		//	Vector_y.shrink_to_fit();

		//	Vector_color_mag.shrink_to_fit();


	}

step11:

	//	if (fabs(z - epsilon) <= 0.0) {

	//		out = false;
	//	}

	if (out == false) {
		//	cout << x_in << " " << y_in << " " << r_in << " " << z_in << "in " << endl;
		//	cout << x << " " << y << " " << r_1 << " " << z <<  "out" << endl;

		n_mag_absorption = n_mag_absorption + 1;
	}

	if (out == true) {

		//cout << v_r << " "<<v_r_0<<endl;
		//cout << x << " " << y << " " << z << " " << r_1 << endl;

		//cout << signum(v_r_in) << endl;

		n_mag_out = n_mag_out + 1;

	}




	//cout << theta_out << endl;

	if (out == true) {

		z_zero = r_out / tan(theta_out);
	}
	else {


		z_zero = 0.0;
	}


	//	if (out == true) {

	//cout << z_zero << endl;

	//}



	//cout << r_out << endl;

	//cout << v_phi_in << " " << v_phi_out << endl;


	if (out == true) {

		Vector_out.erase(Vector_out.end() - 1, Vector_out.end());

		Vector_out.shrink_to_fit();

		Vector_out.push_back(1.0);

		long double mu_particle_temp = 0.0;
		long double mu_particle_force_temp = 0.0;



		if (flaq_on_off_mu_B == false) {
			mu_particle_temp = mu_temp;
			mu_particle_force_temp = mu_force_temp;

			//cout << fabs(mu_particle / mu_bor) << endl;
		}
		if (flaq_on_off_mu_B == true) {


			//	cout << index_condition << endl;

			if (particle_mode == 1) {
				mu_particle_temp = mu_H(index_condition, B_MAX, mu_temp_temp, E_temp_temp)*mu_bor;
				mu_particle_force_temp = mu_H(index_condition, B_MAX, mu_temp_temp, E_temp_temp)*mu_bor_force;
			}

			if (particle_mode == 2) {

				mu_particle_temp = mu_D(index_condition, B_MAX, mu_temp_temp, E_temp_temp)*mu_bor;
				mu_particle_force_temp = mu_D(index_condition, B_MAX, mu_temp_temp, E_temp_temp)*mu_bor_force;
			}

			if (particle_mode == 3) {
				mu_particle_temp = mu_H_2(index_condition, B_MAX, mu_temp_temp, E_temp_temp)*mu_bor;
				mu_particle_force_temp = mu_H_2(index_condition, B_MAX, mu_temp_temp, E_temp_temp)*mu_bor_force;

			}

			if (particle_mode == 4) { //-V112

				mu_particle_temp = mu_D_2(index_condition, B_MAX, mu_temp_temp, E_temp_temp)*mu_bor;
				mu_particle_force_temp = mu_D_2(index_condition, B_MAX, mu_temp_temp, E_temp_temp)*mu_bor_force;

			}

		}






		if (fabs(z_out - (z_in + L_mag)) <= epsilon) {
			if (mu_particle_temp > 0.0 && mu_particle_force_temp > 0.0) {
				N_positive_mag = N_positive_mag + 1;

			}

			if (mu_particle_temp < 0.0 && mu_particle_force_temp < 0.0) {
				N_negative_mag = N_negative_mag + 1;

			}
			if (fabs(mu_particle_temp - 0.0) <= epsilon && fabs(mu_particle_force_temp - 0.0) <= epsilon) {
				N_zero_mag = N_zero_mag + 1;

			}
		}

	}
	return;
}





void mag_curve(long double x_in, long double y_in, long double z_in, long double r_in, long double theta_in, long double phi_in, long double psi_in, long double &x_out, long double &y_out, long double &z_out, long double &r_out, long double &theta_out, long double &phi_out, long double &psi_out, long double z0_mag, long double L_mag, long double r_mag_max, long double mu_core_particle, long double mu_electron_particle, long double m_particle, long double I_particle, long double J_particle, long double m_F, long double m_J, long double B_max, long double B_critical, bool &out, long double V_0, long double &z_zero, size_t &n_mag_in, size_t &n_mag_absorption, size_t &n_mag_out, long double r_mag_max_initial, long double r_mag_max_final) {


	n_mag_in = n_mag_in + 1;

	//long double m; // масса, нужно определить
	//	long double L; // момент частицы, сохраняется
	long double a = 0.0;
	long double b = 0.0;
	long double c = 0.0;
	long double A = 0.0;
	long double lambda = 0.0;
	long double gamma = 0.0;
	long double z = L_mag; // нужно определить
	long double r0 = r_in; // радиус влета в магнит
						   //long double r_max; // нужно определить
	long double y0 = 0.0;
	long double v_z = V_0 * cos(theta_in); // начальная скорость по z

										 // масса приходит в МэВ

	m_particle = m_particle * pow(10.0, 6.0); // теперь масса в эВ

											  //cout << m_particle << endl;

											  //cout << B_max<< endl;

											  //kcout << V_0<< endl;

											  //cout << r_mag_max << endl;

	out = true;

	long double v_phi = 0.0; // начальная скорость по углу phi
	long double v_psi = 0.0;
	long double v_r = 0.0;

	//	if (r_in <= LDBL_EPSILON) {
	//		v_phi = LDBL_MAX;
	//	}
	//	else {

	v_psi = V_0 * sin(theta_in)*sin(phi_in - psi_in); // скорость вдоль угла на входе в магнит

													//	}


	v_phi = V_0 * sin(theta_in)*cos(phi_in - psi_in);

	v_r = V_0 * sin(theta_in); // скорость по радиусу на входе в магнит


							 //long double mu; // нужно определить
	const long double mu_bor = 5.788381806638*pow(10.0, 13.0)*pow(2.99792458, 2.0); // магнетон Бора электронный в единицах эВ/Гс*(скорость света [мм/c])^2

																					//	const long double mu_bor = 3.152451260522*pow(10.0, 10.0)*pow(2.99792458, 2.0); // магнетон Бора ядерный в единицах эВ/Гс*(скорость света [мм/c])^2

																					//long double B_max; // нужно определить

	long double delta1 = 0.0;
	long double delta2 = 0.0;


	long double r1 = 0.0;
	long double r2 = 0.0;

	long double B0 = B_max * pow(r0 / r_mag_max, 2.0); // поле на влете в магнит

	long double x_mag_field = B0 / B_critical;

	long double mu_particle = 0.0; // эффективный магнитный момент

	if (m_J == 0.5) { //-V550

		mu_particle = m_F * mu_core_particle*mu_bor - (mu_core_particle - mu_electron_particle)*mu_bor*(m_F / (2.0*I_particle + 1.0) + x_mag_field / 2.0) / pow(1.0 + x_mag_field * (4.0*m_F) / (2.0*I_particle + 1.0) + pow(x_mag_field, 2.0), 1.0 / 2.0);


	}

	if (m_J == -0.5) { //-V550

		mu_particle = m_F * mu_core_particle*mu_bor + (mu_core_particle - mu_electron_particle)*mu_bor*(m_F / (2.0*I_particle + 1.0) + x_mag_field / 2.0) / pow(1.0 + x_mag_field * (4.0*m_F) / (2.0*I_particle + 1.0) + pow(x_mag_field, 2.0), 1.0 / 2.0);


	}

	//mu_particle = 0.0025*mu_bor;

	//mu_particle = mu_bor/2000.0;

	mu_particle = mu_bor;

	//	if (B_max <= LDBL_EPSILON) {

	//		B_max = LDBL_EPSILON;

	//	}


	gamma = mu_particle * B_max / pow(r_mag_max, 2.0);

	//	a = pow(pow(r0, 2.0)*v_phi, 2.0);

	a = pow(r0*v_phi, 2.0);

	b = 2.0*gamma / m_particle;

	//	cout << r0 << endl;
	//	cout << b << endl;
	//c = pow(v_r, 2.0) + pow(r0*v_phi, 2.0) + b*pow(r0, 2.0);

	c = pow(v_r, 2.0) + pow(v_phi, 2.0) + b * pow(r0, 2.0);

	A = pow((pow(c / (4.0*b), 2.0) - a / (4.0*b)), 1.0 / 2.0);

	lambda = pow(fabs(b), 1.0 / 2.0) / fabs(v_z);



	y0 = pow(r0, 2.0) / 2.0 - c / (4.0*b);





	if (mu_particle > 0) {



		//delta1 = asin(signum(v_r)*pow(pow(y0/A, 2.0) - 1.0, 1.0 / 2.0));

		if (fabs(y0 / A) >= 1.0) {

			delta1 = 0.0;
		}
		else {
			delta1 = acos(y0 / A);
		}

		//	cout << delta1 << endl;

		//delta1 = acos(y0 / A);


		r1 = pow((c / (2.0*b) + 2.0*A*cos(2.0*lambda*z + delta1)), 1.0 / 2.0);




		long double r1_max = pow((c / (2.0*b) + 2.0*A), 1.0 / 2.0); // сам максимум
		long double z1_max = 0.0; // точка максимума
								  // находим минимальную точку максимума
		if (delta1 <= 0) {
			z1_max = -delta1 / (2.0*lambda);
		}
		else {
			z1_max = (2.0*M_PI - delta1) / (2.0*lambda);
		}

		//	cout << psi_in << endl;
		//	cout << c / (2.0*b) << endl;
		//	cout << cos(2.0*lambda*z + delta1) << endl;
		//cout <<v_phi << endl;
		//cout << m_particle << endl;

		//printf("%.9Le %.9Le %.9Le %.3Lf %.9Le %.9Le %.3Lf %.3Lf %.9Le %.3Lf %.3Lf %.3Lf\n", a, b, c, A, lambda, delta1, y0, r0, v_r, r1, r1_max, z1_max);

		v_r = -A * sin(2.0 * lambda*z + delta1) * 2.0 * lambda*v_z / r1; // радиальная скорость на выходе из магнита

																	   //cout << v_r << endl;


																	   //v_r = pow((c - a / pow(r1, 2.0) - b*pow(r1, 2.0)), 1.0 / 2.0);

																	   //cout << v_r << endl;

		if (((r1_max >= r_mag_max) && (z1_max <= L_mag) && (z1_max >= 0.0)) || (r1 >= r_mag_max)) {
			//if ((r1>= r_mag_max)) {

			out = false;
			//out = true;

			//	cout << " " << endl;
		}

		else {

			r_out = r1;
			out = true;


			//z_zero = (acos(-c/pow(c*c+4.0*a*b,1.0/2.0))-2.0*lambda*L_mag-delta1)/(2.0*lambda);

			//	z_zero = (M_PI_2 + atan(pow(c*c/(4.0*a*b)-1.0,1.0/2.0))-2.0*lambda*L_mag-delta1+2.0*M_PI)/(2.0*lambda); // расстояние от магнита на котором зануляется радиус

			//z_zero =(acos(-c/(4.0*b*A))-delta1)/(2.0*lambda); // расстояние от магнита на котором зануляется радиус


			z_zero = (3.0*M_PI - delta1) / (2.0*lambda);
			//	cout << -c / (4.0*b*A) << endl;
			//	cout << (4.0*a*b)/(c*c) << endl;
			//cout << z_zero << endl;
			//cout << r_out << endl;
		}





	}


	else if (mu_particle < 0) {


		//delta2 = asinh((-1.0*signum(r0) / A)*pow(pow(y0, 2.0) - pow(A, 2.0), 1.0 / 2.0));

		if (fabs(-y0 / A) <= 1.0) {

			delta2 = 0.0;
		}
		else {

			delta2 = acosh(-y0 / A);
		}



		r2 = pow((c / (2.0*b) + 2.0*A*cosh(2.0 * lambda*z + delta2)), 1.0 / 2.0);

		// макимум принимается только на концах интервала, нет локальных максимумов
		long double r2_max = pow(c / (2.0 * b) + 2.0 * A*cosh(2.0*lambda*z + delta2), 1.0 / 2.0);

		if (r2_max >= r_mag_max) {

			out = false;

		}

		else {

			r_out = r2;
			out = true;

			//	v_r = A*sinh(2.0 * lambda*z + delta2) * 2.0 * lambda*v_z / r2;

			v_r = pow((c - a / pow(r2, 2.0) - b * pow(r2, 2.0)), 1.0 / 2.0);

		}






	}

	else if (fabs(mu_particle - 0.0) <= epsilon) {



		x_out = x_in;
		y_out = y_in;
		z_in = z_in;
		theta_out = theta_in;

	}





	//theta_out = theta_in + atan(fabs(v_r / v_z));

	theta_out = atan(fabs(v_r / v_z));

	//theta_out = atan(v_r / v_z);

	//theta_out = theta_in + asin(v_r / V_0);


	//theta_out = theta_in + (v_r / r_in)*(L_mag / v_z);

	//	theta_out = theta_in;

	//phi_out = phi_in + (v_phi / r_in)*(L_mag / v_z);
	phi_out = phi_in;


	psi_out = psi_in + (v_psi / r_in)*(L_mag / v_z);
	//psi_out = psi_in;

	if (v_r < 0) {
		//psi_out = psi_out + M_PI;
		phi_out = phi_out + M_PI;
	}


	x_out = r_out * cos(phi_out);

	y_out = r_out * sin(phi_out);


	z_out = z_in + L_mag;


	if (out == false) {
		n_mag_absorption = n_mag_absorption + 1;
	}
	else if (out == true) {

		n_mag_out = n_mag_out + 1;
	}

}


void find_trajectory_mag(long double number_mag, const vector<long double> &trajectory_cyl_x, const vector<long double> &trajectory_cyl_y, const vector<long double> &trajectory_cyl_z, const vector<long double> &trajectory_cyl_r, const vector<long double> &trajectory_cyl_rr, const vector<long double>&Vector_color_trajectory_cyl, const vector<long double> &out_trajectory_cyl, vector<long double> &Vector_x_mag, vector<long double> &Vector_y_mag, vector<long double> &Vector_z_mag, vector<long double> &Vector_r_mag, vector<long double> &Vector_rr_mag,
	vector<long double>&Vector_color_mag, vector<long double> &Vector_out_mag, long double L_mag_initial, long double L_mag_final, bool out_tube, const vector<long double> &trajectory_cyl_phi,
	const vector<long double> &trajectory_cyl_psi, const vector<long double> &trajectory_cyl_theta, vector<long double> &Vector_phi_mag, vector<long double> &Vector_psi_mag, vector<long double> &Vector_theta_mag, const vector<long double> &trajectory_cyl_v_x, const vector<long double> &trajectory_cyl_v_y, const vector<long double> &trajectory_cyl_v_z, const vector<long double> &trajectory_cyl_v_r, const vector<long double> &trajectory_cyl_v_phi, const vector<long double> &trajectory_cyl_v_perp, const vector<long double> &trajectory_cyl_v_0,
	vector<long double> &Vector_v_x_mag, vector<long double> &Vector_v_y_mag, vector<long double> &Vector_v_z_mag, vector<long double> &Vector_v_r_mag, vector<long double> &Vector_v_phi_mag, vector<long double> &Vector_v_perp_mag, vector<long double> &Vector_v_0_mag, const vector<long double> &trajectory_cyl_force, vector<long double> &Vector_force_mag,
	const vector<long double> &trajectory_cyl_condition_color, vector<long double> &Vector_condition_color_mag, const vector<long double> &trajectory_cyl_mu, const vector<long double> &trajectory_cyl_B, vector<long double> &Vector_mu_mag, vector<long double> &Vector_B_mag) {

	//printf("Поиск траеторий в магните\n");
	//printf("\n");

	size_t vector_size = trajectory_cyl_z.size();

	for (size_t i = 0; i < vector_size; i = i + 1) {

		if (trajectory_cyl_z[i] >= L_mag_initial && trajectory_cyl_z[i] <= L_mag_final && (Vector_color_trajectory_cyl[i] == number_mag || Vector_color_trajectory_cyl[i] == 44.0)) { //-V550

			Vector_x_mag.push_back(trajectory_cyl_x[i]);
			Vector_y_mag.push_back(trajectory_cyl_y[i]);
			Vector_z_mag.push_back(trajectory_cyl_z[i]);
			Vector_r_mag.push_back(trajectory_cyl_r[i]);
			Vector_rr_mag.push_back(trajectory_cyl_rr[i]);
			Vector_force_mag.push_back(trajectory_cyl_force[i]);
			Vector_mu_mag.push_back(trajectory_cyl_mu[i]);
			Vector_B_mag.push_back(trajectory_cyl_B[i]);

			Vector_condition_color_mag.push_back(trajectory_cyl_condition_color[i]);

			Vector_phi_mag.push_back(trajectory_cyl_phi[i]);
			Vector_psi_mag.push_back(trajectory_cyl_psi[i]);
			Vector_theta_mag.push_back(trajectory_cyl_theta[i]);


			Vector_v_x_mag.push_back(trajectory_cyl_v_x[i]);
			Vector_v_y_mag.push_back(trajectory_cyl_v_y[i]);
			Vector_v_z_mag.push_back(trajectory_cyl_v_z[i]);
			Vector_v_r_mag.push_back(trajectory_cyl_v_r[i]);
			Vector_v_phi_mag.push_back(trajectory_cyl_v_phi[i]);
			Vector_v_perp_mag.push_back(trajectory_cyl_v_perp[i]);
			Vector_v_0_mag.push_back(trajectory_cyl_v_0[i]);




			if (out_tube == true) {
				Vector_color_mag.push_back(44.0);
			}
			else {
				Vector_color_mag.push_back(Vector_color_trajectory_cyl[i]);

			}


			Vector_out_mag.push_back(out_trajectory_cyl[i]);

		}


	}



}




void find_trajectory_cyl(long double number_cyl, const vector<long double> &trajectory_cyl_x, const vector<long double> &trajectory_cyl_y, const vector<long double> &trajectory_cyl_z, const vector<long double> &trajectory_cyl_r, const vector<long double> &trajectory_cyl_rr, const vector<long double>&Vector_color_trajectory_cyl, const vector<long double> &out_trajectory_cyl, vector<long double> &Vector_x_cyl, vector<long double> &Vector_y_cyl, vector<long double> &Vector_z_cyl, vector<long double> &Vector_r_cyl, vector<long double> &Vector_rr_cyl, vector<long double> &Vector_color_cyl, vector<long double> &Vector_out_cyl, long double L_cyl_initial, long double L_cyl_final, bool out_tube, const vector<long double> &trajectory_cyl_phi,
	const vector<long double> &trajectory_cyl_psi, const vector<long double> &trajectory_cyl_theta, vector<long double> &Vector_phi_cyl, vector<long double> &Vector_psi_cyl, vector<long double> &Vector_theta_cyl, const vector<long double> &trajectory_cyl_v_x, const vector<long double> &trajectory_cyl_v_y, const vector<long double> &trajectory_cyl_v_z, const vector<long double> &trajectory_cyl_v_r, const vector<long double> &trajectory_cyl_v_phi, const vector<long double> &trajectory_cyl_v_perp, const vector<long double> &trajectory_cyl_v_0, vector<long double> &Vector_v_x_cyl, vector<long double> &Vector_v_y_cyl,
	vector<long double> &Vector_v_z_cyl, vector<long double> &Vector_v_r_cyl, vector<long double> &Vector_v_phi_cyl, vector<long double> &Vector_v_perp_cyl, vector<long double> &Vector_v_0_cyl, const vector<long double> &trajectory_cyl_force, vector<long double> &Vector_force_cyl,
	const vector<long double> &trajectory_cyl_condition_color, vector<long double> &Vector_condition_color_cyl, const vector<long double> &trajectory_cyl_mu, const vector<long double> &trajectory_cyl_B, vector<long double> &Vector_mu_cyl, vector<long double> &Vector_B_cyl) {

	//printf("Поиск траеторий в цилиндре\n");
	//printf("\n");

	size_t vector_size = trajectory_cyl_z.size();

	for (size_t i = 0; i < vector_size; i = i + 1) {

		if (trajectory_cyl_z[i] >= L_cyl_initial && trajectory_cyl_z[i] <= L_cyl_final) {

			Vector_x_cyl.push_back(trajectory_cyl_x[i]);
			Vector_y_cyl.push_back(trajectory_cyl_y[i]);
			Vector_z_cyl.push_back(trajectory_cyl_z[i]);
			Vector_r_cyl.push_back(trajectory_cyl_r[i]);
			Vector_rr_cyl.push_back(trajectory_cyl_rr[i]);
			Vector_force_cyl.push_back(trajectory_cyl_force[i]);
			Vector_mu_cyl.push_back(trajectory_cyl_mu[i]);
			Vector_B_cyl.push_back(trajectory_cyl_B[i]);

			Vector_condition_color_cyl.push_back(trajectory_cyl_condition_color[i]);

			Vector_phi_cyl.push_back(trajectory_cyl_phi[i]);
			Vector_psi_cyl.push_back(trajectory_cyl_psi[i]);
			Vector_theta_cyl.push_back(trajectory_cyl_theta[i]);


			Vector_v_x_cyl.push_back(trajectory_cyl_v_x[i]);
			Vector_v_y_cyl.push_back(trajectory_cyl_v_y[i]);
			Vector_v_z_cyl.push_back(trajectory_cyl_v_z[i]);
			Vector_v_r_cyl.push_back(trajectory_cyl_v_r[i]);
			Vector_v_phi_cyl.push_back(trajectory_cyl_v_phi[i]);
			Vector_v_perp_cyl.push_back(trajectory_cyl_v_perp[i]);
			Vector_v_0_cyl.push_back(trajectory_cyl_v_0[i]);


			if (out_tube == true) {
				Vector_color_cyl.push_back(44.0);
			}
			else {
				Vector_color_cyl.push_back(Vector_color_trajectory_cyl[i]);

			}


			Vector_out_cyl.push_back(out_trajectory_cyl[i]);

		}


	}



}


int i_v_r = 0;
int j_v_r = 0;

void cyl(long double x_in, long double y_in, long double z_in, long double r_in, long double theta_in, long double phi_in, long double psi_in, long double &x_out, long double &y_out, long double &z_out, long double &r_out, long double &theta_out, long double &phi_out, long double &psi_out, size_t &N1, size_t &N2, size_t &N3, size_t &N4, size_t &N5, long double L_initial, long double L_final, long double R1_initial, long double R2_initial, long double R3_initial, long double R1_final,
	long double R2_final, long double R3_final, long double b_left, long double b_surface, long double b_right, long double &V_0, bool &out, std::size_t n, long double theta_diffusion_left, long double theta_diffusion_surface, long double theta_diffusion_right, long double z0_mag, long double  L_mag, long double r_mag_max_initial, long double r_mag_max_final, long double mu_core_particle,
	long double m_particle, long double B_mag_max_initial, bool on_off_mag, long double mu_electron_particle, long double I_particle, long double J_particle, long double m_F, long double m_J, long double B_critical, size_t N_mag_partitions, long double &z_zero, size_t &n_mag_in, size_t &n_mag_absorption, size_t &n_mag_out, bool mag_runge, long double B_mag_max_final, long double m_mag, vector<long double> &Vector_r_mag, vector<long double> &Vector_z_mag, vector<long double> &Vector_x_mag, vector<long double> &Vector_y_mag, long double min_r_out_mag, long double min_r_in_mag, int particle_mode, long double iron_mag, vector<long double> &trajectory_cyl_x, vector<long double> &trajectory_cyl_y, vector<long double> &trajectory_cyl_z, vector<long double> &trajectory_cyl_r,
	long double v_r_in, long double &v_r_out, long double v_x_in, long double &v_x_out, long double v_y_in, long double &v_y_out, bool &out_mag, long double v_phi_in, long double &v_phi_out, vector<long double>&Vector_color_mag, vector<long double>&Vector_color_trajectory_cyl, long double cyl_number, vector<long double> &Vector_rr_mag, vector<long double> &trajectory_cyl_rr, size_t N_CYL_partitions, size_t &i_Collision, vector<long double> &out_trajectory_cyl, vector<long double> &Vector_out_mag, long double b_mag_surface, long double b_mag_left, long double b_mag_right, long double L_cyl_1,
	long double L_cyl_2, long double L_cyl_3, long double L_cyl_4, long double L_cyl_5, long double L_cyl_6, long double L_cyl_7, vector<long double> &Vector_phi_mag, vector<long double> &Vector_psi_mag, vector<long double> &Vector_theta_mag, vector<long double> &trajectory_cyl_phi, vector<long double> &trajectory_cyl_psi, vector<long double> &trajectory_cyl_theta,
	vector<long double> &Vector_v_x_mag, vector<long double> &Vector_v_y_mag, vector<long double> &Vector_v_z_mag, vector<long double> &Vector_v_r_mag, vector<long double> &Vector_v_phi_mag, vector<long double> &Vector_v_perp_mag, vector<long double> &Vector_v_0_mag, vector<long double> &trajectory_cyl_v_x, vector<long double> &trajectory_cyl_v_y, vector<long double> &trajectory_cyl_v_z, vector<long double> &trajectory_cyl_v_r, vector<long double> &trajectory_cyl_v_phi, vector<long double> &trajectory_cyl_v_perp, vector<long double> &trajectory_cyl_v_0, long double n_cos_intensity, vector<long double> &Vector_force_mag, vector<long double> &trajectory_cyl_force,
	size_t &N_negative_cyl, size_t &N_zero_cyl, size_t &N_positive_cyl, size_t &N_negative_mag, size_t &N_zero_mag, size_t &N_positive_mag, long double mu_particle, long double mu_particle_force, vector<long double> &Vector_condition_color_mag,
	vector<long double> &trajectory_cyl_condition_color, bool flaq_on_off_B_mu, size_t index_condition, vector<long double> &Vector_mu_mag, vector<long double> &Vector_B_mag, vector<long double> &trajectory_cyl_mu, vector<long double> &trajectory_cyl_B, vector<long double> &Vector_r_magnetic_field_table, vector<long double> &Vector_phi_magnetic_field_table, vector<long double> &Vector_B_magnetic_field_table, vector<long double> &Vector_delta_B_magnetic_field_table, bool on_off_table_magnetic_field, vector <size_t> &Vector_index_r_magnetic_field_table, size_t &index_phi_magnetic_field_table, long double m_mag_table, long double r_min_mag_table, long double r_max_mag_table, long double L_mag_B_off_after) {
	//#pragma omp ordered
	//{
	//	trajectory_cyl_x.push_back(x_in);
	//	trajectory_cyl_y.push_back(y_in);
	//	trajectory_cyl_z.push_back(z_in);
	//	trajectory_cyl_r.push_back(r_in);

	//	if (y_in < 0) {
	//		trajectory_cyl_rr.push_back(-r_in);
	//	}
	//	else if (y_in >= 0) {
	//		trajectory_cyl_rr.push_back(r_in);
	//	}

	//	Vector_color_trajectory_cyl.push_back(0.0);

	long double L_cyl = L_final - L_initial;

	//printf( "%s\n", (on_off_mag ? "Включено" : "Отключено"));


	vector<long double> Vector_temp_r_mag(0);
	vector<long double> Vector_temp_rr_mag(0);
	vector<long double> Vector_temp_z_mag(0);
	vector<long double> Vector_temp_x_mag(0);

	vector<long double> Vector_temp_mu_mag(0);
	vector<long double> Vector_temp_B_mag(0);

	vector<long double> Vector_temp_condition_color_mag(0);

	vector<long double> Vector_temp_y_mag(0);
	vector<long double> Vector_temp_force_mag(0);
	vector<long double> Vector_temp_color_mag(0);
	vector<long double> Vector_temp_out_mag(0);

	vector<long double> Vector_temp_phi_mag(0);
	vector<long double> Vector_temp_psi_mag(0);
	vector<long double> Vector_temp_theta_mag(0);

	vector<long double> Vector_temp_v_x_mag(0);
	vector<long double> Vector_temp_v_y_mag(0);
	vector<long double> Vector_temp_v_z_mag(0);
	vector<long double> Vector_temp_v_r_mag(0);
	vector<long double> Vector_temp_v_phi_mag(0);
	vector<long double> Vector_temp_v_perp_mag(0);
	vector<long double> Vector_temp_v_0_mag(0);



	long double x0 = x_in, y0 = y_in, z0 = z_in, r0 = r_in, theta0 = theta_in, phi0 = phi_in, psi0 = psi_in, v_phi0 = v_phi_in; // значения на предыдущей итерации
	long double x = x_in, y = y_in, z = z_in, r = r_in, theta = theta_in, phi = phi_in, psi = psi_in, v_phi = v_phi_in;// значения на текущей итерации



	long double delta_x = 0.0;
	long double delta_y = 0.0;
	long double delta_z = 0.0;

	//	long double x , y , z, r, theta , phi , psi ;// значения на текущей итерации

	//trajectory_cyl_x.push_back(x_in);
	//trajectory_cyl_y.push_back(y_in);
	//trajectory_cyl_z.push_back(z_in);
	//trajectory_cyl_r.push_back(r_in);


	size_t n1 = N1; // число частиц, вылетевших с левого торца цилинлра
	size_t n2 = N2; // число частиц, вылетевших с правого торца цилинлра
	size_t n3 = N3; // число частиц, захваченных левым торцом цилинлра
	size_t n4 = N4; // число частиц, захваченных образующей цилинлра
	size_t n5 = N5; // число частиц, захваченных правым торцом цилинлра

				 //x_out = 0.0;
				 //y_out = 0.0;
				 //z_out = 0.0;
				 //r_out = 0.0;

				 //out = true; // Булева переменная для индикации вылета частицы из цилиндра

	out = false; // Булева переменная для индикации вылета частицы из цилиндра
	out_mag = false;

	//bool out_mag = false;


	//	if (fabs(z0 - L_final) <= epsilon) {
	//	theta0 = M_PI_2 - theta0;
	//}

	long double t1_left = fabs(time1("left", r0, theta0, phi0, psi0, R1_initial, V_0)); // время контакта до поверхности образующей
	long double t1_right = fabs(time1("right", r0, theta0, phi0, psi0, R1_initial, V_0)); // время контакта до поверхности образующей
	long double t2 = 0.0;
	long double t3 = 0.0;



	// время контакта до торца
	if (on_off_mag == true) {

		//cout << "!!!" << endl;

		t2 = fabs(time1_(z0, L_initial + z0_mag, theta0, V_0));
		t3 = fabs(time1_(z0, L_initial + z0_mag + L_mag, theta0, V_0));

	}

	if (on_off_mag == false) {

		t2 = fabs(time1_(z0, L_final, theta0, V_0));
		t3 = fabs(time1_(z0, L_initial, theta0, V_0));


	}









	if (fabs(z0 - L_initial) <= epsilon) {
		long double t = min(t1_left, t2);
		func1("left", x0, y0, z0, r0, theta0, phi0, psi0, x, y, z, r, theta, phi, psi, t, V_0, v_phi0, v_phi, N_CYL_partitions, trajectory_cyl_x, trajectory_cyl_y, trajectory_cyl_z, trajectory_cyl_r, Vector_color_trajectory_cyl, trajectory_cyl_rr, out_trajectory_cyl, trajectory_cyl_phi, trajectory_cyl_psi, trajectory_cyl_theta, trajectory_cyl_v_x, trajectory_cyl_v_y, trajectory_cyl_v_z, trajectory_cyl_v_r, trajectory_cyl_v_phi, trajectory_cyl_v_perp, trajectory_cyl_v_0, trajectory_cyl_force, trajectory_cyl_condition_color, mu_particle, mu_particle_force, flaq_on_off_B_mu, index_condition, particle_mode, trajectory_cyl_mu, trajectory_cyl_B);

	}

	if (fabs(z0 - L_final) <= epsilon) {
		long double t1 = min(t1_right, t3);
		long double t2 = min(t1_left, t3);

		//long double t = max(t1, t2);

		//	long double x_temp = 0.0;
		//	long double y_temp = 0.0;
		//	long double z_temp = 0.0;
		//	long double r_temp = 0.0;
		//	long double theta_temp = 0.0;
		//	long double phi_temp = 0.0;
		//	long double psi_temp = 0.0;

		//	func1("left_right", x0, y0, z0, r0, theta0, phi0, psi0, x_temp, y_temp, z_temp, r_temp, theta_temp, phi_temp, psi_temp, t1, V_0, v_phi0, v_phi, N_CYL_partitions, trajectory_cyl_x, trajectory_cyl_y, trajectory_cyl_z, trajectory_cyl_r, Vector_color_trajectory_cyl, trajectory_cyl_rr, out_trajectory_cyl);

		//	long double x_temp_1 = x0 + t1*sin(theta0)*cos(psi0);
		//	long double y_temp_1 = y0 + t1*sin(theta0)*sin(psi0);

		//	long double r_temp_1 = pow(pow(x_temp_1, 2.0) + pow(y_temp_1, 2.0), 1.0 / 2.0);

		//	if (r_temp_1 > R1_initial) {

		//	cout << "!!!" << endl;

		//	func1("left_right", x0, y0, z0, r0, theta0, phi0, psi0, x, y, z, r, theta, phi, psi, t1, V_0, v_phi0, v_phi, N_CYL_partitions, trajectory_cyl_x, trajectory_cyl_y, trajectory_cyl_z, trajectory_cyl_r, Vector_color_trajectory_cyl, trajectory_cyl_rr, out_trajectory_cyl);


		//func1("left_right", x0, y0, z0, r0, theta0, phi0, psi0, x, y, z, r, theta, phi, psi, t2, V_0, v_phi0, v_phi, N_CYL_partitions, trajectory_cyl_x, trajectory_cyl_y, trajectory_cyl_z, trajectory_cyl_r, Vector_color_trajectory_cyl, trajectory_cyl_rr, out_trajectory_cyl);

		//	}
		//	else {


		//	func1("left_right", x0, y0, z0, r0, theta0, phi0, psi0, x, y, z, r, theta, phi, psi, t1, V_0, v_phi0, v_phi, N_CYL_partitions, trajectory_cyl_x, trajectory_cyl_y, trajectory_cyl_z, trajectory_cyl_r, Vector_color_trajectory_cyl, trajectory_cyl_rr, out_trajectory_cyl);



		//	}
		//	cout << z0 << "!!!" << z << endl;

		func1("left_right", x0, y0, z0, r0, theta0, phi0, psi0, x, y, z, r, theta, phi, psi, t2, V_0, v_phi0, v_phi, N_CYL_partitions, trajectory_cyl_x, trajectory_cyl_y, trajectory_cyl_z, trajectory_cyl_r, Vector_color_trajectory_cyl, trajectory_cyl_rr, out_trajectory_cyl, trajectory_cyl_phi, trajectory_cyl_psi, trajectory_cyl_theta, trajectory_cyl_v_x, trajectory_cyl_v_y, trajectory_cyl_v_z, trajectory_cyl_v_r, trajectory_cyl_v_phi, trajectory_cyl_v_perp, trajectory_cyl_v_0, trajectory_cyl_force, trajectory_cyl_condition_color, mu_particle, mu_particle_force, flaq_on_off_B_mu, index_condition, particle_mode, trajectory_cyl_mu, trajectory_cyl_B);



	}



	//cout << r << endl;

	//if ((z > L_initial) && (z < L_final)) {


	//	theta0 = M_PI_2 - theta_in;
	//	psi0 = 0.0;
	//	phi0 = phi_in;

	//	}



	delta_x = x - x0;
	delta_y = y - y0;
	delta_z = z - z0;

	/*

	if (x == 0 && y > 0) {

	phi = M_PI_2;
	}


	if (x == 0 && y < 0) {

	phi = 3.0*M_PI_2;
	}


	if (y == 0 && x > 0) {

	phi = 0.0;
	}

	if (y == 0 && x < 0) {

	phi = M_PI;
	}

	if (y == 0 && x == 0) {

	phi = 0.0;
	}

	if (x > 0 && y > 0) {

	phi = atan(fabs(y / x));
	}



	if (x < 0 && y < 0) {

	phi = M_PI + atan(fabs(y / x));
	}

	if (x > 0 && y < 0) {

	phi = 2.0*M_PI - atan(fabs(y / x));
	}


	if (x < 0 && y > 0) {

	phi = M_PI - atan(fabs(y / x));
	}


	*/

	//	if (z== L_initial){
	//	cout << z << endl;

	//	}

	//cout << x << "  " << y << "  " << z << "    " << r << endl;


	//long double v_r = ((r - r0) / fabs((z - z0)))*V_0*cos(theta0);

	long double v_r = (2.0*r0*V_0*cos(phi0 - psi0)*sin(theta0) + 2.0*pow(V_0*sin(theta0), 2.0)*fabs(z - z0) / (V_0*cos(theta0))) / (2.0*r);

	long double v_x = ((x - x0) / fabs((z - z0)))*V_0*cos(theta0);
	long double v_y = ((y - y0) / fabs((z - z0)))*V_0*cos(theta0);
	long double v_z = ((z - z0) / fabs((z - z0)))*V_0*cos(theta0);

	//	x0 = x;
	//	y0 = y;
	//	z0 = z;
	//	r0 = r;
	//	theta0 = theta;
	//	psi0 = psi;
	//	phi0 = phi;


	//#pragma omp parallel
	//	{
	//#pragma omp for // распараллеливание большого цикла на многопоточность


	/*

	long double mu_particle = 0.0;
	long double mu_particle_force = 0.0;

	long double B_temp = 0.001;
	long double mu_temp_temp = 0.0;
	long double E_temp_temp = 0.0;

	const long double mu_bor = 5.788381806638*pow(10.0, 13.0)*pow(2.99792458, 2.0); // магнетон Бора электронный в единицах эВ/Гс*(скорость света [мм/c])^2

																					//	const long double mu_bor = 3.152451260522*pow(10.0, 10.0)*pow(2.99792458, 2.0); // магнетон Бора ядерный в единицах эВ/Гс*(скорость света [мм/c])^2


	const long double mu_bor_force = 9.2740096820*pow(10.0, 0.0);

	if (flaq_on_off_B_mu == false) {
		mu_particle = mu_temp;
		mu_particle_force = mu_force_temp;
	}
	if (flaq_on_off_B_mu == true) {


		//	cout << index_condition << endl;

		if (particle_mode == 1) {
			mu_particle = mu_H(index_condition, B_temp, mu_temp_temp, E_temp_temp)*mu_bor;
			mu_particle_force = mu_H(index_condition, B_temp, mu_temp_temp, E_temp_temp)*mu_bor_force;
		}

		if (particle_mode == 2) {

			mu_particle = mu_D(index_condition, B_temp, mu_temp_temp, E_temp_temp)*mu_bor;
			mu_particle_force = mu_D(index_condition, B_temp, mu_temp_temp, E_temp_temp)*mu_bor_force;
		}

		if (particle_mode == 3) {
			mu_particle = mu_H_2(index_condition, B_temp, mu_temp_temp, E_temp_temp)*mu_bor;
			mu_particle_force = mu_H_2(index_condition, B_temp, mu_temp_temp, E_temp_temp)*mu_bor_force;

		}

		if (particle_mode == 4) { //-V112

			mu_particle = mu_D_2(index_condition, B_temp, mu_temp_temp, E_temp_temp)*mu_bor;
			mu_particle_force = mu_D_2(index_condition, B_temp, mu_temp_temp, E_temp_temp)*mu_bor_force;

		}

	}


   */




	size_t i = 1;

	for (i; i <= n; i = i + 1) { // ограничение на число саударений, иначе, прочесс может идти бесконечность

								 //	cout << x << "  " << y << "  " << z << "    " << r << "    " << i<<  endl;

								 //			bool out_mag = false;

								 //step1:




		if (on_off_mag == false) {


			// вылет из правого конца цилиндра
			if ((fabs(z - L_final) <= epsilon) && (r <= R2_final) && (r >= R3_final) && (r <= R1_initial)) {

				//	break;

				//	cout << "!!!" << endl;

				x_out = x;
				y_out = y;
				z_out = z;
				r_out = r;
				//	theta_out = theta;
				//	phi_out = phi;
				//	psi_out = psi;


				v_phi_out = v_phi;

				v_x_out = v_x;
				v_y_out = v_y;

				/*
				if (x >= 0 && y >= 0) {

				phi = atan(fabs(y / x));
				}



				if (x < 0 && y < 0) {

				phi = M_PI + atan(fabs(y / x));
				}

				if (x > 0 && y < 0) {

				phi = 2.0*M_PI - atan(fabs(y / x));
				}


				if (x < 0 && y > 0) {

				phi = M_PI - atan(fabs(y / x));
				}

				*/
				out = true;
				n2 = n2 + 1;


				//	if (out_mag == true) {

				//			theta_out = theta;

				//			phi_out = phi;
				//			psi_out = psi;

				//			break;
				//	}


				//cout << z0 << endl;
				if ((fabs(z0 - L_initial) <= epsilon)) {
					theta_out = theta;
					//theta_out = theta_in;
					phi_out = phi;
					psi_out = psi;
				}
				else {
					theta_out = M_PI_2 - theta;
					if (delta_x >= 0 && delta_y >= 0) {

						//	psi_out = fabs(asin((delta_x)*v_z / (V_0*h_z*sin(theta))));

						psi_out = fabs(atan(delta_y / delta_x));
					}



					if (delta_x < 0 && delta_y < 0) {

						//	psi_out = M_PI + fabs(asin((delta_x)*v_z / (V_0*h_z*sin(theta))));

						psi_out = 1.0*M_PI + fabs(atan(delta_y / delta_x));

					}

					if (delta_x > 0 && delta_y < 0) {

						//	psi_out = 2.0*M_PI - fabs(asin((delta_x)*v_z / (V_0*h_z*sin(theta))));

						psi_out = 2.0*M_PI - fabs(atan(delta_y / delta_x));

					}


					if (delta_x < 0 && delta_y > 0) {

						//	psi_out = M_PI - fabs(asin((delta_x)*v_z / (V_0*h_z*sin(theta))));

						psi_out = 1.0*M_PI - fabs(atan(delta_y / delta_x));

					}

					phi_out = phi;

				}

				//	theta_out = theta_in;
				//	phi_out = phi;
				//	psi_out = psi_in;

				//cout << 180*phi_out/M_PI << endl;

				//cout << 180*atan(y/x)/M_PI << endl;

				//	cout << x_out << "  " << y_out << "  " << z_out << "    " << r_out << endl;
				//return;



				v_r = (2.0*r0*V_0*cos(phi0 - psi0)*sin(theta0) + 2.0*pow(V_0*sin(theta0), 2.0)*fabs(z - z0) / (V_0*cos(theta0))) / (2.0*r);
				v_r_out = v_r;

				delta_z = z - z0;
				delta_x = x - x0;
				delta_y = y - y0;

				v_x = ((x - x0) / fabs((z - z0)))*V_0*sin(theta0)*cos(psi0);
				v_y = ((y - y0) / fabs((z - z0)))*V_0*sin(theta0)*cos(psi0);
				v_z = ((z - z0) / fabs((z - z0)))*V_0*sin(theta0)*cos(psi0);

				//	v_r = (2.0*r0*V_0*cos(phi0 - psi0)*sin(theta0) + 2.0*pow(V_0*sin(theta0), 2.0)*fabs(z - z0) / (V_0*cos(theta0))) / (2.0*r);


				break;


			}

			//		else {

			//			out = false;
			//			break;
			//		}

			// удар о правый торец цилиндра
			if ((fabs(z - L_final) <= epsilon) && ((r > R2_final) || (r < R3_final)) && (r <= R1_initial)) {

				//break;

				//	srand((unsigned int)time(NULL) + rand()); // привязка генератора случайных чисел к системному времени
				if (b_right == 1.0) { //-V550
					out = false;
					n5 = n5 + 1;
					break;
				}

				long double mu = random(0.0, 1.0); // случайное число для учета захвата частицы поверхностью цилиндра
												   //cout << mu;
				if (mu <= b_right) {
					//return;
					out = false;
					n5 = n5 + 1;
					break;


				}

				else {

					if (fabs(z0 - L_final) <= epsilon) {
						theta0 = theta;
						phi0 = phi;
						psi0 = psi;
					}
					else {
						theta0 = M_PI_2 - theta;
						phi0 = atan2(-y0, x0);
						psi0 = phi;

					}

					x0 = x;
					y0 = y;
					z0 = z;
					r0 = r;
					v_phi0 = v_phi;




					if (theta0 <= theta_diffusion_right) {
						//	srand((unsigned int)time(NULL) + rand()); // привязка генератора случайных чисел к системному времени
						//theta_0 = acos(pow(1.0 - pow(random(0.0, 1.0), 2.0), 1.0 / 2.0)); // от -pi/2 до pi распределена по закону cos(), получена методом обратной функции
						//theta_0 = asin(pow(random(0.0, 1.0), 1.0 / 2.0));
						//theta0 = asin(pow(random(0.0, 1.0), 1.0 / 2.0));// от 0 до pi/2 распределена по закону cos(), получена методом обратной функции, максимум вероятности при theta=0

						theta0 = asin(pow(1.0 - pow(1.0 - random(0.0, 1.0), 2.0 / (n_cos_intensity + 1.0)), 1.0 / 2.0));




						//srand((unsigned int)time(NULL) + rand()); // привязка генератора случайных чисел к системному времени
						phi0 = phi; //от 0 до 2*pi равномерно распределена

									//srand((unsigned int)time(NULL) + rand()); // привязка генератора случайных чисел к системному времени
						psi0 = 2.0*M_PI*random(0.0, 1.0); //от 0 до 2*pi равномерно распределена

					}

					else {
						theta0 = theta;
						phi0 = phi;
						psi0 = psi - M_PI;

					}



					long double t11 = fabs(time1("right", r0, theta0, phi0, psi0, R1_initial, V_0));
					long double t22 = fabs(time1_(z0, L_initial, theta0, V_0));



					long double t = min(t11, t22);
					//cout << t11 << "  " << t22<< "  " <<t<<  endl;
					func1("right", x0, y0, z0, r0, theta0, phi0, psi0, x, y, z, r, theta, phi, psi, t, V_0, v_phi0, v_phi, N_CYL_partitions, trajectory_cyl_x, trajectory_cyl_y, trajectory_cyl_z, trajectory_cyl_r, Vector_color_trajectory_cyl, trajectory_cyl_rr, out_trajectory_cyl,
						trajectory_cyl_phi, trajectory_cyl_psi, trajectory_cyl_theta, trajectory_cyl_v_x, trajectory_cyl_v_y, trajectory_cyl_v_z, trajectory_cyl_v_r, trajectory_cyl_v_phi, trajectory_cyl_v_perp, trajectory_cyl_v_0, trajectory_cyl_force, trajectory_cyl_condition_color, mu_particle, mu_particle_force, flaq_on_off_B_mu, index_condition, particle_mode, trajectory_cyl_mu, trajectory_cyl_B);
					//cout << x << "  " << y << "  " << z << "    " << r << endl;
					//break;
					//continue;

					delta_x = x - x0;
					delta_y = y - y0;
					delta_z = z - z0;

					v_r = (2.0*r0*V_0*cos(phi0 - psi0)*sin(theta0) + 2.0*pow(V_0*sin(theta0), 2.0)*fabs(z - z0) / (V_0*cos(theta0))) / (2.0*r);

				}


				out = false;

				continue;

			}


			//step2:
			// вылет из левого конца цилиндра
			if ((fabs(z - L_initial) <= epsilon) && (r <= R2_initial) && (r >= R3_initial) && (r <= R1_initial)) {

				//	break;

				if (fabs(z0 - L_final) <= epsilon) {
					theta_out = theta;
					phi_out = phi;
					psi_out = psi;
				}
				else {
					theta_out = fabs(M_PI_2 - theta);

					//	theta_out = theta;

					if (delta_x >= 0 && delta_y >= 0) {

						//	psi_out = fabs(asin((delta_x)*v_z / (V_0*h_z*sin(theta))));

						psi_out = fabs(atan(delta_y / delta_x));
					}



					if (delta_x < 0 && delta_y < 0) {

						//	psi_out = M_PI + fabs(asin((delta_x)*v_z / (V_0*h_z*sin(theta))));

						psi_out = (1.0*M_PI + fabs(atan(delta_y / delta_x)));

					}

					if (delta_x > 0 && delta_y < 0) {

						//	psi_out = 2.0*M_PI - fabs(asin((delta_x)*v_z / (V_0*h_z*sin(theta))));

						psi_out = (2.0*M_PI - fabs(atan(delta_y / delta_x)));

					}


					if (delta_x < 0 && delta_y > 0) {

						//	psi_out = M_PI - fabs(asin((delta_x)*v_z / (V_0*h_z*sin(theta))));

						psi_out = (1.0*M_PI - fabs(atan(delta_y / delta_x)));

					}

					//psi_out = psi_out + M_PI;

					//psi_out = -psi_out;

					phi_out = phi;

					//	cout <<fabs(cos(phi_out)) << " " << fabs(x/pow(x*x+y*y,1.0/2.0)) << endl;

					//psi_out = (atan(delta_y / delta_x));

					//	psi_out = psi+M_PI;

				}


				v_r = (2.0*r0*V_0*cos(phi0 - psi0)*sin(theta0) + 2.0*pow(V_0*sin(theta0), 2.0)*fabs(z - z0) / (V_0*cos(theta0))) / (2.0*r);


				v_phi_out = v_phi;
				v_r_out = v_r;
				x_out = x;
				y_out = y;
				z_out = z;
				r_out = r;
				n1 = n1 + 1;

				out = true;

				delta_z = z - z0;
				delta_x = x - x0;
				delta_y = y - y0;

				v_x = ((x - x0) / fabs((z - z0)))*V_0*sin(theta0)*cos(psi0);
				v_y = ((y - y0) / fabs((z - z0)))*V_0*sin(theta0)*cos(psi0);
				v_z = ((z - z0) / fabs((z - z0)))*V_0*sin(theta0)*cos(psi0);

				//	v_r = (2.0*r0*V_0*cos(phi0 - psi0)*sin(theta0) + 2.0*pow(V_0*sin(theta0), 2.0)*fabs(z - z0) / (V_0*cos(theta0))) / (2.0*r);



				//	cout << "8888" << endl;
				//cout << x_out << "  " << y_out << "  " << z_out << "    " << r_out << endl;

				//return;
				break;
			}

			// удар о левый торец цилиндра
			if ((fabs(z - L_initial) <= epsilon) && ((r > R2_initial) || (r < R3_initial)) && (r <= R1_initial)) {

				//break;
				//	srand((unsigned int)time(NULL) + rand()); // привязка генератора случайных чисел к системному времени
				if (b_left == 1.0) { //-V550
					out = false;
					n3 = n3 + 1;
					//	return;
					break;

				}

				long double mu = random(0.0, 1.0); // случайное число для учета захвата частицы поверхностью цилиндра

				if (mu <= b_left) {

					out = false;
					n3 = n3 + 1;
					//	return;
					break;

				}

				else {

					if (fabs(z0 - L_initial) <= epsilon) {
						theta0 = theta;
						phi0 = phi;
						psi0 = psi;
					}
					else {
						theta0 = M_PI_2 - theta;
						phi0 = atan2(-y0, x0);
						psi0 = phi;

					}

					x0 = x;
					y0 = y;
					z0 = z;
					r0 = r;
					v_phi0 = v_phi;

					if (theta0 <= theta_diffusion_left) {
						//	srand((unsigned int)time(NULL) + rand()); // привязка генератора случайных чисел к системному времени
						//theta_0 = acos(pow(1.0 - pow(random(0.0, 1.0), 2.0), 1.0 / 2.0)); // от -pi/2 до pi распределена по закону cos(), получена методом обратной функции
						//theta_0 = asin(pow(random(0.0, 1.0), 1.0 / 2.0));
					//	theta0 = asin(pow(random(0.0, 1.0), 1.0 / 2.0));// от 0 до pi/2 распределена по закону cos(), получена методом обратной функции, максимум вероятности при theta=0

						theta0 = asin(pow(1.0 - pow(1.0 - random(0.0, 1.0), 2.0 / (n_cos_intensity + 1.0)), 1.0 / 2.0));

						//	srand((unsigned int)time(NULL) + rand()); // привязка генератора случайных чисел к системному времени
						phi0 = phi; //от 0 до 2*pi равномерно распределена

									//	srand((unsigned int)time(NULL) + rand()); // привязка генератора случайных чисел к системному времени
						psi0 = 2.0*M_PI*random(0.0, 1.0); //от 0 до 2*pi равномерно распределена

					}

					else {
						theta0 = theta;
						phi0 = phi;
						psi0 = psi - M_PI;

					}



					long double t111 = fabs(time1("left", r0, theta0, phi0, psi0, R1_initial, V_0));
					long double t222 = fabs(time1_(z0, L_final, theta0, V_0));



					long double t = min(t111, t222);
					//cout << t111 << "  " << t222<< "  " <<t<<  endl;
					func1("left", x0, y0, z0, r0, theta0, phi0, psi0, x, y, z, r, theta, phi, psi, t, V_0, v_phi0, v_phi, N_CYL_partitions, trajectory_cyl_x, trajectory_cyl_y, trajectory_cyl_z, trajectory_cyl_r, Vector_color_trajectory_cyl, trajectory_cyl_rr, out_trajectory_cyl, trajectory_cyl_phi, trajectory_cyl_psi, trajectory_cyl_theta, trajectory_cyl_v_x, trajectory_cyl_v_y, trajectory_cyl_v_z,
						trajectory_cyl_v_r, trajectory_cyl_v_phi, trajectory_cyl_v_perp, trajectory_cyl_v_0, trajectory_cyl_force, trajectory_cyl_condition_color, mu_particle, mu_particle_force, flaq_on_off_B_mu, index_condition, particle_mode, trajectory_cyl_mu, trajectory_cyl_B);
					//cout << x << "  " << y << "  " << z << "    " << r << endl;
					//break;
					//continue;

					delta_x = x - x0;
					delta_y = y - y0;
					delta_z = z - z0;

					v_r = (2.0*r0*V_0*cos(phi0 - psi0)*sin(theta0) + 2.0*pow(V_0*sin(theta0), 2.0)*fabs(z - z0) / (V_0*cos(theta0))) / (2.0*r);

				}


				out = false;
				continue;

			}



			// частица внутри цилиндра
			if ((z > L_initial) && (z < L_final)) {


				//break;
				//srand((unsigned int)time(NULL) + rand()); // привязка генератора случайных чисел к системному времени


				//cout << x0 << "  " << y0 << "  " << z0 << "    " << r0 << endl;

				//cout << x << "  " << y << "  " << z << "    " << r << endl;

				if (b_surface == 1.0) { //-V550
					out = false;
					n4 = n4 + 1;
					//return;

					//cout << 180 * phi / M_PI << endl;

					break;

				}


				long double mu = random(0.0, 1.0); // случайное число для учета захвата частицы поверхностью цилиндра

				if (mu <= b_surface) {

					out = false;
					n4 = n4 + 1;
					//return;

					//cout << 180 * phi / M_PI << endl;

					break;

				}


				else {

					if ((fabs(z - L_initial) <= epsilon) || (fabs(z - L_final) <= epsilon)) {
						theta0 = fabs(M_PI_2 - theta);
						psi = atan(v_y / v_z) - M_PI;

						phi0 = phi;
						//psi0 = psi;
					}
					else {

						theta0 = theta;
						phi0 = phi;
						psi0 = psi;

					}


					x0 = x;
					y0 = y;
					z0 = z;
					r0 = r;

					v_phi0 = v_phi;

					//	theta0 = theta;
					//	psi0 = psi;
					//	phi0 = phi;


					//	cout << x0 << "  " << y0 << "  " << z0 << "    " << r0 << endl;

					if (theta0 <= theta_diffusion_surface) {
						//srand((unsigned int)time(NULL) + rand()); // привязка генератора случайных чисел к системному времени
						//theta_0 = acos(pow(1.0 - pow(random(0.0, 1.0), 2.0), 1.0 / 2.0)); // от -pi/2 до pi распределена по закону cos(), получена методом обратной функции
						//theta_0 = asin(pow(random(0.0, 1.0), 1.0 / 2.0));
						//theta0 = asin(pow(random(0.0, 1.0), 1.0 / 2.0));// от 0 до pi/2 распределена по закону cos(), получена методом обратной функции, максимум вероятности при theta=0

						theta0 = asin(pow(1.0 - pow(1.0 - random(0.0, 1.0), 2.0 / (n_cos_intensity + 1.0)), 1.0 / 2.0));												//srand((unsigned int)time(NULL) + rand()); // привязка генератора случайных чисел к системному времени
																		//phi0 = 2.0*M_PI*random(0.0, 1.0); //от 0 до 2*pi равномерно распределена

						phi0 = phi;


						//srand((unsigned int)time(NULL) + rand()); // привязка генератора случайных чисел к системному времени
						psi0 = 2.0*M_PI*random(0.0, 1.0); //от 0 до 2*pi равномерно распределена

					}

					else {
						theta0 = theta;
						phi0 = phi;
						psi0 = psi0 + M_PI;

					}


					//	theta0 = asin(pow(random(0.0, 1.0), 1.0 / 2.0));// от 0 до pi/2 распределена по закону cos(), получена методом обратной функции, максимум вероятности при theta=0

					//srand((unsigned int)time(NULL) + rand()); // привязка генератора случайных чисел к системному времени
					//phi = 2.0*M_PI*random(0.0, 1.0); //от 0 до 2*pi равномерно распределена

					//phi = phi0;

					//			if (x == 0 && y > 0) {

					//				phi = M_PI_2;
					//			}


					//			if (x == 0 && y < 0) {

					//				phi = 3.0*M_PI_2;
					//			}


					//		if (y == 0 && x > 0) {

					//			phi = 0.0;
					//		}

					//			if (y == 0 && x < 0) {

					//				phi = M_PI;
					//			}

					//			if (y == 0 && x == 0) {

					//				phi = 0.0;
					//			}

					//		if (x > 0 && y > 0) {

					//			phi = atan(fabs(y / x));
					//		}



					//		if (x < 0 && y < 0) {

					//			phi = M_PI + atan(fabs(y / x));
					//		}

					//		if (x > 0 && y < 0) {

					//			phi = 2.0*M_PI - atan(fabs(y / x));
					//		}


					//	if (x < 0 && y > 0) {

					//		phi = M_PI - atan(fabs(y / x));
					//	}




					//srand((unsigned int)time(NULL) + rand()); // привязка генератора случайных чисел к системному времени


					//	psi0 = 2.0*M_PI*random(0.0, 1.0); //от 0 до 2*pi равномерно распределена




					long double t14 = time2(theta0, psi0, R1_initial, V_0);
					long double t24 = time2_(z0, L_initial, theta0, psi0, V_0);
					long double t34 = time2_(z0, L_final, theta0, psi0, V_0);





					//	long double t = min(t1, t2, t3);

					//	func2("right", x0, y0, z0, r0, theta, psi, x, y, z, r, t, V_0);

					//	cout << x << "  " << y << "  " << z << "    " << r << endl;



					if (cos(psi0) < 0) {

						//	break;


						long double t_min = min(t14, t24);
						//cout << t1 << "  " << t2<< "  " <<t<<  endl;


						//	cout << t14 << "  " << t24 << "  " << t34 << "  " << min(t14, t24, t34) << "  " <<t_min<< endl;

						//t_min = t14;

						func2("right", x0, y0, z0, r0, theta0, phi0, psi0, x, y, z, r, theta, phi, psi, t_min, V_0, v_phi0, v_phi, N_CYL_partitions, trajectory_cyl_x, trajectory_cyl_y, trajectory_cyl_z, trajectory_cyl_r, Vector_color_trajectory_cyl, trajectory_cyl_rr, out_trajectory_cyl, trajectory_cyl_phi, trajectory_cyl_psi,
							trajectory_cyl_theta, trajectory_cyl_v_x, trajectory_cyl_v_y, trajectory_cyl_v_z, trajectory_cyl_v_r, trajectory_cyl_v_phi, trajectory_cyl_v_perp, trajectory_cyl_v_0, trajectory_cyl_force, trajectory_cyl_condition_color, mu_particle, mu_particle_force, flaq_on_off_B_mu, index_condition, particle_mode, trajectory_cyl_mu, trajectory_cyl_B);



						/*




						if (z <= L_initial + 100.0*DBL_EPSILON) {
						z = L_initial; // из-за погрешоности вычеслений координата может быть немного меньше L_initial (10^-18)
						}

						if ((z > L_initial + 100.0*DBL_EPSILON) && (z < L_final - 100.0*DBL_EPSILON)) {

						r = R1_initial;
						}

						*/


						//	cout << x << "  " << y << "  " << z << "    " << r << endl;

						//continue;
					}

					else if (cos(psi0) >= 0) {


						//break;



						long double t_min = min(t14, t34);
						//cout << t1 << "  " << t2<< "  " <<t<<  endl;


						//	cout << t14 << "  " << t24 << "  " << t34 << "  " << min(t14, t24, t34) << "  " << t_min << endl;

						//t_min = t14;

						func2("left", x0, y0, z0, r0, theta0, phi0, psi0, x, y, z, r, theta, phi, psi, t_min, V_0, v_phi0, v_phi, N_CYL_partitions, trajectory_cyl_x, trajectory_cyl_y, trajectory_cyl_z, trajectory_cyl_r, Vector_color_trajectory_cyl, trajectory_cyl_rr, out_trajectory_cyl, trajectory_cyl_phi, trajectory_cyl_psi, trajectory_cyl_theta, trajectory_cyl_v_x, trajectory_cyl_v_y,
							trajectory_cyl_v_z, trajectory_cyl_v_r, trajectory_cyl_v_phi, trajectory_cyl_v_perp, trajectory_cyl_v_0, trajectory_cyl_force, trajectory_cyl_condition_color, mu_particle, mu_particle_force, flaq_on_off_B_mu, index_condition, particle_mode, trajectory_cyl_mu, trajectory_cyl_B);


						/*

						if (z >= L_final - 100.0*DBL_EPSILON) {
						z = L_final; // из-за погрешоности вычеслений координата может быть немного больше L_final (1*10^-18)
						}

						if ((z > L_initial + 100.0*DBL_EPSILON) && (z < L_final - 100.0*DBL_EPSILON)) {

						r = R1_initial;
						}


						*/

						//cout << x << "  " << y << "  " << z << "    " << r << endl;

						//continue;

					}

					//long double t = t10;

					//func2("left", x0, y0, z0, r0, theta0, psi0, x, y, z, r, theta, phi, psi, t, V_0, v_phi0, v_phi, N_CYL_partitions, trajectory_cyl_x, trajectory_cyl_y, trajectory_cyl_z, trajectory_cyl_r, Vector_color_trajectory_cyl, trajectory_cyl_rr);

					//	cout << x << "  " << y << "  " << z << "    " << r << endl;

					delta_z = z - z0;
					delta_x = x - x0;
					delta_y = y - y0;

					v_x = ((x - x0) / fabs((z - z0)))*V_0*sin(theta0)*cos(psi0);
					v_y = ((y - y0) / fabs((z - z0)))*V_0*sin(theta0)*cos(psi0);
					v_z = ((z - z0) / fabs((z - z0)))*V_0*sin(theta0)*cos(psi0);

					v_r = (2.0*r0*V_0*cos(phi0 - psi0)*sin(theta0) + 2.0*pow(V_0*sin(theta0), 2.0)*fabs(z - z0) / (V_0*cos(theta0))) / (2.0*r);

					//	x0 = x;
					//	y0 = y;
					//	z0 = z;
					//	r0 = r;
					//	theta0 = theta;
					//	phi0 = phi;
					//	psi0 = psi;


					//if ((z > L_initial) && (z < L_final)) {


					//	cout << x << "  " << y << "  " << z << "    " << r << endl;
					//	}


					out = false;

					continue;


					//continue;


				}








				//cout << x_out << "  " << y_out << "  " << z_out << "    " << r_out << endl;

			}



			else {

				//cout << "!!!" << endl;

				//cout << x << "  " << y << "  " << z << "    " << r << endl;


				break;
			}

		}




		else if (on_off_mag == true) {



			//	long double x_out_mag = 0.0;
			//	long double y_out_mag = 0.0;
			//	long double z_out_mag = 0.0;
			//	long double r_out_mag = 0.0;
			//	long double theta_out_mag = 0.0;
			//	long double phi_out_mag = 0.0;
			//	long double psi_out_mag = 0.0;


			//step2:
			// частица в области, где НЕ находится магнит, внутри цилиндра
			if (((z > L_initial) && (z < L_initial + z0_mag)) || ((z > L_initial + z0_mag + L_mag) && (z < L_final))) {


				//break;
				//srand((unsigned int)time(NULL) + rand()); // привязка генератора случайных чисел к системному времени

				//cout << x << "  " << y << "  " << z << "    " << r << endl;

				if (b_surface == 1.0) { //-V550

					out = false;
					out_mag = false;
					n4 = n4 + 1;
					//return;


					//printf("%.3Lf %.3Lf %.9Le %.9Le %.3Lf %.3Lf %.9Le %s\n", x, y, z, r, phi, psi, theta,  (out ? "Да" : "Нет"));

					//cout << 180 * phi / M_PI << endl;

					//	trajectory_cyl_x.erase(trajectory_cyl_x.end() - N_CYL_partitions + 0, trajectory_cyl_x.end());
					//	trajectory_cyl_y.erase(trajectory_cyl_y.end() - N_CYL_partitions + 0, trajectory_cyl_y.end());

					//	trajectory_cyl_z.erase(trajectory_cyl_z.end() - N_CYL_partitions + 0, trajectory_cyl_z.end());
					//	trajectory_cyl_r.erase(trajectory_cyl_r.end() - N_CYL_partitions + 0, trajectory_cyl_r.end());
					//	trajectory_cyl_rr.erase(trajectory_cyl_rr.end() - N_CYL_partitions + 0, trajectory_cyl_rr.end());

					//	Vector_color_trajectory_cyl.erase(Vector_color_trajectory_cyl.end() - N_CYL_partitions + 0, Vector_color_trajectory_cyl.end());


					break;
				}


				long double mu = random(0.0, 1.0); // случайное число для учета захвата частицы поверхностью цилиндра

				if (mu <= b_surface) {

					out = false;
					out_mag = false;
					n4 = n4 + 1;
					//return;


					//printf("%.3Lf %.3Lf %.9Le %.9Le %.3Lf %.3Lf %.9Le %s\n", x, y, z, r, phi, psi, theta,  (out ? "Да" : "Нет"));

					//cout << 180 * phi / M_PI << endl;

					//	trajectory_cyl_x.erase(trajectory_cyl_x.end() - N_CYL_partitions + 0, trajectory_cyl_x.end());
					//	trajectory_cyl_y.erase(trajectory_cyl_y.end() - N_CYL_partitions + 0, trajectory_cyl_y.end());

					//	trajectory_cyl_z.erase(trajectory_cyl_z.end() - N_CYL_partitions + 0, trajectory_cyl_z.end());
					//	trajectory_cyl_r.erase(trajectory_cyl_r.end() - N_CYL_partitions + 0, trajectory_cyl_r.end());
					//	trajectory_cyl_rr.erase(trajectory_cyl_rr.end() - N_CYL_partitions + 0, trajectory_cyl_rr.end());

					//	Vector_color_trajectory_cyl.erase(Vector_color_trajectory_cyl.end() - N_CYL_partitions + 0, Vector_color_trajectory_cyl.end());


					break;

				}


				else {

					//printf("%.3Lf %.3Lf %.9Le %.9Le %.3Lf %.3Lf %.9Le %s\n", x, y, z, r, phi, psi, theta,  (out ? "Да" : "Нет"));

					if ((fabs(z0 - L_initial) <= epsilon) || (fabs(z0 - L_final) <= epsilon) || (fabs(z0 - (L_initial + z0_mag)) <= epsilon) || (fabs(z0 - (L_initial + z0_mag + L_mag)) <= epsilon)) {
						theta0 = theta;
						phi0 = phi;
						psi0 = psi;
					}
					else {
						theta0 = M_PI_2 - theta;
						phi0 = atan2(-y0, x0);
						psi0 = phi;

					}

					x0 = x;
					y0 = y;
					z0 = z;
					r0 = r;

					//	cout << x0 << "  " << y0 << "  " << z0 << "    " << r0 << endl;

					if (theta0 <= theta_diffusion_surface) {
						//srand((unsigned int)time(NULL) + rand()); // привязка генератора случайных чисел к системному времени
						//theta_0 = acos(pow(1.0 - pow(random(0.0, 1.0), 2.0), 1.0 / 2.0)); // от -pi/2 до pi распределена по закону cos(), получена методом обратной функции
						//theta_0 = asin(pow(random(0.0, 1.0), 1.0 / 2.0));
					//	theta = asin(pow(random(0.0, 1.0), 1.0 / 2.0));// от 0 до pi/2 распределена по закону cos(), получена методом обратной функции, максимум вероятности при theta=0

						theta = asin(pow(1.0 - pow(1.0 - random(0.0, 1.0), 2.0 / (n_cos_intensity + 1.0)), 1.0 / 2.0));

						//srand((unsigned int)time(NULL) + rand()); // привязка генератора случайных чисел к системному времени
						phi = 2.0*M_PI*random(0.0, 1.0); //от 0 до 2*pi равномерно распределена

														 //srand((unsigned int)time(NULL) + rand()); // привязка генератора случайных чисел к системному времени
						psi = 2.0*M_PI*random(0.0, 1.0); //от 0 до 2*pi равномерно распределена

					}

					else {
						theta = theta0;
						phi = phi0;
						psi = psi - M_PI;

					}




					long double t1111 = fabs(time2(theta, psi, R1_initial, V_0));
					long double t2222 = fabs(time2_(z0, L_initial, theta, psi, V_0));
					long double t3333 = fabs(time2_(z0, L_final, theta, psi, V_0));
					long double t4 = fabs(time2_(z0, L_initial + z0_mag, theta, psi, V_0));
					long double t5 = fabs(time2_(z0, L_initial + z0_mag + L_mag, theta, psi, V_0));




					//	long double t = min(t1111, t2222, t3);

					//	func2("right", x0, y0, z0, r0, theta, psi, x, y, z, r, t, V_0);

					//	cout << x << "  " << y << "  " << z << "    " << r << endl;



					if (cos(psi) > 0) {

						//	break;
						long double t = 0.0;

						if (z0 > L_initial + z0_mag + L_mag) {

							t = min(t1111, t5);

						}


						if (z0 < L_initial + z0_mag) {

							t = min(t1111, t2222);

						}


						//cout << t1111 << "  " << t2222<< "  " <<t<<  endl;
						func2("right", x0, y0, z0, r0, theta, phi, psi, x, y, z, r, theta, phi, psi, t, V_0, v_phi0, v_phi, N_CYL_partitions, trajectory_cyl_x, trajectory_cyl_y, trajectory_cyl_z, trajectory_cyl_r, Vector_color_trajectory_cyl, trajectory_cyl_rr, out_trajectory_cyl, trajectory_cyl_phi, trajectory_cyl_psi,
							trajectory_cyl_theta, trajectory_cyl_v_x, trajectory_cyl_v_y, trajectory_cyl_v_z, trajectory_cyl_v_r, trajectory_cyl_v_phi, trajectory_cyl_v_perp, trajectory_cyl_v_0, trajectory_cyl_force, trajectory_cyl_condition_color, mu_particle, mu_particle_force, flaq_on_off_B_mu, index_condition, particle_mode, trajectory_cyl_mu, trajectory_cyl_B);



						/*




						if (z <= L_initial + 100.0*DBL_EPSILON) {
						z = L_initial; // из-за погрешоности вычеслений координата может быть немного меньше L_initial (10^-18)
						}

						if ((z > L_initial + 100.0*DBL_EPSILON) && (z < L_final - 100.0*DBL_EPSILON)) {

						r = R1_initial;
						}

						*/


						//	cout << x << "  " << y << "  " << z << "    " << r << endl;

						continue;
					}

					if (cos(psi) <= 0) {


						//break;

						long double t = 0.0;

						if (z0 > L_initial + z0_mag + L_mag) {

							t = min(t1111, t3333);

						}


						if (z0 < L_initial + z0_mag) {

							t = min(t1111, t4);

						}
						//cout << t1111 << "  " << t2<< "  " <<t<<  endl;
						func2("left", x0, y0, z0, r0, theta, phi, psi, x, y, z, r, theta, phi, psi, t, V_0, v_phi0, v_phi, N_CYL_partitions, trajectory_cyl_x, trajectory_cyl_y, trajectory_cyl_z, trajectory_cyl_r, Vector_color_trajectory_cyl, trajectory_cyl_rr, out_trajectory_cyl, trajectory_cyl_phi, trajectory_cyl_psi, trajectory_cyl_theta, trajectory_cyl_v_x, trajectory_cyl_v_y, trajectory_cyl_v_z, trajectory_cyl_v_r, trajectory_cyl_v_phi, trajectory_cyl_v_perp, trajectory_cyl_v_0,
							trajectory_cyl_force, trajectory_cyl_condition_color, mu_particle, mu_particle_force, flaq_on_off_B_mu, index_condition, particle_mode, trajectory_cyl_mu, trajectory_cyl_B);


						/*

						if (z >= L_final - 100.0*DBL_EPSILON) {
						z = L_final; // из-за погрешоности вычеслений координата может быть немного больше L_final (1*10^-18)
						}

						if ((z > L_initial + 100.0*DBL_EPSILON) && (z < L_final - 100.0*DBL_EPSILON)) {

						r = R1_initial;
						}


						*/

						//cout << x << "  " << y << "  " << z << "    " << r << endl;

						continue;

					}



					//cout << x << "  " << y << "  " << z << "    " << r << endl;



					//continue;


				}










				//cout << x_out << "  " << y_out << "  " << z_out << "    " << r_out << endl;

			}





			// частица в области, где находится магнит, внутри цилиндра
			if ((fabs(z - (L_initial + z0_mag)) <= epsilon) || (fabs(z - (L_initial + z0_mag + L_mag)) <= epsilon)) {



				long double x_in_mag = x, y_in_mag = y, z_in_mag = z, r_in_mag = r, theta_in_mag = theta, phi_in_mag = phi, psi_in_mag = psi, v_r_in_mag = v_r, v_x_in_mag = v_x, v_y_in_mag = v_y, v_phi_in_mag = v_phi;

				long double x_out_mag = 0.0, y_out_mag = 0.0, z_out_mag = 0.0, r_out_mag = 0.0, theta_out_mag = 0.0, phi_out_mag = 0.0, psi_out_mag = 0.0, v_r_out_mag = 0.0, v_x_out_mag = 0.0, v_y_out_mag = 0.0, v_phi_out_mag = 0.0;

				out_mag = false;

				x0 = x;
				y0 = y;
				z0 = z;
				r0 = r;

				//bool out_mag = true;

				long double r_mag_max = r_mag_max_initial;
				long double h_mag = L_mag / N_mag_partitions; // шаг разбиения магнита
				long double z0_mag_ = z0_mag; // координата вдоль оси магнита


				if (mag_runge == true) {


					//	RK_4_mag_curve_1(L_mag, r_mag_max_initial, r_mag_max_final, B_mag_max_initial, B_mag_max_final, V_0, m_particle, m_mag, N_mag_partitions, x_in, y_in, z_in, r_in, theta_in, phi_in, psi_in, x_out, y_out, z_out, r_out, theta_out, phi_out, psi_out, out_mag, Vector_r_mag, Vector_z_mag);

					if (cyl_number == 2) { //-V550



						if (v_r_in_mag < 0) {
							i_v_r = i_v_r + 1;
							//	cout << "меньше" << endl;
						}
						else {
							j_v_r = j_v_r + 1;
							//cout << "больше" << endl;
						}
						//cout << i_v_r << endl;
						//cout << j_v_r << endl;
					}
					//#pragma omp ordered
					//{
				
					//cout << "масса " << m_particle << endl;

					RK_4_mag_curve_2(L_mag, r_mag_max_initial, r_mag_max_final, B_mag_max_initial, B_mag_max_final, V_0, m_particle, m_mag, N_mag_partitions, x_in_mag, y_in_mag, z_in_mag, r_in_mag, theta_in_mag, phi_in_mag, psi_in_mag, x_out_mag, y_out_mag, z_out_mag, r_out_mag, theta_out_mag, phi_out_mag, psi_out_mag, out_mag, Vector_temp_r_mag, Vector_temp_z_mag, Vector_temp_x_mag, Vector_temp_y_mag, min_r_out_mag, min_r_in_mag,
						n_mag_in, n_mag_absorption, n_mag_out, z_zero, I_particle, J_particle, m_F, m_J, particle_mode, iron_mag, v_r_in_mag, v_r_out_mag, v_x_in_mag, v_x_out_mag, v_y_in_mag, v_y_out_mag, v_phi_in_mag, v_phi_out_mag, Vector_temp_color_mag, cyl_number, Vector_temp_rr_mag, Vector_temp_out_mag, b_mag_surface, b_mag_left, b_mag_right, z0_mag, L_cyl, L_cyl_1, L_cyl_2, L_cyl_3, L_cyl_4, L_cyl_5, L_cyl_6, L_cyl_7, Vector_temp_phi_mag, Vector_temp_psi_mag, Vector_temp_theta_mag, Vector_temp_v_x_mag, Vector_temp_v_y_mag, Vector_temp_v_z_mag, Vector_temp_v_r_mag, Vector_temp_v_phi_mag, Vector_temp_v_perp_mag, Vector_temp_v_0_mag, n_cos_intensity, Vector_temp_force_mag, N_negative_mag, N_zero_mag, N_positive_mag, mu_particle, mu_particle_force,
						Vector_temp_condition_color_mag, flaq_on_off_B_mu, index_condition, Vector_temp_mu_mag, Vector_temp_B_mag, Vector_r_magnetic_field_table, Vector_phi_magnetic_field_table, Vector_B_magnetic_field_table, Vector_delta_B_magnetic_field_table, on_off_table_magnetic_field, Vector_index_r_magnetic_field_table, index_phi_magnetic_field_table, m_mag_table, r_min_mag_table, r_max_mag_table, L_mag_B_off_after);

					//if (out_mag == true) {
					//	cout << "!!!" << endl;
					//}


					//vector<long double> Vector_temp_r_mag(0);
					//vector<long double> Vector_temp_rr_mag(0);
					//vector<long double> Vector_temp_z_mag(0);
					//vector<long double> Vector_temp_x_mag(0);
					//vector<long double> Vector_temp_y_mag(0);
					//vector<long double> Vector_temp_color_mag(0);
					//vector<long double> Vector_temp_out_mag(0);



				}

				else if (mag_runge == false) {

					for (size_t iiii = 1; iiii <= N_mag_partitions; iiii = iiii + 1) {

						//cout << phi_in << endl;
						mag_curve(x_in, y_in, z_in, r_in, theta_in, phi_in, psi_in, x_out, y_out, z_out, r_out, theta_out, phi_out, psi_out, z0_mag_, h_mag, r_mag_max, mu_core_particle, mu_electron_particle, m_particle, I_particle, J_particle, m_F, m_J, B_mag_max_initial, B_critical,
							out_mag, V_0, z_zero, n_mag_in, n_mag_absorption, n_mag_out, r_mag_max_initial, r_mag_max_final);

						if (out_mag == false) {

							out = false;
							break;

						}

						//printf("%.3Lf %.3Lf %.9Le %.9Le %.3Lf %.3Lf %.9Le %.9Le %.9Le %s\n", x_in, y_in, z_in, r_in, x_out, y_out, z_out, r_out,theta_out, (out_mag ? "Да" : "Нет"));



						r_mag_max = r_mag_max + h_mag * (r_mag_max_final - r_mag_max_initial) / L_mag;
						//	z0_mag_ = z0_mag_ + h_mag;
						z0_mag_ = z_out;
						x_in = x_out;
						y_in = y_out;
						z_in = z_out;
						r_in = r_out;
						theta_in = theta_out;
						phi_in = phi_out;
						psi_in = psi_out;

					}

				}



				//mag_curve(x_in, y_in, z_in, r_in, theta_in, phi_in, psi_in, x_out, y_out, z_out, r_out, theta_out, phi_out, psi_out, z0_mag, L_mag, r_mag_max, mu_particle, m_particle, B_max, out_mag);

				//printf("%.3Lf %.3Lf %.3Lf %.3Lf\n", z_in, r_in, z_out, r_out);


				x = x_out_mag;
				y = y_out_mag;
				z = z_out_mag;
				r = r_out_mag;
				v_r = v_r_out_mag;
				v_phi = v_phi_out_mag;
				phi = phi_out_mag;
				psi = psi_out_mag;
				theta = theta_out_mag;

				x0 = x;
				y0 = y;
				z0 = z;
				r0 = r;

				//printf("%.3Lf %.3Lf %.9Le %.9Le %.3Lf %.3Lf %.9Le %s\n", x, y, z, r, phi, psi, theta, (out_mag ? "Да" : "Нет"));


				if (out_mag == false) {

					out = false;


					//	trajectory_cyl_x.erase(trajectory_cyl_x.end() - 1, trajectory_cyl_x.end());
					//	trajectory_cyl_y.erase(trajectory_cyl_y.end() - 1, trajectory_cyl_y.end());

					//	trajectory_cyl_z.erase(trajectory_cyl_z.end() - 1, trajectory_cyl_z.end());
					//	trajectory_cyl_r.erase(trajectory_cyl_r.end() - 1, trajectory_cyl_r.end());

					//cout << 0 << endl;

					break;

				}


				if (out_mag == true) {




					//	printf("%.3Lf %.3Lf %.3Lf %.3Lf\n", z_in, r_in, z_out, r_out);

					/*



					for (unsigned int j = (unsigned int)(Vector_z_mag.size() - N_mag_partitions - 1); j < Vector_z_mag.size(); j = j + 1) {


					trajectory_cyl_x.push_back(Vector_x_mag[j]);
					trajectory_cyl_y.push_back(Vector_y_mag[j]);
					trajectory_cyl_z.push_back(Vector_z_mag[j] + L_initial + z0_mag);
					trajectory_cyl_r.push_back(Vector_r_mag[j]);
					//	if (j == (Vector_z_mag.size() -1)) {
					//	Vector_color_trajectory_cyl.push_back("purple");
					//}else {
					Vector_color_trajectory_cyl.push_back(Vector_color_mag[j]);
					//}


					trajectory_cyl_rr.push_back(Vector_rr_mag[j]);

					out_trajectory_cyl.push_back(Vector_out_mag[j]);


					//cout << z0_mag << endl;
					}



					*/

					size_t size = Vector_temp_z_mag.size();

					for (size_t j = 0; j < size; j = j + 1) {


						trajectory_cyl_x.push_back(Vector_temp_x_mag[j]);
						trajectory_cyl_y.push_back(Vector_temp_y_mag[j]);
						trajectory_cyl_z.push_back(Vector_temp_z_mag[j] + L_initial + z0_mag);
						trajectory_cyl_force.push_back(Vector_temp_force_mag[j]);



						trajectory_cyl_mu.push_back(Vector_temp_mu_mag[j]);
						trajectory_cyl_B.push_back(Vector_temp_B_mag[j]);

						trajectory_cyl_condition_color.push_back(Vector_temp_condition_color_mag[j]);

						trajectory_cyl_phi.push_back(Vector_temp_phi_mag[j]);
						trajectory_cyl_psi.push_back(Vector_temp_psi_mag[j]);
						trajectory_cyl_theta.push_back(Vector_temp_theta_mag[j]);


						trajectory_cyl_v_x.push_back(Vector_temp_v_x_mag[j]);
						trajectory_cyl_v_y.push_back(Vector_temp_v_y_mag[j]);
						trajectory_cyl_v_z.push_back(Vector_temp_v_z_mag[j]);
						trajectory_cyl_v_r.push_back(Vector_temp_v_r_mag[j]);
						trajectory_cyl_v_phi.push_back(Vector_temp_v_phi_mag[j]);
						trajectory_cyl_v_perp.push_back(Vector_temp_v_perp_mag[j]);
						trajectory_cyl_v_0.push_back(Vector_temp_v_0_mag[j]);


						trajectory_cyl_r.push_back(Vector_temp_r_mag[j]);
						//	if (j == (Vector_z_mag.size() -1)) {
						//	Vector_color_trajectory_cyl.push_back("purple");
						//}else {
						Vector_color_trajectory_cyl.push_back(Vector_temp_color_mag[j]);
						//}


						trajectory_cyl_rr.push_back(Vector_temp_rr_mag[j]);

						out_trajectory_cyl.push_back(Vector_temp_out_mag[j]);


						//cout << z0_mag << endl;
					}


					//	printf("%.3Lf %.3Lf %.9Le %.9Le %.3Lf %.3Lf %.9Le %s\n", x, y, z, r, phi, psi, theta,  (out_mag ? "Да" : "Нет"));



					long double t100 = fabs(time1("left", r_out_mag, theta_out_mag, phi_out_mag, psi_out_mag, R1_final, V_0));
					long double t200 = fabs(time1_(z_out_mag, L_initial, theta_out_mag, V_0));
					long double t300 = fabs(time1_(z_out_mag, L_final, theta_out_mag, V_0));

					/*

					if (cos(psi) < 0) {

					x0 = x;
					y0 = y;
					z0 = z;
					r0 = r;



					long double t = min(t100, t200);
					//cout << t1 << "  " << t2<< "  " <<t<<  endl;
					func1("right", x0, y0, z0, r0, theta, phi, psi, x, y, z, r, t, V_0);






					}

					if (cos(psi) >= 0) {

					x0 = x;
					y0 = y;
					z0 = z;
					r0 = r;


					long double t = min(t100, t300);

					func1("left", x0, y0, z0, r0, theta, phi, psi, x, y, z, r, t, V_0);


					}

					*/

					long double t = min(t100, t300);
					//cout << t1 << "  " << t2<< "  " <<t<<  endl;
					func1("left", x_out_mag, y_out_mag, z_out_mag, r_out_mag, theta_out_mag, phi_out_mag, psi_out_mag, x, y, z, r, theta, phi, psi, t, V_0, v_phi_out_mag, v_phi, N_CYL_partitions, trajectory_cyl_x, trajectory_cyl_y, trajectory_cyl_z, trajectory_cyl_r, Vector_color_trajectory_cyl, trajectory_cyl_rr, out_trajectory_cyl, trajectory_cyl_phi, trajectory_cyl_psi, trajectory_cyl_theta,
						trajectory_cyl_v_x, trajectory_cyl_v_y, trajectory_cyl_v_z, trajectory_cyl_v_r, trajectory_cyl_v_phi, trajectory_cyl_v_perp, trajectory_cyl_v_0, trajectory_cyl_force, trajectory_cyl_condition_color, mu_particle, mu_particle_force, flaq_on_off_B_mu, index_condition, particle_mode, trajectory_cyl_mu, trajectory_cyl_B);


					//v_r_out = ((r - r_out_mag) / fabs((z - z_out_mag)))*V_0*cos(theta);

					v_r_out = (2.0*r_out_mag*V_0*cos(phi_out_mag - psi_out_mag)*sin(theta_out_mag) + 2.0*pow(V_0*sin(theta_out_mag), 2.0)*fabs(z - z_out_mag) / (V_0*cos(theta_out_mag))) / (2.0*r_out_mag);

					v_phi_out = v_phi;

					v_x_out = ((x - x_out_mag) / fabs((z - z_out_mag)))*V_0*cos(theta);
					v_y_out = ((y - y_out_mag) / fabs((z - z_out_mag)))*V_0*cos(theta);

					//	printf("%.3Lf %.3Lf %.9Le %.9Le %.3Lf %.3Lf %.9Le %s\n", x, y, z, r, phi, psi, theta,  (out_mag ? "Да" : "Нет"));

					//continue;
				}




			}

			//printf("%.3Lf %.3Lf %.9Le %.9Le %.3Lf %.3Lf %.9Le %s\n", x, y, z, r, phi, psi, theta,  (out ? "Да" : "Нет"));

			//if (z == L_final) {

			//	break;
			//}

			if ((fabs(z - L_initial) <= epsilon) || (fabs(z - L_final) <= epsilon)) {


				theta_out = theta;

				/*

				if (x >= 0 && y >= 0) {

				phi = atan(fabs(y / x));
				}



				if (x < 0 && y < 0) {

				phi = M_PI + atan(fabs(y / x));
				}

				if (x > 0 && y < 0) {

				phi = 2.0*M_PI - atan(fabs(y / x));
				}


				if (x < 0 && y > 0) {

				phi = M_PI - atan(fabs(y / x));
				}

				*/
				phi_out = phi;

				psi_out = psi;


				x_out = x;
				y_out = y;
				z_out = z;
				r_out = r;
				out = true;


				n2 = n2 + 1;


				//	printf("%.3Lf %.3Lf %.9Le %.9Le %.3Lf %.3Lf %.9Le %s\n", x, y, z, r, phi, psi, theta,  (out ? "Да" : "Нет"));


				//break;

				goto step_out;

				//	goto step2;

			}

			else {

				//	cout << "!!!" << endl;

				//	trajectory_cyl_x.erase(trajectory_cyl_x.end() - N_CYL_partitions + 0, trajectory_cyl_x.end());
				//	trajectory_cyl_y.erase(trajectory_cyl_y.end() - N_CYL_partitions + 0, trajectory_cyl_y.end());

				//	trajectory_cyl_z.erase(trajectory_cyl_z.end() - N_CYL_partitions + 0, trajectory_cyl_z.end());
				//	trajectory_cyl_r.erase(trajectory_cyl_r.end() - N_CYL_partitions + 0, trajectory_cyl_r.end());
				//	trajectory_cyl_rr.erase(trajectory_cyl_rr.end() - N_CYL_partitions + 0, trajectory_cyl_rr.end());

				//	Vector_color_trajectory_cyl.erase(Vector_color_trajectory_cyl.end() - N_CYL_partitions + 0, Vector_color_trajectory_cyl.end());


				out = false;
				goto step_out;
				//goto step2;

				break;
			}

		}






		//cout << i_Collision << endl;

		//break;

	}



	//}


step_out:

	//	cout << i-1 << endl;

	//if (i - 1 == 0) {
	//	i_Collision = 1;
	//}

	//else {

	i_Collision = i - 1;

	//}


	//	cout << i_Collision << endl;



	N1 = n1;
	N2 = n2;
	N3 = n3;
	N4 = n4;
	N5 = n5;


	Vector_temp_r_mag.clear();
	Vector_temp_rr_mag.clear();

	Vector_temp_mu_mag.clear();
	Vector_temp_B_mag.clear();

	Vector_temp_z_mag.clear();
	Vector_temp_force_mag.clear();

	Vector_temp_condition_color_mag.clear();

	Vector_temp_phi_mag.clear();
	Vector_temp_psi_mag.clear();
	Vector_temp_theta_mag.clear();


	Vector_temp_v_x_mag.clear();
	Vector_temp_v_y_mag.clear();
	Vector_temp_v_z_mag.clear();
	Vector_temp_v_r_mag.clear();
	Vector_temp_v_phi_mag.clear();
	Vector_temp_v_perp_mag.clear();
	Vector_temp_v_0_mag.clear();


	Vector_temp_x_mag.clear();
	Vector_temp_y_mag.clear();
	Vector_temp_color_mag.clear();
	Vector_temp_out_mag.clear();


	//	if (z_out==L_initial){
	//	cout << z_out << endl;

	//	}


	//cout << x_out << "  " << y_out << "  " << z_out << "    " << r_out << " Вышла: " << (out ? "Да" : "Нет") <<  endl;

	//return;

	//	if (out == true) {

	//cout << "!!!" << endl;

	//trajectory_cyl_x.push_back(x_out);
	//trajectory_cyl_y.push_back(y_out);
	//trajectory_cyl_z.push_back(z_out);
	//trajectory_cyl_r.push_back(r_out);

	//trajectory_cyl_x.push_back(0.0);
	//trajectory_cyl_y.push_back(0.0);
	//trajectory_cyl_z.push_back(0.0);
	//trajectory_cyl_r.push_back(0.0);

	//	}


	//printf("%s %s %s\n", out ? "Да" : "Нет", on_off_mag ? "Да" : "Нет", out_mag ? "Да" : "Нет");


	//	if (i - 1 == n && out == false) {


	//	trajectory_cyl_x.erase(trajectory_cyl_x.end()  - (i - 3) * N_CYL_partitions, trajectory_cyl_x.end());
	//	trajectory_cyl_y.erase(trajectory_cyl_y.end()  - (i - 3) * N_CYL_partitions, trajectory_cyl_y.end());

	//	trajectory_cyl_z.erase(trajectory_cyl_z.end() - (i - 3) * N_CYL_partitions, trajectory_cyl_z.end());
	//	trajectory_cyl_r.erase(trajectory_cyl_r.end()  - (i - 3)* N_CYL_partitions, trajectory_cyl_r.end());
	//	trajectory_cyl_rr.erase(trajectory_cyl_rr.end()  - (i - 3) * N_CYL_partitions, trajectory_cyl_rr.end());

	//	Vector_color_trajectory_cyl.erase(Vector_color_trajectory_cyl.end() - (i - 3) * N_CYL_partitions, Vector_color_trajectory_cyl.end());


	//	trajectory_cyl_x.shrink_to_fit();
	//	trajectory_cyl_y.shrink_to_fit();
	//	trajectory_cyl_z.shrink_to_fit();
	//	trajectory_cyl_r.shrink_to_fit();
	//	trajectory_cyl_rr.shrink_to_fit();

	//	}




	//	if (out == false) {


	//	cout << i_Collision << endl;

	//	}




	if (out == true) {

		out_trajectory_cyl.erase(out_trajectory_cyl.end() - 1, out_trajectory_cyl.end());

		out_trajectory_cyl.shrink_to_fit();

		out_trajectory_cyl.push_back(1.0);

	}
	if (out == true && fabs(z_out - L_final) <= epsilon) {

		long double mu_temp_temp = 0.0;
		long double mu_temp = 0.0;
		long double mu_force_temp = 0.0;
		long double E_temp_temp = 0.0;
		long double mu_particle_temp = 0.0;
		long double mu_particle_force_temp = 0.0;

		const long double mu_bor = 5.788381806638*pow(10.0, 13.0)*pow(2.99792458, 2.0); // магнетон Бора электронный в единицах эВ/Гс*(скорость света [мм/c])^2

																						//	const long double mu_bor = 3.152451260522*pow(10.0, 10.0)*pow(2.99792458, 2.0); // магнетон Бора ядерный в единицах эВ/Гс*(скорость света [мм/c])^2


		const long double mu_bor_force = 9.2740096820*pow(10.0, 0.0);



		if (flaq_on_off_B_mu == false) {
			mu_particle_temp = mu_temp;
			mu_particle_force_temp = mu_force_temp;

			//cout << fabs(mu_particle / mu_bor) << endl;
		}
		if (flaq_on_off_B_mu == true) {

			


			//	cout << index_condition << endl;

			if (particle_mode == 1) {
				mu_particle_temp = mu_H(index_condition, B_MAX, mu_temp_temp, E_temp_temp)*mu_bor;
				mu_particle_force_temp = mu_H(index_condition, B_MAX, mu_temp_temp, E_temp_temp)*mu_bor_force;
			}

			if (particle_mode == 2) {

				mu_particle_temp = mu_D(index_condition, B_MAX, mu_temp_temp, E_temp_temp)*mu_bor;
				mu_particle_force_temp = mu_D(index_condition, B_MAX, mu_temp_temp, E_temp_temp)*mu_bor_force;
			}

			if (particle_mode == 3) {
				mu_particle_temp = mu_H_2(index_condition, B_MAX, mu_temp_temp, E_temp_temp)*mu_bor;
				mu_particle_force_temp = mu_H_2(index_condition, B_MAX, mu_temp_temp, E_temp_temp)*mu_bor_force;

			}

			if (particle_mode == 4) { //-V112

				mu_particle_temp = mu_D_2(index_condition, B_MAX, mu_temp_temp, E_temp_temp)*mu_bor;
				mu_particle_force_temp = mu_D_2(index_condition, B_MAX, mu_temp_temp, E_temp_temp)*mu_bor_force;

			}

		}




		if (mu_particle_temp > 0.0 && mu_particle_force_temp > 0.0) {
			N_positive_cyl = N_positive_cyl + 1;

		}

		if (mu_particle_temp < 0.0 && mu_particle_force_temp < 0.0) {
			N_negative_cyl = N_negative_cyl + 1;

		}
		if (fabs(mu_particle_temp - 0.0) <= epsilon && fabs(mu_particle_force_temp - 0.0) <= epsilon) {
			N_zero_cyl = N_zero_cyl + 1;

		}

	}

	//if (out == false) {


	//	trajectory_cyl_x.erase(trajectory_cyl_x.end() - 1 - 1 * N_CYL_partitions, trajectory_cyl_x.end());
	//	trajectory_cyl_y.erase(trajectory_cyl_y.end() - 1 - 1 * N_CYL_partitions, trajectory_cyl_y.end());

	//	trajectory_cyl_z.erase(trajectory_cyl_z.end() - 1 - 1 * N_CYL_partitions, trajectory_cyl_z.end());
	//	trajectory_cyl_r.erase(trajectory_cyl_r.end() - 1 - 1 * N_CYL_partitions, trajectory_cyl_r.end());
	//	trajectory_cyl_rr.erase(trajectory_cyl_rr.end() - 1 - 1 * N_CYL_partitions, trajectory_cyl_rr.end());

	//	Vector_color_trajectory_cyl.erase(Vector_color_trajectory_cyl.end() - 1 - 1 * N_CYL_partitions, Vector_color_trajectory_cyl.end());

	//cout << i_Collision <<" " << z << " "<<r<< endl;

	//cout << "!!!" << endl;



	//	trajectory_cyl_x.erase(trajectory_cyl_x.end() - 0 - (i_Collision + 1)*(N_CYL_partitions + 1), trajectory_cyl_x.end());
	//	trajectory_cyl_y.erase(trajectory_cyl_y.end() - 0 - (i_Collision + 1)*(N_CYL_partitions + 1), trajectory_cyl_y.end());

	//	trajectory_cyl_z.erase(trajectory_cyl_z.end() - 0 - (i_Collision + 1)*(N_CYL_partitions + 1), trajectory_cyl_z.end());
	//	trajectory_cyl_r.erase(trajectory_cyl_r.end() - 0 - (i_Collision + 1)*(N_CYL_partitions + 1), trajectory_cyl_r.end());
	//	trajectory_cyl_rr.erase(trajectory_cyl_rr.end() - 0 - (i_Collision + 1)*(N_CYL_partitions + 1), trajectory_cyl_rr.end());

	//	Vector_color_trajectory_cyl.erase(Vector_color_trajectory_cyl.end() - 0 - (i_Collision + 1)*(N_CYL_partitions + 1), Vector_color_trajectory_cyl.end());


	//	trajectory_cyl_x.shrink_to_fit();
	//	trajectory_cyl_y.shrink_to_fit();
	//	trajectory_cyl_z.shrink_to_fit();
	//	trajectory_cyl_r.shrink_to_fit();
	//	trajectory_cyl_rr.shrink_to_fit();



	//	if ( (out_mag == false) && (on_off_mag == false)) {
	//		trajectory_cyl_x.erase(trajectory_cyl_x.end() - 1, trajectory_cyl_x.end());
	//		trajectory_cyl_y.erase(trajectory_cyl_y.end() - 1, trajectory_cyl_y.end());

	//		trajectory_cyl_z.erase(trajectory_cyl_z.end() - 1, trajectory_cyl_z.end());
	//		trajectory_cyl_r.erase(trajectory_cyl_r.end() - 1, trajectory_cyl_r.end());


	//	}


	//	if ((out_mag == true) && (on_off_mag == true)) {

	//	trajectory_cyl_x.erase(trajectory_cyl_x.end() - (N_mag_partitions + 1 + 0 * N_CYL_partitions), trajectory_cyl_x.end());
	//	trajectory_cyl_y.erase(trajectory_cyl_y.end() - (N_mag_partitions + 1 + 0 * N_CYL_partitions), trajectory_cyl_y.end());

	//	trajectory_cyl_z.erase(trajectory_cyl_z.end() - (N_mag_partitions + 1 + 0 * N_CYL_partitions), trajectory_cyl_z.end());
	//	trajectory_cyl_r.erase(trajectory_cyl_r.end() - (N_mag_partitions + 1 + 0 * N_CYL_partitions), trajectory_cyl_r.end());
	//	trajectory_cyl_rr.erase(trajectory_cyl_rr.end() - (N_mag_partitions + 1 + 0 * N_CYL_partitions), trajectory_cyl_rr.end());

	//	Vector_color_trajectory_cyl.erase(Vector_color_trajectory_cyl.end() - (N_mag_partitions + 1 + 0 * N_CYL_partitions), Vector_color_trajectory_cyl.end());


	//	trajectory_cyl_x.shrink_to_fit();
	//	trajectory_cyl_y.shrink_to_fit();
	//	trajectory_cyl_z.shrink_to_fit();
	//	trajectory_cyl_r.shrink_to_fit();
	//	trajectory_cyl_rr.shrink_to_fit();
	//	Vector_color_trajectory_cyl.shrink_to_fit();


	//		}

	//	if ((out_mag == false) && (on_off_mag == true)) {
	//		trajectory_cyl_x.erase(trajectory_cyl_x.end() - 1 , trajectory_cyl_x.end());
	//		trajectory_cyl_y.erase(trajectory_cyl_y.end() - 1 , trajectory_cyl_y.end());

	//		trajectory_cyl_z.erase(trajectory_cyl_z.end() - 1 , trajectory_cyl_z.end());
	//		trajectory_cyl_r.erase(trajectory_cyl_r.end() - 1 , trajectory_cyl_r.end());


	//	}


	//	if ((out_mag == true) && (on_off_mag == false)) {
	//		trajectory_cyl_x.erase(trajectory_cyl_x.end() - 1, trajectory_cyl_x.end());
	//		trajectory_cyl_y.erase(trajectory_cyl_y.end() - 1, trajectory_cyl_y.end());

	//		trajectory_cyl_z.erase(trajectory_cyl_z.end() - 1, trajectory_cyl_z.end());
	//		trajectory_cyl_r.erase(trajectory_cyl_r.end() - 1, trajectory_cyl_r.end());


	//	}

	//	}




	//else 
	//if (on_off_mag == true) {




	//if ((out == false) && (out_mag == true)) {
	//trajectory_cyl_x.erase(trajectory_cyl_x.end() - 1 - N_mag_partitions, trajectory_cyl_x.end());
	//trajectory_cyl_y.erase(trajectory_cyl_y.end() - 1 - N_mag_partitions, trajectory_cyl_y.end());

	//trajectory_cyl_z.erase(trajectory_cyl_z.end() - 1 - N_mag_partitions, trajectory_cyl_z.end());
	//trajectory_cyl_r.erase(trajectory_cyl_r.end() - 1 - N_mag_partitions, trajectory_cyl_r.end());


	//}

	//}

	/*
	if (out_mag == false) {

	if (out == false) {
	trajectory_cyl_x.erase(trajectory_cyl_x.end() - 2, trajectory_cyl_x.end());
	trajectory_cyl_y.erase(trajectory_cyl_y.end() - 2, trajectory_cyl_y.end());

	trajectory_cyl_z.erase(trajectory_cyl_z.end() - 2, trajectory_cyl_z.end());
	trajectory_cyl_r.erase(trajectory_cyl_r.end() - 2, trajectory_cyl_r.end());


	}

	}
	*/

	//}

}



/*Вывод текста из файла на экран*/
void ReadFile_(const char *filename)
{

	const int N = 256; //Константный размер строки
					   //char *FName = filename; //Путь к файлу
					   //cout << endl << "ReadFile:  "; //Для красоты
	char S[N] = { "" }; //В S будут считываться строки
	ifstream in1(filename); //Открыли файл для чтения
	while (!in1.eof()) //Будем читать информацию пока не дойдем до конца файла
	{
		in1.getline(S, N); //Построчное считывание информации в S
		cout << S << endl; //Вывод очередной строки на экран
		SleepEx(8, true);
	}
	in1.close();  //Закрыли открытый файл
}


void angular_coefficient(long double V_0, long double R2_1, long double R3_1, long double R2_2, long double R3_2, long double L_1, long double &x_out, long double &y_out, long double &z_out, long double &r_out, long double &phi_out, long double &psi_out, long double &theta_out, long double &phi_1_2, long double &v_r_out, vector<long double> &trajectory_cyl_x, vector<long double> &trajectory_cyl_y, vector<long double> &trajectory_cyl_z, vector<long double> &trajectory_cyl_r, long double &v_phi_out, vector<long double>&Vector_color_trajectory_cyl, vector<long double> &trajectory_cyl_rr, size_t N_CYL_partitions, vector<long double> &out_trajectory_cyl,
	vector<long double> &trajectory_cyl_phi, vector<long double> &trajectory_cyl_psi, vector<long double> &trajectory_cyl_theta, vector<long double> &trajectory_cyl_v_x, vector<long double> &trajectory_cyl_v_y, vector<long double> &trajectory_cyl_v_z, vector<long double> &trajectory_cyl_v_r, vector<long double> &trajectory_cyl_v_phi, vector<long double> &trajectory_cyl_v_perp, vector<long double> &trajectory_cyl_v_0, vector<long double> &trajectory_cyl_force,
	long double mu_temp, long double mu_force_temp, vector<long double> &trajectory_cyl_condition_color, bool flaq_on_off_mu_B, size_t index_condition, size_t particle_mode, vector<long double> &trajectory_cyl_mu, vector<long double> &trajectory_cyl_B) {




	long double r_1 = pow((pow(R3_1, 2.0) + (pow(R2_1, 2.0) - pow(R3_1, 2.0))*random(0.0, 1.0)), 1.0 / 2.0);

	//cout << r_1 << endl;

	//	long double r_2 = pow((pow(R3_2, 2.0) + (pow(R2_2, 2.0) - pow(R3_2, 2.0))*random(0.0, 1.0)), 1.0 / 2.0);

	//cout << r_2 << endl;

	long double phi_1 = 2.0*M_PI*random(0.0, 1.0);

	//от 0 до 2*pi равномерно распределена
	//long double theta_1 = asin(pow(random(0.0, 1.0), 1.0 / 2.0));// от 0 до pi/2 распределена по закону cos(theta), получена методом обратной функции, максимум вероятности при theta=0

	//	long double a = min(1.0 / (1.0 + pow(L_1 / fabs(R2_2 - r_1), 2.0)), 1.0 / (1.0 + pow(L_1 / fabs(R3_2 - r_1), 2.0)));
	//	long double b = max(1.0 / (1.0 + pow(L_1 / fabs(R2_2 - r_1), 2.0)), 1.0 / (1.0 + pow(L_1 / fabs(R3_2 - r_1), 2.0)));


	long double a = min(pow(sin(atan(fabs(R2_2 - r_1) / L_1)), 2.0), pow(sin(atan(fabs(R3_2 - r_1) / L_1)), 2.0));
	long double b = max(pow(sin(atan(fabs(R2_2 - r_1) / L_1)), 2.0), pow(sin(atan(fabs(R3_2 - r_1) / L_1)), 2.0));

	long double theta_1 = asin(pow(random(a, b), 1.0 / 2.0));

	//cout << theta_1 << endl;

	//long double	psi_1 = 1.0*M_PI*random(0.0, 1.0)*signum(theta_1);

	long double	psi_1 = 0.0;
	//if (signum(theta_1) < 0) {
	//	psi_1 = random(0.0, M_PI);

	//}
	//else
	//{
	//	psi_1 = random(M_PI, 2.0*M_PI);
	//}

	//psi_1 = random(0.0, 2.0*M_PI);

	long double v_z = V_0 * cos(theta_1);

	long double v_phi = V_0 * sin(theta_1)*sin(phi_1 - psi_1);

	//cout << theta_1 << endl;



	long double x_1 = r_1 * cos(phi_1);
	long double y_1 = r_1 * sin(phi_1);
	long double z_1 = 0.0;




	trajectory_cyl_x.push_back(x_1);
	trajectory_cyl_y.push_back(y_1);
	trajectory_cyl_z.push_back(z_1);

	trajectory_cyl_phi.push_back(phi_1);
	trajectory_cyl_psi.push_back(psi_1);
	trajectory_cyl_theta.push_back(theta_1);


	trajectory_cyl_r.push_back(r_1);

	if (y_1 < 0) {
		trajectory_cyl_rr.push_back(-r_1);
	}
	else if (y_1 >= 0) {

		trajectory_cyl_rr.push_back(r_1);
	}

	Vector_color_trajectory_cyl.push_back(0.0);

	long double phi_2 = 0.0;

	//long double phi_2 = phi_1 + fabs(tan(theta_1)*sin(phi_1 - psi_1)*L_1 / r_1);
	long double psi_2 = 0.0;
	long double theta_2 = 0.0;

	long double r_2 = 0.0;

	if (r_1 > R2_2) {
		//r_2 = r_1 - fabs(L_1*sin(theta_1));
		psi_1 = random(M_PI_2, 3.0*M_PI_2);
		//psi_1 = random(-M_PI_2, M_PI_2);
		//psi_1 = random(0.0, 2.0*M_PI);
	}
	else if (r_1 < R3_2) {
		//r_2 = r_1 - fabs(L_1*sin(theta_1));
		psi_1 = random(-M_PI_2, M_PI_2);
		//psi_1 = random(M_PI_2, 3.0*M_PI_2);
		//psi_1 = random(0.0, 2.0*M_PI);
	}
	else if ((r_1 >= R3_2) && (r_1 <= R2_2)) {

		psi_1 = 2.0*M_PI*random(0.0, 1.0);
		//r_2 = r_1 +fabs(L_1*sin(theta_1))*signum(cos(psi_1));

	}

	//psi_1 = random(0.0, 2.0*M_PI);

	//psi_1 = random(0.0, 2.0*M_PI);
	//long double r_2 = r_1 + L_1*sin(theta_1);

	//cout << r_2 << endl;



	//	long double x_2 = r_2*cos(phi_2);
	//long double y_2 = r_2*sin(phi_2);
	long double x_2 = 0.0;
	long double y_2 = 0.0;

	long double z_2 = L_1;


	long double LL = pow(pow(x_1 - x_2, 2.0) + pow(y_1 - y_2, 2.0) + pow(z_1 - z_2, 2.0), 1.0 / 2.0);  // расстояние между точками

																									   //cout << LL << endl;


																									   //long double theta_2 = theta_1;

																									   //	theta_1 = acos(L_1 / LL);
																									   //	theta_2 = acos(L_1 / LL);



	long double t = fabs(time1_(z_1, z_2, theta_1, V_0));












	func1("left", x_1, y_1, z_1, r_1, theta_1, phi_1, psi_1, x_2, y_2, z_2, r_2, theta_2, phi_2, psi_2, t, V_0, v_phi, v_phi_out, N_CYL_partitions, trajectory_cyl_x, trajectory_cyl_y, trajectory_cyl_z, trajectory_cyl_r, Vector_color_trajectory_cyl, trajectory_cyl_rr, out_trajectory_cyl, trajectory_cyl_phi, trajectory_cyl_psi, trajectory_cyl_theta, trajectory_cyl_v_x, trajectory_cyl_v_y, trajectory_cyl_v_z, trajectory_cyl_v_r, trajectory_cyl_v_phi, trajectory_cyl_v_perp, trajectory_cyl_v_0, trajectory_cyl_force, trajectory_cyl_condition_color, mu_temp, mu_force_temp, flaq_on_off_mu_B, index_condition, particle_mode, trajectory_cyl_mu, trajectory_cyl_B);








	//	long double theta_2 = atan(r_2 / L_1);
	//long double theta_2 = theta_1;

	//	cout << theta_2 << endl;

	//long double theta_2 = asin(pow(random(0.0, 1.0), 1.0 / 2.0));

	//	cout << theta_2 << endl;

	long double d_phi_1_2 = fabs(cos(theta_1)*cos(theta_2)*M_PI*(pow(R2_2, 2.0) - pow(R3_2, 2.0)) / (M_PI*pow(LL, 2.0)));

	phi_1_2 = phi_1_2 + d_phi_1_2;

	x_out = x_2;
	y_out = y_2;
	z_out = z_2;
	r_out = r_2;
	phi_out = phi_2;
	psi_out = psi_2;
	theta_out = theta_2;
	//v_r_out = (r_2 - r_1)*v_z / L_1;
	v_r_out = (2.0*r_1*V_0*cos(phi_1 - psi_1)*sin(theta_1) + 2.0*pow(V_0*sin(theta_1), 2.0)*fabs(z_2 - z_1) / (V_0*cos(theta_1))) / (2.0*r_2);
	//v_r_out = 0.0;
	//v_phi_out = v_phi*r_1 / r_2;

	/*



	if (x_out == 0 && y_out > 0) {

	phi_out = M_PI_2;
	}


	if (x_out == 0 && y_out < 0) {

	phi_out = 3.0*M_PI_2;
	}


	if (y_out == 0 && x_out > 0) {

	phi_out = 0.0;
	}

	if (y_out == 0 && x_out < 0) {

	phi_out = M_PI;
	}

	if (y_out == 0 && x_out == 0) {

	phi_out = 0.0;
	}

	if (x_out > 0 && y_out > 0) {

	phi_out = atan(fabs(y_out / x_out));
	}



	if (x_out < 0 && y_out < 0) {

	phi_out = M_PI + atan(fabs(y_out / x_out));
	}

	if (x_out > 0 && y_out < 0) {

	phi_out = 2.0*M_PI - atan(fabs(y_out / x_out));
	}


	if (x_out < 0 && y_out > 0) {

	phi_out = M_PI - atan(fabs(y_out / x_out));
	}


	*/


	//cout << r_out << endl;
}


void angular_coefficient_2(long double V_0, long double R2_1, long double R3_1, long double R2_2, long double R3_2, long double L_1, long double &x_out, long double &y_out, long double &z_out, long double &r_out, long double &phi_out, long double &psi_out, long double &theta_out, long double &phi_1_2, long double &v_r_out, vector<long double> &trajectory_cyl_x, vector<long double> &trajectory_cyl_y, vector<long double> &trajectory_cyl_z, vector<long double> &trajectory_cyl_r, long double &v_phi_out, vector<long double>&Vector_color_trajectory_cyl, vector<long double> &trajectory_cyl_rr, size_t N_CYL_partitions, long double &x_in_1, long double &y_in_1, long double &z_in_1, long double &r_in_1, vector<long double> &out_trajectory_cyl,
	vector<long double> &trajectory_cyl_phi, vector<long double> &trajectory_cyl_psi, vector<long double> &trajectory_cyl_theta, vector<long double> &trajectory_cyl_v_x, vector<long double> &trajectory_cyl_v_y, vector<long double> &trajectory_cyl_v_z, vector<long double> &trajectory_cyl_v_r, vector<long double> &trajectory_cyl_v_phi, vector<long double> &trajectory_cyl_v_perp, vector<long double> &trajectory_cyl_v_0, long double n_cos_intensity, vector<long double> &trajectory_cyl_force,
	size_t &N_negative_cyl, size_t &N_zero_cyl, size_t &N_positive_cyl, long double mu_particle, long double mu_particle_force, vector<long double> &trajectory_cyl_condition_color, bool flaq_on_off_mu_B, size_t index_condition, size_t particle_mode, vector<long double> &trajectory_cyl_mu, vector<long double> &trajectory_cyl_B, size_t multi_slot_nozzle) {

	long double r_1 = 0.0;

	if (multi_slot_nozzle == 1) {


		r_1 = pow((pow(R3_1, 2.0) + (pow(R2_1, 2.0) - pow(R3_1, 2.0))*random(0.0, 1.0)), 1.0 / 2.0);

	}


	if (multi_slot_nozzle > 1) {

		long double delta_nozzle = fabs(R2_1 - R3_1) / (2.0*multi_slot_nozzle - 1.0);

		long double S_summ_all = 0.0;	   // полная сумма ряда;


		long double *R_min = new long double[multi_slot_nozzle]; // одномерный массив входных параметров
		long double *R_max = new long double[multi_slot_nozzle]; // одномерный массив входных параметров
		long double *S = new long double[multi_slot_nozzle]; // площадь сегмента
		long double *S_summ = new long double[multi_slot_nozzle]; // частичная сумма ряда площадей

		for (size_t i = 0; i < multi_slot_nozzle; i = i + 1) {
			R_min[i] = R3_1 + 2.0*delta_nozzle*i;
			R_max[i] = R3_1 + delta_nozzle + 2.0*delta_nozzle*i;
			S[i] = M_PI * (pow(R_max[i], 2.0) - pow(R_min[i], 2.0));


			if (i == 0) {
				S_summ[i] = S[i];
			}
			if (i >= 1) {


				S_summ[i] = S_summ[i - 1] + S[i];

			}
			S_summ_all = S_summ_all + S[i];

		}




		long double ksi_random = S_summ_all * random(0.0, 1.0);

		for (size_t i = 0; i < multi_slot_nozzle; i = i + 1) {
			if (i == 0) {

				if ((ksi_random >= 0.0) && (ksi_random <= S_summ[i])) {

					r_1 = pow((pow(R_min[i], 2.0) + (pow(R_max[i], 2.0) - pow(R_min[i], 2.0))*random(0.0, 1.0)), 1.0 / 2.0);

				}


			}

			if (i >= 1) {
				if ((ksi_random > S_summ[i - 1]) && (ksi_random <= S_summ[i])) {

					r_1 = pow((pow(R_min[i], 2.0) + (pow(R_max[i], 2.0) - pow(R_min[i], 2.0))*random(0.0, 1.0)), 1.0 / 2.0);

				}
			}

		}



		delete[] R_min;
		delete[] R_max;

		delete[] S;
		delete[] S_summ;

		R_min = nullptr;

		R_max = nullptr;

		S = nullptr;

		S_summ = nullptr;

	}

	//cout << r_1 << endl;

	//	long double r_2 = pow((pow(R3_2, 2.0) + (pow(R2_2, 2.0) - pow(R3_2, 2.0))*random(0.0, 1.0)), 1.0 / 2.0);

	//cout << r_2 << endl;

	long double phi_1 = 2.0*M_PI*random(0.0, 1.0);

	//	long double phi_1 = random(M_PI_4 , M_PI_4+0.01);

	//от 0 до 2*pi равномерно распределена
	//long double theta_1 = asin(pow(random(0.0, 1.0), 1.0 / 2.0));// от 0 до pi/2 распределена по закону cos(theta), получена методом обратной функции, максимум вероятности при theta=0

	//	long double a = min(1.0 / (1.0 + pow(L_1 / fabs(R2_2 - r_1), 2.0)), 1.0 / (1.0 + pow(L_1 / fabs(R3_2 - r_1), 2.0)));
	//	long double b = max(1.0 / (1.0 + pow(L_1 / fabs(R2_2 - r_1), 2.0)), 1.0 / (1.0 + pow(L_1 / fabs(R3_2 - r_1), 2.0)));


	//	long double a = min(pow(sin(atan(fabs(R2_2 - r_1) / L_1)), 2.0), pow(sin(atan(fabs(R3_2 - r_1) / L_1)), 2.0));
	//	long double b = max(pow(sin(atan(fabs(R2_2 - r_1) / L_1)), 2.0), pow(sin(atan(fabs(R3_2 - r_1) / L_1)), 2.0));


	long double a = 0.0;
	long double b = 0.0;

	//	long double a = min(atan(fabs(R2_2 - r_1) / L_1), atan(fabs(R3_2 - r_1) / L_1));
	//	long double b = max(atan(fabs(R2_2 - r_1) / L_1), atan(fabs(R3_2 - r_1) / L_1));


		//long double theta_1 = asin(pow(random(a, b), 1.0 / 2.0));

	long double theta_1 = 0.0;

	//long double theta_1 = asin(pow((cos(2.0*a) - cos(2.0*b))*random(0, 1) / 2.0 + pow(sin(a), 2.0), 1.0 / 2.0));



	//cout << theta_1 << endl;

	//long double	psi_1 = 1.0*M_PI*random(0.0, 1.0)*signum(theta_1);

	long double	psi_1 = 0.0;
	//if (signum(theta_1) < 0) {
	psi_1 = random(0.0, M_PI);

	//}
	//else
	//{
	//	psi_1 = 2.0*M_PI*random(0.0,1.0 );
	//}

	//psi_1 = random(0.0, 2.0*M_PI);



	//cout << theta_1 << endl;



	long double x_1 = r_1 * cos(phi_1);
	long double y_1 = r_1 * sin(phi_1);
	long double z_1 = 0.0;




	trajectory_cyl_x.push_back(x_1);
	trajectory_cyl_y.push_back(y_1);
	trajectory_cyl_z.push_back(z_1);
	trajectory_cyl_force.push_back(0.0);

	const long double mu_bor = 5.788381806638*pow(10.0, 13.0)*pow(2.99792458, 2.0); // магнетон Бора электронный в единицах эВ/Гс*(скорость света [мм/c])^2

	long double temp_random = random(0.0, 1.0);																				//	const long double mu_bor = 3.152451260522*pow(10.0, 10.0)*pow(2.99792458, 2.0); // магнетон Бора ядерный в единицах эВ/Гс*(скорость света [мм/c])^2


	const long double mu_bor_force = 9.2740096820*pow(10.0, 0.0);


	/*

	long double mu_particle = 0.0;
	long double mu_particle_force = 0.0;

	long double B_temp = 0.001;
	long double mu_temp_temp = 0.0;
	long double E_temp_temp = 0.0;



	if (flaq_on_off_mu_B == false) {
		mu_particle = mu_temp;
		mu_particle_force = mu_force_temp;
	}
	if (flaq_on_off_mu_B == true) {


		//	cout << index_condition << endl;

		if (particle_mode == 1) {
			mu_particle = mu_H(index_condition, B_temp, mu_temp_temp, E_temp_temp)*mu_bor;
			mu_particle_force = mu_H(index_condition, B_temp, mu_temp_temp, E_temp_temp)*mu_bor_force;
		}

		if (particle_mode == 2) {

			mu_particle = mu_D(index_condition, B_temp, mu_temp_temp, E_temp_temp)*mu_bor;
			mu_particle_force = mu_D(index_condition, B_temp, mu_temp_temp, E_temp_temp)*mu_bor_force;
		}

		if (particle_mode == 3) {
			mu_particle = mu_H_2(index_condition, B_temp, mu_temp_temp, E_temp_temp)*mu_bor;
			mu_particle_force = mu_H_2(index_condition, B_temp, mu_temp_temp, E_temp_temp)*mu_bor_force;

		}

		if (particle_mode == 4) { //-V112

			mu_particle = mu_D_2(index_condition, B_temp, mu_temp_temp, E_temp_temp)*mu_bor;
			mu_particle_force = mu_D_2(index_condition, B_temp, mu_temp_temp, E_temp_temp)*mu_bor_force;

		}

	}


	*/


	if (mu_particle > 0.0) {
		trajectory_cyl_condition_color.push_back(11.0);
	}
	if (fabs(mu_particle - 0.0) <= epsilon) {
		trajectory_cyl_condition_color.push_back(10.0);
	}
	if (mu_particle < 0.0) {
		trajectory_cyl_condition_color.push_back(-11.0);
	}


	trajectory_cyl_mu.push_back(mu_particle / mu_bor);
	trajectory_cyl_B.push_back(0.0);

	//	trajectory_cyl_phi.push_back(phi_1);
	//	trajectory_cyl_psi.push_back(psi_1);
	//	trajectory_cyl_theta.push_back(theta_1);

	trajectory_cyl_r.push_back(r_1);

	x_in_1 = x_1;
	y_in_1 = y_1;
	z_in_1 = z_1;
	r_in_1 = r_1;



	if (y_1 < 0) {
		trajectory_cyl_rr.push_back(-r_1);
	}
	else if (y_1 >= 0) {

		trajectory_cyl_rr.push_back(r_1);
	}

	Vector_color_trajectory_cyl.push_back(0.0);

	out_trajectory_cyl.push_back(0.0);

	long double phi_2 = random(0.0, 2.0*M_PI);

	//long double phi_2 = random(M_PI_4, M_PI_4 + 0.01);



	//long double phi_2 = phi_1 + fabs(tan(theta_1)*sin(phi_1 - psi_1)*L_1 / r_1);
	long double psi_2 = 0.0;
	long double theta_2 = 0.0;

	long double r_2 = 0.0;







	if (r_1 > R2_2) {


		a = min(atan(fabs(R2_2 - r_1) / L_1), atan(fabs(R3_2 - r_1) / L_1));
		b = max(atan(fabs(R2_2 - r_1) / L_1), atan(fabs(R3_2 - r_1) / L_1));


		//theta_1 = asin(pow((cos(2.0*a) - cos(2.0*b))*random(0, 1) / 2.0 + pow(sin(a), 2.0), 1.0 / 2.0));


		theta_1 = acos(pow(pow(cos(a), n_cos_intensity + 1.0) + (pow(cos(b), n_cos_intensity + 1.0) - pow(cos(a), n_cos_intensity + 1.0))*random(0, 1), 1.0 / (n_cos_intensity + 1.0)));

		//r_2 = r_1 - fabs(L_1*sin(theta_1));

		r_2 = r_1 - fabs(L_1*tan(theta_1));





		//psi_1 = random(M_PI_2, 3.0*M_PI_2);
		//psi_1 = random(0.0, 2.0*M_PI);
	}
	else if (r_1 < R3_2) {

		a = min(atan(fabs(R2_2 - r_1) / L_1), atan(fabs(R3_2 - r_1) / L_1));
		b = max(atan(fabs(R2_2 - r_1) / L_1), atan(fabs(R3_2 - r_1) / L_1));


		//theta_1 = asin(pow((cos(2.0*a) - cos(2.0*b))*random(0, 1) / 2.0 + pow(sin(a), 2.0), 1.0 / 2.0));


		theta_1 = acos(pow(pow(cos(a), n_cos_intensity + 1.0) + (pow(cos(b), n_cos_intensity + 1.0) - pow(cos(a), n_cos_intensity + 1.0))*random(0, 1), 1.0 / (n_cos_intensity + 1.0)));



		//r_2 = r_1 + fabs(L_1*sin(theta_1));
		r_2 = r_1 + fabs(L_1*tan(theta_1));




		//psi_1 = random(-M_PI_2, M_PI_2);
		//psi_1 = random(0.0, 2.0*M_PI);
	}
	else if ((r_1 >= R3_2) && (r_1 <= R2_2)) {

		//	cout << R3_2 << endl << R2_2 << endl;


		//	long double temp_r = fabs(R2_2- R3_2);

		//	if (r_1 > temp_r) {

	//	if (signum(cos(psi_1)) > 0) {

		if (temp_random <= 0.5) {


			a = 0.0;
			b = atan(fabs(R2_2 - r_1) / L_1);



			//	a = min(atan(fabs(R2_2 - r_1) / L_1), atan(fabs(R3_2 - r_1) / L_1));
			//	b = max(atan(fabs(R2_2 - r_1) / L_1), atan(fabs(R3_2 - r_1) / L_1));


				//theta_1 = asin(pow((cos(2.0*a) - cos(2.0*b))*random(0, 1) / 2.0 + pow(sin(a), 2.0), 1.0 / 2.0));


			theta_1 = acos(pow(pow(cos(a), n_cos_intensity + 1.0) + (pow(cos(b), n_cos_intensity + 1.0) - pow(cos(a), n_cos_intensity + 1.0))*random(0, 1), 1.0 / (n_cos_intensity + 1.0)));




			//psi_1 = random(0.0, 2.0*M_PI);
			//r_2 = r_1 + fabs(L_1*sin(theta_1))*signum(cos(psi_1));
			//r_2 = r_1 + fabs(L_1*tan(theta_1))*signum(cos(psi_1));

			r_2 = r_1 + fabs(L_1*tan(theta_1));




		}
		else {


			a = 0.0;
			b = atan(fabs(R3_2 - r_1) / L_1);


			theta_1 = acos(pow(pow(cos(a), n_cos_intensity + 1.0) + (pow(cos(b), n_cos_intensity + 1.0) - pow(cos(a), n_cos_intensity + 1.0))*random(0, 1), 1.0 / (n_cos_intensity + 1.0)));

			r_2 = r_1 - fabs(L_1*tan(theta_1));

		}




		//	}



			/*


			else {

				if (signum(cos(psi_1)) > 0) {


					a = 0.0;
					b = atan(fabs(R2_2 - r_1) / L_1);



					//	a = min(atan(fabs(R2_2 - r_1) / L_1), atan(fabs(R3_2 - r_1) / L_1));
					//	b = max(atan(fabs(R2_2 - r_1) / L_1), atan(fabs(R3_2 - r_1) / L_1));


					//theta_1 = asin(pow((cos(2.0*a) - cos(2.0*b))*random(0, 1) / 2.0 + pow(sin(a), 2.0), 1.0 / 2.0));


					theta_1 = acos(pow(pow(cos(a), n_cos_intensity + 1.0) + (pow(cos(b), n_cos_intensity + 1.0) - pow(cos(a), n_cos_intensity + 1.0))*random(0, 1), 1.0 / (n_cos_intensity + 1.0)));




					//psi_1 = random(0.0, 2.0*M_PI);
					//r_2 = r_1 + fabs(L_1*sin(theta_1))*signum(cos(psi_1));
					//r_2 = r_1 + fabs(L_1*tan(theta_1))*signum(cos(psi_1));

					r_2 = r_1 + fabs(L_1*tan(theta_1));




				}
				else {


					a = 0.0;
					b = atan(fabs(R3_2 - r_1) / L_1);


					theta_1 = acos(pow(pow(cos(a), n_cos_intensity + 1.0) + (pow(cos(b), n_cos_intensity + 1.0) - pow(cos(a), n_cos_intensity + 1.0))*random(0, 1), 1.0 / (n_cos_intensity + 1.0)));

					r_2 = r_1 - fabs(L_1*tan(theta_1));

				}



			}



		}



	  */


	  /*

	   if (r_2 > R2_2) {

		   cout << r_2 << endl;
	   }

	   if (r_2 < R3_2) {

		   cout << r_2 << endl;
	   }

	   */

	}





	r_2 = pow((pow(R3_2, 2.0) + (pow(R2_2, 2.0) - pow(R3_2, 2.0))*random(0.0, 1.0)), 1.0 / 2.0);


	//psi_1 = random(0.0, 2.0*M_PI);

	//psi_1 = random(0.0, 2.0*M_PI);
	//long double r_2 = r_1 + L_1*sin(theta_1);

	//cout << r_2 << endl;



	long double x_2 = r_2 * cos(phi_2);
	long double y_2 = r_2 * sin(phi_2);
	//long double x_2 = 0.0;
	//long double y_2 = 0.0;

	long double z_2 = L_1;




	//	long double t = fabs(time1_(z_1, z_2, theta_1, V_0));












	//func1("left", x_1, y_1, z_1, r_1, theta_1, phi_1, psi_1, x_2, y_2, z_2, r_2, theta_2, phi_2, psi_2, t, V_0, v_phi, v_phi_out);





	long double LL = pow(pow(x_1 - x_2, 2.0) + pow(y_1 - y_2, 2.0) + pow(z_1 - z_2, 2.0), 1.0 / 2.0);  // расстояние между точками

																									   //cout << LL << endl;


																									   //long double theta_2 = theta_1;





																									   //long double theta_1 = acos(L_1 / LL);
	long double r_psi = pow(pow(x_2 - x_1, 2.0) + pow(y_2 - y_1, 2.0), 1.0 / 2.0);


	theta_2 = acos(L_1 / LL);

	theta_1 = theta_2;





	//	long double theta_2 = atan(r_2 / L_1);
	//long double theta_2 = theta_1;
	//psi_2 = fabs(acos(cos(phi_1 - phi_2)));

	//	psi_2 = fabs(acos((x_2 - x_1) / (z_2 - z_1) / tan(theta_2)));


	//	psi_2 = fabs(acos((x_2-x_1)/(r_2-r_1)));


	//psi_2 = fabs(acos((x_2 - x_1) / r_psi));

	//cout << (x_2 - x_1) / (r_2 - r_1) << endl;

	long double v_x = x_2 - x_1;
	long double v_y = y_2 - y_1;

	/*



	if (v_x > 0 && v_y > 0) {

	psi_2 = psi_2;

	}


	if (v_x < 0 && v_y < 0) {

	psi_2 = psi_2+M_PI;

	}


	if (v_x > 0 && v_y < 0) {


	psi_2 = 3.0*M_PI_2-psi_2;


	}


	if (v_x < 0 && v_y > 0) {

	psi_2 = M_PI - psi_2;

	}


	*/

	long double dx = x_2 - x_1;
	long double dy = y_2 - y_1;


	if (dx >= 0 && dy >= 0) {

		//	psi_out = fabs(asin((dx)*v_z / (V_0*h_z*sin(theta))));

		psi_2 = fabs(atan(dy / dx));
	}



	if (dx < 0 && dy < 0) {

		//	psi_out = M_PI + fabs(asin((dx)*v_z / (V_0*h_z*sin(theta))));

		psi_2 = 1.0*M_PI + fabs(atan(dy / dx));

	}

	if (dx > 0 && dy < 0) {

		//	psi_out = 2.0*M_PI - fabs(asin((dx)*v_z / (V_0*h_z*sin(theta))));

		psi_2 = 2.0*M_PI - fabs(atan(dy / dx));

	}


	if (dx < 0 && dy > 0) {

		//	psi_out = M_PI - fabs(asin((dx)*v_z / (V_0*h_z*sin(theta))));

		psi_2 = M_PI - fabs(atan(dy / dx));

	}


	//psi_2 =random(0.0,2.0*M_PI);



	//	psi_2 = acos((x_2 - x_1) / r_psi)*signum(asin((y_2 - y_1) / r_psi));

	long double phi = phi_1;
	long double psi = psi_1;
	long double theta = theta_1;




	psi_1 = psi_2;

	psi = psi_1;

	theta = theta_1;

	trajectory_cyl_phi.push_back(phi_1);
	trajectory_cyl_psi.push_back(psi_1);
	trajectory_cyl_theta.push_back(theta_1);

	trajectory_cyl_v_x.push_back(V_0*sin(theta_1)*cos(psi_1));
	trajectory_cyl_v_y.push_back(V_0*sin(theta_1)*sin(psi_1));
	trajectory_cyl_v_z.push_back(V_0*cos(theta_1));
	trajectory_cyl_v_r.push_back(V_0*sin(theta_1)*cos(phi_1 - psi_1));
	trajectory_cyl_v_phi.push_back(V_0*sin(theta_1)*sin(phi_1 - psi_1));
	trajectory_cyl_v_perp.push_back(V_0*sin(theta_1));
	trajectory_cyl_v_0.push_back(V_0);


	//	cout << theta_2 << endl;
	//psi_2 = phi_2;
	//long double theta_2 = asin(pow(random(0.0, 1.0), 1.0 / 2.0));
	long double v_z = V_0 * cos(theta_1);

	long double v_phi = V_0 * sin(theta_1)*sin(phi_1 - psi_1);
	//	cout << theta_2 << endl;

	long double d_phi_1_2 = fabs(cos(theta_2)*cos(theta_2)*M_PI*(pow(R2_2, 2.0) - pow(R3_2, 2.0)) / (M_PI*pow(LL, 2.0)));

	phi_1_2 = phi_1_2 + d_phi_1_2;

	x_out = x_2;
	y_out = y_2;
	z_out = z_2;
	r_out = r_2;
	phi_out = phi_2;
	psi_out = psi_2;
	theta_out = theta_2;
	//v_r_out = (r_2 - r_1)*v_z / L_1;
	v_r_out = (2.0*r_1*V_0*cos(phi_1 - psi_1)*sin(theta_1) + 2.0*pow(V_0*sin(theta_1), 2.0)*fabs(z_2 - z_1) / (V_0*cos(theta_1))) / (2.0*r_2);
	//v_r_out = 0.0;
	v_phi_out = v_phi * r_1 / r_2;

	/*



	if (x_out == 0 && y_out > 0) {

	phi_out = M_PI_2;
	}


	if (x_out == 0 && y_out < 0) {

	phi_out = 3.0*M_PI_2;
	}


	if (y_out == 0 && x_out > 0) {

	phi_out = 0.0;
	}

	if (y_out == 0 && x_out < 0) {

	phi_out = M_PI;
	}

	if (y_out == 0 && x_out == 0) {

	phi_out = 0.0;
	}

	if (x_out > 0 && y_out > 0) {

	phi_out = atan(fabs(y_out / x_out));
	}



	if (x_out < 0 && y_out < 0) {

	phi_out = M_PI + atan(fabs(y_out / x_out));
	}

	if (x_out > 0 && y_out < 0) {

	phi_out = 2.0*M_PI - atan(fabs(y_out / x_out));
	}


	if (x_out < 0 && y_out > 0) {

	phi_out = M_PI - atan(fabs(y_out / x_out));
	}


	*/

	long double x = x_1;
	long double y = y_1;
	long double z = z_1;
	long double r = r_1;

	long double h_z = fabs(z_2 - z_1) / (N_CYL_partitions + 1);

	for (size_t i = 0; i <= N_CYL_partitions - 1; i = i + 1) {

		if (N_CYL_partitions == 0) {

			i = 1;
			break;

		}



		x = x + tan(theta_1)*cos(psi_1)*h_z;
		y = y + tan(theta_1)*sin(psi_1)*h_z;
		z = z + h_z;
		r = pow(pow(x, 2.0) + pow(y, 2.0), 1.0 / 2.0);



		trajectory_cyl_x.push_back(x);
		trajectory_cyl_y.push_back(y);
		trajectory_cyl_z.push_back(z);
		trajectory_cyl_force.push_back(0.0);

		if (mu_particle > 0.0) {
			trajectory_cyl_condition_color.push_back(11.0);
		}
		if (fabs(mu_particle - 0.0) <= epsilon) {
			trajectory_cyl_condition_color.push_back(10.0);
		}
		if (mu_particle < 0.0) {
			trajectory_cyl_condition_color.push_back(-11.0);
		}

		trajectory_cyl_mu.push_back(mu_particle / mu_bor);
		trajectory_cyl_B.push_back(0.0);

		if (fabs(x - 0.0) <= epsilon && y > 0) {

			phi = M_PI_2;
		}


		if (fabs(x - 0.0) <= epsilon && y < 0) {

			phi = 3.0*M_PI_2;
		}


		if (fabs(y - 0.0) <= epsilon && x > 0) {

			phi = 0.0;
		}

		if (fabs(y - 0.0) <= epsilon && x < 0) {

			phi = M_PI;
		}

		if (fabs(y - 0.0) <= epsilon && fabs(x - 0.0) <= epsilon) {

			phi = 0.0;
		}

		if (x > 0 && y > 0) {

			phi = atan(fabs(y / x));
		}



		if (x < 0 && y < 0) {

			phi = M_PI + atan(fabs(y / x));
		}

		if (x > 0 && y < 0) {

			phi = 2.0*M_PI - atan(fabs(y / x));
		}


		if (x < 0 && y > 0) {

			phi = M_PI - atan(fabs(y / x));
		}




		trajectory_cyl_phi.push_back(phi);
		trajectory_cyl_psi.push_back(psi);
		trajectory_cyl_theta.push_back(theta);


		trajectory_cyl_v_x.push_back(V_0*sin(theta)*cos(psi));
		trajectory_cyl_v_y.push_back(V_0*sin(theta)*sin(psi));
		trajectory_cyl_v_z.push_back(V_0*cos(theta));
		trajectory_cyl_v_r.push_back(V_0*sin(theta)*cos(phi - psi));
		trajectory_cyl_v_phi.push_back(V_0*sin(theta)*sin(phi - psi));
		trajectory_cyl_v_perp.push_back(V_0*sin(theta));
		trajectory_cyl_v_0.push_back(V_0);


		trajectory_cyl_r.push_back(r);

		if (y < 0) {
			trajectory_cyl_rr.push_back(-r);
		}
		else if (y >= 0) {
			trajectory_cyl_rr.push_back(r);
		}

		Vector_color_trajectory_cyl.push_back(0.0);

		out_trajectory_cyl.push_back(0.0);

	}




	trajectory_cyl_x.push_back(x_out);
	trajectory_cyl_y.push_back(y_out);
	trajectory_cyl_z.push_back(z_out);
	trajectory_cyl_force.push_back(0.0);





	if (mu_particle > 0.0) {
		trajectory_cyl_condition_color.push_back(11.0);
	}
	if (fabs(mu_particle - 0.0) <= epsilon) {
		trajectory_cyl_condition_color.push_back(10.0);
	}
	if (mu_particle < 0.0) {
		trajectory_cyl_condition_color.push_back(-11.0);
	}

	trajectory_cyl_mu.push_back(mu_particle / mu_bor);
	trajectory_cyl_B.push_back(0.0);


	trajectory_cyl_phi.push_back(phi_out);
	trajectory_cyl_psi.push_back(psi_out);
	trajectory_cyl_theta.push_back(theta_out);

	trajectory_cyl_v_x.push_back(V_0*sin(theta_out)*cos(psi_out));
	trajectory_cyl_v_y.push_back(V_0*sin(theta_out)*sin(psi_out));
	trajectory_cyl_v_z.push_back(V_0*cos(theta_out));
	trajectory_cyl_v_r.push_back(V_0*sin(theta_out)*cos(phi_out - psi_out));
	trajectory_cyl_v_phi.push_back(V_0*sin(theta_out)*sin(phi_out - psi_out));
	trajectory_cyl_v_perp.push_back(V_0*sin(theta_out));
	trajectory_cyl_v_0.push_back(V_0);


	trajectory_cyl_r.push_back(r_out);



	if (y_out < 0) {
		trajectory_cyl_rr.push_back(-r_out);
	}
	else if (y_out >= 0) {

		trajectory_cyl_rr.push_back(r_out);
	}

	Vector_color_trajectory_cyl.push_back(0.0);

	out_trajectory_cyl.push_back(1.0);


	long double mu_temp_temp = 0.0;
	long double mu_temp = 0.0;
	long double mu_force_temp = 0.0;
	long double E_temp_temp = 0.0;
	long double mu_particle_temp = 0.0;
	long double mu_particle_force_temp = 0.0;


	const long double mu_bor_1 = 5.788381806638*pow(10.0, 13.0)*pow(2.99792458, 2.0); // магнетон Бора электронный в единицах эВ/Гс*(скорость света [мм/c])^2

																					//	const long double mu_bor = 3.152451260522*pow(10.0, 10.0)*pow(2.99792458, 2.0); // магнетон Бора ядерный в единицах эВ/Гс*(скорость света [мм/c])^2


	const long double mu_bor_force_1 = 9.2740096820*pow(10.0, 0.0);



	if (flaq_on_off_mu_B == false) {
		mu_particle_temp = mu_temp;
		mu_particle_force_temp = mu_force_temp;

		//cout << fabs(mu_particle / mu_bor) << endl;
	}
	if (flaq_on_off_mu_B == true) {




		//	cout << index_condition << endl;

		if (particle_mode == 1) {
			mu_particle_temp = mu_H(index_condition, B_MAX, mu_temp_temp, E_temp_temp)*mu_bor_1;
			mu_particle_force_temp = mu_H(index_condition, B_MAX, mu_temp_temp, E_temp_temp)*mu_bor_force_1;
		}

		if (particle_mode == 2) {

			mu_particle_temp = mu_D(index_condition, B_MAX, mu_temp_temp, E_temp_temp)*mu_bor_1;
			mu_particle_force_temp = mu_D(index_condition, B_MAX, mu_temp_temp, E_temp_temp)*mu_bor_force_1;
		}

		if (particle_mode == 3) {
			mu_particle_temp = mu_H_2(index_condition, B_MAX, mu_temp_temp, E_temp_temp)*mu_bor_1;
			mu_particle_force_temp = mu_H_2(index_condition, B_MAX, mu_temp_temp, E_temp_temp)*mu_bor_force_1;

		}

		if (particle_mode == 4) { //-V112

			mu_particle_temp = mu_D_2(index_condition, B_MAX, mu_temp_temp, E_temp_temp)*mu_bor_1;
			mu_particle_force_temp = mu_D_2(index_condition, B_MAX, mu_temp_temp, E_temp_temp)*mu_bor_force_1;

		}

	}





	if (mu_particle_temp > 0.0 && mu_particle_force_temp > 0.0) {
		N_positive_cyl = N_positive_cyl + 1;

	}

	if (mu_particle_temp < 0.0 && mu_particle_force_temp < 0.0) {
		N_negative_cyl = N_negative_cyl + 1;

	}
	if (fabs(mu_particle_temp - 0.0) <= epsilon && fabs(mu_particle_force_temp - 0.0) <= epsilon) { //-V550
		N_zero_cyl = N_zero_cyl + 1;

	}

	//cout << r_out << endl;
}


void MaximizeWindow()
{
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
	SMALL_RECT rc;
	rc.Left = rc.Top = 0;
	rc.Right = (short)(min(info.dwMaximumWindowSize.X, info.dwSize.X) - 1);
	rc.Bottom = (short)(min(info.dwMaximumWindowSize.Y, info.dwSize.Y) - 1);
	SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), true, &rc);
}


long double P_z(size_t N_negative, size_t N_zero, size_t N_positive) {

	//cout << N_negative << endl;
	//cout << N_positive << endl;
	//cout << N_zero << endl;

	long double P_z = 0.0;
	if ((N_positive + N_negative + N_zero) != 0) {
		P_z = (long double)(N_positive - N_negative) / (long double)(N_positive + N_negative + N_zero);
	}
	else {

		P_z = 0.0;

	}


	return P_z;

}

long double P_z_error(size_t N_negative, size_t N_zero, size_t N_positive, size_t еrrоr_symm_type) {

	//cout << N_negative << endl;
	//cout << N_positive << endl;
	//cout << N_zero << endl;

	long double P_z_error = 0.0;

	long double d_N_positive = pow(N_positive, 1.0 / 2.0);
	long double d_N_zero = pow(N_zero, 1.0 / 2.0);
	long double d_N_negative = pow(N_negative, 1.0 / 2.0);

	if ((N_positive + N_negative + N_zero) != 0) {

		if (еrrоr_symm_type == 1) {

			P_z_error = d_N_positive * (1.0 / (long double)(N_positive + N_negative + N_zero) + fabs(N_positive - N_negative) / pow(N_positive + N_negative + N_zero, 2.0)) + d_N_negative * (1.0 / (long double)(N_positive + N_negative + N_zero) + fabs(N_positive - N_negative) / pow(N_positive + N_negative + N_zero, 2.0)) + d_N_zero * (fabs(N_positive - N_negative) / pow(N_positive + N_negative + N_zero, 2.0));

		}

		if (еrrоr_symm_type == 2) {

			P_z_error = pow(pow(d_N_positive*(1.0 / (long double)(N_positive + N_negative + N_zero) + fabs(N_positive - N_negative) / pow(N_positive + N_negative + N_zero, 2.0)), 2.0) + pow(d_N_negative*(1.0 / (long double)(N_positive + N_negative + N_zero) + fabs(N_positive - N_negative) / pow(N_positive + N_negative + N_zero, 2.0)), 2.0) + pow(d_N_zero*(fabs(N_positive - N_negative) / pow(N_positive + N_negative + N_zero, 2.0)), 2.0), 1.0 / 2.0);

		}

	}
	else {

		P_z_error = 0.0;

	}

	if (fabs(P_z(N_negative, N_zero, N_positive) - 1.0) <= epsilon) {

		P_z_error = 0.0;

	}


	return P_z_error;

}


long double P_zz(size_t N_negative, size_t N_zero, size_t N_positive) {

	long double P_zz = 0.0;

	long double n_negative = 0.0;
	long double n_zero = 0.0;
	long double n_positive = 0.0;


	if ((N_positive + N_negative + N_zero) != 0) {

		n_negative = (long double)N_negative / (long double)(N_negative + N_zero + N_positive);
		n_zero = (long double)N_zero / (long double)(N_negative + N_zero + N_positive);
		n_positive = (long double)N_positive / (long double)(N_negative + N_zero + N_positive);

	}

	if ((n_positive + n_negative + n_zero) != 0) { //-V550

		P_zz = (1.0 - 3.0*n_zero) / (n_negative + n_zero + n_positive);
	}
	else {

		P_zz = 0.0;

	}
	return P_zz;

}

long double P_zz_error(size_t N_negative, size_t N_zero, size_t N_positive, size_t еrrоr_symm_type) {

	long double P_zz_error = 0.0;

	long double n_negative = 0.0;
	long double n_zero = 0.0;
	long double n_positive = 0.0;


	long double d_N_positive = pow(N_positive, 1.0 / 2.0);
	long double d_N_zero = pow(N_zero, 1.0 / 2.0);
	long double d_N_negative = pow(N_negative, 1.0 / 2.0);

	if ((N_positive + N_negative + N_zero) != 0) {

		n_negative = (long double)N_negative / (long double)(N_negative + N_zero + N_positive);
		n_zero = (long double)N_zero / (long double)(N_negative + N_zero + N_positive);
		n_positive = (long double)N_positive / (long double)(N_negative + N_zero + N_positive);



	}

	if ((n_positive + n_negative + n_zero) != 0) { //-V550

		if (еrrоr_symm_type == 1)

			//	P_zz_error = d_N_zero / pow(N_positive + N_negative + N_zero, 2.0) + 3.0*d_N_zero*(1.0 / (long double)(N_negative + N_zero + N_positive) + N_zero / pow(N_positive + N_negative + N_zero, 2.0));
			P_zz_error = 3.0*d_N_zero*(1.0 / (long double)(N_negative + N_zero + N_positive) + N_zero / pow(N_positive + N_negative + N_zero, 2.0)) + 3.0*d_N_positive*(N_zero / pow(N_negative + N_zero + N_positive, 2.0)) + 3.0*d_N_negative*(N_zero / pow(N_negative + N_zero + N_positive, 2.0));
	}

	if (еrrоr_symm_type == 2) {

		P_zz_error = pow(pow(3.0*d_N_zero*(1.0 / (long double)(N_negative + N_zero + N_positive) + N_zero / pow(N_positive + N_negative + N_zero, 2.0)), 2.0) + pow(3.0*d_N_positive*(N_zero / pow(N_negative + N_zero + N_positive, 2.0)), 2.0) + pow(3.0*d_N_negative*(N_zero / pow(N_negative + N_zero + N_positive, 2.0)), 2.0), 1.0 / 2.0);


	}
	else {

		P_zz_error = 0.0;

	}
	return P_zz_error;

}

long double FM_1(size_t N_negative, size_t N_zero, size_t N_positive) {

	//cout << N_negative << endl;
	//cout << N_positive << endl;
	//cout << N_zero << endl;

	long double FM = 0.0;
	if ((N_positive + N_negative + N_zero) != 0) {

		FM = pow(P_z(N_negative, N_zero, N_positive), 2.0)*(long double)(N_negative + N_zero + N_positive);
	}
	else {

		FM = 0.0;

	}


	return FM;

}

long double FM_1_error(size_t N_negative, size_t N_zero, size_t N_positive, size_t еrrоr_symm_type) {

	//cout << N_negative << endl;
	//cout << N_positive << endl;
	//cout << N_zero << endl;

	long double FM_error = 0.0;

	long double d_N_positive = pow(N_positive, 1.0 / 2.0);
	long double d_N_zero = pow(N_zero, 1.0 / 2.0);
	long double d_N_negative = pow(N_negative, 1.0 / 2.0);

	if ((N_positive + N_negative + N_zero) != 0) {

		if (еrrоr_symm_type == 1)
		{


			FM_error = 2.0*P_z(N_negative, N_zero, N_positive)*P_z_error(N_negative, N_zero, N_positive, еrrоr_symm_type)*(N_negative + N_zero + N_positive) + pow(P_z(N_negative, N_zero, N_positive), 2.0)*(pow(N_negative, 1.0 / 2.0) + pow(N_zero, 1.0 / 2.0) + pow(N_positive, 1.0 / 2.0));

		}

		if (еrrоr_symm_type == 2) {

			FM_error = pow(pow(2.0*P_z(N_negative, N_zero, N_positive)*P_z_error(N_negative, N_zero, N_positive, еrrоr_symm_type)*(N_negative + N_zero + N_positive), 2.0) + pow(pow(P_z(N_negative, N_zero, N_positive), 2.0)*pow(N_negative + N_zero + N_positive, 1.0 / 2.0), 2.0), 1.0 / 2.0);


		}

	}
	else {

		FM_error = 0.0;

	}


	return FM_error;

}




long double FM_2(size_t N_negative, size_t N_zero, size_t N_positive) {

	//cout << N_negative << endl;
	//cout << N_positive << endl;
	//cout << N_zero << endl;

	long double FM = 0.0;
	if ((N_positive + N_negative + N_zero) != 0) {

		FM = P_z(N_negative, N_zero, N_positive)*(long double)(N_negative + N_zero + N_positive);
	}
	else {

		FM = 0.0;

	}


	return FM;

}

long double FM_2_error(size_t N_negative, size_t N_zero, size_t N_positive, size_t еrrоr_symm_type) {

	//cout << N_negative << endl;
	//cout << N_positive << endl;
	//cout << N_zero << endl;

	long double FM_error = 0.0;

	long double d_N_positive = pow(N_positive, 1.0 / 2.0);
	long double d_N_zero = pow(N_zero, 1.0 / 2.0);
	long double d_N_negative = pow(N_negative, 1.0 / 2.0);

	if ((N_positive + N_negative + N_zero) != 0) {

		if (еrrоr_symm_type == 1) {



			FM_error = P_z_error(N_negative, N_zero, N_positive, еrrоr_symm_type)*(N_negative + N_zero + N_positive) + P_z(N_negative, N_zero, N_positive)*(pow(N_negative, 1.0 / 2.0) + pow(N_zero, 1.0 / 2.0) + pow(N_positive, 1.0 / 2.0));

		}

		if (еrrоr_symm_type == 2) {




			FM_error = pow(pow(P_z_error(N_negative, N_zero, N_positive, еrrоr_symm_type)*(N_negative + N_zero + N_positive), 2.0) + pow(P_z(N_negative, N_zero, N_positive)*pow(N_negative + N_zero + N_positive, 1.0 / 2.0), 2.0), 1.0 / 2.0);
		}


	}
	else {

		FM_error = 0.0;

	}


	return FM_error;

}


void set_priority() {


	DWORD dwError, dwPriClass;


	if (!SetPriorityClass(GetCurrentProcess(), HIGH_PRIORITY_CLASS))
	{
		dwError = GetLastError();
		if (ERROR_PROCESS_MODE_ALREADY_BACKGROUND == dwError)
			_tprintf(TEXT("Already in HIGH_PRIORITY mode\n"));
		else _tprintf(TEXT("Failed to enter HIGH_PRIORITY mode (%d)\n"), dwError);
		goto Cleanup;
	}


	// Display priority class


	dwPriClass = GetPriorityClass(GetCurrentProcess());


	_tprintf(TEXT("Current priority class is 0x%x\n"), dwPriClass);


	//
	// Perform background work
	//
	;


	if (!SetPriorityClass(GetCurrentProcess(), HIGH_PRIORITY_CLASS))
	{
		_tprintf(TEXT("Failed to end HIGH_PRIORITY mode (%d)\n"), GetLastError());
	}


Cleanup:
	// Clean up
	;





}


int _tmain(int argc, _TCHAR* argv[]) { //-V553 //-V2008

	MaximizeWindow();

	//set_priority(); // установка высокого приоритета процесса

	//	cout << mu_H_2(0, 37000.0) << " " << 0 << endl;
	//	cout << mu_H_2(1, 37000.0) << " " << 1 << endl;
	//	cout << mu_H_2(2, 37000.0) << " " << 2 << endl;
	//	cout << mu_H_2(3, 37000.0) << " " << 3 << endl;
	//	cout << mu_H_2(4, 37000.0) << " " << 4 << endl;
	//	cout << mu_H_2(5, 37000.0) << " " << 5 << endl;
	//	cout << mu_H_2(6, 37000.0) << " " << 6 << endl;
	//	cout << mu_H_2(7, 37000.0) << " " << 7 << endl;
	//	cout << mu_H_2(8, 50.0) << " " << 8 << endl;
	//	cout << mu_H_2(9, 37000.0) << " " << 9 << endl;
	//	cout << mu_H_2(10, 37000.0) << " " << 10 << endl;
	//	cout << mu_H_2(11, 37000.0) << " " << 11 << endl;


	//out_mu_H_2("out_mu_H_2.txt", 0.001, 3000.0, 50000);


	//cout << sizeof(25) << endl;

	setlocale(LC_ALL, "rus"); // корректное отображение Кириллицы
	cout << endl;
	cout << "Добро Пожаловать В Программу CYL.EXE" << endl;

	cout << endl;
	ReadFile_("CYL.txt");
	cout << endl;

	cout << "Решите правильно уравнение для отображения пасхалки об авторе..." << endl;
	cout << "Сколько будет 1+1= ?" << endl;
	cout << endl;
	long double koren = 0.0;
	cout << "Введите свой ответ и нажмите Enter" << endl;
	cout << endl;
	cin >> koren;
	cout << endl;

	if (koren == 2.0) { //-V550

		cout << "Вы решиле правильно уравнение и увидите пасхалку" << endl;
		SleepEx(40, true); // пауза для того, чтобы успеть прочитать информацию

		ReadFile_("ars.txt");

	}
	else {



		cout << "Вы решиле неправильно уравнение и не увидите пасхалку" << endl;
		SleepEx(40, true); // пауза для того, чтобы успеть прочитать информацию

	}

	//	cout << endl;
	cout << endl;


	//const long double a = 0.0; // границы распределения модулю скорости по Максвеллу, мм/сек
	//const long double b = pow(10.0,9.0);


	long double R1_1 = 0.0, R2_1 = 0.0, R3_1 = 0.0, L_1 = 0.0, V_0 = 0.0;// начальные данные для первого цилиндра, радиус 1, радиус 2,радиус 3, длина цилиндра, начальная скорость
	long double R1_2 = 0.0, R2_2 = 0.0, R3_2 = 0.0, L_2 = 0.0;// начальные данные для второго цилиндра, радиус 1, радиус 2,радиус 3, длина цилиндра
	long double R1_3 = 0.0, R2_3 = 0.0, R3_3 = 0.0, L_3 = 0.0;// начальные данные для третьего цилиндра, радиус 1, длина цилиндра, начальная скорость
	long double R1_4 = 0.0, R2_4 = 0.0, R3_4 = 0.0, L_4 = 0.0;// начальные данные для третьего цилиндра, радиус 1, длина цилиндра, начальная скорость
	long double R1_5 = 0.0, R2_5 = 0.0, R3_5 = 0.0, L_5 = 0.0;// начальные данные для третьего цилиндра, радиус 1, длина цилиндра, начальная скорость
	long double R1_6 = 0.0, R2_6 = 0.0, R3_6 = 0.0, L_6 = 0.0;// начальные данные для третьего цилиндра, радиус 1, длина цилиндра, начальная скорость
	long double R1_7 = 0.0, R2_7 = 0.0, R3_7 = 0.0, L_7 = 0.0;// начальные данные для третьего цилиндра, радиус 1, длина цилиндра, начальная скорость

	long double R1_8 = 0.0, R2_8 = 0.0, R3_8 = 0.0;// начальные данные для третьего цилиндра, радиус 1, длина цилиндра, начальная скорость , правый конец последнего цилиндра

	std::size_t  N = 0; // начальное число частиц

	std::size_t N_histo = 0; // число бинов гистограммы распределения

	long double R = 0.0; // максимальный радиус экрана

	long double b1_left = 0.0, b1_surface = 0.0, b1_right = 0.0;
	long double b2_left = 0.0, b2_surface = 0.0, b2_right = 0.0;
	long double b3_left = 0.0, b3_surface = 0.0, b3_right = 0.0; // коэффициент захвата частицы поверхность цилиндра
	long double b4_left = 0.0, b4_surface = 0.0, b4_right = 0.0;
	long double b5_left = 0.0, b5_surface = 0.0, b5_right = 0.0;
	long double b6_left = 0.0, b6_surface = 0.0, b6_right = 0.0;
	long double b7_left = 0.0, b7_surface = 0.0, b7_right = 0.0;


	long double b1_mag = 0.0, b1_mag_left = 0.0, b1_mag_right = 0.0;
	long double b2_mag = 0.0, b2_mag_left = 0.0, b2_mag_right = 0.0;
	long double b3_mag = 0.0, b3_mag_left = 0.0, b3_mag_right = 0.0;   // коэффициент захвата частицы поверхность магнитов
	long double b4_mag = 0.0, b4_mag_left = 0.0, b4_mag_right = 0.0;
	long double b5_mag = 0.0, b5_mag_left = 0.0, b5_mag_right = 0.0;
	long double b6_mag = 0.0, b6_mag_left = 0.0, b6_mag_right = 0.0;
	long double b7_mag = 0.0, b7_mag_left = 0.0, b7_mag_right = 0.0;

	size_t N_on = 0, N_off = 0;

	size_t N1_1 = 0, N2_1 = 0, N3_1 = 0, N4_1 = 0, N5_1 = 0, N6_1 = 0, N7_1 = 0; // _1_первый цилиндр
	size_t N1_2 = 0, N2_2 = 0, N3_2 = 0, N4_2 = 0, N5_2 = 0, N6_2 = 0, N7_2 = 0; // _2_второй цилиндр
	size_t N1_3 = 0, N2_3 = 0, N3_3 = 0, N4_3 = 0, N5_3 = 0, N6_3 = 0, N7_3 = 0; // _3_третий цилиндр
	size_t N1_4 = 0, N2_4 = 0, N3_4 = 0, N4_4 = 0, N5_4 = 0, N6_4 = 0, N7_4 = 0; // _4_четвертый цилиндр
	size_t N1_5 = 0, N2_5 = 0, N3_5 = 0, N4_5 = 0, N5_5 = 0, N6_5 = 0, N7_5 = 0; // _5_пятый цилиндр
	size_t N1_6 = 0, N2_6 = 0, N3_6 = 0, N4_6 = 0, N5_6 = 0, N6_6 = 0, N7_6 = 0; // _6_шестой цилиндр
	size_t N1_7 = 0, N2_7 = 0, N3_7 = 0, N4_7 = 0, N5_7 = 0, N6_7 = 0, N7_7 = 0; // _7_седьмой цилиндр

	size_t n_mag_1_in = 0, n_mag_1_absorption = 0, n_mag_1_out = 0; // 1 магнит

	size_t n_mag_2_in = 0, n_mag_2_absorption = 0, n_mag_2_out = 0; // 2 магнит

	size_t n_mag_3_in = 0, n_mag_3_absorption = 0, n_mag_3_out = 0; // 3 магнит

	size_t n_mag_4_in = 0, n_mag_4_absorption = 0, n_mag_4_out = 0; // 4 магнит

	size_t n_mag_5_in = 0, n_mag_5_absorption = 0, n_mag_5_out = 0; // 5 магнит

	size_t n_mag_6_in = 0, n_mag_6_absorption = 0, n_mag_6_out = 0; // 6 магнит

	size_t n_mag_7_in = 0, n_mag_7_absorption = 0, n_mag_7_out = 0; // 7 магнит

	size_t n_tube_y0_x0 = 0; // число частиц в трубу в цетре координат


	size_t n1 = 0, n2 = 0, n3 = 0, n4 = 0, n5 = 0, n6 = 0, n7 = 0; // если за это число ударов о стенки цилиндра частица из него не выходит, то считаем, что она осталась в нем жить вечно и переходим к рассмотрению следующей частице 
	size_t n_travel = 0;// если за это число переходов между цилиндрами частица не выходит,то считаем, что частица осталась жить между цилиндрами вечно, переходим к рассмотрению следующей частице 


	size_t i_Collision_1 = 0;
	size_t i_Collision_2 = 0;
	size_t i_Collision_3 = 0;
	size_t i_Collision_4 = 0;
	size_t i_Collision_5 = 0;
	size_t i_Collision_6 = 0;
	size_t i_Collision_7 = 0;

	size_t i_Collision_all_1 = 0;
	size_t i_Collision_all_2 = 0;
	size_t i_Collision_all_3 = 0;
	size_t i_Collision_all_4 = 0;
	size_t i_Collision_all_5 = 0;
	size_t i_Collision_all_6 = 0;
	size_t i_Collision_all_7 = 0;

	long double t = 0.0; // начальное время счета


	long double theta1_diffusion_left = 0.0, theta1_diffusion_surface = 0.0, theta1_diffusion_right = 0.0;
	long double theta2_diffusion_left = 0.0, theta2_diffusion_surface = 0.0, theta2_diffusion_right = 0.0;
	long double theta3_diffusion_left = 0.0, theta3_diffusion_surface = 0.0, theta3_diffusion_right = 0.0;
	long double theta4_diffusion_left = 0.0, theta4_diffusion_surface = 0.0, theta4_diffusion_right = 0.0;
	long double theta5_diffusion_left = 0.0, theta5_diffusion_surface = 0.0, theta5_diffusion_right = 0.0;
	long double theta6_diffusion_left = 0.0, theta6_diffusion_surface = 0.0, theta6_diffusion_right = 0.0;
	long double theta7_diffusion_left = 0.0, theta7_diffusion_surface = 0.0, theta7_diffusion_right = 0.0;

	//	N1  число частиц, вылетевших с левого торца цилинлра
	//	N2  число частиц, вылетевших с правого торца цилинлра
	//	N3  число частиц, захваченных левым торцом цилинлра
	//	N4  число частиц, захваченных образующей цилинлра
	//	N5  число частиц, захваченных правым торцом цилинлра																  


	std::size_t N_histo_source = 0; //число бинов гистограммы распределения
	long double	R_source = 0.0;
	long double x_0_source = 0.0;

	long double z0_mag1 = 0.0, L_mag1 = 0.0; // расстояне магнита от левого торца цилиндра и длина магнита
	long double z0_mag2 = 0.0, L_mag2 = 0.0;
	long double z0_mag3 = 0.0, L_mag3 = 0.0;
	long double z0_mag4 = 0.0, L_mag4 = 0.0;
	long double z0_mag5 = 0.0, L_mag5 = 0.0;
	long double z0_mag6 = 0.0, L_mag6 = 0.0;
	long double z0_mag7 = 0.0, L_mag7 = 0.0;




	long double B1_max_initial = 0.0, B2_max_initial = 0.0, B3_max_initial = 0.0, B4_max_initial = 0.0, B5_max_initial = 0.0, B6_max_initial = 0.0, B7_max_initial = 0.0;
	long double B1_max_final = 0.0, B2_max_final = 0.0, B3_max_final = 0.0, B4_max_final = 0.0, B5_max_final = 0.0, B6_max_final = 0.0, B7_max_final = 0.0;

	long double r1_mag_max_initial = 0.0, r2_mag_max_initial = 0.0, r3_mag_max_initial = 0.0, r4_mag_max_initial = 0.0, r5_mag_max_initial = 0.0, r6_mag_max_initial = 0.0, r7_mag_max_initial = 0.0;
	long double r1_mag_max_final = 0.0, r2_mag_max_final = 0.0, r3_mag_max_final = 0.0, r4_mag_max_final = 0.0, r5_mag_max_final = 0.0, r6_mag_max_final = 0.0, r7_mag_max_final = 0.0;

	long double mu_core_particle = 0.0;

	long double m_particle = 0.0;

	bool on_off_mag_1 = true;
	bool on_off_mag_2 = true;
	bool on_off_mag_3 = true;
	bool on_off_mag_4 = true;
	bool on_off_mag_5 = true;
	bool on_off_mag_6 = true;
	bool on_off_mag_7 = true;

	bool on_off_table_magnetic_field = false;

	long double B_critical = 0.0;

	long double mu_electron_particle = 0.0;

	long double J_particle = 0.0; // момент электронной оболочки частицы в единицах постоянной Планка
	long double I_particle = 0.0; // спин ядра частицы в единицах постоянной Планка

	long double m_J = 0.0; // проекция момента
	long double m_F = 0.0; // проекция момента

	size_t N_mag_partitions = 0; // число разбиений магнита


	const int SIZE_hydrogen = 4; //-V112
	const int SIZE_deuterium = 6;
	const int SIZE_molecular_hydrogen = 16;
	const int MAX_SIZE_conditioт = 10;

	long double B_critical_hydrogen = 507.6; // в Гс
	long double B_critical_deuterium = 117.0; // в Гс

	long double m_particle_hydrogen = 938.272081358; // в МэВ
	long double m_particle_deuterium = 1875.61279347; // в МэВ

	long double m_particle_hydrogen_2 = 1876.123913707; // в МэВ
	long double m_particle_deuterium_2 = 3753.267887355; // в МэВ



	long double mu_core_particle_hydrogen = 2.79284738663;
	long double mu_core_particle_deuterium = 0.857438232992;




	bool flaq_on_off_B_mu = false;
	size_t index_condition = 0;


	bool flaq_out_trajectory = false;


	size_t particle_mode = 0;


	long double temp_beam = 0.0; // температура пучка


	bool flaq_Maxwell = false; // Максвелл или дельта-функция

	bool flaq_Maxwell_mode = false; // режим распределения Максвелла


	long double a_V_0 = 0.0; // границы распределения модулю скорости по Максвеллу, мм/сек
	long double b_V_0 = 0.0;


	long double a_time = 0.0; // границы распределения модулю скорости по Максвеллу, мм/сек
	long double b_time = 0.0;

	std::size_t N_r_angular = 0;
	std::size_t N_phi_angular = 0;

	long int N_monte_carlo_cos_intensity = 0;


	std::size_t N_histo_V_0 = 0, N_histo_V_0_out = 0, N_histo_V_0_tube_out = 0, N_histo_theta_in = 0, N_CYL_partitions = 0, N_histo_time = 0;

	long double **condition_hydrogen = new long double*[SIZE_hydrogen];
	for (int i = 0; i < SIZE_hydrogen; i++) {
		condition_hydrogen[i] = new long double[MAX_SIZE_conditioт];
		// 0 столбей: момент ядра + электронная оболочка; 1 столбец: проекция этого момента
		// 2 столбей: момент (спин) ядра; 3 столбец: проекция этого момента
		// 4 столбей: полный момент электронной оболочки; 5 столбец: проекция этого момента
		// 6 столбей: момент (спин) электрона; 7 столбец: проекция этого момента
		// 8 столбей: механический момент электрона; 9 столбец: проекция этого момента

	}

	condition_hydrogen[0][0] = 1.0, condition_hydrogen[0][1] = 1.0, condition_hydrogen[0][2] = 0.5, condition_hydrogen[0][3] = 0.5, condition_hydrogen[0][4] = 0.5, condition_hydrogen[0][5] = 0.5, condition_hydrogen[0][6] = 0.5, condition_hydrogen[0][7] = 0.5, condition_hydrogen[0][8] = 0.0, condition_hydrogen[0][8] = 0.0;
	condition_hydrogen[1][0] = 1.0, condition_hydrogen[1][1] = 0.0, condition_hydrogen[1][2] = 0.5, condition_hydrogen[1][3] = -0.5, condition_hydrogen[1][4] = 0.5, condition_hydrogen[1][5] = 0.5, condition_hydrogen[1][6] = 0.5, condition_hydrogen[1][7] = 0.5, condition_hydrogen[1][8] = 0.0, condition_hydrogen[0][8] = 0.0;
	condition_hydrogen[2][0] = 1.0, condition_hydrogen[2][1] = -1.0, condition_hydrogen[2][2] = 0.5, condition_hydrogen[2][3] = -0.5, condition_hydrogen[2][4] = 0.5, condition_hydrogen[2][5] = -0.5, condition_hydrogen[2][6] = 0.5, condition_hydrogen[2][7] = -0.5, condition_hydrogen[2][8] = 0.0, condition_hydrogen[0][8] = 0.0;
	condition_hydrogen[3][0] = 0.0, condition_hydrogen[3][1] = 0.0, condition_hydrogen[3][2] = 0.5, condition_hydrogen[3][3] = 0.5, condition_hydrogen[3][4] = 0.5, condition_hydrogen[3][5] = -0.5, condition_hydrogen[3][6] = 0.5, condition_hydrogen[3][7] = -0.5, condition_hydrogen[3][8] = 0.0, condition_hydrogen[0][8] = 0.0;



	long double **condition_deuterium = new long double*[SIZE_deuterium];
	for (int i = 0; i < SIZE_deuterium; i++) {
		condition_deuterium[i] = new long double[MAX_SIZE_conditioт];
		// 0 столбей: момент ядра + электронная оболочка; 1 столбец: проекция этого момента
		// 2 столбей: момент (спин) ядра; 3 столбец: проекция этого момента
		// 4 столбей: полный момент электронной оболочки; 5 столбец: проекция этого момента
		// 6 столбей: момент (спин) электрона; 7 столбец: проекция этого момента
		// 8 столбей: механический момент электрона; 9 столбец: проекция этого момента


	}


	condition_deuterium[0][0] = 1.5, condition_deuterium[0][1] = 1.5, condition_deuterium[0][2] = 1.0, condition_deuterium[0][3] = 1.0, condition_deuterium[0][4] = 0.5, condition_deuterium[0][5] = 0.5, condition_deuterium[0][6] = 0.5, condition_deuterium[0][7] = 0.5, condition_deuterium[0][8] = 0.0, condition_deuterium[0][9] = 0.0;
	condition_deuterium[1][0] = 1.5, condition_deuterium[1][1] = 0.5, condition_deuterium[1][2] = 1.0, condition_deuterium[1][3] = 0.0, condition_deuterium[1][4] = 0.5, condition_deuterium[1][5] = 0.5, condition_deuterium[1][6] = 0.5, condition_deuterium[1][7] = 0.5, condition_deuterium[1][8] = 0.0, condition_deuterium[1][9] = 0.0;
	condition_deuterium[2][0] = 1.5, condition_deuterium[2][1] = -0.5, condition_deuterium[2][2] = 1.0, condition_deuterium[2][3] = -1.0, condition_deuterium[2][4] = 0.5, condition_deuterium[2][5] = 0.5, condition_deuterium[2][6] = 0.5, condition_deuterium[2][7] = 0.5, condition_deuterium[2][8] = 0.0, condition_deuterium[2][9] = 0.0;
	condition_deuterium[3][0] = 1.5, condition_deuterium[3][1] = -1.5, condition_deuterium[3][2] = 1.0, condition_deuterium[3][3] = 1.0, condition_deuterium[3][4] = 0.5, condition_deuterium[3][5] = -0.5, condition_deuterium[3][6] = 0.5, condition_deuterium[3][7] = -0.5, condition_deuterium[3][8] = 0.0, condition_deuterium[3][9] = 0.0;
	condition_deuterium[4][0] = 0.5, condition_deuterium[4][1] = -0.5, condition_deuterium[4][2] = 1.0, condition_deuterium[4][3] = 0.0, condition_deuterium[4][4] = 0.5, condition_deuterium[4][5] = -0.5, condition_deuterium[4][6] = 0.5, condition_deuterium[4][7] = -0.5, condition_deuterium[4][8] = 0.0, condition_deuterium[4][9] = 0.0;
	condition_deuterium[5][0] = 0.5, condition_deuterium[5][1] = 0.5, condition_deuterium[5][2] = 1.0, condition_deuterium[5][3] = -1.0, condition_deuterium[5][4] = 0.5, condition_deuterium[5][5] = -0.5, condition_deuterium[5][6] = 0.5, condition_deuterium[5][7] = -0.5, condition_deuterium[5][8] = 0.0, condition_deuterium[5][9] = 0.0;



	long double **condition_molecular_hydrogen = new long double*[SIZE_molecular_hydrogen];
	for (int i = 0; i < SIZE_molecular_hydrogen; i++) {
		condition_molecular_hydrogen[i] = new long double[MAX_SIZE_conditioт];
		// 0 столбей: момент ядра + электронная оболочка; 1 столбец: проекция этого момента
		// 2 столбей: момент (спин) ядра; 3 столбец: проекция этого момента
		// 4 столбей: полный момент электронной оболочки; 5 столбец: проекция этого момента
		// 6 столбей: момент (спин) электрона; 7 столбец: проекция этого момента
		// 8 столбей: механический момент электрона; 9 столбец: проекция этого момента


	}

	// ортоводород
	condition_molecular_hydrogen[0][0] = 2.0, condition_molecular_hydrogen[0][1] = 2.0, condition_molecular_hydrogen[0][2] = 1.0, condition_molecular_hydrogen[0][3] = 1.0, condition_molecular_hydrogen[0][4] = 1.0, condition_molecular_hydrogen[0][5] = 1.0, condition_molecular_hydrogen[0][6] = 0.5, condition_molecular_hydrogen[0][7] = 0.5, condition_molecular_hydrogen[0][8] = 0.0, condition_molecular_hydrogen[0][9] = 0.0;
	condition_molecular_hydrogen[1][0] = 2.0, condition_molecular_hydrogen[1][1] = 1.0, condition_molecular_hydrogen[1][2] = 1.0, condition_molecular_hydrogen[1][3] = 1.0, condition_molecular_hydrogen[1][4] = 1.0, condition_molecular_hydrogen[1][5] = 0.0, condition_molecular_hydrogen[1][6] = 0.5, condition_molecular_hydrogen[1][7] = 0.5, condition_molecular_hydrogen[1][8] = 0.0, condition_molecular_hydrogen[1][9] = 0.0;
	condition_molecular_hydrogen[2][0] = 2.0, condition_molecular_hydrogen[2][1] = 0.0, condition_molecular_hydrogen[2][2] = 1.0, condition_molecular_hydrogen[2][3] = 1.0, condition_molecular_hydrogen[2][4] = 1.0, condition_molecular_hydrogen[2][5] = -1.0, condition_molecular_hydrogen[2][6] = 0.5, condition_molecular_hydrogen[2][7] = 0.5, condition_molecular_hydrogen[2][8] = 0.0, condition_molecular_hydrogen[2][9] = 0.0;
	condition_molecular_hydrogen[3][0] = 2.0, condition_molecular_hydrogen[3][1] = 1.0, condition_molecular_hydrogen[3][2] = 1.0, condition_molecular_hydrogen[3][3] = 0.0, condition_molecular_hydrogen[3][4] = 1.0, condition_molecular_hydrogen[3][5] = 1.0, condition_molecular_hydrogen[3][6] = 0.5, condition_molecular_hydrogen[3][7] = -0.5, condition_molecular_hydrogen[3][8] = 0.0, condition_molecular_hydrogen[3][9] = 0.0;
	condition_molecular_hydrogen[4][0] = 2.0, condition_molecular_hydrogen[4][1] = 0.0, condition_molecular_hydrogen[4][2] = 1.0, condition_molecular_hydrogen[4][3] = 0.0, condition_molecular_hydrogen[4][4] = 1.0, condition_molecular_hydrogen[4][5] = 0.0, condition_molecular_hydrogen[4][6] = 0.5, condition_molecular_hydrogen[4][7] = -0.5, condition_molecular_hydrogen[4][8] = 0.0, condition_molecular_hydrogen[4][9] = 0.0;
	condition_molecular_hydrogen[5][0] = 2.0, condition_molecular_hydrogen[5][1] = -1.0, condition_molecular_hydrogen[5][2] = 1.0, condition_molecular_hydrogen[5][3] = 0.0, condition_molecular_hydrogen[5][4] = 1.0, condition_molecular_hydrogen[5][5] = -1.0, condition_molecular_hydrogen[5][6] = 0.5, condition_molecular_hydrogen[5][7] = -0.5, condition_molecular_hydrogen[5][8] = 0.0, condition_molecular_hydrogen[5][9] = 0.0;
	condition_molecular_hydrogen[6][0] = 2.0, condition_molecular_hydrogen[6][1] = 0.0, condition_molecular_hydrogen[6][2] = 1.0, condition_molecular_hydrogen[6][3] = -1.0, condition_molecular_hydrogen[6][4] = 1.0, condition_molecular_hydrogen[6][5] = 1.0, condition_molecular_hydrogen[6][6] = 0.5, condition_molecular_hydrogen[6][7] = -0.5, condition_molecular_hydrogen[6][8] = 0.0, condition_molecular_hydrogen[6][9] = 0.0;
	condition_molecular_hydrogen[7][0] = 2.0, condition_molecular_hydrogen[7][1] = -1.0, condition_molecular_hydrogen[7][2] = 1.0, condition_molecular_hydrogen[7][3] = -1.0, condition_molecular_hydrogen[7][4] = 1.0, condition_molecular_hydrogen[7][5] = 0.0, condition_molecular_hydrogen[7][6] = 0.5, condition_molecular_hydrogen[7][7] = -0.5, condition_molecular_hydrogen[7][8] = 0.0, condition_molecular_hydrogen[7][9] = 0.0;
	condition_molecular_hydrogen[8][0] = 2.0, condition_molecular_hydrogen[8][1] = -2.0, condition_molecular_hydrogen[8][2] = 1.0, condition_molecular_hydrogen[8][3] = -1.0, condition_molecular_hydrogen[8][4] = 1.0, condition_molecular_hydrogen[8][5] = -1.0, condition_molecular_hydrogen[8][6] = 0.5, condition_molecular_hydrogen[8][7] = -0.5, condition_molecular_hydrogen[8][8] = 0.0, condition_molecular_hydrogen[8][9] = 0.0;


	// параводород

	condition_molecular_hydrogen[9][0] = 1.0, condition_molecular_hydrogen[9][1] = 1.0, condition_molecular_hydrogen[9][2] = 0.0, condition_molecular_hydrogen[9][3] = 0.0, condition_molecular_hydrogen[9][4] = 1.0, condition_molecular_hydrogen[9][5] = 1.0, condition_molecular_hydrogen[9][6] = 0.5, condition_molecular_hydrogen[9][7] = 0.5, condition_molecular_hydrogen[9][8] = 0.0, condition_molecular_hydrogen[9][9] = 0.0;
	condition_molecular_hydrogen[10][0] = 1.0, condition_molecular_hydrogen[10][1] = 0.0, condition_molecular_hydrogen[10][2] = 0.0, condition_molecular_hydrogen[10][3] = 0.0, condition_molecular_hydrogen[10][4] = 0.0, condition_molecular_hydrogen[10][5] = 0.0, condition_molecular_hydrogen[10][6] = 0.5, condition_molecular_hydrogen[10][7] = 0.5, condition_molecular_hydrogen[10][8] = 0.0, condition_molecular_hydrogen[10][9] = 0.0;
	condition_molecular_hydrogen[11][0] = 1.0, condition_molecular_hydrogen[11][1] = -1.0, condition_molecular_hydrogen[11][2] = 0.0, condition_molecular_hydrogen[11][3] = 0.0, condition_molecular_hydrogen[11][4] = -1.0, condition_molecular_hydrogen[11][5] = -1.0, condition_molecular_hydrogen[11][6] = 0.5, condition_molecular_hydrogen[11][7] = 0.5, condition_molecular_hydrogen[11][8] = 0.0, condition_molecular_hydrogen[11][9] = 0.0;
	condition_molecular_hydrogen[12][0] = 0.0, condition_molecular_hydrogen[12][1] = 0.0, condition_molecular_hydrogen[12][2] = 0.0, condition_molecular_hydrogen[12][3] = 0.0, condition_molecular_hydrogen[12][4] = 0.0, condition_molecular_hydrogen[12][5] = 0.0, condition_molecular_hydrogen[12][6] = 0.5, condition_molecular_hydrogen[12][7] = -0.5, condition_molecular_hydrogen[12][8] = 0.0, condition_molecular_hydrogen[12][9] = 0.0;


	long double z_zero_1 = 0.0, z_zero_2 = 0.0, z_zero_3 = 0.0, z_zero_4 = 0.0, z_zero_5 = 0.0, z_zero_6 = 0.0, z_zero_7 = 0.0; // расстояние от магнита, на котором радиус частицы зануляется

	bool average_peak = false;

	long double m_mag_1 = 0.0, m_mag_2 = 0.0, m_mag_3 = 0.0, m_mag_4 = 0.0, m_mag_5 = 0.0, m_mag_6 = 0.0, m_mag_7 = 0.0; //полюсность магнитов

	bool mag_runge_1 = false, mag_runge_2 = false, mag_runge_3 = false, mag_runge_4 = false, mag_runge_5 = false, mag_runge_6 = false, mag_runge_7 = false; // аналитическое решение или численное Рунге-Кутт 4 порядка

	bool flaq_angular_coefficient = false;

	long double phi_1_2 = 0.0; // угловой коэффициент для цилиндров 1-2

	long double iron_mag_1 = 0.0; // толщина железа магнита, ограничение по радиусу
	long double iron_mag_2 = 0.0;
	long double iron_mag_3 = 0.0;
	long double iron_mag_4 = 0.0;
	long double iron_mag_5 = 0.0;
	long double iron_mag_6 = 0.0;
	long double iron_mag_7 = 0.0;

	long double drift_velocity = 0.0;


	// переменные для подсчета числа частиц
	// объявление одномерного динамического массива на n элементов входных начальных данных:										   
	const std::size_t n = 241;	   // число входных параметров
	long double *mass = new long double[n]; // одномерный массив входных параметров

	for (int i = 0; i < n; i = i + 1) {
		mass[i] = 0.0;
	}




	vector<long double> Vector_r_magnetic_field_table(0);
	vector<long double> Vector_phi_magnetic_field_table(0);
	vector<long double> Vector_B_magnetic_field_table(0);
	vector<long double> Vector_delta_B_magnetic_field_table(0);
	vector<size_t> Vector_index_r_magnetic_field_table(0);
	size_t index_phi_magnetic_field_table = 0;


	vector<long double> Vector_x_in(0);
	vector<long double> Vector_y_in(0);
	vector<long double> Vector_z_in(0);
	vector<long double> Vector_r_in(0);
	vector<long double> Vector_rr_in(0);
	vector<long double> Vector_color_in(0);
	vector<long double> out_in(0);
	vector<long double> Vector_phi_in(0);
	vector<long double> Vector_psi_in(0);
	vector<long double> Vector_theta_in(0);
	vector<long double> Vector_v_x_in(0);
	vector<long double> Vector_v_y_in(0);
	vector<long double> Vector_v_z_in(0);
	vector<long double> Vector_v_r_in(0);
	vector<long double> Vector_v_phi_in(0);
	vector<long double> Vector_v_perp_in(0);
	vector<long double> Vector_v_0_in(0);
	vector<long double> Vector_force_in(0);
	vector<long double> Vector_condition_color_in(0);
	vector<long double> Vector_mu_in(0);
	vector<long double> Vector_B_in(0);




	vector<long double> Vector_x_in_CYL_7(0);
	vector<long double> Vector_y_in_CYL_7(0);
	vector<long double> Vector_z_in_CYL_7(0);
	vector<long double> Vector_r_in_CYL_7(0);
	vector<long double> Vector_rr_in_CYL_7(0);
	vector<long double> Vector_color_in_CYL_7(0);
	vector<long double> out_in_CYL_7(0);
	vector<long double> Vector_phi_in_CYL_7(0);
	vector<long double> Vector_psi_in_CYL_7(0);
	vector<long double> Vector_theta_in_CYL_7(0);
	vector<long double> Vector_v_x_in_CYL_7(0);
	vector<long double> Vector_v_y_in_CYL_7(0);
	vector<long double> Vector_v_z_in_CYL_7(0);
	vector<long double> Vector_v_r_in_CYL_7(0);
	vector<long double> Vector_v_phi_in_CYL_7(0);
	vector<long double> Vector_v_perp_in_CYL_7(0);
	vector<long double> Vector_v_0_in_CYL_7(0);
	vector<long double> Vector_force_in_CYL_7(0);
	vector<long double> Vector_condition_color_in_CYL_7(0);
	vector<long double> Vector_mu_in_CYL_7(0);
	vector<long double> Vector_B_in_CYL_7(0);



	vector<long double> Vector_x_in_CYL_7_negative(0);
	vector<long double> Vector_y_in_CYL_7_negative(0);
	vector<long double> Vector_z_in_CYL_7_negative(0);
	vector<long double> Vector_r_in_CYL_7_negative(0);
	vector<long double> Vector_rr_in_CYL_7_negative(0);
	vector<long double> Vector_phi_in_CYL_7_negative(0);
	vector<long double> Vector_psi_in_CYL_7_negative(0);
	vector<long double> Vector_theta_in_CYL_7_negative(0);


	vector<long double> Vector_x_in_CYL_7_positive(0);
	vector<long double> Vector_y_in_CYL_7_positive(0);
	vector<long double> Vector_z_in_CYL_7_positive(0);
	vector<long double> Vector_r_in_CYL_7_positive(0);
	vector<long double> Vector_rr_in_CYL_7_positive(0);
	vector<long double> Vector_phi_in_CYL_7_positive(0);
	vector<long double> Vector_psi_in_CYL_7_positive(0);
	vector<long double> Vector_theta_in_CYL_7_positive(0);



	vector<long double> Vector_x_in_CYL_7_zero(0);
	vector<long double> Vector_y_in_CYL_7_zero(0);
	vector<long double> Vector_z_in_CYL_7_zero(0);
	vector<long double> Vector_r_in_CYL_7_zero(0);
	vector<long double> Vector_rr_in_CYL_7_zero(0);
	vector<long double> Vector_phi_in_CYL_7_zero(0);
	vector<long double> Vector_psi_in_CYL_7_zero(0);
	vector<long double> Vector_theta_in_CYL_7_zero(0);











	vector<long double> Vector_r_mag_1(0);
	vector<long double> Vector_rr_mag_1(0);
	vector<long double> Vector_z_mag_1(0);
	vector<long double> Vector_x_mag_1(0);
	vector<long double> Vector_y_mag_1(0);
	vector<long double> Vector_color_mag_1(0);
	vector<long double> Vector_out_mag_1(0);
	vector<long double> Vector_phi_mag_1(0);
	vector<long double> Vector_psi_mag_1(0);
	vector<long double> Vector_theta_mag_1(0);
	vector<long double> Vector_v_x_mag_1(0);
	vector<long double> Vector_v_y_mag_1(0);
	vector<long double> Vector_v_z_mag_1(0);
	vector<long double> Vector_v_r_mag_1(0);
	vector<long double> Vector_v_phi_mag_1(0);
	vector<long double> Vector_v_perp_mag_1(0);
	vector<long double> Vector_v_0_mag_1(0);
	vector<long double> Vector_force_mag_1(0);
	vector<long double> Vector_condition_color_mag_1(0);
	vector<long double> Vector_mu_mag_1(0);
	vector<long double> Vector_B_mag_1(0);



	vector<long double> Vector_r_mag_2(0);
	vector<long double> Vector_rr_mag_2(0);
	vector<long double> Vector_z_mag_2(0);
	vector<long double> Vector_x_mag_2(0);
	vector<long double> Vector_y_mag_2(0);
	vector<long double> Vector_color_mag_2(0);
	vector<long double> Vector_out_mag_2(0);
	vector<long double> Vector_phi_mag_2(0);
	vector<long double> Vector_psi_mag_2(0);
	vector<long double> Vector_theta_mag_2(0);
	vector<long double> Vector_v_x_mag_2(0);
	vector<long double> Vector_v_y_mag_2(0);
	vector<long double> Vector_v_z_mag_2(0);
	vector<long double> Vector_v_r_mag_2(0);
	vector<long double> Vector_v_phi_mag_2(0);
	vector<long double> Vector_v_perp_mag_2(0);
	vector<long double> Vector_v_0_mag_2(0);
	vector<long double> Vector_force_mag_2(0);
	vector<long double> Vector_condition_color_mag_2(0);
	vector<long double> Vector_mu_mag_2(0);
	vector<long double> Vector_B_mag_2(0);



	vector<long double> Vector_r_mag_3(0);
	vector<long double> Vector_rr_mag_3(0);
	vector<long double> Vector_z_mag_3(0);
	vector<long double> Vector_x_mag_3(0);
	vector<long double> Vector_y_mag_3(0);
	vector<long double> Vector_color_mag_3(0);
	vector<long double> Vector_out_mag_3(0);
	vector<long double> Vector_phi_mag_3(0);
	vector<long double> Vector_psi_mag_3(0);
	vector<long double> Vector_theta_mag_3(0);
	vector<long double> Vector_v_x_mag_3(0);
	vector<long double> Vector_v_y_mag_3(0);
	vector<long double> Vector_v_z_mag_3(0);
	vector<long double> Vector_v_r_mag_3(0);
	vector<long double> Vector_v_phi_mag_3(0);
	vector<long double> Vector_v_perp_mag_3(0);
	vector<long double> Vector_v_0_mag_3(0);
	vector<long double> Vector_force_mag_3(0);
	vector<long double> Vector_condition_color_mag_3(0);
	vector<long double> Vector_mu_mag_3(0);
	vector<long double> Vector_B_mag_3(0);



	vector<long double> Vector_r_mag_4(0);
	vector<long double> Vector_rr_mag_4(0);
	vector<long double> Vector_z_mag_4(0);
	vector<long double> Vector_x_mag_4(0);
	vector<long double> Vector_y_mag_4(0);
	vector<long double> Vector_color_mag_4(0);
	vector<long double> Vector_out_mag_4(0);
	vector<long double> Vector_phi_mag_4(0);
	vector<long double> Vector_psi_mag_4(0);
	vector<long double> Vector_theta_mag_4(0);
	vector<long double> Vector_v_x_mag_4(0);
	vector<long double> Vector_v_y_mag_4(0);
	vector<long double> Vector_v_z_mag_4(0);
	vector<long double> Vector_v_r_mag_4(0);
	vector<long double> Vector_v_phi_mag_4(0);
	vector<long double> Vector_v_perp_mag_4(0);
	vector<long double> Vector_v_0_mag_4(0);
	vector<long double> Vector_force_mag_4(0);
	vector<long double> Vector_condition_color_mag_4(0);
	vector<long double> Vector_mu_mag_4(0);
	vector<long double> Vector_B_mag_4(0);



	vector<long double> Vector_r_mag_5(0);
	vector<long double> Vector_rr_mag_5(0);
	vector<long double> Vector_z_mag_5(0);
	vector<long double> Vector_x_mag_5(0);
	vector<long double> Vector_y_mag_5(0);
	vector<long double> Vector_color_mag_5(0);
	vector<long double> Vector_out_mag_5(0);
	vector<long double> Vector_phi_mag_5(0);
	vector<long double> Vector_psi_mag_5(0);
	vector<long double> Vector_theta_mag_5(0);
	vector<long double> Vector_v_x_mag_5(0);
	vector<long double> Vector_v_y_mag_5(0);
	vector<long double> Vector_v_z_mag_5(0);
	vector<long double> Vector_v_r_mag_5(0);
	vector<long double> Vector_v_phi_mag_5(0);
	vector<long double> Vector_v_perp_mag_5(0);
	vector<long double> Vector_v_0_mag_5(0);
	vector<long double> Vector_force_mag_5(0);
	vector<long double> Vector_condition_color_mag_5(0);
	vector<long double> Vector_mu_mag_5(0);
	vector<long double> Vector_B_mag_5(0);


	vector<long double> Vector_r_mag_6(0);
	vector<long double> Vector_rr_mag_6(0);
	vector<long double> Vector_z_mag_6(0);
	vector<long double> Vector_x_mag_6(0);
	vector<long double> Vector_y_mag_6(0);
	vector<long double> Vector_color_mag_6(0);
	vector<long double> Vector_out_mag_6(0);
	vector<long double> Vector_phi_mag_6(0);
	vector<long double> Vector_psi_mag_6(0);
	vector<long double> Vector_theta_mag_6(0);
	vector<long double> Vector_v_x_mag_6(0);
	vector<long double> Vector_v_y_mag_6(0);
	vector<long double> Vector_v_z_mag_6(0);
	vector<long double> Vector_v_r_mag_6(0);
	vector<long double> Vector_v_phi_mag_6(0);
	vector<long double> Vector_v_perp_mag_6(0);
	vector<long double> Vector_v_0_mag_6(0);
	vector<long double> Vector_force_mag_6(0);
	vector<long double> Vector_condition_color_mag_6(0);
	vector<long double> Vector_mu_mag_6(0);
	vector<long double> Vector_B_mag_6(0);


	vector<long double> Vector_r_mag_7(0);
	vector<long double> Vector_rr_mag_7(0);
	vector<long double> Vector_z_mag_7(0);
	vector<long double> Vector_x_mag_7(0);
	vector<long double> Vector_y_mag_7(0);
	vector<long double> Vector_color_mag_7(0);
	vector<long double> Vector_out_mag_7(0);
	vector<long double> Vector_phi_mag_7(0);
	vector<long double> Vector_psi_mag_7(0);
	vector<long double> Vector_theta_mag_7(0);
	vector<long double> Vector_v_x_mag_7(0);
	vector<long double> Vector_v_y_mag_7(0);
	vector<long double> Vector_v_z_mag_7(0);
	vector<long double> Vector_v_r_mag_7(0);
	vector<long double> Vector_v_phi_mag_7(0);
	vector<long double> Vector_v_perp_mag_7(0);
	vector<long double> Vector_v_0_mag_7(0);
	vector<long double> Vector_force_mag_7(0);
	vector<long double> Vector_condition_color_mag_7(0);
	vector<long double> Vector_mu_mag_7(0);
	vector<long double> Vector_B_mag_7(0);




	vector<long double> Vector_temp_r_mag(0);
	vector<long double> Vector_temp_rr_mag(0);
	vector<long double> Vector_temp_z_mag(0);
	vector<long double> Vector_temp_x_mag(0);
	vector<long double> Vector_temp_y_mag(0);
	vector<long double> Vector_temp_color_mag(0);
	vector<long double> Vector_temp_out_mag(0);
	vector<long double> Vector_temp_phi_mag(0);
	vector<long double> Vector_temp_psi_mag(0);
	vector<long double> Vector_temp_theta_mag(0);
	vector<long double> Vector_temp_v_x_mag(0);
	vector<long double> Vector_temp_v_y_mag(0);
	vector<long double> Vector_temp_v_z_mag(0);
	vector<long double> Vector_temp_v_r_mag(0);
	vector<long double> Vector_temp_v_phi_mag(0);
	vector<long double> Vector_temp_v_perp_mag(0);
	vector<long double> Vector_temp_v_0_mag(0);
	vector<long double> Vector_temp_force_mag(0);
	vector<long double> Vector_temp_condition_color_mag(0);
	vector<long double> Vector_temp_mu_mag(0);
	vector<long double> Vector_temp_B_mag(0);



	vector<long double> trajectory_cyl_x(0);
	vector<long double> trajectory_cyl_y(0);
	vector<long double> trajectory_cyl_z(0);
	vector<long double> trajectory_cyl_r(0);
	vector<long double> trajectory_cyl_rr(0);
	vector<long double> Vector_color_trajectory_cyl(0);
	vector<long double> out_trajectory_cyl(0);
	vector<long double> trajectory_cyl_phi(0);
	vector<long double> trajectory_cyl_psi(0);
	vector<long double> trajectory_cyl_theta(0);
	vector<long double> trajectory_cyl_v_x(0);
	vector<long double> trajectory_cyl_v_y(0);
	vector<long double> trajectory_cyl_v_z(0);
	vector<long double> trajectory_cyl_v_r(0);
	vector<long double> trajectory_cyl_v_phi(0);
	vector<long double> trajectory_cyl_v_perp(0);
	vector<long double> trajectory_cyl_v_0(0);
	vector<long double> trajectory_cyl_force(0);
	vector<long double> trajectory_cyl_condition_color(0);
	vector<long double> trajectory_cyl_mu(0);
	vector<long double> trajectory_cyl_B(0);


	vector<long double> trajectory_temp_cyl_x(0);
	vector<long double> trajectory_temp_cyl_y(0);
	vector<long double> trajectory_temp_cyl_z(0);
	vector<long double> trajectory_temp_cyl_r(0);
	vector<long double> trajectory_temp_cyl_rr(0);
	vector<long double> Vector_color_trajectory_temp_cyl(0);
	vector<long double> out_trajectory_temp_cyl(0);
	vector<long double> trajectory_temp_cyl_phi(0);
	vector<long double> trajectory_temp_cyl_psi(0);
	vector<long double> trajectory_temp_cyl_theta(0);
	vector<long double> trajectory_temp_cyl_v_x(0);
	vector<long double> trajectory_temp_cyl_v_y(0);
	vector<long double> trajectory_temp_cyl_v_z(0);
	vector<long double> trajectory_temp_cyl_v_r(0);
	vector<long double> trajectory_temp_cyl_v_phi(0);
	vector<long double> trajectory_temp_cyl_v_perp(0);
	vector<long double> trajectory_temp_cyl_v_0(0);
	vector<long double> trajectory_temp_cyl_force(0);
	vector<long double> trajectory_temp_cyl_condition_color(0);
	vector<long double> trajectory_temp_cyl_mu(0);
	vector<long double> trajectory_temp_cyl_B(0);


	vector<long double> Vector_r_cyl_1(0);
	vector<long double> Vector_rr_cyl_1(0);
	vector<long double> Vector_z_cyl_1(0);
	vector<long double> Vector_x_cyl_1(0);
	vector<long double> Vector_y_cyl_1(0);
	vector<long double> Vector_color_cyl_1(0);
	vector<long double> Vector_out_cyl_1(0);
	vector<long double> Vector_phi_cyl_1(0);
	vector<long double> Vector_psi_cyl_1(0);
	vector<long double> Vector_theta_cyl_1(0);
	vector<long double> Vector_v_x_cyl_1(0);
	vector<long double> Vector_v_y_cyl_1(0);
	vector<long double> Vector_v_z_cyl_1(0);
	vector<long double> Vector_v_r_cyl_1(0);
	vector<long double> Vector_v_phi_cyl_1(0);
	vector<long double> Vector_v_perp_cyl_1(0);
	vector<long double> Vector_v_0_cyl_1(0);
	vector<long double> Vector_force_cyl_1(0);
	vector<long double> Vector_condition_color_cyl_1(0);
	vector<long double> Vector_mu_cyl_1(0);
	vector<long double> Vector_B_cyl_1(0);


	vector<long double> Vector_r_cyl_2(0);
	vector<long double> Vector_rr_cyl_2(0);
	vector<long double> Vector_z_cyl_2(0);
	vector<long double> Vector_x_cyl_2(0);
	vector<long double> Vector_y_cyl_2(0);
	vector<long double> Vector_color_cyl_2(0);
	vector<long double> Vector_out_cyl_2(0);
	vector<long double> Vector_phi_cyl_2(0);
	vector<long double> Vector_psi_cyl_2(0);
	vector<long double> Vector_theta_cyl_2(0);
	vector<long double> Vector_v_x_cyl_2(0);
	vector<long double> Vector_v_y_cyl_2(0);
	vector<long double> Vector_v_z_cyl_2(0);
	vector<long double> Vector_v_r_cyl_2(0);
	vector<long double> Vector_v_phi_cyl_2(0);
	vector<long double> Vector_v_perp_cyl_2(0);
	vector<long double> Vector_v_0_cyl_2(0);
	vector<long double> Vector_force_cyl_2(0);
	vector<long double> Vector_condition_color_cyl_2(0);
	vector<long double> Vector_mu_cyl_2(0);
	vector<long double> Vector_B_cyl_2(0);


	vector<long double> Vector_r_cyl_3(0);
	vector<long double> Vector_rr_cyl_3(0);
	vector<long double> Vector_z_cyl_3(0);
	vector<long double> Vector_x_cyl_3(0);
	vector<long double> Vector_y_cyl_3(0);
	vector<long double> Vector_color_cyl_3(0);
	vector<long double> Vector_out_cyl_3(0);
	vector<long double> Vector_phi_cyl_3(0);
	vector<long double> Vector_psi_cyl_3(0);
	vector<long double> Vector_theta_cyl_3(0);
	vector<long double> Vector_v_x_cyl_3(0);
	vector<long double> Vector_v_y_cyl_3(0);
	vector<long double> Vector_v_z_cyl_3(0);
	vector<long double> Vector_v_r_cyl_3(0);
	vector<long double> Vector_v_phi_cyl_3(0);
	vector<long double> Vector_v_perp_cyl_3(0);
	vector<long double> Vector_v_0_cyl_3(0);
	vector<long double> Vector_force_cyl_3(0);
	vector<long double> Vector_condition_color_cyl_3(0);
	vector<long double> Vector_mu_cyl_3(0);
	vector<long double> Vector_B_cyl_3(0);



	vector<long double> Vector_r_cyl_4(0);
	vector<long double> Vector_rr_cyl_4(0);
	vector<long double> Vector_z_cyl_4(0);
	vector<long double> Vector_x_cyl_4(0);
	vector<long double> Vector_y_cyl_4(0);
	vector<long double> Vector_color_cyl_4(0);
	vector<long double> Vector_out_cyl_4(0);
	vector<long double> Vector_phi_cyl_4(0);
	vector<long double> Vector_psi_cyl_4(0);
	vector<long double> Vector_theta_cyl_4(0);
	vector<long double> Vector_v_x_cyl_4(0);
	vector<long double> Vector_v_y_cyl_4(0);
	vector<long double> Vector_v_z_cyl_4(0);
	vector<long double> Vector_v_r_cyl_4(0);
	vector<long double> Vector_v_phi_cyl_4(0);
	vector<long double> Vector_v_perp_cyl_4(0);
	vector<long double> Vector_v_0_cyl_4(0);
	vector<long double> Vector_force_cyl_4(0);
	vector<long double> Vector_condition_color_cyl_4(0);
	vector<long double> Vector_mu_cyl_4(0);
	vector<long double> Vector_B_cyl_4(0);



	vector<long double> Vector_r_cyl_5(0);
	vector<long double> Vector_rr_cyl_5(0);
	vector<long double> Vector_z_cyl_5(0);
	vector<long double> Vector_x_cyl_5(0);
	vector<long double> Vector_y_cyl_5(0);
	vector<long double> Vector_color_cyl_5(0);
	vector<long double> Vector_out_cyl_5(0);
	vector<long double> Vector_phi_cyl_5(0);
	vector<long double> Vector_psi_cyl_5(0);
	vector<long double> Vector_theta_cyl_5(0);
	vector<long double> Vector_v_x_cyl_5(0);
	vector<long double> Vector_v_y_cyl_5(0);
	vector<long double> Vector_v_z_cyl_5(0);
	vector<long double> Vector_v_r_cyl_5(0);
	vector<long double> Vector_v_phi_cyl_5(0);
	vector<long double> Vector_v_perp_cyl_5(0);
	vector<long double> Vector_v_0_cyl_5(0);
	vector<long double> Vector_force_cyl_5(0);
	vector<long double> Vector_condition_color_cyl_5(0);
	vector<long double> Vector_mu_cyl_5(0);
	vector<long double> Vector_B_cyl_5(0);




	vector<long double> Vector_r_cyl_6(0);
	vector<long double> Vector_rr_cyl_6(0);
	vector<long double> Vector_z_cyl_6(0);
	vector<long double> Vector_x_cyl_6(0);
	vector<long double> Vector_y_cyl_6(0);
	vector<long double> Vector_color_cyl_6(0);
	vector<long double> Vector_out_cyl_6(0);
	vector<long double> Vector_phi_cyl_6(0);
	vector<long double> Vector_psi_cyl_6(0);
	vector<long double> Vector_theta_cyl_6(0);
	vector<long double> Vector_v_x_cyl_6(0);
	vector<long double> Vector_v_y_cyl_6(0);
	vector<long double> Vector_v_z_cyl_6(0);
	vector<long double> Vector_v_r_cyl_6(0);
	vector<long double> Vector_v_phi_cyl_6(0);
	vector<long double> Vector_v_perp_cyl_6(0);
	vector<long double> Vector_v_0_cyl_6(0);
	vector<long double> Vector_force_cyl_6(0);
	vector<long double> Vector_condition_color_cyl_6(0);
	vector<long double> Vector_mu_cyl_6(0);
	vector<long double> Vector_B_cyl_6(0);




	vector<long double> Vector_r_cyl_7(0);
	vector<long double> Vector_rr_cyl_7(0);
	vector<long double> Vector_z_cyl_7(0);
	vector<long double> Vector_x_cyl_7(0);
	vector<long double> Vector_y_cyl_7(0);
	vector<long double> Vector_color_cyl_7(0);
	vector<long double> Vector_out_cyl_7(0);
	vector<long double> Vector_phi_cyl_7(0);
	vector<long double> Vector_psi_cyl_7(0);
	vector<long double> Vector_theta_cyl_7(0);
	vector<long double> Vector_v_x_cyl_7(0);
	vector<long double> Vector_v_y_cyl_7(0);
	vector<long double> Vector_v_z_cyl_7(0);
	vector<long double> Vector_v_r_cyl_7(0);
	vector<long double> Vector_v_phi_cyl_7(0);
	vector<long double> Vector_v_perp_cyl_7(0);
	vector<long double> Vector_v_0_cyl_7(0);
	vector<long double> Vector_force_cyl_7(0);
	vector<long double> Vector_condition_color_cyl_7(0);
	vector<long double> Vector_mu_cyl_7(0);
	vector<long double> Vector_B_cyl_7(0);






	long double n_cos_intensity = 0.0;	  // степень n в интенсивности источника cos(theta)^n


	long double min_r_out_mag_1 = 0.0;  // ограничение_по_радиусу_для_частиц_выходящих_из_магнита_1,_мм_(вылетают_частицы_у_которых_радиус_больше_этого)
	long double min_r_out_mag_2 = 0.0;
	long double min_r_out_mag_3 = 0.0;
	long double min_r_out_mag_4 = 0.0;
	long double min_r_out_mag_5 = 0.0;
	long double min_r_out_mag_6 = 0.0;
	long double min_r_out_mag_7 = 0.0;



	long double min_r_in_mag_1 = 0.0;  //ограничение_по_радиусу_для_частиц_входящих_в_магнит_1, _мм_(входящие_частицы_в_магнит_с_радиусом_меньше_этого_не_учитываются)
	long double min_r_in_mag_2 = 0.0;
	long double min_r_in_mag_3 = 0.0;
	long double min_r_in_mag_4 = 0.0;
	long double min_r_in_mag_5 = 0.0;
	long double min_r_in_mag_6 = 0.0;
	long double min_r_in_mag_7 = 0.0;


	long double v_r_in_1 = 0.0, v_r_out_1 = 0.0;
	long double v_r_in_2 = 0.0, v_r_out_2 = 0.0;
	long double v_r_in_3 = 0.0, v_r_out_3 = 0.0;
	long double v_r_in_4 = 0.0, v_r_out_4 = 0.0;
	long double v_r_in_5 = 0.0, v_r_out_5 = 0.0;
	long double v_r_in_6 = 0.0, v_r_out_6 = 0.0;
	long double v_r_in_7 = 0.0, v_r_out_7 = 0.0;


	long double v_phi_in_1 = 0.0, v_phi_out_1 = 0.0;
	long double v_phi_in_2 = 0.0, v_phi_out_2 = 0.0;
	long double v_phi_in_3 = 0.0, v_phi_out_3 = 0.0;
	long double v_phi_in_4 = 0.0, v_phi_out_4 = 0.0;
	long double v_phi_in_5 = 0.0, v_phi_out_5 = 0.0;
	long double v_phi_in_6 = 0.0, v_phi_out_6 = 0.0;
	long double v_phi_in_7 = 0.0, v_phi_out_7 = 0.0;


	long double v_x_in_1 = 0.0, v_x_out_1 = 0.0;
	long double v_x_in_2 = 0.0, v_x_out_2 = 0.0;
	long double v_x_in_3 = 0.0, v_x_out_3 = 0.0;
	long double v_x_in_4 = 0.0, v_x_out_4 = 0.0;
	long double v_x_in_5 = 0.0, v_x_out_5 = 0.0;
	long double v_x_in_6 = 0.0, v_x_out_6 = 0.0;
	long double v_x_in_7 = 0.0, v_x_out_7 = 0.0;


	long double v_y_in_1 = 0.0, v_y_out_1 = 0.0;
	long double v_y_in_2 = 0.0, v_y_out_2 = 0.0;
	long double v_y_in_3 = 0.0, v_y_out_3 = 0.0;
	long double v_y_in_4 = 0.0, v_y_out_4 = 0.0;
	long double v_y_in_5 = 0.0, v_y_out_5 = 0.0;
	long double v_y_in_6 = 0.0, v_y_out_6 = 0.0;
	long double v_y_in_7 = 0.0, v_y_out_7 = 0.0;

	bool out_mag_1 = false;
	bool out_mag_2 = false;
	bool out_mag_3 = false;
	bool out_mag_4 = false;
	bool out_mag_5 = false;
	bool out_mag_6 = false;
	bool out_mag_7 = false;


	long double P_z_cyl_1 = 0.0, P_z_cyl_2 = 0.0, P_z_cyl_3 = 0.0, P_z_cyl_4 = 0.0, P_z_cyl_5 = 0.0, P_z_cyl_6 = 0.0, P_z_cyl_7 = 0.0;
	long double P_zz_cyl_1 = 0.0, P_zz_cyl_2 = 0.0, P_zz_cyl_3 = 0.0, P_zz_cyl_4 = 0.0, P_zz_cyl_5 = 0.0, P_zz_cyl_6 = 0.0, P_zz_cyl_7 = 0.0;

	long double P_z_mag_1 = 0.0, P_z_mag_2 = 0.0, P_z_mag_3 = 0.0, P_z_mag_4 = 0.0, P_z_mag_5 = 0.0, P_z_mag_6 = 0.0, P_z_mag_7 = 0.0;
	long double P_zz_mag_1 = 0.0, P_zz_mag_2 = 0.0, P_zz_mag_3 = 0.0, P_zz_mag_4 = 0.0, P_zz_mag_5 = 0.0, P_zz_mag_6 = 0.0, P_zz_mag_7 = 0.0;

	long double P_z_tube = 0.0;
	long double P_zz_tube = 0.0;

	long double B_min_mu = 0.0;
	long double B_max_mu = 0.0;
	size_t N_mu = 0;


	long double r_min_mag_table = 0.0;
	long double r_max_mag_table = 0.0;


	const long double mu_bor_temp = 5.788381806638*pow(10.0, 13.0)*pow(2.99792458, 2.0); // магнетон Бора электронный в единицах эВ/Гс*(скорость света [мм/c])^2

																				   //	const long double mu_bor = 3.152451260522*pow(10.0, 10.0)*pow(2.99792458, 2.0); // магнетон Бора ядерный в единицах эВ/Гс*(скорость света [мм/c])^2;
	const long double mu_bor_force_temp = 9.2740096820*pow(10.0, 0.0);


	const long double mu_temp_const_0_H = 0.9996530*mu_bor_temp;
	const long double mu_force_temp_const_0_H = 0.9996530*mu_bor_force_temp;

	const long double mu_temp_const_1_H = 0.9995099*mu_bor_temp;
	const long double mu_force_temp_const_1_H = 0.9995099*mu_bor_force_temp;

	const long double mu_temp_const_2_H = -0.9996530*mu_bor_temp;
	const long double mu_force_temp_const_2_H = -0.9996530*mu_bor_force_temp;


	const long double mu_temp_const_3_H = -0.9996099*mu_bor_temp;
	const long double mu_force_temp_const_3_H = -0.9996099*mu_bor_force_temp;


	const long double mu_temp_const_0_D = 0.9996097*mu_bor_temp;
	const long double mu_force_temp_const_0_D = 0.9996097*mu_bor_force_temp;

	const long double mu_temp_const_1_D = 0.9996029*mu_bor_temp;
	const long double mu_force_temp_const_1_D = 0.9996029*mu_bor_force_temp;

	const long double mu_temp_const_2_D = 0.9996029*mu_bor_temp;
	const long double mu_force_temp_const_2_D = 0.9996029*mu_bor_force_temp;


	const long double mu_temp_const_3_D = -0.9996097*mu_bor_temp;
	const long double mu_force_temp_const_3_D = -0.9996097*mu_bor_force_temp;

	const long double mu_temp_const_4_D = -0.9996029*mu_bor_temp;
	const long double mu_force_temp_const_4_D = -0.9996029*mu_bor_force_temp;

	const long double mu_temp_const_5_D = -0.9996029*mu_bor_temp;
	const long double mu_force_temp_const_5_D = 0.0*mu_bor_force_temp;


	const long double mu_temp_const_0_H_2 = 0.0*mu_bor_temp;
	const long double mu_force_temp_const_0_H_2 = 0.0*mu_bor_force_temp;

	const long double mu_temp_const_1_H_2 = 0.0*mu_bor_temp;
	const long double mu_force_temp_const_1_H_2 = 0.0*mu_bor_force_temp;

	const long double mu_temp_const_2_H_2 = 0.0*mu_bor_temp;
	const long double mu_force_temp_const_2_H_2 = 0.0*mu_bor_force_temp;


	const long double mu_temp_const_3_H_2 = 0.0*mu_bor_temp;
	const long double mu_force_temp_const_3_H_2 = 0.0*mu_bor_force_temp;

	const long double mu_temp_const_4_H_2 = 0.0*mu_bor_temp;
	const long double mu_force_temp_const_4_H_2 = 0.0*mu_bor_force_temp;

	const long double mu_temp_const_5_H_2 = 0.0*mu_bor_temp;
	const long double mu_force_temp_const_5_H_2 = 0.0*mu_bor_force_temp;


	const long double mu_temp_const_6_H_2 = 0.00352197*mu_bor_temp;
	const long double mu_force_temp_const_6_H_2 = 0.00352197*mu_bor_force_temp;

	const long double mu_temp_const_7_H_2 = 0.003042107*mu_bor_temp;
	const long double mu_force_temp_const_7_H_2 = 0.003042107*mu_bor_force_temp;

	const long double mu_temp_const_8_H_2 = 0.002559724*mu_bor_temp;
	const long double mu_force_temp_const_8_H_2 = 0.002559724*mu_bor_force_temp;


	const long double mu_temp_const_9_H_2 = -0.002559849*mu_bor_temp;
	const long double mu_force_temp_const_9_H_2 = -0.002559849*mu_bor_force_temp;

	const long double mu_temp_const_10_H_2 = -0.003042195*mu_bor_temp;
	const long double mu_force_temp_const_10_H_2 = -0.003042195*mu_bor_force_temp;

	const long double mu_temp_const_11_H_2 = -0.003522057*mu_bor_temp;
	const long double mu_force_temp_const_11_H_2 = -0.003522057*mu_bor_force_temp;







	const long double mu_temp_const_0_D_2 = 0.0*mu_bor_temp;
	const long double mu_force_temp_const_0_D_2 = 0.0*mu_bor_force_temp;

	const long double mu_temp_const_1_D_2 = 0.0*mu_bor_temp;
	const long double mu_force_temp_const_1_D_2 = 0.0*mu_bor_force_temp;

	const long double mu_temp_const_2_D_2 = 0.0*mu_bor_temp;
	const long double mu_force_temp_const_2_D_2 = 0.0*mu_bor_force_temp;


	const long double mu_temp_const_3_D_2 = 0.0007075703*mu_bor_temp;
	const long double mu_force_temp_const_3_D_2 = 0.0007075703*mu_bor_force_temp;

	const long double mu_temp_const_4_D_2 = 0.0004665274*mu_bor_temp;
	const long double mu_force_temp_const_4_D_2 = 0.0004665274*mu_bor_force_temp;

	const long double mu_temp_const_5_D_2 = 0.0002236703*mu_bor_temp;
	const long double mu_force_temp_const_5_D_2 = 0.0002236703*mu_bor_force_temp;


	const long double mu_temp_const_6_D_2 = -0.0002239503*mu_bor_temp;
	const long double mu_force_temp_const_6_D_2 = -0.0002239503*mu_bor_force_temp;

	const long double mu_temp_const_7_D_2 = -0.0004665719*mu_bor_temp;
	const long double mu_force_temp_const_7_D_2 = -0.0004665719*mu_bor_force_temp;

	const long double mu_temp_const_8_D_2 = -0.0007076097*mu_bor_temp;
	const long double mu_force_temp_const_8_D_2 = -0.0007076097*mu_bor_force_temp;



	long double m_mag_table = 0.0;








	long double mu_temp_manual = 0.0;

	long double mu_temp = 0.0;
	long double mu_force_temp = 0.0;

	size_t N_negative_cyl_1 = 0, N_zero_cyl_1 = 0, N_positive_cyl_1 = 0;
	size_t N_negative_cyl_2 = 0, N_zero_cyl_2 = 0, N_positive_cyl_2 = 0;
	size_t N_negative_cyl_3 = 0, N_zero_cyl_3 = 0, N_positive_cyl_3 = 0;
	size_t N_negative_cyl_4 = 0, N_zero_cyl_4 = 0, N_positive_cyl_4 = 0;
	size_t N_negative_cyl_5 = 0, N_zero_cyl_5 = 0, N_positive_cyl_5 = 0;
	size_t N_negative_cyl_6 = 0, N_zero_cyl_6 = 0, N_positive_cyl_6 = 0;
	size_t N_negative_cyl_7 = 0, N_zero_cyl_7 = 0, N_positive_cyl_7 = 0;




	size_t N_negative_mag_1 = 0, N_zero_mag_1 = 0, N_positive_mag_1 = 0;
	size_t N_negative_mag_2 = 0, N_zero_mag_2 = 0, N_positive_mag_2 = 0;
	size_t N_negative_mag_3 = 0, N_zero_mag_3 = 0, N_positive_mag_3 = 0;
	size_t N_negative_mag_4 = 0, N_zero_mag_4 = 0, N_positive_mag_4 = 0;
	size_t N_negative_mag_5 = 0, N_zero_mag_5 = 0, N_positive_mag_5 = 0;
	size_t N_negative_mag_6 = 0, N_zero_mag_6 = 0, N_positive_mag_6 = 0;
	size_t N_negative_mag_7 = 0, N_zero_mag_7 = 0, N_positive_mag_7 = 0;


	size_t N_negative_cyl_1_temp = 0, N_zero_cyl_1_temp = 0, N_positive_cyl_1_temp = 0;
	size_t N_negative_cyl_2_temp = 0, N_zero_cyl_2_temp = 0, N_positive_cyl_2_temp = 0;
	size_t N_negative_cyl_3_temp = 0, N_zero_cyl_3_temp = 0, N_positive_cyl_3_temp = 0;
	size_t N_negative_cyl_4_temp = 0, N_zero_cyl_4_temp = 0, N_positive_cyl_4_temp = 0;
	size_t N_negative_cyl_5_temp = 0, N_zero_cyl_5_temp = 0, N_positive_cyl_5_temp = 0;
	size_t N_negative_cyl_6_temp = 0, N_zero_cyl_6_temp = 0, N_positive_cyl_6_temp = 0;
	size_t N_negative_cyl_7_temp = 0, N_zero_cyl_7_temp = 0, N_positive_cyl_7_temp = 0;



	size_t N_negative_mag_1_temp = 0, N_zero_mag_1_temp = 0, N_positive_mag_1_temp = 0;
	size_t N_negative_mag_2_temp = 0, N_zero_mag_2_temp = 0, N_positive_mag_2_temp = 0;
	size_t N_negative_mag_3_temp = 0, N_zero_mag_3_temp = 0, N_positive_mag_3_temp = 0;
	size_t N_negative_mag_4_temp = 0, N_zero_mag_4_temp = 0, N_positive_mag_4_temp = 0;
	size_t N_negative_mag_5_temp = 0, N_zero_mag_5_temp = 0, N_positive_mag_5_temp = 0;
	size_t N_negative_mag_6_temp = 0, N_zero_mag_6_temp = 0, N_positive_mag_6_temp = 0;
	size_t N_negative_mag_7_temp = 0, N_zero_mag_7_temp = 0, N_positive_mag_7_temp = 0;
	



	size_t N_negative_tube = 0, N_zero_tube = 0, N_positive_tube = 0;


	size_t multi_slot_nozzle = 1;


	size_t еrrоr_symm_type = 1;

	bool flaq_trajectory_on_off_z = false;


	long double L_mag_1_B_off_after = 0.0;		 // длина после магнита где нет поля
	long double L_mag_2_B_off_after = 0.0;
	long double L_mag_3_B_off_after = 0.0;
	long double L_mag_4_B_off_after = 0.0;
	long double L_mag_5_B_off_after = 0.0;
	long double L_mag_6_B_off_after = 0.0;
	long double L_mag_7_B_off_after = 0.0;


	bool on_off_all_field = false;

	bool on_off_random_state_generation = true;

	long double type_of_sign_magnetic_momentum = 0.0;


	//открываем файл с входными данными в режиме чтения
	cout << endl;
	cout << "Открытие файла с входными данными..." << endl;
	FILE *F;
	fopen_s(&F, "in.txt", "r");


	//если открытие файла прошло некорректно, то вывод
	//сообщения об отсутствии такого файла
	if (F == NULL) {
		fprintf(stderr, "Ошибка открытия выводного файла.\n");
		cout << endl;
		SleepEx(40, true); // пауза для того, чтобы успеть прочитать информацию
		exit(1);
	}


	else {

		cout << "Чтение данных..." << endl;
		cout << endl;

		setlocale(LC_ALL, "C"); // установить используемую системой локаль для корректной отображении точки в выходном файле

		int i = 0; // индекс массива

		const std::size_t SIZE = n;
		//const int MAX_SIZE = 255;
		const std::size_t MAX_SIZE = 513;



		char **str = new char*[SIZE];
		for (int ii = 0; ii < SIZE; ii++) {
			str[ii] = new char[MAX_SIZE];
		}



		//цикл для чтения значений из файла; выполнение цикла прервется,
		//когда достигнем конца файла, в этом случае F.eof() вернет истину.
		while (!feof(F)) {
			//while(	fscanf_s(F, "%Lf", &mass[i]) != EOF)

			SleepEx(5, true); // пауза для того, чтобы успеть прочитать информацию
							   //чтение очередного значения из потока F в переменную mass
			cout << " .";

			if (i == (int)(n / 8.0)) { //-V112
				cout << endl;
			}

			if (i == (int)(2.0 * n / 8.0)) { //-V112
				cout << endl;
			}

			if (i == (int)(3.0 * n / 8.0)) { //-V112
				cout << endl;
			}

			if (i == (int)(4.0 * n / 8.0)) { //-V112
				cout << endl;
			}

			if (i == (int)(5.0 * n / 8.0)) { //-V112
				cout << endl;
			}

			if (i == (int)(6.0 * n / 8.0)) { //-V112
				cout << endl;
			}

			if (i == (int)(7.0 * n / 8.0)) { //-V112
				cout << endl;
			}


			//чтение очередного значения из потока F в переменную mass
			fscanf_s(F, "%Lf // %s", &mass[i], str[i], (unsigned int)MAX_SIZE + 1); /* чтение из файла */
																					//fscanf_s(F, "%Lf", &mass[i]); /* чтение из файла */

			i = i + 1;

		}

		for (i = 0; i < SIZE; i++) {
			delete[] str[i];
		}

		delete[] str;

		str = nullptr;

		setlocale(LC_ALL, "rus"); // корректное отображение Кириллицы

		cout << endl;
		cout << endl;
		cout << "Чтение данных завершено." << endl;

	}


	//закрытие потока

	fclose(F);



	/*


	for (int i = 0; i < 100; i = i + 1) {

		cout << Vector_r_magnetic_field_table[i] << " " << Vector_B_magnetic_field_table[i] << endl;
	}

	*/
	// присваиваем данные из входного файла начальным константам задачи


	// первый цилиндр
	R1_1 = mass[0]; // большой радиус цилиндра
	R2_1 = mass[1]; // внешний радиус кольца
	R3_1 = mass[2]; // внутренний радиус кольца
	L_1 = mass[3]; // длина цилиндра


				   // второй цилиндр
	R1_2 = mass[4]; // большой радиус цилиндра
	R2_2 = mass[5]; // внешний радиус кольца
	R3_2 = mass[6]; // внутренний радиус кольца
	L_2 = mass[7]; // длина цилиндра

				   // третий цилиндр
	R1_3 = mass[8]; // большой радиус цилиндра
	R2_3 = mass[9]; // внешний радиус кольца
	R3_3 = mass[10]; // внутренний радиус кольца
	L_3 = mass[11]; // длина цилиндра


					// четвертый цилиндр
	R1_4 = mass[130]; // большой радиус цилиндра
	R2_4 = mass[131]; // внешний радиус кольца
	R3_4 = mass[132]; // внутренний радиус кольца
	L_4 = mass[133]; // длина цилиндра

					 // пятый цилиндр
	R1_5 = mass[134]; // большой радиус цилиндра
	R2_5 = mass[135]; // внешний радиус кольца
	R3_5 = mass[136]; // внутренний радиус кольца
	L_5 = mass[137]; // длина цилиндра


					 // шестой цилиндр
	R1_6 = mass[138]; // большой радиус цилиндра
	R2_6 = mass[139]; // внешний радиус кольца
	R3_6 = mass[140]; // внутренний радиус кольца
	L_6 = mass[141]; // длина цилиндра

					 // седьмой цилиндр
	R1_7 = mass[142]; // большой радиус цилиндра
	R2_7 = mass[143]; // внешний радиус кольца
	R3_7 = mass[144]; // внутренний радиус кольца
	L_7 = mass[145]; // длина цилиндра



	R1_8 = mass[12]; // большой радиус цилиндра
	R2_8 = mass[13]; // внешний радиус кольца
	R3_8 = mass[14]; // внутренний радиус кольца


	b1_left = mass[15];
	b1_surface = mass[16];
	b1_right = mass[17];

	b2_left = mass[18];
	b2_surface = mass[19];
	b2_right = mass[20];

	b3_left = mass[21];
	b3_surface = mass[22];
	b3_right = mass[23];

	b4_left = mass[146];
	b4_surface = mass[147];
	b4_right = mass[148];


	b5_left = mass[149];
	b5_surface = mass[150];
	b5_right = mass[151];

	b6_left = mass[152];
	b6_surface = mass[153];
	b6_right = mass[154];

	b7_left = mass[155];
	b7_surface = mass[156];
	b7_right = mass[157];

	V_0 = mass[24]; // начальная скорость
	N = (std::size_t)mass[25]; // число частиц
	N_histo = (std::size_t)mass[26]; //число бинов гистограммы распределения
	R = mass[27];

	n1 = (std::size_t)mass[28];
	n2 = (std::size_t)mass[29];
	n3 = (std::size_t)mass[30];
	n4 = (std::size_t)mass[157];
	n5 = (std::size_t)mass[159];
	n6 = (std::size_t)mass[160];
	n7 = (std::size_t)mass[161];

	n_travel = (std::size_t)mass[31];

	t = mass[32];



	theta1_diffusion_left = mass[33];
	theta1_diffusion_surface = mass[34];
	theta1_diffusion_right = mass[35];

	theta2_diffusion_left = mass[36];
	theta2_diffusion_surface = mass[37];
	theta2_diffusion_right = mass[38];

	theta3_diffusion_left = mass[39];
	theta3_diffusion_surface = mass[40];
	theta3_diffusion_right = mass[41];


	theta4_diffusion_left = mass[162];
	theta4_diffusion_surface = mass[163];
	theta4_diffusion_right = mass[164];

	theta5_diffusion_left = mass[165];
	theta5_diffusion_surface = mass[166];
	theta5_diffusion_right = mass[167];

	theta6_diffusion_left = mass[168];
	theta6_diffusion_surface = mass[169];
	theta6_diffusion_right = mass[170];

	theta7_diffusion_left = mass[171];
	theta7_diffusion_surface = mass[172];
	theta7_diffusion_right = mass[173];

	R_source = mass[42]; // радиус кольца детектора
	N_histo_source = (std::size_t)mass[43]; //число точек, измеренных детектором
	x_0_source = mass[44];


	z0_mag1 = mass[45];
	L_mag1 = mass[46];

	z0_mag2 = mass[47];
	L_mag2 = mass[48];

	z0_mag3 = mass[49];
	L_mag3 = mass[50];

	z0_mag4 = mass[174];
	L_mag4 = mass[175];

	z0_mag5 = mass[176];
	L_mag5 = mass[177];

	z0_mag6 = mass[178];
	L_mag6 = mass[179];

	z0_mag7 = mass[180];
	L_mag7 = mass[181];


	B1_max_initial = mass[51];
	B2_max_initial = mass[52];
	B3_max_initial = mass[53];
	B4_max_initial = mass[182];
	B5_max_initial = mass[183];
	B6_max_initial = mass[184];
	B7_max_initial = mass[185];




	B1_max_final = mass[81];
	B2_max_final = mass[82];
	B3_max_final = mass[83];
	B4_max_final = mass[198];
	B5_max_final = mass[199];
	B6_max_final = mass[200];
	B7_max_final = mass[201];

	r1_mag_max_initial = mass[54];
	r2_mag_max_initial = mass[55];
	r3_mag_max_initial = mass[56];
	r4_mag_max_initial = mass[186];
	r5_mag_max_initial = mass[187];
	r6_mag_max_initial = mass[188];
	r7_mag_max_initial = mass[189];

	mu_core_particle = mass[57];

	m_particle = mass[58];

	if (mass[59] == 1.0) { //-V550

		on_off_mag_1 = true;
	}

	if (mass[59] == 0.0) { //-V550

		on_off_mag_1 = false;
	}

	if (mass[60] == 1.0) { //-V550

		on_off_mag_2 = true;
	}

	if (mass[60] == 0.0) { //-V550

		on_off_mag_2 = false;
	}

	if (mass[61] == 1.0) { //-V550

		on_off_mag_3 = true;
	}

	if (mass[61] == 0.0) { //-V550

		on_off_mag_3 = false;
	}


	if (mass[190] == 1.0) { //-V550

		on_off_mag_4 = true;
	}

	if (mass[190] == 0.0) { //-V550

		on_off_mag_4 = false;
	}


	if (mass[191] == 1.0) { //-V550

		on_off_mag_5 = true;
	}

	if (mass[191] == 0.0) { //-V550

		on_off_mag_5 = false;
	}


	if (mass[192] == 1.0) { //-V550

		on_off_mag_6 = true;
	}

	if (mass[192] == 0.0) { //-V550

		on_off_mag_6 = false;
	}


	if (mass[193] == 1.0) { //-V550

		on_off_mag_7 = true;
	}

	if (mass[193] == 0.0) { //-V550

		on_off_mag_7 = false;
	}






	B_critical = mass[62];

	mu_electron_particle = mass[63];

	J_particle = mass[64]; // момент электронной оболочки частицы в единицах постоянной Планка
	I_particle = mass[65]; // спин ядра частицы в единицах постоянной Планка

	m_J = mass[66]; // проекция момента
	m_F = mass[67]; // проекция момента

	r1_mag_max_final = mass[68];
	r2_mag_max_final = mass[69];
	r3_mag_max_final = mass[70];
	r4_mag_max_final = mass[194];
	r5_mag_max_final = mass[195];
	r6_mag_max_final = mass[196];
	r7_mag_max_final = mass[197];

	N_mag_partitions = (size_t)mass[71];


	particle_mode = (size_t)mass[72];

	temp_beam = mass[73];


	if (mass[74] == 0.0) { //-V550

		flaq_Maxwell = false;
	}

	if (mass[74] == 1.0) { //-V550

		flaq_Maxwell = true;
	}

	a_V_0 = mass[75]; // левая граница распределения скоростей
	b_V_0 = mass[76]; // правая граница распределения скоростей



	a_time = 0.0; // левая граница распределения скоростей
	b_time = 0.15; // правая граница распределения скоростей




	N_histo_V_0 = (std::size_t)mass[77];

	//N_histo_time = 1000*(std::size_t)mass[77];

	N_histo_time = 1500;

	N_histo_V_0_out = (std::size_t)mass[77];

	N_histo_V_0_tube_out = (std::size_t)mass[77];

	N_histo_theta_in = (std::size_t)mass[78];

	if (mass[79] == 0.0) { //-V550

		flaq_Maxwell_mode = false;
	}

	if (mass[79] == 1.0) { //-V550

		flaq_Maxwell_mode = true;
	}


	if (mass[80] == 0.0) { //-V550

		average_peak = false;
	}

	if (mass[80] == 1.0) { //-V550

		average_peak = true;
	}


	m_mag_1 = mass[84] / 2.0;
	m_mag_2 = mass[85] / 2.0;
	m_mag_3 = mass[86] / 2.0;
	m_mag_4 = mass[202] / 2.0;
	m_mag_5 = mass[203] / 2.0;
	m_mag_6 = mass[204] / 2.0;
	m_mag_7 = mass[205] / 2.0;



	if (mass[87] == 0.0) { //-V550

		mag_runge_1 = false;
	}

	if (mass[87] == 1.0) { //-V550

		mag_runge_1 = true;
	}


	if (mass[88] == 0.0) { //-V550

		mag_runge_2 = false;
	}

	if (mass[88] == 1.0) { //-V550

		mag_runge_2 = true;
	}


	if (mass[89] == 0.0) { //-V550

		mag_runge_3 = false;
	}

	if (mass[89] == 1.0) { //-V550

		mag_runge_3 = true;
	}


	if (mass[206] == 0.0) { //-V550

		mag_runge_4 = false;
	}

	if (mass[206] == 1.0) { //-V550

		mag_runge_4 = true;
	}

	if (mass[207] == 0.0) { //-V550

		mag_runge_5 = false;
	}

	if (mass[207] == 1.0) { //-V550

		mag_runge_5 = true;
	}

	if (mass[208] == 0.0) { //-V550

		mag_runge_6 = false;
	}

	if (mass[208] == 1.0) { //-V550

		mag_runge_6 = true;
	}

	if (mass[209] == 0.0) { //-V550

		mag_runge_7 = false;
	}

	if (mass[209] == 1.0) { //-V550

		mag_runge_7 = true;
	}


	min_r_out_mag_1 = mass[90];
	min_r_out_mag_2 = mass[91];
	min_r_out_mag_3 = mass[92];
	min_r_out_mag_4 = mass[210];
	min_r_out_mag_5 = mass[211];
	min_r_out_mag_6 = mass[212];
	min_r_out_mag_7 = mass[213];


	min_r_in_mag_1 = mass[93];
	min_r_in_mag_2 = mass[94];
	min_r_in_mag_3 = mass[95];
	min_r_in_mag_4 = mass[214];
	min_r_in_mag_5 = mass[215];
	min_r_in_mag_6 = mass[216];
	min_r_in_mag_7 = mass[217];



	if (mass[96] == 0.0) { //-V550

		flaq_angular_coefficient = false;
	}

	if (mass[96] == 1.0) { //-V550

		flaq_angular_coefficient = true;
		on_off_mag_1 = false;
	}



	if (flaq_angular_coefficient == true) {
		phi_1_2 = 0.0;

	}
	else if (flaq_angular_coefficient == false) {

		phi_1_2 = 1.0;
	}


	iron_mag_1 = mass[97];
	iron_mag_2 = mass[98];
	iron_mag_3 = mass[99];
	iron_mag_4 = mass[218];
	iron_mag_5 = mass[219];
	iron_mag_6 = mass[220];
	iron_mag_7 = mass[221];

	N_CYL_partitions = (size_t)mass[100];

	if (mass[101] == 0.0) { //-V550

		flaq_out_trajectory = false;
		N_CYL_partitions = 1;

	}

	if (mass[101] == 1.0) { //-V550

		flaq_out_trajectory = true;
	}


	b1_mag_left = mass[102];
	b1_mag = mass[103];
	b1_mag_right = mass[104];


	b2_mag_left = mass[105];
	b2_mag = mass[106];
	b2_mag_right = mass[107];


	b3_mag_left = mass[108];
	b3_mag = mass[109];
	b3_mag_right = mass[110];


	b4_mag_left = mass[222];
	b4_mag = mass[223];
	b4_mag_right = mass[224];


	b5_mag_left = mass[225];
	b5_mag = mass[226];
	b5_mag_right = mass[227];


	b6_mag_left = mass[228];
	b6_mag = mass[229];
	b6_mag_right = mass[230];


	b7_mag_left = mass[231];
	b7_mag = mass[232];
	b7_mag_right = mass[233];




	n_cos_intensity = mass[111];

	//	cout << n_cos_intensity << endl;


	N_r_angular = (size_t)mass[112];


	N_phi_angular = (size_t)mass[113];

	N_monte_carlo_cos_intensity = (size_t)mass[114];

	mu_temp_manual = mass[115];

	B_min_mu = mass[116];
	B_max_mu = mass[117];
	N_mu = (size_t)mass[118];


	if (mass[119] == 0.0) { //-V550

		flaq_on_off_B_mu = false;

	}

	if (mass[119] == 1.0) { //-V550

		flaq_on_off_B_mu = true;
	}



	if (mass[120] == 1.0) { //-V550

		on_off_table_magnetic_field = true;
	}

	if (mass[120] == 0.0) { //-V550

		on_off_table_magnetic_field = false;
	}

	r_min_mag_table = mass[121];
	r_max_mag_table = mass[122];


	//	r_max_mag_table = mass[122];



	multi_slot_nozzle = (std::size_t) mass[123];


	еrrоr_symm_type = (std::size_t) mass[124];



	if (mass[125] == 1.0) { //-V550

		flaq_trajectory_on_off_z = true;

		if (flaq_out_trajectory == false) {

			N_CYL_partitions = 1;
		}
	}

	if (mass[125] == 0.0) { //-V550

		flaq_trajectory_on_off_z = false;
	}

	L_mag_1_B_off_after = mass[126];
	L_mag_2_B_off_after = mass[127];
	L_mag_3_B_off_after = mass[128];
	L_mag_4_B_off_after = mass[234];
	L_mag_5_B_off_after = mass[235];
	L_mag_6_B_off_after = mass[236];
	L_mag_7_B_off_after = mass[237];





	if (mass[238] == 1.0) { //-V550

		on_off_all_field = true;

		B1_max_initial = 0.0;
		B2_max_initial = 0.0;
		B3_max_initial = 0.0;
		B4_max_initial = 0.0;
		B5_max_initial = 0.0;
		B6_max_initial = 0.0;
		B7_max_initial = 0.0;

		B1_max_final = 0.0;
		B2_max_final = 0.0;
		B3_max_final = 0.0;
		B4_max_final = 0.0;
		B5_max_final = 0.0;
		B6_max_final = 0.0;
		B7_max_final = 0.0;



	}

	if (mass[238] == 0.0) { //-V550

		on_off_all_field = false;

	  
	}


	if (mass[239] == 0.0) { //-V550

		on_off_random_state_generation = false;


	}

	
	type_of_sign_magnetic_momentum = mass[240];


	drift_velocity = mass[129]; // переносная скорость


	cout << endl;

	ReadFile_magnetic_field_table("in_magnetic_field_table_3D.txt", Vector_r_magnetic_field_table, Vector_phi_magnetic_field_table, Vector_B_magnetic_field_table, Vector_delta_B_magnetic_field_table, Vector_index_r_magnetic_field_table, index_phi_magnetic_field_table, m_mag_table, r_min_mag_table, r_max_mag_table);

	out_magnetic_field_table("out_magnetic_field_table.txt", Vector_r_magnetic_field_table, Vector_phi_magnetic_field_table, Vector_B_magnetic_field_table, Vector_delta_B_magnetic_field_table, Vector_index_r_magnetic_field_table, index_phi_magnetic_field_table, r_min_mag_table, r_max_mag_table);


	out_2_magnetic_field_table("out_2_magnetic_field_table.txt", Vector_r_magnetic_field_table, Vector_phi_magnetic_field_table, Vector_B_magnetic_field_table, Vector_delta_B_magnetic_field_table, Vector_index_r_magnetic_field_table, index_phi_magnetic_field_table, r_min_mag_table, r_max_mag_table);



	//cout<< search_B_magnetic_field_table(Vector_r_magnetic_field_table, Vector_phi_magnetic_field_table,Vector_B_magnetic_field_table, 190.0, 0.104719755, Vector_index_r_magnetic_field_table, index_phi_magnetic_field_table) <<endl;

	//cout << endl;





	//cout << mu_temp_manual << endl;


	long double L_cyl_1 = L_1;
	long double L_cyl_2 = L_2;
	long double L_cyl_3 = L_3;
	long double L_cyl_4 = L_4;
	long double L_cyl_5 = L_5;
	long double L_cyl_6 = L_6;
	long double L_cyl_7 = L_7;

	int min_index_comdotion_H = 0;
	int max_index_comdotion_H = 0;

	int min_index_comdotion_D = 0;
	int max_index_comdotion_D = 0;


	int min_index_comdotion_H2 = 0;
	int max_index_comdotion_H2 = 0;

	int min_index_comdotion_D2 = 0;
	int max_index_comdotion_D2 = 0;


	if (particle_mode == 1) {


		if (on_off_random_state_generation == true) {
			min_index_comdotion_H = 0;
			max_index_comdotion_H = 3;

		}
		else

			if (on_off_random_state_generation == false) {


				if (type_of_sign_magnetic_momentum == 1.0) {

					min_index_comdotion_H = 0;
					max_index_comdotion_H = 1;


				}

				if (type_of_sign_magnetic_momentum == 0.0) {



					min_index_comdotion_H = 0;
					max_index_comdotion_H = 3;


				}


				if (type_of_sign_magnetic_momentum == -1.0) {


					min_index_comdotion_H = 2;
					max_index_comdotion_H = 3;

				}

			}

	}


	if (particle_mode == 2) {


		if (on_off_random_state_generation == true) {
			min_index_comdotion_D = 0;
			max_index_comdotion_D = 5;

		}
		else

			if (on_off_random_state_generation == false) {


				if (type_of_sign_magnetic_momentum == 1.0) {

					min_index_comdotion_D = 2;
					max_index_comdotion_D = 3;


				}

				if (type_of_sign_magnetic_momentum == 0.0) {



					min_index_comdotion_D = 0;
					max_index_comdotion_D = 1;


				}


				if (type_of_sign_magnetic_momentum == -1.0) {


					min_index_comdotion_D = 4;
					max_index_comdotion_D = 5;

				}

			}

	}



	if (particle_mode == 3) {


		if (on_off_random_state_generation == true) {
			min_index_comdotion_H2 = 0;
			max_index_comdotion_H2 = 11;

		} else

		if (on_off_random_state_generation == false) {


			if (type_of_sign_magnetic_momentum == 1.0) {

				min_index_comdotion_H2 = 6;
				max_index_comdotion_H2 = 8;


			}

			if (type_of_sign_magnetic_momentum == 0.0) {



				min_index_comdotion_H2 = 0;
				max_index_comdotion_H2 = 5;


			}


			if (type_of_sign_magnetic_momentum == -1.0) {


				min_index_comdotion_H2 = 9;
				max_index_comdotion_H2 = 11;

			}

		}

	}


	if (particle_mode == 4) {


		if (on_off_random_state_generation == true) {
			min_index_comdotion_D2 = 0;
			max_index_comdotion_D2 = 8;

		}
		else

			if (on_off_random_state_generation == false) {


				if (type_of_sign_magnetic_momentum == 1.0) {

					min_index_comdotion_D2 = 3;
					max_index_comdotion_D2 = 5;


				}

				if (type_of_sign_magnetic_momentum == 0.0) {



					min_index_comdotion_D2 = 0;
					max_index_comdotion_D2 = 2;


				}


				if (type_of_sign_magnetic_momentum == -1.0) {


					min_index_comdotion_D2 = 6;
					max_index_comdotion_D2 = 7;

				}

			}

	}








	out_mu_H("out_mu_H.txt", B_min_mu, B_max_mu, N_mu);

	out_mu_D("out_mu_D.txt", B_min_mu, B_max_mu, N_mu);

	out_mu_H_2("out_mu_H_2.txt", B_min_mu, B_max_mu, N_mu);

	out_mu_D_2("out_mu_D_2.txt", B_min_mu, B_max_mu, N_mu);


	// вывод начальных значений на экран

	cout << endl;
	cout << "Входные данные:" << endl;

	cout << endl;
	cout << "------------------------------" << endl;
	cout << endl;
	cout << "Начальные данные" << endl;
	cout << endl;
	cout << "Скорость (мм/сек) ||" << " Число Частиц (штук) ||" << " Число Бинов (штук) ||" << " Радиус Экрана (мм)" << " Максимальное время счета (мин.)" << endl;
	cout << endl;
	printf("%.2Lf\t  %.4Le\t %.0Lf\t %.2Lf\t %.2Lf\n", V_0, (long double)N, (long double)N_histo, R, t);

	cout << endl;
	cout << "Первый цилиндр" << endl;
	cout << "Коэфф. Захвата 1 левый ||" << " Коэфф. Захвата 1 поверхность ||" << " Коэфф. Захвата 1 правый" << endl;
	printf("%.2Lf\t  %.2Lf\t %.2Lf\n", b1_left, b1_surface, b1_right);
	cout << endl;
	cout << "Второй цилиндр" << endl;
	cout << "Коэфф. Захвата 2 левый ||" << " Коэфф. Захвата 2 поверхность ||" << " Коэфф. Захвата 2 правый" << endl;
	printf("%.2Lf\t  %.2Lf\t %.2Lf\n", b2_left, b2_surface, b2_right);
	cout << endl;
	cout << "Третий цилиндр" << endl;
	cout << "Коэфф. Захвата 3 левый ||" << " Коэфф. Захвата 3 поверхность ||" << " Коэфф. Захвата 3 правый" << endl;
	printf("%.2Lf\t  %.2Lf\t %.2Lf\n", b3_left, b3_surface, b3_right);
	cout << endl;
	cout << "Четвертый цилиндр" << endl;
	cout << "Коэфф. Захвата 4 левый ||" << " Коэфф. Захвата 4 поверхность ||" << " Коэфф. Захвата 4 правый" << endl;
	printf("%.2Lf\t  %.2Lf\t %.2Lf\n", b4_left, b4_surface, b4_right);
	cout << endl;
	cout << "Пятый цилиндр" << endl;
	cout << "Коэфф. Захвата 5 левый ||" << " Коэфф. Захвата 5 поверхность ||" << " Коэфф. Захвата 5 правый" << endl;
	printf("%.2Lf\t  %.2Lf\t %.2Lf\n", b5_left, b5_surface, b5_right);
	cout << endl;
	cout << "Шестой цилиндр" << endl;
	cout << "Коэфф. Захвата 6 левый ||" << " Коэфф. Захвата 6 поверхность ||" << " Коэфф. Захвата 6 правый" << endl;
	printf("%.2Lf\t  %.2Lf\t %.2Lf\n", b6_left, b6_surface, b6_right);
	cout << endl;
	cout << "Седьмой цилиндр" << endl;
	cout << "Коэфф. Захвата 7 левый ||" << " Коэфф. Захвата 7 поверхность ||" << " Коэфф. Захвата 7 правый" << endl;
	printf("%.2Lf\t  %.2Lf\t %.2Lf\n", b7_left, b7_surface, b7_right);
	cout << endl;


	printf("(Цилиндр №1) Дифф. Угол Левого торца = %.2Lf рад. Дифф. Угол Поверхности Образующей = %.2Lf рад. Дифф. Угол Правого торца = %.2Lf рад.\n", theta1_diffusion_left, theta1_diffusion_surface, theta1_diffusion_surface);
	printf("(Цилиндр №2) Дифф. Угол Левого торца = %.2Lf рад. Дифф. Угол Поверхности Образующей = %.2Lf рад. Дифф. Угол Правого торца = %.2Lf рад.\n", theta2_diffusion_left, theta2_diffusion_surface, theta2_diffusion_surface);
	printf("(Цилиндр №3) Дифф. Угол Левого торца = %.2Lf рад. Дифф. Угол Поверхности Образующей = %.2Lf рад. Дифф. Угол Правого торца = %.2Lf рад.\n", theta3_diffusion_left, theta3_diffusion_surface, theta3_diffusion_surface);
	printf("(Цилиндр №4) Дифф. Угол Левого торца = %.2Lf рад. Дифф. Угол Поверхности Образующей = %.2Lf рад. Дифф. Угол Правого торца = %.2Lf рад.\n", theta4_diffusion_left, theta4_diffusion_surface, theta4_diffusion_surface);
	printf("(Цилиндр №5) Дифф. Угол Левого торца = %.2Lf рад. Дифф. Угол Поверхности Образующей = %.2Lf рад. Дифф. Угол Правого торца = %.2Lf рад.\n", theta5_diffusion_left, theta5_diffusion_surface, theta5_diffusion_surface);
	printf("(Цилиндр №6) Дифф. Угол Левого торца = %.2Lf рад. Дифф. Угол Поверхности Образующей = %.2Lf рад. Дифф. Угол Правого торца = %.2Lf рад.\n", theta6_diffusion_left, theta6_diffusion_surface, theta6_diffusion_surface);
	printf("(Цилиндр №7) Дифф. Угол Левого торца = %.2Lf рад. Дифф. Угол Поверхности Образующей = %.2Lf рад. Дифф. Угол Правого торца = %.2Lf рад.\n", theta7_diffusion_left, theta7_diffusion_surface, theta7_diffusion_surface);







	cout << endl;
	printf("(Цилиндр №1) Максимальное число столкновений о стенки = %.0Lf ударов\n", (long double)n1);
	printf("(Цилиндр №2) Максимальное число столкновений о стенки = %.0Lf ударов\n", (long double)n2);
	printf("(Цилиндр №3) Максимальное число столкновений о стенки = %.0Lf ударов\n", (long double)n3);
	printf("(Цилиндр №4) Максимальное число столкновений о стенки = %.0Lf ударов\n", (long double)n4);
	printf("(Цилиндр №5) Максимальное число столкновений о стенки = %.0Lf ударов\n", (long double)n5);
	printf("(Цилиндр №6) Максимальное число столкновений о стенки = %.0Lf ударов\n", (long double)n6);
	printf("(Цилиндр №7) Максимальное число столкновений о стенки = %.0Lf ударов\n", (long double)n7);
	printf("Максимальное число переходов частицы между цилиндрами №1,2,3 = %.0Lf переходов\n", (long double)n_travel);

	//for (int i = 10; i <= 13; i++) {
	//	cout << mass[i] << "  \t";

	//}
	
	
	SleepEx(20, true); // пауза для того, чтобы успеть прочитать информацию
	cout << endl;
	cout << endl;
	cout << "------------------------------" << endl;
	cout << endl;
	cout << "Первый цилиндр" << endl;
	cout << endl;
	cout << "R1_1 мм ||" << " R2_1 мм ||" << " R3_1 мм ||" << " L_1 мм" << endl;
	cout << endl;
	for (int i = 0; i <= 3; i++) {
		cout << mass[i] << "  \t";

	}


	SleepEx(20, true); // пауза для того, чтобы успеть прочитать информацию
	cout << endl;
	cout << endl;
	cout << "------------------------------" << endl;
	cout << endl;
	cout << "Второй цилиндр" << endl;
	cout << endl;
	cout << "R1_2 мм ||" << " R2_2 мм ||" << " R3_2 мм ||" << " L_2 мм" << endl;
	cout << endl;
	for (size_t i = 4; i <= 7; i++) { //-V112
		cout << mass[i] << "  \t";

	}


	SleepEx(20, true); // пауза для того, чтобы успеть прочитать информацию
	cout << endl;
	cout << endl;
	cout << "------------------------------" << endl;
	cout << endl;
	cout << "Третий цилиндр" << endl;
	cout << endl;
	cout << "R1_3 мм ||" << " R2_3 мм ||" << " R3_3 мм ||" << " L_3 мм" << endl;
	cout << endl;
	for (int i = 8; i <= 11; i++) {
		cout << mass[i] << "  \t";

	}


	SleepEx(20, true); // пауза для того, чтобы успеть прочитать информацию
	cout << endl;
	cout << endl;
	cout << "------------------------------" << endl;
	cout << endl;
	cout << "Четвертый цилиндр" << endl;
	cout << endl;
	cout << "R1_4 мм ||" << " R2_4 мм ||" << " R3_4 мм ||" << " L_4 мм" << endl;
	cout << endl;
	for (int i = 130; i <= 133; i++) {
		cout << mass[i] << "  \t";

	}

	SleepEx(20, true); // пауза для того, чтобы успеть прочитать информацию
	cout << endl;
	cout << endl;
	cout << "------------------------------" << endl;
	cout << endl;
	cout << "Пятый цилиндр" << endl;
	cout << endl;
	cout << "R1_5 мм ||" << " R2_5 мм ||" << " R3_5 мм ||" << " L_5 мм" << endl;
	cout << endl;
	for (int i = 134; i <= 137; i++) {
		cout << mass[i] << "  \t";

	}


	SleepEx(20, true); // пауза для того, чтобы успеть прочитать информацию
	cout << endl;
	cout << endl;
	cout << "------------------------------" << endl;
	cout << endl;
	cout << "Шестой цилиндр" << endl;
	cout << endl;
	cout << "R1_6 мм ||" << " R2_6 мм ||" << " R3_6 мм ||" << " L_6 мм" << endl;
	cout << endl;
	for (int i = 138; i <= 141; i++) {
		cout << mass[i] << "  \t";

	}


	SleepEx(20, true); // пауза для того, чтобы успеть прочитать информацию
	cout << endl;
	cout << endl;
	cout << "------------------------------" << endl;
	cout << endl;
	cout << "Седьмой цилиндр" << endl;
	cout << endl;
	cout << "R1_7 мм ||" << " R2_7 мм ||" << " R3_7 мм ||" << " L_7 мм" << endl;
	cout << endl;
	for (int i = 142; i <= 145; i++) {
		cout << mass[i] << "  \t";

	}


	cout << endl;
	cout << endl;
	cout << "R1_8 мм ||" << " R2_8 мм ||" << " R3_8 мм" << endl;
	cout << endl;
	for (int i = 12; i <= 14; i++) {
		cout << mass[i] << "  \t";

	}

	cout << endl;
	cout << endl;
	cout << "------------------------------" << endl;

	SleepEx(40, true); // пауза для того, чтобы успеть прочитать информацию


	cout << endl;

	printf("Максимальный радиус экрана = %.2Lf мм\n", R);
	printf("Усреднение по двум полуплоскостям на экране = %s\n", (average_peak ? "Отключено" : "Включено"));
	printf("Радиус кольца детектора = %.2Lf мм\n", R_source);
	printf("Координата x_0 детектора = %.2Lf мм\n", x_0_source);
	printf("Число точек, измеренных детектором = %.0Lf точек\n", (long double)N_histo_source);


	cout << endl;
	cout << "------------------------------" << endl;
	cout << endl;

	printf("Расстояние магнита от левого_торца цилиндра (первый цилиндр) = %.2Lf мм\n", z0_mag1);
	printf("Длина магнита (первый цилиндр) = %.2Lf мм\n", L_mag1);
	printf("Максимальное магнитное поле (первый цилиндр) = %.2Lf Гс\n", B1_max_initial);
	printf("Максимальный начальный радиус магнита (первый цилиндр) = %.2Lf мм\n", r1_mag_max_initial);
	printf("Максимальный конечный радиус магнита (первый цилиндр) = %.2Lf мм\n", r1_mag_max_final);
	printf("Наличие магнита (первый цилиндр) = %s\n", (on_off_mag_1 ? "Да" : "Нет"));
	//printf("Наличие магнита (первый цилиндр) = %.0Lf\n", on_off_mag_1);


	cout << endl;

	printf("Расстояние магнита от левого_торца цилиндра (второй цилиндр) = %.2Lf мм\n", z0_mag2);
	printf("Длина магнита (второй цилиндр) = %.2Lf мм\n", L_mag2);
	printf("Максимальное магнитное поле (второй цилиндр) = %.2Lf Гс\n", B2_max_initial);
	printf("Максимальный начальный радиус магнита (второй цилиндр) = %.2Lf мм\n", r2_mag_max_initial);
	printf("Максимальный конечный радиус магнита (второй цилиндр) = %.2Lf мм\n", r2_mag_max_final);
	printf("Наличие магнита (второй цилиндр) = %s\n", (on_off_mag_2 ? "Да" : "Нет"));
	//printf("Наличие магнита (второй цилиндр) = %.0Lf\n", on_off_mag_2);
	cout << endl;

	printf("Расстояние магнита от левого_торца цилиндра (третий цилиндр) = %.2Lf мм\n", z0_mag3);
	printf("Длина магнита (третий цилиндр) = %.2Lf мм\n", L_mag3);
	printf("Максимальное магнитное поле (третий цилиндр) = %.2Lf Гс\n", B3_max_initial);
	printf("Максимальный начальный радиус магнита (третий цилиндр) = %.2Lf мм\n", r3_mag_max_initial);
	printf("Максимальный конечный радиус магнита (третий цилиндр) = %.2Lf мм\n", r3_mag_max_final);
	printf("Наличие магнита (третий цилиндр) = %s\n", (on_off_mag_3 ? "Да" : "Нет"));
	//printf("Наличие магнита (третий цилиндр) = %.0Lf\n", on_off_mag_3);


	cout << endl;

	printf("Расстояние магнита от левого_торца цилиндра (четвертый цилиндр) = %.2Lf мм\n", z0_mag4);
	printf("Длина магнита (четвертый цилиндр) = %.2Lf мм\n", L_mag4);
	printf("Максимальное магнитное поле (четвертый цилиндр) = %.2Lf Гс\n", B4_max_initial);
	printf("Максимальный начальный радиус магнита (четвертый цилиндр) = %.2Lf мм\n", r4_mag_max_initial);
	printf("Максимальный конечный радиус магнита (четвертый цилиндр) = %.2Lf мм\n", r4_mag_max_final);
	printf("Наличие магнита (четвертый цилиндр) = %s\n", (on_off_mag_4 ? "Да" : "Нет"));
	//printf("Наличие магнита (третий цилиндр) = %.0Lf\n", on_off_mag_3);


	cout << endl;

	cout << endl;

	printf("Расстояние магнита от левого_торца цилиндра (пятый цилиндр) = %.2Lf мм\n", z0_mag5);
	printf("Длина магнита (пятый цилиндр) = %.2Lf мм\n", L_mag5);
	printf("Максимальное магнитное поле (пятый цилиндр) = %.2Lf Гс\n", B5_max_initial);
	printf("Максимальный начальный радиус магнита (пятый цилиндр) = %.2Lf мм\n", r5_mag_max_initial);
	printf("Максимальный конечный радиус магнита (пятый цилиндр) = %.2Lf мм\n", r5_mag_max_final);
	printf("Наличие магнита (пятый цилиндр) = %s\n", (on_off_mag_5 ? "Да" : "Нет"));
	//printf("Наличие магнита (третий цилиндр) = %.0Lf\n", on_off_mag_3);


	cout << endl;

	printf("Расстояние магнита от левого_торца цилиндра (шестой цилиндр) = %.2Lf мм\n", z0_mag6);
	printf("Длина магнита (шестой цилиндр) = %.2Lf мм\n", L_mag6);
	printf("Максимальное магнитное поле (шестой цилиндр) = %.2Lf Гс\n", B6_max_initial);
	printf("Максимальный начальный радиус магнита (шестой цилиндр) = %.2Lf мм\n", r6_mag_max_initial);
	printf("Максимальный конечный радиус магнита (шестой цилиндр) = %.2Lf мм\n", r6_mag_max_final);
	printf("Наличие магнита (шестой цилиндр) = %s\n", (on_off_mag_6 ? "Да" : "Нет"));
	//printf("Наличие магнита (третий цилиндр) = %.0Lf\n", on_off_mag_3);


	cout << endl;

	printf("Расстояние магнита от левого_торца цилиндра (седьмой цилиндр) = %.2Lf мм\n", z0_mag7);
	printf("Длина магнита (седьмой цилиндр) = %.2Lf мм\n", L_mag7);
	printf("Максимальное магнитное поле (седьмой цилиндр) = %.2Lf Гс\n", B7_max_initial);
	printf("Максимальный начальный радиус магнита (седьмой цилиндр) = %.2Lf мм\n", r7_mag_max_initial);
	printf("Максимальный конечный радиус магнита (седьмой цилиндр) = %.2Lf мм\n", r7_mag_max_final);
	printf("Наличие магнита (седьмой цилиндр) = %s\n", (on_off_mag_7 ? "Да" : "Нет"));
	//printf("Наличие магнита (третий цилиндр) = %.0Lf\n", on_off_mag_3);


	cout << endl;

	cout << "------------------------------" << endl;

	cout << endl;
	printf("Магнитный момент ядра частицы g_I = %.9Le\n", mu_core_particle);
	printf("Магнитный момент электронной оболочки частицы g_J = %.9Le\n", mu_electron_particle);
	printf("Масса частицы m = %.9Le МэВ\n", m_particle);
	printf("Спин ядра частицы I= %.9Le\n", I_particle);
	printf("Момент электронной оболочки частицы J=L+S = %.9Le\n", J_particle);
	printf("Проекция момента электронной оболочки частицы m_J = %.9Le\n", m_J);
	printf("Критическое поле частицы B_critical = %.9Le Гс\n", B_critical);
	printf("Проекция полного момента F=I+J частицы m_F = %.9Le\n", m_F);
	printf("Число разбиений магнита = %.0Lf разбиений\n", (long double)N_mag_partitions);
	printf("Температура пучка частиц = %.3Lf Кельвинов\n", (long double)temp_beam);
	printf("Распределение по модулю скорости = %s\n", (flaq_Maxwell ? " Распределение Максвелла по модулю скорости" : "Дельта функция"));
	printf("Режим распределения Максвелла = %s\n", (flaq_Maxwell_mode ? "Обычнное по модулю скорости" : "Распределение Максвелла для пучка"));
	printf("Левая граница для распределения по модулю скорости  = %.9Le мм/сек\n", a_V_0);
	printf("Певая граница для распределения по модулю скорости  = %.9Le мм/сек\n", b_V_0);
	printf("Число точек гистограммы распределения по модулю скорости  = %.9Le точек\n", (long double)N_histo_V_0);
	printf("Число точек гистограммы распределения по углу theta частиц, вылетающих из кольца источника  = %.9Le точек\n", (long double)N_histo_theta_in);




	if (particle_mode == 0) {
		printf("Режим частиц = ручной ввод состояния (particle mode = %.0Lf)\n", (long double)particle_mode);
	}
	else if (particle_mode == 1) {

		printf("Режим частиц = режим водорода (случайное выбирание подсостояния из возможных для водорода) (particle mode = %.0Lf)\n", (long double)particle_mode);

	}
	else if (particle_mode == 2) {

		printf("Режим частиц = режим дейтерия (случайное выбирание подсостояния из возможных для дейтерия) (particle mode = %.0Lf)\n", (long double)particle_mode);
	}
	else {

		printf("Введено неправильное значение particle mode, введите значение 0,1 или 2 (Вы ввели particle mode = %.0Lf)\n", (long double)particle_mode);

	}







	cout << endl;
	cout << "------------------------------" << endl;
	//Sleep(100); // пауза для того, чтобы успеть прочитать информацию
	cout << endl;





	// массив для функцию распределения(гистограммы) числа частиц, попавших в бины гистограммы
	// объявление двумерного динамического массива на N_histo*2 элементов:
	// массивколичества частиц попавших в каждый бин, всего бинов N_histo, второй столбец двумерного массива это координата левого конца бина
	long double **mass_histo_x = new long double*[N_histo]; // N_histo строк в массиве
	for (size_t count = 0; count < arrlen(mass_histo_x); count++)
		mass_histo_x[count] = new long double[2]; // и два столбца
												  //  где mass_histo  – массив указателей на выделенный участок памяти под массив вещественных чисел  типа long double

	long double h_x = 2.0*R / N_histo; // ширина бина

									   // заполнение массива
	for (size_t count_row = 0; count_row < arrlen(mass_histo_x); count_row++) {
		mass_histo_x[count_row][0] = 0; // превый столбец 0, в начале число частиц в каждом бине ноль
		mass_histo_x[count_row][1] = -1.0*R + 1.0*h_x*count_row; // второй столбец это координата левого конца бина

	}






	long double **mass_histo_x_P_z = new long double*[N_histo]; // N_histo строк в массиве
	for (size_t count = 0; count < arrlen(mass_histo_x_P_z); count++)
		mass_histo_x_P_z[count] = new long double[2]; // и два столбца
												  //  где mass_histo  – массив указателей на выделенный участок памяти под массив вещественных чисел  типа long double
   	
									   // заполнение массива
	for (size_t count_row = 0; count_row < arrlen(mass_histo_x_P_z); count_row++) {
		mass_histo_x_P_z[count_row][0] = 0; // превый столбец 0, в начале число частиц в каждом бине ноль
		mass_histo_x_P_z[count_row][1] = -1.0*R + 1.0*h_x*count_row; // второй столбец это координата левого конца бина

	}




	long double **mass_histo_x_P_zz = new long double*[N_histo]; // N_histo строк в массиве
	for (size_t count = 0; count < arrlen(mass_histo_x_P_zz); count++)
		mass_histo_x_P_zz[count] = new long double[2]; // и два столбца
												  //  где mass_histo  – массив указателей на выделенный участок памяти под массив вещественных чисел  типа long double

									   // заполнение массива
	for (size_t count_row = 0; count_row < arrlen(mass_histo_x_P_zz); count_row++) {
		mass_histo_x_P_zz[count_row][0] = 0; // превый столбец 0, в начале число частиц в каждом бине ноль
		mass_histo_x_P_zz[count_row][1] = -1.0*R + 1.0*h_x*count_row; // второй столбец это координата левого конца бина

	}











	long double **mass_histo_x_cyl1_in_source = new long double*[N_histo]; // N_histo строк в массиве
	for (size_t count = 0; count < arrlen(mass_histo_x_cyl1_in_source); count++)
		mass_histo_x_cyl1_in_source[count] = new long double[2]; // и два столбца
												  //  где mass_histo  – массив указателей на выделенный участок памяти под массив вещественных чисел  типа long double

//	long double h_x = 2.0*R / N_histo; // ширина бина

									   // заполнение массива
	for (size_t count_row = 0; count_row < arrlen(mass_histo_x_cyl1_in_source); count_row++) {
		mass_histo_x_cyl1_in_source[count_row][0] = 0; // превый столбец 0, в начале число частиц в каждом бине ноль
		mass_histo_x_cyl1_in_source[count_row][1] = -1.0*R + 1.0*h_x*count_row; // второй столбец это координата левого конца бина

	}










	long double **mass_histo_x_cyl1_in_source_positive = new long double*[N_histo]; // N_histo строк в массиве
	for (size_t count = 0; count < arrlen(mass_histo_x_cyl1_in_source_positive); count++)
		mass_histo_x_cyl1_in_source_positive[count] = new long double[2]; // и два столбца
																 //  где mass_histo  – массив указателей на выделенный участок памяти под массив вещественных чисел  типа long double

																 //	long double h_x = 2.0*R / N_histo; // ширина бина

																 // заполнение массива
	for (size_t count_row = 0; count_row < arrlen(mass_histo_x_cyl1_in_source_positive); count_row++) {
		mass_histo_x_cyl1_in_source_positive[count_row][0] = 0; // превый столбец 0, в начале число частиц в каждом бине ноль
		mass_histo_x_cyl1_in_source_positive[count_row][1] = -1.0*R + 1.0*h_x*count_row; // второй столбец это координата левого конца бина

	}








	long double **mass_histo_x_cyl1_in_source_zero = new long double*[N_histo]; // N_histo строк в массиве
	for (size_t count = 0; count < arrlen(mass_histo_x_cyl1_in_source_zero); count++)
		mass_histo_x_cyl1_in_source_zero[count] = new long double[2]; // и два столбца
																		  //  где mass_histo  – массив указателей на выделенный участок памяти под массив вещественных чисел  типа long double

																		  //	long double h_x = 2.0*R / N_histo; // ширина бина

																		  // заполнение массива
	for (size_t count_row = 0; count_row < arrlen(mass_histo_x_cyl1_in_source_zero); count_row++) {
		mass_histo_x_cyl1_in_source_zero[count_row][0] = 0; // превый столбец 0, в начале число частиц в каждом бине ноль
		mass_histo_x_cyl1_in_source_zero[count_row][1] = -1.0*R + 1.0*h_x*count_row; // второй столбец это координата левого конца бина

	}








	long double **mass_histo_x_cyl1_in_source_negative = new long double*[N_histo]; // N_histo строк в массиве
	for (size_t count = 0; count < arrlen(mass_histo_x_cyl1_in_source_negative); count++)
		mass_histo_x_cyl1_in_source_negative[count] = new long double[2]; // и два столбца
																	  //  где mass_histo  – массив указателей на выделенный участок памяти под массив вещественных чисел  типа long double

																	  //	long double h_x = 2.0*R / N_histo; // ширина бина

																	  // заполнение массива
	for (size_t count_row = 0; count_row < arrlen(mass_histo_x_cyl1_in_source_negative); count_row++) {
		mass_histo_x_cyl1_in_source_negative[count_row][0] = 0; // превый столбец 0, в начале число частиц в каждом бине ноль
		mass_histo_x_cyl1_in_source_negative[count_row][1] = -1.0*R + 1.0*h_x*count_row; // второй столбец это координата левого конца бина

	}











	long double **mass_histo_r = new long double*[(std::size_t)(N_histo / 2)]; // N_histo строк в массиве
	for (size_t count = 0; count < arrlen(mass_histo_r); count++) {
		mass_histo_r[count] = new long double[2]; // и два столбца
												  //  где mass_histo  – массив указателей на выделенный участок памяти под массив вещественных чисел  типа long double

	}
	long double h_r = 2.0*R / (N_histo); // ширина бина

										 // заполнение массива
	for (size_t count_row = 0; count_row < arrlen(mass_histo_r); count_row++) {
		mass_histo_r[count_row][0] = 0; // превый столбец 0, в начале число частиц в каждом бине ноль
		mass_histo_r[count_row][1] = h_r * count_row; // второй столбец это координата левого конца бина

	}








	long double **mass_histo_r_P_z = new long double*[(std::size_t)(N_histo / 2)]; // N_histo строк в массиве
	for (size_t count = 0; count < arrlen(mass_histo_r_P_z); count++) {
		mass_histo_r_P_z[count] = new long double[2]; // и два столбца
												  //  где mass_histo  – массив указателей на выделенный участок памяти под массив вещественных чисел  типа long double

	}
	
  										 // заполнение массива
	for (size_t count_row = 0; count_row < arrlen(mass_histo_r_P_z); count_row++) {
		mass_histo_r_P_z[count_row][0] = 0; // превый столбец 0, в начале число частиц в каждом бине ноль
		mass_histo_r_P_z[count_row][1] = h_r * count_row; // второй столбец это координата левого конца бина

	}








	long double **mass_histo_r_P_zz = new long double*[(std::size_t)(N_histo / 2)]; // N_histo строк в массиве
	for (size_t count = 0; count < arrlen(mass_histo_r_P_zz); count++) {
		mass_histo_r_P_zz[count] = new long double[2]; // и два столбца
												  //  где mass_histo  – массив указателей на выделенный участок памяти под массив вещественных чисел  типа long double

	}

	// заполнение массива
	for (size_t count_row = 0; count_row < arrlen(mass_histo_r_P_zz); count_row++) {
		mass_histo_r_P_zz[count_row][0] = 0; // превый столбец 0, в начале число частиц в каждом бине ноль
		mass_histo_r_P_zz[count_row][1] = h_r * count_row; // второй столбец это координата левого конца бина

	}










	long double **mass_histo_r_cyl1_in_source = new long double*[(std::size_t)(N_histo / 2)]; // N_histo строк в массиве
	for (size_t count = 0; count < arrlen(mass_histo_r_cyl1_in_source); count++) {
		mass_histo_r_cyl1_in_source[count] = new long double[2]; // и два столбца
												  //  где mass_histo  – массив указателей на выделенный участок памяти под массив вещественных чисел  типа long double

	}
	//	long double h_r = 2.0*R / (N_histo); // ширина бина

											 // заполнение массива
	for (size_t count_row = 0; count_row < arrlen(mass_histo_r_cyl1_in_source); count_row++) {
		mass_histo_r_cyl1_in_source[count_row][0] = 0; // превый столбец 0, в начале число частиц в каждом бине ноль
		mass_histo_r_cyl1_in_source[count_row][1] = h_r * count_row; // второй столбец это координата левого конца бина

	}







	long double **mass_histo_r_cyl1_in_source_positive = new long double*[(std::size_t)(N_histo / 2)]; // N_histo строк в массиве
	for (size_t count = 0; count < arrlen(mass_histo_r_cyl1_in_source_positive); count++) {
		mass_histo_r_cyl1_in_source_positive[count] = new long double[2]; // и два столбца
																 //  где mass_histo  – массив указателей на выделенный участок памяти под массив вещественных чисел  типа long double

	}
	//	long double h_r = 2.0*R / (N_histo); // ширина бина

	// заполнение массива
	for (size_t count_row = 0; count_row < arrlen(mass_histo_r_cyl1_in_source_positive); count_row++) {
		mass_histo_r_cyl1_in_source_positive[count_row][0] = 0; // превый столбец 0, в начале число частиц в каждом бине ноль
		mass_histo_r_cyl1_in_source_positive[count_row][1] = h_r * count_row; // второй столбец это координата левого конца бина

	}








	long double **mass_histo_r_cyl1_in_source_zero = new long double*[(std::size_t)(N_histo / 2)]; // N_histo строк в массиве
	for (size_t count = 0; count < arrlen(mass_histo_r_cyl1_in_source_zero); count++) {
		mass_histo_r_cyl1_in_source_zero[count] = new long double[2]; // и два столбца
																		  //  где mass_histo  – массив указателей на выделенный участок памяти под массив вещественных чисел  типа long double

	}
	//	long double h_r = 2.0*R / (N_histo); // ширина бина

	// заполнение массива
	for (size_t count_row = 0; count_row < arrlen(mass_histo_r_cyl1_in_source_zero); count_row++) {
		mass_histo_r_cyl1_in_source_zero[count_row][0] = 0; // превый столбец 0, в начале число частиц в каждом бине ноль
		mass_histo_r_cyl1_in_source_zero[count_row][1] = h_r * count_row; // второй столбец это координата левого конца бина

	}





	long double **mass_histo_r_cyl1_in_source_negative = new long double*[(std::size_t)(N_histo / 2)]; // N_histo строк в массиве
	for (size_t count = 0; count < arrlen(mass_histo_r_cyl1_in_source_negative); count++) {
		mass_histo_r_cyl1_in_source_negative[count] = new long double[2]; // и два столбца
																	  //  где mass_histo  – массив указателей на выделенный участок памяти под массив вещественных чисел  типа long double

	}
	//	long double h_r = 2.0*R / (N_histo); // ширина бина

	// заполнение массива
	for (size_t count_row = 0; count_row < arrlen(mass_histo_r_cyl1_in_source_negative); count_row++) {
		mass_histo_r_cyl1_in_source_negative[count_row][0] = 0; // превый столбец 0, в начале число частиц в каждом бине ноль
		mass_histo_r_cyl1_in_source_negative[count_row][1] = h_r * count_row; // второй столбец это координата левого конца бина

	}









	long double **mass_histo_x_positive = new long double*[N_histo]; // N_histo строк в массиве
	for (size_t count = 0; count < arrlen(mass_histo_x_positive); count++)
		mass_histo_x_positive[count] = new long double[2]; // и два столбца
												  //  где mass_histo  – массив указателей на выделенный участок памяти под массив вещественных чисел  типа long double

										   // заполнение массива
	for (size_t count_row = 0; count_row < arrlen(mass_histo_x_positive); count_row++) {
		mass_histo_x_positive[count_row][0] = 0; // превый столбец 0, в начале число частиц в каждом бине ноль
		mass_histo_x_positive[count_row][1] = -1.0*R + 1.0*h_x*count_row; // второй столбец это координата левого конца бина

	}


	long double **mass_histo_r_positive = new long double*[(std::size_t)(N_histo / 2)]; // N_histo строк в массиве
	for (size_t count = 0; count < arrlen(mass_histo_r_positive); count++) {
		mass_histo_r_positive[count] = new long double[2]; // и два столбца
												  //  где mass_histo  – массив указателей на выделенный участок памяти под массив вещественных чисел  типа long double

	}
	// заполнение массива
	for (size_t count_row = 0; count_row < arrlen(mass_histo_r_positive); count_row++) {
		mass_histo_r_positive[count_row][0] = 0; // превый столбец 0, в начале число частиц в каждом бине ноль
		mass_histo_r_positive[count_row][1] = h_r * count_row; // второй столбец это координата левого конца бина

	}



	long double **mass_histo_x_zero = new long double*[N_histo]; // N_histo строк в массиве
	for (size_t count = 0; count < arrlen(mass_histo_x_zero); count++)
		mass_histo_x_zero[count] = new long double[2]; // и два столбца
														   //  где mass_histo  – массив указателей на выделенный участок памяти под массив вещественных чисел  типа long double

														   // заполнение массива
	for (size_t count_row = 0; count_row < arrlen(mass_histo_x_zero); count_row++) {
		mass_histo_x_zero[count_row][0] = 0; // превый столбец 0, в начале число частиц в каждом бине ноль
		mass_histo_x_zero[count_row][1] = -1.0*R + 1.0*h_x*count_row; // второй столбец это координата левого конца бина

	}


	long double **mass_histo_r_zero = new long double*[(std::size_t)(N_histo / 2)]; // N_histo строк в массиве
	for (size_t count = 0; count < arrlen(mass_histo_r_zero); count++) {
		mass_histo_r_zero[count] = new long double[2]; // и два столбца
														   //  где mass_histo  – массив указателей на выделенный участок памяти под массив вещественных чисел  типа long double

	}
	// заполнение массива
	for (size_t count_row = 0; count_row < arrlen(mass_histo_r_zero); count_row++) {
		mass_histo_r_zero[count_row][0] = 0; // превый столбец 0, в начале число частиц в каждом бине ноль
		mass_histo_r_zero[count_row][1] = h_r * count_row; // второй столбец это координата левого конца бина

	}



	long double **mass_histo_x_negative = new long double*[N_histo]; // N_histo строк в массиве
	for (size_t count = 0; count < arrlen(mass_histo_x_negative); count++)
		mass_histo_x_negative[count] = new long double[2]; // и два столбца
													   //  где mass_histo  – массив указателей на выделенный участок памяти под массив вещественных чисел  типа long double

													   // заполнение массива
	for (size_t count_row = 0; count_row < arrlen(mass_histo_x_negative); count_row++) {
		mass_histo_x_negative[count_row][0] = 0; // превый столбец 0, в начале число частиц в каждом бине ноль
		mass_histo_x_negative[count_row][1] = -1.0*R + 1.0*h_x*count_row; // второй столбец это координата левого конца бина

	}


	long double **mass_histo_r_negative = new long double*[(std::size_t)(N_histo / 2)]; // N_histo строк в массиве
	for (size_t count = 0; count < arrlen(mass_histo_r_negative); count++) {
		mass_histo_r_negative[count] = new long double[2]; // и два столбца
													   //  где mass_histo  – массив указателей на выделенный участок памяти под массив вещественных чисел  типа long double

	}
	// заполнение массива
	for (size_t count_row = 0; count_row < arrlen(mass_histo_r_negative); count_row++) {
		mass_histo_r_negative[count_row][0] = 0; // превый столбец 0, в начале число частиц в каждом бине ноль
		mass_histo_r_negative[count_row][1] = h_r * count_row; // второй столбец это координата левого конца бина

	}


















	long double **mass_histo_V_0 = new long double*[N_histo_V_0]; // N_histo_V_0 строк в массиве
	for (size_t count = 0; count < arrlen(mass_histo_V_0); count++) {
		mass_histo_V_0[count] = new long double[3]; // и три столбца
													//  где mass_histo  – массив указателей на выделенный участок памяти под массив вещественных чисел  типа long double

	}



	long double **mass_histo_time = new long double*[N_histo_time]; // N_histo_V_0 строк в массиве
	for (size_t count = 0; count < arrlen(mass_histo_time); count++) {
		mass_histo_time[count] = new long double[3]; // и три столбца
													 //  где mass_histo  – массив указателей на выделенный участок памяти под массив вещественных чисел  типа long double

	}



	long double **mass_histo_V_0_out = new long double*[N_histo_V_0_out]; // N_histo_V_0 строк в массиве
	for (size_t count = 0; count < arrlen(mass_histo_V_0_out); count++) {
		mass_histo_V_0_out[count] = new long double[3]; // и три столбца
														//  где mass_histo  – массив указателей на выделенный участок памяти под массив вещественных чисел  типа long double

	}





	long double **mass_histo_V_0_tube_out = new long double*[N_histo_V_0_tube_out]; // N_histo_V_0 строк в массиве
	for (size_t count = 0; count < arrlen(mass_histo_V_0_tube_out); count++) {
		mass_histo_V_0_tube_out[count] = new long double[3]; // и три столбца
															 //  где mass_histo  – массив указателей на выделенный участок памяти под массив вещественных чисел  типа long double

	}


	long double h_V_0 = (b_V_0 - a_V_0) / N_histo_V_0; // ширина бина

	long double h_time = (b_time - a_time) / N_histo_time; // ширина бина

	long double h_V_0_out = (b_V_0 - a_V_0) / N_histo_V_0_out; // ширина бина

	long double h_V_0_tube_out = (b_V_0 - a_V_0) / N_histo_V_0_out; // ширина бина

																	// заполнение массива
	for (size_t count_row = 0; count_row < arrlen(mass_histo_V_0); count_row++) {
		mass_histo_V_0[count_row][0] = 0; // превый столбец 0, в начале число частиц в каждом бине ноль
		mass_histo_V_0[count_row][1] = 0; // второй столбец 0, в начале число частиц в каждом бине ноль, теоретическое распределение Максвелла
		mass_histo_V_0[count_row][2] = h_V_0 * count_row; // третий столбец это координата левого конца бина

	}


	for (size_t count_row = 0; count_row < arrlen(mass_histo_time); count_row++) {
		mass_histo_time[count_row][0] = 0; // превый столбец 0, в начале число частиц в каждом бине ноль
		mass_histo_time[count_row][1] = 0; // второй столбец 0, в начале число частиц в каждом бине ноль, теоретическое распределение Максвелла
		mass_histo_time[count_row][2] = h_time * count_row; // третий столбец это координата левого конца бина

	}


	for (size_t count_row = 0; count_row < arrlen(mass_histo_V_0_out); count_row++) {
		mass_histo_V_0_out[count_row][0] = 0; // превый столбец 0, в начале число частиц в каждом бине ноль
		mass_histo_V_0_out[count_row][1] = 0; // второй столбец 0, в начале число частиц в каждом бине ноль, теоретическое распределение Максвелла
		mass_histo_V_0_out[count_row][2] = h_V_0_out * count_row; // третий столбец это координата левого конца бина


	}


	for (size_t count_row = 0; count_row < arrlen(mass_histo_V_0_tube_out); count_row++) {
		mass_histo_V_0_tube_out[count_row][0] = 0; // превый столбец 0, в начале число частиц в каждом бине ноль
		mass_histo_V_0_tube_out[count_row][1] = 0; // второй столбец 0, в начале число частиц в каждом бине ноль, теоретическое распределение Максвелла
		mass_histo_V_0_tube_out[count_row][2] = h_V_0_tube_out * count_row; // третий столбец это координата левого конца бина

	}



	long double **mass_histo_theta_in = new long double*[N_histo_theta_in]; // N_histo_V_0 строк в массиве
	for (size_t count = 0; count < arrlen(mass_histo_theta_in); count++) {
		mass_histo_theta_in[count] = new long double[4]; // и четыре столбца
														 //  где mass_histo  – массив указателей на выделенный участок памяти под массив вещественных чисел  типа long double

	}





	long double **mass_histo_theta_out = new long double*[N_histo_theta_in]; // N_histo_V_0 строк в массиве
	for (size_t count = 0; count < arrlen(mass_histo_theta_out); count++) {
		mass_histo_theta_out[count] = new long double[4]; // и четыре столбца
														  //  где mass_histo  – массив указателей на выделенный участок памяти под массив вещественных чисел  типа long double

	}


	long double **mass_histo_theta_out_ = new long double*[N_histo_theta_in]; // N_histo_V_0 строк в массиве
	for (size_t count = 0; count < arrlen(mass_histo_theta_out_); count++) {
		mass_histo_theta_out_[count] = new long double[4]; // и четыре столбца
														   //  где mass_histo  – массив указателей на выделенный участок памяти под массив вещественных чисел  типа long double

	}



	long double **mass_histo_theta_in_ = new long double*[N_histo_theta_in]; // N_histo_V_0 строк в массиве
	for (size_t count = 0; count < arrlen(mass_histo_theta_in_); count++) {
		mass_histo_theta_in_[count] = new long double[4]; // и четыре столбца
														  //  где mass_histo  – массив указателей на выделенный участок памяти под массив вещественных чисел  типа long double

	}

	for (size_t i = 0; i < arrlen(mass_histo_theta_in); i = i + 1) {

		for (int j = 0; j < 3; j = j + 1) {

			mass_histo_theta_in[i][j] = 0.0;

		}
	}



	long double **mass_histo_theta_in_out = new long double*[N_histo_theta_in]; // N_histo_V_0 строк в массиве
	for (size_t count = 0; count < arrlen(mass_histo_theta_in_out); count++) {
		mass_histo_theta_in_out[count] = new long double[4]; // и четыре столбца
															 //  где mass_histo  – массив указателей на выделенный участок памяти под массив вещественных чисел  типа long double

	}

	for (size_t i = 0; i < arrlen(mass_histo_theta_in_out); i = i + 1) {

		for (int j = 0; j < 3; j = j + 1) {

			mass_histo_theta_in_out[i][j] = 0.0;

		}
	}



	long double **mass_histo_theta_in_out_ = new long double*[N_histo_theta_in]; // N_histo_V_0 строк в массиве
	for (size_t count = 0; count < arrlen(mass_histo_theta_in_out_); count++) {
		mass_histo_theta_in_out_[count] = new long double[4]; // и четыре столбца
															  //  где mass_histo  – массив указателей на выделенный участок памяти под массив вещественных чисел  типа long double

	}

	for (size_t i = 0; i < arrlen(mass_histo_theta_in_out_); i = i + 1) {

		for (int j = 0; j < 3; j = j + 1) {

			mass_histo_theta_in_out_[i][j] = 0.0;

		}
	}





	for (size_t i = 0; i < arrlen(mass_histo_theta_out); i = i + 1) {

		for (int j = 0; j < 3; j = j + 1) {

			mass_histo_theta_out[i][j] = 0.0;

		}
	}




	for (size_t i = 0; i < arrlen(mass_histo_theta_out_); i = i + 1) {

		for (int j = 0; j < 3; j = j + 1) {

			mass_histo_theta_out_[i][j] = 0.0;

		}
	}



	for (size_t i = 0; i < arrlen(mass_histo_theta_in_); i = i + 1) {

		for (int j = 0; j < 3; j = j + 1) {

			mass_histo_theta_in_[i][j] = 0.0;

		}
	}


	long double h_theta_in = M_PI / N_histo_theta_in; // ширина бина
	long double x_theta_in = -M_PI_2;
	long double x_theta_in_ = -M_PI_2;

	long double A_theta_intensity = 2.0*gamma(n_cos_intensity / 2.0 + 1.0) / (pow(M_PI, 1.0 / 2.0)*gamma((n_cos_intensity + 1.0) / 2.0));

	//	cout << A_theta_intensity << endl;

		// заполнение массива
	for (size_t count_row = 0; count_row < arrlen(mass_histo_theta_in); count_row++) {
		mass_histo_theta_in[count_row][0] = 0; // превый столбец 0, в начале число частиц в каждом бине ноль
		mass_histo_theta_in[count_row][1] = h_theta_in * A_theta_intensity*pow(cos(x_theta_in), n_cos_intensity); // второй столбец 0, в начале число частиц в каждом бине ноль, теоретическое распределение 
		mass_histo_theta_in[count_row][2] = x_theta_in; // третий столбец это координата левого конца бина
		mass_histo_theta_in[count_row][3] = x_theta_in + M_PI_2; // третий столбец это координата левого конца бина, повернутый на 90 градусов

		x_theta_in = x_theta_in + h_theta_in;
	}


	long double h_theta_in_out = M_PI / N_histo_theta_in; // ширина бина
	long double x_theta_in_out = -M_PI_2;
	long double x_theta_in_out_ = -M_PI_2;


	// заполнение массива
	for (size_t count_row = 0; count_row < arrlen(mass_histo_theta_in_out); count_row++) {
		mass_histo_theta_in_out[count_row][0] = 0; // превый столбец 0, в начале число частиц в каждом бине ноль
		mass_histo_theta_in_out[count_row][1] = fabs((n_cos_intensity + 1)*h_theta_in_out*pow(cos(x_theta_in_out), n_cos_intensity)*sin(x_theta_in_out)); // второй столбец 0, в начале число частиц в каждом бине ноль, теоретическое распределение 
		mass_histo_theta_in_out[count_row][2] = x_theta_in_out; // третий столбец это координата левого конца бина
		mass_histo_theta_in_out[count_row][3] = x_theta_in_out + M_PI_2; // третий столбец это координата левого конца бина, повернутый на 90 градусов

		x_theta_in_out = x_theta_in_out + h_theta_in_out;
	}

	long double h_theta_in_out_ = M_PI / N_histo_theta_in; // ширина бина
														   //	long double x_theta_in_out_ = -M_PI_2;
	long double x_theta_in_out__ = -M_PI_2;

	// заполнение массива
	for (size_t count_row = 0; count_row < arrlen(mass_histo_theta_in_out_); count_row++) {
		mass_histo_theta_in_out_[count_row][0] = 0; // превый столбец 0, в начале число частиц в каждом бине ноль
		mass_histo_theta_in_out_[count_row][1] = h_theta_in_out_ * A_theta_intensity*pow(cos(x_theta_in_out__), n_cos_intensity); // второй столбец 0, в начале число частиц в каждом бине ноль, теоретическое распределение 
		mass_histo_theta_in_out_[count_row][2] = x_theta_in_out__; // третий столбец это координата левого конца бина
		mass_histo_theta_in_out_[count_row][3] = x_theta_in_out__ + M_PI_2; // третий столбец это координата левого конца бина, повернутый на 90 градусов

		x_theta_in_out__ = x_theta_in_out__ + h_theta_in_out_;
	}



	long double h_theta_out = M_PI / N_histo_theta_in; // ширина бина
	long double x_theta_out = -M_PI_2;
	long double x_theta_out_ = -M_PI_2;

	// заполнение массива
	for (size_t count_row = 0; count_row < arrlen(mass_histo_theta_out); count_row++) {
		mass_histo_theta_out[count_row][0] = 0; // превый столбец 0, в начале число частиц в каждом бине ноль
		mass_histo_theta_out[count_row][1] = fabs((n_cos_intensity + 1)*h_theta_in*pow(cos(x_theta_out), n_cos_intensity)*sin(x_theta_out)); // второй столбец 0, в начале число частиц в каждом бине ноль, теоретическое распределение 
		mass_histo_theta_out[count_row][2] = x_theta_out; // третий столбец это координата левого конца бина
		mass_histo_theta_out[count_row][3] = x_theta_out + M_PI_2; // третий столбец это координата левого конца бина, повернутый на 90 градусов

		x_theta_out = x_theta_out + h_theta_out;
	}

	long double h_theta_out_ = M_PI / N_histo_theta_in; // ширина бина
	x_theta_out_ = -M_PI_2;
	long double x_theta_out__ = -M_PI_2;

	// заполнение массива
	for (size_t count_row = 0; count_row < arrlen(mass_histo_theta_out_); count_row++) {
		mass_histo_theta_out_[count_row][0] = 0; // превый столбец 0, в начале число частиц в каждом бине ноль
		mass_histo_theta_out_[count_row][1] = A_theta_intensity * pow(cos(x_theta_out_), n_cos_intensity); // второй столбец 0, в начале число частиц в каждом бине ноль, теоретическое распределение 
		mass_histo_theta_out_[count_row][2] = x_theta_out_; // третий столбец это координата левого конца бина
		mass_histo_theta_out_[count_row][3] = x_theta_out_ + M_PI_2; // третий столбец это координата левого конца бина, повернутый на 90 градусов

		x_theta_out_ = x_theta_out_ + h_theta_out_;
	}

	// заполнение массива
	for (size_t count_row = 0; count_row < arrlen(mass_histo_theta_in_); count_row++) {
		mass_histo_theta_in_[count_row][0] = 0; // превый столбец 0, в начале число частиц в каждом бине ноль
		mass_histo_theta_in_[count_row][1] = fabs((n_cos_intensity + 1)*h_theta_in*pow(cos(x_theta_in_), n_cos_intensity)*sin(x_theta_in_)); // второй столбец 0, в начале число частиц в каждом бине ноль, теоретическое распределение 
		mass_histo_theta_in_[count_row][2] = x_theta_in_; // третий столбец это координата левого конца бина
		mass_histo_theta_in_[count_row][3] = x_theta_in_ + M_PI_2; // третий столбец это координата левого конца бина, повернутый на 90 градусов

		x_theta_in_ = x_theta_in_ + h_theta_in;
	}







	// массив для функцию распределения(гистограммы) числа частиц, попавших в бины гистограммы
	// объявление двумерного динамического массива на N_histo*2 элементов:
	// массивколичества частиц попавших в каждый бин, всего бинов N_histo, второй столбец двумерного массива это координата левого конца бина
	long double **mass_histo_x_source = new long double*[N_histo_source]; // N_histo строк в массиве
	for (size_t count = 0; count < arrlen(mass_histo_x_source); count++)
		mass_histo_x_source[count] = new long double[2]; // и два столбца
														 //  где mass_histo  – массив указателей на выделенный участок памяти под массив вещественных чисел  типа long double

	long double h_x_source = 2.0*R / N_histo_source; // ширина бина

													 // заполнение массива
	for (size_t count_row = 0; count_row < arrlen(mass_histo_x_source); count_row++) {
		mass_histo_x_source[count_row][0] = 0; // превый столбец 0, в начале число частиц в каждом бине ноль
		mass_histo_x_source[count_row][1] = -1.0*R + 1.0*h_x_source*count_row; // второй столбец это координата левого конца бина

	}



	long double **mass_histo_r_source = new long double*[(std::size_t)(N_histo_source / 2)]; // N_histo строк в массиве
	for (size_t count = 0; count < arrlen(mass_histo_r_source); count++) {
		mass_histo_r_source[count] = new long double[2]; // и два столбца
														 //  где mass_histo  – массив указателей на выделенный участок памяти под массив вещественных чисел  типа long double

	}
	long double h_r_source = 2.0*R / (N_histo_source); // ширина бина

													   // заполнение массива
	for (size_t count_row = 0; count_row < arrlen(mass_histo_r_source); count_row++) {
		mass_histo_r_source[count_row][0] = 0; // превый столбец 0, в начале число частиц в каждом бине ноль
		mass_histo_r_source[count_row][1] = h_r_source * count_row; // второй столбец это координата левого конца бина

	}












   
   
  



	long double **mass_histo_x_source_P_z = new long double*[N_histo_source]; // N_histo строк в массиве
	for (size_t count = 0; count < arrlen(mass_histo_x_source_P_z); count++) {
	
		mass_histo_x_source_P_z[count] = new long double[2]; // и два столбца
															 //  где mass_histo  – массив указателей на выделенный участок памяти под массив вещественных чисел  типа long double

	 }

													 // заполнение массива
	for (size_t count_row = 0; count_row < arrlen(mass_histo_x_source_P_z); count_row++) {
		mass_histo_x_source_P_z[count_row][0] = 0; // превый столбец 0, в начале число частиц в каждом бине ноль
		mass_histo_x_source_P_z[count_row][1] = -1.0*R + 1.0*h_x_source*count_row; // второй столбец это координата левого конца бина

	}









	long double **mass_histo_x_source_P_zz = new long double*[N_histo_source]; // N_histo строк в массиве
	for (size_t count = 0; count < arrlen(mass_histo_x_source_P_zz); count++) {
		
		mass_histo_x_source_P_zz[count] = new long double[2]; // и два столбца
		//  где mass_histo  – массив указателей на выделенный участок памяти под массив вещественных чисел  типа long double


	}
													 // заполнение массива
	for (size_t count_row = 0; count_row < arrlen(mass_histo_x_source_P_zz); count_row++) {
				
		mass_histo_x_source_P_zz[count_row][0] = 0; // превый столбец 0, в начале число частиц в каждом бине ноль
		mass_histo_x_source_P_zz[count_row][1] = -1.0*R + 1.0*h_x_source*count_row; // второй столбец это координата левого конца бина

	}




	  

	long double **mass_histo_r_source_P_z = new long double*[(std::size_t)(N_histo_source / 2)]; // N_histo строк в массиве
	for (size_t count = 0; count < arrlen(mass_histo_r_source_P_z); count++) {
		mass_histo_r_source_P_z[count] = new long double[2]; // и два столбца
																  //  где mass_histo  – массив указателей на выделенный участок памяти под массив вещественных чисел  типа long double

	}


	// заполнение массива
	for (size_t count_row = 0; count_row < arrlen(mass_histo_r_source_P_z); count_row++) {
		mass_histo_r_source_P_z[count_row][0] = 0; // превый столбец 0, в начале число частиц в каждом бине ноль
		mass_histo_r_source_P_z[count_row][1] = h_r_source * count_row; // второй столбец это координата левого конца бина

	}






	long double **mass_histo_r_source_P_zz = new long double*[(std::size_t)(N_histo_source / 2)]; // N_histo строк в массиве
	for (size_t count = 0; count < arrlen(mass_histo_r_source_P_zz); count++) {
		mass_histo_r_source_P_zz[count] = new long double[2]; // и два столбца
																  //  где mass_histo  – массив указателей на выделенный участок памяти под массив вещественных чисел  типа long double

	}


	// заполнение массива
	for (size_t count_row = 0; count_row < arrlen(mass_histo_r_source_P_zz); count_row++) {
		mass_histo_r_source_P_zz[count_row][0] = 0; // превый столбец 0, в начале число частиц в каждом бине ноль
		mass_histo_r_source_P_zz[count_row][1] = h_r_source * count_row; // второй столбец это координата левого конца бина

	}
















	long double **mass_histo_x_source_positive = new long double*[N_histo_source]; // N_histo строк в массиве
	for (size_t count = 0; count < arrlen(mass_histo_x_source_positive); count++) {
		mass_histo_x_source_positive[count] = new long double[2]; // и два столбца
														 //  где mass_histo  – массив указателей на выделенный участок памяти под массив вещественных чисел  типа long double

	}

													 // заполнение массива
	for (size_t count_row = 0; count_row < arrlen(mass_histo_x_source_positive); count_row++) {
		mass_histo_x_source_positive[count_row][0] = 0; // превый столбец 0, в начале число частиц в каждом бине ноль
		mass_histo_x_source_positive[count_row][1] = -1.0*R + 1.0*h_x_source*count_row; // второй столбец это координата левого конца бина

	}



	long double **mass_histo_r_source_positive = new long double*[(std::size_t)(N_histo_source / 2)]; // N_histo строк в массиве
	for (size_t count = 0; count < arrlen(mass_histo_r_source_positive); count++) {
		mass_histo_r_source_positive[count] = new long double[2]; // и два столбца
														 //  где mass_histo  – массив указателей на выделенный участок памяти под массив вещественных чисел  типа long double

	}


	// заполнение массива
	for (size_t count_row = 0; count_row < arrlen(mass_histo_r_source_positive); count_row++) {
		mass_histo_r_source_positive[count_row][0] = 0; // превый столбец 0, в начале число частиц в каждом бине ноль
		mass_histo_r_source_positive[count_row][1] = h_r_source * count_row; // второй столбец это координата левого конца бина

	}



	long double **mass_histo_x_source_zero = new long double*[N_histo_source]; // N_histo строк в массиве
	for (size_t count = 0; count < arrlen(mass_histo_x_source_zero); count++)
		mass_histo_x_source_zero[count] = new long double[2]; // и два столбца
																  //  где mass_histo  – массив указателей на выделенный участок памяти под массив вещественных чисел  типа long double



																  // заполнение массива
	for (size_t count_row = 0; count_row < arrlen(mass_histo_x_source_zero); count_row++) {
		mass_histo_x_source_zero[count_row][0] = 0; // превый столбец 0, в начале число частиц в каждом бине ноль
		mass_histo_x_source_zero[count_row][1] = -1.0*R + 1.0*h_x_source*count_row; // второй столбец это координата левого конца бина

	}



	long double **mass_histo_r_source_zero = new long double*[(std::size_t)(N_histo_source / 2)]; // N_histo строк в массиве
	for (size_t count = 0; count < arrlen(mass_histo_r_source_zero); count++) {
		mass_histo_r_source_zero[count] = new long double[2]; // и два столбца
																  //  где mass_histo  – массив указателей на выделенный участок памяти под массив вещественных чисел  типа long double

	}


	// заполнение массива
	for (size_t count_row = 0; count_row < arrlen(mass_histo_r_source_zero); count_row++) {
		mass_histo_r_source_zero[count_row][0] = 0; // превый столбец 0, в начале число частиц в каждом бине ноль
		mass_histo_r_source_zero[count_row][1] = h_r_source * count_row; // второй столбец это координата левого конца бина

	}




	long double **mass_histo_x_source_negative = new long double*[N_histo_source]; // N_histo строк в массиве
	for (size_t count = 0; count < arrlen(mass_histo_x_source_negative); count++)
		mass_histo_x_source_negative[count] = new long double[2]; // и два столбца
															  //  где mass_histo  – массив указателей на выделенный участок памяти под массив вещественных чисел  типа long double



															  // заполнение массива
	for (size_t count_row = 0; count_row < arrlen(mass_histo_x_source_negative); count_row++) {
		mass_histo_x_source_negative[count_row][0] = 0; // превый столбец 0, в начале число частиц в каждом бине ноль
		mass_histo_x_source_negative[count_row][1] = -1.0*R + 1.0*h_x_source*count_row; // второй столбец это координата левого конца бина

	}



	long double **mass_histo_r_source_negative = new long double*[(std::size_t)(N_histo_source / 2)]; // N_histo строк в массиве
	for (size_t count = 0; count < arrlen(mass_histo_r_source_negative); count++) {
		mass_histo_r_source_negative[count] = new long double[2]; // и два столбца
															  //  где mass_histo  – массив указателей на выделенный участок памяти под массив вещественных чисел  типа long double

	}


	// заполнение массива
	for (size_t count_row = 0; count_row < arrlen(mass_histo_r_source_negative); count_row++) {
		mass_histo_r_source_negative[count_row][0] = 0; // превый столбец 0, в начале число частиц в каждом бине ноль
		mass_histo_r_source_negative[count_row][1] = h_r_source * count_row; // второй столбец это координата левого конца бина

	}



















	//	Sleep(100); // пауза для того, чтобы успеть прочитать информацию
	//	cout << endl;
	//cout << "Условные обозначения:" << endl;
	//cout << endl;
	//cout << "......\t " << "Частицы, которые сразу вышли из усточника и не коснулись стенок," << endl;
	//cout << "++++++\t " << "Частицы, которые хотя бы раз коснулись стенок и вышли из источника." << endl;
	//cout << endl;
	//Sleep(100); // пауза для того, чтобы успеть прочитать информацию


	SleepEx(40, true); // пауза для того, чтобы успеть прочитать информацию
	cout << "Нажми на клавишу Yes для отображения данных во время расчета" << endl;
	cout << "ИЛИ" << endl;
	cout << "Нажми на клавишу No для неотображения данных во время расчета" << endl;


	bool console_out = true;

	while (true) {

		//cout << " .";
		//Sleep(100); // пауза для того, чтобы успеть прочитать информацию

		SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
		SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода

		if ((_getch() == 0x59) || (_getch() == 0x79) || (_getch() == 0x8D) || (_getch() == 0xAD)) //YES
		{

			cout << endl;
			cout << "Вы нажали Yes." << endl;
			cout << endl;
			cout << "Далее будут выводится столбцы с информацие о частицах на вылете из цилиндра...." << endl;
			cout << endl;
			cout << "X ||" << " Y ||" << " Z ||" << " R ||" << " № частицы выпущенной из источника ||" << " % выполнения программы ||" << " время с начала счета, сек" << " № частицы по порядку" << endl;
			cout << endl;
			console_out = true;

			break;
		}

		if ((_getch() == 0x4E) || (_getch() == 0x6E) || (_getch() == 0x92) || (_getch() == 0xB2))  // NO
		{

			cout << endl;
			cout << "Вы нажали No." << endl;
			cout << endl;
			cout << "Промежуточные данные не будут выводится на экран" << endl;
			cout << endl;
			console_out = false;

			break;
		}

		else {
			cout << endl;
			cout << "Вы нажали какую то клавишу другую клавишу, повторите попытку снова..." << endl;
			//	cout << endl;

		}

		cout << endl;
		continue;
	}

	cout << endl;
	SleepEx(40, true); // пауза для того, чтобы успеть прочитать информацию
	cout << "Нажми на клавишу ENTER для продолжения расчетов." << endl;

	while (true) {

		//cout << " .";
		//Sleep(100); // пауза для того, чтобы успеть прочитать информацию


		if (_getch() == VK_RETURN)
		{

			cout << endl;
			cout << "Вы нажали ENTER." << endl;

			break;
		}
		else {
			cout << endl;
			cout << "Вы нажали какую то клавишу, но точно не ENTER, повторите попытку снова..." << endl;
			//	cout << endl;

		}





		cout << endl;
		continue;

	}













	SleepEx(40, true); // пауза для того, чтобы успеть прочитать информацию

	cout << endl;
	printf("Идет расчет... Пожалуйста,Ждите... Примерное время счета равно=%.3Lf мин.\n", (long double)(N * 20.0) / (pow(10.0, 6.0) * 60));
	//cout << "Идет расчет... Ждите...Примерное время счета равно=" << N*20/(pow(10.0,5.0)*60)<< "мин."<< endl;
	cout << endl;
	SleepEx(40, true); // пауза для того, чтобы успеть прочитать информацию

	const long double k = 1.3806485279; // постоянная Больцмана/10^-23 , Дж/К
	const long double N_A = 6.02214085774; // постоянная Авогадро/10^23 , 1/моль
	const long double R_gas_constant = 8.314459845; // // Универсальная газовая постоянная , Дж/(моль*K)

													//long double m_particle_temp = 0.0;

	long double V_0_initial = 0.0;

	long double v1 = 0.0; // наиболее вероятная скорость
	long double v2 = 0.0; // средняя скорость
	long double v3 = 0.0; // средняя квадратичная скорость
	long double v4 = 0.0; // медианная скорость

	long double Max_Maxwell = 0.0; // максимум функции распределения по скоростям

								   // ручной режим
	if (particle_mode == 0) {

		if (flaq_Maxwell == false) {

			V_0 = mass[24];

			size_t	i = (size_t)(V_0 / h_V_0);

			mass_histo_V_0[i][1] = 1.0;

			mass_histo_time[i][1] = (L_1 + L_2 + L_3 + L_4 + L_5 + L_6 + L_7) / V_0;

			mass_histo_V_0_out[i][1] = 1.0;

			//	m_particle_temp= m_particle*0.0010735441498156322;
		}

		else {

			// перевод МэВ в а.е.м

			long double m = m_particle * 0.0010735441498156322;

			//	m_particle_temp = m;

			//		V_0 = random_Neumann_Maxwell_abs_speed(a_V_0, b_V_0, m, temp_beam);

			for (size_t i = 0; i < arrlen(mass_histo_V_0); i = i + 1) {

				mass_histo_V_0[i][1] = h_V_0 * Maxwell_abs_speed(a_V_0 + h_V_0 * i, m, temp_beam, flaq_Maxwell_mode, drift_velocity);
				mass_histo_V_0_out[i][1] = h_V_0_out * Maxwell_abs_speed(a_V_0 + h_V_0_out * i, m, temp_beam, flaq_Maxwell_mode, drift_velocity);
				mass_histo_V_0_tube_out[i][1] = h_V_0_tube_out * Maxwell_abs_speed(a_V_0 + h_V_0_tube_out * i, m, temp_beam, flaq_Maxwell_mode, drift_velocity);
			}

			for (size_t i = 0; i < arrlen(mass_histo_time); i = i + 1) {

				mass_histo_time[i][1] = 0.0;

			}


		}


		mu_temp = mu_temp_manual * mu_bor_temp;
		mu_force_temp = mu_temp_manual * mu_bor_force_temp;
	}


	// водород
	if (particle_mode == 1) {
		B_critical = B_critical_hydrogen;
		m_particle = m_particle_hydrogen;
		mu_core_particle = mu_core_particle_hydrogen;
		const long double m_particle_hydrogen_u = (1.00727646687991 + 5.4857990907016 / 10000.0)*pow(10.0, -3.0); //масса в кг/моль, а.е.м.
		if (flaq_Maxwell == false) {
			V_0 = pow(3.0*R_gas_constant*temp_beam / m_particle_hydrogen_u, 1.0 / 2.0)*1000.0;

			size_t	i = (size_t)(V_0 / h_V_0);

			mass_histo_V_0[i][1] = 1.0;

			mass_histo_time[i][1] = (L_1 + L_2 + L_3 + L_4 + L_5 + L_6 + L_7) / V_0;

			mass_histo_V_0_out[i][1] = 1.0;


			//	m_particle_temp = 2.0*1.00727646667991;
		}
		else {
			const long double m = 1.00727646687991 + 5.4857990907016 / 10000.0; // в а.е.м.
														//	m_particle_temp = m;
														//V_0 = random_Neumann_Maxwell_abs_speed(a_V_0, b_V_0, m, temp_beam);





			for (size_t i = 0; i < arrlen(mass_histo_V_0); i = i + 1) {

				mass_histo_V_0[i][1] = h_V_0 * Maxwell_abs_speed(a_V_0 + h_V_0 * i, m, temp_beam, flaq_Maxwell_mode, drift_velocity);
				mass_histo_V_0_out[i][1] = h_V_0_out * Maxwell_abs_speed(a_V_0 + h_V_0_out * i, m, temp_beam, flaq_Maxwell_mode, drift_velocity);
				mass_histo_V_0_tube_out[i][1] = h_V_0_tube_out * Maxwell_abs_speed(a_V_0 + h_V_0_tube_out * i, m, temp_beam, flaq_Maxwell_mode, drift_velocity);

			}

			for (size_t i = 0; i < arrlen(mass_histo_time); i = i + 1) {

				mass_histo_time[i][1] = 0.0;

			}

		}


	}

	// дейтерий
	if (particle_mode == 2) {
		B_critical = B_critical_deuterium;
		m_particle = m_particle_deuterium;
		mu_core_particle = mu_core_particle_deuterium;
		const long double m_particle_deuterium_u = (1.00727646687991 + 1.0086649158849 + 5.4857990907016 / 10000.0)*pow(10.0, -3.0); //масса в кг/моль,а.е.м., приведенная масса протона и нейтрона


		if (flaq_Maxwell == false) {
			V_0 = pow(3.0*R_gas_constant*temp_beam / m_particle_deuterium_u, 1.0 / 2.0)*1000.0;

			size_t	i = (size_t)(V_0 / h_V_0);

			mass_histo_V_0[i][1] = 1.0;

			mass_histo_time[i][1] = (L_1 + L_2 + L_3 + L_4 + L_5 + L_6 + L_7) / V_0;

			mass_histo_V_0_out[i][1] = 1.0;


			//	m_particle_temp = (1.00727646667991 + 1.0086649158849);
		}
		else {

			const long double m = (1.00727646687991 + 1.0086649158849 + 5.4857990907016 / 10000.0);
			//	m_particle_temp = m;
			//	V_0 = random_Neumann_Maxwell_abs_speed(a_V_0, b_V_0, m, temp_beam);


			for (size_t i = 0; i < arrlen(mass_histo_V_0); i = i + 1) {

				mass_histo_V_0[i][1] = h_V_0 * Maxwell_abs_speed(a_V_0 + h_V_0 * i, m, temp_beam, flaq_Maxwell_mode, drift_velocity);
				mass_histo_V_0_out[i][1] = h_V_0 * Maxwell_abs_speed(a_V_0 + h_V_0_out * i, m, temp_beam, flaq_Maxwell_mode, drift_velocity);
				mass_histo_V_0_tube_out[i][1] = h_V_0_tube_out * Maxwell_abs_speed(a_V_0 + h_V_0_tube_out * i, m, temp_beam, flaq_Maxwell_mode, drift_velocity);

			}

			for (size_t i = 0; i < arrlen(mass_histo_time); i = i + 1) {

				mass_histo_time[i][1] = 0.0;

			}

		}

	}




	// молекулярный водород
	if (particle_mode == 3) {
		B_critical = B_critical_hydrogen;
		m_particle = m_particle_hydrogen_2;
		mu_core_particle = 2.0*mu_core_particle_hydrogen;
		const long double m_particle_hydrogen_u = 2.0*(1.00727646687991 + 5.4857990907016 / 10000.0)*pow(10.0, -3.0); //масса в кг/моль, а.е.м.
		if (flaq_Maxwell == false) {
			V_0 = pow(3.0*R_gas_constant*temp_beam / m_particle_hydrogen_u, 1.0 / 2.0)*1000.0;


			size_t	i = (size_t)(V_0 / h_V_0);

			mass_histo_V_0[i][1] = 1.0;

			mass_histo_time[i][1] = (L_1 + L_2 + L_3 + L_4 + L_5 + L_6 + L_7) / V_0;

			mass_histo_V_0_out[i][1] = 1.0;



			//	m_particle_temp = 2.0*1.00727646667991;
		}
		else {
			const long double m = 2.0*(1.00727646687991 + 5.4857990907016 / 10000.0); // в а.е.м.
																			   //	m_particle_temp = m;
																			   //V_0 = random_Neumann_Maxwell_abs_speed(a_V_0, b_V_0, m, temp_beam);





			for (size_t i = 0; i < arrlen(mass_histo_V_0); i = i + 1) {

				mass_histo_V_0[i][1] = h_V_0 * Maxwell_abs_speed(a_V_0 + h_V_0 * i, m, temp_beam, flaq_Maxwell_mode, drift_velocity);
				mass_histo_V_0_out[i][1] = h_V_0_out * Maxwell_abs_speed(a_V_0 + h_V_0_out * i, m, temp_beam, flaq_Maxwell_mode, drift_velocity);
				mass_histo_V_0_tube_out[i][1] = h_V_0_tube_out * Maxwell_abs_speed(a_V_0 + h_V_0_tube_out * i, m, temp_beam, flaq_Maxwell_mode, drift_velocity);

			}

			for (size_t i = 0; i < arrlen(mass_histo_time); i = i + 1) {

				mass_histo_time[i][1] = 0.0;

			}

		}


	}

	// молекулярный дейтерий
	if (particle_mode == 4) { //-V112
		B_critical = B_critical_deuterium;
		m_particle = m_particle_deuterium_2;

		//cout << "масса" << m_particle << endl;

		mu_core_particle = 2.0*mu_core_particle_deuterium;
		const long double m_particle_deuterium_u = 2.0*(1.00727646687991 + 1.0086649158849 + 5.4857990907016 / 10000.0)*pow(10.0, -3.0); //масса в кг/моль,а.е.м., приведенная масса протона и нейтрона


		if (flaq_Maxwell == false) {
			V_0 = pow(3.0*R_gas_constant*temp_beam / m_particle_deuterium_u, 1.0 / 2.0)*1000.0;

			size_t	i = (size_t)(V_0 / h_V_0);

			mass_histo_V_0[i][1] = 1.0;

			mass_histo_time[i][1] = (L_1 + L_2 + L_3 + L_4 + L_5 + L_6 + L_7) / V_0;

			mass_histo_V_0_out[i][1] = 1.0;



			//	m_particle_temp = (1.00727646667991 + 1.0086649158849);
		}
		else {

			const long double m = 2.0*(1.00727646687991 + 1.0086649158849 + 5.4857990907016 / 10000.0);
			//	m_particle_temp = m;
			//	V_0 = random_Neumann_Maxwell_abs_speed(a_V_0, b_V_0, m, temp_beam);


			for (size_t i = 0; i < arrlen(mass_histo_V_0); i = i + 1) {

				mass_histo_V_0[i][1] = h_V_0 * Maxwell_abs_speed(a_V_0 + h_V_0 * i, m, temp_beam, flaq_Maxwell_mode, drift_velocity);
				mass_histo_V_0_out[i][1] = h_V_0 * Maxwell_abs_speed(a_V_0 + h_V_0_out * i, m, temp_beam, flaq_Maxwell_mode, drift_velocity);
				mass_histo_V_0_tube_out[i][1] = h_V_0_tube_out * Maxwell_abs_speed(a_V_0 + h_V_0_tube_out * i, m, temp_beam, flaq_Maxwell_mode, drift_velocity);

			}

			for (size_t i = 0; i < arrlen(mass_histo_time); i = i + 1) {

				mass_histo_time[i][1] = 0.0;

			}

		}

	}





	//	m_particle_temp = m_particle_temp*N_A*1.6605402*pow(10.0, -10.0); // в кг, скорость в мм/сек


	/*
	if (flaq_Maxwell_mode == false) {



	v1 = pow(2.0*R_gas_constant*temp_beam / m_particle_temp, 1.0);
	v2 = pow(8.0*R_gas_constant*temp_beam / (M_PI*m_particle_temp), 1.0);
	v3 = pow(3.0*R_gas_constant*temp_beam / m_particle_temp, 1.0);

	}

	else if (flaq_Maxwell_mode == true) {




	v1 = pow(3.0*R_gas_constant*temp_beam / m_particle, 1.0);
	v2 = 3.0*pow(M_PI*R_gas_constant*temp_beam / (8.0*m_particle), 1.0);
	v3 = pow(4.0*R_gas_constant*temp_beam / m_particle, 1.0);

	}


	*/

	int NN = 0;
	int jjj = 0;

	unsigned int start_time = (unsigned int)clock(); // начальное время

	unsigned int end_time = start_time; // конечное время
	unsigned int search_time = end_time - start_time; // искомое время в миллисекундах
	unsigned int search_time_ = search_time / (1000 * 60); // минут

														   //#pragma omp parallel schedule(dynamic)
														   //{






	long double mu_particle = 0.0;
	long double mu_particle_force = 0.0;

	//long double B_temp = 0.001;
	long double B_temp = B_MAX;
	long double mu_temp_temp = 0.0;
	long double E_temp_temp = 0.0;

	const long double mu_bor = 5.788381806638*pow(10.0, 13.0)*pow(2.99792458, 2.0); // магнетон Бора электронный в единицах эВ/Гс*(скорость света [мм/c])^2

																					//	const long double mu_bor = 3.152451260522*pow(10.0, 10.0)*pow(2.99792458, 2.0); // магнетон Бора ядерный в единицах эВ/Гс*(скорость света [мм/c])^2


	const long double mu_bor_force = 9.2740096820*pow(10.0, 0.0);









	
















	//unsigned int end_time = clock(); // конечное время
	//unsigned int search_time = end_time - start_time; // искомое время в миллисекундах
	//long double search_time_ = search_time / (1000.0 * 60.0); // минут
	//&& (search_time_ <= t)

	//#pragma omp for // распараллеливание большого цикла на многопоточность
#pragma omp  parallel for ordered schedule(dynamic)
														   //#pragma omp parallel for schedule(static) ordered




	for (long int ii = 1; ii <= N; ii = ii + 1) {

		end_time = (unsigned int)clock(); // конечное время
		search_time = end_time - start_time; // искомое время в миллисекундах
		search_time_ = search_time / (1000.0 * 60.0); // минут


		if (search_time_ >= t) {
			break;
		}
		//	else {
		//		continue;
		//	}


#pragma omp ordered
		{

			trajectory_temp_cyl_x.clear();
			trajectory_temp_cyl_y.clear();
			trajectory_temp_cyl_z.clear();

			trajectory_temp_cyl_condition_color.clear();

			trajectory_temp_cyl_phi.clear();
			trajectory_temp_cyl_psi.clear();
			trajectory_temp_cyl_theta.clear();


			trajectory_temp_cyl_v_x.clear();
			trajectory_temp_cyl_v_y.clear();
			trajectory_temp_cyl_v_z.clear();
			trajectory_temp_cyl_v_r.clear();
			trajectory_temp_cyl_v_phi.clear();
			trajectory_temp_cyl_v_perp.clear();
			trajectory_temp_cyl_v_0.clear();
			trajectory_temp_cyl_force.clear();
			trajectory_temp_cyl_mu.clear();
			trajectory_temp_cyl_B.clear();


			trajectory_temp_cyl_r.clear();
			trajectory_temp_cyl_rr.clear();
			Vector_color_trajectory_temp_cyl.clear();
			out_trajectory_temp_cyl.clear();


			Vector_temp_r_mag.clear();
			Vector_temp_rr_mag.clear();
			Vector_temp_z_mag.clear();
			Vector_temp_condition_color_mag.clear();

			Vector_temp_phi_mag.clear();
			Vector_temp_psi_mag.clear();
			Vector_temp_theta_mag.clear();


			Vector_temp_v_x_mag.clear();
			Vector_temp_v_y_mag.clear();
			Vector_temp_v_z_mag.clear();
			Vector_temp_v_r_mag.clear();
			Vector_temp_v_phi_mag.clear();
			Vector_temp_v_perp_mag.clear();
			Vector_temp_v_0_mag.clear();
			Vector_temp_force_mag.clear();
			Vector_temp_mu_mag.clear();
			Vector_temp_B_mag.clear();


			Vector_temp_x_mag.clear();
			Vector_temp_y_mag.clear();
			Vector_temp_color_mag.clear();
			Vector_temp_out_mag.clear();


			N_negative_cyl_1_temp = 0, N_zero_cyl_1_temp = 0, N_positive_cyl_1_temp = 0;
			N_negative_cyl_2_temp = 0, N_zero_cyl_2_temp = 0, N_positive_cyl_2_temp = 0;
			N_negative_cyl_3_temp = 0, N_zero_cyl_3_temp = 0, N_positive_cyl_3_temp = 0;
			N_negative_cyl_4_temp = 0, N_zero_cyl_4_temp = 0, N_positive_cyl_4_temp = 0;
			N_negative_cyl_5_temp = 0, N_zero_cyl_5_temp = 0, N_positive_cyl_5_temp = 0;
			N_negative_cyl_6_temp = 0, N_zero_cyl_6_temp = 0, N_positive_cyl_6_temp = 0;
			N_negative_cyl_7_temp = 0, N_zero_cyl_7_temp = 0, N_positive_cyl_7_temp = 0;



			N_negative_mag_1_temp = 0, N_zero_mag_1_temp = 0, N_positive_mag_1_temp = 0;
			N_negative_mag_2_temp = 0, N_zero_mag_2_temp = 0, N_positive_mag_2_temp = 0;
			N_negative_mag_3_temp = 0, N_zero_mag_3_temp = 0, N_positive_mag_3_temp = 0;
			N_negative_mag_4_temp = 0, N_zero_mag_4_temp = 0, N_positive_mag_4_temp = 0;
			N_negative_mag_5_temp = 0, N_zero_mag_5_temp = 0, N_positive_mag_5_temp = 0;
			N_negative_mag_6_temp = 0, N_zero_mag_6_temp = 0, N_positive_mag_6_temp = 0;
			N_negative_mag_7_temp = 0, N_zero_mag_7_temp = 0, N_positive_mag_7_temp = 0;


			bool out1 = false, out2 = false, out3 = false, out4 = false, out5 = false, out6 = false, out7 = false;

			//	out1 = false;
			//	out2 = false;
			//	out3 = false;

			out_mag_1 = false;
			out_mag_2 = false;
			out_mag_3 = false;
			out_mag_4 = false;
			out_mag_5 = false;
			out_mag_6 = false;
			out_mag_7 = false;



			//srand((unsigned int)time(NULL) + rand()); // привязка генератора случайных чисел к системному времени

			//long double r_in = pow(random(pow(R3_1, 2.0), pow(R2_1, 2.0)), 1.0 / 2.0);
			long double r_in = 0.0;

			if (flaq_angular_coefficient == true) {

				goto step0;
			}



			//	r_in = pow((pow(R3_1, 2.0) + (pow(R2_1, 2.0) - pow(R3_1, 2.0))*random(0.0, 1.0)), 1.0 / 2.0);








			if (multi_slot_nozzle == 1) {


				r_in = pow((pow(R3_1, 2.0) + (pow(R2_1, 2.0) - pow(R3_1, 2.0))*random(0.0, 1.0)), 1.0 / 2.0);

			}


			if (multi_slot_nozzle > 1) {

				long double delta_nozzle = fabs(R2_1 - R3_1) / (2.0*multi_slot_nozzle - 1.0);

				long double S_summ_all = 0.0;	   // полная сумма ряда;


				long double *R_min = new long double[multi_slot_nozzle]; // одномерный массив входных параметров
				long double *R_max = new long double[multi_slot_nozzle]; // одномерный массив входных параметров
				long double *S = new long double[multi_slot_nozzle]; // одномерный массив входных параметров
				long double *S_summ = new long double[multi_slot_nozzle]; // частичная сумма ряда

				for (size_t i = 0; i < multi_slot_nozzle; i = i + 1) {
					R_min[i] = R3_1 + 2.0*delta_nozzle*i;
					R_max[i] = R3_1 + delta_nozzle + 2.0*delta_nozzle*i;
					S[i] = M_PI * (pow(R_max[i], 2.0) - pow(R_min[i], 2.0));


					if (i == 0) {
						S_summ[i] = S[i];
					}
					if (i >= 1) {


						S_summ[i] = S_summ[i - 1] + S[i];

					}
					S_summ_all = S_summ_all + S[i];
				}




				long double ksi_random = S_summ_all * random(0.0, 1.0);

				for (size_t i = 0; i < multi_slot_nozzle; i = i + 1) {
					if (i == 0) {

						if ((ksi_random >= 0.0) && (ksi_random <= S_summ[i])) {

							r_in = pow((pow(R_min[i], 2.0) + (pow(R_max[i], 2.0) - pow(R_min[i], 2.0))*random(0.0, 1.0)), 1.0 / 2.0);

						}


					}

					if (i >= 1) {
						if ((ksi_random > S_summ[i - 1]) && (ksi_random <= S_summ[i])) {

							r_in = pow((pow(R_min[i], 2.0) + (pow(R_max[i], 2.0) - pow(R_min[i], 2.0))*random(0.0, 1.0)), 1.0 / 2.0);

						}
					}

				}





				delete[] R_min;
				delete[] R_max;

				delete[] S;
				delete[] S_summ;

				R_min = nullptr;

				R_max = nullptr;

				S = nullptr;

				S_summ = nullptr;

			}















			//long double r_in = R1_1*pow(random(0.0,1.0),1.0/2.0);
			//long double phi = random(0.0, 2.0*M_PI);
			//long double x_in = r_in*cos(phi);
			//long double y_in = r_in*sin(phi);
			// генерируем случайные величины с помощью пользовательской функции random()
			//	long double x_in = random(-R1_1, R1_1); // от -R1_1 до R1_1
			//	srand((unsigned int)time(NULL) + rand()); // привязка генератора случайных чисел к системному времени
			//	long double y_in = random(-R1_1, R1_1); // от -R1 до R1


			//long double z_in = 0.0; // частицы вылетают из левого торца цилиндра
			//	long double r_in = pow(pow(x_in_1, 2.0) + pow(y_in_1, 2.0), 1.0 / 2.0); // начальный радиус

			//	cout << x_in << "  " << y_in << "  " << z_in << "    " << r_in << endl;







			if ((r_in <= R2_1) && (r_in >= R3_1)) {

			step0:

				V_0 = mass[24];

				N_on = N_on + 1;

				long double phi = 2.0*M_PI*random(0.0, 1.0);

				long double x_in = r_in * cos(phi);
				long double y_in = r_in * sin(phi);
				long double z_in = 0.0; // частицы вылетают из левого торца цилиндра

										//	trajectory_cyl_x.push_back(x_in);
										//	trajectory_cyl_y.push_back(y_in);
										//	trajectory_cyl_z.push_back(z_in);
										//	trajectory_cyl_r.push_back(r_in);

				long double random_theta = 0.0;

				long double	x_in_1 = x_in, y_in_1 = y_in, z_in_1 = z_in, r_in_1 = r_in, theta_in_1 = 0.0, phi_in_1 = 0.0, psi_in_1 = 0.0;
				long double	x_in_2 = 0.0, y_in_2 = 0.0, z_in_2 = 0.0, r_in_2 = 0.0, theta_in_2 = 0.0, phi_in_2 = 0.0, psi_in_2 = 0.0;
				long double	x_in_3 = 0.0, y_in_3 = 0.0, z_in_3 = 0.0, r_in_3 = 0.0, theta_in_3 = 0.0, phi_in_3 = 0.0, psi_in_3 = 0.0;
				long double	x_in_4 = 0.0, y_in_4 = 0.0, z_in_4 = 0.0, r_in_4 = 0.0, theta_in_4 = 0.0, phi_in_4 = 0.0, psi_in_4 = 0.0;
				long double	x_in_5 = 0.0, y_in_5 = 0.0, z_in_5 = 0.0, r_in_5 = 0.0, theta_in_5 = 0.0, phi_in_5 = 0.0, psi_in_5 = 0.0;
				long double	x_in_6 = 0.0, y_in_6 = 0.0, z_in_6 = 0.0, r_in_6 = 0.0, theta_in_6 = 0.0, phi_in_6 = 0.0, psi_in_6 = 0.0;
				long double	x_in_7 = 0.0, y_in_7 = 0.0, z_in_7 = 0.0, r_in_7 = 0.0, theta_in_7 = 0.0, phi_in_7 = 0.0, psi_in_7 = 0.0;

				long double theta_in_1_intens = 0.0;


				long double	x_out_1 = 0.0, y_out_1 = 0.0, z_out_1 = 0.0, r_out_1 = 0.0, theta_out_1 = 0.0, phi_out_1 = 0.0, psi_out_1 = 0.0;
				long double	x_out_2 = 0.0, y_out_2 = 0.0, z_out_2 = 0.0, r_out_2 = 0.0, theta_out_2 = 0.0, phi_out_2 = 0.0, psi_out_2 = 0.0;
				long double	x_out_3 = 0.0, y_out_3 = 0.0, z_out_3 = 0.0, r_out_3 = 0.0, theta_out_3 = 0.0, phi_out_3 = 0.0, psi_out_3 = 0.0;
				long double	x_out_4 = 0.0, y_out_4 = 0.0, z_out_4 = 0.0, r_out_4 = 0.0, theta_out_4 = 0.0, phi_out_4 = 0.0, psi_out_4 = 0.0;
				long double	x_out_5 = 0.0, y_out_5 = 0.0, z_out_5 = 0.0, r_out_5 = 0.0, theta_out_5 = 0.0, phi_out_5 = 0.0, psi_out_5 = 0.0;
				long double	x_out_6 = 0.0, y_out_6 = 0.0, z_out_6 = 0.0, r_out_6 = 0.0, theta_out_6 = 0.0, phi_out_6 = 0.0, psi_out_6 = 0.0;
				long double	x_out_7 = 0.0, y_out_7 = 0.0, z_out_7 = 0.0, r_out_7 = 0.0, theta_out_7 = 0.0, phi_out_7 = 0.0, psi_out_7 = 0.0;

				i_Collision_all_1 = i_Collision_all_1 + i_Collision_1;
				i_Collision_all_2 = i_Collision_all_2 + i_Collision_2;
				i_Collision_all_3 = i_Collision_all_3 + i_Collision_3;
				i_Collision_all_4 = i_Collision_all_4 + i_Collision_4;
				i_Collision_all_5 = i_Collision_all_5 + i_Collision_5;
				i_Collision_all_6 = i_Collision_all_6 + i_Collision_6;
				i_Collision_all_7 = i_Collision_all_7 + i_Collision_7;


				// ручной режим
				if (particle_mode == 0) {

					if (flaq_Maxwell == false) {

						V_0 = mass[24];
					}

					else {

						// перевод МэВ в а.е.м

						long double m = m_particle * 0.0010735441498156322;

						V_0 = random_Neumann_Maxwell_abs_speed(a_V_0, b_V_0, m, temp_beam, flaq_Maxwell_mode, v1, v2, v3, v4, Max_Maxwell, drift_velocity);
					}

					mu_temp = mu_temp_manual * mu_bor_temp;
					mu_force_temp = mu_temp_manual * mu_bor_force_temp;


				}


				// водород
				if (particle_mode == 1) {

					size_t mass_index = random_integer(0, (int)(SIZE_hydrogen - 1));
					I_particle = condition_hydrogen[mass_index][2];
					J_particle = condition_hydrogen[mass_index][4];
					m_F = condition_hydrogen[mass_index][1];
					m_J = condition_hydrogen[mass_index][5];


					const long double m_particle_hydrogen_u = 1.0*(1.00727646687991 + 5.4857990907016 / 10000.0)*pow(10.0, -3.0); //масса в кг/моль, а.е.м.
					//const long double m_particle_hydrogen_u = (1.00727646667991 + 5.4857990907016 / 1000.0)*pow(10.0, -3.0); //масса в кг/моль, а.е.м.



					if (flaq_Maxwell == false) {
						V_0 = pow(3.0*R_gas_constant*temp_beam / m_particle_hydrogen_u, 1.0 / 2.0)*1000.0;
					}
					else {
						const long double m = 1.0*(1.00727646687991 + 5.4857990907016 / 10000.0);

						V_0 = random_Neumann_Maxwell_abs_speed(a_V_0, b_V_0, m, temp_beam, flaq_Maxwell_mode, v1, v2, v3, v4, Max_Maxwell, drift_velocity);
					}







					if (flaq_on_off_B_mu == false) {



						size_t mu_temp_index = (size_t)random_integer(min_index_comdotion_H, max_index_comdotion_H);


						long double mu_temp_temp_temp = 0.0;
						long double E_temp_temp_temp = 0.0;
						mu_temp = mu_H(mu_temp_index, B_MAX, mu_temp_temp_temp, E_temp_temp_temp)*mu_bor_temp;
						mu_temp = mu_H(mu_temp_index, B_MAX, mu_temp_temp_temp, E_temp_temp_temp)*mu_bor_force_temp;

						/*



						if (mu_temp_index == 0) {
							mu_temp = mu_temp_const_0_H;
							mu_force_temp = mu_force_temp_const_0_H;
						}
						if (mu_temp_index == 1) {
							mu_temp = mu_temp_const_1_H;
							mu_force_temp = mu_force_temp_const_1_H;
						}
						if (mu_temp_index == 2) {
							mu_temp = mu_temp_const_2_H;
							mu_force_temp = mu_force_temp_const_2_H;
						}
						if (mu_temp_index == 3) {
							mu_temp = mu_temp_const_3_H;
							mu_force_temp = mu_force_temp_const_3_H;
						}

						*/

					}

					if (flaq_on_off_B_mu == true) {

						index_condition = (size_t)random_integer(min_index_comdotion_H, max_index_comdotion_H);

					}




				}



				// дейтерий
				if (particle_mode == 2) {
					size_t mass_index = (size_t)random_integer(0, (int)(SIZE_deuterium - 1));
					I_particle = condition_deuterium[mass_index][2];
					J_particle = condition_deuterium[mass_index][4];
					m_F = condition_deuterium[mass_index][1];
					m_J = condition_deuterium[mass_index][5];

					//cout << mass_index << endl;



					//const long double m_particle_deuterium_u = 2.0*(1.00727646667991*1.0086649158849 / (1.00727646667991 + 1.0086649158849))*pow(10.0, -3.0); //масса в кг/моль,а.е.м., приведенная масса протона и нейтрона
					const long double m_particle_deuterium_u = (1.00727646687991 + 1.0086649158849 + 5.4857990907016 / 10000.0)*pow(10.0, -3.0); //масса в кг/моль,а.е.м., приведенная масса протона и нейтрона


					if (flaq_Maxwell == false) {
						V_0 = pow(3.0*R_gas_constant*temp_beam / m_particle_deuterium_u, 1.0 / 2.0)*1000.0;
					}
					else {

						//const long double m = 2.0*(1.00727646667991*1.0086649158849 / (1.00727646667991 + 1.0086649158849));

						const long double m = (1.00727646687991 + 1.0086649158849 + 5.4857990907016 / 10000.0);


						V_0 = random_Neumann_Maxwell_abs_speed(a_V_0, b_V_0, m, temp_beam, flaq_Maxwell_mode, v1, v2, v3, v4, Max_Maxwell, drift_velocity);
					}

					if (flaq_on_off_B_mu == false) {

						size_t mu_temp_index = (size_t)random_integer(min_index_comdotion_D, max_index_comdotion_D);

						long double mu_temp_temp_temp = 0.0;
						long double E_temp_temp_temp = 0.0;
						mu_temp = mu_D(mu_temp_index, B_MAX, mu_temp_temp_temp, E_temp_temp_temp)*mu_bor_temp;
						mu_temp = mu_D(mu_temp_index, B_MAX, mu_temp_temp_temp, E_temp_temp_temp)*mu_bor_force_temp;

						
						/*



						if (mu_temp_index == 0) {
							mu_temp = mu_temp_const_0_D;
							mu_force_temp = mu_force_temp_const_0_D;
						}
						if (mu_temp_index == 1) {
							mu_temp = mu_temp_const_1_D;
							mu_force_temp = mu_force_temp_const_1_D;
						}
						if (mu_temp_index == 2) {
							mu_temp = mu_temp_const_2_D;
							mu_force_temp = mu_force_temp_const_2_D;
						}
						if (mu_temp_index == 3) {
							mu_temp = mu_temp_const_3_D;
							mu_force_temp = mu_force_temp_const_3_D;
						}
						if (mu_temp_index == 4) { //-V112
							mu_temp = mu_temp_const_4_D;
							mu_force_temp = mu_force_temp_const_4_D;
						}
						if (mu_temp_index == 5) {
							mu_temp = mu_temp_const_5_D;
							mu_force_temp = mu_force_temp_const_5_D;
						}
					   */


					}

					if (flaq_on_off_B_mu == true) {

						index_condition = (size_t)random_integer(min_index_comdotion_D, max_index_comdotion_D);

					}



				}




				// молекулярный водород
				if (particle_mode == 3) {

					size_t mass_index = (size_t)random_integer(0, (int)(SIZE_hydrogen - 1));
					I_particle = condition_molecular_hydrogen[mass_index][2];
					J_particle = condition_molecular_hydrogen[mass_index][4];
					m_F = condition_molecular_hydrogen[mass_index][1];
					m_J = condition_molecular_hydrogen[mass_index][5];

					
					const long double m_particle_hydrogen_u = 2.0*(1.00727646687991 + 5.4857990907016 / 10000.0)*pow(10.0, -3.0); //масса в кг/моль, а.е.м.
					if (flaq_Maxwell == false) {
						V_0 = pow(3.0*R_gas_constant*temp_beam / m_particle_hydrogen_u, 1.0 / 2.0)*1000.0;

					//	cout << V_0 << endl;
					}
					else {
						const long double m = 2.0*(1.00727646687991 + 5.4857990907016 / 10000.0);

						V_0 = random_Neumann_Maxwell_abs_speed(a_V_0, b_V_0, m, temp_beam, flaq_Maxwell_mode, v1, v2, v3, v4, Max_Maxwell, drift_velocity);

					//	cout << V_0 << endl;
					}

					

						if (flaq_on_off_B_mu == false) {

							size_t mu_temp_index = (size_t)random_integer(min_index_comdotion_H2, max_index_comdotion_H2);

							long double mu_temp_temp_temp = 0.0;
							long double E_temp_temp_temp = 0.0;
							mu_temp = mu_H_2(mu_temp_index, B_MAX, mu_temp_temp_temp, E_temp_temp_temp)*mu_bor_temp;
							mu_temp = mu_H_2(mu_temp_index, B_MAX, mu_temp_temp_temp, E_temp_temp_temp)*mu_bor_force_temp;


							/*




							if (mu_temp_index == 0) {
								mu_temp = mu_temp_const_0_H_2;
								mu_force_temp = mu_force_temp_const_0_H_2;
							}
							if (mu_temp_index == 1) {
								mu_temp = mu_temp_const_1_H_2;
								mu_force_temp = mu_force_temp_const_1_H_2;
							}
							if (mu_temp_index == 2) {
								mu_temp = mu_temp_const_2_H_2;
								mu_force_temp = mu_force_temp_const_2_H_2;
							}
							if (mu_temp_index == 3) {
								mu_temp = mu_temp_const_3_H_2;
								mu_force_temp = mu_force_temp_const_3_H_2;
							}
							if (mu_temp_index == 4) { //-V112
								mu_temp = mu_temp_const_4_H_2;
								mu_force_temp = mu_force_temp_const_4_H_2;
							}
							if (mu_temp_index == 5) {
								mu_temp = mu_temp_const_5_H_2;
								mu_force_temp = mu_force_temp_const_5_H_2;
							}

							if (mu_temp_index == 6) {
								mu_temp = mu_temp_const_6_H_2;
								mu_force_temp = mu_force_temp_const_6_H_2;
							}
							if (mu_temp_index == 7) {
								mu_temp = mu_temp_const_7_H_2;
								mu_force_temp = mu_force_temp_const_7_H_2;
							}
							if (mu_temp_index == 8) {
								mu_temp = mu_temp_const_8_H_2;
								mu_force_temp = mu_force_temp_const_8_H_2;
							}


							if (mu_temp_index == 9) {
								mu_temp = mu_temp_const_9_H_2;
								mu_force_temp = mu_force_temp_const_9_H_2;
							}
							if (mu_temp_index == 10) {
								mu_temp = mu_temp_const_10_H_2;
								mu_force_temp = mu_force_temp_const_10_H_2;
							}

							if (mu_temp_index == 11) {
								mu_temp = mu_temp_const_11_H_2;
								mu_force_temp = mu_force_temp_const_11_H_2;
							}


							 */
						}
						if (flaq_on_off_B_mu == true) {

							index_condition = (size_t)random_integer(min_index_comdotion_H2, max_index_comdotion_H2);
							//cout << index_condition << endl;
						}

					


					}



				

				// молекулярный дейтерий
				if (particle_mode == 4) { //-V112

					/*



					size_t mass_index = (size_t)random_integer(0, (int)(SIZE_hydrogen - 1));
					I_particle = condition_molecular_hydrogen[mass_index][2];
					J_particle = condition_molecular_hydrogen[mass_index][4];
					m_F = condition_molecular_hydrogen[mass_index][1];
					m_J = condition_molecular_hydrogen[mass_index][5];
					*/

					const long double m_particle_deuterium_u = 2.0*(1.00727646687991 + 1.0086649158849 + 5.4857990907016 / 10000.0)*pow(10.0, -3.0); //масса в кг/моль, а.е.м.
					if (flaq_Maxwell == false) {
						V_0 = pow(3.0*R_gas_constant*temp_beam / m_particle_deuterium_u, 1.0 / 2.0)*1000.0;
					}
					else {
						const long double m = 2.0*(1.00727646687991 + 1.0086649158849 + 5.4857990907016 / 10000.0);

						V_0 = random_Neumann_Maxwell_abs_speed(a_V_0, b_V_0, m, temp_beam, flaq_Maxwell_mode, v1, v2, v3, v4, Max_Maxwell, drift_velocity);
					}


					if (flaq_on_off_B_mu == false) {

						size_t mu_temp_index = (size_t)random_integer(min_index_comdotion_D2, max_index_comdotion_D2);

						long double mu_temp_temp_temp = 0.0;
						long double E_temp_temp_temp = 0.0;
						mu_temp = mu_D_2(mu_temp_index, B_MAX, mu_temp_temp_temp, E_temp_temp_temp)*mu_bor_temp;
						mu_temp = mu_D_2(mu_temp_index, B_MAX, mu_temp_temp_temp, E_temp_temp_temp)*mu_bor_force_temp;
						
						
						/*
						
						
						


						if (mu_temp_index == 0) {
							mu_temp = mu_temp_const_0_D_2;
							mu_force_temp = mu_force_temp_const_0_D_2;
						}
						if (mu_temp_index == 1) {
							mu_temp = mu_temp_const_1_D_2;
							mu_force_temp = mu_force_temp_const_1_D_2;
						}
						if (mu_temp_index == 2) {
							mu_temp = mu_temp_const_2_D_2;
							mu_force_temp = mu_force_temp_const_2_D_2;
						}
						if (mu_temp_index == 3) {
							mu_temp = mu_temp_const_3_D_2;
							mu_force_temp = mu_force_temp_const_3_D_2;
						}
						if (mu_temp_index == 4) { //-V112
							mu_temp = mu_temp_const_4_D_2;
							mu_force_temp = mu_force_temp_const_4_D_2;
						}
						if (mu_temp_index == 5) {
							mu_temp = mu_temp_const_5_D_2;
							mu_force_temp = mu_force_temp_const_5_D_2;
						}

						if (mu_temp_index == 6) {
							mu_temp = mu_temp_const_6_D_2;
							mu_force_temp = mu_force_temp_const_6_D_2;
						}
						if (mu_temp_index == 7) {
							mu_temp = mu_temp_const_7_D_2;
							mu_force_temp = mu_force_temp_const_7_D_2;
						}
						if (mu_temp_index == 8) {
							mu_temp = mu_temp_const_8_D_2;
							mu_force_temp = mu_force_temp_const_8_D_2;
						}

						*/

					}
					if (flaq_on_off_B_mu == true) {

						index_condition = (size_t)random_integer(min_index_comdotion_D2, max_index_comdotion_D2);

					}

				}




				if (flaq_on_off_B_mu == false) {
					mu_particle = mu_temp;
					mu_particle_force = mu_force_temp;
				}
				if (flaq_on_off_B_mu == true) {


					//	cout << index_condition << endl;

					if (particle_mode == 1) {
						mu_particle = mu_H(index_condition, B_temp, mu_temp_temp, E_temp_temp)*mu_bor;
						mu_particle_force = mu_H(index_condition, B_temp, mu_temp_temp, E_temp_temp)*mu_bor_force;
					}

					if (particle_mode == 2) {

						mu_particle = mu_D(index_condition, B_temp, mu_temp_temp, E_temp_temp)*mu_bor;
						mu_particle_force = mu_D(index_condition, B_temp, mu_temp_temp, E_temp_temp)*mu_bor_force;
					}

					if (particle_mode == 3) {
						mu_particle = mu_H_2(index_condition, B_temp, mu_temp_temp, E_temp_temp)*mu_bor;
						mu_particle_force = mu_H_2(index_condition, B_temp, mu_temp_temp, E_temp_temp)*mu_bor_force;

					}

					if (particle_mode == 4) { //-V112

						mu_particle = mu_D_2(index_condition, B_temp, mu_temp_temp, E_temp_temp)*mu_bor;
						mu_particle_force = mu_D_2(index_condition, B_temp, mu_temp_temp, E_temp_temp)*mu_bor_force;

					}

				}







				V_0_initial = V_0;

				histo_V_0(mass_histo_V_0, N_histo_V_0, a_V_0, b_V_0, V_0);




				//bool out1 = true, out2 = true, out3 = true;



				// углы внутри первого цилиндра

				// начальные углы вылета
				//srand((unsigned int)time(NULL) + rand()); // привязка генератора случайных чисел к системному времени


				if (n_cos_intensity == 1.0) { //-V550

					random_theta = random(0.0, 1.0);

					theta_in_1_intens = asin(random_theta);// от 0 до pi/2 распределена по закону cos(theta), получена методом обратной функции, максимум вероятности при theta=0

					theta_in_1 = asin(pow(1.0 - pow(1.0 - random_theta, 2.0 / (n_cos_intensity + 1.0)), 1.0 / 2.0));// от 0 до pi/2 распределена по закону cos(theta), получена методом обратной функции, максимум вероятности при theta=0
																	//theta_in_1 = acos(pow((1.0- random_theta),1.0/2.0));// от 0 до pi/2 распределена по закону cos(theta), получена методом обратной функции, максимум вероятности при theta=0
				}
				else {

					theta_in_1_intens = random_Neumann_theta_intensity(n_cos_intensity);

					random_theta = random(0.0, 1.0);

					//theta_in_1_intens = asin(random_theta);// от 0 до pi/2 распределена по закону cos(theta), получена методом обратной функции, максимум вероятности при theta=0

					theta_in_1 = asin(pow(1.0 - pow(1.0 - random_theta, 2.0 / (n_cos_intensity + 1.0)), 1.0 / 2.0));
				}
				//theta_in_1 = 0.0080;

				//theta_in_1 = M_PI_2*random(0.0, 1.0);

				//srand((unsigned int)time(NULL) + rand()); // привязка генератора случайных чисел к системному времени
				phi_in_1 = phi;
				//phi_in_1 = 2.0*M_PI*random(0.0, 1.0); //от 0 до 2*pi равномерно распределена
				//srand((unsigned int)time(NULL) + rand()); // привязка генератора случайных чисел к системному времени
				psi_in_1 = 2.0*M_PI*random(0.0, 1.0); //от 0 до 2*pi равномерно распределена


				v_phi_in_1 = V_0 * sin(theta_in_1)*sin(phi_in_1 - psi_in_1);


				//	histo_time(mass_histo_time, N_histo_time, a_time, b_time, (L_1 + L_2 + L_3) / (V_0*cos(theta_in_1)));


				if (cos(psi_in_1) > 0) {

					histo_theta_in(mass_histo_theta_in, N_histo_theta_in, theta_in_1_intens);
					histo_theta_in(mass_histo_theta_in_, N_histo_theta_in, theta_in_1);
				}
				if (cos(psi_in_1) <= 0) {

					histo_theta_in(mass_histo_theta_in, N_histo_theta_in, -theta_in_1_intens);
					histo_theta_in(mass_histo_theta_in_, N_histo_theta_in, -theta_in_1);
				}














				//bool out1 = false, out2 = false, out3 = false;




				if (flaq_angular_coefficient == true) {
					//angular_coefficient(V_0,R2_1, R3_1, R2_2, R3_2, L_1, x_in_2, y_in_2, z_in_2, r_in_2, phi_in_2, psi_in_2, theta_in_2, phi_1_2,v_r_in_2, trajectory_cyl_x, trajectory_cyl_y, trajectory_cyl_z, trajectory_cyl_r,v_phi_in_2,Vector_color_trajectory_cyl,trajectory_cyl_rr);

					angular_coefficient_2(V_0, R2_1, R3_1, R2_2, R3_2, L_1, x_in_2, y_in_2, z_in_2, r_in_2, phi_in_2, psi_in_2, theta_in_2, phi_1_2, v_r_in_2, trajectory_temp_cyl_x, trajectory_temp_cyl_y, trajectory_temp_cyl_z, trajectory_temp_cyl_r, v_phi_in_2, Vector_color_trajectory_temp_cyl, trajectory_temp_cyl_rr, N_CYL_partitions, x_in_1, y_in_1, z_in_1, r_in_1, out_trajectory_temp_cyl, trajectory_temp_cyl_phi, trajectory_temp_cyl_psi, trajectory_temp_cyl_theta,
						trajectory_temp_cyl_v_x, trajectory_temp_cyl_v_y, trajectory_temp_cyl_v_z, trajectory_temp_cyl_v_r, trajectory_temp_cyl_v_phi, trajectory_temp_cyl_v_perp, trajectory_temp_cyl_v_0, n_cos_intensity, trajectory_temp_cyl_force, N_negative_cyl_1, N_zero_cyl_1, N_positive_cyl_1, mu_particle, mu_particle_force, trajectory_temp_cyl_condition_color, flaq_on_off_B_mu, index_condition, particle_mode, trajectory_temp_cyl_mu, trajectory_temp_cyl_B, multi_slot_nozzle);

					//theta_in_1_intens = asin(random_theta);// от 0 до pi/2 распределена по закону cos(theta), получена методом обратной функции, максимум вероятности при theta=0

					//				theta_in_1 = theta_in_2;
					//				theta_in_1_intens = asin(pow(sin(theta_in_2), 2.0));

					//				if (cos(psi_in_2) > 0) {

					//					histo_theta_in(mass_histo_theta_in, N_histo_theta_in, theta_in_1_intens);
					//					histo_theta_in(mass_histo_theta_in_, N_histo_theta_in, theta_in_1);
					//				}
					//				if (cos(psi_in_2) <= 0) {

					//					histo_theta_in(mass_histo_theta_in, N_histo_theta_in, -theta_in_1_intens);
					//					histo_theta_in(mass_histo_theta_in_, N_histo_theta_in, -theta_in_1);
					//				}


					//	x_out_1 = x_in_2;
					//	y_out_1 = y_in_2;
					//	z_out_1 = z_in_2;
					//	r_out_1 = r_in_2;
					//	theta_out_1 = theta_in_2;
					//	phi_out_1 = phi_in_2;
					//	psi_out_1 = psi_in_2;

					out1 = true;
					out2 = false;
					out3 = false;
					out4 = false;
					out5 = false;
					out6 = false;
					out7 = false;



					goto CYL_2;

				}
				else {

					trajectory_temp_cyl_x.push_back(x_in_1);
					trajectory_temp_cyl_y.push_back(y_in_1);
					trajectory_temp_cyl_z.push_back(z_in_1);

					trajectory_temp_cyl_phi.push_back(phi_in_1);
					trajectory_temp_cyl_psi.push_back(psi_in_1);
					trajectory_temp_cyl_theta.push_back(theta_in_1);


					trajectory_temp_cyl_v_x.push_back(V_0*sin(theta_in_1)*cos(psi_in_1));
					trajectory_temp_cyl_v_y.push_back(V_0*sin(theta_in_1)*sin(psi_in_1));
					trajectory_temp_cyl_v_z.push_back(V_0*cos(theta_in_1));
					trajectory_temp_cyl_v_r.push_back(V_0*sin(theta_in_1)*cos(phi_in_1 - psi_in_1));
					trajectory_temp_cyl_v_phi.push_back(V_0*sin(theta_in_1)*sin(phi_in_1 - psi_in_1));
					trajectory_temp_cyl_v_perp.push_back(V_0*sin(theta_in_1));
					trajectory_temp_cyl_v_0.push_back(V_0);
					trajectory_temp_cyl_force.push_back(0.0);

					if (mu_particle > 0.0) {
						trajectory_cyl_condition_color.push_back(11.0);
					}
					if (fabs(mu_particle - 0.0) <= epsilon) {
						trajectory_cyl_condition_color.push_back(10.0);
					}
					if (mu_particle < 0.0) {
						trajectory_cyl_condition_color.push_back(-11.0);
					}



					trajectory_temp_cyl_r.push_back(r_in_1);




					if (y_in_1 < 0) {
						trajectory_temp_cyl_rr.push_back(-r_in_1);
					}
					else if (y_in_1 >= 0) {

						trajectory_temp_cyl_rr.push_back(r_in_1);
					}

					Vector_color_trajectory_temp_cyl.push_back(0.0);

					out_trajectory_temp_cyl.push_back(0.0);


				}


				//	trajectory_cyl_x.push_back(x_in);
				//	trajectory_cyl_y.push_back(y_in);
				//	trajectory_cyl_z.push_back(z_in);
				//	trajectory_cyl_r.push_back(r_in);



				cyl(x_in_1, y_in_1, z_in_1, r_in_1, theta_in_1, phi_in_1, psi_in_1, x_out_1, y_out_1, z_out_1, r_out_1, theta_out_1, phi_out_1, psi_out_1, N1_1, N2_1, N3_1, N4_1, N5_1, 0.0, L_1, R1_1, R2_1, R3_1, R1_1, R2_2, R3_2, b1_left, b1_surface, b1_right, V_0, out1, n1, theta1_diffusion_left, theta1_diffusion_surface, theta1_diffusion_right, z0_mag1, L_mag1, r1_mag_max_initial, r1_mag_max_final, mu_core_particle, m_particle, B1_max_initial, on_off_mag_1, mu_electron_particle, I_particle, J_particle, m_F, m_J, B_critical, N_mag_partitions, z_zero_1, n_mag_1_in, n_mag_1_absorption, n_mag_1_out, mag_runge_1, B1_max_final, m_mag_1, Vector_temp_r_mag, Vector_temp_z_mag, Vector_temp_x_mag, Vector_temp_y_mag, min_r_out_mag_1, min_r_in_mag_1, particle_mode,
					iron_mag_1, trajectory_temp_cyl_x, trajectory_temp_cyl_y, trajectory_temp_cyl_z, trajectory_temp_cyl_r, v_r_in_1, v_r_out_1, v_x_in_1, v_x_out_1, v_y_in_1, v_y_out_1, out_mag_1, v_phi_in_1, v_phi_out_1, Vector_temp_color_mag, Vector_color_trajectory_temp_cyl, 1.0, Vector_temp_rr_mag, trajectory_temp_cyl_rr, N_CYL_partitions, i_Collision_1, out_trajectory_temp_cyl, Vector_temp_out_mag, b1_mag, b1_mag_left, b1_mag_right, L_cyl_1, L_cyl_2, L_cyl_3, L_cyl_4, L_cyl_5, L_cyl_6, L_cyl_7, Vector_temp_phi_mag, Vector_temp_psi_mag, Vector_temp_theta_mag, trajectory_temp_cyl_phi, trajectory_temp_cyl_psi, trajectory_temp_cyl_theta,
					Vector_temp_v_x_mag, Vector_temp_v_y_mag, Vector_temp_v_z_mag, Vector_temp_v_r_mag, Vector_temp_v_phi_mag, Vector_temp_v_perp_mag, Vector_temp_v_0_mag, trajectory_temp_cyl_v_x, trajectory_temp_cyl_v_y, trajectory_temp_cyl_v_z, trajectory_temp_cyl_v_r, trajectory_temp_cyl_v_phi, trajectory_temp_cyl_v_perp, trajectory_temp_cyl_v_0, n_cos_intensity, Vector_temp_force_mag, trajectory_temp_cyl_force, N_negative_cyl_1, N_zero_cyl_1, N_positive_cyl_1, N_negative_mag_1, N_zero_mag_1,
					N_positive_mag_1, mu_particle, mu_particle_force, Vector_temp_condition_color_mag, trajectory_temp_cyl_condition_color, flaq_on_off_B_mu, index_condition, Vector_temp_mu_mag, Vector_temp_B_mag, trajectory_temp_cyl_mu, trajectory_temp_cyl_B, Vector_r_magnetic_field_table, Vector_phi_magnetic_field_table, Vector_B_magnetic_field_table, Vector_delta_B_magnetic_field_table, on_off_table_magnetic_field, Vector_index_r_magnetic_field_table, index_phi_magnetic_field_table, m_mag_table, r_min_mag_table, r_max_mag_table, L_mag_1_B_off_after);

				//cout << v_phi_in_1 << " " << v_phi_out_1 << endl;

				if (out1 == false) {
					out2 = false;
					out3 = false;
					out4 = false;
					out5 = false;
					out6 = false;
					out7 = false;


					out_mag_1 = false;
					out_mag_2 = false;
					out_mag_3 = false;
					out_mag_4 = false;
					out_mag_5 = false;
					out_mag_6 = false;
					out_mag_7 = false;

				}

				//cyl(x_in_1, y_in_1, z_in_1, r_in_1, theta_in_1, phi_in_1, psi_in_1, x_out_1, y_out_1, z_out_1, r_out_1, theta_out_1, phi_out_1, psi_out_1, N1_1, N2_1, N3_1, N4_1, N5_1, 0.0, 365.0, 21.0, 0.0001, 0.0, 21.0, 21.0, 0.0, b1_left, b1_surface, b1_right, V_0, out1, n1, theta1_diffusion_left, theta1_diffusion_surface, theta1_diffusion_right, z0_mag1, L_mag1);


				//	cout << x_out_1 << "  " << y_out_1 << "  " << z_out_1 << "    " << r_out_1 << endl;

				//	printf("%.9Le %.9Le\n", phi_in_1, phi_out_1);
				//	printf("%.9Le %.9Le\n", theta_in_1, theta_out_1);
				//	printf("%.9Le %.9Le\n", psi_in_1, psi_out_1);


				//	if ((out1 == true)&&(z_out_1 ==L_1)) {

				//	printf("%+.3f %+.3f %.3Lf %.3Lf\n", x_out_1, y_out_1, z_out_1, r_out_1 );

				//		printf("%.9Le %.9Le\n", phi_in_1, phi_out_1);
				//	printf("%.9Le %.9Le\n", theta_in_1, theta_out_1);
				//	printf("%.9Le %.9Le\n", psi_in_1, psi_out_1);

				//	}

				//	if (out1 == true) {

				//	goto CYL_2_;
				//}

				//#pragma omp ordered

				//int i_travel = 0;
				for (size_t i_travel = 1; i_travel <= n_travel; i_travel = i_travel + 1) {




					//out1 = false;
					//out2 = false;
					//out3 = false;

					//out_mag_1 = false;
					//out_mag_2 = false;
					//out_mag_3 = false;



					//	bool out1 = true, out2 = true, out3 = true;


					if (out1 == false) {




						//trajectory_cyl_x.erase(trajectory_cyl_x.end() - 1, trajectory_cyl_x.end());
						//trajectory_cyl_y.erase(trajectory_cyl_y.end() - 1, trajectory_cyl_y.end());

						//trajectory_cyl_z.erase(trajectory_cyl_z.end() - 1, trajectory_cyl_z.end());
						//trajectory_cyl_r.erase(trajectory_cyl_r.end() - 1, trajectory_cyl_r.end());



						//	cout << x_out_1 << "  " << y_out_1 << "  " << z_out_1 << "    " << r_out_1 << endl;

						out1 = false;
						out2 = false;
						out3 = false;
						out4 = false;
						out5 = false;
						out6 = false;
						out7 = false;

						out_mag_1 = false;
						out_mag_2 = false;
						out_mag_3 = false;
						out_mag_4 = false;
						out_mag_5 = false;
						out_mag_6 = false;
						out_mag_7 = false;

						break;
					}


					if ((out1 == true) && (fabs(z_out_1 - 0.0) <= epsilon)) {

						//cout << x_out_1 << "  " << y_out_1 << "  " << z_out_1 << "    " << r_out_1 << endl;


						//	cout << i_Collision_1 << "  " << i_Collision_2 << "  " << i_Collision_3 <<endl;

						//		int index = 1;

						//		if (out2 == true && out3 == false) {
						//		index = 2;
						//		}

						//	if (out2 == false && out3 == true) {
						//		index = 2;
						//	}

						//	if (out2 == true && out3 == true) {
						//		index = 3;
						//	}



						out1 = false;
						out2 = false;
						out3 = false;
						out4 = false;
						out5 = false;
						out6 = false;
						out7 = false;

						out_mag_1 = false;
						out_mag_2 = false;
						out_mag_3 = false;
						out_mag_4 = false;
						out_mag_5 = false;
						out_mag_6 = false;
						out_mag_7 = false;




						//	trajectory_cyl_x.erase(trajectory_cyl_x.end() - 0 - (i_Collision_1 + i_Collision_2 + i_Collision_3 + index)*(N_CYL_partitions + 1), trajectory_cyl_x.end());
						//	trajectory_cyl_y.erase(trajectory_cyl_y.end() - 0 - (i_Collision_1 + i_Collision_2 + i_Collision_3 + index)*(N_CYL_partitions + 1), trajectory_cyl_y.end());

						//	trajectory_cyl_z.erase(trajectory_cyl_z.end() - 0 - (i_Collision_1 + i_Collision_2 + i_Collision_3 + index)*(N_CYL_partitions + 1), trajectory_cyl_z.end());
						//	trajectory_cyl_r.erase(trajectory_cyl_r.end() - 0 - (i_Collision_1 + i_Collision_2 + i_Collision_3 + index)*(N_CYL_partitions + 1), trajectory_cyl_r.end());
						//	trajectory_cyl_rr.erase(trajectory_cyl_rr.end() - 0 - (i_Collision_1 + i_Collision_2 + i_Collision_3 + index)*(N_CYL_partitions + 1), trajectory_cyl_rr.end());
						//	Vector_color_trajectory_cyl.erase(Vector_color_trajectory_cyl.end() - 0 - (i_Collision_1 + i_Collision_2 + i_Collision_3 + index)*(N_CYL_partitions + 1), Vector_color_trajectory_cyl.end());

						//	trajectory_cyl_x.shrink_to_fit();
						//	trajectory_cyl_y.shrink_to_fit();
						//	trajectory_cyl_z.shrink_to_fit();
						//	trajectory_cyl_r.shrink_to_fit();
						//	trajectory_cyl_rr.shrink_to_fit();
						//	Vector_color_trajectory_cyl.shrink_to_fit();





						break;


					}

				   /*
				   
				   
					//if ((z_out_1 == L_1) && (r_out_1 <= 21.0) && (r_out_1 >= 0.0)) {

					//	NN = NN + 1;

					//	break;

					//continue;

					//}
					*/


					if ((out1 == true) && (fabs(z_out_1 - L_1) <= epsilon)) {

						//					CYL_2_:

						//	printf("%+.3f %+.3f %.3Lf %.3Lf\n", x_out_1, y_out_1, z_out_1, r_out_1 );

						//	printf("%.9Le %.9Le\n", phi_in_1, phi_out_1);
						//	printf("%.9Le %.9Le\n", theta_in_1, theta_out_1);
						//	printf("%.9Le %.9Le\n", psi_in_1, psi_out_1);



						//	long double procent = ((long double)ii / N)*100.0;
						//	unsigned int end_time0 = (unsigned int)clock(); // текущее время
						//	unsigned int search_time0 = end_time0 - start_time; // искомое время в миллисекундах


						//mass_histo_x = histo_x("histo", mass_histo_x, N_histo, x_out_1, y_out_1, R, R_source, x_0_source);
						//mass_histo_r = histo_r("histo", mass_histo_r, (int)(N_histo / 2), x_out_1, y_out_1, R, R_source, x_0_source);


						//mass_histo_x_source = histo_x("source", mass_histo_x_source, N_histo_source, x_out_1, y_out_1, R, R_source, x_0_source);
						//mass_histo_r_source = histo_r("source", mass_histo_r_source, (int)(N_histo_source / 2), x_out_1, y_out_1, R, R_source, x_0_source);

						//printf("%+.3f %+.3f %.3Lf %.3Lf %.9Le %.3Lf %.2Lf\n", x_out_1, y_out_1, z_out_1, r_out_1, (long double)ii, procent, (long double)search_time0 / 1000.0);




						x_in_2 = x_out_1;
						y_in_2 = y_out_1;
						z_in_2 = z_out_1;
						r_in_2 = r_out_1;

						v_r_in_2 = v_r_out_1;
						v_phi_in_2 = v_phi_out_1;

						theta_in_2 = theta_out_1;
						phi_in_2 = phi_out_1;
						psi_in_2 = psi_out_1;


						/*



						if (x_out_1 >= 0 && y_out_1 >= 0) {

						phi_in_2 = atan(fabs(y_out_1 / x_out_1));
						}



						if (x_out_1 < 0 && y_out_1 < 0) {

						phi_in_2 = M_PI + atan(fabs(y_out_1 / x_out_1));
						}

						if (x_out_1 > 0 && y_out_1 < 0) {

						phi_in_2 = 2.0*M_PI - atan(fabs(y_out_1 / x_out_1));
						}


						if (x_out_1 < 0 && y_out_1 > 0) {

						phi_in_2 = M_PI - atan(fabs(y_out_1 / x_out_1));
						}

						*/

					CYL_2:

						cyl(x_in_2, y_in_2, z_in_2, r_in_2, theta_in_2, phi_in_2, psi_in_2, x_out_2, y_out_2, z_out_2, r_out_2, theta_out_2, phi_out_2, psi_out_2, N1_2, N2_2, N3_2, N4_2, N5_2, L_1, L_1 + L_2, R1_2, R2_2, R3_2, R1_2, R2_3, R3_3, b2_left, b2_surface, b2_right, V_0, out2, n2, theta2_diffusion_left, theta2_diffusion_surface, theta2_diffusion_right, z0_mag2, L_mag2, r2_mag_max_initial, r2_mag_max_final, mu_core_particle, m_particle, B2_max_initial, on_off_mag_2, mu_electron_particle, I_particle, J_particle, m_F, m_J, B_critical, N_mag_partitions, z_zero_2, n_mag_2_in, n_mag_2_absorption, n_mag_2_out, mag_runge_2, B2_max_final, m_mag_2, Vector_temp_r_mag, Vector_temp_z_mag, Vector_temp_x_mag, Vector_temp_y_mag, min_r_out_mag_2, min_r_in_mag_2, particle_mode, iron_mag_2, trajectory_temp_cyl_x, trajectory_temp_cyl_y, trajectory_temp_cyl_z, trajectory_temp_cyl_r,
							v_r_in_2, v_r_out_2, v_x_in_2, v_x_out_2, v_y_in_2, v_y_out_2, out_mag_2, v_phi_in_2, v_phi_out_2, Vector_temp_color_mag, Vector_color_trajectory_temp_cyl, 2.0, Vector_temp_rr_mag, trajectory_temp_cyl_rr, N_CYL_partitions, i_Collision_2, out_trajectory_temp_cyl, Vector_temp_out_mag, b2_mag, b2_mag_left, b2_mag_right, L_cyl_1, L_cyl_2, L_cyl_3, L_cyl_4, L_cyl_5, L_cyl_6, L_cyl_7, Vector_temp_phi_mag, Vector_temp_psi_mag, Vector_temp_theta_mag, trajectory_temp_cyl_phi, trajectory_temp_cyl_psi, trajectory_temp_cyl_theta,
							Vector_temp_v_x_mag, Vector_temp_v_y_mag, Vector_temp_v_z_mag, Vector_temp_v_r_mag, Vector_temp_v_phi_mag, Vector_temp_v_perp_mag, Vector_temp_v_0_mag, trajectory_temp_cyl_v_x, trajectory_temp_cyl_v_y, trajectory_temp_cyl_v_z, trajectory_temp_cyl_v_r, trajectory_temp_cyl_v_phi, trajectory_temp_cyl_v_perp, trajectory_temp_cyl_v_0, n_cos_intensity, Vector_temp_force_mag, trajectory_temp_cyl_force, N_negative_cyl_2, N_zero_cyl_2, N_positive_cyl_2, N_negative_mag_2, N_zero_mag_2, N_positive_mag_2, mu_particle, mu_particle_force, Vector_temp_condition_color_mag, trajectory_temp_cyl_condition_color, flaq_on_off_B_mu, index_condition, Vector_temp_mu_mag, Vector_temp_B_mag, trajectory_temp_cyl_mu, trajectory_temp_cyl_B, Vector_r_magnetic_field_table, Vector_phi_magnetic_field_table, Vector_B_magnetic_field_table, Vector_delta_B_magnetic_field_table, on_off_table_magnetic_field, Vector_index_r_magnetic_field_table, index_phi_magnetic_field_table, m_mag_table, r_min_mag_table, r_max_mag_table, L_mag_2_B_off_after);





						//		if (out2 == true) {

						//			out1 = true;
						//			out3 = false;



						//		out_mag_3 = false;

						//	}

						//break;

						//	if (out2 == true) {


						//	goto CYL_3;
						//}


					}





					/*
					
					

					//printf("%+.3f %+.3f %.3Lf %.3Lf\n", x_out_2, y_out_2, z_out_2, r_out_2);


					//	if (out2 == true) {
					//		printf("%+.3f %+.3f %.3Lf %.3Lf\n", x_out_2, y_out_2, z_out_2, r_out_2);
					//	}
					*/

					if (out2 == false) {


						/*


						//printf("%s %s %s\n", (on_off_mag_1 ? "Да" : "Нет"), on_off_mag_2 ? "Да" : "Нет", on_off_mag_3 ? "Да" : "Нет");


						//printf("%s %s %s\n", (out_mag_1 ? "Да" : "Нет"), out_mag_2 ? "Да" : "Нет", out_mag_3 ? "Да" : "Нет");

						//		int index = 0;




						//if ((on_off_mag_1 == false) && (on_off_mag_2 == false)) {

						//	index = 0;
						//}

						//if ((on_off_mag_1 == true) &&( on_off_mag_2 == true)) {

						//	index = 2;
						//}

						//if ((on_off_mag_1 == true) &&( on_off_mag_2 == false)) {

						//	index = 1;
						//}

						//if ((on_off_mag_1 == false) && (on_off_mag_2 == true)) {

						//	if (out_mag_2 == true) {

						//	cout << "!!!" << endl;

						//		index = 1;
						//	}
						//	else if (out_mag_2 == false) {

						//	index = 0;
						//}


						//}


						//		index = 0;

						//printf("%s %s %s\n", (on_off_mag_1 ? "Да" : "Нет"), on_off_mag_2 ? "Да" : "Нет", on_off_mag_3 ? "Да" : "Нет");

						//index = index - 1;


						//	cout << i_Collision_1 <<" "<< i_Collision_2 << endl;


						//		if (out3 == true && out1==true) {
						//			index = 2;
						//		}

						//		if (out3 == true && out1 == false) {
						//			index = 1;
						//		}

						//		if (out3 == false && out1 == true) {
						//			index = 1;
						//		}


						//	trajectory_cyl_x.erase(trajectory_cyl_x.end() - (i_Collision_1 + i_Collision_2 + i_Collision_3 + index) * (N_CYL_partitions + 1), trajectory_cyl_x.end());
						//	trajectory_cyl_y.erase(trajectory_cyl_y.end() - (i_Collision_1 + i_Collision_2 + i_Collision_3 + index) * (N_CYL_partitions + 1), trajectory_cyl_y.end());

						//	trajectory_cyl_z.erase(trajectory_cyl_z.end() - (i_Collision_1 + i_Collision_2 + i_Collision_3 + index) * (N_CYL_partitions + 1), trajectory_cyl_z.end());
						//	trajectory_cyl_r.erase(trajectory_cyl_r.end() - (i_Collision_1 + i_Collision_2 + i_Collision_3 + index) * (N_CYL_partitions + 1), trajectory_cyl_r.end());
						//	trajectory_cyl_rr.erase(trajectory_cyl_rr.end() - (i_Collision_1 + i_Collision_2 + i_Collision_3 + index) * (N_CYL_partitions + 1), trajectory_cyl_rr.end());
						//	Vector_color_trajectory_cyl.erase(Vector_color_trajectory_cyl.end() - (i_Collision_1 + i_Collision_2 + i_Collision_3 + index) * (N_CYL_partitions + 1), Vector_color_trajectory_cyl.end());



						//	trajectory_cyl_x.shrink_to_fit();
						//	trajectory_cyl_y.shrink_to_fit();
						//	trajectory_cyl_z.shrink_to_fit();
						//	trajectory_cyl_r.shrink_to_fit();
						//	trajectory_cyl_rr.shrink_to_fit();

						//	Vector_color_trajectory_cyl.shrink_to_fit();





						//	trajectory_cyl_x.erase(trajectory_cyl_x.end() - 1 - 1 * (N_CYL_partitions - 0), trajectory_cyl_x.end());
						//	trajectory_cyl_y.erase(trajectory_cyl_y.end() - 1 - 1 * (N_CYL_partitions - 0), trajectory_cyl_y.end());

						//	trajectory_cyl_z.erase(trajectory_cyl_z.end() - 1 - 1 * (N_CYL_partitions - 0), trajectory_cyl_z.end());
						//	trajectory_cyl_r.erase(trajectory_cyl_r.end() - 1 - 1 * (N_CYL_partitions - 0), trajectory_cyl_r.end());
						//	trajectory_cyl_rr.erase(trajectory_cyl_rr.end() - 1 - 1 * (N_CYL_partitions - 0), trajectory_cyl_rr.end());




						//	Vector_color_trajectory_cyl.erase(Vector_color_trajectory_cyl.end() - 1 - 1 * (N_CYL_partitions - 0), Vector_color_trajectory_cyl.end());




						//	trajectory_cyl_x.shrink_to_fit();
						//	trajectory_cyl_y.shrink_to_fit();
						//	trajectory_cyl_z.shrink_to_fit();
						//	trajectory_cyl_r.shrink_to_fit();
						//	trajectory_cyl_rr.shrink_to_fit();

						//	Vector_color_trajectory_cyl.shrink_to_fit();

						//		if (on_off_mag_1 == true) {



						//	Vector_x_mag_1.erase(Vector_x_mag_1.end() - (N_mag_partitions + 1 + 0), Vector_x_mag_1.end());
						//	Vector_y_mag_1.erase(Vector_y_mag_1.end() - (N_mag_partitions + 1 + 0), Vector_y_mag_1.end());

						//	Vector_z_mag_1.erase(Vector_z_mag_1.end() - (N_mag_partitions + 1 + 0), Vector_z_mag_1.end());
						//	Vector_r_mag_1.erase(Vector_r_mag_1.end() - (N_mag_partitions + 1 + 0), Vector_r_mag_1.end());
						//	Vector_rr_mag_1.erase(Vector_rr_mag_1.end() - (N_mag_partitions + 1 + 0), Vector_rr_mag_1.end());

						//	Vector_color_mag_1.erase(Vector_color_mag_1.end() - (N_mag_partitions + 1 + 0), Vector_color_mag_1.end());

						//	Vector_x_mag_1.shrink_to_fit();
						//	Vector_y_mag_1.shrink_to_fit();
						//	Vector_z_mag_1.shrink_to_fit();
						//	Vector_r_mag_1.shrink_to_fit();
						//	Vector_rr_mag_1.shrink_to_fit();
						//	Vector_color_mag_1.shrink_to_fit();






						//	trajectory_cyl_x.erase(trajectory_cyl_x.end() - (N_mag_partitions + 1 + N_CYL_partitions - 0), trajectory_cyl_x.end());
						//	trajectory_cyl_y.erase(trajectory_cyl_y.end() - (N_mag_partitions + 1 + N_CYL_partitions - 0), trajectory_cyl_y.end());

						//	trajectory_cyl_z.erase(trajectory_cyl_z.end() - (N_mag_partitions + 1 + N_CYL_partitions - 0), trajectory_cyl_z.end());
						//	trajectory_cyl_r.erase(trajectory_cyl_r.end() - (N_mag_partitions + 1 + N_CYL_partitions - 0), trajectory_cyl_r.end());
						//	trajectory_cyl_rr.erase(trajectory_cyl_rr.end() - (N_mag_partitions + 1 + N_CYL_partitions - 0), trajectory_cyl_rr.end());

						//	Vector_color_trajectory_cyl.erase(Vector_color_trajectory_cyl.end() - (N_mag_partitions + 1 + N_CYL_partitions - 0), Vector_color_trajectory_cyl.end());

						//	trajectory_cyl_x.shrink_to_fit();
						//	trajectory_cyl_y.shrink_to_fit();
						//	trajectory_cyl_z.shrink_to_fit();
						//	trajectory_cyl_r.shrink_to_fit();
						//	trajectory_cyl_rr.shrink_to_fit();
						//	Vector_color_trajectory_cyl.shrink_to_fit();


						//		}
						//trajectory_cyl_x.erase(trajectory_cyl_x.end() - 2 , trajectory_cyl_x.end());
						//trajectory_cyl_y.erase(trajectory_cyl_y.end() - 2 , trajectory_cyl_y.end());

						//trajectory_cyl_z.erase(trajectory_cyl_z.end() - 2 , trajectory_cyl_z.end());
						//trajectory_cyl_r.erase(trajectory_cyl_r.end() - 2 , trajectory_cyl_r.end());





						//	trajectory_cyl_x.erase(trajectory_cyl_x.end() - 2 , trajectory_cyl_x.end());
						//	trajectory_cyl_y.erase(trajectory_cyl_y.end() - 2 , trajectory_cyl_y.end());

						//	trajectory_cyl_z.erase(trajectory_cyl_z.end() - 2 , trajectory_cyl_z.end());
						//	trajectory_cyl_r.erase(trajectory_cyl_r.end() - 2 , trajectory_cyl_r.end());


						*/

						out1 = false;
						out2 = false;
						out3 = false;
						out4 = false;
						out5 = false;
						out6 = false;
						out7 = false;

						out_mag_1 = false;
						out_mag_2 = false;
						out_mag_3 = false;
						out_mag_4 = false;
						out_mag_5 = false;
						out_mag_6 = false;
						out_mag_7 = false;


						break;
					}


					if ((out2 == true) && (fabs(z_out_2 - L_1) <= epsilon)) {

						//	cout << "!!!" << endl;


						out1 = false;
						out2 = false;
						out3 = false;
						out4 = false;
						out5 = false;
						out6 = false;
						out7 = false;



						out_mag_1 = false;
						out_mag_2 = false;
						out_mag_3 = false;
						out_mag_4 = false;
						out_mag_5 = false;
						out_mag_6 = false;
						out_mag_7 = false;

						x_in_1 = x_out_2;
						y_in_1 = y_out_2;
						z_in_1 = z_out_2;
						r_in_1 = r_out_2;

						v_r_in_1 = v_r_out_2;
						v_phi_in_1 = v_phi_out_2;

						theta_in_1 = theta_out_2;
						phi_in_1 = phi_out_2;
						psi_in_1 = psi_out_2;

						cyl(x_in_1, y_in_1, z_in_1, r_in_1, theta_in_1, phi_in_1, psi_in_1, x_out_1, y_out_1, z_out_1, r_out_1, theta_out_1, phi_out_1, psi_out_1, N1_1, N2_1, N3_1, N4_1, N5_1, 0.0, L_1, R1_1, R2_1, R3_1, R1_1, R2_2, R3_2, b1_left, b1_surface, b1_right, V_0, out1, n1, theta1_diffusion_left, theta1_diffusion_surface, theta1_diffusion_right, z0_mag1, L_mag1, r1_mag_max_initial, r1_mag_max_final, mu_core_particle, m_particle, B1_max_initial, on_off_mag_1, mu_electron_particle, I_particle, J_particle, m_F, m_J, B_critical, N_mag_partitions, z_zero_1, n_mag_1_in, n_mag_1_absorption, n_mag_1_out,
							mag_runge_1, B1_max_final, m_mag_1, Vector_temp_r_mag, Vector_temp_z_mag, Vector_temp_x_mag, Vector_temp_y_mag, min_r_out_mag_1, min_r_in_mag_1, particle_mode, iron_mag_1, trajectory_temp_cyl_x, trajectory_temp_cyl_y, trajectory_temp_cyl_z, trajectory_temp_cyl_r, v_r_in_1, v_r_out_1, v_x_in_1, v_x_out_1, v_y_in_1, v_y_out_1, out_mag_1, v_phi_in_1, v_phi_out_1, Vector_temp_color_mag, Vector_color_trajectory_temp_cyl, 1.0, Vector_temp_rr_mag, trajectory_temp_cyl_rr, N_CYL_partitions, i_Collision_1, out_trajectory_temp_cyl, Vector_temp_out_mag, b1_mag, b1_mag_left, b1_mag_right, L_cyl_1, L_cyl_2, L_cyl_3, L_cyl_4, L_cyl_5, L_cyl_6, L_cyl_7, Vector_temp_phi_mag, Vector_temp_psi_mag, Vector_temp_theta_mag, trajectory_temp_cyl_phi, trajectory_temp_cyl_psi, trajectory_temp_cyl_theta,
							Vector_temp_v_x_mag, Vector_temp_v_y_mag, Vector_temp_v_z_mag, Vector_temp_v_r_mag, Vector_temp_v_phi_mag, Vector_temp_v_perp_mag, Vector_temp_v_0_mag, trajectory_temp_cyl_v_x, trajectory_temp_cyl_v_y, trajectory_temp_cyl_v_z, trajectory_temp_cyl_v_r, trajectory_temp_cyl_v_phi, trajectory_temp_cyl_v_perp, trajectory_temp_cyl_v_0, n_cos_intensity, Vector_temp_force_mag, trajectory_temp_cyl_force, N_negative_cyl_1, N_zero_cyl_1, N_positive_cyl_1, N_negative_mag_1, N_zero_mag_1, N_positive_mag_1, mu_particle, mu_particle_force, Vector_temp_condition_color_mag, trajectory_temp_cyl_condition_color, flaq_on_off_B_mu, index_condition, Vector_temp_mu_mag, Vector_temp_B_mag, trajectory_temp_cyl_mu, trajectory_temp_cyl_B, Vector_r_magnetic_field_table,
							Vector_phi_magnetic_field_table, Vector_B_magnetic_field_table, Vector_delta_B_magnetic_field_table, on_off_table_magnetic_field, Vector_index_r_magnetic_field_table, index_phi_magnetic_field_table, m_mag_table, r_min_mag_table, r_max_mag_table, L_mag_1_B_off_after);


						continue;






					}


					if ((out2 == true) && (fabs(z_out_2 - (L_1 + L_2)) <= epsilon)) {

						//					CYL_3:



						out1 = false;
						out2 = false;
						out3 = false;
						out4 = false;
						out5 = false;
						out6 = false;
						out7 = false;


						out_mag_1 = false;
						out_mag_2 = false;
						out_mag_3 = false;
						out_mag_4 = false;
						out_mag_5 = false;
						out_mag_6 = false;
						out_mag_7 = false;


						x_in_3 = x_out_2;
						y_in_3 = y_out_2;
						z_in_3 = z_out_2;
						r_in_3 = r_out_2;

						v_r_in_3 = v_r_out_2;
						v_phi_in_3 = v_phi_out_2;

						theta_in_3 = theta_out_2;
						phi_in_3 = phi_out_2;
						psi_in_3 = psi_out_2;

						/*

						if (x_out_2 >= 0 && y_out_2 >= 0) {

						phi_in_3 = atan(fabs(y_out_2 / x_out_2));
						}



						if (x_out_2 < 0 && y_out_2 < 0) {

						phi_in_3 = M_PI + atan(fabs(y_out_2 / x_out_2));
						}

						if (x_out_2 > 0 && y_out_2 < 0) {

						phi_in_3 = 2.0*M_PI - atan(fabs(y_out_2 / x_out_2));
						}


						if (x_out_2 < 0 && y_out_2 > 0) {

						phi_in_3 = M_PI - atan(fabs(y_out_2 / x_out_2));
						}

						*/


						/*



						//cout << x_in_3 << "  " << y_in_3 << "  " << z_in_3 << "    " << r_in_3 << endl;


						//	long double procent = ((long double)ii / N)*100.0;
						//	unsigned int end_time2 = (unsigned int)clock(); // текущее время
						//	unsigned int search_time2 = end_time2 - start_time; // искомое время в миллисекундах


						//mass_histo_x = histo_x("histo", mass_histo_x, N_histo, x_out_2, y_out_2, R, R_source, x_0_source);
						//mass_histo_r = histo_r("histo", mass_histo_r, (int)(N_histo / 2), x_out_2, y_out_2, R, R_source, x_0_source);


						//mass_histo_x_source = histo_x("source", mass_histo_x_source, N_histo_source, x_out_2, y_out_2, R, R_source, x_0_source);
						//mass_histo_r_source = histo_r("source", mass_histo_r_source, (int)(N_histo_source / 2), x_out_2, y_out_2, R, R_source, x_0_source);

						//printf("%+.3f %+.3f %.3Lf %.3Lf %.9Le %.3Lf %.2Lf\n", x_out_2, y_out_2, z_out_2, r_out_2, (long double)ii, procent, (long double)search_time / 1000.0);

						//printf("%s\n",(out2 ? "Да" : "Нет"));
					   */


						cyl(x_in_3, y_in_3, z_in_3, r_in_3, theta_in_3, phi_in_3, psi_in_3, x_out_3, y_out_3, z_out_3, r_out_3, theta_out_3, phi_out_3, psi_out_3, N1_3, N2_3, N3_3, N4_3, N5_3, L_1 + L_2, L_1 + L_2 + L_3, R1_3, R2_3, R3_3, R1_3, R2_4, R3_4, b3_left, b3_surface, b3_right, V_0, out3, n3, theta3_diffusion_left, theta3_diffusion_surface, theta3_diffusion_right, z0_mag3, L_mag3, r3_mag_max_initial, r3_mag_max_final, mu_core_particle, m_particle, B3_max_initial, on_off_mag_3, mu_electron_particle, I_particle, J_particle, m_F, m_J, B_critical, N_mag_partitions, z_zero_3,
							n_mag_3_in, n_mag_3_absorption, n_mag_3_out, mag_runge_3, B3_max_final, m_mag_3, Vector_temp_r_mag, Vector_temp_z_mag, Vector_temp_x_mag, Vector_temp_y_mag, min_r_out_mag_3, min_r_in_mag_3, particle_mode, iron_mag_3, trajectory_temp_cyl_x, trajectory_temp_cyl_y, trajectory_temp_cyl_z, trajectory_temp_cyl_r, v_r_in_3, v_r_out_3, v_x_in_3, v_x_out_3, v_y_in_3, v_y_out_3, out_mag_3, v_phi_in_3, v_phi_out_3, Vector_temp_color_mag, Vector_color_trajectory_temp_cyl, 3.0, Vector_temp_rr_mag, trajectory_temp_cyl_rr, N_CYL_partitions, i_Collision_3, out_trajectory_temp_cyl, Vector_temp_out_mag, b3_mag, b3_mag_left, b3_mag_right, L_cyl_1, L_cyl_2, L_cyl_3, L_cyl_4, L_cyl_5, L_cyl_6, L_cyl_7, Vector_temp_phi_mag, Vector_temp_psi_mag, Vector_temp_theta_mag, trajectory_temp_cyl_phi, trajectory_temp_cyl_psi, trajectory_temp_cyl_theta,
							Vector_temp_v_x_mag, Vector_temp_v_y_mag, Vector_temp_v_z_mag, Vector_temp_v_r_mag, Vector_temp_v_phi_mag, Vector_temp_v_perp_mag, Vector_temp_v_0_mag, trajectory_temp_cyl_v_x, trajectory_temp_cyl_v_y, trajectory_temp_cyl_v_z, trajectory_temp_cyl_v_r, trajectory_temp_cyl_v_phi, trajectory_temp_cyl_v_perp, trajectory_temp_cyl_v_0, n_cos_intensity, Vector_temp_force_mag, trajectory_temp_cyl_force, N_negative_cyl_3, N_zero_cyl_3, N_positive_cyl_3, N_negative_mag_3, N_zero_mag_3, N_positive_mag_3, mu_particle, mu_particle_force, Vector_temp_condition_color_mag, trajectory_temp_cyl_condition_color, flaq_on_off_B_mu, index_condition, Vector_temp_mu_mag, Vector_temp_B_mag, trajectory_temp_cyl_mu, trajectory_temp_cyl_B, Vector_r_magnetic_field_table, Vector_phi_magnetic_field_table, Vector_B_magnetic_field_table,
							Vector_delta_B_magnetic_field_table, on_off_table_magnetic_field, Vector_index_r_magnetic_field_table, index_phi_magnetic_field_table, m_mag_table, r_min_mag_table, r_max_mag_table, L_mag_3_B_off_after);

						/*




						//cout << min_r_out_mag_3 << endl;


						//	if (out3 == true) {
						//		out1 = true;
						//		out2 = true;




						//		}

						//	cout << x_out_3 << "  " << y_out_3 << "  " << z_out_3 << "    " << r_out_3 << endl;
						//	out1 = false;
						//	out2 = false;

						//	continue;


						//	if (out3 == true) {

						//	cout << "YES" << endl;
						//	}


						*/

					}





					if (out3 == false) {


						/*


						//printf("%s %s %s\n", (on_off_mag_1 ? "Да" : "Нет"), on_off_mag_2 ? "Да" : "Нет", on_off_mag_3 ? "Да" : "Нет");


						//printf("%s %s %s\n", (out_mag_1 ? "Да" : "Нет"), out_mag_2 ? "Да" : "Нет", out_mag_3 ? "Да" : "Нет");

						//		int index = 0;




						//if ((on_off_mag_1 == false) && (on_off_mag_2 == false)) {

						//	index = 0;
						//}

						//if ((on_off_mag_1 == true) &&( on_off_mag_2 == true)) {

						//	index = 2;
						//}

						//if ((on_off_mag_1 == true) &&( on_off_mag_2 == false)) {

						//	index = 1;
						//}

						//if ((on_off_mag_1 == false) && (on_off_mag_2 == true)) {

						//	if (out_mag_2 == true) {

						//	cout << "!!!" << endl;

						//		index = 1;
						//	}
						//	else if (out_mag_2 == false) {

						//	index = 0;
						//}


						//}


						//		index = 0;

						//printf("%s %s %s\n", (on_off_mag_1 ? "Да" : "Нет"), on_off_mag_2 ? "Да" : "Нет", on_off_mag_3 ? "Да" : "Нет");

						//index = index - 1;


						//	cout << i_Collision_1 <<" "<< i_Collision_2 << endl;


						//		if (out3 == true && out1==true) {
						//			index = 2;
						//		}

						//		if (out3 == true && out1 == false) {
						//			index = 1;
						//		}

						//		if (out3 == false && out1 == true) {
						//			index = 1;
						//		}


						//	trajectory_cyl_x.erase(trajectory_cyl_x.end() - (i_Collision_1 + i_Collision_2 + i_Collision_3 + index) * (N_CYL_partitions + 1), trajectory_cyl_x.end());
						//	trajectory_cyl_y.erase(trajectory_cyl_y.end() - (i_Collision_1 + i_Collision_2 + i_Collision_3 + index) * (N_CYL_partitions + 1), trajectory_cyl_y.end());

						//	trajectory_cyl_z.erase(trajectory_cyl_z.end() - (i_Collision_1 + i_Collision_2 + i_Collision_3 + index) * (N_CYL_partitions + 1), trajectory_cyl_z.end());
						//	trajectory_cyl_r.erase(trajectory_cyl_r.end() - (i_Collision_1 + i_Collision_2 + i_Collision_3 + index) * (N_CYL_partitions + 1), trajectory_cyl_r.end());
						//	trajectory_cyl_rr.erase(trajectory_cyl_rr.end() - (i_Collision_1 + i_Collision_2 + i_Collision_3 + index) * (N_CYL_partitions + 1), trajectory_cyl_rr.end());
						//	Vector_color_trajectory_cyl.erase(Vector_color_trajectory_cyl.end() - (i_Collision_1 + i_Collision_2 + i_Collision_3 + index) * (N_CYL_partitions + 1), Vector_color_trajectory_cyl.end());



						//	trajectory_cyl_x.shrink_to_fit();
						//	trajectory_cyl_y.shrink_to_fit();
						//	trajectory_cyl_z.shrink_to_fit();
						//	trajectory_cyl_r.shrink_to_fit();
						//	trajectory_cyl_rr.shrink_to_fit();

						//	Vector_color_trajectory_cyl.shrink_to_fit();





						//	trajectory_cyl_x.erase(trajectory_cyl_x.end() - 1 - 1 * (N_CYL_partitions - 0), trajectory_cyl_x.end());
						//	trajectory_cyl_y.erase(trajectory_cyl_y.end() - 1 - 1 * (N_CYL_partitions - 0), trajectory_cyl_y.end());

						//	trajectory_cyl_z.erase(trajectory_cyl_z.end() - 1 - 1 * (N_CYL_partitions - 0), trajectory_cyl_z.end());
						//	trajectory_cyl_r.erase(trajectory_cyl_r.end() - 1 - 1 * (N_CYL_partitions - 0), trajectory_cyl_r.end());
						//	trajectory_cyl_rr.erase(trajectory_cyl_rr.end() - 1 - 1 * (N_CYL_partitions - 0), trajectory_cyl_rr.end());




						//	Vector_color_trajectory_cyl.erase(Vector_color_trajectory_cyl.end() - 1 - 1 * (N_CYL_partitions - 0), Vector_color_trajectory_cyl.end());




						//	trajectory_cyl_x.shrink_to_fit();
						//	trajectory_cyl_y.shrink_to_fit();
						//	trajectory_cyl_z.shrink_to_fit();
						//	trajectory_cyl_r.shrink_to_fit();
						//	trajectory_cyl_rr.shrink_to_fit();

						//	Vector_color_trajectory_cyl.shrink_to_fit();

						//		if (on_off_mag_1 == true) {



						//	Vector_x_mag_1.erase(Vector_x_mag_1.end() - (N_mag_partitions + 1 + 0), Vector_x_mag_1.end());
						//	Vector_y_mag_1.erase(Vector_y_mag_1.end() - (N_mag_partitions + 1 + 0), Vector_y_mag_1.end());

						//	Vector_z_mag_1.erase(Vector_z_mag_1.end() - (N_mag_partitions + 1 + 0), Vector_z_mag_1.end());
						//	Vector_r_mag_1.erase(Vector_r_mag_1.end() - (N_mag_partitions + 1 + 0), Vector_r_mag_1.end());
						//	Vector_rr_mag_1.erase(Vector_rr_mag_1.end() - (N_mag_partitions + 1 + 0), Vector_rr_mag_1.end());

						//	Vector_color_mag_1.erase(Vector_color_mag_1.end() - (N_mag_partitions + 1 + 0), Vector_color_mag_1.end());

						//	Vector_x_mag_1.shrink_to_fit();
						//	Vector_y_mag_1.shrink_to_fit();
						//	Vector_z_mag_1.shrink_to_fit();
						//	Vector_r_mag_1.shrink_to_fit();
						//	Vector_rr_mag_1.shrink_to_fit();
						//	Vector_color_mag_1.shrink_to_fit();






						//	trajectory_cyl_x.erase(trajectory_cyl_x.end() - (N_mag_partitions + 1 + N_CYL_partitions - 0), trajectory_cyl_x.end());
						//	trajectory_cyl_y.erase(trajectory_cyl_y.end() - (N_mag_partitions + 1 + N_CYL_partitions - 0), trajectory_cyl_y.end());

						//	trajectory_cyl_z.erase(trajectory_cyl_z.end() - (N_mag_partitions + 1 + N_CYL_partitions - 0), trajectory_cyl_z.end());
						//	trajectory_cyl_r.erase(trajectory_cyl_r.end() - (N_mag_partitions + 1 + N_CYL_partitions - 0), trajectory_cyl_r.end());
						//	trajectory_cyl_rr.erase(trajectory_cyl_rr.end() - (N_mag_partitions + 1 + N_CYL_partitions - 0), trajectory_cyl_rr.end());

						//	Vector_color_trajectory_cyl.erase(Vector_color_trajectory_cyl.end() - (N_mag_partitions + 1 + N_CYL_partitions - 0), Vector_color_trajectory_cyl.end());

						//	trajectory_cyl_x.shrink_to_fit();
						//	trajectory_cyl_y.shrink_to_fit();
						//	trajectory_cyl_z.shrink_to_fit();
						//	trajectory_cyl_r.shrink_to_fit();
						//	trajectory_cyl_rr.shrink_to_fit();
						//	Vector_color_trajectory_cyl.shrink_to_fit();


						//		}
						//trajectory_cyl_x.erase(trajectory_cyl_x.end() - 2 , trajectory_cyl_x.end());
						//trajectory_cyl_y.erase(trajectory_cyl_y.end() - 2 , trajectory_cyl_y.end());

						//trajectory_cyl_z.erase(trajectory_cyl_z.end() - 2 , trajectory_cyl_z.end());
						//trajectory_cyl_r.erase(trajectory_cyl_r.end() - 2 , trajectory_cyl_r.end());





						//	trajectory_cyl_x.erase(trajectory_cyl_x.end() - 2 , trajectory_cyl_x.end());
						//	trajectory_cyl_y.erase(trajectory_cyl_y.end() - 2 , trajectory_cyl_y.end());

						//	trajectory_cyl_z.erase(trajectory_cyl_z.end() - 2 , trajectory_cyl_z.end());
						//	trajectory_cyl_r.erase(trajectory_cyl_r.end() - 2 , trajectory_cyl_r.end());


						*/

						out1 = false;
						out2 = false;
						out3 = false;
						out4 = false;
						out5 = false;
						out6 = false;
						out7 = false;

						out_mag_1 = false;
						out_mag_2 = false;
						out_mag_3 = false;
						out_mag_4 = false;
						out_mag_5 = false;
						out_mag_6 = false;
						out_mag_7 = false;


						break;
					}


					if ((out3 == true) && (fabs(z_out_3 - (L_1 + L_2)) <= epsilon)) {

						//	cout << "!!!" << endl;


						out1 = false;
						out2 = false;
						out3 = false;
						out4 = false;
						out5 = false;
						out6 = false;
						out7 = false;



						out_mag_1 = false;
						out_mag_2 = false;
						out_mag_3 = false;
						out_mag_4 = false;
						out_mag_5 = false;
						out_mag_6 = false;
						out_mag_7 = false;

						x_in_2 = x_out_3;
						y_in_2 = y_out_3;
						z_in_2 = z_out_3;
						r_in_2 = r_out_3;

						v_r_in_2 = v_r_out_3;
						v_phi_in_2 = v_phi_out_3;

						theta_in_2 = theta_out_3;
						phi_in_2 = phi_out_3;
						psi_in_2 = psi_out_3;

						cyl(x_in_2, y_in_2, z_in_2, r_in_2, theta_in_2, phi_in_2, psi_in_2, x_out_2, y_out_2, z_out_2, r_out_2, theta_out_2, phi_out_2, psi_out_2, N1_2, N2_2, N3_2, N4_2, N5_2, L_1, L_1 + L_2, R1_2, R2_2, R3_2, R1_2, R2_3, R3_3, b2_left, b2_surface, b2_right, V_0, out2, n2, theta2_diffusion_left, theta2_diffusion_surface, theta2_diffusion_right, z0_mag2, L_mag2, r2_mag_max_initial, r2_mag_max_final, mu_core_particle, m_particle, B2_max_initial, on_off_mag_2, mu_electron_particle, I_particle, J_particle, m_F, m_J, B_critical, N_mag_partitions, z_zero_2, n_mag_2_in, n_mag_2_absorption, n_mag_2_out,
							mag_runge_2, B2_max_final, m_mag_2, Vector_temp_r_mag, Vector_temp_z_mag, Vector_temp_x_mag, Vector_temp_y_mag, min_r_out_mag_2, min_r_in_mag_2, particle_mode, iron_mag_2, trajectory_temp_cyl_x, trajectory_temp_cyl_y, trajectory_temp_cyl_z, trajectory_temp_cyl_r, v_r_in_2, v_r_out_2, v_x_in_2, v_x_out_2, v_y_in_2, v_y_out_2, out_mag_2, v_phi_in_2, v_phi_out_2, Vector_temp_color_mag, Vector_color_trajectory_temp_cyl, 2.0, Vector_temp_rr_mag, trajectory_temp_cyl_rr, N_CYL_partitions, i_Collision_2, out_trajectory_temp_cyl, Vector_temp_out_mag, b2_mag, b2_mag_left, b2_mag_right, L_cyl_1, L_cyl_2, L_cyl_3, L_cyl_4, L_cyl_5, L_cyl_6, L_cyl_7, Vector_temp_phi_mag, Vector_temp_psi_mag, Vector_temp_theta_mag, trajectory_temp_cyl_phi, trajectory_temp_cyl_psi, trajectory_temp_cyl_theta,
							Vector_temp_v_x_mag, Vector_temp_v_y_mag, Vector_temp_v_z_mag, Vector_temp_v_r_mag, Vector_temp_v_phi_mag, Vector_temp_v_perp_mag, Vector_temp_v_0_mag, trajectory_temp_cyl_v_x, trajectory_temp_cyl_v_y, trajectory_temp_cyl_v_z, trajectory_temp_cyl_v_r, trajectory_temp_cyl_v_phi, trajectory_temp_cyl_v_perp, trajectory_temp_cyl_v_0, n_cos_intensity, Vector_temp_force_mag, trajectory_temp_cyl_force, N_negative_cyl_2, N_zero_cyl_2, N_positive_cyl_2, N_negative_mag_2, N_zero_mag_2, N_positive_mag_2, mu_particle, mu_particle_force, Vector_temp_condition_color_mag, trajectory_temp_cyl_condition_color, flaq_on_off_B_mu, index_condition, Vector_temp_mu_mag, Vector_temp_B_mag, trajectory_temp_cyl_mu, trajectory_temp_cyl_B, Vector_r_magnetic_field_table,
							Vector_phi_magnetic_field_table, Vector_B_magnetic_field_table, Vector_delta_B_magnetic_field_table, on_off_table_magnetic_field, Vector_index_r_magnetic_field_table, index_phi_magnetic_field_table, m_mag_table, r_min_mag_table, r_max_mag_table, L_mag_2_B_off_after);


						continue;






					}


					if ((out3 == true) && (fabs(z_out_3 - (L_1 + L_2 + L_3)) <= epsilon)) {

						//					CYL_3:



						out1 = false;
						out2 = false;
						out3 = false;
						out4 = false;
						out5 = false;
						out6 = false;
						out7 = false;


						out_mag_1 = false;
						out_mag_2 = false;
						out_mag_3 = false;
						out_mag_4 = false;
						out_mag_5 = false;
						out_mag_6 = false;
						out_mag_7 = false;


						x_in_4 = x_out_3;
						y_in_4 = y_out_3;
						z_in_4 = z_out_3;
						r_in_4 = r_out_3;

						v_r_in_4 = v_r_out_3;
						v_phi_in_4 = v_phi_out_3;

						theta_in_4 = theta_out_3;
						phi_in_4 = phi_out_3;
						psi_in_4 = psi_out_3;

						/*

						if (x_out_2 >= 0 && y_out_2 >= 0) {

						phi_in_3 = atan(fabs(y_out_2 / x_out_2));
						}



						if (x_out_2 < 0 && y_out_2 < 0) {

						phi_in_3 = M_PI + atan(fabs(y_out_2 / x_out_2));
						}

						if (x_out_2 > 0 && y_out_2 < 0) {

						phi_in_3 = 2.0*M_PI - atan(fabs(y_out_2 / x_out_2));
						}


						if (x_out_2 < 0 && y_out_2 > 0) {

						phi_in_3 = M_PI - atan(fabs(y_out_2 / x_out_2));
						}

						*/


						/*



						//cout << x_in_3 << "  " << y_in_3 << "  " << z_in_3 << "    " << r_in_3 << endl;


						//	long double procent = ((long double)ii / N)*100.0;
						//	unsigned int end_time2 = (unsigned int)clock(); // текущее время
						//	unsigned int search_time2 = end_time2 - start_time; // искомое время в миллисекундах


						//mass_histo_x = histo_x("histo", mass_histo_x, N_histo, x_out_2, y_out_2, R, R_source, x_0_source);
						//mass_histo_r = histo_r("histo", mass_histo_r, (int)(N_histo / 2), x_out_2, y_out_2, R, R_source, x_0_source);


						//mass_histo_x_source = histo_x("source", mass_histo_x_source, N_histo_source, x_out_2, y_out_2, R, R_source, x_0_source);
						//mass_histo_r_source = histo_r("source", mass_histo_r_source, (int)(N_histo_source / 2), x_out_2, y_out_2, R, R_source, x_0_source);

						//printf("%+.3f %+.3f %.3Lf %.3Lf %.9Le %.3Lf %.2Lf\n", x_out_2, y_out_2, z_out_2, r_out_2, (long double)ii, procent, (long double)search_time / 1000.0);

						//printf("%s\n",(out2 ? "Да" : "Нет"));
						*/


						cyl(x_in_4, y_in_4, z_in_4, r_in_4, theta_in_4, phi_in_4, psi_in_4, x_out_4, y_out_4, z_out_4, r_out_4, theta_out_4, phi_out_4, psi_out_4, N1_4, N2_4, N3_4, N4_4, N5_4, L_1 + L_2 + L_3, L_1 + L_2 + L_3 + L_4, R1_4, R2_4, R3_4, R1_4, R2_5, R3_5, b4_left, b4_surface, b4_right, V_0, out4, n4, theta4_diffusion_left, theta4_diffusion_surface, theta4_diffusion_right, z0_mag4, L_mag4, r4_mag_max_initial, r4_mag_max_final, mu_core_particle, m_particle, B4_max_initial, on_off_mag_4, mu_electron_particle, I_particle, J_particle, m_F, m_J, B_critical, N_mag_partitions, z_zero_4,
							n_mag_4_in, n_mag_4_absorption, n_mag_4_out, mag_runge_4, B4_max_final, m_mag_4, Vector_temp_r_mag, Vector_temp_z_mag, Vector_temp_x_mag, Vector_temp_y_mag, min_r_out_mag_4, min_r_in_mag_4, particle_mode, iron_mag_4, trajectory_temp_cyl_x, trajectory_temp_cyl_y, trajectory_temp_cyl_z, trajectory_temp_cyl_r, v_r_in_4, v_r_out_4, v_x_in_4, v_x_out_4, v_y_in_4, v_y_out_4, out_mag_4, v_phi_in_4, v_phi_out_4, Vector_temp_color_mag, Vector_color_trajectory_temp_cyl, 4.0, Vector_temp_rr_mag, trajectory_temp_cyl_rr, N_CYL_partitions, i_Collision_4, out_trajectory_temp_cyl, Vector_temp_out_mag, b4_mag, b4_mag_left, b4_mag_right, L_cyl_1, L_cyl_2, L_cyl_3, L_cyl_4, L_cyl_5, L_cyl_6, L_cyl_7, Vector_temp_phi_mag, Vector_temp_psi_mag, Vector_temp_theta_mag, trajectory_temp_cyl_phi, trajectory_temp_cyl_psi, trajectory_temp_cyl_theta,
							Vector_temp_v_x_mag, Vector_temp_v_y_mag, Vector_temp_v_z_mag, Vector_temp_v_r_mag, Vector_temp_v_phi_mag, Vector_temp_v_perp_mag, Vector_temp_v_0_mag, trajectory_temp_cyl_v_x, trajectory_temp_cyl_v_y, trajectory_temp_cyl_v_z, trajectory_temp_cyl_v_r, trajectory_temp_cyl_v_phi, trajectory_temp_cyl_v_perp, trajectory_temp_cyl_v_0, n_cos_intensity, Vector_temp_force_mag, trajectory_temp_cyl_force, N_negative_cyl_4, N_zero_cyl_4, N_positive_cyl_4, N_negative_mag_4, N_zero_mag_4, N_positive_mag_4, mu_particle, mu_particle_force, Vector_temp_condition_color_mag, trajectory_temp_cyl_condition_color, flaq_on_off_B_mu, index_condition, Vector_temp_mu_mag, Vector_temp_B_mag, trajectory_temp_cyl_mu, trajectory_temp_cyl_B, Vector_r_magnetic_field_table, Vector_phi_magnetic_field_table, Vector_B_magnetic_field_table,
							Vector_delta_B_magnetic_field_table, on_off_table_magnetic_field, Vector_index_r_magnetic_field_table, index_phi_magnetic_field_table, m_mag_table, r_min_mag_table, r_max_mag_table, L_mag_4_B_off_after);

						/*




						//cout << min_r_out_mag_3 << endl;


						//	if (out3 == true) {
						//		out1 = true;
						//		out2 = true;




						//		}

						//	cout << x_out_3 << "  " << y_out_3 << "  " << z_out_3 << "    " << r_out_3 << endl;
						//	out1 = false;
						//	out2 = false;

						//	continue;


						//	if (out3 == true) {

						//	cout << "YES" << endl;
						//	}


						*/

					}










					if (out4 == false) {


						/*


						//printf("%s %s %s\n", (on_off_mag_1 ? "Да" : "Нет"), on_off_mag_2 ? "Да" : "Нет", on_off_mag_3 ? "Да" : "Нет");


						//printf("%s %s %s\n", (out_mag_1 ? "Да" : "Нет"), out_mag_2 ? "Да" : "Нет", out_mag_3 ? "Да" : "Нет");

						//		int index = 0;




						//if ((on_off_mag_1 == false) && (on_off_mag_2 == false)) {

						//	index = 0;
						//}

						//if ((on_off_mag_1 == true) &&( on_off_mag_2 == true)) {

						//	index = 2;
						//}

						//if ((on_off_mag_1 == true) &&( on_off_mag_2 == false)) {

						//	index = 1;
						//}

						//if ((on_off_mag_1 == false) && (on_off_mag_2 == true)) {

						//	if (out_mag_2 == true) {

						//	cout << "!!!" << endl;

						//		index = 1;
						//	}
						//	else if (out_mag_2 == false) {

						//	index = 0;
						//}


						//}


						//		index = 0;

						//printf("%s %s %s\n", (on_off_mag_1 ? "Да" : "Нет"), on_off_mag_2 ? "Да" : "Нет", on_off_mag_3 ? "Да" : "Нет");

						//index = index - 1;


						//	cout << i_Collision_1 <<" "<< i_Collision_2 << endl;


						//		if (out3 == true && out1==true) {
						//			index = 2;
						//		}

						//		if (out3 == true && out1 == false) {
						//			index = 1;
						//		}

						//		if (out3 == false && out1 == true) {
						//			index = 1;
						//		}


						//	trajectory_cyl_x.erase(trajectory_cyl_x.end() - (i_Collision_1 + i_Collision_2 + i_Collision_3 + index) * (N_CYL_partitions + 1), trajectory_cyl_x.end());
						//	trajectory_cyl_y.erase(trajectory_cyl_y.end() - (i_Collision_1 + i_Collision_2 + i_Collision_3 + index) * (N_CYL_partitions + 1), trajectory_cyl_y.end());

						//	trajectory_cyl_z.erase(trajectory_cyl_z.end() - (i_Collision_1 + i_Collision_2 + i_Collision_3 + index) * (N_CYL_partitions + 1), trajectory_cyl_z.end());
						//	trajectory_cyl_r.erase(trajectory_cyl_r.end() - (i_Collision_1 + i_Collision_2 + i_Collision_3 + index) * (N_CYL_partitions + 1), trajectory_cyl_r.end());
						//	trajectory_cyl_rr.erase(trajectory_cyl_rr.end() - (i_Collision_1 + i_Collision_2 + i_Collision_3 + index) * (N_CYL_partitions + 1), trajectory_cyl_rr.end());
						//	Vector_color_trajectory_cyl.erase(Vector_color_trajectory_cyl.end() - (i_Collision_1 + i_Collision_2 + i_Collision_3 + index) * (N_CYL_partitions + 1), Vector_color_trajectory_cyl.end());



						//	trajectory_cyl_x.shrink_to_fit();
						//	trajectory_cyl_y.shrink_to_fit();
						//	trajectory_cyl_z.shrink_to_fit();
						//	trajectory_cyl_r.shrink_to_fit();
						//	trajectory_cyl_rr.shrink_to_fit();

						//	Vector_color_trajectory_cyl.shrink_to_fit();





						//	trajectory_cyl_x.erase(trajectory_cyl_x.end() - 1 - 1 * (N_CYL_partitions - 0), trajectory_cyl_x.end());
						//	trajectory_cyl_y.erase(trajectory_cyl_y.end() - 1 - 1 * (N_CYL_partitions - 0), trajectory_cyl_y.end());

						//	trajectory_cyl_z.erase(trajectory_cyl_z.end() - 1 - 1 * (N_CYL_partitions - 0), trajectory_cyl_z.end());
						//	trajectory_cyl_r.erase(trajectory_cyl_r.end() - 1 - 1 * (N_CYL_partitions - 0), trajectory_cyl_r.end());
						//	trajectory_cyl_rr.erase(trajectory_cyl_rr.end() - 1 - 1 * (N_CYL_partitions - 0), trajectory_cyl_rr.end());




						//	Vector_color_trajectory_cyl.erase(Vector_color_trajectory_cyl.end() - 1 - 1 * (N_CYL_partitions - 0), Vector_color_trajectory_cyl.end());




						//	trajectory_cyl_x.shrink_to_fit();
						//	trajectory_cyl_y.shrink_to_fit();
						//	trajectory_cyl_z.shrink_to_fit();
						//	trajectory_cyl_r.shrink_to_fit();
						//	trajectory_cyl_rr.shrink_to_fit();

						//	Vector_color_trajectory_cyl.shrink_to_fit();

						//		if (on_off_mag_1 == true) {



						//	Vector_x_mag_1.erase(Vector_x_mag_1.end() - (N_mag_partitions + 1 + 0), Vector_x_mag_1.end());
						//	Vector_y_mag_1.erase(Vector_y_mag_1.end() - (N_mag_partitions + 1 + 0), Vector_y_mag_1.end());

						//	Vector_z_mag_1.erase(Vector_z_mag_1.end() - (N_mag_partitions + 1 + 0), Vector_z_mag_1.end());
						//	Vector_r_mag_1.erase(Vector_r_mag_1.end() - (N_mag_partitions + 1 + 0), Vector_r_mag_1.end());
						//	Vector_rr_mag_1.erase(Vector_rr_mag_1.end() - (N_mag_partitions + 1 + 0), Vector_rr_mag_1.end());

						//	Vector_color_mag_1.erase(Vector_color_mag_1.end() - (N_mag_partitions + 1 + 0), Vector_color_mag_1.end());

						//	Vector_x_mag_1.shrink_to_fit();
						//	Vector_y_mag_1.shrink_to_fit();
						//	Vector_z_mag_1.shrink_to_fit();
						//	Vector_r_mag_1.shrink_to_fit();
						//	Vector_rr_mag_1.shrink_to_fit();
						//	Vector_color_mag_1.shrink_to_fit();






						//	trajectory_cyl_x.erase(trajectory_cyl_x.end() - (N_mag_partitions + 1 + N_CYL_partitions - 0), trajectory_cyl_x.end());
						//	trajectory_cyl_y.erase(trajectory_cyl_y.end() - (N_mag_partitions + 1 + N_CYL_partitions - 0), trajectory_cyl_y.end());

						//	trajectory_cyl_z.erase(trajectory_cyl_z.end() - (N_mag_partitions + 1 + N_CYL_partitions - 0), trajectory_cyl_z.end());
						//	trajectory_cyl_r.erase(trajectory_cyl_r.end() - (N_mag_partitions + 1 + N_CYL_partitions - 0), trajectory_cyl_r.end());
						//	trajectory_cyl_rr.erase(trajectory_cyl_rr.end() - (N_mag_partitions + 1 + N_CYL_partitions - 0), trajectory_cyl_rr.end());

						//	Vector_color_trajectory_cyl.erase(Vector_color_trajectory_cyl.end() - (N_mag_partitions + 1 + N_CYL_partitions - 0), Vector_color_trajectory_cyl.end());

						//	trajectory_cyl_x.shrink_to_fit();
						//	trajectory_cyl_y.shrink_to_fit();
						//	trajectory_cyl_z.shrink_to_fit();
						//	trajectory_cyl_r.shrink_to_fit();
						//	trajectory_cyl_rr.shrink_to_fit();
						//	Vector_color_trajectory_cyl.shrink_to_fit();


						//		}
						//trajectory_cyl_x.erase(trajectory_cyl_x.end() - 2 , trajectory_cyl_x.end());
						//trajectory_cyl_y.erase(trajectory_cyl_y.end() - 2 , trajectory_cyl_y.end());

						//trajectory_cyl_z.erase(trajectory_cyl_z.end() - 2 , trajectory_cyl_z.end());
						//trajectory_cyl_r.erase(trajectory_cyl_r.end() - 2 , trajectory_cyl_r.end());





						//	trajectory_cyl_x.erase(trajectory_cyl_x.end() - 2 , trajectory_cyl_x.end());
						//	trajectory_cyl_y.erase(trajectory_cyl_y.end() - 2 , trajectory_cyl_y.end());

						//	trajectory_cyl_z.erase(trajectory_cyl_z.end() - 2 , trajectory_cyl_z.end());
						//	trajectory_cyl_r.erase(trajectory_cyl_r.end() - 2 , trajectory_cyl_r.end());


						*/

						out1 = false;
						out2 = false;
						out3 = false;
						out4 = false;
						out5 = false;
						out6 = false;
						out7 = false;

						out_mag_1 = false;
						out_mag_2 = false;
						out_mag_3 = false;
						out_mag_4 = false;
						out_mag_5 = false;
						out_mag_6 = false;
						out_mag_7 = false;


						break;
					}


					if ((out4 == true) && (fabs(z_out_4 - (L_1 + L_2 + L_3)) <= epsilon)) {

						//	cout << "!!!" << endl;


						out1 = false;
						out2 = false;
						out3 = false;
						out4 = false;
						out5 = false;
						out6 = false;
						out7 = false;



						out_mag_1 = false;
						out_mag_2 = false;
						out_mag_3 = false;
						out_mag_4 = false;
						out_mag_5 = false;
						out_mag_6 = false;
						out_mag_7 = false;

						x_in_3 = x_out_4;
						y_in_3 = y_out_4;
						z_in_3 = z_out_4;
						r_in_3 = r_out_4;

						v_r_in_3 = v_r_out_4;
						v_phi_in_3 = v_phi_out_4;

						theta_in_3 = theta_out_4;
						phi_in_3 = phi_out_4;
						psi_in_3 = psi_out_4;

						cyl(x_in_3, y_in_3, z_in_3, r_in_3, theta_in_3, phi_in_3, psi_in_3, x_out_3, y_out_3, z_out_3, r_out_3, theta_out_3, phi_out_3, psi_out_3, N1_3, N2_3, N3_3, N4_3, N5_3, L_1 + L_2, L_1 + L_2 + L_3, R1_3, R2_3, R3_3, R1_3, R2_4, R3_4, b3_left, b3_surface, b3_right, V_0, out3, n3, theta3_diffusion_left, theta3_diffusion_surface, theta3_diffusion_right, z0_mag3, L_mag3, r3_mag_max_initial, r3_mag_max_final, mu_core_particle, m_particle, B3_max_initial, on_off_mag_3, mu_electron_particle, I_particle, J_particle, m_F, m_J, B_critical, N_mag_partitions, z_zero_3, n_mag_3_in, n_mag_3_absorption, n_mag_3_out,
							mag_runge_3, B3_max_final, m_mag_3, Vector_temp_r_mag, Vector_temp_z_mag, Vector_temp_x_mag, Vector_temp_y_mag, min_r_out_mag_3, min_r_in_mag_3, particle_mode, iron_mag_3, trajectory_temp_cyl_x, trajectory_temp_cyl_y, trajectory_temp_cyl_z, trajectory_temp_cyl_r, v_r_in_3, v_r_out_3, v_x_in_3, v_x_out_3, v_y_in_3, v_y_out_3, out_mag_3, v_phi_in_3, v_phi_out_3, Vector_temp_color_mag, Vector_color_trajectory_temp_cyl, 3.0, Vector_temp_rr_mag, trajectory_temp_cyl_rr, N_CYL_partitions, i_Collision_3, out_trajectory_temp_cyl, Vector_temp_out_mag, b3_mag, b3_mag_left, b3_mag_right, L_cyl_1, L_cyl_2, L_cyl_3, L_cyl_4, L_cyl_5, L_cyl_6, L_cyl_7, Vector_temp_phi_mag, Vector_temp_psi_mag, Vector_temp_theta_mag, trajectory_temp_cyl_phi, trajectory_temp_cyl_psi, trajectory_temp_cyl_theta,
							Vector_temp_v_x_mag, Vector_temp_v_y_mag, Vector_temp_v_z_mag, Vector_temp_v_r_mag, Vector_temp_v_phi_mag, Vector_temp_v_perp_mag, Vector_temp_v_0_mag, trajectory_temp_cyl_v_x, trajectory_temp_cyl_v_y, trajectory_temp_cyl_v_z, trajectory_temp_cyl_v_r, trajectory_temp_cyl_v_phi, trajectory_temp_cyl_v_perp, trajectory_temp_cyl_v_0, n_cos_intensity, Vector_temp_force_mag, trajectory_temp_cyl_force, N_negative_cyl_3, N_zero_cyl_3, N_positive_cyl_3, N_negative_mag_3, N_zero_mag_3, N_positive_mag_3, mu_particle, mu_particle_force, Vector_temp_condition_color_mag, trajectory_temp_cyl_condition_color, flaq_on_off_B_mu, index_condition, Vector_temp_mu_mag, Vector_temp_B_mag, trajectory_temp_cyl_mu, trajectory_temp_cyl_B, Vector_r_magnetic_field_table,
							Vector_phi_magnetic_field_table, Vector_B_magnetic_field_table, Vector_delta_B_magnetic_field_table, on_off_table_magnetic_field, Vector_index_r_magnetic_field_table, index_phi_magnetic_field_table, m_mag_table, r_min_mag_table, r_max_mag_table, L_mag_3_B_off_after);


						continue;






					}


					if ((out4 == true) && (fabs(z_out_4 - (L_1 + L_2 + L_3 + L_4)) <= epsilon)) {

						//					CYL_3:



						out1 = false;
						out2 = false;
						out3 = false;
						out4 = false;
						out5 = false;
						out6 = false;
						out7 = false;


						out_mag_1 = false;
						out_mag_2 = false;
						out_mag_3 = false;
						out_mag_4 = false;
						out_mag_5 = false;
						out_mag_6 = false;
						out_mag_7 = false;


						x_in_5 = x_out_4;
						y_in_5 = y_out_4;
						z_in_5 = z_out_4;
						r_in_5 = r_out_4;

						v_r_in_5 = v_r_out_4;
						v_phi_in_5 = v_phi_out_4;

						theta_in_5 = theta_out_4;
						phi_in_5 = phi_out_4;
						psi_in_5 = psi_out_4;

						/*

						if (x_out_2 >= 0 && y_out_2 >= 0) {

						phi_in_3 = atan(fabs(y_out_2 / x_out_2));
						}



						if (x_out_2 < 0 && y_out_2 < 0) {

						phi_in_3 = M_PI + atan(fabs(y_out_2 / x_out_2));
						}

						if (x_out_2 > 0 && y_out_2 < 0) {

						phi_in_3 = 2.0*M_PI - atan(fabs(y_out_2 / x_out_2));
						}


						if (x_out_2 < 0 && y_out_2 > 0) {

						phi_in_3 = M_PI - atan(fabs(y_out_2 / x_out_2));
						}

						*/


						/*



						//cout << x_in_3 << "  " << y_in_3 << "  " << z_in_3 << "    " << r_in_3 << endl;


						//	long double procent = ((long double)ii / N)*100.0;
						//	unsigned int end_time2 = (unsigned int)clock(); // текущее время
						//	unsigned int search_time2 = end_time2 - start_time; // искомое время в миллисекундах


						//mass_histo_x = histo_x("histo", mass_histo_x, N_histo, x_out_2, y_out_2, R, R_source, x_0_source);
						//mass_histo_r = histo_r("histo", mass_histo_r, (int)(N_histo / 2), x_out_2, y_out_2, R, R_source, x_0_source);


						//mass_histo_x_source = histo_x("source", mass_histo_x_source, N_histo_source, x_out_2, y_out_2, R, R_source, x_0_source);
						//mass_histo_r_source = histo_r("source", mass_histo_r_source, (int)(N_histo_source / 2), x_out_2, y_out_2, R, R_source, x_0_source);

						//printf("%+.3f %+.3f %.3Lf %.3Lf %.9Le %.3Lf %.2Lf\n", x_out_2, y_out_2, z_out_2, r_out_2, (long double)ii, procent, (long double)search_time / 1000.0);

						//printf("%s\n",(out2 ? "Да" : "Нет"));
						*/


						cyl(x_in_5, y_in_5, z_in_5, r_in_5, theta_in_5, phi_in_5, psi_in_5, x_out_5, y_out_5, z_out_5, r_out_5, theta_out_5, phi_out_5, psi_out_5, N1_5, N2_5, N3_5, N4_5, N5_5, L_1 + L_2 + L_3 + L_4, L_1 + L_2 + L_3 + L_4 + L_5, R1_5, R2_5, R3_5, R1_5, R2_6, R3_6, b5_left, b5_surface, b5_right, V_0, out5, n5, theta5_diffusion_left, theta5_diffusion_surface, theta5_diffusion_right, z0_mag5, L_mag5, r5_mag_max_initial, r5_mag_max_final, mu_core_particle, m_particle, B5_max_initial, on_off_mag_5, mu_electron_particle, I_particle, J_particle, m_F, m_J, B_critical, N_mag_partitions, z_zero_5,
							n_mag_5_in, n_mag_5_absorption, n_mag_5_out, mag_runge_5, B5_max_final, m_mag_5, Vector_temp_r_mag, Vector_temp_z_mag, Vector_temp_x_mag, Vector_temp_y_mag, min_r_out_mag_5, min_r_in_mag_5, particle_mode, iron_mag_5, trajectory_temp_cyl_x, trajectory_temp_cyl_y, trajectory_temp_cyl_z, trajectory_temp_cyl_r, v_r_in_5, v_r_out_5, v_x_in_5, v_x_out_5, v_y_in_5, v_y_out_5, out_mag_5, v_phi_in_5, v_phi_out_5, Vector_temp_color_mag, Vector_color_trajectory_temp_cyl, 5.0, Vector_temp_rr_mag, trajectory_temp_cyl_rr, N_CYL_partitions, i_Collision_5, out_trajectory_temp_cyl, Vector_temp_out_mag, b5_mag, b5_mag_left, b5_mag_right, L_cyl_1, L_cyl_2, L_cyl_3, L_cyl_4, L_cyl_5, L_cyl_6, L_cyl_7, Vector_temp_phi_mag, Vector_temp_psi_mag, Vector_temp_theta_mag, trajectory_temp_cyl_phi, trajectory_temp_cyl_psi, trajectory_temp_cyl_theta,
							Vector_temp_v_x_mag, Vector_temp_v_y_mag, Vector_temp_v_z_mag, Vector_temp_v_r_mag, Vector_temp_v_phi_mag, Vector_temp_v_perp_mag, Vector_temp_v_0_mag, trajectory_temp_cyl_v_x, trajectory_temp_cyl_v_y, trajectory_temp_cyl_v_z, trajectory_temp_cyl_v_r, trajectory_temp_cyl_v_phi, trajectory_temp_cyl_v_perp, trajectory_temp_cyl_v_0, n_cos_intensity, Vector_temp_force_mag, trajectory_temp_cyl_force, N_negative_cyl_5, N_zero_cyl_5, N_positive_cyl_5, N_negative_mag_5, N_zero_mag_5, N_positive_mag_5, mu_particle, mu_particle_force, Vector_temp_condition_color_mag, trajectory_temp_cyl_condition_color, flaq_on_off_B_mu, index_condition, Vector_temp_mu_mag, Vector_temp_B_mag, trajectory_temp_cyl_mu, trajectory_temp_cyl_B, Vector_r_magnetic_field_table, Vector_phi_magnetic_field_table, Vector_B_magnetic_field_table,
							Vector_delta_B_magnetic_field_table, on_off_table_magnetic_field, Vector_index_r_magnetic_field_table, index_phi_magnetic_field_table, m_mag_table, r_min_mag_table, r_max_mag_table, L_mag_5_B_off_after);

						/*




						//cout << min_r_out_mag_3 << endl;


						//	if (out3 == true) {
						//		out1 = true;
						//		out2 = true;




						//		}

						//	cout << x_out_3 << "  " << y_out_3 << "  " << z_out_3 << "    " << r_out_3 << endl;
						//	out1 = false;
						//	out2 = false;

						//	continue;


						//	if (out3 == true) {

						//	cout << "YES" << endl;
						//	}


						*/

					}









					if (out5 == false) {


						/*


						//printf("%s %s %s\n", (on_off_mag_1 ? "Да" : "Нет"), on_off_mag_2 ? "Да" : "Нет", on_off_mag_3 ? "Да" : "Нет");


						//printf("%s %s %s\n", (out_mag_1 ? "Да" : "Нет"), out_mag_2 ? "Да" : "Нет", out_mag_3 ? "Да" : "Нет");

						//		int index = 0;




						//if ((on_off_mag_1 == false) && (on_off_mag_2 == false)) {

						//	index = 0;
						//}

						//if ((on_off_mag_1 == true) &&( on_off_mag_2 == true)) {

						//	index = 2;
						//}

						//if ((on_off_mag_1 == true) &&( on_off_mag_2 == false)) {

						//	index = 1;
						//}

						//if ((on_off_mag_1 == false) && (on_off_mag_2 == true)) {

						//	if (out_mag_2 == true) {

						//	cout << "!!!" << endl;

						//		index = 1;
						//	}
						//	else if (out_mag_2 == false) {

						//	index = 0;
						//}


						//}


						//		index = 0;

						//printf("%s %s %s\n", (on_off_mag_1 ? "Да" : "Нет"), on_off_mag_2 ? "Да" : "Нет", on_off_mag_3 ? "Да" : "Нет");

						//index = index - 1;


						//	cout << i_Collision_1 <<" "<< i_Collision_2 << endl;


						//		if (out3 == true && out1==true) {
						//			index = 2;
						//		}

						//		if (out3 == true && out1 == false) {
						//			index = 1;
						//		}

						//		if (out3 == false && out1 == true) {
						//			index = 1;
						//		}


						//	trajectory_cyl_x.erase(trajectory_cyl_x.end() - (i_Collision_1 + i_Collision_2 + i_Collision_3 + index) * (N_CYL_partitions + 1), trajectory_cyl_x.end());
						//	trajectory_cyl_y.erase(trajectory_cyl_y.end() - (i_Collision_1 + i_Collision_2 + i_Collision_3 + index) * (N_CYL_partitions + 1), trajectory_cyl_y.end());

						//	trajectory_cyl_z.erase(trajectory_cyl_z.end() - (i_Collision_1 + i_Collision_2 + i_Collision_3 + index) * (N_CYL_partitions + 1), trajectory_cyl_z.end());
						//	trajectory_cyl_r.erase(trajectory_cyl_r.end() - (i_Collision_1 + i_Collision_2 + i_Collision_3 + index) * (N_CYL_partitions + 1), trajectory_cyl_r.end());
						//	trajectory_cyl_rr.erase(trajectory_cyl_rr.end() - (i_Collision_1 + i_Collision_2 + i_Collision_3 + index) * (N_CYL_partitions + 1), trajectory_cyl_rr.end());
						//	Vector_color_trajectory_cyl.erase(Vector_color_trajectory_cyl.end() - (i_Collision_1 + i_Collision_2 + i_Collision_3 + index) * (N_CYL_partitions + 1), Vector_color_trajectory_cyl.end());



						//	trajectory_cyl_x.shrink_to_fit();
						//	trajectory_cyl_y.shrink_to_fit();
						//	trajectory_cyl_z.shrink_to_fit();
						//	trajectory_cyl_r.shrink_to_fit();
						//	trajectory_cyl_rr.shrink_to_fit();

						//	Vector_color_trajectory_cyl.shrink_to_fit();





						//	trajectory_cyl_x.erase(trajectory_cyl_x.end() - 1 - 1 * (N_CYL_partitions - 0), trajectory_cyl_x.end());
						//	trajectory_cyl_y.erase(trajectory_cyl_y.end() - 1 - 1 * (N_CYL_partitions - 0), trajectory_cyl_y.end());

						//	trajectory_cyl_z.erase(trajectory_cyl_z.end() - 1 - 1 * (N_CYL_partitions - 0), trajectory_cyl_z.end());
						//	trajectory_cyl_r.erase(trajectory_cyl_r.end() - 1 - 1 * (N_CYL_partitions - 0), trajectory_cyl_r.end());
						//	trajectory_cyl_rr.erase(trajectory_cyl_rr.end() - 1 - 1 * (N_CYL_partitions - 0), trajectory_cyl_rr.end());




						//	Vector_color_trajectory_cyl.erase(Vector_color_trajectory_cyl.end() - 1 - 1 * (N_CYL_partitions - 0), Vector_color_trajectory_cyl.end());




						//	trajectory_cyl_x.shrink_to_fit();
						//	trajectory_cyl_y.shrink_to_fit();
						//	trajectory_cyl_z.shrink_to_fit();
						//	trajectory_cyl_r.shrink_to_fit();
						//	trajectory_cyl_rr.shrink_to_fit();

						//	Vector_color_trajectory_cyl.shrink_to_fit();

						//		if (on_off_mag_1 == true) {



						//	Vector_x_mag_1.erase(Vector_x_mag_1.end() - (N_mag_partitions + 1 + 0), Vector_x_mag_1.end());
						//	Vector_y_mag_1.erase(Vector_y_mag_1.end() - (N_mag_partitions + 1 + 0), Vector_y_mag_1.end());

						//	Vector_z_mag_1.erase(Vector_z_mag_1.end() - (N_mag_partitions + 1 + 0), Vector_z_mag_1.end());
						//	Vector_r_mag_1.erase(Vector_r_mag_1.end() - (N_mag_partitions + 1 + 0), Vector_r_mag_1.end());
						//	Vector_rr_mag_1.erase(Vector_rr_mag_1.end() - (N_mag_partitions + 1 + 0), Vector_rr_mag_1.end());

						//	Vector_color_mag_1.erase(Vector_color_mag_1.end() - (N_mag_partitions + 1 + 0), Vector_color_mag_1.end());

						//	Vector_x_mag_1.shrink_to_fit();
						//	Vector_y_mag_1.shrink_to_fit();
						//	Vector_z_mag_1.shrink_to_fit();
						//	Vector_r_mag_1.shrink_to_fit();
						//	Vector_rr_mag_1.shrink_to_fit();
						//	Vector_color_mag_1.shrink_to_fit();






						//	trajectory_cyl_x.erase(trajectory_cyl_x.end() - (N_mag_partitions + 1 + N_CYL_partitions - 0), trajectory_cyl_x.end());
						//	trajectory_cyl_y.erase(trajectory_cyl_y.end() - (N_mag_partitions + 1 + N_CYL_partitions - 0), trajectory_cyl_y.end());

						//	trajectory_cyl_z.erase(trajectory_cyl_z.end() - (N_mag_partitions + 1 + N_CYL_partitions - 0), trajectory_cyl_z.end());
						//	trajectory_cyl_r.erase(trajectory_cyl_r.end() - (N_mag_partitions + 1 + N_CYL_partitions - 0), trajectory_cyl_r.end());
						//	trajectory_cyl_rr.erase(trajectory_cyl_rr.end() - (N_mag_partitions + 1 + N_CYL_partitions - 0), trajectory_cyl_rr.end());

						//	Vector_color_trajectory_cyl.erase(Vector_color_trajectory_cyl.end() - (N_mag_partitions + 1 + N_CYL_partitions - 0), Vector_color_trajectory_cyl.end());

						//	trajectory_cyl_x.shrink_to_fit();
						//	trajectory_cyl_y.shrink_to_fit();
						//	trajectory_cyl_z.shrink_to_fit();
						//	trajectory_cyl_r.shrink_to_fit();
						//	trajectory_cyl_rr.shrink_to_fit();
						//	Vector_color_trajectory_cyl.shrink_to_fit();


						//		}
						//trajectory_cyl_x.erase(trajectory_cyl_x.end() - 2 , trajectory_cyl_x.end());
						//trajectory_cyl_y.erase(trajectory_cyl_y.end() - 2 , trajectory_cyl_y.end());

						//trajectory_cyl_z.erase(trajectory_cyl_z.end() - 2 , trajectory_cyl_z.end());
						//trajectory_cyl_r.erase(trajectory_cyl_r.end() - 2 , trajectory_cyl_r.end());





						//	trajectory_cyl_x.erase(trajectory_cyl_x.end() - 2 , trajectory_cyl_x.end());
						//	trajectory_cyl_y.erase(trajectory_cyl_y.end() - 2 , trajectory_cyl_y.end());

						//	trajectory_cyl_z.erase(trajectory_cyl_z.end() - 2 , trajectory_cyl_z.end());
						//	trajectory_cyl_r.erase(trajectory_cyl_r.end() - 2 , trajectory_cyl_r.end());


						*/

						out1 = false;
						out2 = false;
						out3 = false;
						out4 = false;
						out5 = false;
						out6 = false;
						out7 = false;

						out_mag_1 = false;
						out_mag_2 = false;
						out_mag_3 = false;
						out_mag_4 = false;
						out_mag_5 = false;
						out_mag_6 = false;
						out_mag_7 = false;


						break;
					}


					if ((out5 == true) && (fabs(z_out_5 - (L_1 + L_2 + L_3 + L_4)) <= epsilon)) {

						//	cout << "!!!" << endl;


						out1 = false;
						out2 = false;
						out3 = false;
						out4 = false;
						out5 = false;
						out6 = false;
						out7 = false;



						out_mag_1 = false;
						out_mag_2 = false;
						out_mag_3 = false;
						out_mag_4 = false;
						out_mag_5 = false;
						out_mag_6 = false;
						out_mag_7 = false;

						x_in_4 = x_out_5;
						y_in_4 = y_out_5;
						z_in_4 = z_out_5;
						r_in_4 = r_out_5;

						v_r_in_4 = v_r_out_5;
						v_phi_in_4 = v_phi_out_5;

						theta_in_4 = theta_out_5;
						phi_in_4 = phi_out_5;
						psi_in_4 = psi_out_5;

						cyl(x_in_4, y_in_4, z_in_4, r_in_4, theta_in_4, phi_in_4, psi_in_4, x_out_4, y_out_4, z_out_4, r_out_4, theta_out_4, phi_out_4, psi_out_4, N1_4, N2_4, N3_4, N4_4, N5_4, L_1 + L_2 + L_3, L_1 + L_2 + L_3 + L_4, R1_4, R2_4, R3_4, R1_4, R2_5, R3_5, b4_left, b4_surface, b4_right, V_0, out4, n4, theta4_diffusion_left, theta4_diffusion_surface, theta4_diffusion_right, z0_mag4, L_mag4, r4_mag_max_initial, r4_mag_max_final, mu_core_particle, m_particle, B4_max_initial, on_off_mag_4, mu_electron_particle, I_particle, J_particle, m_F, m_J, B_critical, N_mag_partitions, z_zero_4, n_mag_4_in, n_mag_4_absorption, n_mag_4_out,
							mag_runge_4, B4_max_final, m_mag_4, Vector_temp_r_mag, Vector_temp_z_mag, Vector_temp_x_mag, Vector_temp_y_mag, min_r_out_mag_4, min_r_in_mag_4, particle_mode, iron_mag_4, trajectory_temp_cyl_x, trajectory_temp_cyl_y, trajectory_temp_cyl_z, trajectory_temp_cyl_r, v_r_in_4, v_r_out_4, v_x_in_4, v_x_out_4, v_y_in_4, v_y_out_4, out_mag_4, v_phi_in_4, v_phi_out_4, Vector_temp_color_mag, Vector_color_trajectory_temp_cyl, 4.0, Vector_temp_rr_mag, trajectory_temp_cyl_rr, N_CYL_partitions, i_Collision_4, out_trajectory_temp_cyl, Vector_temp_out_mag, b4_mag, b4_mag_left, b4_mag_right, L_cyl_1, L_cyl_2, L_cyl_3, L_cyl_4, L_cyl_5, L_cyl_6, L_cyl_7, Vector_temp_phi_mag, Vector_temp_psi_mag, Vector_temp_theta_mag, trajectory_temp_cyl_phi, trajectory_temp_cyl_psi, trajectory_temp_cyl_theta,
							Vector_temp_v_x_mag, Vector_temp_v_y_mag, Vector_temp_v_z_mag, Vector_temp_v_r_mag, Vector_temp_v_phi_mag, Vector_temp_v_perp_mag, Vector_temp_v_0_mag, trajectory_temp_cyl_v_x, trajectory_temp_cyl_v_y, trajectory_temp_cyl_v_z, trajectory_temp_cyl_v_r, trajectory_temp_cyl_v_phi, trajectory_temp_cyl_v_perp, trajectory_temp_cyl_v_0, n_cos_intensity, Vector_temp_force_mag, trajectory_temp_cyl_force, N_negative_cyl_4, N_zero_cyl_4, N_positive_cyl_4, N_negative_mag_4, N_zero_mag_4, N_positive_mag_4, mu_particle, mu_particle_force, Vector_temp_condition_color_mag, trajectory_temp_cyl_condition_color, flaq_on_off_B_mu, index_condition, Vector_temp_mu_mag, Vector_temp_B_mag, trajectory_temp_cyl_mu, trajectory_temp_cyl_B, Vector_r_magnetic_field_table,
							Vector_phi_magnetic_field_table, Vector_B_magnetic_field_table, Vector_delta_B_magnetic_field_table, on_off_table_magnetic_field, Vector_index_r_magnetic_field_table, index_phi_magnetic_field_table, m_mag_table, r_min_mag_table, r_max_mag_table, L_mag_4_B_off_after);


						continue;






					}


					if ((out5 == true) && (fabs(z_out_5 - (L_1 + L_2 + L_3 + L_4 + L_5)) <= epsilon)) {

						//					CYL_3:



						out1 = false;
						out2 = false;
						out3 = false;
						out4 = false;
						out5 = false;
						out6 = false;
						out7 = false;


						out_mag_1 = false;
						out_mag_2 = false;
						out_mag_3 = false;
						out_mag_4 = false;
						out_mag_5 = false;
						out_mag_6 = false;
						out_mag_7 = false;


						x_in_6 = x_out_5;
						y_in_6 = y_out_5;
						z_in_6 = z_out_5;
						r_in_6 = r_out_5;

						v_r_in_6 = v_r_out_5;
						v_phi_in_6 = v_phi_out_5;

						theta_in_6 = theta_out_5;
						phi_in_6 = phi_out_5;
						psi_in_6 = psi_out_5;

						/*

						if (x_out_2 >= 0 && y_out_2 >= 0) {

						phi_in_3 = atan(fabs(y_out_2 / x_out_2));
						}



						if (x_out_2 < 0 && y_out_2 < 0) {

						phi_in_3 = M_PI + atan(fabs(y_out_2 / x_out_2));
						}

						if (x_out_2 > 0 && y_out_2 < 0) {

						phi_in_3 = 2.0*M_PI - atan(fabs(y_out_2 / x_out_2));
						}


						if (x_out_2 < 0 && y_out_2 > 0) {

						phi_in_3 = M_PI - atan(fabs(y_out_2 / x_out_2));
						}

						*/


						/*



						//cout << x_in_3 << "  " << y_in_3 << "  " << z_in_3 << "    " << r_in_3 << endl;


						//	long double procent = ((long double)ii / N)*100.0;
						//	unsigned int end_time2 = (unsigned int)clock(); // текущее время
						//	unsigned int search_time2 = end_time2 - start_time; // искомое время в миллисекундах


						//mass_histo_x = histo_x("histo", mass_histo_x, N_histo, x_out_2, y_out_2, R, R_source, x_0_source);
						//mass_histo_r = histo_r("histo", mass_histo_r, (int)(N_histo / 2), x_out_2, y_out_2, R, R_source, x_0_source);


						//mass_histo_x_source = histo_x("source", mass_histo_x_source, N_histo_source, x_out_2, y_out_2, R, R_source, x_0_source);
						//mass_histo_r_source = histo_r("source", mass_histo_r_source, (int)(N_histo_source / 2), x_out_2, y_out_2, R, R_source, x_0_source);

						//printf("%+.3f %+.3f %.3Lf %.3Lf %.9Le %.3Lf %.2Lf\n", x_out_2, y_out_2, z_out_2, r_out_2, (long double)ii, procent, (long double)search_time / 1000.0);

						//printf("%s\n",(out2 ? "Да" : "Нет"));
						*/


						cyl(x_in_6, y_in_6, z_in_6, r_in_6, theta_in_6, phi_in_6, psi_in_6, x_out_6, y_out_6, z_out_6, r_out_6, theta_out_6, phi_out_6, psi_out_6, N1_6, N2_6, N3_6, N4_6, N5_6, L_1 + L_2 + L_3 + L_4 + L_5, L_1 + L_2 + L_3 + L_4 + L_5 + L_6, R1_6, R2_6, R3_6, R1_6, R2_7, R3_7, b6_left, b6_surface, b6_right, V_0, out6, n6, theta6_diffusion_left, theta6_diffusion_surface, theta6_diffusion_right, z0_mag6, L_mag6, r6_mag_max_initial, r6_mag_max_final, mu_core_particle, m_particle, B6_max_initial, on_off_mag_6, mu_electron_particle, I_particle, J_particle, m_F, m_J, B_critical, N_mag_partitions, z_zero_6,
							n_mag_6_in, n_mag_6_absorption, n_mag_6_out, mag_runge_6, B6_max_final, m_mag_6, Vector_temp_r_mag, Vector_temp_z_mag, Vector_temp_x_mag, Vector_temp_y_mag, min_r_out_mag_6, min_r_in_mag_6, particle_mode, iron_mag_6, trajectory_temp_cyl_x, trajectory_temp_cyl_y, trajectory_temp_cyl_z, trajectory_temp_cyl_r, v_r_in_6, v_r_out_6, v_x_in_6, v_x_out_6, v_y_in_6, v_y_out_6, out_mag_6, v_phi_in_6, v_phi_out_6, Vector_temp_color_mag, Vector_color_trajectory_temp_cyl, 6.0, Vector_temp_rr_mag, trajectory_temp_cyl_rr, N_CYL_partitions, i_Collision_6, out_trajectory_temp_cyl, Vector_temp_out_mag, b6_mag, b6_mag_left, b6_mag_right, L_cyl_1, L_cyl_2, L_cyl_3, L_cyl_4, L_cyl_5, L_cyl_6, L_cyl_7, Vector_temp_phi_mag, Vector_temp_psi_mag, Vector_temp_theta_mag, trajectory_temp_cyl_phi, trajectory_temp_cyl_psi, trajectory_temp_cyl_theta,
							Vector_temp_v_x_mag, Vector_temp_v_y_mag, Vector_temp_v_z_mag, Vector_temp_v_r_mag, Vector_temp_v_phi_mag, Vector_temp_v_perp_mag, Vector_temp_v_0_mag, trajectory_temp_cyl_v_x, trajectory_temp_cyl_v_y, trajectory_temp_cyl_v_z, trajectory_temp_cyl_v_r, trajectory_temp_cyl_v_phi, trajectory_temp_cyl_v_perp, trajectory_temp_cyl_v_0, n_cos_intensity, Vector_temp_force_mag, trajectory_temp_cyl_force, N_negative_cyl_6, N_zero_cyl_6, N_positive_cyl_6, N_negative_mag_6, N_zero_mag_6, N_positive_mag_6, mu_particle, mu_particle_force, Vector_temp_condition_color_mag, trajectory_temp_cyl_condition_color, flaq_on_off_B_mu, index_condition, Vector_temp_mu_mag, Vector_temp_B_mag, trajectory_temp_cyl_mu, trajectory_temp_cyl_B, Vector_r_magnetic_field_table, Vector_phi_magnetic_field_table, Vector_B_magnetic_field_table,
							Vector_delta_B_magnetic_field_table, on_off_table_magnetic_field, Vector_index_r_magnetic_field_table, index_phi_magnetic_field_table, m_mag_table, r_min_mag_table, r_max_mag_table, L_mag_6_B_off_after);

						/*




						//cout << min_r_out_mag_3 << endl;


						//	if (out3 == true) {
						//		out1 = true;
						//		out2 = true;




						//		}

						//	cout << x_out_3 << "  " << y_out_3 << "  " << z_out_3 << "    " << r_out_3 << endl;
						//	out1 = false;
						//	out2 = false;

						//	continue;


						//	if (out3 == true) {

						//	cout << "YES" << endl;
						//	}


						*/

					}






					if (out6 == false) {


						/*


						//printf("%s %s %s\n", (on_off_mag_1 ? "Да" : "Нет"), on_off_mag_2 ? "Да" : "Нет", on_off_mag_3 ? "Да" : "Нет");


						//printf("%s %s %s\n", (out_mag_1 ? "Да" : "Нет"), out_mag_2 ? "Да" : "Нет", out_mag_3 ? "Да" : "Нет");

						//		int index = 0;




						//if ((on_off_mag_1 == false) && (on_off_mag_2 == false)) {

						//	index = 0;
						//}

						//if ((on_off_mag_1 == true) &&( on_off_mag_2 == true)) {

						//	index = 2;
						//}

						//if ((on_off_mag_1 == true) &&( on_off_mag_2 == false)) {

						//	index = 1;
						//}

						//if ((on_off_mag_1 == false) && (on_off_mag_2 == true)) {

						//	if (out_mag_2 == true) {

						//	cout << "!!!" << endl;

						//		index = 1;
						//	}
						//	else if (out_mag_2 == false) {

						//	index = 0;
						//}


						//}


						//		index = 0;

						//printf("%s %s %s\n", (on_off_mag_1 ? "Да" : "Нет"), on_off_mag_2 ? "Да" : "Нет", on_off_mag_3 ? "Да" : "Нет");

						//index = index - 1;


						//	cout << i_Collision_1 <<" "<< i_Collision_2 << endl;


						//		if (out3 == true && out1==true) {
						//			index = 2;
						//		}

						//		if (out3 == true && out1 == false) {
						//			index = 1;
						//		}

						//		if (out3 == false && out1 == true) {
						//			index = 1;
						//		}


						//	trajectory_cyl_x.erase(trajectory_cyl_x.end() - (i_Collision_1 + i_Collision_2 + i_Collision_3 + index) * (N_CYL_partitions + 1), trajectory_cyl_x.end());
						//	trajectory_cyl_y.erase(trajectory_cyl_y.end() - (i_Collision_1 + i_Collision_2 + i_Collision_3 + index) * (N_CYL_partitions + 1), trajectory_cyl_y.end());

						//	trajectory_cyl_z.erase(trajectory_cyl_z.end() - (i_Collision_1 + i_Collision_2 + i_Collision_3 + index) * (N_CYL_partitions + 1), trajectory_cyl_z.end());
						//	trajectory_cyl_r.erase(trajectory_cyl_r.end() - (i_Collision_1 + i_Collision_2 + i_Collision_3 + index) * (N_CYL_partitions + 1), trajectory_cyl_r.end());
						//	trajectory_cyl_rr.erase(trajectory_cyl_rr.end() - (i_Collision_1 + i_Collision_2 + i_Collision_3 + index) * (N_CYL_partitions + 1), trajectory_cyl_rr.end());
						//	Vector_color_trajectory_cyl.erase(Vector_color_trajectory_cyl.end() - (i_Collision_1 + i_Collision_2 + i_Collision_3 + index) * (N_CYL_partitions + 1), Vector_color_trajectory_cyl.end());



						//	trajectory_cyl_x.shrink_to_fit();
						//	trajectory_cyl_y.shrink_to_fit();
						//	trajectory_cyl_z.shrink_to_fit();
						//	trajectory_cyl_r.shrink_to_fit();
						//	trajectory_cyl_rr.shrink_to_fit();

						//	Vector_color_trajectory_cyl.shrink_to_fit();





						//	trajectory_cyl_x.erase(trajectory_cyl_x.end() - 1 - 1 * (N_CYL_partitions - 0), trajectory_cyl_x.end());
						//	trajectory_cyl_y.erase(trajectory_cyl_y.end() - 1 - 1 * (N_CYL_partitions - 0), trajectory_cyl_y.end());

						//	trajectory_cyl_z.erase(trajectory_cyl_z.end() - 1 - 1 * (N_CYL_partitions - 0), trajectory_cyl_z.end());
						//	trajectory_cyl_r.erase(trajectory_cyl_r.end() - 1 - 1 * (N_CYL_partitions - 0), trajectory_cyl_r.end());
						//	trajectory_cyl_rr.erase(trajectory_cyl_rr.end() - 1 - 1 * (N_CYL_partitions - 0), trajectory_cyl_rr.end());




						//	Vector_color_trajectory_cyl.erase(Vector_color_trajectory_cyl.end() - 1 - 1 * (N_CYL_partitions - 0), Vector_color_trajectory_cyl.end());




						//	trajectory_cyl_x.shrink_to_fit();
						//	trajectory_cyl_y.shrink_to_fit();
						//	trajectory_cyl_z.shrink_to_fit();
						//	trajectory_cyl_r.shrink_to_fit();
						//	trajectory_cyl_rr.shrink_to_fit();

						//	Vector_color_trajectory_cyl.shrink_to_fit();

						//		if (on_off_mag_1 == true) {



						//	Vector_x_mag_1.erase(Vector_x_mag_1.end() - (N_mag_partitions + 1 + 0), Vector_x_mag_1.end());
						//	Vector_y_mag_1.erase(Vector_y_mag_1.end() - (N_mag_partitions + 1 + 0), Vector_y_mag_1.end());

						//	Vector_z_mag_1.erase(Vector_z_mag_1.end() - (N_mag_partitions + 1 + 0), Vector_z_mag_1.end());
						//	Vector_r_mag_1.erase(Vector_r_mag_1.end() - (N_mag_partitions + 1 + 0), Vector_r_mag_1.end());
						//	Vector_rr_mag_1.erase(Vector_rr_mag_1.end() - (N_mag_partitions + 1 + 0), Vector_rr_mag_1.end());

						//	Vector_color_mag_1.erase(Vector_color_mag_1.end() - (N_mag_partitions + 1 + 0), Vector_color_mag_1.end());

						//	Vector_x_mag_1.shrink_to_fit();
						//	Vector_y_mag_1.shrink_to_fit();
						//	Vector_z_mag_1.shrink_to_fit();
						//	Vector_r_mag_1.shrink_to_fit();
						//	Vector_rr_mag_1.shrink_to_fit();
						//	Vector_color_mag_1.shrink_to_fit();






						//	trajectory_cyl_x.erase(trajectory_cyl_x.end() - (N_mag_partitions + 1 + N_CYL_partitions - 0), trajectory_cyl_x.end());
						//	trajectory_cyl_y.erase(trajectory_cyl_y.end() - (N_mag_partitions + 1 + N_CYL_partitions - 0), trajectory_cyl_y.end());

						//	trajectory_cyl_z.erase(trajectory_cyl_z.end() - (N_mag_partitions + 1 + N_CYL_partitions - 0), trajectory_cyl_z.end());
						//	trajectory_cyl_r.erase(trajectory_cyl_r.end() - (N_mag_partitions + 1 + N_CYL_partitions - 0), trajectory_cyl_r.end());
						//	trajectory_cyl_rr.erase(trajectory_cyl_rr.end() - (N_mag_partitions + 1 + N_CYL_partitions - 0), trajectory_cyl_rr.end());

						//	Vector_color_trajectory_cyl.erase(Vector_color_trajectory_cyl.end() - (N_mag_partitions + 1 + N_CYL_partitions - 0), Vector_color_trajectory_cyl.end());

						//	trajectory_cyl_x.shrink_to_fit();
						//	trajectory_cyl_y.shrink_to_fit();
						//	trajectory_cyl_z.shrink_to_fit();
						//	trajectory_cyl_r.shrink_to_fit();
						//	trajectory_cyl_rr.shrink_to_fit();
						//	Vector_color_trajectory_cyl.shrink_to_fit();


						//		}
						//trajectory_cyl_x.erase(trajectory_cyl_x.end() - 2 , trajectory_cyl_x.end());
						//trajectory_cyl_y.erase(trajectory_cyl_y.end() - 2 , trajectory_cyl_y.end());

						//trajectory_cyl_z.erase(trajectory_cyl_z.end() - 2 , trajectory_cyl_z.end());
						//trajectory_cyl_r.erase(trajectory_cyl_r.end() - 2 , trajectory_cyl_r.end());





						//	trajectory_cyl_x.erase(trajectory_cyl_x.end() - 2 , trajectory_cyl_x.end());
						//	trajectory_cyl_y.erase(trajectory_cyl_y.end() - 2 , trajectory_cyl_y.end());

						//	trajectory_cyl_z.erase(trajectory_cyl_z.end() - 2 , trajectory_cyl_z.end());
						//	trajectory_cyl_r.erase(trajectory_cyl_r.end() - 2 , trajectory_cyl_r.end());


						*/

						out1 = false;
						out2 = false;
						out3 = false;
						out4 = false;
						out5 = false;
						out6 = false;
						out7 = false;

						out_mag_1 = false;
						out_mag_2 = false;
						out_mag_3 = false;
						out_mag_4 = false;
						out_mag_5 = false;
						out_mag_6 = false;
						out_mag_7 = false;


						break;
					}


					if ((out6 == true) && (fabs(z_out_6 - (L_1 + L_2 + L_3 + L_4 + L_5)) <= epsilon)) {

						//	cout << "!!!" << endl;


						out1 = false;
						out2 = false;
						out3 = false;
						out4 = false;
						out5 = false;
						out6 = false;
						out7 = false;



						out_mag_1 = false;
						out_mag_2 = false;
						out_mag_3 = false;
						out_mag_4 = false;
						out_mag_5 = false;
						out_mag_6 = false;
						out_mag_7 = false;

						x_in_5 = x_out_6;
						y_in_5 = y_out_6;
						z_in_5 = z_out_6;
						r_in_5 = r_out_6;

						v_r_in_5 = v_r_out_6;
						v_phi_in_5 = v_phi_out_6;

						theta_in_5 = theta_out_6;
						phi_in_5 = phi_out_6;
						psi_in_5 = psi_out_6;

						cyl(x_in_5, y_in_5, z_in_5, r_in_5, theta_in_5, phi_in_5, psi_in_5, x_out_5, y_out_5, z_out_5, r_out_5, theta_out_5, phi_out_5, psi_out_5, N1_5, N2_5, N3_5, N4_5, N5_5, L_1 + L_2 + L_3+ L_4, L_1 + L_2 + L_3 + L_4 + L_5, R1_5, R2_5, R3_5, R1_5, R2_6, R3_6, b5_left, b5_surface, b5_right, V_0, out5, n5, theta5_diffusion_left, theta5_diffusion_surface, theta5_diffusion_right, z0_mag5, L_mag5, r5_mag_max_initial, r5_mag_max_final, mu_core_particle, m_particle, B5_max_initial, on_off_mag_5, mu_electron_particle, I_particle, J_particle, m_F, m_J, B_critical, N_mag_partitions, z_zero_5, n_mag_5_in, n_mag_5_absorption, n_mag_5_out,
							mag_runge_5, B5_max_final, m_mag_5, Vector_temp_r_mag, Vector_temp_z_mag, Vector_temp_x_mag, Vector_temp_y_mag, min_r_out_mag_5, min_r_in_mag_5, particle_mode, iron_mag_5, trajectory_temp_cyl_x, trajectory_temp_cyl_y, trajectory_temp_cyl_z, trajectory_temp_cyl_r, v_r_in_5, v_r_out_5, v_x_in_5, v_x_out_5, v_y_in_5, v_y_out_5, out_mag_5, v_phi_in_5, v_phi_out_5, Vector_temp_color_mag, Vector_color_trajectory_temp_cyl, 5.0, Vector_temp_rr_mag, trajectory_temp_cyl_rr, N_CYL_partitions, i_Collision_5, out_trajectory_temp_cyl, Vector_temp_out_mag, b5_mag, b5_mag_left, b5_mag_right, L_cyl_1, L_cyl_2, L_cyl_3, L_cyl_4, L_cyl_5, L_cyl_6, L_cyl_7, Vector_temp_phi_mag, Vector_temp_psi_mag, Vector_temp_theta_mag, trajectory_temp_cyl_phi, trajectory_temp_cyl_psi, trajectory_temp_cyl_theta,
							Vector_temp_v_x_mag, Vector_temp_v_y_mag, Vector_temp_v_z_mag, Vector_temp_v_r_mag, Vector_temp_v_phi_mag, Vector_temp_v_perp_mag, Vector_temp_v_0_mag, trajectory_temp_cyl_v_x, trajectory_temp_cyl_v_y, trajectory_temp_cyl_v_z, trajectory_temp_cyl_v_r, trajectory_temp_cyl_v_phi, trajectory_temp_cyl_v_perp, trajectory_temp_cyl_v_0, n_cos_intensity, Vector_temp_force_mag, trajectory_temp_cyl_force, N_negative_cyl_5, N_zero_cyl_5, N_positive_cyl_5, N_negative_mag_5, N_zero_mag_5, N_positive_mag_5, mu_particle, mu_particle_force, Vector_temp_condition_color_mag, trajectory_temp_cyl_condition_color, flaq_on_off_B_mu, index_condition, Vector_temp_mu_mag, Vector_temp_B_mag, trajectory_temp_cyl_mu, trajectory_temp_cyl_B, Vector_r_magnetic_field_table,
							Vector_phi_magnetic_field_table, Vector_B_magnetic_field_table, Vector_delta_B_magnetic_field_table, on_off_table_magnetic_field, Vector_index_r_magnetic_field_table, index_phi_magnetic_field_table, m_mag_table, r_min_mag_table, r_max_mag_table, L_mag_5_B_off_after);


						continue;






					}


					if ((out6 == true) && (fabs(z_out_6 - (L_1 + L_2 + L_3 + L_4 + L_5 + L_6)) <= epsilon)) {

						//					CYL_3:



						out1 = false;
						out2 = false;
						out3 = false;
						out4 = false;
						out5 = false;
						out6 = false;
						out7 = false;


						out_mag_1 = false;
						out_mag_2 = false;
						out_mag_3 = false;
						out_mag_4 = false;
						out_mag_5 = false;
						out_mag_6 = false;
						out_mag_7 = false;


						x_in_7 = x_out_6;
						y_in_7 = y_out_6;
						z_in_7 = z_out_6;
						r_in_7 = r_out_6;

						v_r_in_7 = v_r_out_6;
						v_phi_in_7 = v_phi_out_6;

						theta_in_7 = theta_out_6;
						phi_in_7 = phi_out_6;
						psi_in_7 = psi_out_6;

						/*

						if (x_out_2 >= 0 && y_out_2 >= 0) {

						phi_in_3 = atan(fabs(y_out_2 / x_out_2));
						}



						if (x_out_2 < 0 && y_out_2 < 0) {

						phi_in_3 = M_PI + atan(fabs(y_out_2 / x_out_2));
						}

						if (x_out_2 > 0 && y_out_2 < 0) {

						phi_in_3 = 2.0*M_PI - atan(fabs(y_out_2 / x_out_2));
						}


						if (x_out_2 < 0 && y_out_2 > 0) {

						phi_in_3 = M_PI - atan(fabs(y_out_2 / x_out_2));
						}

						*/


						/*



						//cout << x_in_3 << "  " << y_in_3 << "  " << z_in_3 << "    " << r_in_3 << endl;


						//	long double procent = ((long double)ii / N)*100.0;
						//	unsigned int end_time2 = (unsigned int)clock(); // текущее время
						//	unsigned int search_time2 = end_time2 - start_time; // искомое время в миллисекундах


						//mass_histo_x = histo_x("histo", mass_histo_x, N_histo, x_out_2, y_out_2, R, R_source, x_0_source);
						//mass_histo_r = histo_r("histo", mass_histo_r, (int)(N_histo / 2), x_out_2, y_out_2, R, R_source, x_0_source);


						//mass_histo_x_source = histo_x("source", mass_histo_x_source, N_histo_source, x_out_2, y_out_2, R, R_source, x_0_source);
						//mass_histo_r_source = histo_r("source", mass_histo_r_source, (int)(N_histo_source / 2), x_out_2, y_out_2, R, R_source, x_0_source);

						//printf("%+.3f %+.3f %.3Lf %.3Lf %.9Le %.3Lf %.2Lf\n", x_out_2, y_out_2, z_out_2, r_out_2, (long double)ii, procent, (long double)search_time / 1000.0);

						//printf("%s\n",(out2 ? "Да" : "Нет"));
						*/


						cyl(x_in_7, y_in_7, z_in_7, r_in_7, theta_in_7, phi_in_7, psi_in_7, x_out_7, y_out_7, z_out_7, r_out_7, theta_out_7, phi_out_7, psi_out_7, N1_7, N2_7, N3_7, N4_7, N5_7, L_1 + L_2 + L_3 + L_4 + L_5 + L_6, L_1 + L_2 + L_3 + L_4 + L_5 + L_6 + L_7, R1_7, R2_7, R3_7, R1_7, R2_8, R3_8, b7_left, b7_surface, b7_right, V_0, out7, n7, theta7_diffusion_left, theta7_diffusion_surface, theta7_diffusion_right, z0_mag7, L_mag6, r7_mag_max_initial, r7_mag_max_final, mu_core_particle, m_particle, B7_max_initial, on_off_mag_7, mu_electron_particle, I_particle, J_particle, m_F, m_J, B_critical, N_mag_partitions, z_zero_7,
							n_mag_7_in, n_mag_7_absorption, n_mag_7_out, mag_runge_7, B7_max_final, m_mag_7, Vector_temp_r_mag, Vector_temp_z_mag, Vector_temp_x_mag, Vector_temp_y_mag, min_r_out_mag_7, min_r_in_mag_7, particle_mode, iron_mag_7, trajectory_temp_cyl_x, trajectory_temp_cyl_y, trajectory_temp_cyl_z, trajectory_temp_cyl_r, v_r_in_7, v_r_out_7, v_x_in_7, v_x_out_7, v_y_in_7, v_y_out_7, out_mag_7, v_phi_in_7, v_phi_out_7, Vector_temp_color_mag, Vector_color_trajectory_temp_cyl, 7.0, Vector_temp_rr_mag, trajectory_temp_cyl_rr, N_CYL_partitions, i_Collision_7, out_trajectory_temp_cyl, Vector_temp_out_mag, b7_mag, b7_mag_left, b7_mag_right, L_cyl_1, L_cyl_2, L_cyl_3, L_cyl_4, L_cyl_5, L_cyl_6, L_cyl_7, Vector_temp_phi_mag, Vector_temp_psi_mag, Vector_temp_theta_mag, trajectory_temp_cyl_phi, trajectory_temp_cyl_psi, trajectory_temp_cyl_theta,
							Vector_temp_v_x_mag, Vector_temp_v_y_mag, Vector_temp_v_z_mag, Vector_temp_v_r_mag, Vector_temp_v_phi_mag, Vector_temp_v_perp_mag, Vector_temp_v_0_mag, trajectory_temp_cyl_v_x, trajectory_temp_cyl_v_y, trajectory_temp_cyl_v_z, trajectory_temp_cyl_v_r, trajectory_temp_cyl_v_phi, trajectory_temp_cyl_v_perp, trajectory_temp_cyl_v_0, n_cos_intensity, Vector_temp_force_mag, trajectory_temp_cyl_force, N_negative_cyl_7, N_zero_cyl_7, N_positive_cyl_7, N_negative_mag_7, N_zero_mag_7, N_positive_mag_7, mu_particle, mu_particle_force, Vector_temp_condition_color_mag, trajectory_temp_cyl_condition_color, flaq_on_off_B_mu, index_condition, Vector_temp_mu_mag, Vector_temp_B_mag, trajectory_temp_cyl_mu, trajectory_temp_cyl_B, Vector_r_magnetic_field_table, Vector_phi_magnetic_field_table, Vector_B_magnetic_field_table,
							Vector_delta_B_magnetic_field_table, on_off_table_magnetic_field, Vector_index_r_magnetic_field_table, index_phi_magnetic_field_table, m_mag_table, r_min_mag_table, r_max_mag_table, L_mag_7_B_off_after);

						/*




						//cout << min_r_out_mag_3 << endl;


						//	if (out3 == true) {
						//		out1 = true;
						//		out2 = true;




						//		}

						//	cout << x_out_3 << "  " << y_out_3 << "  " << z_out_3 << "    " << r_out_3 << endl;
						//	out1 = false;
						//	out2 = false;

						//	continue;


						//	if (out3 == true) {

						//	cout << "YES" << endl;
						//	}


						*/

					}












					//printf("%s %s %s\n", (out1 ? "Да" : "Нет"), out2 ? "Да" : "Нет", out3? "Да" : "Нет");

					if (out7 == false) {

						//printf("%s %s %s\n", (out_mag_1 ? "Да" : "Нет"), out_mag_2 ? "Да" : "Нет", out_mag_3 ? "Да" : "Нет");

						//cout << "!!!" << endl;

						// printf("%s %s %s\n", (on_off_mag_1 ? "Да" : "Нет"), on_off_mag_2 ? "Да" : "Нет", on_off_mag_3 ? "Да" : "Нет");

						//	printf("%s\n", out2 ? "Да" : "Нет");

						//	int index = 0;

						//if ((on_off_mag_1 == false) &&( on_off_mag_2 == false) &&( on_off_mag_3 == false)) {

						//	index = 0;
						//}

						//if ((on_off_mag_1 == true )&&( on_off_mag_2 == true) && (on_off_mag_3 == true)) {

						//	if (out_mag_3 == false) {
						//		index = 2;
						//	}
						//	else if (out_mag_3 == true) {

						//		index = 2;
						//	}


						//}

						//if ((on_off_mag_1 == true) &&( on_off_mag_2 == true )&& (on_off_mag_3 == false)) {

						//cout << "!!!" << endl;

						//	index = 2;
						//}

						//if ((on_off_mag_1 == true )&& (on_off_mag_2 == false) && (on_off_mag_3 == false)) {

						//	index = 1;
						//}

						//if ((on_off_mag_1 == false) && (on_off_mag_2 == true) && (on_off_mag_3 == true)) {

						//	if (out_mag_3 == false) {
						//		index = 1;
						//	}
						//	else if (out_mag_3 == true) {

						//		index = 1;
						//	}



						//	}

						//if ((on_off_mag_1 == false) &&( on_off_mag_2 == true) && (on_off_mag_3 == false) ){

						//	index = 1;
						//}

						//if ((on_off_mag_1 == false) && (on_off_mag_2 == false) && (on_off_mag_3 == true)) {

						//cout << "!!!" << endl;

						//	if (out_mag_3 == false) {
						//		index = 0;
						//	}
						//	else if (out_mag_3 == true) {

						//		index = 0;
						//	}


						//	}


						//	if ((on_off_mag_1 == true) &&( on_off_mag_2 == false) && (on_off_mag_3 == true)) {

						//	if (out_mag_3 == false) {
						//		index = 1;
						//	}
						//	else if (out_mag_3 == true) {

						//		index = 1;
						//	}


						//	}

						//printf("%s %s %s\n", (on_off_mag_1 ? "Да" : "Нет"), on_off_mag_2 ? "Да" : "Нет", on_off_mag_3 ? "Да" : "Нет");

						//	trajectory_cyl_x.erase(trajectory_cyl_x.end() - (i_Collision_1 + i_Collision_2 - 2) * (2 * N_CYL_partitions), trajectory_cyl_x.end());
						//	trajectory_cyl_y.erase(trajectory_cyl_y.end() - (i_Collision_1 + i_Collision_2 - 2) * (2*N_CYL_partitions), trajectory_cyl_y.end());

						//	trajectory_cyl_z.erase(trajectory_cyl_z.end() - (i_Collision_1 + i_Collision_2 - 2) * (2*N_CYL_partitions), trajectory_cyl_z.end());
						//	trajectory_cyl_r.erase(trajectory_cyl_r.end() - (i_Collision_1 + i_Collision_2 - 2) * (2*N_CYL_partitions), trajectory_cyl_r.end());
						//	trajectory_cyl_rr.erase(trajectory_cyl_rr.end() - (i_Collision_1 + i_Collision_2 - 2) * (2*N_CYL_partitions), trajectory_cyl_rr.end());




						//	Vector_color_trajectory_cyl.erase(Vector_color_trajectory_cyl.end() - (i_Collision_1 + i_Collision_2 - 2) * (2*N_CYL_partitions), Vector_color_trajectory_cyl.end());



						//trajectory_cyl_x.shrink_to_fit();
						//	trajectory_cyl_y.shrink_to_fit();
						//trajectory_cyl_z.shrink_to_fit();
						//	trajectory_cyl_r.shrink_to_fit();
						//	trajectory_cyl_rr.shrink_to_fit();
						//	Vector_color_trajectory_cyl.shrink_to_fit();




						//	trajectory_cyl_x.erase(trajectory_cyl_x.end() - 2 - 2 * (N_CYL_partitions - 0), trajectory_cyl_x.end());
						//	trajectory_cyl_y.erase(trajectory_cyl_y.end() - 2 - 2 * (N_CYL_partitions - 0), trajectory_cyl_y.end());

						//	trajectory_cyl_z.erase(trajectory_cyl_z.end() - 2 - 2 * (N_CYL_partitions - 0), trajectory_cyl_z.end());
						//	trajectory_cyl_r.erase(trajectory_cyl_r.end() - 2 - 2 * (N_CYL_partitions - 0), trajectory_cyl_r.end());
						//	trajectory_cyl_rr.erase(trajectory_cyl_rr.end() - 2 - 2 * (N_CYL_partitions - 0), trajectory_cyl_rr.end());

						//	Vector_color_trajectory_cyl.erase(Vector_color_trajectory_cyl.end() - 2 - 2 * (N_CYL_partitions - 0), Vector_color_trajectory_cyl.end());

						//	trajectory_cyl_x.shrink_to_fit();
						//	trajectory_cyl_y.shrink_to_fit();
						//	trajectory_cyl_z.shrink_to_fit();
						//	trajectory_cyl_r.shrink_to_fit();
						//	trajectory_cyl_rr.shrink_to_fit();
						//	Vector_color_trajectory_cyl.shrink_to_fit();




						//		if ((on_off_mag_1 == true) && (on_off_mag_2 == false)) {


						//	Vector_x_mag_1.erase(Vector_x_mag_1.end() - (N_mag_partitions + 1 + 0), Vector_x_mag_1.end());
						//	Vector_y_mag_1.erase(Vector_y_mag_1.end() - (N_mag_partitions + 1 + 0), Vector_y_mag_1.end());

						//	Vector_z_mag_1.erase(Vector_z_mag_1.end() - (N_mag_partitions + 1 + 0), Vector_z_mag_1.end());
						//	Vector_r_mag_1.erase(Vector_r_mag_1.end() - (N_mag_partitions + 1 + 0), Vector_r_mag_1.end());
						//	Vector_rr_mag_1.erase(Vector_rr_mag_1.end() - (N_mag_partitions + 1 + 0), Vector_rr_mag_1.end());

						//	Vector_color_mag_1.erase(Vector_color_mag_1.end() - (N_mag_partitions + 1 + 0), Vector_color_mag_1.end());

						//	Vector_x_mag_1.shrink_to_fit();
						//	Vector_y_mag_1.shrink_to_fit();
						//	Vector_z_mag_1.shrink_to_fit();
						//	Vector_r_mag_1.shrink_to_fit();
						//	Vector_rr_mag_1.shrink_to_fit();
						//	Vector_color_mag_1.shrink_to_fit();














						//	trajectory_cyl_x.erase(trajectory_cyl_x.end() - (N_mag_partitions + 1 + N_CYL_partitions - 0), trajectory_cyl_x.end());
						//	trajectory_cyl_y.erase(trajectory_cyl_y.end() - (N_mag_partitions + 1 + N_CYL_partitions - 0), trajectory_cyl_y.end());

						//	trajectory_cyl_z.erase(trajectory_cyl_z.end() - (N_mag_partitions + 1 + N_CYL_partitions - 0), trajectory_cyl_z.end());
						//	trajectory_cyl_r.erase(trajectory_cyl_r.end() - (N_mag_partitions + 1 + N_CYL_partitions - 0), trajectory_cyl_r.end());
						//	trajectory_cyl_rr.erase(trajectory_cyl_rr.end() - (N_mag_partitions + 1 + N_CYL_partitions - 0), trajectory_cyl_rr.end());
						//	Vector_color_trajectory_cyl.erase(Vector_color_trajectory_cyl.end() - (N_mag_partitions + 1 + N_CYL_partitions - 0), Vector_color_trajectory_cyl.end());

						//	trajectory_cyl_x.shrink_to_fit();
						//	trajectory_cyl_y.shrink_to_fit();
						//	trajectory_cyl_z.shrink_to_fit();
						//	trajectory_cyl_r.shrink_to_fit();
						//	trajectory_cyl_rr.shrink_to_fit();
						//	Vector_color_trajectory_cyl.shrink_to_fit();


						//		}



						//		if ((on_off_mag_1 == false) && (on_off_mag_2 == true)) {





						//	Vector_x_mag_2.erase(Vector_x_mag_2.end() - (N_mag_partitions + 1 + 0), Vector_x_mag_2.end());
						//	Vector_y_mag_2.erase(Vector_y_mag_2.end() - (N_mag_partitions + 1 + 0), Vector_y_mag_2.end());

						//	Vector_z_mag_2.erase(Vector_z_mag_2.end() - (N_mag_partitions + 1 + 0), Vector_z_mag_2.end());
						//	Vector_r_mag_2.erase(Vector_r_mag_2.end() - (N_mag_partitions + 1 + 0), Vector_r_mag_2.end());
						//	Vector_rr_mag_2.erase(Vector_rr_mag_2.end() - (N_mag_partitions + 1 + 0), Vector_rr_mag_2.end());

						//	Vector_color_mag_2.erase(Vector_color_mag_2.end() - (N_mag_partitions + 1 + 0), Vector_color_mag_2.end());

						//	Vector_x_mag_2.shrink_to_fit();
						//	Vector_y_mag_2.shrink_to_fit();
						//	Vector_z_mag_2.shrink_to_fit();
						//	Vector_r_mag_2.shrink_to_fit();
						//	Vector_rr_mag_2.shrink_to_fit();
						//	Vector_color_mag_2.shrink_to_fit();








						//	trajectory_cyl_x.erase(trajectory_cyl_x.end() - (N_mag_partitions + 1 + N_CYL_partitions - 0), trajectory_cyl_x.end());
						//	trajectory_cyl_y.erase(trajectory_cyl_y.end() - (N_mag_partitions + 1 + N_CYL_partitions - 0), trajectory_cyl_y.end());

						//	trajectory_cyl_z.erase(trajectory_cyl_z.end() - (N_mag_partitions + 1 + N_CYL_partitions - 0), trajectory_cyl_z.end());
						//	trajectory_cyl_r.erase(trajectory_cyl_r.end() - (N_mag_partitions + 1 + N_CYL_partitions - 0), trajectory_cyl_r.end());
						//	trajectory_cyl_rr.erase(trajectory_cyl_rr.end() - (N_mag_partitions + 1 + N_CYL_partitions - 0), trajectory_cyl_rr.end());

						//	Vector_color_trajectory_cyl.erase(Vector_color_trajectory_cyl.end() - (N_mag_partitions + 1 + N_CYL_partitions - 0), Vector_color_trajectory_cyl.end());

						//	trajectory_cyl_x.shrink_to_fit();
						//	trajectory_cyl_y.shrink_to_fit();
						//	trajectory_cyl_z.shrink_to_fit();
						//	trajectory_cyl_r.shrink_to_fit();
						//	trajectory_cyl_rr.shrink_to_fit();
						//	Vector_color_trajectory_cyl.shrink_to_fit();

						//	}


						//	if ((on_off_mag_1 == true) && (on_off_mag_2 == true)) {




						//	Vector_x_mag_1.erase(Vector_x_mag_1.end() - (N_mag_partitions + 1 + 0), Vector_x_mag_1.end());
						//	Vector_y_mag_1.erase(Vector_y_mag_1.end() - (N_mag_partitions + 1 + 0), Vector_y_mag_1.end());

						//	Vector_z_mag_1.erase(Vector_z_mag_1.end() - (N_mag_partitions + 1 + 0), Vector_z_mag_1.end());
						//	Vector_r_mag_1.erase(Vector_r_mag_1.end() - (N_mag_partitions + 1 + 0), Vector_r_mag_1.end());
						//	Vector_rr_mag_1.erase(Vector_rr_mag_1.end() - (N_mag_partitions + 1 + 0), Vector_rr_mag_1.end());

						//	Vector_color_mag_1.erase(Vector_color_mag_1.end() - (N_mag_partitions + 1 + 0), Vector_color_mag_1.end());

						//	Vector_x_mag_1.shrink_to_fit();
						//	Vector_y_mag_1.shrink_to_fit();
						//	Vector_z_mag_1.shrink_to_fit();
						//	Vector_r_mag_1.shrink_to_fit();
						//	Vector_rr_mag_1.shrink_to_fit();
						//	Vector_color_mag_1.shrink_to_fit();






						//	Vector_x_mag_2.erase(Vector_x_mag_2.end() - (N_mag_partitions + 1 + 0), Vector_x_mag_2.end());
						//	Vector_y_mag_2.erase(Vector_y_mag_2.end() - (N_mag_partitions + 1 + 0), Vector_y_mag_2.end());

						//	Vector_z_mag_2.erase(Vector_z_mag_2.end() - (N_mag_partitions + 1 + 0), Vector_z_mag_2.end());
						//	Vector_r_mag_2.erase(Vector_r_mag_2.end() - (N_mag_partitions + 1 + 0), Vector_r_mag_2.end());
						//	Vector_rr_mag_2.erase(Vector_rr_mag_2.end() - (N_mag_partitions + 1 + 0), Vector_rr_mag_2.end());

						//	Vector_color_mag_2.erase(Vector_color_mag_2.end() - (N_mag_partitions + 1 + 0), Vector_color_mag_2.end());

						//	Vector_x_mag_2.shrink_to_fit();
						//	Vector_y_mag_2.shrink_to_fit();
						//	Vector_z_mag_2.shrink_to_fit();
						//	Vector_r_mag_2.shrink_to_fit();
						//	Vector_rr_mag_2.shrink_to_fit();
						//	Vector_color_mag_2.shrink_to_fit();






						//	trajectory_cyl_x.erase(trajectory_cyl_x.end() - 2 * (N_mag_partitions + 1 + N_CYL_partitions - 0), trajectory_cyl_x.end());
						//	trajectory_cyl_y.erase(trajectory_cyl_y.end() - 2 * (N_mag_partitions + 1 + N_CYL_partitions - 0), trajectory_cyl_y.end());

						//	trajectory_cyl_z.erase(trajectory_cyl_z.end() - 2 * (N_mag_partitions + 1 + N_CYL_partitions - 0), trajectory_cyl_z.end());
						//	trajectory_cyl_r.erase(trajectory_cyl_r.end() - 2 * (N_mag_partitions + 1 + N_CYL_partitions - 0), trajectory_cyl_r.end());
						//	trajectory_cyl_rr.erase(trajectory_cyl_rr.end() - 2 * (N_mag_partitions + 1 + N_CYL_partitions - 0), trajectory_cyl_rr.end());
						//	Vector_color_trajectory_cyl.erase(Vector_color_trajectory_cyl.end() - 2 * (N_mag_partitions + 1 + N_CYL_partitions - 0), Vector_color_trajectory_cyl.end());

						//	trajectory_cyl_x.shrink_to_fit();
						//	trajectory_cyl_y.shrink_to_fit();
						//	trajectory_cyl_z.shrink_to_fit();
						//	trajectory_cyl_r.shrink_to_fit();
						//	trajectory_cyl_rr.shrink_to_fit();
						//	Vector_color_trajectory_cyl.shrink_to_fit();

						//		}


						//	trajectory_cyl_x.erase(trajectory_cyl_x.end() - 3 - index*(N_mag_partitions + 1), trajectory_cyl_x.end());
						//	trajectory_cyl_y.erase(trajectory_cyl_y.end() - 3 - index*(N_mag_partitions + 1), trajectory_cyl_y.end());

						//	trajectory_cyl_z.erase(trajectory_cyl_z.end() - 3 - index*(N_mag_partitions + 1), trajectory_cyl_z.end());
						//	trajectory_cyl_r.erase(trajectory_cyl_r.end() - 3 - index*(N_mag_partitions + 1), trajectory_cyl_r.end());

						//	trajectory_cyl_x.erase(trajectory_cyl_x.end() - 1 - index*(N_mag_partitions+0), trajectory_cyl_x.end());
						//	trajectory_cyl_y.erase(trajectory_cyl_y.end() - 1 - index*(N_mag_partitions+0 ), trajectory_cyl_y.end());

						//	trajectory_cyl_z.erase(trajectory_cyl_z.end() - 1 - index*(N_mag_partitions+0 ), trajectory_cyl_z.end());
						//	trajectory_cyl_r.erase(trajectory_cyl_r.end() - 1 - index*(N_mag_partitions+0 ), trajectory_cyl_r.end());




						//cout << index << endl;








						out1 = false;
						out2 = false;
						out3 = false;
						out4 = false;
						out5 = false;
						out6 = false;
						out7 = false;



						out_mag_1 = false;
						out_mag_2 = false;
						out_mag_3 = false;
						out_mag_4 = false;
						out_mag_5 = false;
						out_mag_6 = false;
						out_mag_7 = false;

						break;

					}


					if ((out7 == true) && (fabs(z_out_7 - (L_1 + L_2 + L_3 + L_4 + L_5 + L_6)) <= epsilon)) {

						//cout << "!!!" << endl;

						out1 = false;
						out2 = false;
						out3 = false;
						out4 = false;
						out5 = false;
						out6 = false;
						out7 = false;


						out_mag_1 = false;
						out_mag_2 = false;
						out_mag_3 = false;
						out_mag_4 = false;
						out_mag_5 = false;
						out_mag_6 = false;
						out_mag_7 = false;

						x_in_6 = x_out_7;
						y_in_6 = y_out_7;
						z_in_6 = z_out_7;
						r_in_6 = r_out_7;

						v_r_in_6 = v_r_out_7;
						v_phi_in_6 = v_phi_out_7;

						theta_in_6 = theta_out_7;
						phi_in_6 = phi_out_7;
						psi_in_6 = psi_out_7;
						//cout << x_in_3 << "  " << y_in_3 << "  " << z_in_3 << "    " << r_in_3 << endl;


						cyl(x_in_6, y_in_6, z_in_6, r_in_6, theta_in_6, phi_in_6, psi_in_6, x_out_6, y_out_6, z_out_6, r_out_6, theta_out_6, phi_out_6, psi_out_6, N1_6, N2_6, N3_6, N4_6, N5_6, L_1 + L_2 + L_3 + L_4 + L_5, L_1 + L_2 + L_3 + L_4 + L_5 + L_6, R1_6, R2_6, R3_6, R1_6, R2_7, R3_7, b6_left, b6_surface, b6_right, V_0, out6, n6, theta6_diffusion_left, theta6_diffusion_surface, theta6_diffusion_right, z0_mag6, L_mag6, r6_mag_max_initial, r6_mag_max_final, mu_core_particle, m_particle, B6_max_initial, on_off_mag_6, mu_electron_particle, I_particle, J_particle, m_F, m_J, B_critical, N_mag_partitions, z_zero_6, n_mag_6_in, n_mag_6_absorption, n_mag_6_out, mag_runge_6, B6_max_final,
							m_mag_6, Vector_temp_r_mag, Vector_temp_z_mag, Vector_temp_x_mag, Vector_temp_y_mag, min_r_out_mag_6, min_r_in_mag_6, particle_mode, iron_mag_6, trajectory_temp_cyl_x, trajectory_temp_cyl_y, trajectory_temp_cyl_z, trajectory_temp_cyl_r, v_r_in_6, v_r_out_6, v_x_in_6, v_x_out_6, v_y_in_6, v_y_out_6, out_mag_6, v_phi_in_6, v_phi_out_6, Vector_color_mag_6, Vector_color_trajectory_temp_cyl, 6.0, Vector_temp_rr_mag, trajectory_temp_cyl_rr, N_CYL_partitions, i_Collision_6, out_trajectory_temp_cyl, Vector_temp_out_mag, b6_mag, b6_mag_left, b6_mag_right, L_cyl_1, L_cyl_2, L_cyl_3, L_cyl_4, L_cyl_5, L_cyl_6, L_cyl_7, Vector_temp_phi_mag, Vector_temp_psi_mag, Vector_temp_theta_mag, trajectory_temp_cyl_phi, trajectory_temp_cyl_psi, trajectory_temp_cyl_theta,
							Vector_temp_v_x_mag, Vector_temp_v_y_mag, Vector_temp_v_z_mag, Vector_temp_v_r_mag, Vector_temp_v_phi_mag, Vector_temp_v_perp_mag, Vector_temp_v_0_mag, trajectory_temp_cyl_v_x, trajectory_temp_cyl_v_y, trajectory_temp_cyl_v_z, trajectory_temp_cyl_v_r, trajectory_temp_cyl_v_phi, trajectory_temp_cyl_v_perp, trajectory_temp_cyl_v_0, n_cos_intensity, Vector_temp_force_mag, trajectory_temp_cyl_force, N_negative_cyl_6, N_zero_cyl_6, N_positive_cyl_6, N_negative_mag_6, N_zero_mag_6, N_positive_mag_6, mu_particle, mu_particle_force, Vector_temp_condition_color_mag, trajectory_temp_cyl_condition_color, flaq_on_off_B_mu,
							index_condition, Vector_temp_mu_mag, Vector_temp_B_mag, trajectory_temp_cyl_mu, trajectory_temp_cyl_B, Vector_r_magnetic_field_table, Vector_phi_magnetic_field_table, Vector_B_magnetic_field_table, Vector_delta_B_magnetic_field_table, on_off_table_magnetic_field, Vector_index_r_magnetic_field_table, index_phi_magnetic_field_table, m_mag_table, r_min_mag_table, r_max_mag_table, L_mag_6_B_off_after);



						continue;

					}



					if ((out7 == true) && (fabs(z_out_7 - (L_1 + L_2 + L_3 + L_4 + L_5 + L_6 + L_7)) <= epsilon)) {

						out1 = false;
						out2 = false;
						out3 = false;
						out4 = false;
						out5 = false;
						out6 = false;
						out7 = false;



						out_mag_1 = false;
						out_mag_2 = false;
						out_mag_3 = false;
						out_mag_4 = false;
						out_mag_5 = false;
						out_mag_6 = false;
						out_mag_7 = false;

						jjj = jjj + 1;

						//	cout << v_phi_in_1 << " " << v_phi_out_3 << endl;

						/*



						if (mu_temp > 0 && mu_force_temp > 0) {
							N_positive_tube = N_positive_tube + 1;

						}

						if (mu_temp < 0 && mu_force_temp < 0) {
							N_negative_tube = N_negative_tube + 1;

						}
						if (mu_temp == 0 && mu_force_temp == 0) {
							N_zero_tube = N_zero_tube + 1;

						}

						*/


						if (r_out_7 <= R_source) {


							long double mu_temp_temp = 0.0;
							long double mu_temp = 0.0;
							long double mu_force_temp = 0.0;
							long double E_temp_temp = 0.0;
							long double mu_particle_temp = 0.0;
							long double mu_particle_force_temp = 0.0;


							const long double mu_bor_1 = 5.788381806638*pow(10.0, 13.0)*pow(2.99792458, 2.0); // магнетон Бора электронный в единицах эВ/Гс*(скорость света [мм/c])^2

																											  //	const long double mu_bor = 3.152451260522*pow(10.0, 10.0)*pow(2.99792458, 2.0); // магнетон Бора ядерный в единицах эВ/Гс*(скорость света [мм/c])^2


							const long double mu_bor_force_1 = 9.2740096820*pow(10.0, 0.0);



							if (flaq_on_off_B_mu == false) {
								mu_particle_temp = mu_temp;
								mu_particle_force_temp = mu_force_temp;

								//cout << fabs(mu_particle / mu_bor) << endl;
							}
							if (flaq_on_off_B_mu == true) {




								//	cout << index_condition << endl;

								if (particle_mode == 1) {
									mu_particle_temp = mu_H(index_condition, B_MAX, mu_temp_temp, E_temp_temp)*mu_bor_1;
									mu_particle_force_temp = mu_H(index_condition, B_MAX, mu_temp_temp, E_temp_temp)*mu_bor_force_1;
								}

								if (particle_mode == 2) {

									mu_particle_temp = mu_D(index_condition, B_MAX, mu_temp_temp, E_temp_temp)*mu_bor_1;
									mu_particle_force_temp = mu_D(index_condition, B_MAX, mu_temp_temp, E_temp_temp)*mu_bor_force_1;
								}

								if (particle_mode == 3) {
									mu_particle_temp = mu_H_2(index_condition, B_MAX, mu_temp_temp, E_temp_temp)*mu_bor_1;
									mu_particle_force_temp = mu_H_2(index_condition, B_MAX, mu_temp_temp, E_temp_temp)*mu_bor_force_1;

								}

								if (particle_mode == 4) { //-V112

									mu_particle_temp = mu_D_2(index_condition, B_MAX, mu_temp_temp, E_temp_temp)*mu_bor_1;
									mu_particle_force_temp = mu_D_2(index_condition, B_MAX, mu_temp_temp, E_temp_temp)*mu_bor_force_1;
								   /*
								   	   cout << endl;
									cout << mu_particle_temp / mu_bor_1 << endl;
									cout << endl;
									cout << index_condition << endl;
									cout << endl;
								   */
									
								}

							}






							if (mu_particle_temp > 0.0 && mu_particle_force_temp > 0.0) {
								N_positive_tube = N_positive_tube + 1;

							}

							if (mu_particle_temp < 0.0 && mu_particle_force_temp < 0.0) {
								N_negative_tube = N_negative_tube + 1;

							}
							if (fabs(mu_particle_temp - 0.0) <= epsilon && fabs(mu_particle_force_temp - 0.0) <= epsilon) {
								N_zero_tube = N_zero_tube + 1;

							}


						}







						if (flaq_out_trajectory == true) {


							bool out_tube = false;

							if (r_out_7 <= R_source) {

								/*



								if (mu_temp > 0 && mu_force_temp > 0) {
									N_positive_tube = N_positive_tube + 1;

								}

								if (mu_temp < 0 && mu_force_temp < 0) {
									N_negative_tube = N_negative_tube + 1;

								}
								if (mu_temp == 0 && mu_force_temp == 0) {
									N_zero_tube = N_zero_tube + 1;

								}

								*/


								out_tube = true;
							}

							if (flaq_trajectory_on_off_z == false) {

								find_trajectory_mag(1.0, trajectory_temp_cyl_x, trajectory_temp_cyl_y, trajectory_temp_cyl_z, trajectory_temp_cyl_r, trajectory_temp_cyl_rr, Vector_color_trajectory_temp_cyl, out_trajectory_temp_cyl, Vector_x_mag_1, Vector_y_mag_1, Vector_z_mag_1, Vector_r_mag_1, Vector_rr_mag_1, Vector_color_mag_1, Vector_out_mag_1, z0_mag1, z0_mag1 + L_mag1, out_tube, trajectory_temp_cyl_phi, trajectory_temp_cyl_psi, trajectory_temp_cyl_theta, Vector_phi_mag_1, Vector_psi_mag_1, Vector_theta_mag_1, trajectory_temp_cyl_v_x, trajectory_temp_cyl_v_y, trajectory_temp_cyl_v_z, trajectory_temp_cyl_v_r, trajectory_temp_cyl_v_phi, trajectory_temp_cyl_v_perp, trajectory_temp_cyl_v_0, Vector_v_x_mag_1, Vector_v_y_mag_1, Vector_v_z_mag_1, Vector_v_r_mag_1, Vector_v_phi_mag_1, Vector_v_perp_mag_1, Vector_v_0_mag_1, trajectory_temp_cyl_force, Vector_force_mag_1, trajectory_temp_cyl_condition_color, Vector_condition_color_mag_1, trajectory_temp_cyl_mu, trajectory_temp_cyl_B, Vector_mu_mag_1, Vector_B_mag_1);

								find_trajectory_mag(2.0, trajectory_temp_cyl_x, trajectory_temp_cyl_y, trajectory_temp_cyl_z, trajectory_temp_cyl_r, trajectory_temp_cyl_rr, Vector_color_trajectory_temp_cyl, out_trajectory_temp_cyl, Vector_x_mag_2, Vector_y_mag_2, Vector_z_mag_2, Vector_r_mag_2, Vector_rr_mag_2, Vector_color_mag_2, Vector_out_mag_2, L_1 + z0_mag2, L_1 + z0_mag2 + L_mag2, out_tube, trajectory_temp_cyl_phi, trajectory_temp_cyl_psi, trajectory_temp_cyl_theta, Vector_phi_mag_2, Vector_psi_mag_2, Vector_theta_mag_2, trajectory_temp_cyl_v_x, trajectory_temp_cyl_v_y, trajectory_temp_cyl_v_z, trajectory_temp_cyl_v_r, trajectory_temp_cyl_v_phi, trajectory_temp_cyl_v_perp, trajectory_temp_cyl_v_0, Vector_v_x_mag_2, Vector_v_y_mag_2, Vector_v_z_mag_2, Vector_v_r_mag_2, Vector_v_phi_mag_2, Vector_v_perp_mag_2, Vector_v_0_mag_2, trajectory_temp_cyl_force, Vector_force_mag_2, trajectory_temp_cyl_condition_color, Vector_condition_color_mag_2, trajectory_temp_cyl_mu, trajectory_temp_cyl_B, Vector_mu_mag_2, Vector_B_mag_2);

								find_trajectory_mag(3.0, trajectory_temp_cyl_x, trajectory_temp_cyl_y, trajectory_temp_cyl_z, trajectory_temp_cyl_r, trajectory_temp_cyl_rr, Vector_color_trajectory_temp_cyl, out_trajectory_temp_cyl, Vector_x_mag_3, Vector_y_mag_3, Vector_z_mag_3, Vector_r_mag_3, Vector_rr_mag_3, Vector_color_mag_3, Vector_out_mag_3, L_1 + L_2 + z0_mag3, L_1 + L_2 + z0_mag3 + L_mag3, out_tube, trajectory_temp_cyl_phi, trajectory_temp_cyl_psi, trajectory_temp_cyl_theta, Vector_phi_mag_3, Vector_psi_mag_3, Vector_theta_mag_3, trajectory_temp_cyl_v_x, trajectory_temp_cyl_v_y, trajectory_temp_cyl_v_z, trajectory_temp_cyl_v_r, trajectory_temp_cyl_v_phi, trajectory_temp_cyl_v_perp, trajectory_temp_cyl_v_0, Vector_v_x_mag_3, Vector_v_y_mag_3, Vector_v_z_mag_3, Vector_v_r_mag_3, Vector_v_phi_mag_3, Vector_v_perp_mag_3, Vector_v_0_mag_3, trajectory_temp_cyl_force, Vector_force_mag_3, trajectory_temp_cyl_condition_color, Vector_condition_color_mag_3, trajectory_temp_cyl_mu, trajectory_temp_cyl_B, Vector_mu_mag_3, Vector_B_mag_3);

								find_trajectory_mag(4.0, trajectory_temp_cyl_x, trajectory_temp_cyl_y, trajectory_temp_cyl_z, trajectory_temp_cyl_r, trajectory_temp_cyl_rr, Vector_color_trajectory_temp_cyl, out_trajectory_temp_cyl, Vector_x_mag_4, Vector_y_mag_4, Vector_z_mag_4, Vector_r_mag_4, Vector_rr_mag_4, Vector_color_mag_4, Vector_out_mag_4, L_1 + L_2 + L_3 + z0_mag4, L_1 + L_2 + L_3 + z0_mag4 + L_mag4, out_tube, trajectory_temp_cyl_phi, trajectory_temp_cyl_psi, trajectory_temp_cyl_theta, Vector_phi_mag_4, Vector_psi_mag_4, Vector_theta_mag_4, trajectory_temp_cyl_v_x, trajectory_temp_cyl_v_y, trajectory_temp_cyl_v_z, trajectory_temp_cyl_v_r, trajectory_temp_cyl_v_phi, trajectory_temp_cyl_v_perp, trajectory_temp_cyl_v_0, Vector_v_x_mag_4, Vector_v_y_mag_4, Vector_v_z_mag_4, Vector_v_r_mag_4, Vector_v_phi_mag_4, Vector_v_perp_mag_4, Vector_v_0_mag_4, trajectory_temp_cyl_force, Vector_force_mag_4, trajectory_temp_cyl_condition_color, Vector_condition_color_mag_4, trajectory_temp_cyl_mu, trajectory_temp_cyl_B, Vector_mu_mag_4, Vector_B_mag_4);

								find_trajectory_mag(5.0, trajectory_temp_cyl_x, trajectory_temp_cyl_y, trajectory_temp_cyl_z, trajectory_temp_cyl_r, trajectory_temp_cyl_rr, Vector_color_trajectory_temp_cyl, out_trajectory_temp_cyl, Vector_x_mag_5, Vector_y_mag_5, Vector_z_mag_5, Vector_r_mag_5, Vector_rr_mag_5, Vector_color_mag_5, Vector_out_mag_5, L_1 + L_2 + L_3 + L_4 + z0_mag5, L_1 + L_2 + L_3 + L_4 + z0_mag5 + L_mag5, out_tube, trajectory_temp_cyl_phi, trajectory_temp_cyl_psi, trajectory_temp_cyl_theta, Vector_phi_mag_5, Vector_psi_mag_5, Vector_theta_mag_5, trajectory_temp_cyl_v_x, trajectory_temp_cyl_v_y, trajectory_temp_cyl_v_z, trajectory_temp_cyl_v_r, trajectory_temp_cyl_v_phi, trajectory_temp_cyl_v_perp, trajectory_temp_cyl_v_0, Vector_v_x_mag_5, Vector_v_y_mag_5, Vector_v_z_mag_5, Vector_v_r_mag_5, Vector_v_phi_mag_5, Vector_v_perp_mag_5, Vector_v_0_mag_5, trajectory_temp_cyl_force, Vector_force_mag_5, trajectory_temp_cyl_condition_color, Vector_condition_color_mag_5, trajectory_temp_cyl_mu, trajectory_temp_cyl_B, Vector_mu_mag_5, Vector_B_mag_5);

								find_trajectory_mag(6.0, trajectory_temp_cyl_x, trajectory_temp_cyl_y, trajectory_temp_cyl_z, trajectory_temp_cyl_r, trajectory_temp_cyl_rr, Vector_color_trajectory_temp_cyl, out_trajectory_temp_cyl, Vector_x_mag_6, Vector_y_mag_6, Vector_z_mag_6, Vector_r_mag_6, Vector_rr_mag_6, Vector_color_mag_6, Vector_out_mag_6, L_1 + L_2 + L_3 + L_4 + L_5 + z0_mag6 , L_1 + L_2 + L_3 + L_4 + L_5 + z0_mag6 + L_mag6, out_tube, trajectory_temp_cyl_phi, trajectory_temp_cyl_psi, trajectory_temp_cyl_theta, Vector_phi_mag_6, Vector_psi_mag_6, Vector_theta_mag_6, trajectory_temp_cyl_v_x, trajectory_temp_cyl_v_y, trajectory_temp_cyl_v_z, trajectory_temp_cyl_v_r, trajectory_temp_cyl_v_phi, trajectory_temp_cyl_v_perp, trajectory_temp_cyl_v_0, Vector_v_x_mag_6, Vector_v_y_mag_6, Vector_v_z_mag_6, Vector_v_r_mag_6, Vector_v_phi_mag_6, Vector_v_perp_mag_6, Vector_v_0_mag_6, trajectory_temp_cyl_force, Vector_force_mag_6, trajectory_temp_cyl_condition_color, Vector_condition_color_mag_6, trajectory_temp_cyl_mu, trajectory_temp_cyl_B, Vector_mu_mag_6, Vector_B_mag_6);

								find_trajectory_mag(7.0, trajectory_temp_cyl_x, trajectory_temp_cyl_y, trajectory_temp_cyl_z, trajectory_temp_cyl_r, trajectory_temp_cyl_rr, Vector_color_trajectory_temp_cyl, out_trajectory_temp_cyl, Vector_x_mag_7, Vector_y_mag_7, Vector_z_mag_7, Vector_r_mag_7, Vector_rr_mag_7, Vector_color_mag_7, Vector_out_mag_7, L_1 + L_2 + L_3 + L_4 + L_5 + L_6 + z0_mag7, L_1 + L_2 + L_3 + L_4 + L_5 + L_6 + z0_mag7 + L_mag7, out_tube, trajectory_temp_cyl_phi, trajectory_temp_cyl_psi, trajectory_temp_cyl_theta, Vector_phi_mag_7, Vector_psi_mag_7, Vector_theta_mag_7, trajectory_temp_cyl_v_x, trajectory_temp_cyl_v_y, trajectory_temp_cyl_v_z, trajectory_temp_cyl_v_r, trajectory_temp_cyl_v_phi, trajectory_temp_cyl_v_perp, trajectory_temp_cyl_v_0, Vector_v_x_mag_7, Vector_v_y_mag_7, Vector_v_z_mag_7, Vector_v_r_mag_7, Vector_v_phi_mag_7, Vector_v_perp_mag_7, Vector_v_0_mag_7, trajectory_temp_cyl_force, Vector_force_mag_7, trajectory_temp_cyl_condition_color, Vector_condition_color_mag_7, trajectory_temp_cyl_mu, trajectory_temp_cyl_B, Vector_mu_mag_7, Vector_B_mag_7);





								find_trajectory_cyl(1.0, trajectory_temp_cyl_x, trajectory_temp_cyl_y, trajectory_temp_cyl_z, trajectory_temp_cyl_r, trajectory_temp_cyl_rr, Vector_color_trajectory_temp_cyl, out_trajectory_temp_cyl, Vector_x_cyl_1, Vector_y_cyl_1, Vector_z_cyl_1, Vector_r_cyl_1, Vector_rr_cyl_1, Vector_color_cyl_1, Vector_out_cyl_1, 0.0, L_1, out_tube, trajectory_temp_cyl_phi, trajectory_temp_cyl_psi, trajectory_temp_cyl_theta, Vector_phi_cyl_1, Vector_psi_cyl_1, Vector_theta_cyl_1, trajectory_temp_cyl_v_x, trajectory_temp_cyl_v_y, trajectory_temp_cyl_v_z, trajectory_temp_cyl_v_r, trajectory_temp_cyl_v_phi, trajectory_temp_cyl_v_perp, trajectory_temp_cyl_v_0, Vector_v_x_cyl_1, Vector_v_y_cyl_1, Vector_v_z_cyl_1, Vector_v_r_cyl_1, Vector_v_phi_cyl_1, Vector_v_perp_cyl_1, Vector_v_0_cyl_1, trajectory_temp_cyl_force, Vector_force_cyl_1, trajectory_temp_cyl_condition_color, Vector_condition_color_cyl_1, trajectory_temp_cyl_mu, trajectory_temp_cyl_B, Vector_mu_cyl_1, Vector_B_cyl_1);

								find_trajectory_cyl(2.0, trajectory_temp_cyl_x, trajectory_temp_cyl_y, trajectory_temp_cyl_z, trajectory_temp_cyl_r, trajectory_temp_cyl_rr, Vector_color_trajectory_temp_cyl, out_trajectory_temp_cyl, Vector_x_cyl_2, Vector_y_cyl_2, Vector_z_cyl_2, Vector_r_cyl_2, Vector_rr_cyl_2, Vector_color_cyl_2, Vector_out_cyl_2, L_1, L_1 + L_2, out_tube, trajectory_temp_cyl_phi, trajectory_temp_cyl_psi, trajectory_temp_cyl_theta, Vector_phi_cyl_2, Vector_psi_cyl_2, Vector_theta_cyl_2, trajectory_temp_cyl_v_x, trajectory_temp_cyl_v_y, trajectory_temp_cyl_v_z, trajectory_temp_cyl_v_r, trajectory_temp_cyl_v_phi, trajectory_temp_cyl_v_perp, trajectory_temp_cyl_v_0, Vector_v_x_cyl_2, Vector_v_y_cyl_2, Vector_v_z_cyl_2, Vector_v_r_cyl_2, Vector_v_phi_cyl_2, Vector_v_perp_cyl_2, Vector_v_0_cyl_2, trajectory_temp_cyl_force, Vector_force_cyl_2, trajectory_temp_cyl_condition_color, Vector_condition_color_cyl_2, trajectory_temp_cyl_mu, trajectory_temp_cyl_B, Vector_mu_cyl_2, Vector_B_cyl_2);

								find_trajectory_cyl(3.0, trajectory_temp_cyl_x, trajectory_temp_cyl_y, trajectory_temp_cyl_z, trajectory_temp_cyl_r, trajectory_temp_cyl_rr, Vector_color_trajectory_temp_cyl, out_trajectory_temp_cyl, Vector_x_cyl_3, Vector_y_cyl_3, Vector_z_cyl_3, Vector_r_cyl_3, Vector_rr_cyl_3, Vector_color_cyl_3, Vector_out_cyl_3, L_1 + L_2, L_1 + L_2 + L_3, out_tube, trajectory_temp_cyl_phi, trajectory_temp_cyl_psi, trajectory_temp_cyl_theta, Vector_phi_cyl_3, Vector_psi_cyl_3, Vector_theta_cyl_3, trajectory_temp_cyl_v_x, trajectory_temp_cyl_v_y, trajectory_temp_cyl_v_z, trajectory_temp_cyl_v_r, trajectory_temp_cyl_v_phi, trajectory_temp_cyl_v_perp, trajectory_temp_cyl_v_0, Vector_v_x_cyl_3, Vector_v_y_cyl_3, Vector_v_z_cyl_3, Vector_v_r_cyl_3, Vector_v_phi_cyl_3, Vector_v_perp_cyl_3, Vector_v_0_cyl_3, trajectory_temp_cyl_force, Vector_force_cyl_3, trajectory_temp_cyl_condition_color, Vector_condition_color_cyl_3, trajectory_temp_cyl_mu, trajectory_temp_cyl_B, Vector_mu_cyl_3, Vector_B_cyl_3);

								find_trajectory_cyl(4.0, trajectory_temp_cyl_x, trajectory_temp_cyl_y, trajectory_temp_cyl_z, trajectory_temp_cyl_r, trajectory_temp_cyl_rr, Vector_color_trajectory_temp_cyl, out_trajectory_temp_cyl, Vector_x_cyl_4, Vector_y_cyl_4, Vector_z_cyl_4, Vector_r_cyl_4, Vector_rr_cyl_4, Vector_color_cyl_4, Vector_out_cyl_4, L_1 + L_2 + L_3, L_1 + L_2 + L_3 + L_4, out_tube, trajectory_temp_cyl_phi, trajectory_temp_cyl_psi, trajectory_temp_cyl_theta, Vector_phi_cyl_4, Vector_psi_cyl_4, Vector_theta_cyl_4, trajectory_temp_cyl_v_x, trajectory_temp_cyl_v_y, trajectory_temp_cyl_v_z, trajectory_temp_cyl_v_r, trajectory_temp_cyl_v_phi, trajectory_temp_cyl_v_perp, trajectory_temp_cyl_v_0, Vector_v_x_cyl_4, Vector_v_y_cyl_4, Vector_v_z_cyl_4, Vector_v_r_cyl_4, Vector_v_phi_cyl_4, Vector_v_perp_cyl_4, Vector_v_0_cyl_4, trajectory_temp_cyl_force, Vector_force_cyl_4, trajectory_temp_cyl_condition_color, Vector_condition_color_cyl_4, trajectory_temp_cyl_mu, trajectory_temp_cyl_B, Vector_mu_cyl_4, Vector_B_cyl_4);

								find_trajectory_cyl(5.0, trajectory_temp_cyl_x, trajectory_temp_cyl_y, trajectory_temp_cyl_z, trajectory_temp_cyl_r, trajectory_temp_cyl_rr, Vector_color_trajectory_temp_cyl, out_trajectory_temp_cyl, Vector_x_cyl_5, Vector_y_cyl_5, Vector_z_cyl_5, Vector_r_cyl_5, Vector_rr_cyl_5, Vector_color_cyl_5, Vector_out_cyl_5, L_1 + L_2 + L_3 + L_4, L_1 + L_2 + L_3 + L_4 + L_5, out_tube, trajectory_temp_cyl_phi, trajectory_temp_cyl_psi, trajectory_temp_cyl_theta, Vector_phi_cyl_5, Vector_psi_cyl_5, Vector_theta_cyl_5, trajectory_temp_cyl_v_x, trajectory_temp_cyl_v_y, trajectory_temp_cyl_v_z, trajectory_temp_cyl_v_r, trajectory_temp_cyl_v_phi, trajectory_temp_cyl_v_perp, trajectory_temp_cyl_v_0, Vector_v_x_cyl_5, Vector_v_y_cyl_5, Vector_v_z_cyl_5, Vector_v_r_cyl_5, Vector_v_phi_cyl_5, Vector_v_perp_cyl_5, Vector_v_0_cyl_5, trajectory_temp_cyl_force, Vector_force_cyl_5, trajectory_temp_cyl_condition_color, Vector_condition_color_cyl_5, trajectory_temp_cyl_mu, trajectory_temp_cyl_B, Vector_mu_cyl_5, Vector_B_cyl_5);

								find_trajectory_cyl(6.0, trajectory_temp_cyl_x, trajectory_temp_cyl_y, trajectory_temp_cyl_z, trajectory_temp_cyl_r, trajectory_temp_cyl_rr, Vector_color_trajectory_temp_cyl, out_trajectory_temp_cyl, Vector_x_cyl_6, Vector_y_cyl_6, Vector_z_cyl_6, Vector_r_cyl_6, Vector_rr_cyl_6, Vector_color_cyl_6, Vector_out_cyl_6, L_1 + L_2 + L_3 + L_4 + L_5, L_1 + L_2 + L_3 + L_4 + L_5 + L_6, out_tube, trajectory_temp_cyl_phi, trajectory_temp_cyl_psi, trajectory_temp_cyl_theta, Vector_phi_cyl_6, Vector_psi_cyl_6, Vector_theta_cyl_6, trajectory_temp_cyl_v_x, trajectory_temp_cyl_v_y, trajectory_temp_cyl_v_z, trajectory_temp_cyl_v_r, trajectory_temp_cyl_v_phi, trajectory_temp_cyl_v_perp, trajectory_temp_cyl_v_0, Vector_v_x_cyl_6, Vector_v_y_cyl_6, Vector_v_z_cyl_6, Vector_v_r_cyl_6, Vector_v_phi_cyl_6, Vector_v_perp_cyl_6, Vector_v_0_cyl_6, trajectory_temp_cyl_force, Vector_force_cyl_6, trajectory_temp_cyl_condition_color, Vector_condition_color_cyl_6, trajectory_temp_cyl_mu, trajectory_temp_cyl_B, Vector_mu_cyl_6, Vector_B_cyl_6);

								find_trajectory_cyl(7.0, trajectory_temp_cyl_x, trajectory_temp_cyl_y, trajectory_temp_cyl_z, trajectory_temp_cyl_r, trajectory_temp_cyl_rr, Vector_color_trajectory_temp_cyl, out_trajectory_temp_cyl, Vector_x_cyl_7, Vector_y_cyl_7, Vector_z_cyl_7, Vector_r_cyl_7, Vector_rr_cyl_7, Vector_color_cyl_7, Vector_out_cyl_7, L_1 + L_2 + L_3 + L_4 + L_5 + L_6, L_1 + L_2 + L_3 + L_4 + L_5 + L_6 + L_7, out_tube, trajectory_temp_cyl_phi, trajectory_temp_cyl_psi, trajectory_temp_cyl_theta, Vector_phi_cyl_7, Vector_psi_cyl_7, Vector_theta_cyl_7, trajectory_temp_cyl_v_x, trajectory_temp_cyl_v_y, trajectory_temp_cyl_v_z, trajectory_temp_cyl_v_r, trajectory_temp_cyl_v_phi, trajectory_temp_cyl_v_perp, trajectory_temp_cyl_v_0, Vector_v_x_cyl_7, Vector_v_y_cyl_7, Vector_v_z_cyl_7, Vector_v_r_cyl_7, Vector_v_phi_cyl_7, Vector_v_perp_cyl_7, Vector_v_0_cyl_7, trajectory_temp_cyl_force, Vector_force_cyl_7, trajectory_temp_cyl_condition_color, Vector_condition_color_cyl_7, trajectory_temp_cyl_mu, trajectory_temp_cyl_B, Vector_mu_cyl_7, Vector_B_cyl_7);


							}

							Vector_x_in.push_back(x_in_1);
							Vector_y_in.push_back(y_in_1);
							Vector_z_in.push_back(z_in_1);

							Vector_phi_in.push_back(phi_in_1);
							Vector_psi_in.push_back(psi_in_1);
							Vector_theta_in.push_back(theta_in_1);


							Vector_r_in.push_back(r_in_1);


							Vector_x_in_CYL_7.push_back(x_out_7);
							Vector_y_in_CYL_7.push_back(y_out_7);
							Vector_z_in_CYL_7.push_back(z_out_7);

							Vector_phi_in_CYL_7.push_back(phi_out_7);
							Vector_psi_in_CYL_7.push_back(psi_out_7);
							Vector_theta_in_CYL_7.push_back(theta_out_7);

							Vector_r_in_CYL_7.push_back(r_out_7);




							if (y_in_1 < 0) {
								Vector_rr_in.push_back(-r_in_1);
							}
							else if (y_in_1 >= 0) {

								Vector_rr_in.push_back(r_in_1);
							}



							if (y_out_7 < 0) {
								Vector_rr_in_CYL_7.push_back(-r_out_7);
							}
							else if (y_out_7 >= 0) {

								Vector_rr_in_CYL_7.push_back(r_out_7);
							}




							if (mu_particle < 0.0) {
								Vector_x_in_CYL_7_negative.push_back(x_out_7);
								Vector_y_in_CYL_7_negative.push_back(y_out_7);
								Vector_z_in_CYL_7_negative.push_back(z_out_7);

								Vector_phi_in_CYL_7_negative.push_back(phi_out_7);
								Vector_psi_in_CYL_7_negative.push_back(psi_out_7);
								Vector_theta_in_CYL_7_negative.push_back(theta_out_7);

								Vector_r_in_CYL_7_negative.push_back(r_out_7);



								if (y_out_7 < 0) {
									Vector_rr_in_CYL_7_negative.push_back(-r_out_7);
								}
								else if (y_out_7 >= 0) {

									Vector_rr_in_CYL_7_negative.push_back(r_out_7);
								}

							}
							if (mu_particle > 0.0) {
								Vector_x_in_CYL_7_positive.push_back(x_out_7);
								Vector_y_in_CYL_7_positive.push_back(y_out_7);
								Vector_z_in_CYL_7_positive.push_back(z_out_7);

								Vector_phi_in_CYL_7_positive.push_back(phi_out_7);
								Vector_psi_in_CYL_7_positive.push_back(psi_out_7);
								Vector_theta_in_CYL_7_positive.push_back(theta_out_7);

								Vector_r_in_CYL_7_positive.push_back(r_out_7);



								if (y_out_7 < 0) {
									Vector_rr_in_CYL_7_positive.push_back(-r_out_7);
								}
								else if (y_out_7 >= 0) {

									Vector_rr_in_CYL_7_positive.push_back(r_out_7);
								}

							}
							if (fabs(mu_particle - 0.0) <= epsilon) {
								Vector_x_in_CYL_7_zero.push_back(x_out_7);
								Vector_y_in_CYL_7_zero.push_back(y_out_7);
								Vector_z_in_CYL_7_zero.push_back(z_out_7);

								Vector_phi_in_CYL_7_zero.push_back(phi_out_7);
								Vector_psi_in_CYL_7_zero.push_back(psi_out_7);
								Vector_theta_in_CYL_7_zero.push_back(theta_out_7);

								Vector_r_in_CYL_7_zero.push_back(r_out_7);



								if (y_out_7 < 0) {
									Vector_rr_in_CYL_7_zero.push_back(-r_out_7);
								}
								else if (y_out_7 >= 0) {

									Vector_rr_in_CYL_7_zero.push_back(r_out_7);
								}

							}

							//	trajectory_cyl_x.push_back(x_out_3);
							//	trajectory_cyl_y.push_back(y_out_3);
							//	trajectory_cyl_z.push_back(z_out_3);
							//	trajectory_cyl_r.push_back(r_out_3);

							//	if (y_out_3 < 0) {
							//		trajectory_cyl_rr.push_back(-r_out_3);
							//	}
							//	else if (y_out_3 >= 0) {

							//		trajectory_cyl_rr.push_back(r_out_3);
							//	}


							if (flaq_trajectory_on_off_z == false) {

								//	Vector_color_trajectory_cyl.push_back(0.0);

								size_t vector_size = trajectory_temp_cyl_z.size();

								for (size_t i = 0; i < vector_size; i = i + 1) {

									trajectory_cyl_x.push_back(trajectory_temp_cyl_x[i]);
									trajectory_cyl_y.push_back(trajectory_temp_cyl_y[i]);
									trajectory_cyl_z.push_back(trajectory_temp_cyl_z[i]);

									trajectory_cyl_mu.push_back(trajectory_temp_cyl_mu[i]);
									trajectory_cyl_B.push_back(trajectory_temp_cyl_B[i]);




									trajectory_cyl_phi.push_back(trajectory_temp_cyl_phi[i]);
									trajectory_cyl_psi.push_back(trajectory_temp_cyl_psi[i]);
									trajectory_cyl_theta.push_back(trajectory_temp_cyl_theta[i]);


									trajectory_cyl_v_x.push_back(trajectory_temp_cyl_v_x[i]);
									trajectory_cyl_v_y.push_back(trajectory_temp_cyl_v_y[i]);
									trajectory_cyl_v_z.push_back(trajectory_temp_cyl_v_z[i]);
									trajectory_cyl_v_r.push_back(trajectory_temp_cyl_v_r[i]);
									trajectory_cyl_v_phi.push_back(trajectory_temp_cyl_v_phi[i]);
									trajectory_cyl_v_perp.push_back(trajectory_temp_cyl_v_perp[i]);
									trajectory_cyl_v_0.push_back(trajectory_temp_cyl_v_0[i]);
									trajectory_cyl_force.push_back(trajectory_temp_cyl_force[i]);


									trajectory_cyl_r.push_back(trajectory_temp_cyl_r[i]);
									trajectory_cyl_rr.push_back(trajectory_temp_cyl_rr[i]);
									Vector_color_trajectory_cyl.push_back(Vector_color_trajectory_temp_cyl[i]);

									trajectory_cyl_condition_color.push_back(trajectory_temp_cyl_condition_color[i]);


									out_trajectory_cyl.push_back(out_trajectory_temp_cyl[i]);
								}

								//			long double rr_out_3 = 0.0;

								//			if (y_out_3 >= 0) {
								//				rr_out_3 = r_out_3;
								//			}
								//			else {
								//				rr_out_3 = -r_out_3;
								//			}


								//			trajectory_cyl_x.push_back(x_out_3);
								//			trajectory_cyl_y.push_back(y_out_3);
								//			trajectory_cyl_z.push_back(z_out_3);
								//			trajectory_cyl_r.push_back(r_out_3);
								//			trajectory_cyl_rr.push_back(rr_out_3);
								//			Vector_color_trajectory_cyl.push_back(0.0);
								//			out_trajectory_cyl.push_back(1.0);

								out_trajectory_cyl.erase(out_trajectory_cyl.end() - 1, out_trajectory_cyl.end());

								out_trajectory_cyl.shrink_to_fit();

								out_trajectory_cyl.push_back(1.0);

							}

							if (r_out_7 <= R_source) {

								Vector_color_in.push_back(1.0);

								Vector_color_in_CYL_7.push_back(1.0);


								//histo_V_0(mass_histo_V_0_tube_out, N_histo_V_0_tube_out, a_V_0, b_V_0, V_0);

							}
							else {
								Vector_color_in.push_back(0.0);

								Vector_color_in_CYL_7.push_back(0.0);

							}



						}

						long double procent = ((long double)ii / N)*100.0;
						unsigned int end_time1 = (unsigned int)clock(); // текущее время
						unsigned int search_time1 = end_time1 - start_time; // искомое время в миллисекундах

						printf("%+.3Lf %+.3Lf %.3Lf %.3Lf %.3Le %.3Lf %% %i мин. %i сек. %i мсек. %.3Le мм/сек. № %.0Lf %.3Lf\r", x_out_7, y_out_7, z_out_7, r_out_7, (long double)ii, procent, (search_time1 / (1000 * 60)), (search_time1 / 1000) % 60, search_time1 % 1000, V_0, (long double)jjj, z_zero_7);



						if (console_out == true) {





							printf("%+.3Lf %+.3Lf %.3Lf %.3Lf %.3Le %.3Lf %% %i мин. %i сек. %i мсек. %.3Le мм/сек. № %.0Lf %.3Lf\n", x_out_7, y_out_7, z_out_7, r_out_7, (long double)ii, procent, (int)(search_time1 / (1000 * 60)), (int)((int)(search_time1 / 1000) % 60), search_time1 % 1000, V_0, (long double)jjj, z_zero_7);



							//cout << x_out_3 << "  " << y_out_3 << "  " << z_out_3 << "    " << r_out_3 << endl;
						}

						if (console_out == false) {

							printf("%+.3Lf %+.3Lf %.3Lf %.3Lf %.3Le %.3Lf %% %i мин. %i сек. %i мсек. %.3Le мм/сек. № %.0Lf %.3Lf\r", x_out_7, y_out_7, z_out_7, r_out_7, (long double)ii, procent, (int)(search_time1 / (1000 * 60)), (int)((int)(search_time1 / 1000) % 60), search_time1 % 1000, V_0, (long double)jjj, z_zero_7);

						}

						histo_V_0(mass_histo_V_0_out, N_histo_V_0_out, a_V_0, b_V_0, V_0);

						histo_time(mass_histo_time, N_histo_time, a_time, b_time, (L_1 + L_2 + L_3 + L_4 + L_5 + L_6 + L_7) / (V_0_initial*cos(theta_in_1)));

						long double	theta_out_7_intens = 0.0;

						if (n_cos_intensity == 1.0) { //-V550

							long double ksi_out = pow(sin(theta_out_7), 2.0);

							theta_out_7_intens = asin(ksi_out);

						}
						else {

							theta_out_7_intens = random_Neumann_theta_intensity(n_cos_intensity);
						}



						if (cos(psi_out_7) > 0) {

							histo_theta_in(mass_histo_theta_out, N_histo_theta_in, theta_out_7);
							histo_theta_in(mass_histo_theta_out_, N_histo_theta_in, theta_out_7_intens);

						}
						if (cos(psi_out_7) <= 0) {

							histo_theta_in(mass_histo_theta_out, N_histo_theta_in, -theta_out_7);
							histo_theta_in(mass_histo_theta_out_, N_histo_theta_in, -theta_out_7_intens);

						}

						if (flaq_angular_coefficient == true) {
							theta_in_1 = theta_in_2;
							psi_in_1 = psi_in_2;

							if (n_cos_intensity == 1.0) { //-V550

								long double ksi = pow(sin(theta_in_1), 2.0);

								theta_in_1_intens = asin(ksi);
							}
							else {

								theta_in_1_intens = random_Neumann_theta_intensity(n_cos_intensity);

							}
						}

						if (cos(psi_in_1) > 0) {

							histo_theta_in(mass_histo_theta_in_out, N_histo_theta_in, theta_in_1);
							histo_theta_in(mass_histo_theta_in_out_, N_histo_theta_in, theta_in_1_intens);
						}
						if (cos(psi_in_1) <= 0) {

							histo_theta_in(mass_histo_theta_in_out, N_histo_theta_in, -theta_in_1);
							histo_theta_in(mass_histo_theta_in_out_, N_histo_theta_in, -theta_in_1_intens);
						}





						if (r_out_7 <= R_source) {

							histo_V_0(mass_histo_V_0_tube_out, N_histo_V_0_tube_out, a_V_0, b_V_0, V_0);

						}



						mass_histo_x = histo_x("histo", mass_histo_x, N_histo, x_out_7, y_out_7, R, R_source, x_0_source);
						mass_histo_r = histo_r("histo", mass_histo_r, (std::size_t)(N_histo / 2), x_out_7, y_out_7, R, R_source, x_0_source);

						if (r_out_7 <= R_source) {


							mass_histo_x_cyl1_in_source = histo_x("histo", mass_histo_x_cyl1_in_source, N_histo, x_in_1, y_in_1, R, R_source, x_0_source);

							mass_histo_r_cyl1_in_source = histo_r("histo", mass_histo_r_cyl1_in_source, (std::size_t)(N_histo / 2), x_in_1, y_in_1, R, R_source, x_0_source);


							if (mu_particle > 0) {

								mass_histo_x_cyl1_in_source_positive = histo_x("histo", mass_histo_x_cyl1_in_source_positive, N_histo, x_in_1, y_in_1, R, R_source, x_0_source);

								mass_histo_r_cyl1_in_source_positive = histo_r("histo", mass_histo_r_cyl1_in_source_positive, (std::size_t)(N_histo / 2), x_in_1, y_in_1, R, R_source, x_0_source);


							}


							if (fabs(mu_particle - 0.0) <= epsilon) {


								mass_histo_x_cyl1_in_source_zero = histo_x("histo", mass_histo_x_cyl1_in_source_zero, N_histo, x_in_1, y_in_1, R, R_source, x_0_source);

								mass_histo_r_cyl1_in_source_zero = histo_r("histo", mass_histo_r_cyl1_in_source_zero, (std::size_t)(N_histo / 2), x_in_1, y_in_1, R, R_source, x_0_source);


							}


							if (mu_particle < 0) {


								mass_histo_x_cyl1_in_source_negative = histo_x("histo", mass_histo_x_cyl1_in_source_negative, N_histo, x_in_1, y_in_1, R, R_source, x_0_source);

								mass_histo_r_cyl1_in_source_negative = histo_r("histo", mass_histo_r_cyl1_in_source_negative, (std::size_t)(N_histo / 2), x_in_1, y_in_1, R, R_source, x_0_source);



							}




							//cout << "!!!" << endl;
							//cout << x_in_1 << " " << y_in_1 << endl;
						}

						mass_histo_x_source = histo_x("source", mass_histo_x_source, N_histo_source, x_out_7, y_out_7, R, R_source, x_0_source);
						mass_histo_r_source = histo_r("source", mass_histo_r_source, (std::size_t)(N_histo_source / 2), x_out_7, y_out_7, R, R_source, x_0_source);







						if (mu_particle > 0) {


							mass_histo_x_positive = histo_x("histo", mass_histo_x_positive, N_histo, x_out_7, y_out_7, R, R_source, x_0_source);
							mass_histo_r_positive = histo_r("histo", mass_histo_r_positive, (std::size_t)(N_histo / 2), x_out_7, y_out_7, R, R_source, x_0_source);


							mass_histo_x_source_positive = histo_x("source", mass_histo_x_source_positive, N_histo_source, x_out_7, y_out_7, R, R_source, x_0_source);
							mass_histo_r_source_positive = histo_r("source", mass_histo_r_source_positive, (std::size_t)(N_histo_source / 2), x_out_7, y_out_7, R, R_source, x_0_source);

						}
						if (fabs(mu_particle - 0.0) <= epsilon) {

							mass_histo_x_zero = histo_x("histo", mass_histo_x_zero, N_histo, x_out_7, y_out_7, R, R_source, x_0_source);
							mass_histo_r_zero = histo_r("histo", mass_histo_r_zero, (std::size_t)(N_histo / 2), x_out_7, y_out_7, R, R_source, x_0_source);


							mass_histo_x_source_zero = histo_x("source", mass_histo_x_source_zero, N_histo_source, x_out_7, y_out_7, R, R_source, x_0_source);
							mass_histo_r_source_zero = histo_r("source", mass_histo_r_source_zero, (std::size_t)(N_histo_source / 2), x_out_7, y_out_7, R, R_source, x_0_source);

						}

						if (mu_particle < 0) {

							mass_histo_x_negative = histo_x("histo", mass_histo_x_negative, N_histo, x_out_7, y_out_7, R, R_source, x_0_source);
							mass_histo_r_negative = histo_r("histo", mass_histo_r_negative, (std::size_t)(N_histo / 2), x_out_7, y_out_7, R, R_source, x_0_source);


							mass_histo_x_source_negative = histo_x("source", mass_histo_x_source_negative, N_histo_source, x_out_7, y_out_7, R, R_source, x_0_source);
							mass_histo_r_source_negative = histo_r("source", mass_histo_r_source_negative, (std::size_t)(N_histo_source / 2), x_out_7, y_out_7, R, R_source, x_0_source);

						}

						break;

					}


					//break;

				}

				//	printf("%s %s %s\n", (out1 ? "Да" : "Нет"), (out2 ? "Да" : "Нет"), (out3 ? "Да" : "Нет"));


				//	continue;
			}

			else {

				N_off = N_off + 1;
				//	continue;
			}





		}





	}


	SleepEx(40, true); // пауза для того, чтобы успеть прочитать информацию



	if (console_out == true) {


		cout << endl;
		cout << "Выходные данные: Гистограмма распределения по радиусу" << endl;
		cout << endl;
		cout << "Первый столбец: Число частиц, попавших в бин ||" << " Второй столбец: Координата левого конца бина" << endl;
		cout << endl;

		SleepEx(40, true); // пауза для того, чтобы успеть прочитать информацию

						   //	mass_histo_out(mass_histo_x);

	}








	WORD ATTR = FOREGROUND_BLUE;
	HANDLE CH = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(CH, ATTR);
	cout << endl;
	//	printf("Полное число частиц брошенных в квадрат, описанный вокруг торца цилиндра %.1e\n", (long double)N);
	//	printf("Число частиц, которые не вышли из квадрата в источник %.1e\n", (long double)N4);
	//cout << "Число частиц выпущенных из кольца источником " << N1 << endl;
	//	printf("Полное число частиц выпущенных из кольца источником  %.1e\n", (long double)N);

	//	cout << "Полное число частиц, которые вышли из цилиндра " << N2 << endl;
	//	cout << "Число частиц, которые вернулись обратно в источник " << N3 << endl;
	//	cout << "Число частиц, которые были захвачены поверхностью цилиндра " << N7 << endl;
	cout << endl;
	//	cout << "Число частиц, которые сразу вышли из усточника и не коснулись стенок " << N5 << endl;
	//	cout << "Число частиц, которые хотя бы раз коснулись стенок и вышли из источника " << N6 << endl;
	cout << endl;
	//	cout << "N_out/N_in=" << ((long double)N2 / (long double)N1) << endl;
	cout << "L_3/R_2=" << ((long double)L_3 / (long double)R1_2) << endl;
	//	cout << "k=(N_out/N_in)/(L_3/R_3)=" << ((long double)N2 / (long double)N1) / ((long double)L_3 / (long double)R1_3) << endl;
	cout << endl;

	ATTR = FOREGROUND_GREEN;

	SetConsoleTextAttribute(CH, ATTR);





	//unsigned int end_time = clock(); // конечное время
	//unsigned int search_time = end_time - start_time; // искомое время в миллисекундах
	//unsigned int search_time_ = (int)(search_time / (1000.0 * 60.0)); // минут
	unsigned int search_time__ = (search_time / 1000) % 60; // секунд


	end_time = (unsigned int)clock(); // конечное время
	search_time = end_time - start_time; // искомое время в миллисекундах
	search_time_ = (search_time / (1000 * 60)); // минут
												//search_time__ = (search_time / 1000) % 60; // секунд

	size_t normalization_x = 0; // число частиц для нормировки гитограммы
	size_t normalization_r = 0; // число частиц для нормировки гитограммы

	size_t normalization_x_source = 0; // число частиц для нормировки гитограммы, урседеннной по детектору
	size_t normalization_r_source = 0; // число частиц для нормировки гитограммы, урседеннной по детектору


	size_t normalization_x_cyl1_in_source = 0; // число частиц для нормировки гитограммы
	size_t normalization_r_cyl1_in_source = 0; // число частиц для нормировки гитограммы, урседеннной по детектору


	size_t normalization_x_cyl1_in_source_positive = 0; // число частиц для нормировки гитограммы
	size_t normalization_r_cyl1_in_source_positive = 0; // число частиц для нормировки гитограммы, урседеннной по детектору


	size_t normalization_x_cyl1_in_source_zero = 0; // число частиц для нормировки гитограммы
	size_t normalization_r_cyl1_in_source_zero = 0; // число частиц для нормировки гитограммы, урседеннной по детектору


	size_t normalization_x_cyl1_in_source_negative = 0; // число частиц для нормировки гитограммы
	size_t normalization_r_cyl1_in_source_negative = 0; // число частиц для нормировки гитограммы, урседеннной по детектору



	size_t normalization_x_positive = 0; // число частиц для нормировки гитограммы
	size_t normalization_r_positive = 0; // число частиц для нормировки гитограммы

	size_t normalization_x_source_positive = 0; // число частиц для нормировки гитограммы, урседеннной по детектору
	size_t normalization_r_source_positive = 0; // число частиц для нормировки гитограммы, урседеннной по детектору





	size_t normalization_x_zero = 0; // число частиц для нормировки гитограммы
	size_t normalization_r_zero = 0; // число частиц для нормировки гитограммы

	size_t normalization_x_source_zero = 0; // число частиц для нормировки гитограммы, урседеннной по детектору
	size_t normalization_r_source_zero = 0; // число частиц для нормировки гитограммы, урседеннной по детектору




	size_t normalization_x_negative = 0; // число частиц для нормировки гитограммы
	size_t normalization_r_negative = 0; // число частиц для нормировки гитограммы

	size_t normalization_x_source_negative = 0; // число частиц для нормировки гитограммы, урседеннной по детектору
	size_t normalization_r_source_negative = 0; // число частиц для нормировки гитограммы, урседеннной по детектору






	size_t normalization_V_0 = 0; // число частиц для нормировки гитограммы

	size_t normalization_time = 0; // число частиц для нормировки гитограммы

	size_t normalization_V_0_out = 0; // число частиц для нормировки гитограммы

	size_t normalization_V_0_tube_out = 0; // число частиц для нормировки гитограммы

	size_t normalization_theta_in = 0; // число частиц для нормировки гитограммы


	size_t normalization_theta_out = 0; // число частиц для нормировки гитограммы


	size_t normalization_theta_out_ = 0; // число частиц для нормировки гитограммы


	size_t normalization_theta_in_ = 0; // число частиц для нормировки гитограммы


	size_t normalization_theta_in_out = 0; // число частиц для нормировки гитограммы


	size_t normalization_theta_in_out_ = 0; // число частиц для нормировки гитограммы

	for (size_t i = 0; i < arrlen(mass_histo_x_source); i = i + 1) {
		normalization_x_source = normalization_x_source + (size_t)mass_histo_x_source[i][0];
	}

	for (size_t i = 0; i < arrlen(mass_histo_r_source); i = i + 1) {
		normalization_r_source = normalization_r_source + (size_t)mass_histo_r_source[i][0];
	}




	for (size_t i = 0; i < arrlen(mass_histo_x); i = i + 1) {
		normalization_x = normalization_x + (size_t)mass_histo_x[i][0];
	}

	for (size_t i = 0; i < arrlen(mass_histo_r); i = i + 1) {
		normalization_r = normalization_r + (size_t)mass_histo_r[i][0];
	}





	for (size_t i = 0; i < arrlen(mass_histo_x_cyl1_in_source); i = i + 1) {
		normalization_x_cyl1_in_source = normalization_x_cyl1_in_source + (size_t)mass_histo_x_cyl1_in_source[i][0];
	}


	for (size_t i = 0; i < arrlen(mass_histo_r_cyl1_in_source); i = i + 1) {
		normalization_r_cyl1_in_source = normalization_r_cyl1_in_source + (size_t)mass_histo_r_cyl1_in_source[i][0];
	}




	for (size_t i = 0; i < arrlen(mass_histo_x_cyl1_in_source_positive); i = i + 1) {
		normalization_x_cyl1_in_source_positive = normalization_x_cyl1_in_source_positive + (size_t)mass_histo_x_cyl1_in_source_positive[i][0];
	}


	for (size_t i = 0; i < arrlen(mass_histo_r_cyl1_in_source_positive); i = i + 1) {
		normalization_r_cyl1_in_source_positive = normalization_r_cyl1_in_source_positive + (size_t)mass_histo_r_cyl1_in_source_positive[i][0];
	}





	for (size_t i = 0; i < arrlen(mass_histo_x_cyl1_in_source_zero); i = i + 1) {
		normalization_x_cyl1_in_source_zero = normalization_x_cyl1_in_source_zero + (size_t)mass_histo_x_cyl1_in_source_zero[i][0];
	}


	for (size_t i = 0; i < arrlen(mass_histo_r_cyl1_in_source_zero); i = i + 1) {
		normalization_r_cyl1_in_source_zero = normalization_r_cyl1_in_source_zero + (size_t)mass_histo_r_cyl1_in_source_zero[i][0];
	}



	for (size_t i = 0; i < arrlen(mass_histo_x_cyl1_in_source_negative); i = i + 1) {
		normalization_x_cyl1_in_source_negative = normalization_x_cyl1_in_source_negative + (size_t)mass_histo_x_cyl1_in_source_negative[i][0];
	}


	for (size_t i = 0; i < arrlen(mass_histo_r_cyl1_in_source_negative); i = i + 1) {
		normalization_r_cyl1_in_source_negative = normalization_r_cyl1_in_source_negative + (size_t)mass_histo_r_cyl1_in_source_negative[i][0];
	}





	//cout << normalization_x_cyl1_in_source << "!!!!!!!!" << normalization_r_cyl1_in_source << endl;


	for (size_t i = 0; i < arrlen(mass_histo_x_source_positive); i = i + 1) {
		normalization_x_source_positive = normalization_x_source_positive + (size_t)mass_histo_x_source_positive[i][0];
	}

	for (size_t i = 0; i < arrlen(mass_histo_r_source_positive); i = i + 1) {
		normalization_r_source_positive = normalization_r_source_positive + (size_t)mass_histo_r_source_positive[i][0];
	}


	for (size_t i = 0; i < arrlen(mass_histo_x_positive); i = i + 1) {
		normalization_x_positive = normalization_x_positive + (size_t)mass_histo_x_positive[i][0];
	}

	for (size_t i = 0; i < arrlen(mass_histo_r_positive); i = i + 1) {
		normalization_r_positive = normalization_r_positive + (size_t)mass_histo_r_positive[i][0];
	}









	for (size_t i = 0; i < arrlen(mass_histo_x_source_zero); i = i + 1) {
		normalization_x_source_zero = normalization_x_source_zero + (size_t)mass_histo_x_source_zero[i][0];
	}

	for (size_t i = 0; i < arrlen(mass_histo_r_source_zero); i = i + 1) {
		normalization_r_source_zero = normalization_r_source_zero + (size_t)mass_histo_r_source_zero[i][0];
	}


	for (size_t i = 0; i < arrlen(mass_histo_x_zero); i = i + 1) {
		normalization_x_zero = normalization_x_zero + (size_t)mass_histo_x_zero[i][0];
	}

	for (size_t i = 0; i < arrlen(mass_histo_r_zero); i = i + 1) {
		normalization_r_zero = normalization_r_zero + (size_t)mass_histo_r_zero[i][0];
	}









	for (size_t i = 0; i < arrlen(mass_histo_x_source_negative); i = i + 1) {
		normalization_x_source_negative = normalization_x_source_negative + (size_t)mass_histo_x_source_negative[i][0];
	}

	for (size_t i = 0; i < arrlen(mass_histo_r_source_negative); i = i + 1) {
		normalization_r_source_negative = normalization_r_source_negative + (size_t)mass_histo_r_source_negative[i][0];
	}


	for (size_t i = 0; i < arrlen(mass_histo_x_negative); i = i + 1) {
		normalization_x_negative = normalization_x_negative + (size_t)mass_histo_x_negative[i][0];
	}

	for (size_t i = 0; i < arrlen(mass_histo_r_negative); i = i + 1) {
		normalization_r_negative = normalization_r_negative + (size_t)mass_histo_r_negative[i][0];
	}










	for (size_t i = 0; i < arrlen(mass_histo_V_0); i = i + 1) {
		normalization_V_0 = normalization_V_0 + (size_t)mass_histo_V_0[i][0];
	}


	for (size_t i = 0; i < arrlen(mass_histo_time); i = i + 1) {
		normalization_time = normalization_time + (size_t)mass_histo_time[i][0];
	}

	for (size_t i = 0; i < arrlen(mass_histo_V_0_out); i = i + 1) {
		normalization_V_0_out = normalization_V_0_out + (size_t)mass_histo_V_0_out[i][0];
	}


	for (size_t i = 0; i < arrlen(mass_histo_V_0_tube_out); i = i + 1) {
		normalization_V_0_tube_out = normalization_V_0_tube_out + (size_t)mass_histo_V_0_tube_out[i][0];
	}



	for (size_t i = 0; i < arrlen(mass_histo_theta_in); i = i + 1) {
		normalization_theta_in = normalization_theta_in + (size_t)mass_histo_theta_in[i][0];
	}



	for (size_t i = 0; i < arrlen(mass_histo_theta_in_out); i = i + 1) {
		normalization_theta_in_out = normalization_theta_in_out + (size_t)mass_histo_theta_in_out[i][0];
	}


	for (size_t i = 0; i < arrlen(mass_histo_theta_in); i = i + 1) {
		normalization_theta_in_out_ = normalization_theta_in_out_ + (size_t)mass_histo_theta_in_out_[i][0];
	}



	for (size_t i = 0; i < arrlen(mass_histo_theta_out); i = i + 1) {
		normalization_theta_out = normalization_theta_out + (size_t)mass_histo_theta_out[i][0];
	}



	for (size_t i = 0; i < arrlen(mass_histo_theta_out_); i = i + 1) {
		normalization_theta_out_ = normalization_theta_out_ + (size_t)mass_histo_theta_out_[i][0];
	}



	for (size_t i = 0; i < arrlen(mass_histo_theta_in_); i = i + 1) {
		normalization_theta_in_ = normalization_theta_in_ + (size_t)mass_histo_theta_in_[i][0];
	}

	n_tube_y0_x0 = (size_t)mass_histo_r_source[0][0];





	//long double k1 = 0.0, k2=0.0,k3=0.0,k4=0.0 ;

	//long double phi_1_2_new = k1*phi_1_2_new_1 + *k2*phi_1_2_new_2 - k3*phi_1_2_new_3 - k4*phi_1_2_new_4;

	//long double phi_1_2_new = phi_1_2_new_1 + phi_1_2_new_2 - phi_1_2_new_3 - phi_1_2_new_4;




	long double phi_1_2_new = 0.0;


	cout << "Число щелей= " << multi_slot_nozzle << endl;

	cout << "Степень косинуса= " << n_cos_intensity << endl;

	cout << endl;

	if (n_cos_intensity == 1.0) { //-V550


		long double R1_1_temp = R1_1;
		long double R2_1_temp = R2_1;
		long double R3_1_temp = R3_1;


		long double R1_2_temp = R1_2;
		long double R2_2_temp = R2_2;
		long double R3_2_temp = R3_2;

		long double L_1_temp = L_1;

		if (fabs(R1_1) < epsilon) {
			
			R1_1_temp = epsilon;

		}

		if (fabs(R2_1) < epsilon) {

			R2_1_temp = epsilon;

		}

		if (fabs(R3_1) < epsilon) {

			R3_1_temp = epsilon;

		}





		if (fabs(R1_2) < epsilon) {

			R1_2_temp = epsilon;

		}

		if (fabs(R2_2) < epsilon) {

			R2_2_temp = epsilon;

		}

		if (fabs(R3_2) < epsilon) {

			R3_2_temp = epsilon;

		}



		if (fabs(L_1) < epsilon) {

			L_1_temp = epsilon;

		}


		cout << R1_1 << " " << R2_1 << " " << R3_1 << endl;
		cout << R1_2 << " " << R2_2 << " " << R3_2 << endl;
		cout << L_1 << endl;
		cout << endl;


		cout << R1_1_temp << " " << R2_1_temp << " " << R3_1_temp << endl;
		cout << R1_2_temp << " " << R2_2_temp << " " << R3_2_temp << endl;
		cout << L_1_temp << endl;
		cout << endl;

		if (multi_slot_nozzle == 1) {

			//phi_1_2_new = 0.0;

			//cout << phi_1_2 << endl;

			long double	r1 = max(R2_1_temp, R2_2_temp);
			long double r2 = max(R3_1_temp, R3_2_temp);
			long double r3 = max(R2_1_temp, R3_2_temp);
			long double r4 = max(R2_2_temp, R3_1_temp);


			//long double phi_1_2_new = (1.0 / (2.0*pow(r1, 2.0)))*(pow(L_1, 2.0) + pow(R2_1, 2.0) + pow(R2_2, 2.0) - pow(pow(pow(L_1, 2.0) + pow(R2_1, 2.0) + pow(R2_2, 2.0), 2.0) - 4.0*pow(R2_1*R2_2, 2.0), 1.0 / 2.0)) - (1.0 / (2.0*pow(r2, 2.0)))*(pow(L_1, 2.0) + pow(R3_1, 2.0) + pow(R3_2, 2.0) - pow(pow(pow(L_1, 2.0) + pow(R3_1, 2.0) + pow(R3_2, 2.0), 2.0) - 4.0*pow(R3_1*R3_2, 2.0), 1.0 / 2.0));

			//long double phi_1_2_new_1 = (1.0 / (2.0*pow(r1, 2.0)))*(pow(L_1, 2.0) + pow(R2_1, 2.0) + pow(R2_2, 2.0) - pow(pow(pow(L_1, 2.0) + pow(R2_1, 2.0) + pow(R2_2, 2.0), 2.0) - 4.0*pow(R2_1*R2_2, 2.0), 1.0 / 2.0));
			//long double phi_1_2_new_2 = (1.0 / (2.0*pow(r2, 2.0)))*(pow(L_1, 2.0) + pow(R3_1, 2.0) + pow(R3_2, 2.0) - pow(pow(pow(L_1, 2.0) + pow(R3_1, 2.0) + pow(R3_2, 2.0), 2.0) - 4.0*pow(R3_1*R3_2, 2.0), 1.0 / 2.0));
			//long double phi_1_2_new_3 = (1.0 / (2.0*pow(r3, 2.0)))*(pow(L_1, 2.0) + pow(R2_1, 2.0) + pow(R3_2, 2.0) - pow(pow(pow(L_1, 2.0) + pow(R2_1, 2.0) + pow(R3_2, 2.0), 2.0) - 4.0*pow(R2_1*R3_2, 2.0), 1.0 / 2.0));
			//long double phi_1_2_new_4 = (1.0 / (2.0*pow(r4, 2.0)))*(pow(L_1, 2.0) + pow(R2_2, 2.0) + pow(R3_1, 2.0) - pow(pow(pow(L_1, 2.0) + pow(R2_2, 2.0) + pow(R3_1, 2.0), 2.0) - 4.0*pow(R2_2*R3_1, 2.0), 1.0 / 2.0));


			long double phi_12_34 = (1.0 / (2.0*pow(R2_1_temp, 2.0)))*(pow(L_1_temp, 2.0) + pow(R2_1_temp, 2.0) + pow(R2_2_temp, 2.0) - pow(pow(pow(L_1_temp, 2.0) + pow(R2_1_temp, 2.0) + pow(R2_2_temp, 2.0), 2.0) - 4.0*pow(R2_1_temp*R2_2_temp, 2.0), 1.0 / 2.0));
			long double phi_12_4 = (1.0 / (2.0*pow(R2_1_temp, 2.0)))*(pow(L_1_temp, 2.0) + pow(R2_1_temp, 2.0) + pow(R3_2_temp, 2.0) - pow(pow(pow(L_1_temp, 2.0) + pow(R2_1_temp, 2.0) + pow(R3_2_temp, 2.0), 2.0) - 4.0*pow(R2_1_temp*R3_2_temp, 2.0), 1.0 / 2.0));
			long double phi_1_34 = (1.0 / (2.0*pow(R3_1_temp, 2.0)))*(pow(L_1_temp, 2.0) + pow(R3_1_temp, 2.0) + pow(R2_2_temp, 2.0) - pow(pow(pow(L_1_temp, 2.0) + pow(R3_1_temp, 2.0) + pow(R2_2_temp, 2.0), 2.0) - 4.0*pow(R3_1_temp*R2_2_temp, 2.0), 1.0 / 2.0));
			long double phi_1_4 = (1.0 / (2.0*pow(R3_1_temp, 2.0)))*(pow(L_1_temp, 2.0) + pow(R3_1_temp, 2.0) + pow(R3_2_temp, 2.0) - pow(pow(pow(L_1_temp, 2.0) + pow(R3_1_temp, 2.0) + pow(R3_2_temp, 2.0), 2.0) - 4.0*pow(R3_1_temp*R3_2_temp, 2.0), 1.0 / 2.0));

			cout << "элементарные угловые коэффициенты" << endl;

			cout << phi_12_34 << endl;
			cout << phi_12_4 << endl;
			cout << phi_1_34 << endl;
			cout << phi_1_4 << endl;






			phi_1_2_new = (pow(R2_1_temp, 2.0) / (pow(R2_1_temp, 2.0) - pow(R3_1_temp, 2.0)))*(phi_12_34 - phi_12_4) - (pow(R3_1_temp, 2.0) / (pow(R2_1_temp, 2.0) - pow(R3_1_temp, 2.0)))*(phi_1_34 - phi_1_4);
			phi_1_2 = phi_1_2_new;

			long double phi_1_2_new_temp_1 = 0.0;
			long double phi_1_2_new_temp_2 = 0.0;




			/*


			phi_1_2_new_temp_1 = angular_coefficient_calculation(0.0, L_1, R1_1, R2_1, R3_1, R1_2, R2_2, R3_2, N_r_angular, N_phi_angular, n_cos_intensity);
			phi_1_2_new_temp_2 = angular_coefficient_calculation_monte_carlo(0.0, L_1, R1_1, R2_1, R3_1, R1_2, R2_2, R3_2, N_monte_carlo_cos_intensity, n_cos_intensity);
			cout << phi_1_2_new_temp_1 << endl;

			cout << phi_1_2_new_temp_2 << endl;

			cout << (phi_1_2_new_temp_1 + phi_1_2_new_temp_2) / 2.0 << endl;
			//cout << n_cos_intensity << endl;

			 */


		}

		if (multi_slot_nozzle > 1) {


			phi_1_2_new = 0.0;

			long double delta_nozzle = fabs(R2_1_temp - R3_1_temp) / (2.0*multi_slot_nozzle - 1.0);



			long double R_min = 0.0; // одномерный массив входных параметров
			long double R_max = 0.0; // одномерный массив входных параметров
			long double S = 0.0; // одномерный массив входных параметров
			long double S_summ_all = 0.0;


			long double	r1 = 0.0;
			long double r2 = 0.0;
			long double r3 = 0.0;
			long double r4 = 0.0;

			long double phi_12_34 = 0.0;
			long double phi_12_4 = 0.0;
			long double phi_1_34 = 0.0;
			long double phi_1_4 = 0.0;



			for (size_t i = 0; i < multi_slot_nozzle; i = i + 1) {


				R_min = R3_1_temp + 2.0*delta_nozzle*i;
				R_max = R3_1_temp + delta_nozzle + 2.0*delta_nozzle*i;
				S = M_PI * (pow(R_max, 2.0) - pow(R_min, 2.0));

				S_summ_all = S_summ_all + S;

				cout << endl;

				//	cout << "R_min= " << R_min << endl;

				//	cout << "R_max= " << R_max << endl;

				//	cout << "S= " << S << endl;

				//	cout << "S_summ_all= " << S_summ_all << endl;


					//cout << phi_1_2 << endl;

				r1 = max(R_max, R2_2_temp);
				r2 = max(R_min, R3_2_temp);
				r3 = max(R_max, R3_2_temp);
				r4 = max(R2_2_temp, R_min);


				//long double phi_1_2_new = (1.0 / (2.0*pow(r1, 2.0)))*(pow(L_1, 2.0) + pow(R2_1, 2.0) + pow(R2_2, 2.0) - pow(pow(pow(L_1, 2.0) + pow(R2_1, 2.0) + pow(R2_2, 2.0), 2.0) - 4.0*pow(R2_1*R2_2, 2.0), 1.0 / 2.0)) - (1.0 / (2.0*pow(r2, 2.0)))*(pow(L_1, 2.0) + pow(R3_1, 2.0) + pow(R3_2, 2.0) - pow(pow(pow(L_1, 2.0) + pow(R3_1, 2.0) + pow(R3_2, 2.0), 2.0) - 4.0*pow(R3_1*R3_2, 2.0), 1.0 / 2.0));

				//long double phi_1_2_new_1 = (1.0 / (2.0*pow(r1, 2.0)))*(pow(L_1, 2.0) + pow(R2_1, 2.0) + pow(R2_2, 2.0) - pow(pow(pow(L_1, 2.0) + pow(R2_1, 2.0) + pow(R2_2, 2.0), 2.0) - 4.0*pow(R2_1*R2_2, 2.0), 1.0 / 2.0));
				//long double phi_1_2_new_2 = (1.0 / (2.0*pow(r2, 2.0)))*(pow(L_1, 2.0) + pow(R3_1, 2.0) + pow(R3_2, 2.0) - pow(pow(pow(L_1, 2.0) + pow(R3_1, 2.0) + pow(R3_2, 2.0), 2.0) - 4.0*pow(R3_1*R3_2, 2.0), 1.0 / 2.0));
				//long double phi_1_2_new_3 = (1.0 / (2.0*pow(r3, 2.0)))*(pow(L_1, 2.0) + pow(R2_1, 2.0) + pow(R3_2, 2.0) - pow(pow(pow(L_1, 2.0) + pow(R2_1, 2.0) + pow(R3_2, 2.0), 2.0) - 4.0*pow(R2_1*R3_2, 2.0), 1.0 / 2.0));
				//long double phi_1_2_new_4 = (1.0 / (2.0*pow(r4, 2.0)))*(pow(L_1, 2.0) + pow(R2_2, 2.0) + pow(R3_1, 2.0) - pow(pow(pow(L_1, 2.0) + pow(R2_2, 2.0) + pow(R3_1, 2.0), 2.0) - 4.0*pow(R2_2*R3_1, 2.0), 1.0 / 2.0));


				phi_12_34 = (1.0 / (2.0*pow(R_max, 2.0)))*(pow(L_1_temp, 2.0) + pow(R_max, 2.0) + pow(R2_2_temp, 2.0) - pow(pow(pow(L_1_temp, 2.0) + pow(R_max, 2.0) + pow(R2_2_temp, 2.0), 2.0) - 4.0*pow(R_max*R2_2_temp, 2.0), 1.0 / 2.0));
				phi_12_4 = (1.0 / (2.0*pow(R_max, 2.0)))*(pow(L_1_temp, 2.0) + pow(R_max, 2.0) + pow(R3_2_temp, 2.0) - pow(pow(pow(L_1_temp, 2.0) + pow(R_max, 2.0) + pow(R3_2_temp, 2.0), 2.0) - 4.0*pow(R_max*R3_2_temp, 2.0), 1.0 / 2.0));
				phi_1_34 = (1.0 / (2.0*pow(R_min, 2.0)))*(pow(L_1_temp, 2.0) + pow(R_min, 2.0) + pow(R2_2_temp, 2.0) - pow(pow(pow(L_1_temp, 2.0) + pow(R_min, 2.0) + pow(R2_2_temp, 2.0), 2.0) - 4.0*pow(R_min*R2_2_temp, 2.0), 1.0 / 2.0));
				phi_1_4 = (1.0 / (2.0*pow(R_min, 2.0)))*(pow(L_1_temp, 2.0) + pow(R_min, 2.0) + pow(R3_2_temp, 2.0) - pow(pow(pow(L_1_temp, 2.0) + pow(R_min, 2.0) + pow(R3_2_temp, 2.0), 2.0) - 4.0*pow(R_min*R3_2_temp, 2.0), 1.0 / 2.0));








				phi_1_2_new = phi_1_2_new + S * ((pow(R_max, 2.0) / (pow(R_max, 2.0) - pow(R_min, 2.0)))*(phi_12_34 - phi_12_4) - (pow(R_min, 2.0) / (pow(R_max, 2.0) - pow(R_min, 2.0)))*(phi_1_34 - phi_1_4));



















			}
			phi_1_2_new = phi_1_2_new / S_summ_all;

			phi_1_2 = phi_1_2_new;


		}


	}
	else {




		if (multi_slot_nozzle == 1) {


			long double phi_1_2_new = 0.0;

			long double phi_1_2_new_temp_1 = 0.0;
			long double phi_1_2_new_temp_2 = 0.0;

			phi_1_2_new_temp_1 = angular_coefficient_calculation(0.0, L_1, R1_1, R2_1, R3_1, R1_2, R2_2, R3_2, N_r_angular, N_phi_angular, n_cos_intensity);

			//	cout << phi_1_2_new_temp_1 << endl;
			phi_1_2_new_temp_2 = angular_coefficient_calculation_monte_carlo(0.0, L_1, R1_1, R2_1, R3_1, R1_2, R2_2, R3_2, N_monte_carlo_cos_intensity, n_cos_intensity);
			//	cout << phi_1_2_new_temp_2 << endl;
			phi_1_2_new = (phi_1_2_new_temp_1 + phi_1_2_new_temp_2) / 2.0;
			//	cout << phi_1_2_new << endl;
			phi_1_2 = phi_1_2_new;


			printf("Интегральный угловой коэффициент для цилиндров №№ 1-2 = %.10Le 1/(число частиц вышло из цилиндра № 1)\n", phi_1_2_new_temp_1);
			printf("Интегральный угловой коэффициент для цилиндров №№ 1-2 = %.10Le 1/(число частиц вышло из цилиндра № 1)\n", phi_1_2_new_temp_2);
			printf("Интегральный угловой коэффициент для цилиндров №№ 1-2 = %.10Le 1/(число частиц вышло из цилиндра № 1)\n", phi_1_2_new);




		}

		if (multi_slot_nozzle > 1) {


			long double phi_1_2_new = 0.0;

			long double phi_1_2_new_temp_1 = 0.0;
			long double phi_1_2_new_temp_2 = 0.0;

			long double delta_nozzle = fabs(R2_1 - R3_1) / (2.0*multi_slot_nozzle - 1.0);



			long double R_min = 0.0; // одномерный массив входных параметров
			long double R_max = 0.0; // одномерный массив входных параметров
			long double S = 0.0; // одномерный массив входных параметров
			long double S_summ_all = 0.0;

			for (size_t i = 0; i < multi_slot_nozzle; i = i + 1) {
				R_min = R3_1 + 2.0*delta_nozzle*i;
				R_max = R3_1 + delta_nozzle + 2.0*delta_nozzle*i;
				S = M_PI * (pow(R_max, 2.0) - pow(R_min, 2.0));

				phi_1_2_new_temp_1 = phi_1_2_new_temp_1 + S * angular_coefficient_calculation(0.0, L_1, R1_1, R_max, R_min, R1_2, R2_2, R3_2, N_r_angular, N_phi_angular, n_cos_intensity);


				phi_1_2_new_temp_2 = phi_1_2_new_temp_2 + S * angular_coefficient_calculation_monte_carlo(0.0, L_1, R1_1, R_max, R_min, R1_2, R2_2, R3_2, N_monte_carlo_cos_intensity, n_cos_intensity);


				S_summ_all = S_summ_all + S;


			}

			phi_1_2_new_temp_1 = phi_1_2_new_temp_1 / S_summ_all;

			phi_1_2_new_temp_2 = phi_1_2_new_temp_2 / S_summ_all;


			//cout << phi_1_2_new_temp_1 << endl;

			//cout << phi_1_2_new_temp_2 << endl;
			phi_1_2_new = (phi_1_2_new_temp_1 + phi_1_2_new_temp_2) / 2.0;
			//cout << phi_1_2_new << endl;
			phi_1_2 = phi_1_2_new;


			printf("Интегральный угловой коэффициент для цилиндров №№ 1-2 = %.10Le 1/(число частиц вышло из цилиндра № 1)\n", phi_1_2_new_temp_1);
			printf("Интегральный угловой коэффициент для цилиндров №№ 1-2 = %.10Le 1/(число частиц вышло из цилиндра № 1)\n", phi_1_2_new_temp_2);
			printf("Интегральный угловой коэффициент для цилиндров №№ 1-2 = %.10Le 1/(число частиц вышло из цилиндра № 1)\n", phi_1_2_new);




		}
	}




	/*
	
	
	

	for (size_t count_row = 0; count_row < arrlen(mass_histo_x_source_P_z); count_row++) {

		cout << count_row << endl;
		cout << mass_histo_x_source_positive[count_row][0] << endl;
		cout << endl;

		//	mass_histo_x_source_P_z[count_row][0] = (mass_histo_x_source_positive[count_row][0] - mass_histo_x_source_negative[count_row][0]) / (mass_histo_x_source_positive[count_row][0] + mass_histo_x_source_negative[count_row][0]); // превый столбец 0, в начале число частиц в каждом бине ноль


	}

	*/


	for (size_t count_row = 0; count_row < arrlen(mass_histo_x_source_P_z); count_row++) {

		if (fabs(mass_histo_x_source_positive[count_row][0] + mass_histo_x_source_negative[count_row][0]) <= epsilon) {

			mass_histo_x_source_P_z[count_row][0] = 0.0;
		}
		else {

			mass_histo_x_source_P_z[count_row][0] = (mass_histo_x_source_positive[count_row][0] - mass_histo_x_source_negative[count_row][0]) / (mass_histo_x_source_positive[count_row][0] + mass_histo_x_source_zero[count_row][0] + mass_histo_x_source_negative[count_row][0]); // превый столбец 0, в начале число частиц в каждом бине ноль
		}

	}



	for (size_t count_row = 0; count_row < arrlen(mass_histo_x_source_P_zz); count_row++) {

		if (fabs(mass_histo_x_source_positive[count_row][0] + mass_histo_x_source_zero[count_row][0] + mass_histo_x_source_negative[count_row][0]) <= epsilon) {

			mass_histo_x_source_P_zz[count_row][0] = 0.0;

		}
		else {



			mass_histo_x_source_P_zz[count_row][0] = 1.0 - 3.0*mass_histo_x_source_zero[count_row][0] / (mass_histo_x_source_positive[count_row][0] + mass_histo_x_source_zero[count_row][0] + mass_histo_x_source_negative[count_row][0]); // превый столбец 0, в начале число частиц в каждом бине ноль

		}

	}





	for (size_t count_row = 0; count_row < arrlen(mass_histo_r_source_P_z); count_row++) {

		mass_histo_r_source_P_z[count_row][0] = (mass_histo_r_source_positive[count_row][0] - mass_histo_r_source_negative[count_row][0]) / (mass_histo_r_source_positive[count_row][0] + mass_histo_x_source_zero[count_row][0] + mass_histo_r_source_negative[count_row][0]); // превый столбец 0, в начале число частиц в каждом бине ноль


	}



	for (size_t count_row = 0; count_row < arrlen(mass_histo_r_source_P_zz); count_row++) {

		mass_histo_r_source_P_zz[count_row][0] = 1.0 - 3.0*mass_histo_r_source_zero[count_row][0] / (mass_histo_r_source_positive[count_row][0] + mass_histo_r_source_zero[count_row][0] + mass_histo_r_source_negative[count_row][0]); // превый столбец 0, в начале число частиц в каждом бине ноль


	}







	for (size_t count_row = 0; count_row < arrlen(mass_histo_x_P_z); count_row++) {

		if (fabs(mass_histo_x_positive[count_row][0] + mass_histo_x_negative[count_row][0]) <= epsilon) {

			mass_histo_x_P_z[count_row][0] = 0.0;
		}
		else {

			mass_histo_x_P_z[count_row][0] = (mass_histo_x_positive[count_row][0] - mass_histo_x_negative[count_row][0]) / (mass_histo_x_positive[count_row][0] + mass_histo_x_source_zero[count_row][0] + mass_histo_x_negative[count_row][0]); // превый столбец 0, в начале число частиц в каждом бине ноль
		}

	}



	for (size_t count_row = 0; count_row < arrlen(mass_histo_x_P_zz); count_row++) {

		if (fabs(mass_histo_x_positive[count_row][0] + mass_histo_x_zero[count_row][0] + mass_histo_x_negative[count_row][0]) <= epsilon) {

			mass_histo_x_P_zz[count_row][0] = 0.0;

		}
		else {



			mass_histo_x_P_zz[count_row][0] = 1.0 - 3.0*mass_histo_x_zero[count_row][0] / (mass_histo_x_positive[count_row][0] + mass_histo_x_zero[count_row][0] + mass_histo_x_negative[count_row][0]); // превый столбец 0, в начале число частиц в каждом бине ноль

		}

	}





	for (size_t count_row = 0; count_row < arrlen(mass_histo_r_P_z); count_row++) {

		mass_histo_r_P_z[count_row][0] = (mass_histo_r_positive[count_row][0] - mass_histo_r_negative[count_row][0]) / (mass_histo_r_positive[count_row][0] + mass_histo_x_source_zero[count_row][0] + mass_histo_r_negative[count_row][0]); // превый столбец 0, в начале число частиц в каждом бине ноль


	}



	for (size_t count_row = 0; count_row < arrlen(mass_histo_r_P_zz); count_row++) {

		mass_histo_r_P_zz[count_row][0] = 1.0 - 3.0*mass_histo_r_zero[count_row][0] / (mass_histo_r_positive[count_row][0] + mass_histo_r_zero[count_row][0] + mass_histo_r_negative[count_row][0]); // превый столбец 0, в начале число частиц в каждом бине ноль


	}














	//long double phi_1_2_new_1 = (1.0 / (2.0*pow(r1, 2.0)))*(pow(L_1, 2.0) + pow(R2_1, 2.0) + pow(R2_2, 2.0) - pow(pow(pow(L_1, 2.0) + pow(R2_1, 2.0) + pow(R2_2, 2.0), 2.0) - 4.0*pow(R2_1*R2_2, 2.0), 1.0 / 2.0)) - (1.0 / (2.0*pow(r1, 2.0)))*(pow(L_1, 2.0) + pow(R2_1, 2.0) + pow(R3_2, 2.0) - pow(pow(pow(L_1, 2.0) + pow(R2_1, 2.0) + pow(R3_2, 2.0), 2.0) - 4.0*pow(R2_1*R3_2, 2.0), 1.0 / 2.0))-(1.0 / (2.0*pow(r2, 2.0)))*(pow(L_1, 2.0) + pow(R2_2, 2.0) + pow(R3_1, 2.0) - pow(pow(pow(L_1, 2.0) + pow(R2_2, 2.0) + pow(R3_1, 2.0), 2.0) - 4.0*pow(R2_2*R3_1, 2.0), 1.0 / 2.0)) - (1.0 / (2.0*pow(R2_1, 2.0)))*(pow(L_1, 2.0) + pow(R2_1, 2.0) + pow(R2_2, 2.0) - pow(pow(pow(L_1, 2.0) + pow(R2_1, 2.0) + pow(R2_2, 2.0), 2.0) - 4.0*pow(R2_1*R2_2, 2.0), 1.0 / 2.0));

	//phi_1_2_new = ((n_cos_intensity+1.0)/2.0)*(pow(R2_1, 2.0) / (pow(R2_1, 2.0) - pow(R3_1, 2.0)))*(phi_12_34 - phi_12_4) - (pow(R3_1, 2.0) / (pow(R2_1, 2.0) - pow(R3_1, 2.0)))*(phi_1_34 - phi_1_4);

	//phi_1_2 = phi_1_2_new;

	/*



	if (n_cos_intensity == 1) {
		cout << angular_coefficient_calculation(0.0, L_1, R1_1, R2_1, R3_1, R1_2, R2_2, R3_2, N_r_angular, N_phi_angular, n_cos_intensity) << endl;

	cout << angular_coefficient_calculation_monte_carlo(0.0, L_1, R1_1, R2_1, R3_1, R1_2, R2_2, R3_2, N_monte_carlo_cos_intensity, n_cos_intensity) << endl;
	//cout << n_cos_intensity << endl;
	}


   */
	printf("Интегральный угловой коэффициент для цилиндров №№ 1-2 = %.10Le 1/(число частиц вышло из цилиндра № 1)\n", phi_1_2);
	printf("Интегральный угловой коэффициент для цилиндров №№ 1-2 = %.10Le 1/(число частиц вышло из цилиндра № 1)\n", phi_1_2_new);










	out_txt("out.txt", mass_histo_x, mass_histo_r, start_time, end_time, R1_1, R2_1, R3_1, L_1, V_0, R1_2, R2_2, R3_2, L_2, R1_3, R2_3, R3_3, L_3, R1_4, R2_4, R3_4, L_4, R1_5, R2_5, R3_5, L_5, R1_6, R2_6, R3_6, L_6, R1_7, R2_7, R3_7, L_7, R1_8, R2_8, R3_8, N, N_histo, R, b1_left, b1_surface, b1_right, b2_left, b2_surface, b2_right, b3_left, b3_surface, b3_right, b4_left, b4_surface, b4_right, b5_left, b5_surface, b5_right, b6_left, b6_surface, b6_right, b7_left, b7_surface, b7_right, N_on, N_off, N1_1, N2_1, N3_1, N4_1, N5_1, N6_1, N7_1, N1_2, N2_2, N3_2, N4_2, N5_2, N6_2, N7_2, N1_3, N2_3, N3_3, N4_3, N5_3, N6_3, N7_3, N1_4, N2_4, N3_4, N4_4, N5_4, N6_4, N7_4, N1_5, N2_5, N3_5, N4_5, N5_5, N6_5, N7_5, N1_6, N2_6, N3_6, N4_6, N5_6, N6_6, N7_6, N1_7, N2_7, N3_7, N4_7, N5_7, N6_7, N7_7, n1, n2, n3, n4, n5, n6, n7, n_travel, t,
		theta1_diffusion_left, theta1_diffusion_surface, theta1_diffusion_right, theta2_diffusion_left, theta2_diffusion_surface, theta2_diffusion_right, theta3_diffusion_left, theta3_diffusion_surface, theta3_diffusion_right, theta4_diffusion_left, theta4_diffusion_surface, theta4_diffusion_right, theta5_diffusion_left, theta5_diffusion_surface, theta5_diffusion_right, theta6_diffusion_left, theta6_diffusion_surface, theta6_diffusion_right, theta7_diffusion_left, theta7_diffusion_surface, theta7_diffusion_right, R_source, N_histo_source, normalization_x, normalization_r, x_0_source, z0_mag1, L_mag1, z0_mag2, L_mag2, z0_mag3, L_mag3, z0_mag4, L_mag4, z0_mag5, L_mag5, z0_mag6, L_mag6, z0_mag7, L_mag7, B1_max_initial, B2_max_initial, B3_max_initial, B4_max_initial, B5_max_initial, B6_max_initial, B7_max_initial, r1_mag_max_initial, r2_mag_max_initial, r3_mag_max_initial, r4_mag_max_initial, r5_mag_max_initial, r6_mag_max_initial, r7_mag_max_initial, mu_core_particle, m_particle, on_off_mag_1, on_off_mag_2, on_off_mag_3, on_off_mag_4, on_off_mag_5, on_off_mag_6, on_off_mag_7, B_critical, mu_electron_particle, J_particle, I_particle, mu_core_particle, m_J, m_F, r1_mag_max_final, r2_mag_max_final, r3_mag_max_final, r4_mag_max_final, r5_mag_max_final, r6_mag_max_final, r7_mag_max_final, N_mag_partitions, particle_mode, temp_beam, flaq_Maxwell, a_V_0, b_V_0, N_histo_V_0, N_histo_theta_in,
		flaq_Maxwell_mode, average_peak, n_mag_1_in, n_mag_1_absorption, n_mag_1_out, n_mag_2_in, n_mag_2_absorption, n_mag_2_out, n_mag_3_in, n_mag_3_absorption, n_mag_3_out, n_mag_4_in, n_mag_4_absorption, n_mag_4_out, n_mag_5_in, n_mag_5_absorption, n_mag_5_out, n_mag_6_in, n_mag_6_absorption, n_mag_6_out, n_mag_7_in, n_mag_7_absorption, n_mag_7_out, n_tube_y0_x0, phi_1_2, flaq_angular_coefficient, N_CYL_partitions, N_r_angular, N_phi_angular, n_cos_intensity);

	out_txt("out_cyl1_in_source.txt", mass_histo_x_cyl1_in_source, mass_histo_r_cyl1_in_source, start_time, end_time, R1_1, R2_1, R3_1, L_1, V_0, R1_2, R2_2, R3_2, L_2, R1_3, R2_3, R3_3, L_3, R1_4, R2_4, R3_4, L_4, R1_5, R2_5, R3_5, L_5, R1_6, R2_6, R3_6, L_6, R1_7, R2_7, R3_7, L_7, R1_8, R2_8, R3_8, N, N_histo, R, b1_left, b1_surface, b1_right, b2_left, b2_surface, b2_right, b3_left, b3_surface, b3_right, b4_left, b4_surface, b4_right, b5_left, b5_surface, b5_right, b6_left, b6_surface, b6_right, b7_left, b7_surface, b7_right, N_on, N_off, N1_1, N2_1, N3_1, N4_1, N5_1, N6_1, N7_1, N1_2, N2_2, N3_2, N4_2, N5_2, N6_2, N7_2, N1_3, N2_3, N3_3, N4_3, N5_3, N6_3, N7_3, N1_4, N2_4, N3_4, N4_4, N5_4, N6_4, N7_4, N1_5, N2_5, N3_5, N4_5, N5_5, N6_5, N7_5, N1_6, N2_6, N3_6, N4_6, N5_6, N6_6, N7_6, N1_7, N2_7, N3_7, N4_7, N5_7, N6_7, N7_7, n1, n2, n3, n4, n5, n6, n7, n_travel, t,
		theta1_diffusion_left, theta1_diffusion_surface, theta1_diffusion_right, theta2_diffusion_left, theta2_diffusion_surface, theta2_diffusion_right, theta3_diffusion_left, theta3_diffusion_surface, theta3_diffusion_right, theta4_diffusion_left, theta4_diffusion_surface, theta4_diffusion_right, theta5_diffusion_left, theta5_diffusion_surface, theta5_diffusion_right, theta6_diffusion_left, theta6_diffusion_surface, theta6_diffusion_right, theta7_diffusion_left, theta7_diffusion_surface, theta7_diffusion_right, R_source, N_histo_source, normalization_x_cyl1_in_source, normalization_r_cyl1_in_source, x_0_source, z0_mag1, L_mag1, z0_mag2, L_mag2, z0_mag3, L_mag3, z0_mag4, L_mag4, z0_mag5, L_mag5, z0_mag6, L_mag6, z0_mag7, L_mag7, B1_max_initial, B2_max_initial, B3_max_initial, B4_max_initial, B5_max_initial, B6_max_initial, B7_max_initial, r1_mag_max_initial, r2_mag_max_initial, r3_mag_max_initial, r4_mag_max_initial, r5_mag_max_initial, r6_mag_max_initial, r7_mag_max_initial, mu_core_particle, m_particle, on_off_mag_1, on_off_mag_2, on_off_mag_3, on_off_mag_4, on_off_mag_5, on_off_mag_6, on_off_mag_7, B_critical, mu_electron_particle, J_particle, I_particle, mu_core_particle, m_J, m_F, r1_mag_max_final, r2_mag_max_final, r3_mag_max_final, r4_mag_max_final, r5_mag_max_final, r6_mag_max_final, r7_mag_max_final, N_mag_partitions, particle_mode,
		temp_beam, flaq_Maxwell, a_V_0, b_V_0, N_histo_V_0, N_histo_theta_in, flaq_Maxwell_mode, average_peak, n_mag_1_in, n_mag_1_absorption, n_mag_1_out, n_mag_2_in, n_mag_2_absorption, n_mag_2_out, n_mag_3_in, n_mag_3_absorption, n_mag_3_out, n_mag_4_in, n_mag_4_absorption, n_mag_4_out, n_mag_5_in, n_mag_5_absorption, n_mag_5_out, n_mag_6_in, n_mag_6_absorption, n_mag_6_out, n_mag_7_in, n_mag_7_absorption, n_mag_7_out, n_tube_y0_x0, phi_1_2, flaq_angular_coefficient, N_CYL_partitions, N_r_angular, N_phi_angular, n_cos_intensity);


	out_txt("out_cyl1_in_source_positive.txt", mass_histo_x_cyl1_in_source_positive, mass_histo_r_cyl1_in_source_positive, start_time, end_time, R1_1, R2_1, R3_1, L_1, V_0, R1_2, R2_2, R3_2, L_2, R1_3, R2_3, R3_3, L_3, R1_4, R2_4, R3_4, L_4, R1_5, R2_5, R3_5, L_5, R1_6, R2_6, R3_6, L_6, R1_7, R2_7, R3_7, L_7, R1_8, R2_8, R3_8, N, N_histo, R, b1_left, b1_surface, b1_right, b2_left, b2_surface, b2_right, b3_left, b3_surface, b3_right, b4_left, b4_surface, b4_right, b5_left, b5_surface, b5_right, b6_left, b6_surface, b6_right, b7_left, b7_surface, b7_right, N_on, N_off, N1_1, N2_1, N3_1, N4_1, N5_1, N6_1, N7_1, N1_2, N2_2, N3_2, N4_2, N5_2, N6_2, N7_2, N1_3, N2_3, N3_3, N4_3, N5_3, N6_3, N7_3, N1_4, N2_4, N3_4, N4_4, N5_4, N6_4, N7_4, N1_5, N2_5, N3_5, N4_5, N5_5, N6_5, N7_5, N1_6, N2_6, N3_6, N4_6, N5_6, N6_6, N7_6, N1_7, N2_7, N3_7, N4_7, N5_7, N6_7, N7_7, n1, n2, n3, n4, n5, n6, n7, n_travel, t, theta1_diffusion_left, theta1_diffusion_surface, theta1_diffusion_right, theta2_diffusion_left, theta2_diffusion_surface, theta2_diffusion_right, theta3_diffusion_left, theta3_diffusion_surface, theta3_diffusion_right, theta4_diffusion_left, theta4_diffusion_surface, theta4_diffusion_right, theta5_diffusion_left, theta5_diffusion_surface, theta5_diffusion_right, theta6_diffusion_left, theta6_diffusion_surface, theta6_diffusion_right, theta7_diffusion_left, theta7_diffusion_surface, theta7_diffusion_right,
		R_source, N_histo_source, normalization_x_cyl1_in_source, normalization_r_cyl1_in_source, x_0_source, z0_mag1, L_mag1, z0_mag2, L_mag2, z0_mag3, L_mag3, z0_mag4, L_mag4, z0_mag5, L_mag5, z0_mag6, L_mag6, z0_mag7, L_mag7, B1_max_initial, B2_max_initial, B3_max_initial, B4_max_initial, B5_max_initial, B6_max_initial, B7_max_initial, r1_mag_max_initial, r2_mag_max_initial, r3_mag_max_initial, r4_mag_max_initial, r5_mag_max_initial, r6_mag_max_initial, r7_mag_max_initial, mu_core_particle, m_particle, on_off_mag_1, on_off_mag_2, on_off_mag_3, on_off_mag_4, on_off_mag_5, on_off_mag_6, on_off_mag_7, B_critical, mu_electron_particle, J_particle, I_particle, mu_core_particle, m_J, m_F, r1_mag_max_final, r2_mag_max_final, r3_mag_max_final, r4_mag_max_final, r5_mag_max_final, r6_mag_max_final, r7_mag_max_final, N_mag_partitions,
		particle_mode, temp_beam, flaq_Maxwell, a_V_0, b_V_0, N_histo_V_0, N_histo_theta_in, flaq_Maxwell_mode, average_peak, n_mag_1_in, n_mag_1_absorption, n_mag_1_out, n_mag_2_in, n_mag_2_absorption, n_mag_2_out, n_mag_3_in, n_mag_3_absorption, n_mag_3_out, n_mag_4_in, n_mag_4_absorption, n_mag_4_out, n_mag_5_in, n_mag_5_absorption, n_mag_5_out, n_mag_6_in, n_mag_6_absorption, n_mag_6_out, n_mag_7_in, n_mag_7_absorption, n_mag_7_out, n_tube_y0_x0, phi_1_2, flaq_angular_coefficient, N_CYL_partitions, N_r_angular, N_phi_angular, n_cos_intensity);

	out_txt("out_cyl1_in_source_zero.txt", mass_histo_x_cyl1_in_source_zero, mass_histo_r_cyl1_in_source_zero, start_time, end_time, R1_1, R2_1, R3_1, L_1, V_0, R1_2, R2_2, R3_2, L_2, R1_3, R2_3, R3_3, L_3, R1_4, R2_4, R3_4, L_4, R1_5, R2_5, R3_5, L_5, R1_6, R2_6, R3_6, L_6, R1_7, R2_7, R3_7, L_7, R1_8, R2_8, R3_8, N, N_histo, R, b1_left, b1_surface, b1_right, b2_left, b2_surface, b2_right, b3_left, b3_surface, b3_right, b4_left, b4_surface, b4_right, b5_left, b5_surface, b5_right, b6_left, b6_surface, b6_right, b7_left, b7_surface, b7_right, N_on, N_off, N1_1, N2_1, N3_1, N4_1, N5_1, N6_1, N7_1, N1_2, N2_2, N3_2, N4_2, N5_2, N6_2, N7_2, N1_3, N2_3, N3_3, N4_3, N5_3, N6_3, N7_3, N1_4, N2_4, N3_4, N4_4, N5_4, N6_4, N7_4, N1_5, N2_5, N3_5, N4_5, N5_5, N6_5, N7_5, N1_6, N2_6, N3_6, N4_6, N5_6, N6_6, N7_6, N1_7, N2_7, N3_7, N4_7, N5_7, N6_7, N7_7, n1, n2, n3, n4, n5, n6, n7, n_travel, t,
		theta1_diffusion_left, theta1_diffusion_surface, theta1_diffusion_right, theta2_diffusion_left, theta2_diffusion_surface, theta2_diffusion_right, theta3_diffusion_left, theta3_diffusion_surface, theta3_diffusion_right, theta4_diffusion_left, theta4_diffusion_surface, theta4_diffusion_right, theta5_diffusion_left, theta5_diffusion_surface, theta5_diffusion_right, theta6_diffusion_left, theta6_diffusion_surface, theta6_diffusion_right, theta7_diffusion_left, theta7_diffusion_surface, theta7_diffusion_right, R_source, N_histo_source, normalization_x_cyl1_in_source, normalization_r_cyl1_in_source, x_0_source, z0_mag1, L_mag1, z0_mag2, L_mag2, z0_mag3, L_mag3, z0_mag4, L_mag4, z0_mag5, L_mag5, z0_mag6, L_mag6, z0_mag7, L_mag7, B1_max_initial, B2_max_initial, B3_max_initial, B4_max_initial, B5_max_initial, B6_max_initial, B7_max_initial, r1_mag_max_initial, r2_mag_max_initial, r3_mag_max_initial, r4_mag_max_initial, r5_mag_max_initial, r6_mag_max_initial, r7_mag_max_initial, mu_core_particle, m_particle, on_off_mag_1, on_off_mag_2, on_off_mag_3, on_off_mag_4, on_off_mag_5, on_off_mag_6, on_off_mag_7, B_critical, mu_electron_particle, J_particle, I_particle, mu_core_particle, m_J, m_F, r1_mag_max_final, r2_mag_max_final, r3_mag_max_final, r4_mag_max_final, r5_mag_max_final, r6_mag_max_final, r7_mag_max_final, N_mag_partitions, particle_mode,
		temp_beam, flaq_Maxwell, a_V_0, b_V_0, N_histo_V_0, N_histo_theta_in, flaq_Maxwell_mode, average_peak, n_mag_1_in, n_mag_1_absorption, n_mag_1_out, n_mag_2_in, n_mag_2_absorption, n_mag_2_out, n_mag_3_in, n_mag_3_absorption, n_mag_3_out, n_mag_4_in, n_mag_4_absorption, n_mag_4_out, n_mag_5_in, n_mag_5_absorption, n_mag_5_out, n_mag_6_in, n_mag_6_absorption, n_mag_6_out, n_mag_7_in, n_mag_7_absorption, n_mag_7_out, n_tube_y0_x0, phi_1_2, flaq_angular_coefficient, N_CYL_partitions, N_r_angular, N_phi_angular, n_cos_intensity);

	out_txt("out_cyl1_in_source_negative.txt", mass_histo_x_cyl1_in_source_negative, mass_histo_r_cyl1_in_source_negative, start_time, end_time, R1_1, R2_1, R3_1, L_1, V_0, R1_2, R2_2, R3_2, L_2, R1_3, R2_3, R3_3, L_3, R1_4, R2_4, R3_4, L_4, R1_5, R2_5, R3_5, L_5, R1_6, R2_6, R3_6, L_6, R1_7, R2_7, R3_7, L_7, R1_8, R2_8, R3_8, N, N_histo, R, b1_left, b1_surface, b1_right, b2_left, b2_surface, b2_right, b3_left, b3_surface, b3_right, b4_left, b4_surface, b4_right, b5_left, b5_surface, b5_right, b6_left, b6_surface, b6_right, b7_left, b7_surface, b7_right, N_on, N_off, N1_1, N2_1, N3_1, N4_1, N5_1, N6_1, N7_1, N1_2, N2_2, N3_2, N4_2, N5_2, N6_2, N7_2, N1_3, N2_3, N3_3, N4_3, N5_3, N6_3, N7_3, N1_4, N2_4, N3_4, N4_4, N5_4, N6_4, N7_4, N1_5, N2_5, N3_5, N4_5, N5_5, N6_5, N7_5, N1_6, N2_6, N3_6, N4_6, N5_6, N6_6, N7_6, N1_7, N2_7, N3_7, N4_7, N5_7, N6_7, N7_7, n1, n2, n3, n4, n5, n6, n7, n_travel, t, theta1_diffusion_left, theta1_diffusion_surface,
		theta1_diffusion_right, theta2_diffusion_left, theta2_diffusion_surface, theta2_diffusion_right, theta3_diffusion_left, theta3_diffusion_surface, theta3_diffusion_right, theta4_diffusion_left, theta4_diffusion_surface, theta4_diffusion_right, theta5_diffusion_left, theta5_diffusion_surface, theta5_diffusion_right, theta6_diffusion_left, theta6_diffusion_surface, theta6_diffusion_right, theta7_diffusion_left, theta7_diffusion_surface, theta7_diffusion_right, R_source, N_histo_source, normalization_x_cyl1_in_source, normalization_r_cyl1_in_source, x_0_source, z0_mag1, L_mag1, z0_mag2, L_mag2, z0_mag3, L_mag3, z0_mag4, L_mag4, z0_mag5, L_mag5, z0_mag6, L_mag6, z0_mag7, L_mag7, B1_max_initial, B2_max_initial, B3_max_initial, B4_max_initial, B5_max_initial, B6_max_initial, B7_max_initial, r1_mag_max_initial, r2_mag_max_initial, r3_mag_max_initial, r4_mag_max_initial, r5_mag_max_initial, r6_mag_max_initial, r7_mag_max_initial, mu_core_particle, m_particle, on_off_mag_1, on_off_mag_2, on_off_mag_3, on_off_mag_4, on_off_mag_5, on_off_mag_6, on_off_mag_7, B_critical, mu_electron_particle, J_particle, I_particle, mu_core_particle, m_J, m_F, r1_mag_max_final, r2_mag_max_final, r3_mag_max_final, r4_mag_max_final, r5_mag_max_final, r6_mag_max_final, r7_mag_max_final, N_mag_partitions, particle_mode,
		temp_beam, flaq_Maxwell, a_V_0, b_V_0, N_histo_V_0, N_histo_theta_in, flaq_Maxwell_mode, average_peak, n_mag_1_in, n_mag_1_absorption, n_mag_1_out, n_mag_2_in, n_mag_2_absorption, n_mag_2_out, n_mag_3_in, n_mag_3_absorption, n_mag_3_out, n_mag_4_in, n_mag_4_absorption, n_mag_4_out, n_mag_5_in, n_mag_5_absorption, n_mag_5_out, n_mag_6_in, n_mag_6_absorption, n_mag_6_out, n_mag_7_in, n_mag_7_absorption, n_mag_7_out, n_tube_y0_x0, phi_1_2, flaq_angular_coefficient, N_CYL_partitions, N_r_angular, N_phi_angular, n_cos_intensity);


	out_txt("out_source.txt", mass_histo_x_source, mass_histo_r_source, start_time, end_time, R1_1, R2_1, R3_1, L_1, V_0, R1_2, R2_2, R3_2, L_2, R1_3, R2_3, R3_3, L_3, R1_4, R2_4, R3_4, L_4, R1_5, R2_5, R3_5, L_5, R1_6, R2_6, R3_6, L_6, R1_7, R2_7, R3_7, L_7, R1_8, R2_8, R3_8, N, N_histo, R, b1_left, b1_surface, b1_right, b2_left, b2_surface, b2_right, b3_left, b3_surface, b3_right, b4_left, b4_surface, b4_right, b5_left, b5_surface, b5_right, b6_left, b6_surface, b6_right, b7_left, b7_surface, b7_right, N_on, N_off, N1_1, N2_1, N3_1, N4_1, N5_1, N6_1, N7_1, N1_2, N2_2, N3_2, N4_2, N5_2, N6_2, N7_2, N1_3, N2_3, N3_3, N4_3, N5_3, N6_3, N7_3, N1_4, N2_4, N3_4, N4_4, N5_4, N6_4, N7_4, N1_5, N2_5, N3_5, N4_5, N5_5, N6_5, N7_5, N1_6, N2_6, N3_6, N4_6, N5_6, N6_6, N7_6, N1_7, N2_7, N3_7, N4_7, N5_7, N6_7, N7_7, n1, n2, n3, n4, n5, n6, n7,
		n_travel, t, theta1_diffusion_left, theta1_diffusion_surface, theta1_diffusion_right, theta2_diffusion_left, theta2_diffusion_surface, theta2_diffusion_right, theta3_diffusion_left, theta3_diffusion_surface, theta3_diffusion_right, theta4_diffusion_left, theta4_diffusion_surface, theta4_diffusion_right, theta5_diffusion_left, theta5_diffusion_surface, theta5_diffusion_right, theta6_diffusion_left, theta6_diffusion_surface, theta6_diffusion_right, theta7_diffusion_left, theta7_diffusion_surface, theta7_diffusion_right, R_source, N_histo_source, normalization_x_source, normalization_r_source, x_0_source, z0_mag1, L_mag1, z0_mag2, L_mag2, z0_mag3, L_mag3, z0_mag4, L_mag4, z0_mag5, L_mag5, z0_mag6, L_mag6, z0_mag7, L_mag7, B1_max_initial, B2_max_initial, B3_max_initial, B4_max_initial, B5_max_initial, B6_max_initial, B7_max_initial, r1_mag_max_initial, r2_mag_max_initial, r3_mag_max_initial, r4_mag_max_initial, r5_mag_max_initial, r6_mag_max_initial, r7_mag_max_initial, mu_core_particle, m_particle, on_off_mag_1, on_off_mag_2, on_off_mag_3, on_off_mag_4, on_off_mag_5, on_off_mag_6, on_off_mag_7, B_critical, mu_electron_particle, J_particle, I_particle, mu_core_particle, m_J, m_F, r1_mag_max_final, r2_mag_max_final, r3_mag_max_final, r4_mag_max_final, r5_mag_max_final, r6_mag_max_final, r7_mag_max_final, N_mag_partitions, particle_mode, temp_beam, flaq_Maxwell, a_V_0, b_V_0, N_histo_V_0, N_histo_theta_in,
		flaq_Maxwell_mode, average_peak, n_mag_1_in, n_mag_1_absorption, n_mag_1_out, n_mag_2_in, n_mag_2_absorption, n_mag_2_out, n_mag_3_in, n_mag_3_absorption, n_mag_3_out, n_mag_4_in, n_mag_4_absorption, n_mag_4_out, n_mag_5_in, n_mag_5_absorption, n_mag_5_out, n_mag_6_in, n_mag_6_absorption, n_mag_6_out, n_mag_7_in, n_mag_7_absorption, n_mag_7_out, n_tube_y0_x0, phi_1_2, flaq_angular_coefficient, N_CYL_partitions, N_r_angular, N_phi_angular, n_cos_intensity);





	out_txt("out_positive.txt", mass_histo_x_positive, mass_histo_r_positive, start_time, end_time, R1_1, R2_1, R3_1, L_1, V_0, R1_2, R2_2, R3_2, L_2, R1_3, R2_3, R3_3, L_3, R1_4, R2_4, R3_4, L_4, R1_5, R2_5, R3_5, L_5, R1_6, R2_6, R3_6, L_6, R1_7, R2_7, R3_7, L_7, R1_8, R2_8, R3_8, N, N_histo, R, b1_left, b1_surface, b1_right, b2_left, b2_surface, b2_right, b3_left, b3_surface, b3_right, b4_left, b4_surface, b4_right, b5_left, b5_surface, b5_right, b6_left, b6_surface, b6_right, b7_left, b7_surface, b7_right, N_on, N_off, N1_1, N2_1, N3_1, N4_1, N5_1, N6_1, N7_1, N1_2, N2_2, N3_2, N4_2, N5_2, N6_2, N7_2, N1_3, N2_3, N3_3, N4_3, N5_3, N6_3, N7_3, N1_4, N2_4, N3_4, N4_4, N5_4, N6_4, N7_4, N1_5, N2_5, N3_5, N4_5, N5_5, N6_5, N7_5, N1_6, N2_6, N3_6, N4_6, N5_6, N6_6, N7_6, N1_7, N2_7, N3_7, N4_7, N5_7, N6_7, N7_7, n1, n2, n3, n4, n5, n6, n7, n_travel, t, theta1_diffusion_left,
		theta1_diffusion_surface, theta1_diffusion_right, theta2_diffusion_left, theta2_diffusion_surface, theta2_diffusion_right, theta3_diffusion_left, theta3_diffusion_surface, theta3_diffusion_right, theta4_diffusion_left, theta4_diffusion_surface, theta4_diffusion_right, theta5_diffusion_left, theta5_diffusion_surface, theta5_diffusion_right, theta6_diffusion_left, theta6_diffusion_surface, theta6_diffusion_right, theta7_diffusion_left, theta7_diffusion_surface, theta7_diffusion_right, R_source, N_histo_source, normalization_x, normalization_r, x_0_source, z0_mag1, L_mag1, z0_mag2, L_mag2, z0_mag3, L_mag3, z0_mag4, L_mag4, z0_mag5, L_mag5, z0_mag6, L_mag6, z0_mag7, L_mag7, B1_max_initial, B2_max_initial, B3_max_initial, B4_max_initial, B5_max_initial, B6_max_initial, B7_max_initial, r1_mag_max_initial, r2_mag_max_initial, r3_mag_max_initial, r4_mag_max_initial, r5_mag_max_initial, r6_mag_max_initial, r7_mag_max_initial, mu_core_particle, m_particle, on_off_mag_1, on_off_mag_2, on_off_mag_3, on_off_mag_4, on_off_mag_5, on_off_mag_6, on_off_mag_7, B_critical, mu_electron_particle, J_particle, I_particle, mu_core_particle, m_J, m_F, r1_mag_max_final, r2_mag_max_final, r3_mag_max_final, r4_mag_max_final, r5_mag_max_final, r6_mag_max_final, r7_mag_max_final, N_mag_partitions, particle_mode, temp_beam, flaq_Maxwell, a_V_0, b_V_0, N_histo_V_0, N_histo_theta_in, flaq_Maxwell_mode,
		average_peak, n_mag_1_in, n_mag_1_absorption, n_mag_1_out, n_mag_2_in, n_mag_2_absorption, n_mag_2_out, n_mag_3_in, n_mag_3_absorption, n_mag_3_out, n_mag_4_in, n_mag_4_absorption, n_mag_4_out, n_mag_5_in, n_mag_5_absorption, n_mag_5_out, n_mag_6_in, n_mag_6_absorption, n_mag_6_out, n_mag_7_in, n_mag_7_absorption, n_mag_7_out, n_tube_y0_x0, phi_1_2, flaq_angular_coefficient, N_CYL_partitions, N_r_angular, N_phi_angular, n_cos_intensity);

	out_txt("out_source_positive.txt", mass_histo_x_source_positive, mass_histo_r_source_positive, start_time, end_time, R1_1, R2_1, R3_1, L_1, V_0, R1_2, R2_2, R3_2, L_2, R1_3, R2_3, R3_3, L_3, R1_4, R2_4, R3_4, L_4, R1_5, R2_5, R3_5, L_5, R1_6, R2_6, R3_6, L_6, R1_7, R2_7, R3_7, L_7, R1_8, R2_8, R3_8, N, N_histo, R, b1_left, b1_surface, b1_right, b2_left, b2_surface, b2_right, b3_left, b3_surface, b3_right, b4_left, b4_surface, b4_right, b5_left, b5_surface, b5_right, b6_left, b6_surface, b6_right, b7_left, b7_surface, b7_right, N_on, N_off, N1_1, N2_1, N3_1, N4_1, N5_1, N6_1, N7_1, N1_2, N2_2, N3_2, N4_2, N5_2, N6_2, N7_2, N1_3, N2_3, N3_3, N4_3, N5_3, N6_3, N7_3, N1_4, N2_4, N3_4, N4_4, N5_4, N6_4, N7_4, N1_5, N2_5, N3_5, N4_5, N5_5, N6_5, N7_5, N1_6, N2_6, N3_6, N4_6, N5_6, N6_6, N7_6, N1_7, N2_7, N3_7, N4_7, N5_7, N6_7, N7_7, n1, n2, n3, n4, n5, n6, n7, n_travel, t,
		theta1_diffusion_left, theta1_diffusion_surface, theta1_diffusion_right, theta2_diffusion_left, theta2_diffusion_surface, theta2_diffusion_right, theta3_diffusion_left, theta3_diffusion_surface, theta3_diffusion_right, theta4_diffusion_left, theta4_diffusion_surface, theta4_diffusion_right, theta5_diffusion_left, theta5_diffusion_surface, theta5_diffusion_right, theta6_diffusion_left, theta6_diffusion_surface, theta6_diffusion_right, theta7_diffusion_left, theta7_diffusion_surface, theta7_diffusion_right, R_source, N_histo_source, normalization_x_source, normalization_r_source, x_0_source, z0_mag1, L_mag1, z0_mag2, L_mag2, z0_mag3, L_mag3, z0_mag4, L_mag4, z0_mag5, L_mag5, z0_mag6, L_mag6, z0_mag7, L_mag7, B1_max_initial, B2_max_initial, B3_max_initial, B4_max_initial, B5_max_initial, B6_max_initial, B7_max_initial, r1_mag_max_initial, r2_mag_max_initial, r3_mag_max_initial, r4_mag_max_initial, r5_mag_max_initial, r6_mag_max_initial, r7_mag_max_initial, mu_core_particle, m_particle, on_off_mag_1, on_off_mag_2, on_off_mag_3, on_off_mag_4, on_off_mag_5, on_off_mag_6, on_off_mag_7, B_critical, mu_electron_particle, J_particle, I_particle, mu_core_particle, m_J, m_F, r1_mag_max_final, r2_mag_max_final, r3_mag_max_final, r4_mag_max_final, r5_mag_max_final, r6_mag_max_final, r7_mag_max_final, N_mag_partitions, particle_mode, temp_beam, flaq_Maxwell, a_V_0, b_V_0, N_histo_V_0, N_histo_theta_in, flaq_Maxwell_mode,
		average_peak, n_mag_1_in, n_mag_1_absorption, n_mag_1_out, n_mag_2_in, n_mag_2_absorption, n_mag_2_out, n_mag_3_in, n_mag_3_absorption, n_mag_3_out, n_mag_4_in, n_mag_4_absorption, n_mag_4_out, n_mag_5_in, n_mag_5_absorption, n_mag_5_out, n_mag_6_in, n_mag_6_absorption, n_mag_6_out, n_mag_7_in, n_mag_7_absorption, n_mag_7_out, n_tube_y0_x0, phi_1_2, flaq_angular_coefficient, N_CYL_partitions, N_r_angular, N_phi_angular, n_cos_intensity);




	out_txt("out_zero.txt", mass_histo_x_zero, mass_histo_r_zero, start_time, end_time, R1_1, R2_1, R3_1, L_1, V_0, R1_2, R2_2, R3_2, L_2, R1_3, R2_3, R3_3, L_3, R1_4, R2_4, R3_4, L_4, R1_5, R2_5, R3_5, L_5, R1_6, R2_6, R3_6, L_6, R1_7, R2_7, R3_7, L_7, R1_8, R2_8, R3_8, N, N_histo, R, b1_left, b1_surface, b1_right, b2_left, b2_surface, b2_right, b3_left, b3_surface, b3_right, b4_left, b4_surface, b4_right, b5_left, b5_surface, b5_right, b6_left, b6_surface, b6_right, b7_left, b7_surface, b7_right, N_on, N_off, N1_1, N2_1, N3_1, N4_1, N5_1, N6_1, N7_1, N1_2, N2_2, N3_2, N4_2, N5_2, N6_2, N7_2, N1_3, N2_3, N3_3, N4_3, N5_3, N6_3, N7_3, N1_4, N2_4, N3_4, N4_4, N5_4, N6_4, N7_4, N1_5, N2_5, N3_5, N4_5, N5_5, N6_5, N7_5, N1_6, N2_6, N3_6, N4_6, N5_6, N6_6, N7_6, N1_7, N2_7, N3_7, N4_7, N5_7, N6_7, N7_7, n1, n2, n3, n4, n5, n6, n7, n_travel, t, theta1_diffusion_left, theta1_diffusion_surface, theta1_diffusion_right, theta2_diffusion_left, theta2_diffusion_surface, theta2_diffusion_right, theta3_diffusion_left, theta3_diffusion_surface, theta3_diffusion_right, theta4_diffusion_left, theta4_diffusion_surface, theta4_diffusion_right, theta5_diffusion_left, theta5_diffusion_surface, theta5_diffusion_right, theta6_diffusion_left, theta6_diffusion_surface, theta6_diffusion_right, theta7_diffusion_left, theta7_diffusion_surface, theta7_diffusion_right, R_source, N_histo_source, normalization_x, normalization_r, x_0_source, z0_mag1, L_mag1, z0_mag2, L_mag2, z0_mag3, L_mag3, z0_mag4, L_mag4, z0_mag5, L_mag5, z0_mag6, L_mag6, z0_mag7, L_mag7, B1_max_initial,
		B2_max_initial, B3_max_initial, B4_max_initial, B5_max_initial, B6_max_initial, B7_max_initial, r1_mag_max_initial, r2_mag_max_initial, r3_mag_max_initial, r4_mag_max_initial, r5_mag_max_initial, r6_mag_max_initial, r7_mag_max_initial, mu_core_particle, m_particle, on_off_mag_1, on_off_mag_2, on_off_mag_3, on_off_mag_4, on_off_mag_5, on_off_mag_6, on_off_mag_7, B_critical, mu_electron_particle, J_particle, I_particle, mu_core_particle, m_J, m_F, r1_mag_max_final, r2_mag_max_final, r3_mag_max_final, r4_mag_max_final, r5_mag_max_final, r6_mag_max_final, r7_mag_max_final, N_mag_partitions, particle_mode, temp_beam, flaq_Maxwell, a_V_0, b_V_0, N_histo_V_0, N_histo_theta_in, flaq_Maxwell_mode,
		average_peak, n_mag_1_in, n_mag_1_absorption, n_mag_1_out, n_mag_2_in, n_mag_2_absorption, n_mag_2_out, n_mag_3_in, n_mag_3_absorption, n_mag_3_out, n_mag_4_in, n_mag_4_absorption, n_mag_4_out, n_mag_5_in, n_mag_5_absorption, n_mag_5_out, n_mag_6_in, n_mag_6_absorption, n_mag_6_out, n_mag_7_in, n_mag_7_absorption, n_mag_7_out, n_tube_y0_x0, phi_1_2, flaq_angular_coefficient, N_CYL_partitions, N_r_angular, N_phi_angular, n_cos_intensity);

	out_txt("out_source_zero.txt", mass_histo_x_source_zero, mass_histo_r_source_zero, start_time, end_time, R1_1, R2_1, R3_1, L_1, V_0, R1_2, R2_2, R3_2, L_2, R1_3, R2_3, R3_3, L_3, R1_4, R2_4, R3_4, L_4, R1_5, R2_5, R3_5, L_5, R1_6, R2_6, R3_6, L_6, R1_7, R2_7, R3_7, L_7, R1_8, R2_8, R3_8, N, N_histo, R, b1_left, b1_surface, b1_right, b2_left, b2_surface, b2_right, b3_left, b3_surface, b3_right, b4_left, b4_surface, b4_right, b5_left, b5_surface, b5_right, b6_left, b6_surface, b6_right, b7_left, b7_surface, b7_right, N_on, N_off, N1_1, N2_1, N3_1, N4_1, N5_1, N6_1, N7_1, N1_2, N2_2, N3_2, N4_2, N5_2, N6_2, N7_2, N1_3, N2_3, N3_3, N4_3, N5_3, N6_3, N7_3, N1_4, N2_4, N3_4, N4_4, N5_4, N6_4, N7_4, N1_5, N2_5, N3_5, N4_5, N5_5, N6_5, N7_5, N1_6, N2_6, N3_6, N4_6, N5_6, N6_6, N7_6, N1_7, N2_7, N3_7, N4_7, N5_7, N6_7, N7_7, n1, n2, n3, n4, n5, n6, n7, n_travel, t, theta1_diffusion_left, theta1_diffusion_surface, theta1_diffusion_right, theta2_diffusion_left, theta2_diffusion_surface, theta2_diffusion_right, theta3_diffusion_left, theta3_diffusion_surface, theta3_diffusion_right, theta4_diffusion_left, theta4_diffusion_surface, theta4_diffusion_right, theta5_diffusion_left, theta5_diffusion_surface, theta5_diffusion_right, theta6_diffusion_left, theta6_diffusion_surface, theta6_diffusion_right, theta7_diffusion_left, theta7_diffusion_surface, theta7_diffusion_right, R_source, N_histo_source, normalization_x_source, normalization_r_source, x_0_source, z0_mag1, L_mag1, z0_mag2, L_mag2, z0_mag3,
		L_mag3, z0_mag4, L_mag4, z0_mag5, L_mag5, z0_mag6, L_mag6, z0_mag7, L_mag7, B1_max_initial, B2_max_initial, B3_max_initial, B4_max_initial, B5_max_initial, B6_max_initial, B7_max_initial, r1_mag_max_initial, r2_mag_max_initial, r3_mag_max_initial, r4_mag_max_initial, r5_mag_max_initial, r6_mag_max_initial, r7_mag_max_initial, mu_core_particle, m_particle, on_off_mag_1, on_off_mag_2, on_off_mag_3, on_off_mag_4, on_off_mag_5, on_off_mag_6, on_off_mag_7, B_critical, mu_electron_particle, J_particle, I_particle, mu_core_particle, m_J, m_F, r1_mag_max_final, r2_mag_max_final, r3_mag_max_final, r4_mag_max_final, r5_mag_max_final, r6_mag_max_final, r7_mag_max_final, N_mag_partitions, particle_mode, temp_beam, flaq_Maxwell, a_V_0, b_V_0, N_histo_V_0, N_histo_theta_in, flaq_Maxwell_mode,
		average_peak, n_mag_1_in, n_mag_1_absorption, n_mag_1_out, n_mag_2_in, n_mag_2_absorption, n_mag_2_out, n_mag_3_in, n_mag_3_absorption, n_mag_3_out, n_mag_4_in, n_mag_4_absorption, n_mag_4_out, n_mag_5_in, n_mag_5_absorption, n_mag_5_out, n_mag_6_in, n_mag_6_absorption, n_mag_6_out, n_mag_7_in, n_mag_7_absorption, n_mag_7_out, n_tube_y0_x0, phi_1_2, flaq_angular_coefficient, N_CYL_partitions, N_r_angular, N_phi_angular, n_cos_intensity);



	out_txt("out_negative.txt", mass_histo_x_negative, mass_histo_r_negative, start_time, end_time, R1_1, R2_1, R3_1, L_1, V_0, R1_2, R2_2, R3_2, L_2, R1_3, R2_3, R3_3, L_3, R1_4, R2_4, R3_4, L_4, R1_5, R2_5, R3_5, L_5, R1_6, R2_6, R3_6, L_6, R1_7, R2_7, R3_7, L_7, R1_8, R2_8, R3_8, N, N_histo, R, b1_left, b1_surface, b1_right, b2_left, b2_surface, b2_right, b3_left, b3_surface, b3_right, b4_left, b4_surface, b4_right, b5_left, b5_surface, b5_right, b6_left, b6_surface, b6_right, b7_left, b7_surface, b7_right, N_on, N_off, N1_1, N2_1, N3_1, N4_1, N5_1, N6_1, N7_1, N1_2, N2_2, N3_2, N4_2, N5_2, N6_2, N7_2, N1_3, N2_3, N3_3, N4_3, N5_3, N6_3, N7_3, N1_4, N2_4, N3_4, N4_4, N5_4, N6_4, N7_4, N1_5, N2_5, N3_5, N4_5, N5_5, N6_5, N7_5, N1_6, N2_6, N3_6, N4_6, N5_6, N6_6, N7_6, N1_7, N2_7, N3_7, N4_7, N5_7, N6_7, N7_7, n1, n2, n3, n4, n5, n6, n7, n_travel, t, theta1_diffusion_left, theta1_diffusion_surface, theta1_diffusion_right, theta2_diffusion_left, theta2_diffusion_surface, theta2_diffusion_right, theta3_diffusion_left, theta3_diffusion_surface, theta3_diffusion_right, theta4_diffusion_left, theta4_diffusion_surface, theta4_diffusion_right, theta5_diffusion_left, theta5_diffusion_surface, theta5_diffusion_right, theta6_diffusion_left, theta6_diffusion_surface, theta6_diffusion_right, theta7_diffusion_left, theta7_diffusion_surface, theta7_diffusion_right, R_source, N_histo_source, normalization_x, normalization_r, x_0_source, z0_mag1, L_mag1, z0_mag2, L_mag2, z0_mag3, L_mag3, z0_mag4, L_mag4, z0_mag5, L_mag5, z0_mag6, L_mag6, z0_mag7, L_mag7, B1_max_initial,
		B2_max_initial, B3_max_initial, B4_max_initial, B5_max_initial, B6_max_initial, B7_max_initial, r1_mag_max_initial, r2_mag_max_initial, r3_mag_max_initial, r4_mag_max_initial, r5_mag_max_initial, r6_mag_max_initial, r7_mag_max_initial, mu_core_particle, m_particle, on_off_mag_1, on_off_mag_2, on_off_mag_3, on_off_mag_4, on_off_mag_5, on_off_mag_6, on_off_mag_7, B_critical, mu_electron_particle, J_particle, I_particle, mu_core_particle, m_J, m_F, r1_mag_max_final, r2_mag_max_final, r3_mag_max_final, r4_mag_max_final, r5_mag_max_final, r6_mag_max_final, r7_mag_max_final, N_mag_partitions, particle_mode, temp_beam, flaq_Maxwell, a_V_0, b_V_0, N_histo_V_0, N_histo_theta_in, flaq_Maxwell_mode,
		average_peak, n_mag_1_in, n_mag_1_absorption, n_mag_1_out, n_mag_2_in, n_mag_2_absorption, n_mag_2_out, n_mag_3_in, n_mag_3_absorption, n_mag_3_out, n_mag_4_in, n_mag_4_absorption, n_mag_4_out, n_mag_5_in, n_mag_5_absorption, n_mag_5_out, n_mag_6_in, n_mag_6_absorption, n_mag_6_out, n_mag_7_in, n_mag_7_absorption, n_mag_7_out, n_tube_y0_x0, phi_1_2, flaq_angular_coefficient, N_CYL_partitions, N_r_angular, N_phi_angular, n_cos_intensity);

	out_txt("out_source_negative.txt", mass_histo_x_source_negative, mass_histo_r_source_negative, start_time, end_time, R1_1, R2_1, R3_1, L_1, V_0, R1_2, R2_2, R3_2, L_2, R1_3, R2_3, R3_3, L_3, R1_4, R2_4, R3_4, L_4, R1_5, R2_5, R3_5, L_5, R1_6, R2_6, R3_6, L_6, R1_7, R2_7, R3_7, L_7, R1_8, R2_8, R3_8, N, N_histo, R, b1_left, b1_surface, b1_right, b2_left, b2_surface, b2_right, b3_left, b3_surface, b3_right, b4_left, b4_surface, b4_right, b5_left, b5_surface, b5_right, b6_left, b6_surface, b6_right, b7_left, b7_surface, b7_right, N_on, N_off, N1_1, N2_1, N3_1, N4_1, N5_1, N6_1, N7_1, N1_2, N2_2, N3_2, N4_2, N5_2, N6_2, N7_2, N1_3, N2_3, N3_3, N4_3, N5_3, N6_3, N7_3, N1_4, N2_4, N3_4, N4_4, N5_4, N6_4, N7_4, N1_5, N2_5, N3_5, N4_5, N5_5, N6_5, N7_5, N1_6, N2_6, N3_6, N4_6, N5_6, N6_6, N7_6, N1_7, N2_7, N3_7, N4_7, N5_7, N6_7, N7_7, n1, n2, n3, n4, n5, n6, n7, n_travel, t, theta1_diffusion_left, theta1_diffusion_surface, theta1_diffusion_right, theta2_diffusion_left, theta2_diffusion_surface, theta2_diffusion_right, theta3_diffusion_left, theta3_diffusion_surface, theta3_diffusion_right, theta4_diffusion_left, theta4_diffusion_surface, theta4_diffusion_right, theta5_diffusion_left, theta5_diffusion_surface, theta5_diffusion_right, theta6_diffusion_left, theta6_diffusion_surface, theta6_diffusion_right, theta7_diffusion_left, theta7_diffusion_surface, theta7_diffusion_right, R_source, N_histo_source, normalization_x_source, normalization_r_source, x_0_source, z0_mag1, L_mag1, z0_mag2, L_mag2,
		z0_mag3, L_mag3, z0_mag4, L_mag4, z0_mag5, L_mag5, z0_mag6, L_mag6, z0_mag7, L_mag7, B1_max_initial, B2_max_initial, B3_max_initial, B4_max_initial, B5_max_initial, B6_max_initial, B7_max_initial, r1_mag_max_initial, r2_mag_max_initial, r3_mag_max_initial, r4_mag_max_initial, r5_mag_max_initial, r6_mag_max_initial, r7_mag_max_initial, mu_core_particle, m_particle, on_off_mag_1, on_off_mag_2, on_off_mag_3, on_off_mag_4, on_off_mag_5, on_off_mag_6, on_off_mag_7, B_critical, mu_electron_particle, J_particle, I_particle, mu_core_particle, m_J, m_F, r1_mag_max_final, r2_mag_max_final, r3_mag_max_final, r4_mag_max_final, r5_mag_max_final, r6_mag_max_final, r7_mag_max_final, N_mag_partitions, particle_mode, temp_beam, flaq_Maxwell, a_V_0, b_V_0, N_histo_V_0, N_histo_theta_in, flaq_Maxwell_mode,
		average_peak, n_mag_1_in, n_mag_1_absorption, n_mag_1_out, n_mag_2_in, n_mag_2_absorption, n_mag_2_out, n_mag_3_in, n_mag_3_absorption, n_mag_3_out, n_mag_4_in, n_mag_4_absorption, n_mag_4_out, n_mag_5_in, n_mag_5_absorption, n_mag_5_out, n_mag_6_in, n_mag_6_absorption, n_mag_6_out, n_mag_7_in, n_mag_7_absorption, n_mag_7_out, n_tube_y0_x0, phi_1_2, flaq_angular_coefficient, N_CYL_partitions, N_r_angular, N_phi_angular, n_cos_intensity);




	out_txt_P_z_P_zz("out_source_P_z.txt", mass_histo_x_source_P_z, mass_histo_r_source_P_z, start_time, end_time, R1_1, R2_1, R3_1, L_1, V_0, R1_2, R2_2, R3_2, L_2, R1_3, R2_3, R3_3, L_3, R1_4, R2_4, R3_4, L_4, R1_5, R2_5, R3_5, L_5, R1_6, R2_6, R3_6, L_6, R1_7, R2_7, R3_7, L_7, R1_8, R2_8, R3_8, N, N_histo, R, b1_left, b1_surface, b1_right, b2_left, b2_surface, b2_right, b3_left, b3_surface, b3_right, b4_left, b4_surface, b4_right, b5_left, b5_surface, b5_right, b6_left, b6_surface, b6_right, b7_left, b7_surface, b7_right, N_on, N_off, N1_1, N2_1, N3_1, N4_1, N5_1, N6_1, N7_1, N1_2, N2_2, N3_2, N4_2, N5_2, N6_2, N7_2, N1_3, N2_3, N3_3, N4_3, N5_3, N6_3, N7_3, N1_4, N2_4, N3_4, N4_4, N5_4, N6_4, N7_4, N1_5, N2_5, N3_5, N4_5, N5_5, N6_5, N7_5, N1_6, N2_6, N3_6, N4_6, N5_6, N6_6, N7_6, N1_7, N2_7, N3_7, N4_7, N5_7, N6_7, N7_7, n1, n2, n3, n4, n5, n6, n7, n_travel, t, theta1_diffusion_left, theta1_diffusion_surface, theta1_diffusion_right, theta2_diffusion_left, theta2_diffusion_surface, theta2_diffusion_right, theta3_diffusion_left, theta3_diffusion_surface, theta3_diffusion_right, theta4_diffusion_left, theta4_diffusion_surface, theta4_diffusion_right, theta5_diffusion_left, theta5_diffusion_surface, theta5_diffusion_right, theta6_diffusion_left, theta6_diffusion_surface, theta6_diffusion_right, theta7_diffusion_left, theta7_diffusion_surface, theta7_diffusion_right, R_source, N_histo_source, normalization_x_source, normalization_r_source, x_0_source, z0_mag1, L_mag1, z0_mag2, L_mag2,
		z0_mag3, L_mag3, z0_mag4, L_mag4, z0_mag5, L_mag5, z0_mag6, L_mag6, z0_mag7, L_mag7, B1_max_initial, B2_max_initial, B3_max_initial, B4_max_initial, B5_max_initial, B6_max_initial, B7_max_initial, r1_mag_max_initial, r2_mag_max_initial, r3_mag_max_initial, r4_mag_max_initial, r5_mag_max_initial, r6_mag_max_initial, r7_mag_max_initial, mu_core_particle, m_particle, on_off_mag_1, on_off_mag_2, on_off_mag_3, on_off_mag_4, on_off_mag_5, on_off_mag_6, on_off_mag_7, B_critical, mu_electron_particle, J_particle, I_particle, mu_core_particle, m_J, m_F, r1_mag_max_final, r2_mag_max_final, r3_mag_max_final, r4_mag_max_final, r5_mag_max_final, r6_mag_max_final, r7_mag_max_final, N_mag_partitions, particle_mode, temp_beam, flaq_Maxwell, a_V_0, b_V_0, N_histo_V_0, N_histo_theta_in, flaq_Maxwell_mode,
		average_peak, n_mag_1_in, n_mag_1_absorption, n_mag_1_out, n_mag_2_in, n_mag_2_absorption, n_mag_2_out, n_mag_3_in, n_mag_3_absorption, n_mag_3_out, n_mag_4_in, n_mag_4_absorption, n_mag_4_out, n_mag_5_in, n_mag_5_absorption, n_mag_5_out, n_mag_6_in, n_mag_6_absorption, n_mag_6_out, n_mag_7_in, n_mag_7_absorption, n_mag_7_out, n_tube_y0_x0, phi_1_2, flaq_angular_coefficient, N_CYL_partitions, N_r_angular, N_phi_angular, n_cos_intensity);




	out_txt_P_z_P_zz("out_source_P_zz.txt", mass_histo_x_source_P_zz, mass_histo_r_source_P_zz, start_time, end_time, R1_1, R2_1, R3_1, L_1, V_0, R1_2, R2_2, R3_2, L_2, R1_3, R2_3, R3_3, L_3, R1_4, R2_4, R3_4, L_4, R1_5, R2_5, R3_5, L_5, R1_6, R2_6, R3_6, L_6, R1_7, R2_7, R3_7, L_7, R1_8, R2_8, R3_8, N, N_histo, R, b1_left, b1_surface, b1_right, b2_left, b2_surface, b2_right, b3_left, b3_surface, b3_right, b4_left, b4_surface, b4_right, b5_left, b5_surface, b5_right, b6_left, b6_surface, b6_right, b7_left, b7_surface, b7_right, N_on, N_off, N1_1, N2_1, N3_1, N4_1, N5_1, N6_1, N7_1, N1_2, N2_2, N3_2, N4_2, N5_2, N6_2, N7_2, N1_3, N2_3, N3_3, N4_3, N5_3, N6_3, N7_3, N1_4, N2_4, N3_4, N4_4, N5_4, N6_4, N7_4, N1_5, N2_5, N3_5, N4_5, N5_5, N6_5, N7_5, N1_6, N2_6, N3_6, N4_6, N5_6, N6_6, N7_6, N1_7, N2_7, N3_7, N4_7, N5_7, N6_7, N7_7, n1, n2, n3, n4, n5, n6, n7, n_travel, t, theta1_diffusion_left, theta1_diffusion_surface, theta1_diffusion_right, theta2_diffusion_left, theta2_diffusion_surface, theta2_diffusion_right, theta3_diffusion_left, theta3_diffusion_surface, theta3_diffusion_right, theta4_diffusion_left, theta4_diffusion_surface, theta4_diffusion_right, theta5_diffusion_left, theta5_diffusion_surface, theta5_diffusion_right, theta6_diffusion_left, theta6_diffusion_surface, theta6_diffusion_right, theta7_diffusion_left, theta7_diffusion_surface, theta7_diffusion_right, R_source, N_histo_source, normalization_x_source, normalization_r_source, x_0_source, z0_mag1, L_mag1, z0_mag2, L_mag2,
		z0_mag3, L_mag3, z0_mag4, L_mag4, z0_mag5, L_mag5, z0_mag6, L_mag6, z0_mag7, L_mag7, B1_max_initial, B2_max_initial, B3_max_initial, B4_max_initial, B5_max_initial, B6_max_initial, B7_max_initial, r1_mag_max_initial, r2_mag_max_initial, r3_mag_max_initial, r4_mag_max_initial, r5_mag_max_initial, r6_mag_max_initial, r7_mag_max_initial, mu_core_particle, m_particle, on_off_mag_1, on_off_mag_2, on_off_mag_3, on_off_mag_4, on_off_mag_5, on_off_mag_6, on_off_mag_7, B_critical, mu_electron_particle, J_particle, I_particle, mu_core_particle, m_J, m_F, r1_mag_max_final, r2_mag_max_final, r3_mag_max_final, r4_mag_max_final, r5_mag_max_final, r6_mag_max_final, r7_mag_max_final, N_mag_partitions, particle_mode, temp_beam, flaq_Maxwell, a_V_0, b_V_0, N_histo_V_0, N_histo_theta_in, flaq_Maxwell_mode,
		average_peak, n_mag_1_in, n_mag_1_absorption, n_mag_1_out, n_mag_2_in, n_mag_2_absorption, n_mag_2_out, n_mag_3_in, n_mag_3_absorption, n_mag_3_out, n_mag_4_in, n_mag_4_absorption, n_mag_4_out, n_mag_5_in, n_mag_5_absorption, n_mag_5_out, n_mag_6_in, n_mag_6_absorption, n_mag_6_out, n_mag_7_in, n_mag_7_absorption, n_mag_7_out, n_tube_y0_x0, phi_1_2, flaq_angular_coefficient, N_CYL_partitions, N_r_angular, N_phi_angular, n_cos_intensity);





	out_txt_P_z_P_zz("out_x_P_z.txt", mass_histo_x_P_z, mass_histo_r_P_z, start_time, end_time, R1_1, R2_1, R3_1, L_1, V_0, R1_2, R2_2, R3_2, L_2, R1_3, R2_3, R3_3, L_3, R1_4, R2_4, R3_4, L_4, R1_5, R2_5, R3_5, L_5, R1_6, R2_6, R3_6, L_6, R1_7, R2_7, R3_7, L_7, R1_8, R2_8, R3_8, N, N_histo, R, b1_left, b1_surface, b1_right, b2_left, b2_surface, b2_right, b3_left, b3_surface, b3_right, b4_left, b4_surface, b4_right, b5_left, b5_surface, b5_right, b6_left, b6_surface, b6_right, b7_left, b7_surface, b7_right, N_on, N_off, N1_1, N2_1, N3_1, N4_1, N5_1, N6_1, N7_1, N1_2, N2_2, N3_2, N4_2, N5_2, N6_2, N7_2, N1_3, N2_3, N3_3, N4_3, N5_3, N6_3, N7_3, N1_4, N2_4, N3_4, N4_4, N5_4, N6_4, N7_4, N1_5, N2_5, N3_5, N4_5, N5_5, N6_5, N7_5, N1_6, N2_6, N3_6, N4_6, N5_6, N6_6, N7_6, N1_7, N2_7, N3_7, N4_7, N5_7, N6_7, N7_7, n1, n2, n3, n4, n5, n6, n7, n_travel, t, theta1_diffusion_left, theta1_diffusion_surface, theta1_diffusion_right, theta2_diffusion_left, theta2_diffusion_surface, theta2_diffusion_right, theta3_diffusion_left, theta3_diffusion_surface, theta3_diffusion_right, theta4_diffusion_left, theta4_diffusion_surface, theta4_diffusion_right, theta5_diffusion_left, theta5_diffusion_surface, theta5_diffusion_right, theta6_diffusion_left, theta6_diffusion_surface, theta6_diffusion_right, theta7_diffusion_left, theta7_diffusion_surface, theta7_diffusion_right, R_source, N_histo_source, normalization_x_source, normalization_r_source, x_0_source, z0_mag1, L_mag1, z0_mag2, L_mag2,
		z0_mag3, L_mag3, z0_mag4, L_mag4, z0_mag5, L_mag5, z0_mag6, L_mag6, z0_mag7, L_mag7, B1_max_initial, B2_max_initial, B3_max_initial, B4_max_initial, B5_max_initial, B6_max_initial, B7_max_initial, r1_mag_max_initial, r2_mag_max_initial, r3_mag_max_initial, r4_mag_max_initial, r5_mag_max_initial, r6_mag_max_initial, r7_mag_max_initial, mu_core_particle, m_particle, on_off_mag_1, on_off_mag_2, on_off_mag_3, on_off_mag_4, on_off_mag_5, on_off_mag_6, on_off_mag_7, B_critical, mu_electron_particle, J_particle, I_particle, mu_core_particle, m_J, m_F, r1_mag_max_final, r2_mag_max_final, r3_mag_max_final, r4_mag_max_final, r5_mag_max_final, r6_mag_max_final, r7_mag_max_final, N_mag_partitions, particle_mode, temp_beam, flaq_Maxwell, a_V_0, b_V_0, N_histo_V_0, N_histo_theta_in, flaq_Maxwell_mode,
		average_peak, n_mag_1_in, n_mag_1_absorption, n_mag_1_out, n_mag_2_in, n_mag_2_absorption, n_mag_2_out, n_mag_3_in, n_mag_3_absorption, n_mag_3_out, n_mag_4_in, n_mag_4_absorption, n_mag_4_out, n_mag_5_in, n_mag_5_absorption, n_mag_5_out, n_mag_6_in, n_mag_6_absorption, n_mag_6_out, n_mag_7_in, n_mag_7_absorption, n_mag_7_out, n_tube_y0_x0, phi_1_2, flaq_angular_coefficient, N_CYL_partitions, N_r_angular, N_phi_angular, n_cos_intensity);




	out_txt_P_z_P_zz("out_x_P_zz.txt", mass_histo_x_P_zz, mass_histo_r_P_zz, start_time, end_time, R1_1, R2_1, R3_1, L_1, V_0, R1_2, R2_2, R3_2, L_2, R1_3, R2_3, R3_3, L_3, R1_4, R2_4, R3_4, L_4, R1_5, R2_5, R3_5, L_5, R1_6, R2_6, R3_6, L_6, R1_7, R2_7, R3_7, L_7, R1_8, R2_8, R3_8, N, N_histo, R, b1_left, b1_surface, b1_right, b2_left, b2_surface, b2_right, b3_left, b3_surface, b3_right, b4_left, b4_surface, b4_right, b5_left, b5_surface, b5_right, b6_left, b6_surface, b6_right, b7_left, b7_surface, b7_right, N_on, N_off, N1_1, N2_1, N3_1, N4_1, N5_1, N6_1, N7_1, N1_2, N2_2, N3_2, N4_2, N5_2, N6_2, N7_2, N1_3, N2_3, N3_3, N4_3, N5_3, N6_3, N7_3, N1_4, N2_4, N3_4, N4_4, N5_4, N6_4, N7_4, N1_5, N2_5, N3_5, N4_5, N5_5, N6_5, N7_5, N1_6, N2_6, N3_6, N4_6, N5_6, N6_6, N7_6, N1_7, N2_7, N3_7, N4_7, N5_7, N6_7, N7_7, n1, n2, n3, n4, n5, n6, n7, n_travel, t, theta1_diffusion_left, theta1_diffusion_surface, theta1_diffusion_right, theta2_diffusion_left, theta2_diffusion_surface, theta2_diffusion_right, theta3_diffusion_left, theta3_diffusion_surface, theta3_diffusion_right, theta4_diffusion_left, theta4_diffusion_surface, theta4_diffusion_right, theta5_diffusion_left, theta5_diffusion_surface, theta5_diffusion_right, theta6_diffusion_left, theta6_diffusion_surface, theta6_diffusion_right, theta7_diffusion_left, theta7_diffusion_surface, theta7_diffusion_right, R_source, N_histo_source, normalization_x_source, normalization_r_source, x_0_source, z0_mag1, L_mag1, z0_mag2, L_mag2,
		z0_mag3, L_mag3, z0_mag4, L_mag4, z0_mag5, L_mag5, z0_mag6, L_mag6, z0_mag7, L_mag7, B1_max_initial, B2_max_initial, B3_max_initial, B4_max_initial, B5_max_initial, B6_max_initial, B7_max_initial, r1_mag_max_initial, r2_mag_max_initial, r3_mag_max_initial, r4_mag_max_initial, r5_mag_max_initial, r6_mag_max_initial, r7_mag_max_initial, mu_core_particle, m_particle, on_off_mag_1, on_off_mag_2, on_off_mag_3, on_off_mag_4, on_off_mag_5, on_off_mag_6, on_off_mag_7, B_critical, mu_electron_particle, J_particle, I_particle, mu_core_particle, m_J, m_F, r1_mag_max_final, r2_mag_max_final, r3_mag_max_final, r4_mag_max_final, r5_mag_max_final, r6_mag_max_final, r7_mag_max_final, N_mag_partitions, particle_mode, temp_beam, flaq_Maxwell, a_V_0, b_V_0, N_histo_V_0, N_histo_theta_in, flaq_Maxwell_mode,
		average_peak, n_mag_1_in, n_mag_1_absorption, n_mag_1_out, n_mag_2_in, n_mag_2_absorption, n_mag_2_out, n_mag_3_in, n_mag_3_absorption, n_mag_3_out, n_mag_4_in, n_mag_4_absorption, n_mag_4_out, n_mag_5_in, n_mag_5_absorption, n_mag_5_out, n_mag_6_in, n_mag_6_absorption, n_mag_6_out, n_mag_7_in, n_mag_7_absorption, n_mag_7_out, n_tube_y0_x0, phi_1_2, flaq_angular_coefficient, N_CYL_partitions, N_r_angular, N_phi_angular, n_cos_intensity);





	long double x_title = 0.75*b_V_0;
	long double y_title = 0.9*Max_Maxwell;


	long double x_title_time = 0.65*b_time*pow(10.0, 3.0);
	//long double y_title_time = 0.9*90;
	long double y_title_time = 0.9 * 290;











	out_txt_V_0("out_V_0.txt", mass_histo_V_0, normalization_V_0, a_V_0, b_V_0, N_histo_V_0, x_title, y_title);


	out_txt_time("out_time.txt", mass_histo_time, normalization_time, a_time, b_time, N_histo_time, x_title_time, y_title_time);


	out_txt_V_0("out_V_0_out.txt", mass_histo_V_0_out, normalization_V_0_out, a_V_0, b_V_0, N_histo_V_0_out, x_title, y_title);

	out_txt_V_0("out_V_0_tube_out.txt", mass_histo_V_0_tube_out, normalization_V_0_tube_out, a_V_0, b_V_0, N_histo_V_0_tube_out, x_title, y_title);


	//cout << N2_3 / n_tube_y0_x0 << endl;

	//long double A_cos_theta_intensity = 0.0;


	out_txt_theta_in("out_theta_in.txt", mass_histo_theta_in, normalization_theta_in, h_theta_in, A_theta_intensity);


	out_txt_theta_in("out_theta_out.txt", mass_histo_theta_out, normalization_theta_in, h_theta_out, n_cos_intensity + 1);

	out_txt_theta_in("out_theta_out_.txt", mass_histo_theta_out_, normalization_theta_in, h_theta_out, A_theta_intensity);

	out_txt_theta_in("out_theta_in_.txt", mass_histo_theta_in_, normalization_theta_in_, h_theta_in, n_cos_intensity + 1);

	//	out_txt_theta_in("out_theta_in__.txt", mass_histo_theta_in_, normalization_theta_in, h_theta_in,n_cos_intensity);

	out_txt_theta_in("out_theta_in_out.txt", mass_histo_theta_in_out, normalization_theta_in, h_theta_in_out, n_cos_intensity + 1);

	out_txt_theta_in("out_theta_in_out_.txt", mass_histo_theta_in_out_, normalization_theta_in, h_theta_in_out_, A_theta_intensity);




	if (flaq_out_trajectory == true) {


		if (flaq_trajectory_on_off_z == false) {

			out_txt_traectory_mag("out_traectory_mag_1.txt", Vector_r_mag_1, Vector_z_mag_1, z0_mag1 + L_mag1, Vector_x_mag_1, Vector_y_mag_1, Vector_color_mag_1, Vector_rr_mag_1, Vector_out_mag_1, Vector_phi_mag_1, Vector_psi_mag_1, Vector_theta_mag_1, Vector_v_x_mag_1, Vector_v_y_mag_1, Vector_v_z_mag_1, Vector_v_r_mag_1, Vector_v_phi_mag_1, Vector_v_perp_mag_1, Vector_v_0_mag_1, Vector_force_mag_1, Vector_condition_color_mag_1, Vector_mu_mag_1, Vector_B_mag_1);
			out_txt_traectory_mag("out_traectory_mag_2.txt", Vector_r_mag_2, Vector_z_mag_2, L_1 + z0_mag2 + L_mag2, Vector_x_mag_2, Vector_y_mag_2, Vector_color_mag_2, Vector_rr_mag_2, Vector_out_mag_2, Vector_phi_mag_2, Vector_psi_mag_2, Vector_theta_mag_2, Vector_v_x_mag_2, Vector_v_y_mag_2, Vector_v_z_mag_2, Vector_v_r_mag_2, Vector_v_phi_mag_2, Vector_v_perp_mag_2, Vector_v_0_mag_2, Vector_force_mag_2, Vector_condition_color_mag_2, Vector_mu_mag_2, Vector_B_mag_2);
			out_txt_traectory_mag("out_traectory_mag_3.txt", Vector_r_mag_3, Vector_z_mag_3, L_1 + L_2 + z0_mag3 + L_mag3, Vector_x_mag_3, Vector_y_mag_3, Vector_color_mag_3, Vector_rr_mag_3, Vector_out_mag_3, Vector_phi_mag_3, Vector_psi_mag_3, Vector_theta_mag_3, Vector_v_x_mag_3, Vector_v_y_mag_3, Vector_v_z_mag_3, Vector_v_r_mag_3, Vector_v_phi_mag_3, Vector_v_perp_mag_3, Vector_v_0_mag_3, Vector_force_mag_3, Vector_condition_color_mag_3, Vector_mu_mag_3, Vector_B_mag_3);
			out_txt_traectory_mag("out_traectory_mag_4.txt", Vector_r_mag_4, Vector_z_mag_4, L_1 + L_2 + L_3 + z0_mag4 + L_mag4, Vector_x_mag_4, Vector_y_mag_4, Vector_color_mag_4, Vector_rr_mag_4, Vector_out_mag_4, Vector_phi_mag_4, Vector_psi_mag_4, Vector_theta_mag_4, Vector_v_x_mag_4, Vector_v_y_mag_4, Vector_v_z_mag_4, Vector_v_r_mag_4, Vector_v_phi_mag_4, Vector_v_perp_mag_4, Vector_v_0_mag_4, Vector_force_mag_4, Vector_condition_color_mag_4, Vector_mu_mag_4, Vector_B_mag_4);
			out_txt_traectory_mag("out_traectory_mag_5.txt", Vector_r_mag_5, Vector_z_mag_5, L_1 + L_2 + L_3 + L_4 + z0_mag5 + L_mag5, Vector_x_mag_5, Vector_y_mag_5, Vector_color_mag_5, Vector_rr_mag_5, Vector_out_mag_5, Vector_phi_mag_5, Vector_psi_mag_5, Vector_theta_mag_5, Vector_v_x_mag_5, Vector_v_y_mag_5, Vector_v_z_mag_5, Vector_v_r_mag_5, Vector_v_phi_mag_5, Vector_v_perp_mag_5, Vector_v_0_mag_5, Vector_force_mag_5, Vector_condition_color_mag_5, Vector_mu_mag_5, Vector_B_mag_5);
			out_txt_traectory_mag("out_traectory_mag_6.txt", Vector_r_mag_6, Vector_z_mag_6, L_1 + L_2 + L_3 + L_4 + L_5 + z0_mag6 + L_mag6, Vector_x_mag_6, Vector_y_mag_6, Vector_color_mag_6, Vector_rr_mag_6, Vector_out_mag_6, Vector_phi_mag_6, Vector_psi_mag_6, Vector_theta_mag_6, Vector_v_x_mag_6, Vector_v_y_mag_6, Vector_v_z_mag_6, Vector_v_r_mag_6, Vector_v_phi_mag_6, Vector_v_perp_mag_6, Vector_v_0_mag_6, Vector_force_mag_6, Vector_condition_color_mag_6, Vector_mu_mag_6, Vector_B_mag_6);
			out_txt_traectory_mag("out_traectory_mag_7.txt", Vector_r_mag_7, Vector_z_mag_7, L_1 + L_2 + L_3 + L_4 + L_5 + L_6 + z0_mag7 + L_mag7, Vector_x_mag_7, Vector_y_mag_7, Vector_color_mag_7, Vector_rr_mag_7, Vector_out_mag_7, Vector_phi_mag_7, Vector_psi_mag_7, Vector_theta_mag_7, Vector_v_x_mag_7, Vector_v_y_mag_7, Vector_v_z_mag_7, Vector_v_r_mag_7, Vector_v_phi_mag_7, Vector_v_perp_mag_7, Vector_v_0_mag_7, Vector_force_mag_7, Vector_condition_color_mag_7, Vector_mu_mag_7, Vector_B_mag_7);


			out_txt_traectory_cyl_one("out_traectory_cyl_1.txt", Vector_r_cyl_1, Vector_z_cyl_1, L_1, Vector_x_cyl_1, Vector_y_cyl_1, Vector_color_cyl_1, Vector_rr_cyl_1, Vector_out_cyl_1, Vector_phi_cyl_1, Vector_psi_cyl_1, Vector_theta_cyl_1, Vector_v_x_cyl_1, Vector_v_y_cyl_1, Vector_v_z_cyl_1, Vector_v_r_cyl_1, Vector_v_phi_cyl_1, Vector_v_perp_cyl_1, Vector_v_0_cyl_1, Vector_force_cyl_1, Vector_condition_color_cyl_1, Vector_mu_cyl_1, Vector_B_cyl_1);
			out_txt_traectory_cyl_one("out_traectory_cyl_2.txt", Vector_r_cyl_2, Vector_z_cyl_2, L_1 + L_2, Vector_x_cyl_2, Vector_y_cyl_2, Vector_color_cyl_2, Vector_rr_cyl_2, Vector_out_cyl_2, Vector_phi_cyl_2, Vector_psi_cyl_2, Vector_theta_cyl_2, Vector_v_x_cyl_2, Vector_v_y_cyl_2, Vector_v_z_cyl_2, Vector_v_r_cyl_2, Vector_v_phi_cyl_2, Vector_v_perp_cyl_2, Vector_v_0_cyl_2, Vector_force_cyl_2, Vector_condition_color_cyl_2, Vector_mu_cyl_2, Vector_B_cyl_2);
			out_txt_traectory_cyl_one("out_traectory_cyl_3.txt", Vector_r_cyl_3, Vector_z_cyl_3, L_1 + L_2 + L_3, Vector_x_cyl_3, Vector_y_cyl_3, Vector_color_cyl_3, Vector_rr_cyl_3, Vector_out_cyl_3, Vector_phi_cyl_3, Vector_psi_cyl_3, Vector_theta_cyl_3, Vector_v_x_cyl_3, Vector_v_y_cyl_3, Vector_v_z_cyl_3, Vector_v_r_cyl_3, Vector_v_phi_cyl_3, Vector_v_perp_cyl_3, Vector_v_0_cyl_3, Vector_force_cyl_3, Vector_condition_color_cyl_3, Vector_mu_cyl_3, Vector_B_cyl_3);
			out_txt_traectory_cyl_one("out_traectory_cyl_4.txt", Vector_r_cyl_4, Vector_z_cyl_4, L_1 + L_2 + L_3 + L_4, Vector_x_cyl_4, Vector_y_cyl_4, Vector_color_cyl_4, Vector_rr_cyl_4, Vector_out_cyl_4, Vector_phi_cyl_4, Vector_psi_cyl_4, Vector_theta_cyl_4, Vector_v_x_cyl_4, Vector_v_y_cyl_4, Vector_v_z_cyl_4, Vector_v_r_cyl_4, Vector_v_phi_cyl_4, Vector_v_perp_cyl_4, Vector_v_0_cyl_4, Vector_force_cyl_4, Vector_condition_color_cyl_4, Vector_mu_cyl_4, Vector_B_cyl_4);
			out_txt_traectory_cyl_one("out_traectory_cyl_5.txt", Vector_r_cyl_5, Vector_z_cyl_5, L_1 + L_2 + L_3 + L_4 + L_5, Vector_x_cyl_5, Vector_y_cyl_5, Vector_color_cyl_5, Vector_rr_cyl_5, Vector_out_cyl_5, Vector_phi_cyl_5, Vector_psi_cyl_5, Vector_theta_cyl_5, Vector_v_x_cyl_5, Vector_v_y_cyl_5, Vector_v_z_cyl_5, Vector_v_r_cyl_5, Vector_v_phi_cyl_5, Vector_v_perp_cyl_5, Vector_v_0_cyl_5, Vector_force_cyl_5, Vector_condition_color_cyl_5, Vector_mu_cyl_5, Vector_B_cyl_5);
			out_txt_traectory_cyl_one("out_traectory_cyl_6.txt", Vector_r_cyl_6, Vector_z_cyl_6, L_1 + L_2 + L_3 + L_4 + L_5 + L_6, Vector_x_cyl_6, Vector_y_cyl_6, Vector_color_cyl_6, Vector_rr_cyl_6, Vector_out_cyl_6, Vector_phi_cyl_6, Vector_psi_cyl_6, Vector_theta_cyl_6, Vector_v_x_cyl_6, Vector_v_y_cyl_6, Vector_v_z_cyl_6, Vector_v_r_cyl_6, Vector_v_phi_cyl_6, Vector_v_perp_cyl_6, Vector_v_0_cyl_6, Vector_force_cyl_6, Vector_condition_color_cyl_6, Vector_mu_cyl_6, Vector_B_cyl_6);
			out_txt_traectory_cyl_one("out_traectory_cyl_7.txt", Vector_r_cyl_7, Vector_z_cyl_7, L_1 + L_2 + L_3 + L_4 + L_5 + L_6 + L_7, Vector_x_cyl_7, Vector_y_cyl_7, Vector_color_cyl_7, Vector_rr_cyl_7, Vector_out_cyl_7, Vector_phi_cyl_7, Vector_psi_cyl_7, Vector_theta_cyl_7, Vector_v_x_cyl_7, Vector_v_y_cyl_7, Vector_v_z_cyl_7, Vector_v_r_cyl_7, Vector_v_phi_cyl_7, Vector_v_perp_cyl_7, Vector_v_0_cyl_7, Vector_force_cyl_7, Vector_condition_color_cyl_7, Vector_mu_cyl_7, Vector_B_cyl_7);


			// вывод траеторий частиц в цилиндрах №1,2,3
			out_txt_traectory_CYL("out_traectory_CYL.txt", trajectory_cyl_x, trajectory_cyl_y, trajectory_cyl_z, trajectory_cyl_r, L_1 + L_2 + L_3 + L_4 + L_5 + L_6 + L_7, Vector_color_trajectory_cyl, trajectory_cyl_rr, N_mag_partitions, on_off_mag_1, on_off_mag_2, on_off_mag_3, on_off_mag_4, on_off_mag_5, on_off_mag_6, on_off_mag_7, R_source, N_CYL_partitions, i_Collision_all_1, i_Collision_all_2, i_Collision_all_3, i_Collision_all_4, i_Collision_all_5, i_Collision_all_6, i_Collision_all_7, out_trajectory_cyl, trajectory_cyl_phi, trajectory_cyl_psi, trajectory_cyl_theta, trajectory_cyl_v_x, trajectory_cyl_v_y, trajectory_cyl_v_z, trajectory_cyl_v_r, trajectory_cyl_v_phi, trajectory_cyl_v_perp, trajectory_cyl_v_0, trajectory_cyl_force, trajectory_cyl_condition_color, trajectory_cyl_mu, trajectory_cyl_B);

			out_txt_traectory_CYL_angular("out_traectory_CYL_phi.txt", trajectory_cyl_z, trajectory_cyl_r, L_1 + L_2 + L_3 + L_4 + L_5 + L_6 + L_7, Vector_color_trajectory_cyl, N_CYL_partitions, N_mag_partitions, on_off_mag_1, on_off_mag_2, on_off_mag_3, on_off_mag_4, on_off_mag_5, on_off_mag_6, on_off_mag_7, R_source, N_CYL_partitions, i_Collision_all_1, i_Collision_all_2, i_Collision_all_3, i_Collision_all_4, i_Collision_all_5, i_Collision_all_6, i_Collision_all_7, out_trajectory_cyl, trajectory_cyl_phi);

			out_txt_traectory_CYL_angular("out_traectory_CYL_psi.txt", trajectory_cyl_z, trajectory_cyl_r, L_1 + L_2 + L_3 + L_4 + L_5 + L_6 + L_7, Vector_color_trajectory_cyl, N_CYL_partitions, N_mag_partitions, on_off_mag_1, on_off_mag_2, on_off_mag_3, on_off_mag_4, on_off_mag_5, on_off_mag_6, on_off_mag_7, R_source, N_CYL_partitions, i_Collision_all_1, i_Collision_all_2, i_Collision_all_3, i_Collision_all_4, i_Collision_all_5, i_Collision_all_6, i_Collision_all_7, out_trajectory_cyl, trajectory_cyl_psi);


			out_txt_traectory_CYL_force("out_traectory_CYL_force.txt", trajectory_cyl_z, trajectory_cyl_r, trajectory_cyl_force, Vector_color_trajectory_cyl, L_1 + L_2 + L_3 + L_4 + L_5 + L_6 + L_7, N_CYL_partitions, N_mag_partitions, on_off_mag_1, on_off_mag_2, on_off_mag_3, on_off_mag_4, on_off_mag_5, on_off_mag_6, on_off_mag_7, R_source, N_CYL_partitions, i_Collision_all_1, i_Collision_all_2, i_Collision_all_3, i_Collision_all_4, i_Collision_all_5, i_Collision_all_6, i_Collision_all_7, out_trajectory_cyl);

			out_txt_traectory_CYL_mu("out_traectory_CYL_mu.txt", trajectory_cyl_z, trajectory_cyl_r, trajectory_cyl_mu, Vector_color_trajectory_cyl, L_1 + L_2 + L_3 + L_4 + L_5 + L_6 + L_7, N_CYL_partitions, N_mag_partitions, on_off_mag_1, on_off_mag_2, on_off_mag_3, on_off_mag_4, on_off_mag_5, on_off_mag_6, on_off_mag_7, R_source, N_CYL_partitions, i_Collision_all_1, i_Collision_all_2, i_Collision_all_3, i_Collision_all_4, i_Collision_all_5, i_Collision_all_6, i_Collision_all_7, out_trajectory_cyl);


			out_txt_traectory_CYL_B("out_traectory_CYL_B.txt", trajectory_cyl_z, trajectory_cyl_r, trajectory_cyl_B, Vector_color_trajectory_cyl, L_1 + L_2 + L_3 + L_4 + L_5 + L_6 + L_7, N_CYL_partitions, N_mag_partitions, on_off_mag_1, on_off_mag_2, on_off_mag_3, on_off_mag_4, on_off_mag_5, on_off_mag_6, on_off_mag_7, R_source, N_CYL_partitions, i_Collision_all_1, i_Collision_all_2, i_Collision_all_3, i_Collision_all_4, i_Collision_all_5, i_Collision_all_6, i_Collision_all_7, out_trajectory_cyl);

		}

		out_txt_xy_in("out_xy_in.txt", Vector_x_in, Vector_y_in, Vector_z_in, Vector_r_in, Vector_rr_in, Vector_color_in);


		out_txt_xy_in("out_xy_in_CYL_7.txt", Vector_x_in_CYL_7, Vector_y_in_CYL_7, Vector_z_in_CYL_7, Vector_r_in_CYL_7, Vector_rr_in_CYL_7, Vector_color_in_CYL_7);

		out_txt_xy_in("out_xy_in_CYL_7_positive.txt", Vector_x_in_CYL_7_positive, Vector_y_in_CYL_7_positive, Vector_z_in_CYL_7_positive, Vector_r_in_CYL_7_positive, Vector_rr_in_CYL_7_positive, Vector_color_in_CYL_7);

		out_txt_xy_in("out_xy_in_CYL_7_negative.txt", Vector_x_in_CYL_7_negative, Vector_y_in_CYL_7_negative, Vector_z_in_CYL_7_negative, Vector_r_in_CYL_7_negative, Vector_rr_in_CYL_7_negative, Vector_color_in_CYL_7);

		out_txt_xy_in("out_xy_in_CYL_7_zero.txt", Vector_x_in_CYL_7_zero, Vector_y_in_CYL_7_zero, Vector_z_in_CYL_7_zero, Vector_r_in_CYL_7_zero, Vector_rr_in_CYL_7_zero, Vector_color_in_CYL_7);

	}
	//cout << normalization_V_0 << endl;

	long double FWHM_delta = 0.0;

	long double delta_v_min = 0.0;

	long double delta_v_max = 0.0;

	FWHM_maxwell(m_particle, temp_beam, a_V_0, b_V_0, flaq_Maxwell_mode, FWHM_delta, drift_velocity);



	//cout << FWHM_delta << endl;
	if (particle_mode == 0) {



		if (flaq_Maxwell == false) {

			v1 = mass[24];

			v2 = mass[24];

			v3 = mass[24];

			v4 = NAN;
			FWHM_delta = 0.0;

			y_title = 1000.0 / h_V_0;
		}

	}
	else {

		//cout << "масса " << m_particle << endl;
		
		v_mean_maxwell(m_particle, temp_beam, a_V_0, b_V_0, flaq_Maxwell, flaq_Maxwell_mode, drift_velocity, v1, v2, v3, v4);

	}
	out_txt_V_title("out_V_title.txt", v1, v2, v3, v4, FWHM_delta, x_title, y_title);

	//	out_magnetic_field_table("out_magnetic_field_table.txt", Vector_r_magnetic_field_table, Vector_phi_magnetic_field_table, Vector_B_magnetic_field_table, Vector_delta_B_magnetic_field_table, Vector_index_r_magnetic_field_table, index_phi_magnetic_field_table, r_min_mag_table, r_max_mag_table);

	cout << endl;

	//cout << normalization_theta_in << endl;

	cout << "Данные выведены в файл" << endl;
	cout << endl;

	cout << "Время выполнения расчета: " << search_time_ << " мин. и " << search_time__ << " сек." << endl;
	cout << endl;

	cout << NN << endl;


	delete[] mass; // высвобождение памяти одномерного динамического массива



	delete[] condition_hydrogen;



	delete[] condition_deuterium;



	delete[] condition_molecular_hydrogen;


	mass = nullptr;
	condition_hydrogen = nullptr;
	condition_deuterium = nullptr;

	condition_molecular_hydrogen = nullptr;

	Vector_x_in.clear();
	Vector_y_in.clear();
	Vector_z_in.clear();

	Vector_condition_color_in.clear();

	Vector_force_in.clear();

	//	Vector_phi_in.clear();
	//	Vector_psi_in.clear();
	//	Vector_theta_in.clear();


	Vector_r_in.clear();
	Vector_rr_in.clear();
	Vector_color_in.clear();
	out_in.clear();

	Vector_mu_in.clear();
	Vector_B_in.clear();



	Vector_x_in_CYL_7.clear();
	Vector_y_in_CYL_7.clear();
	Vector_z_in_CYL_7.clear();

	Vector_x_in_CYL_7_negative.clear();
	Vector_y_in_CYL_7_negative.clear();
	Vector_z_in_CYL_7_negative.clear();

	Vector_x_in_CYL_7_positive.clear();
	Vector_y_in_CYL_7_positive.clear();
	Vector_z_in_CYL_7_positive.clear();

	Vector_x_in_CYL_7_zero.clear();
	Vector_y_in_CYL_7_zero.clear();
	Vector_z_in_CYL_7_zero.clear();

	Vector_mu_in_CYL_7.clear();
	Vector_B_in_CYL_7.clear();

	Vector_condition_color_in_CYL_7.clear();

	Vector_force_in_CYL_7.clear();

	//	Vector_phi_in_CYL_3.clear();
	//	Vector_psi_in_CYL_3.clear();
	//	Vector_theta_in_CYL_3.clear();


	Vector_r_in_CYL_7.clear();
	Vector_rr_in_CYL_7.clear();
	Vector_color_in_CYL_7.clear();
	out_in_CYL_7.clear();


	Vector_r_in_CYL_7_positive.clear();
	Vector_rr_in_CYL_7_positive.clear();

	Vector_r_in_CYL_7_negative.clear();
	Vector_rr_in_CYL_7_negative.clear();

	Vector_r_in_CYL_7_zero.clear();
	Vector_rr_in_CYL_7_zero.clear();


	Vector_r_mag_1.clear();
	Vector_r_mag_2.clear();
	Vector_r_mag_3.clear();
	Vector_r_mag_4.clear();
	Vector_r_mag_5.clear();
	Vector_r_mag_6.clear();
	Vector_r_mag_7.clear();

	Vector_mu_mag_1.clear();
	Vector_B_mag_1.clear();

	Vector_mu_mag_2.clear();
	Vector_B_mag_2.clear();

	Vector_mu_mag_3.clear();
	Vector_B_mag_3.clear();

	Vector_mu_mag_4.clear();
	Vector_B_mag_4.clear();

	Vector_mu_mag_5.clear();
	Vector_B_mag_5.clear();

	Vector_mu_mag_6.clear();
	Vector_B_mag_6.clear();

	Vector_mu_mag_7.clear();
	Vector_B_mag_7.clear();

	Vector_condition_color_mag_1.clear();
	Vector_condition_color_mag_2.clear();
	Vector_condition_color_mag_3.clear();
	Vector_condition_color_mag_4.clear();
	Vector_condition_color_mag_5.clear();
	Vector_condition_color_mag_6.clear();
	Vector_condition_color_mag_7.clear();

	Vector_force_mag_1.clear();
	Vector_force_mag_2.clear();
	Vector_force_mag_3.clear();
	Vector_force_mag_4.clear();
	Vector_force_mag_5.clear();
	Vector_force_mag_6.clear();
	Vector_force_mag_7.clear();



	Vector_rr_mag_1.clear();
	Vector_rr_mag_2.clear();
	Vector_rr_mag_3.clear();
	Vector_rr_mag_4.clear();
	Vector_rr_mag_5.clear();
	Vector_rr_mag_6.clear();
	Vector_rr_mag_7.clear();


	Vector_z_mag_1.clear();
	Vector_z_mag_2.clear();
	Vector_z_mag_3.clear();
	Vector_z_mag_4.clear();
	Vector_z_mag_5.clear();
	Vector_z_mag_6.clear();
	Vector_z_mag_7.clear();


	Vector_x_mag_1.clear();
	Vector_x_mag_2.clear();
	Vector_x_mag_3.clear();
	Vector_x_mag_4.clear();
	Vector_x_mag_5.clear();
	Vector_x_mag_6.clear();
	Vector_x_mag_7.clear();

	Vector_y_mag_1.clear();
	Vector_y_mag_2.clear();
	Vector_y_mag_3.clear();
	Vector_y_mag_4.clear();
	Vector_y_mag_5.clear();
	Vector_y_mag_6.clear();
	Vector_y_mag_7.clear();


	Vector_color_mag_1.clear();
	Vector_color_mag_2.clear();
	Vector_color_mag_3.clear();
	Vector_color_mag_4.clear();
	Vector_color_mag_5.clear();
	Vector_color_mag_6.clear();
	Vector_color_mag_7.clear();


	Vector_out_mag_1.clear();
	Vector_out_mag_2.clear();
	Vector_out_mag_3.clear();
	Vector_out_mag_4.clear();
	Vector_out_mag_5.clear();
	Vector_out_mag_6.clear();
	Vector_out_mag_7.clear();



	Vector_v_x_mag_1.clear();
	Vector_v_y_mag_1.clear();
	Vector_v_z_mag_1.clear();
	Vector_v_r_mag_1.clear();
	Vector_v_phi_mag_1.clear();
	Vector_v_perp_mag_1.clear();
	Vector_v_0_mag_1.clear();


	Vector_v_x_mag_2.clear();
	Vector_v_y_mag_2.clear();
	Vector_v_z_mag_2.clear();
	Vector_v_r_mag_2.clear();
	Vector_v_phi_mag_2.clear();
	Vector_v_perp_mag_2.clear();
	Vector_v_0_mag_2.clear();




	Vector_v_x_mag_3.clear();
	Vector_v_y_mag_3.clear();
	Vector_v_z_mag_3.clear();
	Vector_v_r_mag_3.clear();
	Vector_v_phi_mag_3.clear();
	Vector_v_perp_mag_3.clear();
	Vector_v_0_mag_3.clear();



	Vector_v_x_mag_4.clear();
	Vector_v_y_mag_4.clear();
	Vector_v_z_mag_4.clear();
	Vector_v_r_mag_4.clear();
	Vector_v_phi_mag_4.clear();
	Vector_v_perp_mag_4.clear();
	Vector_v_0_mag_4.clear();


	Vector_v_x_mag_5.clear();
	Vector_v_y_mag_5.clear();
	Vector_v_z_mag_5.clear();
	Vector_v_r_mag_5.clear();
	Vector_v_phi_mag_5.clear();
	Vector_v_perp_mag_5.clear();
	Vector_v_0_mag_5.clear();



	Vector_v_x_mag_6.clear();
	Vector_v_y_mag_6.clear();
	Vector_v_z_mag_6.clear();
	Vector_v_r_mag_6.clear();
	Vector_v_phi_mag_6.clear();
	Vector_v_perp_mag_6.clear();
	Vector_v_0_mag_6.clear();



	Vector_v_x_mag_7.clear();
	Vector_v_y_mag_7.clear();
	Vector_v_z_mag_7.clear();
	Vector_v_r_mag_7.clear();
	Vector_v_phi_mag_7.clear();
	Vector_v_perp_mag_7.clear();
	Vector_v_0_mag_7.clear();



	Vector_v_x_cyl_1.clear();
	Vector_v_y_cyl_1.clear();
	Vector_v_z_cyl_1.clear();
	Vector_v_r_cyl_1.clear();
	Vector_v_phi_cyl_1.clear();
	Vector_v_perp_cyl_1.clear();
	Vector_v_0_cyl_1.clear();

	Vector_mu_cyl_1.clear();
	Vector_B_cyl_1.clear();

	Vector_mu_cyl_2.clear();
	Vector_B_cyl_2.clear();

	Vector_mu_cyl_3.clear();
	Vector_B_cyl_3.clear();

	Vector_mu_cyl_4.clear();
	Vector_B_cyl_4.clear();

	Vector_mu_cyl_5.clear();
	Vector_B_cyl_5.clear();

	Vector_mu_cyl_6.clear();
	Vector_B_cyl_6.clear();

	Vector_mu_cyl_7.clear();
	Vector_B_cyl_7.clear();




	Vector_condition_color_cyl_1.clear();

	Vector_force_cyl_1.clear();


	Vector_v_x_cyl_2.clear();
	Vector_v_y_cyl_2.clear();
	Vector_v_z_cyl_2.clear();
	Vector_v_r_cyl_2.clear();
	Vector_v_phi_cyl_2.clear();
	Vector_v_perp_cyl_2.clear();
	Vector_v_0_cyl_2.clear();

	Vector_condition_color_cyl_2.clear();
	Vector_force_cyl_2.clear();


	Vector_v_x_cyl_3.clear();
	Vector_v_y_cyl_3.clear();
	Vector_v_z_cyl_3.clear();
	Vector_v_r_cyl_3.clear();
	Vector_v_phi_cyl_3.clear();
	Vector_v_perp_cyl_3.clear();
	Vector_v_0_cyl_3.clear();
	
	Vector_condition_color_cyl_3.clear();
   	Vector_force_cyl_3.clear();



	Vector_v_x_cyl_4.clear();
	Vector_v_y_cyl_4.clear();
	Vector_v_z_cyl_4.clear();
	Vector_v_r_cyl_4.clear();
	Vector_v_phi_cyl_4.clear();
	Vector_v_perp_cyl_4.clear();
	Vector_v_0_cyl_4.clear();
	
	Vector_condition_color_cyl_4.clear();
	Vector_force_cyl_4.clear();

	Vector_v_x_cyl_5.clear();
	Vector_v_y_cyl_5.clear();
	Vector_v_z_cyl_5.clear();
	Vector_v_r_cyl_5.clear();
	Vector_v_phi_cyl_5.clear();
	Vector_v_perp_cyl_5.clear();
	Vector_v_0_cyl_5.clear();

	Vector_condition_color_cyl_5.clear();
	Vector_force_cyl_5.clear();

	Vector_v_x_cyl_6.clear();
	Vector_v_y_cyl_6.clear();
	Vector_v_z_cyl_6.clear();
	Vector_v_r_cyl_6.clear();
	Vector_v_phi_cyl_6.clear();
	Vector_v_perp_cyl_6.clear();
	Vector_v_0_cyl_6.clear();

	Vector_condition_color_cyl_6.clear();
	Vector_force_cyl_6.clear();


	Vector_v_x_cyl_7.clear();
	Vector_v_y_cyl_7.clear();
	Vector_v_z_cyl_7.clear();
	Vector_v_r_cyl_7.clear();
	Vector_v_phi_cyl_7.clear();
	Vector_v_perp_cyl_7.clear();
	Vector_v_0_cyl_7.clear();

	//Vector_condition_color_cyl_7.clear();
	Vector_force_cyl_7.clear();




	Vector_v_x_in.clear();
	Vector_v_y_in.clear();
	Vector_v_z_in.clear();
	Vector_v_r_in.clear();
	Vector_v_phi_in.clear();
	Vector_v_perp_in.clear();
	Vector_v_0_in.clear();

	//Vector_force_in.clear();


	Vector_v_x_in_CYL_7.clear();
	Vector_v_y_in_CYL_7.clear();
	Vector_v_z_in_CYL_7.clear();
	Vector_v_r_in_CYL_7.clear();
	Vector_v_phi_in_CYL_7.clear();
	Vector_v_perp_in_CYL_7.clear();
	Vector_v_0_in_CYL_7.clear();
	Vector_condition_color_cyl_7.clear();

	//	Vector_force_in_CYL_3.clear();




	trajectory_cyl_x.clear();
	trajectory_cyl_y.clear();

	trajectory_cyl_mu.clear();
	trajectory_cyl_B.clear();

	trajectory_cyl_z.clear();
	trajectory_cyl_r.clear();
	trajectory_cyl_rr.clear();
	Vector_color_trajectory_cyl.clear();
	out_trajectory_cyl.clear();
	//trajectory_cyl_force.clear();
	trajectory_cyl_condition_color.clear();

	trajectory_temp_cyl_x.clear();
	trajectory_temp_cyl_y.clear();

	trajectory_temp_cyl_mu.clear();
	trajectory_temp_cyl_B.clear();

	trajectory_temp_cyl_z.clear();
	trajectory_temp_cyl_r.clear();
	trajectory_temp_cyl_rr.clear();
	Vector_color_trajectory_temp_cyl.clear();
	out_trajectory_temp_cyl.clear();
	//trajectory_temp_cyl_force.clear();
	trajectory_temp_cyl_condition_color.clear();

	Vector_temp_r_mag.clear();
	Vector_temp_rr_mag.clear();

	Vector_temp_mu_mag.clear();
	Vector_temp_B_mag.clear();

	Vector_temp_z_mag.clear();
	Vector_temp_x_mag.clear();
	Vector_temp_y_mag.clear();
	Vector_temp_color_mag.clear();
	Vector_temp_out_mag.clear();
	Vector_temp_force_mag.clear();

	trajectory_temp_cyl_v_x.clear();
	trajectory_temp_cyl_v_y.clear();
	trajectory_temp_cyl_v_z.clear();
	trajectory_temp_cyl_v_r.clear();
	trajectory_temp_cyl_v_phi.clear();
	trajectory_temp_cyl_v_perp.clear();
	trajectory_temp_cyl_v_0.clear();
	trajectory_temp_cyl_force.clear();


	trajectory_cyl_v_x.clear();
	trajectory_cyl_v_y.clear();
	trajectory_cyl_v_z.clear();
	trajectory_cyl_v_r.clear();
	trajectory_cyl_v_phi.clear();
	trajectory_cyl_v_perp.clear();
	trajectory_cyl_v_0.clear();
	trajectory_cyl_force.clear();


	Vector_r_cyl_1.clear();
	Vector_r_cyl_2.clear();
	Vector_r_cyl_3.clear();
	Vector_r_cyl_4.clear();
	Vector_r_cyl_5.clear();
	Vector_r_cyl_6.clear();
	Vector_r_cyl_7.clear();

	//Vector_force_cyl_1.clear();
	//Vector_force_cyl_2.clear();
	//Vector_force_cyl_3.clear();


	Vector_rr_cyl_1.clear();
	Vector_rr_cyl_2.clear();
	Vector_rr_cyl_3.clear();
	Vector_rr_cyl_4.clear();
	Vector_rr_cyl_5.clear();
	Vector_rr_cyl_6.clear();
	Vector_rr_cyl_7.clear();


	Vector_z_cyl_1.clear();
	Vector_z_cyl_2.clear();
	Vector_z_cyl_3.clear();
	Vector_z_cyl_4.clear();
	Vector_z_cyl_5.clear();
	Vector_z_cyl_6.clear();
	Vector_z_cyl_7.clear();


	Vector_x_cyl_1.clear();
	Vector_x_cyl_2.clear();
	Vector_x_cyl_3.clear();
	Vector_x_cyl_4.clear();
	Vector_x_cyl_5.clear();
	Vector_x_cyl_6.clear();
	Vector_x_cyl_7.clear();


	Vector_y_cyl_1.clear();
	Vector_y_cyl_2.clear();
	Vector_y_cyl_3.clear();
	Vector_y_cyl_4.clear();
	Vector_y_cyl_5.clear();
	Vector_y_cyl_6.clear();
	Vector_y_cyl_7.clear();


	Vector_temp_v_x_mag.clear();
	Vector_temp_v_y_mag.clear();
	Vector_temp_v_z_mag.clear();
	Vector_temp_v_r_mag.clear();
	Vector_temp_v_phi_mag.clear();
	Vector_temp_v_perp_mag.clear();
	Vector_temp_v_0_mag.clear();
	//Vector_temp_force_mag.clear();
	Vector_temp_condition_color_mag.clear();

	Vector_color_cyl_1.clear();
	Vector_color_cyl_2.clear();
	Vector_color_cyl_3.clear();
	Vector_color_cyl_4.clear();
	Vector_color_cyl_5.clear();
	Vector_color_cyl_6.clear();
	Vector_color_cyl_7.clear();

	Vector_out_cyl_1.clear();
	Vector_out_cyl_2.clear();
	Vector_out_cyl_3.clear();
	Vector_out_cyl_4.clear();
	Vector_out_cyl_5.clear();
	Vector_out_cyl_6.clear();
	Vector_out_cyl_7.clear();


	Vector_phi_cyl_1.clear();
	Vector_psi_cyl_1.clear();
	Vector_theta_cyl_1.clear();


	Vector_phi_cyl_2.clear();
	Vector_psi_cyl_2.clear();
	Vector_theta_cyl_2.clear();


	Vector_phi_cyl_3.clear();
	Vector_psi_cyl_3.clear();
	Vector_theta_cyl_3.clear();


	Vector_phi_cyl_4.clear();
	Vector_psi_cyl_4.clear();
	Vector_theta_cyl_4.clear();

	Vector_phi_cyl_5.clear();
	Vector_psi_cyl_5.clear();
	Vector_theta_cyl_5.clear();

	Vector_phi_cyl_6.clear();
	Vector_psi_cyl_6.clear();
	Vector_theta_cyl_6.clear();

	Vector_phi_cyl_7.clear();
	Vector_psi_cyl_7.clear();
	Vector_theta_cyl_7.clear();



	Vector_phi_mag_1.clear();
	Vector_psi_mag_1.clear();
	Vector_theta_mag_1.clear();

	Vector_phi_mag_2.clear();
	Vector_psi_mag_2.clear();
	Vector_theta_mag_2.clear();

	Vector_phi_mag_3.clear();
	Vector_psi_mag_3.clear();
	Vector_theta_mag_3.clear();

	Vector_phi_mag_4.clear();
	Vector_psi_mag_4.clear();
	Vector_theta_mag_4.clear();

	Vector_phi_mag_5.clear();
	Vector_psi_mag_5.clear();
	Vector_theta_mag_5.clear();

	Vector_phi_mag_6.clear();
	Vector_psi_mag_6.clear();
	Vector_theta_mag_6.clear();

	Vector_phi_mag_7.clear();
	Vector_psi_mag_7.clear();
	Vector_theta_mag_7.clear();




	trajectory_cyl_phi.clear();
	trajectory_cyl_psi.clear();
	trajectory_cyl_theta.clear();


	trajectory_temp_cyl_phi.clear();
	trajectory_temp_cyl_psi.clear();
	trajectory_temp_cyl_theta.clear();


	Vector_temp_phi_mag.clear();
	Vector_temp_psi_mag.clear();
	Vector_temp_theta_mag.clear();




	Vector_phi_in.clear();
	Vector_psi_in.clear();
	Vector_theta_in.clear();


	Vector_phi_in_CYL_7.clear();
	Vector_psi_in_CYL_7.clear();
	Vector_theta_in_CYL_7.clear();


	Vector_phi_in_CYL_7_negative.clear();
	Vector_psi_in_CYL_7_negative.clear();
	Vector_theta_in_CYL_7_negative.clear();

	Vector_phi_in_CYL_7_positive.clear();
	Vector_psi_in_CYL_7_positive.clear();
	Vector_theta_in_CYL_7_positive.clear();

	Vector_phi_in_CYL_7_zero.clear();
	Vector_psi_in_CYL_7_zero.clear();
	Vector_theta_in_CYL_7_zero.clear();


	Vector_r_magnetic_field_table.clear();
	Vector_phi_magnetic_field_table.clear();
	Vector_B_magnetic_field_table.clear();
	Vector_delta_B_magnetic_field_table.clear();
	Vector_index_r_magnetic_field_table.clear();






	/*




	Vector_r_mag_1.~vector();
	Vector_r_mag_2.~vector();
	Vector_r_mag_3.~vector();

	Vector_z_mag_1.~vector();
	Vector_z_mag_2.~vector();
	Vector_z_mag_3.~vector();


	Vector_x_mag_1.~vector();
	Vector_x_mag_2.~vector();
	Vector_x_mag_3.~vector();

	Vector_y_mag_1.~vector();
	Vector_y_mag_2.~vector();
	Vector_y_mag_3.~vector();


	trajectory_cyl_x.~vector();
	trajectory_cyl_y.~vector();
	trajectory_cyl_z.~vector();
	trajectory_cyl_r.~vector();


	*/

	long double N_0 = 0.0;

	if (flaq_angular_coefficient == true) {
		printf("N_tube/N_0 = %.9Le +/- %.9Le штук\n", (long double)n_tube_y0_x0 / (N / phi_1_2_new), (long double)pow(n_tube_y0_x0, 1.0 / 2.0) / (N / phi_1_2_new));
		printf("N_0 = %.9Le штук\n", N / phi_1_2_new);
		N_0 = N / phi_1_2_new;

	}
	else if (flaq_angular_coefficient == false) {

		printf("N_tube/N_0 = %.9Le +/- %.9Le штук штук\n", (long double)n_tube_y0_x0 / N, (long double)pow(n_tube_y0_x0, 1.0 / 2.0) / N);
		printf("N_0 = %.9Le штук\n", (long double)N);
		N_0 = (long double)N;
	}



	cout << "число чатсиц из сопла" << N_0 << endl;

	cout << "N_- cyl_1= " << N_negative_cyl_1 << " +/- " << pow(N_negative_cyl_1, 1.0 / 2.0) << " N_0 cyl_1= " << N_zero_cyl_1 << " +/- " << pow(N_zero_cyl_1, 1.0 / 2.0) << " N_+ cyl_1= " << N_positive_cyl_1 << " +/- " << pow(N_positive_cyl_1, 1.0 / 2.0) << " N_all cyl_1= " << (N_negative_cyl_1 + N_zero_cyl_1 + N_positive_cyl_1) << " +/- " << pow(N_negative_cyl_1 + N_zero_cyl_1 + N_positive_cyl_1, 1.0 / 2.0) << endl;
	cout << "N_- cyl_2= " << N_negative_cyl_2 << " +/- " << pow(N_negative_cyl_2, 1.0 / 2.0) << " N_0 cyl_2= " << N_zero_cyl_2 << " +/- " << pow(N_zero_cyl_2, 1.0 / 2.0) << " N_+ cyl_2= " << N_positive_cyl_2 << " +/- " << pow(N_positive_cyl_2, 1.0 / 2.0) << " N_all cyl_2= " << (N_negative_cyl_2 + N_zero_cyl_2 + N_positive_cyl_2) << " +/- " << pow(N_negative_cyl_2 + N_zero_cyl_2 + N_positive_cyl_2, 1.0 / 2.0) << endl;
	cout << "N_- cyl_3= " << N_negative_cyl_3 << " +/- " << pow(N_negative_cyl_3, 1.0 / 2.0) << " N_0 cyl_3= " << N_zero_cyl_3 << " +/- " << pow(N_zero_cyl_3, 1.0 / 2.0) << " N_+ cyl_3= " << N_positive_cyl_3 << " +/- " << pow(N_positive_cyl_3, 1.0 / 2.0) << " N_all cyl_3= " << (N_negative_cyl_3 + N_zero_cyl_3 + N_positive_cyl_3) << " +/- " << pow(N_negative_cyl_3 + N_zero_cyl_3 + N_positive_cyl_3, 1.0 / 2.0) << endl;
	cout << "N_- cyl_4= " << N_negative_cyl_4 << " +/- " << pow(N_negative_cyl_4, 1.0 / 2.0) << " N_0 cyl_4= " << N_zero_cyl_4 << " +/- " << pow(N_zero_cyl_4, 1.0 / 2.0) << " N_+ cyl_4= " << N_positive_cyl_4 << " +/- " << pow(N_positive_cyl_4, 1.0 / 2.0) << " N_all cyl_4= " << (N_negative_cyl_4 + N_zero_cyl_4 + N_positive_cyl_4) << " +/- " << pow(N_negative_cyl_4 + N_zero_cyl_4 + N_positive_cyl_4, 1.0 / 2.0) << endl;
	cout << "N_- cyl_5= " << N_negative_cyl_5 << " +/- " << pow(N_negative_cyl_5, 1.0 / 2.0) << " N_0 cyl_5= " << N_zero_cyl_5 << " +/- " << pow(N_zero_cyl_5, 1.0 / 2.0) << " N_+ cyl_5= " << N_positive_cyl_5 << " +/- " << pow(N_positive_cyl_5, 1.0 / 2.0) << " N_all cyl_5= " << (N_negative_cyl_5 + N_zero_cyl_5 + N_positive_cyl_5) << " +/- " << pow(N_negative_cyl_5 + N_zero_cyl_5 + N_positive_cyl_5, 1.0 / 2.0) << endl;
	cout << "N_- cyl_6= " << N_negative_cyl_6 << " +/- " << pow(N_negative_cyl_6, 1.0 / 2.0) << " N_0 cyl_6= " << N_zero_cyl_6 << " +/- " << pow(N_zero_cyl_6, 1.0 / 2.0) << " N_+ cyl_6= " << N_positive_cyl_6 << " +/- " << pow(N_positive_cyl_6, 1.0 / 2.0) << " N_all cyl_6= " << (N_negative_cyl_6 + N_zero_cyl_6 + N_positive_cyl_6) << " +/- " << pow(N_negative_cyl_6 + N_zero_cyl_6 + N_positive_cyl_6, 1.0 / 2.0) << endl;
	cout << "N_- cyl_7= " << N_negative_cyl_7 << " +/- " << pow(N_negative_cyl_7, 1.0 / 2.0) << " N_0 cyl_7= " << N_zero_cyl_7 << " +/- " << pow(N_zero_cyl_7, 1.0 / 2.0) << " N_+ cyl_6= " << N_positive_cyl_7 << " +/- " << pow(N_positive_cyl_7, 1.0 / 2.0) << " N_all cyl_7= " << (N_negative_cyl_7 + N_zero_cyl_7 + N_positive_cyl_7) << " +/- " << pow(N_negative_cyl_7 + N_zero_cyl_7 + N_positive_cyl_7, 1.0 / 2.0) << endl;




	cout << endl;

	cout << "N_- cyl_1= " << N_negative_cyl_1 / N_0 << " +/- " << pow(N_negative_cyl_1, 1.0 / 2.0) / N_0 << " N_0 cyl_1= " << N_zero_cyl_1 / N_0 << " +/- " << pow(N_zero_cyl_1, 1.0 / 2.0) / N_0 << " N_+ cyl_1= " << N_positive_cyl_1 / N_0 << " +/- " << pow(N_positive_cyl_1, 1.0 / 2.0) / N_0 << " N_all cyl_1= " << (N_negative_cyl_1 + N_zero_cyl_1 + N_positive_cyl_1) / N_0 << " +/- " << pow(N_negative_cyl_1 + N_zero_cyl_1 + N_positive_cyl_1, 1.0 / 2.0) / N_0 << endl;
	cout << "N_- cyl_2= " << N_negative_cyl_2 / N_0 << " +/- " << pow(N_negative_cyl_2, 1.0 / 2.0) / N_0 << " N_0 cyl_2= " << N_zero_cyl_2 / N_0 << " +/- " << pow(N_zero_cyl_2, 1.0 / 2.0) / N_0 << " N_+ cyl_2= " << N_positive_cyl_2 / N_0 << " +/- " << pow(N_positive_cyl_2, 1.0 / 2.0) / N_0 << " N_all cyl_2= " << (N_negative_cyl_2 + N_zero_cyl_2 + N_positive_cyl_2) / N_0 << " +/- " << pow(N_negative_cyl_2 + N_zero_cyl_2 + N_positive_cyl_2, 1.0 / 2.0) / N_0 << endl;
	cout << "N_- cyl_3= " << N_negative_cyl_3 / N_0 << " +/- " << pow(N_negative_cyl_3, 1.0 / 2.0) / N_0 << " N_0 cyl_3= " << N_zero_cyl_3 / N_0 << " +/- " << pow(N_zero_cyl_3, 1.0 / 2.0) / N_0 << " N_+ cyl_3= " << N_positive_cyl_3 / N_0 << " +/- " << pow(N_positive_cyl_3, 1.0 / 2.0) / N_0 << " N_all cyl_3= " << (N_negative_cyl_3 + N_zero_cyl_3 + N_positive_cyl_3) / N_0 << " +/- " << pow(N_negative_cyl_3 + N_zero_cyl_3 + N_positive_cyl_3, 1.0 / 2.0) / N_0 << endl;
	cout << "N_- cyl_4= " << N_negative_cyl_4 / N_0 << " +/- " << pow(N_negative_cyl_4, 1.0 / 2.0) / N_0 << " N_0 cyl_4= " << N_zero_cyl_4 / N_0 << " +/- " << pow(N_zero_cyl_4, 1.0 / 2.0) / N_0 << " N_+ cyl_4= " << N_positive_cyl_4 / N_0 << " +/- " << pow(N_positive_cyl_4, 1.0 / 2.0) / N_0 << " N_all cyl_4= " << (N_negative_cyl_4 + N_zero_cyl_4 + N_positive_cyl_4) / N_0 << " +/- " << pow(N_negative_cyl_4 + N_zero_cyl_4 + N_positive_cyl_4, 1.0 / 2.0) / N_0 << endl;
	cout << "N_- cyl_5= " << N_negative_cyl_5 / N_0 << " +/- " << pow(N_negative_cyl_5, 1.0 / 2.0) / N_0 << " N_0 cyl_5= " << N_zero_cyl_5 / N_0 << " +/- " << pow(N_zero_cyl_5, 1.0 / 2.0) / N_0 << " N_+ cyl_5= " << N_positive_cyl_5 / N_0 << " +/- " << pow(N_positive_cyl_5, 1.0 / 2.0) / N_0 << " N_all cyl_5= " << (N_negative_cyl_5 + N_zero_cyl_5 + N_positive_cyl_5) / N_0 << " +/- " << pow(N_negative_cyl_5 + N_zero_cyl_5 + N_positive_cyl_5, 1.0 / 2.0) / N_0 << endl;
	cout << "N_- cyl_6= " << N_negative_cyl_6 / N_0 << " +/- " << pow(N_negative_cyl_6, 1.0 / 2.0) / N_0 << " N_0 cyl_6= " << N_zero_cyl_6 / N_0 << " +/- " << pow(N_zero_cyl_6, 1.0 / 2.0) / N_0 << " N_+ cyl_6= " << N_positive_cyl_6 / N_0 << " +/- " << pow(N_positive_cyl_6, 1.0 / 2.0) / N_0 << " N_all cyl_6= " << (N_negative_cyl_6 + N_zero_cyl_6 + N_positive_cyl_6) / N_0 << " +/- " << pow(N_negative_cyl_6 + N_zero_cyl_6 + N_positive_cyl_6, 1.0 / 2.0) / N_0 << endl;
	cout << "N_- cyl_7= " << N_negative_cyl_7 / N_0 << " +/- " << pow(N_negative_cyl_7, 1.0 / 2.0) / N_0 << " N_0 cyl_7= " << N_zero_cyl_7 / N_0 << " +/- " << pow(N_zero_cyl_7, 1.0 / 2.0) / N_0 << " N_+ cyl_7= " << N_positive_cyl_7 / N_0 << " +/- " << pow(N_positive_cyl_7, 1.0 / 2.0) / N_0 << " N_all cyl_7= " << (N_negative_cyl_7 + N_zero_cyl_7 + N_positive_cyl_7) / N_0 << " +/- " << pow(N_negative_cyl_7 + N_zero_cyl_7 + N_positive_cyl_7, 1.0 / 2.0) / N_0 << endl;




	cout << endl;

	cout << "N_- mag_1= " << N_negative_mag_1 << " +/- " << pow(N_negative_mag_1, 1.0 / 2.0) << " N_0 mag_1= " << N_zero_mag_1 << " +/- " << pow(N_zero_mag_1, 1.0 / 2.0) << " N_+ mag_1= " << N_positive_mag_1 << " +/- " << pow(N_positive_mag_1, 1.0 / 2.0) << " N_all mag_1= " << (N_negative_mag_1 + N_zero_mag_1 + N_positive_mag_1) << " +/- " << pow(N_negative_mag_1 + N_zero_mag_1 + N_positive_mag_1, 1.0 / 2.0) << endl;
	cout << "N_- mag_2= " << N_negative_mag_2 << " +/- " << pow(N_negative_mag_2, 1.0 / 2.0) << " N_0 mag_2= " << N_zero_mag_2 << " +/- " << pow(N_zero_mag_2, 1.0 / 2.0) << " N_+ mag_2= " << N_positive_mag_2 << " +/- " << pow(N_positive_mag_2, 1.0 / 2.0) << " N_all mag_2= " << (N_negative_mag_2 + N_zero_mag_2 + N_positive_mag_2) << " +/- " << pow(N_negative_mag_2 + N_zero_mag_2 + N_positive_mag_2, 1.0 / 2.0) << endl;
	cout << "N_- mag_3= " << N_negative_mag_3 << " +/- " << pow(N_negative_mag_3, 1.0 / 2.0) << " N_0 mag_3= " << N_zero_mag_3 << " +/- " << pow(N_zero_mag_3, 1.0 / 2.0) << " N_+ mag_3= " << N_positive_mag_3 << " +/- " << pow(N_positive_mag_3, 1.0 / 2.0) << " N_all mag_3= " << (N_negative_mag_3 + N_zero_mag_3 + N_positive_mag_3) << " +/- " << pow(N_negative_mag_3 + N_zero_mag_3 + N_positive_mag_3, 1.0 / 2.0) << endl;
	cout << "N_- mag_4= " << N_negative_mag_4 << " +/- " << pow(N_negative_mag_4, 1.0 / 2.0) << " N_0 mag_4= " << N_zero_mag_4 << " +/- " << pow(N_zero_mag_4, 1.0 / 2.0) << " N_+ mag_4= " << N_positive_mag_4 << " +/- " << pow(N_positive_mag_4, 1.0 / 2.0) << " N_all mag_4= " << (N_negative_mag_4 + N_zero_mag_4 + N_positive_mag_4) << " +/- " << pow(N_negative_mag_4 + N_zero_mag_4 + N_positive_mag_4, 1.0 / 2.0) << endl;
	cout << "N_- mag_5= " << N_negative_mag_5 << " +/- " << pow(N_negative_mag_5, 1.0 / 2.0) << " N_0 mag_5= " << N_zero_mag_5 << " +/- " << pow(N_zero_mag_5, 1.0 / 2.0) << " N_+ mag_5= " << N_positive_mag_5 << " +/- " << pow(N_positive_mag_5, 1.0 / 2.0) << " N_all mag_5= " << (N_negative_mag_5 + N_zero_mag_5 + N_positive_mag_5) << " +/- " << pow(N_negative_mag_5 + N_zero_mag_5 + N_positive_mag_5, 1.0 / 2.0) << endl;
	cout << "N_- mag_6= " << N_negative_mag_6 << " +/- " << pow(N_negative_mag_6, 1.0 / 2.0) << " N_0 mag_6= " << N_zero_mag_6 << " +/- " << pow(N_zero_mag_6, 1.0 / 2.0) << " N_+ mag_6= " << N_positive_mag_6 << " +/- " << pow(N_positive_mag_6, 1.0 / 2.0) << " N_all mag_6= " << (N_negative_mag_6 + N_zero_mag_6 + N_positive_mag_6) << " +/- " << pow(N_negative_mag_6 + N_zero_mag_6 + N_positive_mag_6, 1.0 / 2.0) << endl;
	cout << "N_- mag_7= " << N_negative_mag_7 << " +/- " << pow(N_negative_mag_7, 1.0 / 2.0) << " N_0 mag_7= " << N_zero_mag_7 << " +/- " << pow(N_zero_mag_7, 1.0 / 2.0) << " N_+ mag_7= " << N_positive_mag_7 << " +/- " << pow(N_positive_mag_7, 1.0 / 2.0) << " N_all mag_7= " << (N_negative_mag_7 + N_zero_mag_7 + N_positive_mag_7) << " +/- " << pow(N_negative_mag_7 + N_zero_mag_7 + N_positive_mag_7, 1.0 / 2.0) << endl;




	cout << endl;

	cout << "N_- mag_1= " << N_negative_mag_1 / N_0 << " +/- " << pow(N_negative_mag_1, 1.0 / 2.0) / N_0 << " N_0 mag_1= " << N_zero_mag_1 / N_0 << " +/- " << pow(N_zero_mag_1, 1.0 / 2.0) / N_0 << " N_+ mag_1= " << N_positive_mag_1 / N_0 << " +/- " << pow(N_positive_mag_1, 1.0 / 2.0) / N_0 << " N_all mag_1= " << (N_negative_mag_1 + N_zero_mag_1 + N_positive_mag_1) / N_0 << " +/- " << pow(N_negative_mag_1 + N_zero_mag_1 + N_positive_mag_1, 1.0 / 2.0) / N_0 << endl;
	cout << "N_- mag_2= " << N_negative_mag_2 / N_0 << " +/- " << pow(N_negative_mag_2, 1.0 / 2.0) / N_0 << " N_0 mag_2= " << N_zero_mag_2 / N_0 << " +/- " << pow(N_zero_mag_2, 1.0 / 2.0) / N_0 << " N_+ mag_2= " << N_positive_mag_2 / N_0 << " +/- " << pow(N_positive_mag_2, 1.0 / 2.0) / N_0 << " N_all mag_2= " << (N_negative_mag_2 + N_zero_mag_2 + N_positive_mag_2) / N_0 << " +/- " << pow(N_negative_mag_2 + N_zero_mag_2 + N_positive_mag_2, 1.0 / 2.0) / N_0 << endl;
	cout << "N_- mag_3= " << N_negative_mag_3 / N_0 << " +/- " << pow(N_negative_mag_3, 1.0 / 2.0) / N_0 << " N_0 mag_3= " << N_zero_mag_3 / N_0 << " +/- " << pow(N_zero_mag_3, 1.0 / 2.0) / N_0 << " N_+ mag_3= " << N_positive_mag_3 / N_0 << " +/- " << pow(N_positive_mag_3, 1.0 / 2.0) / N_0 << " N_all mag_3= " << (N_negative_mag_3 + N_zero_mag_3 + N_positive_mag_3) / N_0 << " +/- " << pow(N_negative_mag_3 + N_zero_mag_3 + N_positive_mag_3, 1.0 / 2.0) / N_0 << endl;
	cout << "N_- mag_4= " << N_negative_mag_4 / N_0 << " +/- " << pow(N_negative_mag_4, 1.0 / 2.0) / N_0 << " N_0 mag_4= " << N_zero_mag_4 / N_0 << " +/- " << pow(N_zero_mag_4, 1.0 / 2.0) / N_0 << " N_+ mag_4= " << N_positive_mag_4 / N_0 << " +/- " << pow(N_positive_mag_4, 1.0 / 2.0) / N_0 << " N_all mag_4= " << (N_negative_mag_4 + N_zero_mag_4 + N_positive_mag_4) / N_0 << " +/- " << pow(N_negative_mag_4 + N_zero_mag_4 + N_positive_mag_4, 1.0 / 2.0) / N_0 << endl;
	cout << "N_- mag_5= " << N_negative_mag_5 / N_0 << " +/- " << pow(N_negative_mag_5, 1.0 / 2.0) / N_0 << " N_0 mag_5= " << N_zero_mag_5 / N_0 << " +/- " << pow(N_zero_mag_5, 1.0 / 2.0) / N_0 << " N_+ mag_5= " << N_positive_mag_5 / N_0 << " +/- " << pow(N_positive_mag_5, 1.0 / 2.0) / N_0 << " N_all mag_5= " << (N_negative_mag_5 + N_zero_mag_5 + N_positive_mag_5) / N_0 << " +/- " << pow(N_negative_mag_5 + N_zero_mag_5 + N_positive_mag_5, 1.0 / 2.0) / N_0 << endl;
	cout << "N_- mag_6= " << N_negative_mag_6 / N_0 << " +/- " << pow(N_negative_mag_6, 1.0 / 2.0) / N_0 << " N_0 mag_6= " << N_zero_mag_6 / N_0 << " +/- " << pow(N_zero_mag_6, 1.0 / 2.0) / N_0 << " N_+ mag_6= " << N_positive_mag_6 / N_0 << " +/- " << pow(N_positive_mag_6, 1.0 / 2.0) / N_0 << " N_all mag_6= " << (N_negative_mag_6 + N_zero_mag_6 + N_positive_mag_6) / N_0 << " +/- " << pow(N_negative_mag_6 + N_zero_mag_6 + N_positive_mag_6, 1.0 / 2.0) / N_0 << endl;
	cout << "N_- mag_7= " << N_negative_mag_7 / N_0 << " +/- " << pow(N_negative_mag_7, 1.0 / 2.0) / N_0 << " N_0 mag_7= " << N_zero_mag_7 / N_0 << " +/- " << pow(N_zero_mag_7, 1.0 / 2.0) / N_0 << " N_+ mag_7= " << N_positive_mag_7 / N_0 << " +/- " << pow(N_positive_mag_7, 1.0 / 2.0) / N_0 << " N_all mag_7= " << (N_negative_mag_7 + N_zero_mag_7 + N_positive_mag_7) / N_0 << " +/- " << pow(N_negative_mag_7 + N_zero_mag_7 + N_positive_mag_7, 1.0 / 2.0) / N_0 << endl;




	cout << endl;

	cout << "N_- tube= " << N_negative_tube << " +/- " << pow(N_negative_tube, 1.0 / 2.0) << " N_0 tube= " << N_zero_tube << " +/- " << pow(N_zero_tube, 1.0 / 2.0) << " N_+ tube= " << N_positive_tube << " +/- " << pow(N_positive_tube, 1.0 / 2.0) << " N_all tube= " << (N_negative_tube + N_zero_tube + N_positive_tube) << " +/- " << pow(N_negative_tube + N_zero_tube + N_positive_tube, 1.0 / 2.0) << endl;

	cout << endl;

	cout << "N_- tube= " << N_negative_tube / N_0 << " +/- " << pow(N_negative_tube, 1.0 / 2.0) / N_0 << " N_0 tube= " << N_zero_tube / N_0 << " +/- " << pow(N_zero_tube, 1.0 / 2.0) / N_0 << " N_+ tube= " << N_positive_tube / N_0 << " +/- " << pow(N_positive_tube, 1.0 / 2.0) / N_0 << " N_all tube= " << (N_negative_tube + N_zero_tube + N_positive_tube) / N_0 << " +/- " << pow(N_negative_tube + N_zero_tube + N_positive_tube, 1.0 / 2.0) / N_0 << endl;

	cout << endl;

	//	cout << N_zero_cyl_1 << endl;

	cout << "P_z_cyl_1= " << P_z(N_negative_cyl_1, N_zero_cyl_1, N_positive_cyl_1) << " +/- " << P_z_error(N_negative_cyl_1, N_zero_cyl_1, N_positive_cyl_1, еrrоr_symm_type) << endl;
	cout << "P_z_cyl_2= " << P_z(N_negative_cyl_2, N_zero_cyl_2, N_positive_cyl_2) << " +/- " << P_z_error(N_negative_cyl_2, N_zero_cyl_2, N_positive_cyl_2, еrrоr_symm_type) << endl;
	cout << "P_z_cyl_3= " << P_z(N_negative_cyl_3, N_zero_cyl_3, N_positive_cyl_3) << " +/- " << P_z_error(N_negative_cyl_3, N_zero_cyl_3, N_positive_cyl_3, еrrоr_symm_type) << endl;
	cout << "P_z_cyl_4= " << P_z(N_negative_cyl_4, N_zero_cyl_4, N_positive_cyl_4) << " +/- " << P_z_error(N_negative_cyl_4, N_zero_cyl_4, N_positive_cyl_4, еrrоr_symm_type) << endl;
	cout << "P_z_cyl_5= " << P_z(N_negative_cyl_5, N_zero_cyl_5, N_positive_cyl_5) << " +/- " << P_z_error(N_negative_cyl_5, N_zero_cyl_5, N_positive_cyl_5, еrrоr_symm_type) << endl;
	cout << "P_z_cyl_6= " << P_z(N_negative_cyl_6, N_zero_cyl_6, N_positive_cyl_6) << " +/- " << P_z_error(N_negative_cyl_6, N_zero_cyl_6, N_positive_cyl_6, еrrоr_symm_type) << endl;
	cout << "P_z_cyl_7= " << P_z(N_negative_cyl_7, N_zero_cyl_7, N_positive_cyl_7) << " +/- " << P_z_error(N_negative_cyl_7, N_zero_cyl_7, N_positive_cyl_7, еrrоr_symm_type) << endl;

	cout << endl;

	cout << "P_z_mag_1= " << P_z(N_negative_mag_1, N_zero_mag_1, N_positive_mag_1) << " +/- " << P_z_error(N_negative_mag_1, N_zero_mag_1, N_positive_mag_1, еrrоr_symm_type) << endl;
	cout << "P_z_mag_2= " << P_z(N_negative_mag_2, N_zero_mag_2, N_positive_mag_2) << " +/- " << P_z_error(N_negative_mag_2, N_zero_mag_2, N_positive_mag_2, еrrоr_symm_type) << endl;
	cout << "P_z_mag_3= " << P_z(N_negative_mag_3, N_zero_mag_3, N_positive_mag_3) << " +/- " << P_z_error(N_negative_mag_3, N_zero_mag_3, N_positive_mag_3, еrrоr_symm_type) << endl;
	cout << "P_z_mag_4= " << P_z(N_negative_mag_4, N_zero_mag_4, N_positive_mag_4) << " +/- " << P_z_error(N_negative_mag_4, N_zero_mag_4, N_positive_mag_4, еrrоr_symm_type) << endl;
	cout << "P_z_mag_5= " << P_z(N_negative_mag_5, N_zero_mag_5, N_positive_mag_5) << " +/- " << P_z_error(N_negative_mag_5, N_zero_mag_5, N_positive_mag_5, еrrоr_symm_type) << endl;
	cout << "P_z_mag_6= " << P_z(N_negative_mag_6, N_zero_mag_6, N_positive_mag_6) << " +/- " << P_z_error(N_negative_mag_6, N_zero_mag_6, N_positive_mag_6, еrrоr_symm_type) << endl;
	cout << "P_z_mag_7= " << P_z(N_negative_mag_7, N_zero_mag_7, N_positive_mag_7) << " +/- " << P_z_error(N_negative_mag_7, N_zero_mag_7, N_positive_mag_7, еrrоr_symm_type) << endl;

	cout << endl;

	cout << "P_z_tube= " << P_z(N_negative_tube, N_zero_tube, N_positive_tube) << " +/- " << P_z_error(N_negative_tube, N_zero_tube, N_positive_tube, еrrоr_symm_type) << endl;
	
	cout << endl;

	cout << "P_zz_cyl_1= " << P_zz(N_negative_cyl_1, N_zero_cyl_1, N_positive_cyl_1) << " +/- " << P_zz_error(N_negative_cyl_1, N_zero_cyl_1, N_positive_cyl_1, еrrоr_symm_type) << endl;
	cout << "P_zz_cyl_2= " << P_zz(N_negative_cyl_2, N_zero_cyl_2, N_positive_cyl_2) << " +/- " << P_zz_error(N_negative_cyl_2, N_zero_cyl_2, N_positive_cyl_2, еrrоr_symm_type) << endl;
	cout << "P_zz_cyl_3= " << P_zz(N_negative_cyl_3, N_zero_cyl_3, N_positive_cyl_3) << " +/- " << P_zz_error(N_negative_cyl_3, N_zero_cyl_3, N_positive_cyl_3, еrrоr_symm_type) << endl;
	cout << "P_zz_cyl_4= " << P_zz(N_negative_cyl_4, N_zero_cyl_4, N_positive_cyl_4) << " +/- " << P_zz_error(N_negative_cyl_4, N_zero_cyl_4, N_positive_cyl_4, еrrоr_symm_type) << endl;
	cout << "P_zz_cyl_5= " << P_zz(N_negative_cyl_5, N_zero_cyl_5, N_positive_cyl_5) << " +/- " << P_zz_error(N_negative_cyl_5, N_zero_cyl_5, N_positive_cyl_5, еrrоr_symm_type) << endl;
	cout << "P_zz_cyl_6= " << P_zz(N_negative_cyl_6, N_zero_cyl_6, N_positive_cyl_6) << " +/- " << P_zz_error(N_negative_cyl_6, N_zero_cyl_6, N_positive_cyl_6, еrrоr_symm_type) << endl;
	cout << "P_zz_cyl_7= " << P_zz(N_negative_cyl_7, N_zero_cyl_7, N_positive_cyl_7) << " +/- " << P_zz_error(N_negative_cyl_7, N_zero_cyl_7, N_positive_cyl_7, еrrоr_symm_type) << endl;


	cout << endl;
	
	cout << "P_zz_mag_1= " << P_zz(N_negative_mag_1, N_zero_mag_1, N_positive_mag_1) << " +/- " << P_zz_error(N_negative_mag_1, N_zero_mag_1, N_positive_mag_1, еrrоr_symm_type) << endl;
	cout << "P_zz_mag_2= " << P_zz(N_negative_mag_2, N_zero_mag_2, N_positive_mag_2) << " +/- " << P_zz_error(N_negative_mag_2, N_zero_mag_2, N_positive_mag_2, еrrоr_symm_type) << endl;
	cout << "P_zz_mag_3= " << P_zz(N_negative_mag_3, N_zero_mag_3, N_positive_mag_3) << " +/- " << P_zz_error(N_negative_mag_3, N_zero_mag_3, N_positive_mag_3, еrrоr_symm_type) << endl;
	cout << "P_zz_mag_4= " << P_zz(N_negative_mag_4, N_zero_mag_4, N_positive_mag_4) << " +/- " << P_zz_error(N_negative_mag_4, N_zero_mag_4, N_positive_mag_4, еrrоr_symm_type) << endl;
	cout << "P_zz_mag_5= " << P_zz(N_negative_mag_5, N_zero_mag_5, N_positive_mag_5) << " +/- " << P_zz_error(N_negative_mag_5, N_zero_mag_5, N_positive_mag_5, еrrоr_symm_type) << endl;
	cout << "P_zz_mag_6= " << P_zz(N_negative_mag_6, N_zero_mag_6, N_positive_mag_6) << " +/- " << P_zz_error(N_negative_mag_6, N_zero_mag_6, N_positive_mag_6, еrrоr_symm_type) << endl;
	cout << "P_zz_mag_7= " << P_zz(N_negative_mag_7, N_zero_mag_7, N_positive_mag_7) << " +/- " << P_zz_error(N_negative_mag_7, N_zero_mag_7, N_positive_mag_7, еrrоr_symm_type) << endl;


	cout << endl;
	
	cout << "P_zz_tube= " << P_zz(N_negative_tube, N_zero_tube, N_positive_tube) << " +/- " << P_zz_error(N_negative_tube, N_zero_tube, N_positive_tube, еrrоr_symm_type) << endl;

	cout << endl;

	cout << "FM_1_cyl_1= " << FM_1(N_negative_cyl_1, N_zero_cyl_1, N_positive_cyl_1) << " +/- " << FM_1_error(N_negative_cyl_1, N_zero_cyl_1, N_positive_cyl_1, еrrоr_symm_type) << endl;
	cout << "FM_1_cyl_2= " << FM_1(N_negative_cyl_2, N_zero_cyl_2, N_positive_cyl_2) << " +/- " << FM_1_error(N_negative_cyl_2, N_zero_cyl_2, N_positive_cyl_2, еrrоr_symm_type) << endl;
	cout << "FM_1_cyl_3= " << FM_1(N_negative_cyl_3, N_zero_cyl_3, N_positive_cyl_3) << " +/- " << FM_1_error(N_negative_cyl_3, N_zero_cyl_3, N_positive_cyl_3, еrrоr_symm_type) << endl;
	cout << "FM_1_cyl_4= " << FM_1(N_negative_cyl_4, N_zero_cyl_4, N_positive_cyl_4) << " +/- " << FM_1_error(N_negative_cyl_4, N_zero_cyl_4, N_positive_cyl_4, еrrоr_symm_type) << endl;
	cout << "FM_1_cyl_5= " << FM_1(N_negative_cyl_5, N_zero_cyl_5, N_positive_cyl_5) << " +/- " << FM_1_error(N_negative_cyl_5, N_zero_cyl_5, N_positive_cyl_5, еrrоr_symm_type) << endl;
	cout << "FM_1_cyl_6= " << FM_1(N_negative_cyl_6, N_zero_cyl_6, N_positive_cyl_6) << " +/- " << FM_1_error(N_negative_cyl_6, N_zero_cyl_6, N_positive_cyl_6, еrrоr_symm_type) << endl;
	cout << "FM_1_cyl_7= " << FM_1(N_negative_cyl_7, N_zero_cyl_7, N_positive_cyl_7) << " +/- " << FM_1_error(N_negative_cyl_7, N_zero_cyl_7, N_positive_cyl_7, еrrоr_symm_type) << endl;


	cout << endl;

	cout << "FM_1_cyl_1= " << FM_1(N_negative_cyl_1, N_zero_cyl_1, N_positive_cyl_1) / N_0 << " +/- " << FM_1_error(N_negative_cyl_1, N_zero_cyl_1, N_positive_cyl_1, еrrоr_symm_type) / N_0 << endl;
	cout << "FM_1_cyl_2= " << FM_1(N_negative_cyl_2, N_zero_cyl_2, N_positive_cyl_2) / N_0 << " +/- " << FM_1_error(N_negative_cyl_2, N_zero_cyl_2, N_positive_cyl_2, еrrоr_symm_type) / N_0 << endl;
	cout << "FM_1_cyl_3= " << FM_1(N_negative_cyl_3, N_zero_cyl_3, N_positive_cyl_3) / N_0 << " +/- " << FM_1_error(N_negative_cyl_3, N_zero_cyl_3, N_positive_cyl_3, еrrоr_symm_type) / N_0 << endl;
	cout << "FM_1_cyl_4= " << FM_1(N_negative_cyl_4, N_zero_cyl_4, N_positive_cyl_4) / N_0 << " +/- " << FM_1_error(N_negative_cyl_4, N_zero_cyl_4, N_positive_cyl_4, еrrоr_symm_type) / N_0 << endl;
	cout << "FM_1_cyl_5= " << FM_1(N_negative_cyl_5, N_zero_cyl_5, N_positive_cyl_5) / N_0 << " +/- " << FM_1_error(N_negative_cyl_5, N_zero_cyl_5, N_positive_cyl_5, еrrоr_symm_type) / N_0 << endl;
	cout << "FM_1_cyl_6= " << FM_1(N_negative_cyl_6, N_zero_cyl_6, N_positive_cyl_6) / N_0 << " +/- " << FM_1_error(N_negative_cyl_6, N_zero_cyl_6, N_positive_cyl_6, еrrоr_symm_type) / N_0 << endl;
	cout << "FM_1_cyl_7= " << FM_1(N_negative_cyl_7, N_zero_cyl_7, N_positive_cyl_7) / N_0 << " +/- " << FM_1_error(N_negative_cyl_7, N_zero_cyl_7, N_positive_cyl_7, еrrоr_symm_type) / N_0 << endl;




	cout << endl;

	cout << "FM_1_mag_1= " << FM_1(N_negative_mag_1, N_zero_mag_1, N_positive_mag_1) << " +/- " << FM_1_error(N_negative_mag_1, N_zero_mag_1, N_positive_mag_1, еrrоr_symm_type) << endl;
	cout << "FM_1_mag_2= " << FM_1(N_negative_mag_2, N_zero_mag_2, N_positive_mag_2) << " +/- " << FM_1_error(N_negative_mag_2, N_zero_mag_2, N_positive_mag_2, еrrоr_symm_type) << endl;
	cout << "FM_1_mag_3= " << FM_1(N_negative_mag_3, N_zero_mag_3, N_positive_mag_3) << " +/- " << FM_1_error(N_negative_mag_3, N_zero_mag_3, N_positive_mag_3, еrrоr_symm_type) << endl;
	cout << "FM_1_mag_4= " << FM_1(N_negative_mag_4, N_zero_mag_4, N_positive_mag_4) << " +/- " << FM_1_error(N_negative_mag_4, N_zero_mag_4, N_positive_mag_4, еrrоr_symm_type) << endl;
	cout << "FM_1_mag_5= " << FM_1(N_negative_mag_5, N_zero_mag_5, N_positive_mag_5) << " +/- " << FM_1_error(N_negative_mag_5, N_zero_mag_5, N_positive_mag_5, еrrоr_symm_type) << endl;
	cout << "FM_1_mag_6= " << FM_1(N_negative_mag_6, N_zero_mag_6, N_positive_mag_6) << " +/- " << FM_1_error(N_negative_mag_6, N_zero_mag_6, N_positive_mag_6, еrrоr_symm_type) << endl;
	cout << "FM_1_mag_7= " << FM_1(N_negative_mag_7, N_zero_mag_7, N_positive_mag_7) << " +/- " << FM_1_error(N_negative_mag_7, N_zero_mag_7, N_positive_mag_7, еrrоr_symm_type) << endl;


	cout << endl;

	cout << "FM_1_mag_1= " << FM_1(N_negative_mag_1, N_zero_mag_1, N_positive_mag_1) / N_0 << " +/- " << FM_1_error(N_negative_mag_1, N_zero_mag_1, N_positive_mag_1, еrrоr_symm_type) / N_0 << endl;
	cout << "FM_1_mag_2= " << FM_1(N_negative_mag_2, N_zero_mag_2, N_positive_mag_2) / N_0 << " +/- " << FM_1_error(N_negative_mag_2, N_zero_mag_2, N_positive_mag_2, еrrоr_symm_type) / N_0 << endl;
	cout << "FM_1_mag_3= " << FM_1(N_negative_mag_3, N_zero_mag_3, N_positive_mag_3) / N_0 << " +/- " << FM_1_error(N_negative_mag_3, N_zero_mag_3, N_positive_mag_3, еrrоr_symm_type) / N_0 << endl;
	cout << "FM_1_mag_4= " << FM_1(N_negative_mag_4, N_zero_mag_4, N_positive_mag_4) / N_0 << " +/- " << FM_1_error(N_negative_mag_4, N_zero_mag_4, N_positive_mag_4, еrrоr_symm_type) / N_0 << endl;
	cout << "FM_1_mag_5= " << FM_1(N_negative_mag_5, N_zero_mag_5, N_positive_mag_5) / N_0 << " +/- " << FM_1_error(N_negative_mag_5, N_zero_mag_5, N_positive_mag_5, еrrоr_symm_type) / N_0 << endl;
	cout << "FM_1_mag_6= " << FM_1(N_negative_mag_6, N_zero_mag_6, N_positive_mag_6) / N_0 << " +/- " << FM_1_error(N_negative_mag_6, N_zero_mag_6, N_positive_mag_6, еrrоr_symm_type) / N_0 << endl;
	cout << "FM_1_mag_7= " << FM_1(N_negative_mag_7, N_zero_mag_7, N_positive_mag_7) / N_0 << " +/- " << FM_1_error(N_negative_mag_7, N_zero_mag_7, N_positive_mag_7, еrrоr_symm_type) / N_0 << endl;


	cout << endl;

	cout << "FM_1_tube= " << FM_1(N_negative_tube, N_zero_tube, N_positive_tube) << " +/- " << FM_1_error(N_negative_tube, N_zero_tube, N_positive_tube, еrrоr_symm_type) << endl;

	cout << endl;

	cout << "FM_1_tube= " << FM_1(N_negative_tube, N_zero_tube, N_positive_tube) / N_0 << " +/- " << FM_1_error(N_negative_tube, N_zero_tube, N_positive_tube, еrrоr_symm_type) / N_0 << endl;

	cout << endl;



	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;

	cout << endl;

	cout << "FM_2_cyl_1= " << FM_2(N_negative_cyl_1, N_zero_cyl_1, N_positive_cyl_1) << " +/- " << FM_2_error(N_negative_cyl_1, N_zero_cyl_1, N_positive_cyl_1, еrrоr_symm_type) << endl;
	cout << "FM_2_cyl_2= " << FM_2(N_negative_cyl_2, N_zero_cyl_2, N_positive_cyl_2) << " +/- " << FM_2_error(N_negative_cyl_2, N_zero_cyl_2, N_positive_cyl_2, еrrоr_symm_type) << endl;
	cout << "FM_2_cyl_3= " << FM_2(N_negative_cyl_3, N_zero_cyl_3, N_positive_cyl_3) << " +/- " << FM_2_error(N_negative_cyl_3, N_zero_cyl_3, N_positive_cyl_3, еrrоr_symm_type) << endl;
	cout << "FM_2_cyl_4= " << FM_2(N_negative_cyl_4, N_zero_cyl_4, N_positive_cyl_4) << " +/- " << FM_2_error(N_negative_cyl_4, N_zero_cyl_4, N_positive_cyl_4, еrrоr_symm_type) << endl;
	cout << "FM_2_cyl_5= " << FM_2(N_negative_cyl_5, N_zero_cyl_5, N_positive_cyl_5) << " +/- " << FM_2_error(N_negative_cyl_5, N_zero_cyl_5, N_positive_cyl_5, еrrоr_symm_type) << endl;
	cout << "FM_2_cyl_6= " << FM_2(N_negative_cyl_6, N_zero_cyl_6, N_positive_cyl_6) << " +/- " << FM_2_error(N_negative_cyl_6, N_zero_cyl_6, N_positive_cyl_6, еrrоr_symm_type) << endl;
	cout << "FM_2_cyl_7= " << FM_2(N_negative_cyl_7, N_zero_cyl_7, N_positive_cyl_7) << " +/- " << FM_2_error(N_negative_cyl_7, N_zero_cyl_7, N_positive_cyl_7, еrrоr_symm_type) << endl;




	cout << endl;

	cout << "FM_2_cyl_1= " << FM_2(N_negative_cyl_1, N_zero_cyl_1, N_positive_cyl_1) / N_0 << " +/- " << FM_2_error(N_negative_cyl_1, N_zero_cyl_1, N_positive_cyl_1, еrrоr_symm_type) / N_0 << endl;
	cout << "FM_2_cyl_2= " << FM_2(N_negative_cyl_2, N_zero_cyl_2, N_positive_cyl_2) / N_0 << " +/- " << FM_2_error(N_negative_cyl_2, N_zero_cyl_2, N_positive_cyl_2, еrrоr_symm_type) / N_0 << endl;
	cout << "FM_2_cyl_3= " << FM_2(N_negative_cyl_3, N_zero_cyl_3, N_positive_cyl_3) / N_0 << " +/- " << FM_2_error(N_negative_cyl_3, N_zero_cyl_3, N_positive_cyl_3, еrrоr_symm_type) / N_0 << endl;
	cout << "FM_2_cyl_4= " << FM_2(N_negative_cyl_4, N_zero_cyl_4, N_positive_cyl_4) / N_0 << " +/- " << FM_2_error(N_negative_cyl_4, N_zero_cyl_4, N_positive_cyl_4, еrrоr_symm_type) / N_0 << endl;
	cout << "FM_2_cyl_5= " << FM_2(N_negative_cyl_5, N_zero_cyl_5, N_positive_cyl_5) / N_0 << " +/- " << FM_2_error(N_negative_cyl_5, N_zero_cyl_5, N_positive_cyl_5, еrrоr_symm_type) / N_0 << endl;
	cout << "FM_2_cyl_6= " << FM_2(N_negative_cyl_6, N_zero_cyl_6, N_positive_cyl_6) / N_0 << " +/- " << FM_2_error(N_negative_cyl_6, N_zero_cyl_6, N_positive_cyl_6, еrrоr_symm_type) / N_0 << endl;
	cout << "FM_2_cyl_7= " << FM_2(N_negative_cyl_7, N_zero_cyl_7, N_positive_cyl_7) / N_0 << " +/- " << FM_2_error(N_negative_cyl_7, N_zero_cyl_7, N_positive_cyl_7, еrrоr_symm_type) / N_0 << endl;


	cout << endl;

	cout << "FM_2_mag_1= " << FM_2(N_negative_mag_1, N_zero_mag_1, N_positive_mag_1) << " +/- " << FM_2_error(N_negative_mag_1, N_zero_mag_1, N_positive_mag_1, еrrоr_symm_type) << endl;
	cout << "FM_2_mag_2= " << FM_2(N_negative_mag_2, N_zero_mag_2, N_positive_mag_2) << " +/- " << FM_2_error(N_negative_mag_2, N_zero_mag_2, N_positive_mag_2, еrrоr_symm_type) << endl;
	cout << "FM_2_mag_3= " << FM_2(N_negative_mag_3, N_zero_mag_3, N_positive_mag_3) << " +/- " << FM_2_error(N_negative_mag_3, N_zero_mag_3, N_positive_mag_3, еrrоr_symm_type) << endl;
	cout << "FM_2_mag_4= " << FM_2(N_negative_mag_4, N_zero_mag_4, N_positive_mag_4) << " +/- " << FM_2_error(N_negative_mag_4, N_zero_mag_4, N_positive_mag_4, еrrоr_symm_type) << endl;
	cout << "FM_2_mag_5= " << FM_2(N_negative_mag_5, N_zero_mag_5, N_positive_mag_5) << " +/- " << FM_2_error(N_negative_mag_5, N_zero_mag_5, N_positive_mag_5, еrrоr_symm_type) << endl;
	cout << "FM_2_mag_6= " << FM_2(N_negative_mag_6, N_zero_mag_6, N_positive_mag_6) << " +/- " << FM_2_error(N_negative_mag_6, N_zero_mag_6, N_positive_mag_6, еrrоr_symm_type) << endl;
	cout << "FM_2_mag_7= " << FM_2(N_negative_mag_7, N_zero_mag_7, N_positive_mag_7) << " +/- " << FM_2_error(N_negative_mag_7, N_zero_mag_7, N_positive_mag_7, еrrоr_symm_type) << endl;


	cout << endl;

	cout << "FM_2_mag_1= " << FM_2(N_negative_mag_1, N_zero_mag_1, N_positive_mag_1) / N_0 << " +/- " << FM_2_error(N_negative_mag_1, N_zero_mag_1, N_positive_mag_1, еrrоr_symm_type) / N_0 << endl;
	cout << "FM_2_mag_2= " << FM_2(N_negative_mag_2, N_zero_mag_2, N_positive_mag_2) / N_0 << " +/- " << FM_2_error(N_negative_mag_2, N_zero_mag_2, N_positive_mag_2, еrrоr_symm_type) / N_0 << endl;
	cout << "FM_2_mag_3= " << FM_2(N_negative_mag_3, N_zero_mag_3, N_positive_mag_3) / N_0 << " +/- " << FM_2_error(N_negative_mag_3, N_zero_mag_3, N_positive_mag_3, еrrоr_symm_type) / N_0 << endl;
	cout << "FM_2_mag_4= " << FM_2(N_negative_mag_4, N_zero_mag_4, N_positive_mag_4) / N_0 << " +/- " << FM_2_error(N_negative_mag_4, N_zero_mag_4, N_positive_mag_4, еrrоr_symm_type) / N_0 << endl;
	cout << "FM_2_mag_5= " << FM_2(N_negative_mag_5, N_zero_mag_5, N_positive_mag_5) / N_0 << " +/- " << FM_2_error(N_negative_mag_5, N_zero_mag_5, N_positive_mag_5, еrrоr_symm_type) / N_0 << endl;
	cout << "FM_2_mag_6= " << FM_2(N_negative_mag_6, N_zero_mag_6, N_positive_mag_6) / N_0 << " +/- " << FM_2_error(N_negative_mag_6, N_zero_mag_6, N_positive_mag_6, еrrоr_symm_type) / N_0 << endl;
	cout << "FM_2_mag_7= " << FM_2(N_negative_mag_7, N_zero_mag_7, N_positive_mag_7) / N_0 << " +/- " << FM_2_error(N_negative_mag_7, N_zero_mag_7, N_positive_mag_7, еrrоr_symm_type) / N_0 << endl;


	cout << endl;

	cout << "FM_2_tube= " << FM_2(N_negative_tube, N_zero_tube, N_positive_tube) << " +/- " << FM_2_error(N_negative_tube, N_zero_tube, N_positive_tube, еrrоr_symm_type) << endl;

	cout << endl;

	cout << "FM_2_tube= " << FM_2(N_negative_tube, N_zero_tube, N_positive_tube) / N_0 << " +/- " << FM_2_error(N_negative_tube, N_zero_tube, N_positive_tube, еrrоr_symm_type) / N_0 << endl;

	cout << endl;





	cout << i_v_r << endl;
	cout << j_v_r << endl;


	_CrtDumpMemoryLeaks();

	system("pause");
	return 0;
}




// Разработка программы поддержана грантом РНФ № 16-42-01009 "К молекулярному источнику поляризованного дейтериевого топлива для исследований ядерного синтеза и других применений"


// Это маленький гусенок

//#####################################@#@@@@@@@@@@@@@@@@@@@@@@@@@####@@#@@##@@@@@######################################################################
//#################################@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@###############@#######################################################################
//###############################@@@@@@@#@@@@@@@@@@@@@@@@@@@@@@@@###############@#######################################################################
//###############################@##@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@######################################################################################
//###########################@@@@##@#@@@@@@@@@@@@@@@@@@@@@@@@@@@@=+*:--::**+=%@@########################################################################
//##########################@@@@@@@@#@@@@@@@@@@@@@@@@@@@@@@%+:--------...............-+#################################################################
//###########################@##@@####@@@@@@@@@@@@@@@@@@@*:::*****::::::---.............-%##############################################################
//#####################################@@@@@@@@@@@@@@@@*::*++++++=%=++*:---..----..........+############################################################
//########################################@@@@@@@@@@%*:**++++++==++++++=++-..::::---...--..--:@#########################################################
//########################################@@@@@@@@@***+++++*++%+=+=%@@%@@%:....*+:---:==+==+==+=########################################################
//#########################################@@@###@++++++++++*%==+**+%@@%@@+-...-++**::===+++=++=%#######################################################
//###############################################++++++++++=@==++****=%=**--...-:=++**+====++++==%######################################################
//##############################################++++++++**++%+==++**::::::-----:*+*+*%%%%====+=====#####################################################
//#############################################=+++++++****+*=*+=**::::::::::**:+:::*=@@@@%%=========@##################################################
//############################################%+++++++***::*:=+*-::::::::-:*+*:++*:*+%@@@%%===%%=======%################################################
//###########################################@+++++=++**:::::=:++:::::::::**:*+**+**+@@@@@@%%%===%%%%%====##############################################
//###########################################+++++===+**:::::=****+===+***==+*******+@@@@@@@@@%%%=%@@#%==+++=@##########################################
//##########################################=+++++==+++++****=**********:::::***::::%@@@%%%@@@@@@@@%====+===++++%#######################################
//#########################################@+++++=+++++++++**=**:::::::::::::::*:::=%@@@%%%%@@@@@@@@@%%%==+++*******%###################################
//#########################################%+++++==+++++++++*=***:::::::****:*+++**%@%%%%%%%@@@@@@@@%%%%%==+++****::::%#################################
//#########################################=+**++===+++++++*+=+*+**++++++++++++++==+@@@@@%%%%%%%%%%@@#@@%%%==%=+*::::::=################################
//#########################################+***++===++++++++*=**++==++===+===+++==+++%#@@@@@@@@@@@@@@@@@####@%==++:::::+################################
//########################################%+*+++=====++++++++=++++====++++++========%====%@@##@#########@@@@@####@%=+**@################################
//########################################++++++========+++++=++++++++++++==+*+===+**=##################################################################
//#######################################%++++=+==++======+++%++++++++++++******+%######################################################################
//#######################################=++====+++++++++==++=++++++++++**+**+@#########################################################################
//######################################@+++====+++++++******++++++**+++*:::############################################################################
//######################################%+++====+++++***:**::*:*::**::::::-@############################################################################
//######################################=+++====++++++*::::::*:::---------:#############################################################################
//######################################+++====++**+****:::::*:---------..*#############################################################################
//######################################++====+++++*****:::::*--.---.--...=#############################################################################
//######################################++====++*+++***:::::-*:::-----...-@#############################################################################
//######################################+++===++++++**:::::*:*------.....*##############################################################################
//######################################++++==+++++++*::***::*------....-@##############################################################################
//######################################+++++++++++++**:**::-*-----.....+###############################################################################
//######################################+++==+++++++++****:--*-........-@###############################################################################
//######################################+++++=++++**++*:***--::........+################################################################################
//######################################+++++==++++*++*::::-:-*.......-%################################################################################
//######################################+++=+++=+++++++::-----*.......*#################################################################################
//######################################+++===+==++++***:-:-..*......-+#################################################################################
//######################################+*++++=+=++++++*:--...*.......*#################################################################################
//#####################################@++*+=====*++++**:--...*-......+#################################################################################
//######################################+++++=++=+*+++***--...-:......*#################################################################################
//######################################=++++=++++++++::*:-...-:.......%################################################################################
//######################################=+*+++++++**+***:*-....*.......*################################################################################
//######################################@+*++=+++++***:::*:---.*........@###############################################################################
//######################################@+*++++==++***:::**---.*-.......-###############################################################################
//#######################################%++++++++*::**:::*----::........:##############################################################################
//#######################################%+*+++++++*:**:-::::-.-*......-..@#############################################################################
//########################################=++++++**:****::-.....*.........-@############################################################################
//########################################%=++++++*::*:**:---...*..........-############################################################################
//########################################@==++++++:::-**:--.--.+...........=###########################################################################
//#########################################====++++*:::----.--..+.......  ...*##########################################################################
//#########################################====+***:**:---..--..+........ ....:#########################################################################
//###########################################@%=+***:::--.-.--..+........  .....=#######################################################################
//############################################@%=+++::::-.......+................*%#####################################################################
//#############################################@@#@==*:::----...+.................-%%###################################################################
//############################################@#####%++**::---.-+..................-=%@#################################################################
//###########################################@#####@@@=***+******-.................:-%@%################################################################
//##########################################@@@@@##@####=+*:---=::::--............-:.:%@=@##############################################################
//########################################@@#@@##@@##@@#@@*:::=:----......--:-:--.:*.**@@%=@############################################################
//#######################################@@##@@@@@@###@%@@#%:@*::::::--:------..-*:-*++%%@@%=%@#########################################################
//#####################################@@##@#@@@@@##@@@#@@@@#+:::::::=#@@@@@#%%**=@@@#@%+=%@@%%%########################################################
//####################################@###@####@##@@@@###@@%@@@::::::=##@@@%%%%+@@%%=%##@%##%%%%=%@@@###################################################
//##########################################@@###@@@@####@@@@@@#=*::+=##@@%@#@%@##%@@@###%@#@%@@%==%@@@@@@@@@@##########################################
//########################################@@###@@@@@@###@@@#@@@%@@+++=##@@@@@=@#@#@##@#@@+@@@@@@@%=%==%@@@@@@@@@@@@#@##############@####################
//#########################@@@@##########@@#@@@@%@#####@@@##@@@@%%@%+=@#@@@@##%+#####@@#@%@######@%%%%===%%%@@@@@@@@###############@####################
//###################@@@@@@@@########@@#####@@%@@@@@##@@@##@@@@@@%%%@=%##@@@@@#@@%::-----:+=%%%%##@%%%%%%@%%=%=@@@@@######@@@###########################
//##########@#@#@@#@@@@@@@@@#########@@#@@##%@@@@@@@@@@#@##@#@#@@@@%%@@#@#@#@%+*--+:.......-..-:+@#@@%%%@%%%%=%==@@@@@#@@#@@@@######@@##################
//##########@@@@@@@@@@@@@@@######@@%@###@@@%##@@@@@%@@@@##@@@@#@@@@@%%%#@@=++*---.-:*.-.....-....*%#@@%%%%%=====%=%@@@@@@@@@@@@#####@@@#################
//#########@@@@@@@@@@@@@@########@@@@@%@@##@@@##@=@@@@@@@@@@@@@##@@@@@%%@#=*------..:*--.....-....:%@@@%%%%===%%%%%%@@@@@@@@@@@@@@##@@@#################
//##########@@@@@@@@@@@#######@%%@@@@@@@%@@#@#@@#######@@@@@@@@@@##@@@@%%=@%:------..-*---....-....:@@@@%%%%=%%%%%%@@@@@@@@@@@@@@@@@#@@#################
//######@##@@@@@@@@@@#####@##@@@@@@%@@#@@@%@@@@@%@#@@@@@@%@@@@@@@@@@@@@@%%%%%*---------*---...---..-*#@@@%%%%%%%@%@@@@@@@@@@@@@@@@@@@@@#@###############
//#####@@##@@@@@@@@######@@@%=%@@@@@@%%@@@@@%@@@@@%@@@@@@@@@@@@@@@@@@@@%@%%%=%+---------*---....-..--=#@@%%%%%%%%%@@@@@@@@@@@@@@@@@@@@@@@###############
//###@@@@@@@@@@@@##########@@@@%=@@@@@@%%@@@@@%@@#@@%%@@@@@@@@@@@@%@@@@@@@@%%%=%:--------*---....-..-*@@@@%%@%%%%@@@@@@@@@@@@@@@@@@@@@@@@#@@@###########
//