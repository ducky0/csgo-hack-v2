

#define coloresp gcvars.colorsredtwo,gcvars.colorsgreentwo,gcvars.colorsbluetwo,255

namespace esp
{
	inline void draw(entities* local)
	{
		int imyteam = local->getteamnum();

		static vector vscreen;

		static float ftop;

		for (int ax = 1; ax <= pengine->getmaxclients(); ax++)
		{
			entities* entity = pentlist->getcliententity(ax);

			if (!entity)
				continue;

			if (entity == local)
				continue;

			if (entity->isdormant())
				continue;

			if (!entity->isalive())
				continue;

			if (entity->getteamnum() == imyteam)
				continue;

			vector vorigin = entity->absorigin();

			if (vorigin.iszero())
				continue;

			if (!draw::worldtoscreen(vorigin, vscreen))
				continue;

			vector vheadpos = entity->getbonepos(8);

			if (vheadpos.iszero())
				continue;

			vheadpos.z += 7.0f;

			ftop = vheadpos.z;

			vector vtop = (vector(vorigin.x, vorigin.y, ftop));

			vector vtopscreen;

			if (!draw::worldtoscreen(vtop, vtopscreen))
				continue;

			float h = (vscreen.y - vtopscreen.y);

			float w = h / 4.5f;

			if (gcvars.espbox)
			{
				int r_x = vtopscreen.x - w;

				w *= 2;

				int frame_w = w;

				int frame_ww = frame_w;
				frame_ww /= 3;

				frame_w /= 2.3;

				draw::fillrgba(r_x, vtopscreen.y, frame_ww, 1, coloresp);
				draw::fillrgba(r_x, vtopscreen.y, 1, frame_w, coloresp);

				draw::fillrgba(r_x, vtopscreen.y - 1, frame_ww, 1, 0, 0, 0, 255);
				draw::fillrgba(r_x - 1, vtopscreen.y, 1, frame_w, 0, 0, 0, 255);

				int calc_x = r_x + (w - frame_ww);
				int calc_y = vtopscreen.y + (h - frame_w);

				draw::fillrgba(calc_x, vtopscreen.y, frame_ww, 1, coloresp);
				draw::fillrgba(r_x + w, vtopscreen.y, 1, frame_w, coloresp);

				draw::fillrgba(calc_x, vtopscreen.y - 1, frame_ww + 1, 1, 0, 0, 0, 255);
				draw::fillrgba(r_x + w + 1, vtopscreen.y, 1, frame_w, 0, 0, 0, 255);

				draw::fillrgba(r_x, vtopscreen.y + h, frame_ww, 1, coloresp);
				draw::fillrgba(r_x, calc_y, 1, frame_w, coloresp);

				draw::fillrgba(r_x, vtopscreen.y + h + 1, frame_ww, 1, 0, 0, 0, 255);
				draw::fillrgba(r_x - 1, calc_y, 1, frame_w + 1, 0, 0, 0, 255);

				draw::fillrgba(calc_x + 1, vtopscreen.y + h, frame_ww, 1, coloresp);
				draw::fillrgba(r_x + w, calc_y, 1, frame_w, coloresp);

				draw::fillrgba(calc_x + 1, vtopscreen.y + h + 1, frame_ww, 1, 0, 0, 0, 255);
				draw::fillrgba(r_x + w + 1, calc_y, 1, frame_w + 1, 0, 0, 0, 255);
			}

			if (gcvars.healthbar)
			{
				int curhealth = entity->gethealth();

				if (curhealth > 100)
					curhealth = 100;

				int ihealthwidth = (curhealth * (w*0.5*0.1) * 0.2);
				int ihealthmaxwidth = (100 * (w*0.5*0.1) * 0.2);

				draw::drawheader(vscreen.x - w * 0.5, vscreen.y + 5, ihealthmaxwidth + 2, ihealthwidth, coloresp);
			}
		}
	}

	inline void charms(entities* local)
	{
		int imyteam = local->getteamnum();

		for (int ax = 1; ax <= pengine->getmaxclients(); ax++)
		{
			entities* entity = pentlist->getcliententity(ax);

			if (!entity)
				continue;

			if (entity == local)
				continue;

			if (entity->isdormant())
				continue;

			if (!entity->isalive())
				continue;

			if (entity->getteamnum() == team_none)
				continue;

			if (entity->getteamnum() == team_spec)
				continue;

			int iteamnum = entity->getteamnum();

			if (iteamnum == imyteam && !gcvars.chamteam)
			{
				*(char*)((DWORD)(entity)+xoffsets.dt_baseentity.m_clrrender) = (byte)255;
				*(char*)((DWORD)(entity)+xoffsets.dt_baseentity.m_clrrender + 0x1) = (byte)255;
				*(char*)((DWORD)(entity)+xoffsets.dt_baseentity.m_clrrender + 0x2) = (byte)255;
				*(char*)((DWORD)(entity)+xoffsets.dt_baseentity.m_clrrender + 0x3) = (byte)255;
			}
			else
			{
				*(char*)((DWORD)(entity)+xoffsets.dt_baseentity.m_clrrender) = (byte)gcvars.colorsredfive;
				*(char*)((DWORD)(entity)+xoffsets.dt_baseentity.m_clrrender + 0x1) = (byte)gcvars.colorsgreenfive;
				*(char*)((DWORD)(entity)+xoffsets.dt_baseentity.m_clrrender + 0x2) = (byte)gcvars.colorsbluefive;
				*(char*)((DWORD)(entity)+xoffsets.dt_baseentity.m_clrrender + 0x3) = (byte)255;
			}
		}
	}

};

