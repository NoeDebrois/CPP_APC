#ifndef SKYWAREHOUSE_HH
#define SKYWAREHOUSE_HH

class skiWarehouse {
private:
  unsigned int skis;
  unsigned int snowboards;

public:
  skiWarehouse(unsigned int sk, unsigned int sn) : skis(sk), snowboards(sn) {}
  
  unsigned int getSkis() const { return skis; }
  unsigned int getSnowboards() const { return snowboards; }

  void bookSkis(unsigned int num) { skis -= num; }
  void bookSnowboards(unsigned int num) { snowboards -= num; }

  void resupply(unsigned int num = 0);
};

#endif // SKYWAREHOUSE_HH