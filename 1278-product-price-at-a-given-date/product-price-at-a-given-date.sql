SELECT product_id, 
CASE 
    WHEN MIN(change_date) <= '2019-08-16' THEN new_price 
    ELSE 10 
END AS price
FROM Products P1
WHERE (product_id, change_date) IN (
    SELECT P2.product_id, MAX(P2.change_date)
    FROM Products P2
    WHERE change_date <= '2019-08-16'
    GROUP BY product_id
) 
OR (product_id) IN (
    SELECT product_id
    FROM Products
    GROUP BY product_id
    HAVING MIN(change_date) > '2019-08-16'
)
GROUP BY product_id
ORDER BY product_id