void main(int i)
{


	allocate_controls =
	    EHEA_BMASK_SET(H_ALL_RES_EQ_RES_TYPE, H_ALL_RES_TYPE_EQ)
	    | EHEA_BMASK_SET(H_ALL_RES_EQ_NEQ, eq_attr->type ? 1 : 0)
	    | EHEA_BMASK_SET(H_ALL_RES_EQ_INH_EQE_GEN, !eq_attr->eqe_gen)
	    | EHEA_BMASK_SET(H_ALL_RES_EQ_NON_NEQ_ISN, 1);


	t->device_dir[0].ctl_name =
		parport_device_num(port->number, port->muxport,
				   device->daisy)
		+ 1;  /* nb 0 isn't legal here */ 


            us_crt =
            us_video
            +video_fill_us
            +cpm_us
            +us_m + us_n +us_p
            ;


			res =
			    data->temp[0] >=
			    AUTO_TEMP_MIN_FROM_REG_DEG(data->auto_temp[0])
			    || data->temp[1] >=
			    AUTO_TEMP_MIN_FROM_REG_DEG(data->auto_temp[1])
			    || (data->chip_type == adm1031 
				&& data->temp[2] >=
				AUTO_TEMP_MIN_FROM_REG_DEG(data->auto_temp[2]));
			break;


		data->alarms =
		    i2c_smbus_read_byte_data(client, LM83_REG_R_STATUS1)
		    + (i2c_smbus_read_byte_data(client, LM83_REG_R_STATUS2)
		    << 8);

	t->device_dir[0].ctl_name =
		parport_device_num(port->number, port->muxport,
				   device->daisy)
		+ 1;  /* nb 0 isn't legal here */ 

}
