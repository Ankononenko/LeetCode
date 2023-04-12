SELECT id
	,sum(CASE 
			WHEN month = 'jan'
				THEN revenue
			ELSE NULL
			END) AS Jan_Revenue
	,sum(CASE 
			WHEN month = 'feb'
				THEN revenue
			ELSE NULL
			END) AS Feb_Revenue
	,sum(CASE 
			WHEN month = 'mar'
				THEN revenue
			ELSE NULL
			END) AS Mar_Revenue
	,sum(CASE 
			WHEN month = 'apr'
				THEN revenue
			ELSE NULL
			END) AS Apr_Revenue
	,sum(CASE 
			WHEN month = 'may'
				THEN revenue
			ELSE NULL
			END) AS May_Revenue
	,sum(CASE 
			WHEN month = 'jun'
				THEN revenue
			ELSE NULL
			END) AS Jun_Revenue
	,sum(CASE 
			WHEN month = 'jul'
				THEN revenue
			ELSE NULL
			END) AS Jul_Revenue
	,sum(CASE 
			WHEN month = 'aug'
				THEN revenue
			ELSE NULL
			END) AS Aug_Revenue
	,sum(CASE 
			WHEN month = 'sep'
				THEN revenue
			ELSE NULL
			END) AS Sep_Revenue
	,sum(CASE 
			WHEN month = 'oct'
				THEN revenue
			ELSE NULL
			END) AS Oct_Revenue
	,sum(CASE 
			WHEN month = 'nov'
				THEN revenue
			ELSE NULL
			END) AS Nov_Revenue
	,sum(CASE 
			WHEN month = 'dec'
				THEN revenue
			ELSE NULL
			END) AS Dec_Revenue
FROM department
GROUP BY id
