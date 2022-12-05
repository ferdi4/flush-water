class ToiletState
{
  private:
    int _sensorPin1 = 0;
    int _sensorPin2 = 0;
    int _sensorPin3 = 0;
    int _state = 0;

  public:
    ToiletState();
    ~ToiletState();
    void setup(int sensorPin1, int sensorPin2, int sensorPin3);
    void updateState();
    void init();
    int getState();
};

void ToiletState::setup(int sensorPin1, int sensorPin2, int sensorPin3) {
  _sensorPin1 = sensorPin1;
  _sensorPin2 = sensorPin2;
  _sensorPin3 = sensorPin3;
}

ToiletState::~ToiletState() {}
ToiletState::ToiletState() {}

void ToiletState::init() {
  pinMode(_sensorPin1, INPUT_PULLUP);
  pinMode(_sensorPin2, INPUT_PULLUP);
  pinMode(_sensorPin3, INPUT_PULLUP);
}

void ToiletState::updateState() {
  _state = digitalRead(_sensorPin1) + digitalRead(_sensorPin2) + digitalRead(_sensorPin3);
}

int ToiletState::getState() {
  return _state;
}

ToiletState state;


void setup() {
  state.setup(23, 22, 1);
  state.init();

  Serial.begin(115200);
}

void loop() {
  state.updateState();
  Serial.println(state.getState());
  delay(1000);
}
