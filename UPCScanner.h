template <class T>
class Scanner {

public:
	virtual void scan(T& product) = 0;
	virtual ~Scanner() {}
};

