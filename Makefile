# REV06: Tue 31 Jan 2023 17:00
# REV05: Tue 06 Jul 2021 10:00
# REV02: Tue 15 Jun 2021 11:00
# REV01: Fri 12 Mar 2021 13:00
# START: Mon 15 Feb 2021 09:00

ALL: 000.md

000.md: 000.pmd _config.yml Gemfile _layouts/layout.html Makefile \
        _includes/navbar.html \
        _includes/footer.html _includes/head.html _includes/google-analytics.html \
	assets/css/style.css assets/scripts/includeScript.py 
	python assets/scripts/includeScript.py < 000.pmd > 000.md

.phony: ALL

