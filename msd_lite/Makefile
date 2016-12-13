#
# Copyright (C) 2008-2016 OpenWrt.org
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=msd_lite
PKG_VERSION=1.08
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=http://www.netlab.linkpc.net/download/software/msd/lite

include $(INCLUDE_DIR)/package.mk

define Package/msd_lite
  SECTION:=multimedia
  CATEGORY:=Multimedia
  DEPENDS:=+libpthread
  TITLE:=Multi Stream daemon Lite
  URL:=http://www.netlab.linkpc.net/wiki/index?id=en:software:msd:lite
endef

define Package/msd_lite/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/src/msd_lite $(1)/opt/bin/
	$(INSTALL_DIR) $(1)/opt/etc/init.d
	$(INSTALL_DATA) $(PKG_BUILD_DIR)/msd_lite.conf $(1)/opt/etc/
	$(INSTALL_BIN) ./files/S80msd_lite $(1)/opt/etc/init.d
endef

$(eval $(call BuildPackage,msd_lite))
