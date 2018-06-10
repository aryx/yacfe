void main(int i)
{
			while (1) {
				if (vc->vc_need_wrap || vc->vc_decim)
					FLUSH
				if (vc->vc_need_wrap) {
					cr(vc);
					lf(vc);
				}
			}
}
