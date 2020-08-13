# metrocard

Calculates which custom NYC MetroCard amounts yield the lowest remainders

## Installation

```bash
make && sudo make install
```

## Usage

```bash
metrocard [-o|--old] [-f|--fare <fare>] [-b|--bonus <bonus>]
          [-m|--minimum <minimum>] [-M|--maximum <maximum>]
          [-t|--threshold <threshold>] [-i|--increment <increment>]
          [-h|--help]
```

Note: Effective March 22, 2015, the base fare will be $2.75 (up $0.25 from the previous rate of $2.50). This program uses the new rate by default. To harken back to simpler, cheaper times and use the $2.50 fare and %5 bonus:

```bash
metrocard --old
```

| Flag           | Description                        | Default |
| -------------- | ---------------------------------- | ------- |
| -o|--old       | Uses the old base fare             | $2.50   |
| -f|--fare      | Base fare                          | $2.75   |
| -b|--bonus     | Purchase bonus, decimal percentage | 0.11    |
| -m|--minimum   | Minimum purchase                   | $5.50   |
| -M|--maximum   | Maximum purchase                   | $20.00  |
| -t|--treshold  | Remainder threshold                | $0.05   |
| -i|--increment | Purchase increment                 | $0.05   |
| -h|--help      | Help                               |         |

Note: All inputs should be floating point numbers with no dollar signs

## Example

New fare (default):

```
# Rides | You Pay | On Card | Remainder
--------+---------+---------+----------
      3 |  $ 7.45 |  $ 8.27 | $ 0.02
      4 |  $ 9.95 |  $11.04 | $ 0.04
      5 |  $12.40 |  $13.76 | $ 0.01
      6 |  $14.90 |  $16.54 | $ 0.04
      7 |  $17.35 |  $19.26 | $ 0.01
      8 |  $19.85 |  $22.03 | $ 0.03
```

Old fare:

```
# Rides | You Pay | On Card | Remainder
--------+---------+---------+----------
      2 |  $ 4.80 |  $ 5.04 | $ 0.04
      3 |  $ 7.15 |  $ 7.51 | $ 0.01
      4 |  $ 9.55 |  $10.03 | $ 0.03
      5 |  $11.95 |  $12.55 | $ 0.05
      6 |  $14.30 |  $15.02 | $ 0.02
      7 |  $16.70 |  $17.54 | $ 0.04
      8 |  $19.05 |  $20.00 | $ 0.00
```

## Acknowledgements

Inspired by [this post](http://iquantny.tumblr.com/post/96700509489/how-memorizing-19-05-can-help-you-outsmart-the) on I Quant NY.
