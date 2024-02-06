# SPDX-License-Identifier: GPL-2.0-only
#
# Copyright (C) 2020-2024 Entware

include $(TOPDIR)/rules.mk

PKG_NAME:=ndisc6
PKG_VERSION:=1.0.8
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_URL:=https://www.remlab.net/files/ndisc6
PKG_HASH:=1f2fb2dc1172770aa5a09d39738a44d8b753cc5e2e25e306ca78682f9fea0b4f

PKG_LICENSE:=GPL-3.0-only

PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk

define Package/ndisc6/Default
	SECTION:=net
	CATEGORY:=Network
	TITLE:=IPv6 diagnostic tools
	URL:=https://www.remlab.net/ndisc6
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/ndisc6
	$(call Package/ndisc6/Default)
	TITLE:=ICMPv6 Neighbor Discovery tool
endef

define Package/rdisc6
	$(call Package/ndisc6/Default)
	TITLE:=ICMPv6 Router Discovery tool
endef

define Package/tcptraceroute6
	$(call Package/ndisc6/Default)
	TITLE:=lightweight IPv6 tcptraceroute
endef

define Package/tcpspray6
	$(call Package/ndisc6/Default)
	TITLE:=Discard and Echo client
endef

define Package/rdnssd
	$(call Package/ndisc6/Default)
	TITLE:=Recursive DNS Servers discovery Daemon
endef

define Package/ndisc6/Default/description
 NDisc6 is a small collection of useful tools for IPv6 networking.
endef

define Package/ndisc6/description
$(call Package/ndisc6/Default/description)
  ndisc6: ICMPv6 Neighbor Discovery tool
endef

define Package/rdisc6/description
$(call Package/ndisc6/Default/description)
  rdisc6: ICMPv6 Router Discovery tool
endef

define Package/tcptraceroute6/description
$(call Package/ndisc6/Default/description)
  tcptraceroute6: lightweight IPv6 tcptraceroute
endef

define Package/tcpspray6/description
$(call Package/ndisc6/Default/description)
  tcpspray6: a TCP/IP Discard/Echo bandwidth metter
endef

define Package/rdnssd/description
$(call Package/ndisc6/Default/description)
  rdnssd: Recursive DNS Servers discovery Daemon
endef

define Package/ndisc6/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/ndisc6 $(1)/opt/bin
endef

define Package/rdisc6/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/rdisc6 $(1)/opt/bin
endef

define Package/tcptraceroute6/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/rltraceroute6 $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/tcptraceroute6 $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/tracert6 $(1)/opt/bin
endef

define Package/tcpspray6/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/tcpspray{,6} $(1)/opt/bin
endef

define Package/rdnssd/install
	$(INSTALL_DIR) $(1)/opt/sbin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/sbin/rdnssd $(1)/opt/sbin

	$(INSTALL_DIR) $(1)/opt/etc/rdnssd
	$(INSTALL_DIR) $(1)/opt/var/run/rdnssd
endef

$(eval $(call BuildPackage,ndisc6))
$(eval $(call BuildPackage,rdisc6))
$(eval $(call BuildPackage,tcptraceroute6))
$(eval $(call BuildPackage,tcpspray6))
#$(eval $(call BuildPackage,rdnssd))
