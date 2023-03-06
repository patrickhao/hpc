#include <iostream>

int main() {
    enum class Day {Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday};
    // When you reference an enumerator, it must be qualified by the type name
    Day today {Day::Monday};

    // To output the value of today, you must cast it to a numeric type
    // because the standard output stream will not recognize the type Day
    std::cout << static_cast<int>(today) << std::endl;

    // This definition of type Day has enumerator values 1 through 7
    enum class Day2 {Monday = 1, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday};

    enum class Day3 {Monday = 3, Tuesday, Wednesday, Thursday, Friday, Saturday = 1, Sunday};
    std::cout << static_cast<int>(Day3::Tuesday) << std::endl;
    std::cout << static_cast<int>(Day3::Sunday) << std::endl;

    // The enumerators don’t even need to have unique values
    // Monday和Mon的含义是一样的，随便用哪个都行
    // 注意在Day3这种赋值形式下，避免意义不同的两个名称有同样的值，编译器虽然不会报错但是可能会存在使用上的问题
    enum class Day4 {Monday = 1, Mon = 1, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday };

    // You can also define the value of an enumerator in terms of a previous enumerator
    // Values for enumerators must be compile-time constants
    enum class Day5 { Monday, Mon = Monday, Tuesday = Monday + 2, Tues = Tuesday, Wednesday = Tuesday + 2, Wed = Wednesday, Thursday = Wednesday + 2, Thurs = Thursday, Friday = Thursday + 2, Fri = Friday, Saturday = Friday + 2, Sat = Saturday, Sunday = Saturday + 2, Sun = Sunday };

    // The enumerators can be an integer type that you choose
    enum class Punctuation : char {Comma = ',', Exclamation = '!', Question='?'};
    std::cout << static_cast<int>(Punctuation::Comma) << std::endl;


    return 0;
}