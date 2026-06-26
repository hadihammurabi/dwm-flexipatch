unsigned int
nexttag(bool skip_vacant)
{
	unsigned int seltag = selmon->tagset[selmon->seltags];
	unsigned int MASK = 1 << (NUMTAGS - 1);
  if (!skip_vacant) {
    return seltag == 1 ? MASK : seltag << 1;
  }

	unsigned int usedtags = 0;
	Client *c = selmon->clients;

	if (!c)
		return seltag;

	/* skip vacant tags */
	do {
		usedtags |= c->tags;
		c = c->next;
	} while (c);

	do {
		seltag = seltag == MASK ? 1 : seltag << 1;
	} while (!(seltag & usedtags));

	return seltag;
}

unsigned int
prevtag(bool skip_vacant)
{
	unsigned int seltag = selmon->tagset[selmon->seltags];
	unsigned int MASK = 1 << (NUMTAGS - 1);

  if (!skip_vacant) {
    return seltag == 1 ? MASK : seltag >> 1;
  }

	unsigned int usedtags = 0;
	Client *c = selmon->clients;
	if (!c)
		return seltag;

	/* skip vacant tags */
	do {
		usedtags |= c->tags;
		c = c->next;
	} while (c);

	do {
		seltag = seltag == 1 ? MASK : seltag >> 1;
	} while (!(seltag & usedtags));

	return seltag;
}

void
tagtonext(const Arg *arg)
{
	unsigned int tmp;

	if (selmon->sel == NULL)
		return;

	if ((tmp = nexttag(false)) == selmon->tagset[selmon->seltags])
		return;

	tag(&(const Arg){.ui = tmp });
	view(&(const Arg){.ui = tmp });
}

void
tagtoprev(const Arg *arg)
{
	unsigned int tmp;

	if (selmon->sel == NULL)
		return;

	if ((tmp = prevtag(false)) == selmon->tagset[selmon->seltags])
		return;

	tag(&(const Arg){.ui = tmp });
	view(&(const Arg){.ui = tmp });
}

void
viewnext(const Arg *arg)
{
	view(&(const Arg){.ui = nexttag(true)});
}

void
viewprev(const Arg *arg)
{
	view(&(const Arg){.ui = prevtag(true)});
}


