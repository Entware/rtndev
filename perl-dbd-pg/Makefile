#
# Copyright (C) 2021 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=perl-dbd-pg
PKG_VERSION:=3.16.0
PKG_RELEASE:=1

PKG_SOURCE:=DBD-Pg-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=https://cpan.metacpan.org/authors/id/T/TU/TURNSTEP
PKG_HASH:=2c31163d8bdaaf8beaef9c97b8f260432d67a534bc7b69e7265c21cb841432b8

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

MOD_CFLAGS_PERL += -DPGLIBVERSION=\"130400\" -DPGDEFPORT=\"5432\"

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
