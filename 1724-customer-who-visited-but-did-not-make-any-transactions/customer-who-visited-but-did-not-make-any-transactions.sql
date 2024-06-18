# Write your MySQL query statement below
SELECT customer_id, COUNT(v.visit_id) AS count_no_trans
FROM Visits v LEFT JOIN Transactions t
ON t.visit_id = v.visit_id
WHERE transaction_id is NULL
GROUP BY customer_id