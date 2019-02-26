#
# Copyright (C) 2017-2019 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=groff
PKG_VERSION:=1.22.4
PKG_RELEASE:=1

PKG_SOURCE_URL:=http://ftp.gnu.org/gnu/groff
PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_HASH:=e78e7b4cb7dec310849004fa88847c44701e8d133b5d4c13057d876c1bad0293

PKG_LICENSE:=GPL

PKG_FIXUP:=autoreconf

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

define Build/Compile
	+$(MAKE) $(PKG_JOBS) -C $(PKG_BUILD_DIR) \
		DESTDIR="$(PKG_INSTALL_DIR)" \
		all install
endef

define Package/groff/install
	$(INSTALL_DIR) $(1)/opt/{bin,lib,share}
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/{g,n,t}roff $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/grotty $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/tbl $(1)/opt/bin
	$(CP) $(PKG_INSTALL_DIR)/opt/{lib,share} $(1)/opt
	# fix perl exec path in scripts
	find $(PKG_BUILD_DIR) -name *.pl | xargs $(SED) 's|/usr/bin/env perl|/opt/bin/perl|'
endef

$(eval $(call BuildPackage,groff))
