all: beacon_flood

beacon_flood: bf.cpp
	g++ bf.cpp -o beacon_flood -ltins

clean:
	rm *.0 beacon_flood
