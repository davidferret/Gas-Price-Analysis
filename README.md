# Gas Price Analysis Program

This program reads gas price data from a file, sorts and analyzes it, and allows users to interactively evaluate historical trends.

- **Data Input**: Reads monthly gas prices from a file.
- **Sorting Options**: Sorts data by regular gas price or by month.
- **Average Price Calculation**: Computes and displays average regular and premium gas prices.
- **Historical Comparison**: Analyzes gas price changes over time.
- **Cheapest Months Identification**: Finds the months with the lowest gas prices.
- **User-Defined Analysis**: Allows users to search for months with gas prices below a threshold.

## Example Usage
```
Choose sorting method:
1 - Sort by Regular Gas Price
2 - Sort by Month
3 - No Sorting
Enter choice: 1

Choose sorting order:
1 - Ascending
2 - Descending
Enter choice: 1

Month     Year      Regular   Premium    
March     2023      3.10      3.80      
January   2023      3.25      3.90      
February  2023      3.50      4.10      

The average regular gasoline price: 3.28
The average premium gasoline price: 3.93

Cheapest months with regular gas price of 3.10:
March 2023

Historical Gas Price Comparison:
2022 vs 2023 - Regular: 3.00 -> 3.10, Premium: 3.75 -> 3.80

Enter a price threshold to find months with regular gas price below this value: 3.30
Months with regular gas price below 3.30:
Regular: 3.10 | Premium: 3.80

```
