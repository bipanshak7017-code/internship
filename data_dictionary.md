# Data Dictionary - Mutual Fund Analytics

## 1. dim_fund (Dimension Table)
| Column Name | Data Type | Definition | Source Reference |
| :--- | :--- | :--- | :--- |
| amfi_code | INTEGER (PK) | Unique identification code for each mutual fund scheme | AMFI India |
| fund_name | TEXT | Official name of the mutual fund scheme | Internal Master |
| category | TEXT | Asset class category (Equity, Debt, Hybrid, ELSS) | Internal Master |

## 2. fact_transactions (Fact Table)
| Column Name | Data Type | Definition | Source Reference |
| :--- | :--- | :--- | :--- |
| transaction_id | INTEGER (PK) | Unique identifier for each investor transaction | investor_transactions.csv |
| amfi_code | INTEGER (FK) | References dim_fund(amfi_code) | investor_transactions.csv |
| transaction_type | TEXT | Type of investment (SIP, Lumpsum, Redemption) | investor_transactions.csv |
| amount | REAL | Total monetary value of the transaction | investor_transactions.csv |
| transaction_date | TEXT | Date when the transaction occurred (YYYY-MM-DD) | investor_transactions.csv |
| kyc_status | TEXT | Investor KYC verification status (YES, NO, PENDING) | investor_transactions.csv |

## 3. fact_performance (Fact Table)
| Column Name | Data Type | Definition | Source Reference |
| :--- | :--- | :--- | :--- |
| amfi_code | INTEGER (PK/FK) | References dim_fund(amfi_code) | scheme_performance.csv |
| return_1y | REAL | 1-Year annualized percentage return of the scheme | scheme_performance.csv |
| return_3y | REAL | 3-Year annualized percentage return of the scheme | scheme_performance.csv |
| expense_ratio | REAL | Annual fee charged by the fund to manage assets (%) | scheme_performance.csv |
| anomaly_flag | TEXT | Flags anomalous expense ratios (<0.1% or >2.5%) | Derived Column |

## 4. fact_aum (Fact Table)
| Column Name | Data Type | Definition | Source Reference |
| :--- | :--- | :--- | :--- |
| amfi_code | INTEGER (PK/FK) | References dim_fund(amfi_code) | Internal System Data |
| total_aum | REAL | Total Assets Under Management for the scheme | Internal System Data |
| state | TEXT | State from where major investments are sourced | Internal System Data |
