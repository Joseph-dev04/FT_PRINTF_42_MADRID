*This project was created by **jopajuel** as part of the 42 Madrid curriculum.*

## 💡 Description
The **ft_printf** project is a challenge to recode the famous standard C library function `printf`. This project is essential for understanding **variadic functions** (functions that accept a variable number of arguments) and practicing precise string parsing and data formatting.

The goal is to create a library (`libftprintf.a`) that mimics the behavior of the original `printf`, handling various conversions and advanced formatting flags.

---

## 🛠 Instructions

This library, `libftprintf.a`, handles the following conversion specifiers and modifiers:

### Mandatory Conversions
| Specifier | Description |
| :---: | :--- |
| **%d** / **%i** | Print signed integers (base 10). |
| **%s** | Print a string of characters. |
| **%c** | Print a single character. |
| **%u** | Print unsigned decimal numbers. |
| **%p** | Print a pointer address in hexadecimal format. |
| **%x** | Print numbers in hexadecimal (lowercase). |
| **%X** | Print numbers in hexadecimal (uppercase). |
| **%%** | Print a literal percent sign. |

### Bonus Modifiers
The following flags and modifiers have been implemented to control the output format:
* **`0`** : Left-pads the number with zeroes instead of spaces.
* **`.`** : Specifies precision (number of digits or string length).
* **`#`** : Alternate form (adds `0x` or `0X` to hex values).
* **`-`** : Left-justifies the output within the field width.
* **`+`** : Forces the sign (+ or -) to be displayed.
* *(Space)* : Leaves a blank space before positive numbers.

---

## 📚 Resource: The Manual
The definitive guide for this project is the system's programmer's manual. You can access it via the terminal:

```bash
man 3 printf