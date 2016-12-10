class Data {
  int zi, luna, an;

public:
  Data(int dd, int mm, int yyyy) : zi(dd), luna(mm), an(yyyy),
	  zileInLuna{0,31,28,31,30,31,30,31,31,30,31,30,31} {}

  int operator - (const Data& d) {
	  return inZile() - d.inZile();
	}

  Data& operator += (int zile) {
	  zi += zile;

	  while(zi > zileInLuna[luna]) {
	    zi -= zileInLuna[luna];
	    ++luna;

	    if(luna > 12) {
	      luna = 1;
	      ++an;
	    }
	  }
		return *this;
	}

	friend ostream& operator << (ostream& os, const Data& d) {
		return os<<d.zi<<"/"<<d.luna<<"/"<<d.an;
	}

private:
  int zileInLuna[13];

	int inZile() const {
		int zile = an * 365 + zi;
	  for(int i=1;i<luna;++i)
	    zile += zileInLuna[i];
	  return zile;
	}
};
