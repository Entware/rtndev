#
# Copyright (C) 2017 Joakim Plate <joakim.plate@gmail.com>
# Copyright (C) 2017-2021 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=pimd
PKG_VERSION:=2.3.2
PKG_REV:=6b91405516e9f919f2df23f7794d00e916fc1871
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/troglobit/pimd.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)
PKG_MIRROR_HASH:=f5307dce69af95c9c42a1467a4170f1382c34ce6b06f36065448508f268c8fe0

PKG_FIXUP:=autoreconf

include $(INCLUDE_DIR)/package.mk

define Package/pimd
	SECTION:=net
	CATEGORY:=Network
	SUBMENU:=Routing and Redirection
	TITLE:=multicast routing daemon (PIM-SM/SSM)
	URL:=http://troglobit.com/pimd.html
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/pimd/description
 pimd is a lightweight standalone PIM-SM/SSM v2 multicast routing daemon. It is
 the original USC (netweb/catarina.usc.edu) implementation of the protocol,
 RFC 2362. Today pimd strives for RFC 4601 compliance, with the v2.3.0 release
 supporting both PIM-SSM and IGMPv3.
endef

define Package/pimd/conffiles
/opt/etc/pimd.conf
endef

define Package/pimd/install
	$(INSTALL_DIR) $(1)/opt/etc/init.d
	$(INSTALL_CONF) $(PKG_BUILD_DIR)/pimd.conf $(1)/opt/etc
	$(INSTALL_BIN) ./files/S69pimd $(1)/opt/etc/init.d
	$(INSTALL_DIR) $(1)/opt/sbin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/pimd $(1)/opt/sbin
endef

$(eval $(call BuildPackage,pimd))
