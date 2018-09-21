CFLAGS+=-fexceptions -DOPENSSL=1 -O2
SRC=sendmsg.cpp openssldl.cpp cJSON.c main.cpp nonblocking.cpp opensslbio.cpp ngrok.cpp

#ddns.cpp
#global.cpp
#https.cpp
#ngrok-c.cbp
#polarsslbio.cpp
#win-ngrok-c.cbp

all:
	$(CXX) -s $(SRC) $(CFLAGS) $(CXXFLAGS) -o ngrokc $(LDFLAGS) -lssl -lcrypto -ldl

clean:
	rm -f $(LIBS) ngrokc
