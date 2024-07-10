# SPDX-License-Identifier: GPL-2.0-only
#
# Copyright (C) 2015-2024 Entware

include $(TOPDIR)/rules.mk

PKG_NAME:=perl-image-exiftool
PKG_VERSION:=12.87
PKG_RELEASE:=1

PKG_SOURCE_URL:=https://exiftool.org
PKG_SOURCE:=Image-ExifTool-$(PKG_VERSION).tar.gz
PKG_HASH:=7da3428d374cb18b2ab7011278d29b85bcac560e0d551efc7a6704ef0e7f2c21

PKG_LICENSE:=GPL-1.0-or-later Artistic-1.0-Perl

PKG_BUILD_DIR:=$(BUILD_DIR)/perl/Image-ExifTool-$(PKG_VERSION)

include $(INCLUDE_DIR)/package.mk
include $(TOPDIR)/feeds/packages/lang/perl/perlmod.mk

define Package/perl-image-exiftool
	SECTION:=multimedia
	CATEGORY:=Multimedia
	DEPENDS:=+perl +perlbase-base +perlbase-encode +perlbase-essential +perlbase-file +perlbase-time
	TITLE:=Perl library and command-line application for reading, writing and editing meta information
	URL:=https://www.sno.phy.queensu.ca/~phil/exiftool/
	MAINTAINER:=Entware team, https://entware.net
endef

define Build/Configure
	$(call perlmod/Configure,,)
endef

define Build/Compile
	$(call perlmod/Compile,,)
endef

define Package/perl-image-exiftool/install
	$(call perlmod/Install,$(1),File Image Image/ExifTool auto/Image/ExifTool)
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/exiftool $(1)/opt/bin
	$(SED) 's,#!.*perl,#!/opt/bin/perl,' $(1)/opt/bin/exiftool
endef

$(eval $(call BuildPackage,perl-image-exiftool))
