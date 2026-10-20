# SPDX-License-Identifier: GPL-2.0-only
#
# Copyright (C) 2021-2026 Entware

include $(TOPDIR)/rules.mk

PKG_NAME:=perl-dbd-pg
PKG_VERSION:=3.21.2
PKG_RELEASE:=1

PKG_SOURCE:=DBD-Pg-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=https://cpan.metacpan.org/authors/id/T/TU/TURNSTEP
PKG_HASH:=d79179255ccb0c87b029db2eecaea56828e581255c48445d5fc0e79fa4e9245b

PKG_BUILD_DIR:=$(BUILD_DIR)/perl/DBD-Pg-$(PKG_VERSION)

PKG_LICENSE:=Artistic-1.0-Perl GPL-2.0-or-later
PKG_LICENSE_FILES:=LICENSES/artistic.txt LICENSES/gpl-2.0.txt

PKG_BUILD_DEPENDS:=perl-dbi/host

include $(INCLUDE_DIR)/package.mk
include $(TOPDIR)/feeds/packages/lang/perl/perlmod.mk

define Package/perl-dbd-pg
	SUBMENU:=Perl
	SECTION:=lang
	CATEGORY:=Languages
	TITLE:=PostgreSQL database driver for the DBI module
	URL:=https://metacpan.org/dist/DBD-Pg
	MAINTAINER:=Entware team, https://entware.net
	DEPENDS:=+libpq +perl-dbi +perlbase-test
endef

MOD_CFLAGS_PERL += -DPGLIBVERSION=\"170500\" -DPGDEFPORT=\"5432\"

define Build/Configure
	$(call perlmod/Configure,,POSTGRES_HOME="$(STAGING_DIR)/opt",)
endef

define Build/Compile
	$(call perlmod/Compile,,)
endef

define Package/perl-dbd-pg/install
	$(call perlmod/Install,$(1),auto/DBD DBD)
endef

$(eval $(call BuildPackage,perl-dbd-pg))
