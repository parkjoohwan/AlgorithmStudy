#if defined(LIBC_SCCS) && !defined(lint)
static char rcsid[] = "$Id: inet_pton.c,v 8.6 1996/06/26 23:17:26 vixie Exp $";
#endif /* LIBC_SCCS and not lint */

#include <string.h>
#include <errno.h>
#include <iostream>

using namespace std;
#define	IN6ADDRSZ	16
#define	INADDRSZ	 4
#define	INT16SZ		 2

#ifndef	AF_INET6
#define	AF_INET6	AF_MAX+1	/* just to let this compile */
#endif

/*
* WARNING: Don't even consider trying to compile this on a system where
* sizeof(int) < 4.  sizeof(int) > 4 is fine; all the world's not a VAX.
*/

static int	inet_pton4(const char *src);
static int	inet_pton6(const char *src);

/* int
* inet_pton(af, src, dst)
*	convert from presentation format (which usually means ASCII printable)
*	to network format (which is usually some kind of binary format).
* return:
*	1 if the address was valid for the specified address family
*	0 if the address wasn't valid (`dst' is untouched in this case)
*	-1 if some other error occurred (`dst' is untouched in this case, too)
* author:
*	Paul Vixie, 1996.
*/
int
inet_pton(
	int af,
	const char *src)
{
	switch (af) {
	case 0:
		return (inet_pton4(src));
	case 1:
		return (inet_pton6(src));
	default:
		errno = EAFNOSUPPORT;
		return (-1);
	}
	/* NOTREACHED */
}

/* int
* inet_pton4(src, dst)
*	like inet_aton() but without all the hexadecimal and shorthand.
* return:
*	1 if `src' is a valid dotted quad, else 0.
* notice:
*	does not touch `dst' unless it's returning 1.
* author:
*	Paul Vixie, 1996.
*/
static int inet_pton4(const char *src)
{
	static const char digits[] = "0123456789";
	int saw_digit, octets, ch;
	char tmp[INADDRSZ], *tp;

	saw_digit = 0;
	octets = 0;
	*(tp = tmp) = 0;
	while ((ch = *src++) != '\0') {
		const char *pch;

		if ((pch = strchr(digits, ch)) != NULL) {
			int new1 = *tp * 10 + (pch - digits);

			if (new1> 255)
				return (0);
			*tp = new1;
			if (!saw_digit) {
				if (++octets > 4)
					return (0);
				saw_digit = 1;
			}
		}
		else if (ch == '.' && saw_digit) {
			if (octets == 4)
				return (0);
			*++tp = 0;
			saw_digit = 0;
		}
		else
			return (0);
	}
	if (octets < 4)
		return (0);
	/* bcopy(tmp, dst, INADDRSZ); */
	return (1);
}

/* int
* inet_pton6(src, dst)
*	convert presentation level address to network order binary form.
* return:
*	1 if `src' is a valid [RFC1884 2.2] address, else 0.
* notice:
*	(1) does not touch `dst' unless it's returning 1.
*	(2) :: in a full address is silently ignored.
* credit:
*	inspired by Mark Andrews.
* author:
*	Paul Vixie, 1996.
*/
static int
inet_pton6(const char *src)
{
	static const char xdigits_l[] = "0123456789abcdef",
		xdigits_u[] = "0123456789ABCDEF";
	char tmp[IN6ADDRSZ], *tp, *endp, *colonp;
	const char *xdigits, *curtok;
	int ch, saw_xdigit;
	int val;

	memset((tp = tmp), 0, IN6ADDRSZ);
	endp = tp + IN6ADDRSZ;
	colonp = NULL;
	/* Leading :: requires some special handling. */
	if (*src == ':')
		if (*++src != ':')
			return (0);
	curtok = src;
	saw_xdigit = 0;
	val = 0;
	while ((ch = *src++) != '\0') {
		const char *pch;

		if ((pch = strchr((xdigits = xdigits_l), ch)) == NULL)
			pch = strchr((xdigits = xdigits_u), ch);
		if (pch != NULL) {
			val <<= 4;
			val |= (pch - xdigits);
			if (val > 0xffff)
				return (0);
			saw_xdigit = 1;
			continue;
		}
		if (ch == ':') {
			curtok = src;
			if (!saw_xdigit) {
				if (colonp)
					return (0);
				colonp = tp;
				continue;
			}
			if (tp + INT16SZ > endp)
				return (0);
			*tp++ = (char)(val >> 8) & 0xff;
			*tp++ = (char)val & 0xff;
			saw_xdigit = 0;
			val = 0;
			continue;
		}
		if (ch == '.' && ((tp + INADDRSZ) <= endp) &&
			inet_pton4(curtok) > 0) {
			tp += INADDRSZ;
			saw_xdigit = 0;
			break;	/* '\0' was seen by inet_pton4(). */
		}
		return (0);
	}
	if (saw_xdigit) {
		if (tp + INT16SZ > endp)
			return (0);
		*tp++ = (char)(val >> 8) & 0xff;
		*tp++ = (char)val & 0xff;
	}
	if (colonp != NULL) {
		/*
		* Since some memmove()'s erroneously fail to handle
		* overlapping regions, we'll do the shift by hand.
		*/
		const int n = tp - colonp;
		int i;

		for (i = 1; i <= n; i++) {
			endp[-i] = colonp[n - i];
			colonp[n - i] = 0;
		}
		tp = endp;
	}
	if (tp != endp)
		return (0);
	/* bcopy(tmp, dst, IN6ADDRSZ); */
	return (1);
}

int main() {


	cout << inet_pton(1, "1111::1111") << endl;



	system("pause");
	return 0;
}