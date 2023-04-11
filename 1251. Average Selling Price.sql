SELECT Prices.product_id
	,round(sum(UnitsSold.units * Prices.price) / sum(UnitsSold.units), 2) AS average_price
FROM UnitsSold
INNER JOIN Prices ON Prices.product_id = UnitsSold.product_id
WHERE purchase_date BETWEEN start_date
		AND end_date
GROUP BY product_id
