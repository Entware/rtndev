#
# Copyright (C) 2017
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=groff
PKG_VERSION:=1.22.3
PKG_RELEASE:=1

PKG_SOURCE_URL:=http://ftp.gnu.org/gnu/groff
PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_HASH:=3a48a9d6c97750bfbd535feeb5be0111db6406ddb7bb79fc680809cda6d828a5

PKG_LICENSE:=GPL

include $(INCLUDE_DIR)/package.mk

define Package/groff
  SECTION:=utils
  CATEGORY:=Utilities
  TITLE:=GNU troff text-formatting system
  URL:=https://www.gnu.org/software/groff/
  DEPENDS:= +libstdcpp
  MAINTAINER:=Entware team, http://entware.net
endef

define Package/groff/description
  This package contains optional components of the GNU troff text-formatting system.
endef

define Build/Configure
	$(call Build/Configure/Default)
endef

define Build/Compile
	+$(MAKE) $(PKG_JOBS) -C $(PKG_BUILD_DIR) \
		DESTDIR="$(PKG_INSTALL_DIR)" \
		all install
endef

define Package/groff/install
	$(INSTALL_DIR) $(1)/opt/{bin,lib,share}
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/groff $(1)/opt/bin/
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/grotty $(1)/opt/bin/
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/nroff $(1)/opt/bin/
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/troff $(1)/opt/bin/
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/tbl $(1)/opt/bin/
	$(CP) $(PKG_INSTALL_DIR)/opt/{lib,share} $(1)/opt/
	$(CP) $(PKG_INSTALL_DIR)/opt/{info,man} $(1)/opt/share/
	# fix perl exec path in scripts
	find $(PKG_BUILD_DIR) -name *.pl | xargs $(SED) 's|/usr/bin/env perl|/opt/bin/perl|'
endef

$(eval $(call BuildPackage,groff))
