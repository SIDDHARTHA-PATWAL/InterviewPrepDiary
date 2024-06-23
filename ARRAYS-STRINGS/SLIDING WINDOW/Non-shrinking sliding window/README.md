## Things to Remember

1) Try making the inner loop for shrinking window into a a IF condition statement.

2)  EXPAND THE WINDOW UNTIL THE BAD ELEMENT ENTERS THE WINDOW AND THEN STOP EXPANDING

3) Unlike the usual sliding window approach, the window never shrinks and remain same if there is a bad element

3) The current subarray may be good or bad, but the current size of subarray represent the longest good subarray enecounterred till the current situation

4) If the bad elements in subarray becomes zero,then it can start expanding again  ,
until bad condtion is encounterred again