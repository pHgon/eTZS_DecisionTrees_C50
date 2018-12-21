if (ColetaDados::getSAD(0)>284) {
	if (ColetaDados::getRdCost(0)>306) {
		termination=0;
	}
	else {
		if (ColetaDados::getPredMode(ColetaDados::getMv(0))>0) {
			if (ColetaDados::getQP()<=32) {
				termination=0;
			}
			else {
				if (ColetaDados::getSAD(0)<=510) {
					termination=1;
				}
				else {
					termination=0;
				}
			}
		}else {
			if (ColetaDados::getSAD(0)>612) {
				if (ColetaDados::getRdCost(0)>86) {
					termination=0;
				}
				else {
					if (hPU<=8) {
						termination=0;
					}
					else {
						if (ColetaDados::getSAD(0)>1577) {
							termination=0;
						}
						else {
							if (ColetaDados::getQP()>32) {
								termination=1;
							}
							else {
								if (wPU>16) {
									termination=1;
								}
								else {
									if (hPU<=24) {
										termination=0;
									}
									else {
										termination=1;
									}
								}
							}
						}
					}
				}
			}else {
				if (ColetaDados::getRdCost(0)>241) {
					termination=0;
				}
				else {
					if (ColetaDados::getQP()<=32) {
						if (ColetaDados::getRdCost(0)>86) {
							termination=0;
						}
						else {
							if (ColetaDados::getQP()<=27) {
								if (hPU<=8) {
									termination=0;
								}
								else {
									if (ColetaDados::getRdCost(0)<=24) {
										termination=1;
									}
									else {
										termination=0;
									}
								}
							}else {
								if (wPU>8) {
									termination=1;
								}
								else {
									if (ColetaDados::getSAD(0)<=387) {
										termination=1;
									}
									else {
										termination=0;
									}
								}
							}
						}
					}else {
						if (ColetaDados::getRdCost(0)<=80) {
							termination=1;
						}
						else {
							if (cb_distance<=0) {
								termination=0;
							}
							else {
								if (ColetaDados::getRdCost(0)<=162) {
									termination=1;
								}
								else {
									if (ColetaDados::getMv(0).getVer()>1) {
										termination=0;
									}
									else {
										if (ColetaDados::getSAD(0)<=404) {
											termination=1;
										}
										else {
											termination=0;
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}else {
	if (ColetaDados::getPredMode(ColetaDados::getMv(0))>0) {
		if (ColetaDados::getQP()>27) {
			termination=1;
		}
		else {
			if (ColetaDados::getSAD(0)<=84) {
				termination=1;
			}
			else {
				if (ColetaDados::getQP()>22) {
					if (ColetaDados::getRdCost(0)<=72) {
						termination=1;
					}
					else {
						termination=0;
					}
				}else {
					if (ColetaDados::getRdCost(0)>43) {
						termination=0;
					}
					else {
						if (ColetaDados::getTamWidth() * ColetaDados::getTamHeight()<=2073600) {
							termination=0;
						}
						else {
							termination=1;
						}
					}
				}
			}
		}
	}else {
		if (ColetaDados::getRdCost(0)>86) {
			if (ColetaDados::getQP()>32) {
				if (ColetaDados::getRdCost(0)<=162) {
					termination=1;
				}
				else {
					if (cb_distance<=3) {
						termination=0;
					}
					else {
						termination=1;
					}
					else {
						if (cb_distance<=0) {
							termination=0;
						}
						else {
							if (ColetaDados::getQP()<=27) {
								termination=0;
							}
							else {
								if (ColetaDados::getRdCost(0)>150) {
									termination=0;
								}
								else {
									if (ColetaDados::getRdCost(0)>123) {
										termination=1;
									}
									else {
										if (cb_distance<=5) {
											termination=0;
										}
										else {
											termination=1;
										}
									}
								}
							}
						}
					}
				}
			}else {
				if (ColetaDados::getQP()>27) {
					termination=1;
				}
				else {
					if (ColetaDados::getSAD(0)<=80) {
						termination=1;
					}
					else {
						if (ColetaDados::getRdCost(0)<=24) {
							termination=1;
						}
						else {
							if (ColetaDados::getQP()<=22) {
								if (ColetaDados::getRdCost(0)>32) {
									termination=0;
								}
								else {
									if (ColetaDados::getSAD(0)<=127) {
										termination=1;
									}
									else {
										termination=0;
									}
								}
							}else {
								if (ColetaDados::getSAD(0)<=116) {
									termination=1;
								}
								else {
									if (ColetaDados::getRdCost(0)>72) {
										termination=0;
									}
									else {
										if (cb_distance<=0) {
											termination=0;
										}
										else {
											if (ColetaDados::getRdCost(0)<=48) {
												termination=1;
											}
											else {
												if (ColetaDados::getRdCost(0)<=64) {
													termination=0;
												}
												else {
													termination=1;
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}
