# LED Sequence V3.0 MISRA compliant
#### MISRA

# Proiect_map
| File                  | Link                                                                           
| --------------------- | ------------------------------------------------------------------------------ |
| MCU file                   | [.hex](https://github.com/ahmedatef1496/MISRA/blob/main/LED%20Sequence%20V3.0%20MISRA%20compliant/LED%20Sequence%20V3.0%20MISRA%20compliant/Debug/LED%20Sequence%20V3.0%20MISRA%20compliant.hex)  |
| Simulation                    | [Simulation](https://github.com/ahmedatef1496/MISRA/tree/main/LED%20Sequence%20V3.0%20MISRA%20compliant/LED%20Sequence%20V3.0%20MISRA%20compliant/sim) |
| HW_Test Video                 | [Video](https://youtu.be/LorM2qhaJbI)|
| Re-build Video                 | [Video](https://github.com/ahmedatef1496/MISRA/blob/main/LED%20Sequence%20V3.0%20MISRA%20compliant/LED%20Sequence%20V3.0%20MISRA%20compliant/video.mp4)|



# MISRA Rules Applied in This PROJECT + TIMER Driver (using TIMER0) + DIO Driver

 #Drivers
-Rule 14.7, requires that functions with variable-length argument lists should not be called.<br>
-Rule 18.1, requires that all declarations should be at the top of the function or file scope.<br>
-Rule 10.1, requires that all operands of logical and relational operators should have a Boolean type.<br>
-Rule 17.4, prohibits the use of the comma operator.<br>
-Rule 13.2, which requires that all conditional statements should have a Boolean expression as the controlling expression.<br>
-Rule 12.2, which requires that all switch statements should have a default case.

#Project
Rule 1.1: A compiler warning shall be produced for any instance of code that does not conform to the rules of the Standard.<br>
Rule 2.1: Assembly language shall be encapsulated and isolated.<br>
Rule 5.2: Expressions shall not be used as the controlling expression of an if statement or as the operand of a while or do-while statement.
Rule 10.3: The value of a complex expression of integer type shall only be cast to a type that is narrower and of the same signedness as the underlying type of the expression.<br>
Rule 12.1: Only one break statement shall appear in the body of a switch statement.<br>
Rule 13.5: The operands of the && and || operators shall be of scalar type.<br>
Rule 14.2: All non-static functions shall have external linkage.<br>
Rule 14.3: A function shall not have multiple exit points.<br>
Rule 17.3: Type definitions shall not be used in the return types of functions.<br>



## Simulation Schematic

<p align="center">
  <img width="800" height="400" src="https://github.com/ahmedatef1496/MISRA/blob/main/LED%20Sequence%20V3.0%20MISRA%20compliant/LED%20Sequence%20V3.0%20MISRA%20compliant/sim/sim.PNG">
</p>

