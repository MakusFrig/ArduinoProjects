#define ZERO 6
#define ONE 2
#define TWO 5
#define THREE 5
#define FOUR 4
#define FIVE 5
#define SIX 6
#define SEVEN 3
#define EIGHT 7
#define NINE 5

const int zero[6] = {3, 5, 6, 7, 8 ,9};

const int one[2] = {6, 7};

const int two[5] = {9, 4, 3, 7, 5};

const int three[5] = {9, 4, 3, 8, 5};

const int four[4] = {8, 5, 4, 6};

const int five[5] = {9, 4, 3, 8, 6};

const int six[6] = {3, 4, 6, 7, 8, 9};

const int seven[3] = {9, 8, 5};

const int eight[7] = {3, 4, 5, 6, 7, 8, 9};

const int nine[5] = {4, 5, 6, 8, 9};

int numbers[] = {0,0,0,0,0};

int c = 0;

int num;

const int potpin = 0;



unsigned long previousTime;
//problem there is shifting
//when using four digit numbers its alright
//maybe we are inadvertanly adding another

void setup() {
  // put your setup code here, to run once:
  for (int i = 3; i <= 9; i++) {
    pinMode(i, OUTPUT);
  }
  for (int i = 10; i < 14; i++) {
    pinMode(i, OUTPUT);
    digitalWrite(i, HIGH);
  }
  pinMode(2, OUTPUT);
  digitalWrite(2, HIGH);
  previousTime = millis();
  Serial.begin(9600);
  /*
  int myarr[4];
  int *p = create_array(myarr, 1023);
  for (int i = 0; i < 4; i ++) {
    Serial.print(p[i]);
    Serial.print("_");
  }
  We know that this works
  */
}


void loop() {
  // put your main code here, to run repeatedly:
  int analog_value = analogRead(potpin);

  int myarr[4];

  int *ptr = create_array(myarr, analog_value);

  unsigned long currentTime = millis();

  previousTime = millis();

  
  while (currentTime - previousTime < 100) {
    
    display_screen(ptr);
    currentTime = millis();
    
  }
  previousTime = millis();
  clear_screen();


}
int * create_array(int *arr, int x) {//This now works
  

  //Try to isolate the different numbers
  if (x < 1000) {
      arr[0] = 0;
  } else {
    int c = 0;
    while (x >= 1000) {
      x -= 1000;
      c++;
    }
    arr[0] = c;
  }
  if (x < 100) {
    arr[1] = 0;
  } else {
    int c = 0;
    while (x >= 100) {
      x -= 100;
      c++;
    }
    arr[1] = c;
  }
  if (x <  10) { 
    arr[2] = 0;
  } else {
    int c = 0;
    while (x >= 10) {
      x -= 10;
      c ++;
    }
    arr[2] = c;
  } 
  arr[3] = x;
  //I dont know return something
  return arr;
  //Must assign a pointer to what is being returned
}

void clear_screen() {
  for(int i = 3; i < 10; i++ ){
    digitalWrite(i, LOW);
  }
  for (int i = 10; i < 14; i++) {
    digitalWrite(i, HIGH);
  }
  digitalWrite(2, HIGH);
  
}

void display_screen(int arr[]) {
  for (int i = 0; i < 5; i++) {
    if (i == 0) {
      digitalWrite(2, LOW);
      
    } else {
      digitalWrite(i+9, LOW);
    }
    switch (arr[i]) {
      case 0:
        for (int u = 0; u < ZERO; u++) {
          digitalWrite(zero[u], HIGH);
        }
        break;
      case 1:
        for (int u = 0; u < ONE; u++) {
          digitalWrite(one[u], HIGH);
        }
        break;
      case 2:
        for (int u = 0; u < TWO; u++) {
          digitalWrite(two[u], HIGH);
        }
        break;
      case 3:
        for (int u = 0; u < THREE; u++) {
          digitalWrite(three[u], HIGH);
        }
        break;
      case 4:
        for (int u = 0; u < FOUR; u++) {
          digitalWrite(four[u], HIGH);
        }
        break;
      case 5:
        for (int u = 0; u < FIVE; u++) {
          digitalWrite(five[u], HIGH);
        }
        break;
      case 6:
        for (int u = 0; u < SIX; u++) {
          digitalWrite(six[u], HIGH);
        }
        break;
      case 7:
        for (int u = 0; u < SEVEN; u++) {
          digitalWrite(seven[u], HIGH);
        }
        break;
      case 8:
        for (int u = 0; u < EIGHT; u++) {
          digitalWrite(eight[u], HIGH);
        }
        break;
      case 9:
        for (int u = 0; u < NINE; u++) {
          digitalWrite(nine[u], HIGH);
        }
        break;
    }
    if (i == 0) {
      digitalWrite(2, HIGH);
    } else {
      digitalWrite(i+9, HIGH);
    }
    for (int j = 3; j < 10; j++) {
      digitalWrite(j, LOW);
    }
  }
  
  
}
