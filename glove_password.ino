const int flex_1 = A0;
const int flex_2 = A1;
const int flex_3 = A2;
const int flex_4 = A3;
const int flex_5 = 6;
int val_1;
int val_2;
int val_3;
int val_4;
int val_5;
int pos_1;
int pos_2;
int pos_3;
int pos_4;
int pos_5;
int hand[5];
int x[5];
int i;
int j;
int correct = 1;
int check = 0;
int num = 0;
/*0 MEANS NOT BENT AND 1 MEANS BENT*/
int positions[10][5] = {{0, 1, 1, 1, 1},   /*0*/   
                       {0, 0, 1, 1, 1},   /*1*/
                       {1, 0, 0, 1, 1},   /*2*/
                       {0, 0, 0, 1, 1},   /*3*/
                       {1, 0, 0, 0, 0},   /*4*/
                       {0, 0, 0, 0, 0},   /*5*/
                       {1, 0, 0, 0, 1},   /*6*/
                       {1, 0, 0, 1, 0},   /*7*/
                       {1, 0, 1, 0, 0},   /*8*/
                       {1, 1, 0, 0, 0}};   /*9*/
char words[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
char password[4] = {'5', '1', '5', '1'};
float angle_1;
float angle_2;
float angle_3;
float angle_4;
float angle_5;
void setup() {
  Serial.begin(9600);
  pinMode(flex_1, INPUT);
  pinMode(flex_2, INPUT);
  pinMode(flex_3, INPUT);
  pinMode(flex_4, INPUT);
  pinMode(flex_5, INPUT);
  delay(2000);
}
int pos(int a)
{
  if (a < 255)
  {
    return 1;
  }
  if ((a > 270) && (a < 330))
  {
    return 0;
  }
}
char findnum(int x[5])
{
  for(i = 0; i < 9; i ++)
  {
    for(j = 0; j < 5; j++){
      if(positions[i][j] != x[j])
      {
        correct = 0;
      }
    }
    if(correct == 1){
        return words[i];
        break;
      }
      else
      {
        correct = 1;
      }
  }
}
void loop() { 
  val_1 = analogRead(flex_1);
  val_2 = analogRead(flex_2);
  val_3 = analogRead(flex_3);
  val_4 = analogRead(flex_4);
  val_5 = analogRead(flex_5);
  pos_1 = pos(val_1);
  hand[0] = pos_1;
  pos_2 = pos(val_2);
  hand[1] = pos_2;
  pos_3 = pos(val_3);
  hand[2] = pos_3;
  pos_4 = pos(val_4);
  hand[3] = pos_4;
  pos_5 = pos(val_5);
  hand[4] = pos_5;
  if (num == 0){
    Serial.println("Reading first digit...");
    if (findnum(hand) == password[0])
    {
      check ++;
    }
    Serial.println(findnum(hand));
    num++;
    delay(2000);
  }
  else if (num == 1){
    Serial.println("Reading second digit...");
    if (findnum(hand) == password[1])
    {
      check ++;
    }
    Serial.println(findnum(hand));
    num++;
    delay(2000);
  }
  else if (num == 2){
    Serial.println("Reading third digit...");
    if (findnum(hand) == password[2])
    {
      check ++;
    }
    Serial.println(findnum(hand));
    num++;
    delay(2000);
  }
  else if (num == 3){
    Serial.println("Reading fourth digit...");
    if (findnum(hand) == password[3])
    {
      check ++;
    }
    Serial.println(findnum(hand));
    num++;
    delay(2000);
  }
  else if (num == 4){
    if (check == 4)
    {
      Serial.println("CORRECT PASSWORD!");
    }
    else
    {
       Serial.println("PASSWORD IS INCORRECT!");
    }
    num = 0;
    check = 0;
  }

}
