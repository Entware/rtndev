#
# Copyright (C) 2011-2021 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=iotop
PKG_VERSION:=0.6-20200108
PKG_RELEASE:=1
PKG_REV:=1bfb3bc70febb1ffb95146b6dcd65257228099a3

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://repo.or.cz/iotop.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)
PKG_MIRROR_HASH:=8e07f44dbfb861e46f8a0758f94aa9ca2a5f728454025b27cbed77ebddfe69f1

include $(TOPDIR)/feeds/packages/lang/python/pypi.mk
include $(INCLUDE_DIR)/package.mk
include $(TOPDIR)/feeds/packages/lang/python/python3-package.mk

define Package/$(PKG_NAME)
	SECTION:=admin
	CATEGORY:=Administration
	TITLE:=iotop watches I/O usage information output by the Linux kernel
	URL:=http://guichaz.free.fr/iotop/
	DEPENDS:=+python3-ncurses +python3-ctypes
endef

define Package/$(PKG_NAME)/description
 Iotop is a Python program with a top like UI used to show of behalf of
 which process is the I/O going on.
endef

PYTHON3_PKG_SETUP_ARGS:=$(filter-out --single-version-externally-managed,$(PYTHON3_PKG_SETUP_ARGS))

define Package/$(PKG_NAME)/install
	$(INSTALL_DIR) $(1)/opt/{lib,sbin}
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/* $(1)/opt/sbin
	$(SED) 's!/.*/python!/opt/bin/python!' $(1)/opt/sbin/iotop
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/* $(1)/opt/lib
endef

$(eval $(call Py3Package,iotop))
$(eval $(call BuildPackage,iotop))
