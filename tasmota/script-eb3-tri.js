>D

time=""
date=""
cnt=0
wtd=0
clk=""
old=""
hh=0
mm=0
ss=0

>B

tper=10
smlj=0

=>SerialLog 0
=>SensorRetain 0
=>Sensor53 r

>S

time=st(tstamp T 2)
date=st(tstamp T 1)
hh=sml[1]
mm=sml[2]
ss=sml[3]

if cnt==30
then
smlj=1
endif

if cnt<99
then
cnt+=1
endif

; modbus watchdog block begin

clk=s(2.0hh)+s(2.0mm)+s(2.0ss)

if cnt==99
then
wtd+=1
endif

if wtd==1
then
old=clk
endif

if wtd==90
then
wtd=0
if old==clk
then
print modbus error
; 
=>Restart -3
; 
endif
endif

; modbus watchdog block end

>W

@<b>NTP </b> %date% %time%
@<b>Vars </b> cnt=%0cnt% tper=%0tper% smlj=%0smlj%
@<b>Vars </b> wtd=%0wtd% clk=%0clk% old=%0old%
@<hr>

; Below registers only work in EB3 !

>M 1

; esp32 19/18
; esp8266 3/1
: tfreire 14/5
; change to your gpios and mode
; power off is required
;  v  v             v
+1,3,mN1,1,9600,EB3,1,15,r010400010001,r0104006C0007,r010400730007,r0104007A0006,r010400260003,r010400160006,r0104000B0004

; 01

1,01040Cxxxxxxxxxxuu@i0:1,Clock ,h,CH,0
1,01040Cxxxxxxxxxxxxuu@i0:1,Clock ,m,CM,0
1,01040Cxxxxxxxxxxxxxxuu@i0:1,Clock ,s,CS,0

1,=h<hr>

; 6C

1,01040EUUuu@i1:10,Voltage L1 ,V,VL1,1
1,01040ExxxxxxxxUUuu@i1:10,Voltage L2 ,V,VL2,1
1,01040ExxxxxxxxxxxxxxxxUUuu@i1:10,Voltage L3 ,V,VL3,1

1,=h<hr>

1,01040ExxxxxxxxxxxxxxxxxxxxxxxxUUuu@i1:10,Current ,A,CT,1

1,01040ExxxxUUuu@i1:10,Current L1 ,A,CL1,1
1,01040ExxxxxxxxxxxxUUuu@i1:10,Current L2 ,A,CL2,1
1,01040ExxxxxxxxxxxxxxxxxxxxUUuu@i1:10,Current L3 ,A,CL3,1

1,=h<hr>

; 73

1,01041cx8x8x8UUuuUUuu@i2:1,Active Power ,W,AP,0

1,01041cUUuuUUuu@i2:1,Active Power L1 ,W,APL1,0
1,01041cx8UUuuUUuu@i2:1,Active Power L2 ,W,APL2,0
1,01041cx8x8UUuuUUuu@i2:1,Active Power L3 ,W,APL3,0

1,=h<hr>

; 7A

1,01040eUUuuUUuu@i3:1,Active Power Export,W,APE,0

1,01040exxxxxxxxUUuu@i3:1000,Power Factor ,pu,PF,3
1,01040exxxxxxxxxxxxUUuu@i3:1000,Power Factor L1 ,pu,PFL1,3
1,01040exxxxxxxxxxxxxxxxUUuu@i3:1000,Power Factor L2 ,pu,PFL2,3
1,01040exxxxxxxxxxxxxxxxxxxxUUuu@i3:1000,Power Factor L3 ,pu,PFL3,3
1,01040exxxxxxxxxxxxxxxxxxxxxxxxUUuu@i3:10,Frequency ,Hz,FR,1

1,=h<hr>

; 26

1,01040CUUuuUUuu@i4:1000,Total Energy T1 Vazio ,kWh,TET1,1
1,01040CxxxxxxxxUUuuUUuu@i4:1000,Total Energy T2 Ponta ,kWh,TET2,1
1,01040CxxxxxxxxxxxxxxxxUUuuUUuu@i4:1000,Total Energy T3 Cheias ,kWh,TET3,1

1,=h<hr>

; 16

1,010418UUuuUUuu@i5:1000,Total Energy Import ,kWh,TEI,1
1,010418xxxxxxxxUUuuUUuu@i5:1000,Total Energy Export ,kWh,TEE,3

1,=h<hr>

; 0B

1,01040euu@i6:1,Tariff ,,Tariff,0

#

; eof

