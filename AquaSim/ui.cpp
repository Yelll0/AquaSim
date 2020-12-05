#include <iostream>
#include <string>

using namespace std;

fish_pos = []
food_pos = []
user_input = True

cout << "Enter input values for fish x, y, z, food, age, position, speed, size, eat_thres, metabolism, birth_thres serparated by spaces";

string upper(string text) {
    string upperCase;
    for (int it : text) {
        if (it > 96 && it < 123) {
            upperCase += char(it - 32);
        }
        else {
            upperCase += char(it);
        }
    }
    return upperCase;
}


while (user_input == True) {

    cout << "Enter values, [F]inish inputting values or [D] to to use default values";
    cin >> in_val;

    if upper(in_val) == 'D' {
        cout << "How many fish would you like to generate? [D] to use default value";
        cin >> num_fish;

        num_fish = num_fish

            if upper(num_fish) == 'D' {
                num_fish = 10
            }

        for (n = 0, n >= num_fish, n++) {
            df = df.append({}) //add rows with default vals
        }
    }
                   
