SELECT PRC.product_id, COALESCE(ROUND(SUM(price * units) / SUM(units), 2), 0) as average_price
FROM Prices PRC
LEFT JOIN UnitsSold SLD
ON PRC.product_id = SLD.product_id
AND SLD.purchase_date >= PRC.start_date
AND SLD.purchase_date <= PRC.end_date
GROUP BY PRC.product_id
