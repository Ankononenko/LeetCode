SELECT Product.product_name
	,Sales.year
	,Sales.price
FROM Product
INNER JOIN sales ON Sales.product_id = Product.product_id
