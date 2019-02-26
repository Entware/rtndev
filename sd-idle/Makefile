#
# Copyright (C) 2011-2019 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=sd-idle
PKG_VERSION:=2.6
PKG_RELEASE:=1

include $(INCLUDE_DIR)/package.mk

define Package/sd-idle
	SECTION:=utils
	CATEGORY:=Utilities
	SUBMENU:=Disc
	TITLE:=Disk idle spindown program
	URL:=http://tomatousb.org/forum/t-271603/sd-idle-2-6-disk-idle-spindown-program-for-2-6
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/sd-idle/description
 sd-idle-2.6 is a disk idle spindown program for router firmware based on linux 2.6.
endef

define Package/sd-idle/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/sd-idle-2.6 $(1)/opt/bin/sd-idle
	$(INSTALL_DIR) $(1)/opt/etc/init.d
	$(INSTALL_BIN) ./files/S16sdidle $(1)/opt/etc/init.d/
endef

$(eval $(call BuildPackage,sd-idle))
