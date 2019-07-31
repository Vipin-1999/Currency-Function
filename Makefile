AUTO = npm run -- autogypi
GYPFLAGS = --init-gyp -p nbind -s
NG = npm run -- node-gyp
cpp = currency.cpp
RUNINIT = $(AUTO) $(GYPFLAGS) $(cpp)
NFLAGS = configure build
all: build mv clean

build : config
	$(NG) $(NFLAGS) 

config :
	$(RUNINIT)


mv :
	cp build/Release/nbind.node ./Currency.node


clean : 
	rm -rf auto-top.gypi auto.gypi binding.gyp autogypi.json build
