#
# Copyright (C) 2017-2021 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=groff
PKG_VERSION:=1.22.4
PKG_RELEASE:=2

PKG_SOURCE_URL:=http://ftp.gnu.org/gnu/groff
PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_HASH:=e78e7b4cb7dec310849004fa88847c44701e8d133b5d4c13057d876c1bad0293

PKG_LICENSE:=GPL

PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/nls.mk

define Package/groff
	SECTION:=utils
	CATEGORY:=Utilities
	TITLE:=GNU troff text-formatting system
	URL:=https://www.gnu.org/software/groff/
	DEPENDS:= +libstdcpp $(ICONV_DEPENDS) $(INTL_DEPENDS)
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/groff/description
 This package contains optional components of the GNU troff
 text-formatting system.
endef

CONFIGURE_ARGS += \
	--with-doc=no

define Package/groff/install
	$(INSTALL_DIR) $(1)/opt/{bin,lib,share}
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/{g,n,t}roff $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/grotty $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/tbl $(1)/opt/bin
	$(CP) $(PKG_INSTALL_DIR)/opt/{lib,share} $(1)/opt
	# Entware specific: fix exec path in scripts
	$(FIND) $(1)/opt -name '*.pl' | $(XARGS) $(SED) 's,^#!.*perl,#!/opt/bin/perl,'
	$(SED) 's,^#!.*awk,#!/opt/bin/awk,' \
		$(1)/opt/share/groff/$(PKG_VERSION)/font/devlj4/generate/special.awk
#	$(SED) 's,^#!.*perl,#!/opt/bin/perl,' \
#		$(1)/opt/share/groff/$(PKG_VERSION)/font/devpdf/util/BuildFoundries
	$(SED) 's,^#!.*sed,#!/opt/bin/sed,' \
		$(1)/opt/share/groff/$(PKG_VERSION)/font/devps/generate/symbol.sed
	$(FIND) $(1)/opt/share -type f | $(XARGS) $(SED) 's,/usr/share,/opt/share,g'
endef

$(eval $(call BuildPackage,groff))
