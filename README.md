# Mutual Fund Analytics - ETL Pipeline Project

## Project Overview
This project extracts raw Net Asset Value (NAV) data of various Mutual Fund schemes, cleans and transforms the dataset using Python (Pandas), and loads the structured data into an SQLite database for running advanced SQL analytical queries.

## Deliverables Included
* **`cleaned_nav_history.csv`**: The finalized, structured, and cleaned dataset.
* **`bluestock_mf (1).db`**: The SQLite database file containing the structured data table `fact_nav_history`.

---

## SQL Analytics & Insights

### Query 1: Data Overview Per Scheme
```sql
SELECT 
    scheme_name, 
    COUNT(*) as total_days,
    MIN(date) as start_date,
    MAX(date) as end_date
FROM fact_nav_history
GROUP BY scheme_name;
SELECT 
    scheme_name, 
    MAX(nav) as highest_nav
FROM fact_nav_history
GROUP BY scheme_name
ORDER BY highest_nav DESC;
