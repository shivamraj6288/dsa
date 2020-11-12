void set(int x1, int y1, int x2, int y2, int b) {
			int temp = pow(2, this->n);
			
			if (x1==1 && x2==temp && y1==1 && y2==temp) {
				this->value = b;
				this->c1 = NULL;
				this->c2 = NULL;
				this->c3 = NULL;
				this->c4 = NULL;
				return;
			} else { 
				this->c1 = new quad_tree((this->n)-1);
				this->c2 = new quad_tree((this->n)-1);
				this->c3 = new quad_tree((this->n)-1);
				this->c4 = new quad_tree((this->n)-1);

				if (x1<=(temp/2) && x2<=(temp/2) && y1<=(temp/2) && y2<=(temp/2)) {

					this->c1->set(x1, y1, x2, y2, b);

				} else if (x1<=(temp/2) && x2<=(temp/2) && y1>(temp/2) && y2>(temp/2)) {

					this->c2->set(x1, y1-(temp/2), x2, y2-(temp/2), b);

				} else if (x1>(temp/2) && x2>(temp/2) && y1<=(temp/2) && y2<=(temp/2)) {

					this->c3->set(x1-(temp/2), y1, x2-(temp/2), y2, b);

				} else if (x1>(temp/2) && x2>(temp/2) && y1>(temp/2) && y2>(temp/2)) {

					this->c4->set(x1-(temp/2), y1-(temp/2), x2-(temp/2), y2-(temp/2), b);

				} else if (x1<=(temp/2) && x2<=(temp/2) && y1<=(temp/2) && y2>(temp/2)) {

					this->c1->set(x1, y1, x2, (temp/2), b);
					this->c2->set(x1, 0, x2, y2-(temp/2), b);

				} else if (x1>(temp/2) && x2>(temp/2) && y1<=(temp/2) && y2>(temp/2)) {

					this->c3->set(x1-(temp/2), y1, x2-(temp/2), (temp/2), b);
					this->c4->set(x1-(temp/2), 0, x2-(temp/2), y2-(temp/2), b);

				} else if (x1<=(temp/2) && x2>(temp/2) && y1<=(temp/2) && y2<=(temp/2)) {

					this->c1->set(x1, y1, (temp/2), y2, b);
					this->c3->set(0, y1, x2-(temp/2), y2, b);

				} else if (x1<=(temp/2) && x2>(temp/2) && y1>(temp/2) && y2>(temp/2)) {

					this->c2->set(x1, y1-(temp/2), (temp/2), y2-(temp/2), b);
					this->c4->set(0, y1-(temp/2), x2-(temp/2), y2-(temp/2), b);

				} else if (x1<=(temp/2) && x2>(temp/2) && y1<=(temp/2) && y2>(temp/2)) {

					this->c1->set(x1, (temp/2), y1, (temp/2), b);
					this->c2->set(x1, (temp/2), 0, y2-(temp/2), b);
					this->c3->set(0, y1, x2-(temp/2), (temp/2), b);
					this->c4->set(0, 0, x2-(temp/2), y2-(temp/2), b);

				}
			}
		}