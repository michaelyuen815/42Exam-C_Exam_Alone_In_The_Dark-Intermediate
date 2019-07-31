#include <stdlib.h>
#include <string.h>

#define BL_ODD(ch) ((ch - 48) % 2)
#define BL_EVEN(Ch) (!(ch - 48) % 2))

typedef struct s_sub	t_sub;

struct s_sub
{
	char	*start_;
	size_t	len_;
};

char	*longest_subarray(char *arr)
{
	char	*ret;
	t_sub	t_ret;
	t_sub	t_cur;
	int		i;
	int		j;
	int		balance;

	t_ret.len_ = 0;
	if (arr)
	{
		i = 0;
		while (arr[i])
		{
			j = 0;
			t_cur.start_ = arr + i;
			t_cur.len_ = 0;
			balance = 0;
			while (arr[i + j])
			{
				balance += BL_ODD(arr[i + j]) ? 1 : -1;
				if (!balance)
					t_cur.len_ = (size_t)1 + j;
				j++;
			}
			if (t_cur.len_ > t_ret.len_)
			{
				t_ret.len_ = t_cur.len_;
				t_ret.start_ = t_cur.start_;
			}
			i++;
		}
	}
	ret = (char*)malloc(sizeof(char) * (1 + t_ret.len_));
	ret[t_ret.len_] = 0;
	i = -1;
	while ((size_t)++i < t_ret.len_)
		ret[i] = t_ret.start_[i];
	return (ret);
}
