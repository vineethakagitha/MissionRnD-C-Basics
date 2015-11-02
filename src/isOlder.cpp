/*
OVERVIEW: 	Given date of births of two persons as inputs, return 1 if person one is elder,
2 if person two is elder, 0 if both are of same age.
Example: isOlder("24-07-2000", "25-07-2000") should return 1 as person one
is elder than person two.

INPUTS: 	DOBs of two persons as parameters in the format "DD-MM-YYYY".

OUTPUT: 	1 if person one is elder, 2 if person two is elder, 0 if both are of same age.

ERROR CASES: Return -1 if any DOB is invalid.

NOTES: 		Don't use any built-in C functions for comparisions. You are free to write any helper functions.
*/

int isOlder(char *dob1, char *dob2) {
	int n1,n2,d1 = 0, d2 = 0, m1 = 0, m2 = 0, y1 = 0, y2 = 0;
	for (n1 = 0; dob1[n1] != '-'; n1++)
		d1 = d1 * 10 + (dob1[n1] - '0');
	for (n2 = n1+1; dob1[n2] != '-'; n2++)
		m1 = m1 * 10 + (dob1[n2] - '0');
	for (n1 = n2+1; dob1[n1]; n1++)
		y1 = y1 * 10 + (dob1[n1] - '0');
	for (n1 = 0; dob2[n1] != '-'; n1++)
		d2 = d2 * 10 + (dob2[n1] - '0');
	for (n2 = n1+1; dob2[n2] != '-'; n2++)
		m2 = m2 * 10 + (dob2[n2] - '0');
	for (n1 = n2+1; dob2[n1]; n1++)
		y2 = y2 * 10 + (dob2[n1] - '0');
	//test cases
	if (y1 > 0 && y2 > 0)
	{
		if (m1 > 12 || m2 > 12 || m1<=0 || m2<=0 || d1<=0 || d2<=0)
			return -1;
		if (m1==1||m1==3||m1==5||m1==7||m1==8||m1==10||m1==12)
		{
			if (d1 > 31)
				return -1;
		}
		else{
			if (y1 % 4 == 0 && y1 % 400 == 0)
			{
				if (m1 == 2 && d1 > 29)
					return -1;
			}
			else{
				if (m1 != 2 && d1 > 30)
					return -1;
				else if (m1 == 2 && d1 > 28)
					return -1;
			}
		}
		if (m2 == 1 || m2 == 3 || m2 == 5 || m2 == 7 || m2 == 8 || m2 == 10 || m2 == 12)
		{
			if (d1 > 31) 
				return -1;
		}
		else{
			if (y2 % 4 == 0 && y2 % 400 == 0)
			{
				if (m2 == 2 && d2 > 29)
					return -1;
			}
			else{
				if (m2 != 2 && d2 > 30)
					return -1;
				else if (m2 == 2 && d2 > 28)
					return -1;
			}
		}
		if (y1 > y2) return 2;
		else if (y1 < y2) return 1;
		else{
			if (m1 > m2) return 2;
			else if (m1 < m2) return 1;
			else{
				if (d1 > d2) return 2;
				else if (d1 < d2) return 1;
				else
					return 0;
			}
		}
	}
	else return -1;
}
